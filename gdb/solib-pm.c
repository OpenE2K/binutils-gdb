/* Handle E2k Protected Mode shared libraries for GDB, the GNU Debugger.

   Copyright (C) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000,
   2001, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "defs.h"

#include "elf/external.h"
#include "elf/common.h"
#include "elf/e2k.h"

#include "target.h"
#include "bfd-target.h"
#include "elf-bfd.h"
#include "elfxx-e2k.h"
#include "exceptions.h"
#include "gdbcore.h"
#include "symtab.h"
#include "objfiles.h"
#include "extract-store-integer.h"
#include "inferior.h"
#include "regcache.h"

#include "solist.h"
#include "solib.h"
#include "solib-pm.h"
#include "symtab.h"

#include "exec.h"

#include "e2k-tdep.h"

#include <string.h>

struct lm_info_pm final : public lm_info
{
  /* Pointer to copy of link map from inferior.  The type is char *
     rather than void *, so that we may use byte offsets to find the
     various fields without the need for a cast.  */
  gdb_byte *lm;

  CORE_ADDR l_code_addr;
  CORE_ADDR l_data_addr;
};

using lm_info_pm_up = std::unique_ptr<lm_info_pm>;


/* Per pspace Protected Mode specific data.  */

struct pm_info
{
  /* Base of dynamic linker structures. See `struct r_debug' in `link.h'
     for glibc and `struct my_r_debug' in `ldsodefs.h' for my awful PM
     ld.so.  */
  CORE_ADDR debug_base;

  /* Validity flag for debug_loader_{code,data}_offset.  */
  int debug_loader_offsets_p;

  /* Load addresses of code and data for the dynamic linker, inferred.  */
  CORE_ADDR debug_loader_code_offset;
  CORE_ADDR debug_loader_data_offset;

};


/* Per-program-space data key.  */
static const registry<program_space>::key<pm_info> solib_pm_pspace_data;

/* Get the current PM data.  If none is found yet, add it now.  This
   function always returns a valid object.  */

static struct pm_info *
get_pm_info (program_space *pspace)
{
  struct pm_info *info = solib_pm_pspace_data.get (pspace);

  if (info == NULL)
    info = solib_pm_pspace_data.emplace (pspace);

  return info;
}


static struct solib_ops pm_so_ops;


static struct link_map_offsets *
pm_fetch_link_map_offsets (void)
{
  static struct link_map_offsets lmo;
  static struct link_map_offsets *lmp = NULL;

  /* Reminder: offsets below match GLIBC version of PM ld.so, not the one
     in LIBMCST.  */
  if (lmp == NULL)
    {
      lmp = &lmo;

      lmo.r_map_offset = 0x10;
      lmo.r_brk_offset = 0x20;

      /* Everything we need is within `struct link_map_public' subobject of
         `struct link_map' being 0x50 bytes long.  */
      lmo.link_map_size = 0x50;
      lmo.l_data_addr_offset = 0x0;
      lmo.l_code_addr_offset = 0x8;
      lmo.l_name_offset = 0x10;
      lmo.l_next_offset = 0x30;
      lmo.l_prev_offset = 0x40;
    }

  return lmp;
}

static CORE_ADDR
bfd_lookup_symbol (bfd *abfd, const char *symname)
{
  long storage_needed;
  asymbol *sym;
  unsigned int number_of_symbols;
  unsigned int i;
  CORE_ADDR symaddr = 0;

  storage_needed = bfd_get_symtab_upper_bound (abfd);

  if (storage_needed > 0)
    {
      asymbol **symbol_table;
      asymbol **psym;
      psym = symbol_table = (asymbol **) xmalloc (storage_needed);
      auto cleanup = make_scope_exit ([&] ()
	{
	  xfree (symbol_table);
	});

      number_of_symbols = bfd_canonicalize_symtab (abfd, symbol_table);

      for (i = 0; i < number_of_symbols; i++)
	{
	  sym = *psym++;
	  if (strcmp (sym->name, symname) == 0
              && (sym->section->flags & SEC_ALLOC) != 0)
	    {
	      /* BFD symbols are section relative.  */
	      symaddr = sym->value + sym->section->vma;
	      break;
	    }
	}
    }

  /* There is no point in scanning the dynamic symbol table since
     in PM `ld.so' does not have it (because it's a statically-linked
     application). */

  return symaddr;
}



