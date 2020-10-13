/* E2K-specific support for 32-bit ELF
   Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
   2003, 2004, 2005, 2006, 2007 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/e2k.h"
#include "elfxx-e2k.h"


static int
elf64_e2k_write_out_phdrs (bfd *abfd,
                           const Elf_Internal_Phdr *phdr,
                           unsigned int count)
{
  /* See a more detailed comment in `elf32-e2k.c'.  */
  if (!e2k_dsp_linux_mode)
    return bfd_elf64_write_out_phdrs (abfd, phdr, count);

  while (count--)
    {
      Elf64_External_Phdr extphdr;

      if (phdr->p_vaddr != phdr->p_paddr)
        {
          Elf_Internal_Phdr fake;
          memcpy (&fake, phdr, sizeof (fake));
          fake.p_vaddr = phdr->p_paddr;
          bfd_elf64_swap_phdr_out (abfd, &fake, &extphdr);
        }
      else
        bfd_elf64_swap_phdr_out (abfd, phdr, &extphdr);


      if (bfd_bwrite (&extphdr, sizeof (Elf64_External_Phdr), abfd)
          != sizeof (Elf64_External_Phdr))
        return -1;

      phdr++;
    }

  return 0;
}


/* All fields are set to their default values from
   `elfcode.h' except `write_out_phdrs' which shoud
   fool the Kernel in case of DSP segments. */
static const struct elf_size_info elf64_e2k_size_info = {
  sizeof (Elf64_External_Ehdr),
  sizeof (Elf64_External_Phdr),
  sizeof (Elf64_External_Shdr),
  sizeof (Elf64_External_Rel),
  sizeof (Elf64_External_Rela),
  sizeof (Elf64_External_Sym),
  sizeof (Elf64_External_Dyn),
  sizeof (Elf_External_Note),
  4,
  1,
  64, 3,
  2, 1,
  elf64_e2k_write_out_phdrs,
  bfd_elf64_write_shdrs_and_ehdr,
  bfd_elf64_checksum_contents,
  bfd_elf64_write_relocs,
  bfd_elf64_swap_symbol_in,
  bfd_elf64_swap_symbol_out,
  bfd_elf64_slurp_reloc_table,
  bfd_elf64_slurp_symbol_table,
  bfd_elf64_swap_dyn_in,
  bfd_elf64_swap_dyn_out,
  bfd_elf64_swap_reloc_in,
  bfd_elf64_swap_reloc_out,
  bfd_elf64_swap_reloca_in,
  bfd_elf64_swap_reloca_out
};



#define bfd_elf64_bfd_link_add_symbols          _bfd_e2k_elf_link_add_symbols
#define bfd_elf64_bfd_reloc_type_lookup         _bfd_e2k_elf_reloc_type_lookup
#define bfd_elf64_bfd_reloc_name_lookup         _bfd_e2k_elf_reloc_name_lookup
#define bfd_elf64_bfd_merge_private_bfd_data    _bfd_e2k_elf_merge_private_bfd_data
#define bfd_elf64_mkobject                      _bfd_e2k_elf_mkobject
#define bfd_elf64_bfd_link_hash_table_create    _bfd_e2k_elf_link_hash_table_create
#define bfd_elf64_bfd_final_link                _bfd_e2k_elf_final_link
#define bfd_elf64_get_synthetic_symtab	        _bfd_e2k_elf_get_synthetic_symtab
#define bfd_elf64_write_object_contents         _bfd_e2k_elf_write_object_contents
#define bfd_elf64_bfd_copy_private_bfd_data     _bfd_e2k_elf_copy_private_bfd_data


#define elf_info_to_howto                       _bfd_e2k_elf_info_to_howto

#define elf_backend_add_symbol_hook             _bfd_e2k_elf_add_symbol_hook
#define elf_backend_special_sections            _bfd_e2k_elf_special_sections
#define elf_backend_common_definition           _bfd_e2k_elf_common_definition
#define elf_backend_merge_symbol_attribute      _bfd_e2k_elf_merge_symbol_attribute
#define elf_backend_grok_prstatus               _bfd_e2k_elf_grok_prstatus
#define elf_backend_write_core_note             _bfd_e2k_elf_write_core_note


/* This one is required in order to create `{,.rela}.plt' and  . . .
   Typically backends have their own `create_dynamic_sections' method which
   calls `_bfd_elf_create_dynamic_sections ()'.  */
#define elf_backend_create_dynamic_sections	_bfd_e2k_elf_create_dynamic_sections

#define elf_backend_copy_indirect_symbol        _bfd_e2k_elf_copy_indirect_symbol
#define elf_backend_check_directives            _bfd_e2k_elf_check_directives
#define elf_backend_check_relocs                _bfd_e2k_elf_check_relocs
#define elf_backend_gc_sweep_hook               _bfd_e2k_elf_gc_sweep_hook
#define elf_backend_adjust_dynamic_symbol       _bfd_e2k_elf_adjust_dynamic_symbol
#define elf_backend_size_dynamic_sections       _bfd_e2k_elf_size_dynamic_sections
#define elf_backend_action_discarded            _bfd_e2k_elf_action_discarded
#define elf_backend_relocate_section            _bfd_e2k_elf_relocate_section
#define elf_backend_finish_dynamic_symbol	_bfd_e2k_elf_finish_dynamic_symbol
#define elf_backend_reloc_type_class            _bfd_e2k_elf_reloc_type_class
#define elf_backend_finish_dynamic_sections	_bfd_e2k_elf_finish_dynamic_sections
#define elf_backend_post_process_headers        _bfd_e2k_elf_post_process_headers
#define elf_backend_ignore_discarded_relocs     _bfd_e2k_elf_ignore_discarded_relocs
#define elf_backend_hide_symbol                 _bfd_e2k_elf_hide_symbol
#define elf_backend_object_p                    _bfd_e2k_elf_object_p
#define elf_backend_setup_gnu_properties	_bfd_e2k_elf_link_setup_gnu_properties

/* Make tests employing `gc-sections' option PASS. I wonder if any backend-
   specific support is required. TODO: place here actual names of the tests.  */
#define elf_backend_can_gc_sections             1
#define elf_backend_want_got_sym                1
/* I want got.refcount start from `0', not from `-1'
   (see _bfd_elf_link_hash_table_init). */
#define elf_backend_can_refcount                1

#define elf_backend_want_got_plt                1
#define elf_backend_plt_readonly                1

/* The first entry in `.got' is reserved for the `_DYNAMIC' link-time
   address.  */
#define elf_backend_got_header_size             24

/* This is required to ensure that addends of rela-relocations against section
   symbols are adjusted correctly during the relocatable linkage in
   `elf_link_input_bfd ()'.  */
#define elf_backend_rela_normal                 1

#define elf_backend_plt_alignment               3

#define elf_backend_size_info                   elf64_e2k_size_info

#define elf_backend_extern_protected_data       1

#define elf_backend_r_none_info                 R_E2K_NONE


#define TARGET_LITTLE_SYM       e2k_elf64_vec
#define TARGET_LITTLE_NAME      "elf64-e2k"
#define ELF_ARCH                bfd_arch_e2k

#define ELF_MACHINE_CODE        EM_MCST_ELBRUS

/* This is the value we initially used.  */
#define ELF_MACHINE_ALT1        EM_E2K_OLD

#define ELF_MAXPAGESIZE         0x1000

/* Don't rush to set up BFD target vector if we are included on behalf of KPDA
   target: some of the above definitions are going to be altered by it.  */
#ifndef TARGET_KPDA
#include "elf64-target.h"
#endif /*  ! TARGET_KPDA  */