/* Return program interpreter string.  */
static char *
find_program_interpreter (void)
{
  char *buf = NULL;
  bfd *exec_bfd = current_program_space->exec_bfd ();

  /* If we have an exec_bfd, use its section table.  */
  if (exec_bfd && bfd_get_flavour (exec_bfd) == bfd_target_elf_flavour)
   {
     struct bfd_section *interp_sect;

     interp_sect = bfd_get_section_by_name (exec_bfd, ".interp");
     if (interp_sect != NULL)
      {
	int sect_size = bfd_section_size (interp_sect);

	buf = (char *) xmalloc (sect_size);
	bfd_get_section_contents (exec_bfd, interp_sect, buf, 0, sect_size);
      }
   }

  /* Implement this a bit later. */
#if 0

  /* If we didn't find it, use the target auxillary vector.  */
  if (!buf)
    buf = read_program_header (PT_INTERP, NULL, NULL);
#endif /* 0 */

  return buf;
}

static CORE_ADDR
LM_NEXT (solib *so)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  lm_info_pm *li = (lm_info_pm *) so->lm_info.get ();
  struct type *ptr_type
    = builtin_type (current_inferior ()->arch ())->builtin_data_ptr;

  /* `l_next' is AP in PM `struct link_map'.  */
  return extract_typed_address (li->lm + lmo->l_next_offset, ptr_type);
}

static CORE_ADDR
LM_PREV (solib *so)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  lm_info_pm *li = (lm_info_pm *) so->lm_info.get ();
  struct type *ptr_type
    = builtin_type (current_inferior ()->arch ())->builtin_data_ptr;

  /* `l_prev' is AP in PM `struct link_map'.  */
  return extract_typed_address (li->lm + lmo->l_prev_offset, ptr_type);
}

static CORE_ADDR
LM_NAME (solib *so)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  lm_info_pm *li = (lm_info_pm *) so->lm_info.get ();
  struct type *ptr_type
    = builtin_type (current_inferior ()->arch ())->builtin_data_ptr;

  /* `l_name' is AP in PM `struct link_map'.  */
  return extract_typed_address (li->lm + lmo->l_name_offset, ptr_type);
}

static void
FETCH_LM_ADDRESSES (solib *so)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  enum bfd_endian byte_order = gdbarch_byte_order (current_inferior ()->arch ());
  lm_info_pm *li = (lm_info_pm *) so->lm_info.get ();

  /* `l_addr' is Elf32_Addr in PM `struct link_map'.  */
  li->l_data_addr
    = extract_unsigned_integer (li->lm + lmo->l_data_addr_offset, 8,
				byte_order);

  /* `l_code_addr' is Elf32_Addr in PM `struct link_map'.  */
  li->l_code_addr
    = extract_unsigned_integer (li->lm + lmo->l_code_addr_offset,
				8, byte_order);
}

static CORE_ADDR
LM_ADDR (solib *so, struct bfd_section *sec)
{
  CORE_ADDR res;
  lm_info_pm *li = (lm_info_pm *) so->lm_info.get ();
  if (li->l_code_addr == (CORE_ADDR)-1)
    {
      /* Fetch both l_{code,data}_addr values at once. */
      FETCH_LM_ADDRESSES (so);
    }

  /* We may be invoked with `sec->owner == NULL' when `info shared-base' is
     executed because a specially customized `target_section' is used in that
     case to fetch out library base address (see the implementation in
     `solib.c'). Return the base of TEXT segment in that case.  */
  if (sec->owner == NULL)
    return li->l_code_addr;

  
  res = (sec->flags & SEC_CODE) ? li->l_code_addr : li->l_data_addr;

  unsigned int range_num = _bfd_e2k_elf_get_range_num (sec->owner);
  struct pm_range ranges[range_num];

  _bfd_e2k_elf_fill_ranges (sec->owner, range_num, ranges);
  res += _bfd_e2k_elf_get_offset_delta (range_num, ranges, sec->vma);
  return res;
}


static int
IGNORE_FIRST_LINK_MAP_ENTRY (solib *so)
{
  bfd *exec_bfd = current_program_space->exec_bfd ();
  /* Assume that everything is a library if the dynamic loader was loaded
     late by a static executable.  */
  /* I suspect that `dlopen ()' is not supported in Protected Mode.
     Therefore this check doesn't actually make sense.  */
  if (exec_bfd && bfd_get_section_by_name (exec_bfd, ".dynamic") == NULL)
    return 0;

  return LM_PREV (so) == 0;
}



/* This function is used both when relocating a statically-linked
   executable and filling in `debug_loader_{code,data}_offset'
   fields of `struct pm_info'. */
static void
get_displacements (CORE_ADDR *code_displ, CORE_ADDR *data_displ)
{
  int i;
  struct regcache *regcache;
  struct internalvar *cutd;
  CORE_ADDR cutd_base;
  struct e2k_gdbarch_data *data;

  if (! target_has_execution () && current_program_space->core_bfd () == NULL)
    {
      /* Don't attempt to access registers in such a case.  */
      *code_displ = *data_displ = 0;
      return;
    }

  regcache = get_thread_arch_regcache (current_inferior (),
				       inferior_ptid, current_inferior ()->arch ());
  *code_displ = (regcache_read_pc (regcache)
                 - bfd_get_start_address (current_program_space->exec_bfd ()));

  data = get_e2k_gdbarch_data (current_inferior ()->arch ());
  cutd = create_ivar_from_reg (current_inferior ()->arch (), regcache, E2K_CUTD_REGNUM);
  cutd_base = ivar_field (cutd, "base");

  free_ivar (cutd);

  /* PM ld.so (or the main executable in static case) seems to have different
     CUIs between linux-{3.14,4.x}: whereas in the former case it turns out to
     be 2, in the latter one it's equal to 1.  The right choice matches the
     first non-zero displacement(s) in CUT.  */
  for (i = 1; i <= 2; i++)
    {
      struct internalvar *cut_zero, *cut_two;
      cut_zero = create_ivar_from_value
	(value_at_lazy (data->cut_zero_type, cutd_base + i * 32));
      cut_two = create_ivar_from_value
	(value_at_lazy (data->cut_two_type, cutd_base + i * 32 + 16));

      *code_displ = ivar_field (cut_zero, "cud_base");
      *data_displ = ivar_field (cut_two, "gd_base");

      free_ivar (cut_two);
      free_ivar (cut_zero);

      /* Is this the entry of interest?  */
      if (*code_displ || *data_displ)
	break;
    }
}


static CORE_ADDR
elf_locate_base (void)
{
  CORE_ADDR sym_addr;
  char *interp_name;
  gdb_bfd_ref_ptr tmp_bfd;

  interp_name = find_program_interpreter ();
  if (!interp_name
      || (tmp_bfd = solib_bfd_open (interp_name)) == NULL)
    /* We cannot do anything without `ld.so' in Protected Mode. */
    return 0;

  sym_addr = bfd_lookup_symbol (tmp_bfd.get (), "_r_debug");
  xfree (interp_name);

  if (sym_addr != 0)
    {
      CORE_ADDR code_base;
      CORE_ADDR data_base;

      /* What an awful duplication it is: it's called once more
         in `enable_break ()' by analogy with `solib-svr4.c'. Here
         I need because of the PM specifics. Probably remove this
         call from `enable_break ()'. */
      get_displacements (&code_base, &data_base);

      unsigned int range_num = _bfd_e2k_elf_get_range_num (tmp_bfd.get ());
      struct pm_range ranges[range_num];
      _bfd_e2k_elf_fill_ranges (tmp_bfd.get (), range_num, ranges);


      return (data_base + sym_addr
	      + _bfd_e2k_elf_get_offset_delta (range_num, ranges,
					       sym_addr));
    }

  /* The absense of `_r_debug' symbol from `ld.so' probably makes it impossible
     to locate the "debug_base".  */
  return 0;
}


static CORE_ADDR
locate_base (struct pm_info *info)
{
  if (info->debug_base == 0)
    info->debug_base = elf_locate_base ();
  return info->debug_base;
}


static CORE_ADDR
solib_pm_r_map (struct pm_info *info)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  CORE_ADDR addr = 0;

  try
    {
      struct type *ptr_type
	= builtin_type (current_inferior ()->arch ())->builtin_data_ptr;

      /* `r_map' is AP in PM `struct r_debug'.  */
      addr = read_memory_typed_address (info->debug_base + lmo->r_map_offset,
					ptr_type);
					
    }
  catch (const gdb_exception_error &ex)
    {
      exception_print (gdb_stderr, ex);
    }

  return addr;
}


/* Find r_brk from the inferior's debug base.  */

static CORE_ADDR
solib_pm_r_brk (struct pm_info *info)
{
  struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
  enum bfd_endian byte_order = gdbarch_byte_order (current_inferior ()->arch ());
  CORE_ADDR addr = 0;

  try
    {
      /* `r_brk' is Elf32_Addr in PM `struct r_debug'.  */
      addr
	= read_memory_unsigned_integer (info->debug_base + lmo->r_brk_offset,
					4, byte_order);
    }
  catch (const gdb_exception_error &ex)
    {
      exception_print (gdb_stderr, ex);
    }

  return addr;
}

static void pm_relocate_main_executable (CORE_ADDR, CORE_ADDR);

static intrusive_list<solib>
pm_current_sos (void)
{
  CORE_ADDR lm, prev_lm;
  intrusive_list<solib> head;
  struct pm_info *info;

  info = get_pm_info (current_program_space);

  /* Always locate the debug struct, in case it has moved. This
     has been borrowed from `solib-svr4.c'. Can it be moved in
     my case?  */
  info->debug_base = 0;
  locate_base (info);

  /* This function is invoked for the first time just after the inferior has
     been executed and before `link_map's on ld.so side have been loaded and
     arranged into a list. Avoid enabling breakpoints in such a case to avoid
     memory access errors and other unexpected effects.  With LIBMCST in use
     where the address of `r_debug_struct' is stored by ld.so into `_dl_debug_
     addr' right before calling `_dl_debug_state ()' (which means that the list
     on ld.so side has already been created) this case could be recognized by
     the following condition . . .  */
  if (! info->debug_base)
    return {};

  prev_lm = 0;
  lm = solib_pm_r_map (info);

  /* . . . however, with PM glibc, which doesn't make use of `_dl_debug_addr',
     "debug_base" is calculated directly based on `_r_debug' symbol value (in
     case it's present, of course) which means that it may turn out to be non-
     NULL even if the list hasn't been constructed yet. Therefore, one should
     ensure that the head of the chain of loaded objects (i.e. `_r_debug.r_map')
     is non-NULL before enabling breakpoints.  */
  if (lm == 0)
    return {};

  while (lm)
    {
      struct link_map_offsets *lmo = pm_fetch_link_map_offsets ();
      solib *newobj = new struct solib;
      auto cleanup1 = make_scope_exit ([&] ()
	{
	  delete newobj;
	});

      CORE_ADDR next_lm;
      lm_info_pm_up li = std::make_unique<lm_info_pm> ();

      auto cleanup2 = make_scope_exit ([&] ()
	{
	  // xfree (newobj->lm_info);
	});

      li->l_code_addr = (CORE_ADDR)-1;
      li->l_data_addr = (CORE_ADDR)-1;
      li->lm = (gdb_byte *) xzalloc (lmo->link_map_size);
      auto cleanup3 = make_scope_exit ([&] ()
	{
	  xfree (li->lm);
	});


      read_memory (lm, li->lm, lmo->link_map_size);

      newobj->lm_info = std::move (li);

      next_lm = LM_NEXT (newobj);

      if (LM_PREV (newobj) != prev_lm)
	{
	  warning (_("Corrupted shared library list"));
	  // free_so (newobj);
	  next_lm = 0;
	}
      /* In our case the first entry in the link map is for the
         inferior executable, so we must ignore it.  */
      else if (IGNORE_FIRST_LINK_MAP_ENTRY (newobj))
        {
          /* If I just free it, `pm_relocate_section_addresses' will be
             never called for the main executable's sections. Therefore,
             the first option is not to free it. However, if I choose it
             breakpoints, set into the main executable, are not relocated
             somehow . . . Let's try to relocate the main executable here
             explicitly and then free it.  */

          FETCH_LM_ADDRESSES (newobj);
	  pm_relocate_main_executable
	    (((lm_info_pm *) newobj->lm_info.get ())->l_code_addr,
	     ((lm_info_pm *) newobj->lm_info.get ())->l_data_addr);
          // free_so (newobj);
        }
      else
	{
	  /* Extract this shared object's name.  */
	  gdb::unique_xmalloc_ptr<char> buffer = 
	    target_read_string (LM_NAME (newobj), SO_NAME_MAX_PATH_SIZE - 1);

	  if (buffer == nullptr)
	    warning (_("Can't read pathname for load map."));
	  else
	    {
	      newobj->so_name = buffer.get ();
	      newobj->so_original_name = newobj->so_name;
	    }

	  /* If this entry has no name, don't include it in the list.  */
	  if (! newobj->so_name[0])
	    ; // free_so (newobj);
	  else
	    {
	      head.push_back (*newobj);
	    }
	}

      prev_lm = lm;
      lm = next_lm;

      /* `cleanup1.release ()' isn't likely to release subsequent cleanup{2,3}
	 as well by analogy with how `discard_cleanups (old_chain)' did.  */
      cleanup3.release ();
      cleanup2.release ();
      cleanup1.release ();
    }

  enable_breakpoints_after_startup ();

  /* What should I do if `head' is NULL?  */
  return head;
}

/* Return 1 if PC lies in the dynamic symbol resolution code of the
   PM run time loader. I guess that my run-time loader does not
   support dynamic symbol resolution yet, therefore just `return 0'.  */

/* As follows from `solib-svr4.c' this function also returns one when
   `pc' is inside PLT section of ANY object (either the main executable
   or DSO). I don't quite understand whether the corresponding code in
   PLT is considered to be dynamic symbol resolution . . . However we
   don't have PLT in Protected Mode either . . .   */

static int
pm_in_dynsym_resolve_code (CORE_ADDR pc)
{
  return 0;
}


static void
enable_break (struct pm_info *info)
{
  CORE_ADDR sym_addr;
  char *interp_name;

  CORE_ADDR load_code_addr;
  CORE_ADDR load_data_addr;
  gdb_bfd_ref_ptr tmp_bfd = NULL;

  sym_addr = 0;
  if (info->debug_base && solib_pm_r_map (info) != 0)
    sym_addr = solib_pm_r_brk (info);

  if (sym_addr != 0)
    /* I believe that at present this should be impossible here. */
    return;

  interp_name = find_program_interpreter ();
  if (!interp_name
      || (tmp_bfd = solib_bfd_open (interp_name)) == NULL)
    /* We cannot do anything without `ld.so' in Protected Mode. */
    return;

  /* Let us (temporarely) not consider a `running target' where
     the dynamic linker's base address can be obtained from the
     shared library list. */

  get_displacements (&load_code_addr, &load_data_addr);

  info->debug_loader_offsets_p = 1;
  info->debug_loader_code_offset = load_code_addr;
  info->debug_loader_data_offset = load_data_addr;

  sym_addr = bfd_lookup_symbol (tmp_bfd.get (), "_dl_debug_state");

  unsigned int range_num = _bfd_e2k_elf_get_range_num (tmp_bfd.get ());
  struct pm_range ranges[range_num];
  _bfd_e2k_elf_fill_ranges (tmp_bfd.get (), range_num, ranges);

  if (sym_addr != 0)
    create_solib_event_breakpoint
      (current_inferior ()->arch (),
       (load_code_addr + sym_addr
	+ _bfd_e2k_elf_get_offset_delta (range_num, ranges, sym_addr)));

  xfree (interp_name);
}


static int
pm_exec_displacements (CORE_ADDR *code_displ, CORE_ADDR *data_displ)
{
  char *interp_name;

  if (current_program_space->exec_bfd () == NULL)
    return 0;

  if ((interp_name = find_program_interpreter ()) != NULL)
    {
      /* Since at present we don't have a valid AT_ENTRY it's impossible
         to calculate a displacement for a dynamically-linked program
         unless the main executable's entry has already been loaded into
         CUT. The latter is not the case just after startup. */

      /* . . . */

      xfree (interp_name);
      return 0;
    }

  /* In case of a static executable it seems to be simple. */

  get_displacements (code_displ, data_displ);
  return 1;
}

static void
pm_relocate_main_executable (CORE_ADDR code_displ, CORE_ADDR data_displ)
{
  bfd *exec_bfd;

  if (current_program_space->symfile_object_file)
    {
      int i;
      objfile *objf = current_program_space->symfile_object_file;

      size_t num_sections = objf->section_offsets.size ();
      section_offsets new_offsets (num_sections);

      unsigned int range_num = _bfd_e2k_elf_get_range_num (objf->obfd.get ());
      struct pm_range ranges[range_num];
      _bfd_e2k_elf_fill_ranges (objf->obfd.get (), range_num, ranges);


      for (i = 0; i < num_sections; i++)
        {
	  struct obj_section *crnt = &objf->sections_start[i];

	  /* This is something! */
          if (crnt < objf->sections_end
              && crnt->the_bfd_section
              && (crnt->the_bfd_section->flags & SEC_CODE))
            new_offsets[i] = code_displ;
          else
            new_offsets[i] = data_displ;

	  if (crnt->the_bfd_section)
	    new_offsets[i]
	      += _bfd_e2k_elf_get_offset_delta (range_num, ranges,
						crnt->the_bfd_section->vma);
        }

      objfile_relocate (objf, new_offsets);
    }
  else if ((exec_bfd = current_program_space->exec_bfd ()) != nullptr)
    {
      asection *asect;

      for (asect = exec_bfd->sections; asect != NULL; asect = asect->next)
	exec_set_section_address (bfd_get_filename (exec_bfd), asect->index,
				  (bfd_section_vma (asect)
				   + code_displ));
    }

  /* While `waiting_for_inferior ()' (before we come here)
     `find_pc_partial_function ()' is called. As a consequence
     we obtain wrong `cache_pc_function_{low,high,name . . }'
     values since they are calculated before the relocation
     takes place. This may very well lead to further errors
     when calling `find_pc_partial_function ()', for example
     when disassembling. */

  /* TODO: find out what are all these incorrect
     `ecs->stop_func_{name,start,end, . . }' used for. Don't
     they lead to any other errors? */
  clear_pc_function_cache ();
}

static void
pm_relocate_static_executable (void)
{
  CORE_ADDR code_displ, data_displ;

  if (! pm_exec_displacements (&code_displ, &data_displ))
    return;

  pm_relocate_main_executable (code_displ, data_displ);
}

static void
pm_solib_create_inferior_hook (int from_tty)
{
  char *interp_name;
  struct pm_info *info = get_pm_info (current_program_space);

  if ((interp_name = find_program_interpreter ()) != NULL)
    {
      xfree (interp_name);
      /* For dynamic programs breakpoints will be re-enabled within the
         `current_sos' method. For static ones there is probably no point
         in disabling them at all. Taking into account that this method may
	 be called nowadays on behalf of `file' command before execution
	 actually starts, don't bother about disabling breakpoints if this
	 is the case.  */
      if (target_has_execution ())
	disable_breakpoints_before_startup ();
    }
  pm_relocate_static_executable ();

  enable_break (info);
}


static void
pm_clear_solib (program_space *pspace)
{
}

#if 0
static void
pm_free_so (solib *so)
{
  lm_info_pm *li = (lm_info_pm *) so->lm_info;  
  xfree (li->lm);
  xfree (li);
}
#endif

static void
pm_relocate_section_addresses (solib &so,
                               struct target_section *sec)
{
  sec->addr = sec->addr + LM_ADDR (&so, sec->the_bfd_section);
  sec->endaddr = sec->endaddr + LM_ADDR (&so, sec->the_bfd_section);
}



void
set_solib_pm_ops (struct gdbarch *gdbarch)
{
  set_gdbarch_so_ops (gdbarch, &pm_so_ops);
}

void _initialize_pm_solib ();
void
_initialize_pm_solib ()
{
  /* Do I need `gdbarch_data' here? Probably not. */

  /* I don't understand clearly why `svr4_so_ops' fields are set in an
     `_initailze'-function. Why cannot this be done statically?
     Imitating this behaviour let's set all of them to NULLs in our
     case. */

  memset (&pm_so_ops, 0, sizeof (pm_so_ops));

  pm_so_ops.relocate_section_addresses = pm_relocate_section_addresses;
  pm_so_ops.clear_solib = pm_clear_solib;
  // pm_so_ops.free_so = pm_free_so;
  pm_so_ops.solib_create_inferior_hook = pm_solib_create_inferior_hook;
  pm_so_ops.current_sos = pm_current_sos;
  pm_so_ops.in_dynsym_resolve_code = pm_in_dynsym_resolve_code;
  pm_so_ops.bfd_open = solib_bfd_open;
}
