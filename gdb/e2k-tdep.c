/* Target-dependent code for E2K & E2K64.

   Copyright (c) 2009-2025 AO MCST.
   Copyright (C) 1991-2025 Free Software Foundation, Inc.
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this program; if not, see
   <https://www.gnu.org/licenses/>.  */

#include "defs.h"
#include "arch-utils.h"
#include "breakpoint.h"
#include "command.h"
#include "dummy-frame.h"
#include "exceptions.h"
#include "frame.h"
#include "frame-unwind.h"
#include "extract-store-integer.h"
#include "gdbcore.h"
#include "gdbtypes.h"
#include "infcall.h"
#include "inferior.h"
#include "infrun.h"
#include "language.h"
#include "objfiles.h"
#include "dwarf2/frame.h"
#include "osabi.h"
#include "regcache.h"
#include "reggroups.h"
#include "value.h"
#include "valprint.h"
#include "dis-asm.h"

#include "observable.h"

#include "e2k-tdep.h"

#include "elf/common.h"
#include "elf/e2k.h"

#include <string.h>
#include <algorithm>

#include "features/e2k-linux.c"
#include "features/elbrus-v2-linux.c"
#include "features/elbrus-v3-linux.c"
#include "features/elbrus-v5-linux.c"
#include "features/elbrus-v6-linux.c"
#include "features/elbrus-v7-linux.c"
#include "features/elbrus-maket32c-linux.c"

#include "target-descriptions.h"

int debug_e2k_tdep = 1;

/* Array of register names.  */

static const char *e2k_register_names[NUM_E2K_RAW_REGS + NUM_E2K_ALL_PSEUDO_REGS] =
  {
#define E2K_RAW_REG(a, b, c) a,
#define E2K_PSEUDO_REG(a, b) a,

#include "e2k-regs.inc"

#undef E2K_PSEUDO_REG
#undef E2K_RAW_REG
  };


e2k_gdbarch_data::e2k_gdbarch_data (struct gdbarch *gdbarch)
{
  this->hword_type = tdesc_find_type (gdbarch, "uint16");
  this->word_type = tdesc_find_type (gdbarch, "uint32");

  this->hs_type = tdesc_register_type (gdbarch, E2K_FAKE_HS_REGNUM);
  this->alf2_type = tdesc_register_type (gdbarch, E2K_FAKE_ALF2_REGNUM);
  this->c1f1_type = tdesc_register_type (gdbarch, E2K_FAKE_C1F1_REGNUM);
  this->cs0_dummy_type = tdesc_register_type (gdbarch,
                                              E2K_FAKE_CS0_DUMMY_REGNUM);
  this->cs1_setwd_type = tdesc_register_type (gdbarch,
                                              E2K_FAKE_CS1_SETWD_REGNUM);
  this->cs1_call_type = tdesc_register_type (gdbarch, E2K_FAKE_CS1_CALL_REGNUM);
  this->lts0_setwd_type = tdesc_register_type (gdbarch,
                                               E2K_FAKE_LTS0_SETWD_REGNUM);
  this->ss_type = tdesc_register_type (gdbarch, E2K_FAKE_SS_REGNUM);
  this->ctpr_rwp_type = tdesc_register_type (gdbarch, E2K_FAKE_CTPR_RWP_REGNUM);

  /* Types of tagged values in memory.  */
  this->mem_tagged32_type = tdesc_register_type (gdbarch,
						 E2K_FAKE_MEM_TAGGED32_REGNUM);
  this->mem_tagged64_type = tdesc_register_type (gdbarch,
						 E2K_FAKE_MEM_TAGGED64_REGNUM);
  this->mem_signed_tagged32_type =
    tdesc_register_type (gdbarch, E2K_FAKE_MEM_SIGNED_TAGGED32_REGNUM);
  this->mem_signed_tagged64_type =
    tdesc_register_type (gdbarch, E2K_FAKE_MEM_SIGNED_TAGGED64_REGNUM);

  /* Types of tagged values on registers.  */
  this->tagged64_type = tdesc_register_type (gdbarch, E2K_R0_REGNUM);
  this->tagged80_type = tdesc_register_type (gdbarch, E2K_FAKE_TAGGED80_REGNUM);
  this->tagged128_type = tdesc_register_type (gdbarch,
					      E2K_FAKE_TAGGED128_REGNUM);


  this->pred_type = tdesc_register_type (gdbarch, E2K_PRED0_REGNUM);

  this->cut_zero_type = tdesc_register_type (gdbarch, E2K_FAKE_CUT_ZERO_REGNUM);
  this->cut_two_type = tdesc_register_type (gdbarch, E2K_FAKE_CUT_TWO_REGNUM);

  this->pf_type = tdesc_register_type (gdbarch, E2K_FAKE_PF_REGNUM);

  this->mlt_type = tdesc_register_type (gdbarch, E2K_MLT_0);

  this->dbl_param_type = tdesc_register_type (gdbarch, E2K_DBL_REG);
  this->quad_param_type = tdesc_register_type (gdbarch, E2K_QUAD_REG);
}

static const registry<gdbarch>::key<e2k_gdbarch_data>
     e2k_gdbarch_data_handle;

struct e2k_gdbarch_data *
get_e2k_gdbarch_data (struct gdbarch *gdbarch)
{
  struct e2k_gdbarch_data *result = e2k_gdbarch_data_handle.get (gdbarch);
  if (result == nullptr)
    result = e2k_gdbarch_data_handle.emplace (gdbarch, gdbarch);

  return result;
}



/* Types of operations supported by `e2k_handle_nonaligned_watchpoint ()'.  */
typedef enum { WP_INSERT, WP_REMOVE, WP_COUNT } e2k_wp_op_t;

#if 0
static ULONGEST
ivar_as_ulongest (struct internalvar *var)
{
  ULONGEST ret;
  struct value *val = value_of_internalvar (NULL, var);
  release_value (val);
  ret = (ULONGEST) value_as_long (val);
  value_free (val);

  return ret;
}
#endif /* 0  */

#if 0
/* FIXME: is this function required at all nowadays?  */
static void
set_ivar (struct internalvar *var, ULONGEST num)
{
  struct value *val;
  struct value *src;
  struct value *underlying;

  val = value_of_internalvar (NULL /* gdbarch */, var);
  release_value (val);

  src = value_from_ulongest (val->type (), num);
  release_value (src);

  value_assign (val, src);

  /* In case the underlying value lies in memory enforce actual
     transfer of its modified contents there. */
  if ((underlying = value_ref_of_internalvar (var))->lval () == lval_memory)
    value_assign (underlying, underlying);

  value_free (src);
  value_free (val);
}
#endif /* 0  */


ULONGEST
ivar_field (struct internalvar *var, const char *name)
{
  ULONGEST ret;
  struct value *elt;
  /* For INTERNALVAR_VALUE `gdbarch' parameter is not
     needed in `value_of_internalvar'. How am I going
     to fix this? */

  struct value *val = value_of_internalvar (/* gdbarch */ NULL, var);


  elt = value_struct_elt (&val,
                          {}, /* This is required for C++ types */
                          name,
                          0, /* not a static memfuncp */
                          "struct" /* Do I need an error string here? */
                          );

  ret = (ULONGEST) value_as_long (elt);

  release_value (elt);
  release_value (val);

  // value_decref (elt);
  // value_decref (val);

  return ret;
}

void
set_ivar_field (struct internalvar *var, const char *name, ULONGEST num)
{
  struct value *val;
  struct value *elt;
  struct value *src;
  struct value *underlying;

  val = value_of_internalvar (NULL /* gdbarch */, var);
  // release_value (val);

  elt = value_struct_elt (&val, {}, name, 0, "struct");
  // release_value (elt);

  src = value_from_ulongest (elt->type (), num);
  // release_value (src);

  value_assign (elt, src);

  /* In case the underlying value lies in memory enforce actual
     transfer of its modified contents there. */
  if ((underlying = value_ref_of_internalvar (var))->lval () == lval_memory)
    value_assign (underlying, underlying);

  // value_decref (src);
  // value_decref (elt);
  // value_decref (val);
}

struct internalvar *
create_ivar_from_value (struct value *val)
{
  struct internalvar *res = create_nameless_internalvar ();
  set_internalvar (res, val);
  return res;
}

struct internalvar *
create_ivar_from_reg (struct gdbarch * gdbarch,
                      readable_regcache *regcache, int regnum)
{
  struct internalvar *res;
  struct value *val = value::zero (register_type (gdbarch, regnum), not_lval);
  // release_value (val);
  /* `regcache_raw_read' is called for `raw'
     registers in the end */
  regcache->cooked_read (regnum, val->contents_writeable ().data ());
  res = create_ivar_from_value (val);
  // value_decref (val);

  return res;
}


static struct internalvar *
create_zero_ivar (struct type *type)
{
  struct internalvar *res;
  struct value *zero = value::zero (type, not_lval);

  // release_value (zero);
  res = create_ivar_from_value (zero);
  // value_decref (zero);

  return res;
}

void
free_ivar (struct internalvar *var)
{
  free_nameless_internalvar (var);
}




static const char *
e2k_register_name (struct gdbarch *gdbarch, int reg)
{
  return e2k_register_names[reg];
}

static struct type *
e2k_register_type (struct gdbarch *gdbarch, int regnum)
{
  internal_error (_("invalid regnum"));
  return NULL;
}

static const char *
e2k_pseudo_register_name (struct gdbarch *gdbarch, int regnum)
{
  e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);

  gdb_assert (regnum >= NUM_E2K_RAW_REGS
              && regnum < (NUM_E2K_RAW_REGS + NUM_E2K_PSEUDO_REGS
                           + tdep->num_elbrus_v5_pseudo_regs));

  return e2k_register_names[regnum];
}

static struct type *
e2k_pseudo_register_type (struct gdbarch *gdbarch, int regnum)
{
  struct e2k_gdbarch_data *data;
  e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);

  gdb_assert (regnum >= NUM_E2K_RAW_REGS
              && regnum < (NUM_E2K_RAW_REGS + NUM_E2K_PSEUDO_REGS
                           + tdep->num_elbrus_v5_pseudo_regs));

  data = get_e2k_gdbarch_data (gdbarch);

  if ((regnum >= VR0_REGNUM && regnum <= VR223_REGNUM)
      || (regnum >= VB0_REGNUM && regnum <= VB127_REGNUM))
    return data->tagged64_type;
  else if (regnum >= VP0_REGNUM && regnum <= VP31_REGNUM)
    return data->pred_type;
  /* FIXME: it would be better to store all necessary types in DATA.  */
  else if (regnum == VPSP_LO_REGNUM)
    return tdesc_register_type (gdbarch, E2K_PSP_LO_REGNUM);
  else if (regnum == VPSP_HI_REGNUM)
    return tdesc_register_type (gdbarch, E2K_PSP_HI_REGNUM);
  else if (regnum == VCR0_LO_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR0_LO_REGNUM);
  else if (regnum == VCR0_HI_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR0_HI_REGNUM);
  else if (regnum == VCR1_LO_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR1_LO_REGNUM);
  else if (regnum == VCR1_HI_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR1_HI_REGNUM);
  else if (regnum == VPCSP_LO_REGNUM)
    return tdesc_register_type (gdbarch, E2K_PCSP_LO_REGNUM);
  else if (regnum == VPCSP_HI_REGNUM)
    return tdesc_register_type (gdbarch, E2K_PCSP_HI_REGNUM);
  else if (regnum == VWD_REGNUM)
    return tdesc_register_type (gdbarch, E2K_WD_REGNUM);
  else if (regnum == VBR_REGNUM)
    return tdesc_register_type (gdbarch, E2K_BR_REGNUM);
  else if (regnum == VPSP_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if (regnum == VPCSP_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if (regnum == VPC_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if (regnum >= VG0_REGNUM && regnum <= VG31_REGNUM)
    return data->tagged64_type;
  else if (regnum == VCR0_LO_NEXT_REGNUM)
    return data->pf_type;
  else if (regnum == VCR0_HI_NEXT_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR0_HI_REGNUM);
  else if (regnum == VCR1_LO_NEXT_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR1_LO_REGNUM);
  else if (regnum == VCR1_HI_NEXT_REGNUM)
    return tdesc_register_type (gdbarch, E2K_CR1_HI_REGNUM);
  else if (regnum == VSP_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if (regnum == VFP_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if (regnum == VIP_REGNUM)
    return builtin_type (gdbarch)->builtin_uint64;
  else if ((regnum >= VXR0_REGNUM && regnum <= VXR223_REGNUM)
           || (regnum >= VXB0_REGNUM && regnum <= VXB127_REGNUM)
           || (regnum >= VXG0_REGNUM && regnum <= VXG31_REGNUM))
    return data->tagged80_type;
  else if ((regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM)
	   || (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM))
    return builtin_type (gdbarch)->builtin_uint64;
  else if ((regnum >= VQPR0_REGNUM && regnum <= VQPR223_REGNUM)
           || (regnum >= VQPB0_REGNUM && regnum <= VQPB127_REGNUM)
           || (regnum >= VQPG0_REGNUM && regnum <= VQPG31_REGNUM))
    return data->tagged128_type;
    
  internal_error (_("invalid regnum"));
  return NULL;
}


static int
e2k_dwarf_reg_to_regnum (struct gdbarch *gdbarch, int reg)
{
  /* Our compiler enumerates `%r0 - %r63' from 0 to 63 and `%b[0] - %b[63]'
     from 64 to 127 in debug info respectively. TODO: find out why `%b[64] -
     %b[127]' are not assigned "GNU" numbers for use in debug info. */

  if (reg >= 0 && reg <= 63)
    return VDWR0_REGNUM + reg;
  else if (reg >= 64 && reg <= 127)
    return VDWB0_REGNUM + (reg - 64);

  return -1;
}


static int
number_alses (ULONGEST al)
{
  int i;
  int ret = 0;

  for (i = 0; i < 6; al >>= 1, i++)
    {
      if (al & 1)
        ret++;
    }

  return ret;
}


static CORE_ADDR
e2k_skip_prologue (struct gdbarch *gdbarch, CORE_ADDR pc)
{
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
  struct internalvar *hs = create_zero_ivar (data->hs_type);
  struct internalvar *al0 = create_zero_ivar (data->alf2_type);
  struct internalvar *cs1 = create_zero_ivar (data->c1f1_type);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);


  for (;;)
    {
      set_ivar_field (hs, "word",
                      read_memory_unsigned_integer (pc, 4, byte_order));

      if (ivar_field (hs, "word") == 0)
        {
          /* This corresponds to `nop' at the beginning of a function
             which may appear due to assembler awkwardness. TODO: verify
             whether HS == 0 actually means `nop. */

          /* In this case HS.lng == 0 */
          pc += 8;
          continue;
        }

      if (ivar_field (hs, "al") & 0x1)
        {
          /* GETSP may be encoded in ALS0 only. */
          CORE_ADDR al0_addr = pc + 4 + 4 * ivar_field (hs, "s");

          set_ivar_field
            (al0, "word",
             read_memory_unsigned_integer (al0_addr, 4, byte_order));

          if (ivar_field (al0, "opc") == 0x58)
            {
              /* It's GETSP. */
              pc += (ivar_field (hs, "lng") + 1) * 8;
              continue;
            }
        }

      if (ivar_field (hs, "c") & 0x2)
        {
          int opc;

          /* SETBR, SETR0 and SETR1 may be implemented in CS1 only. */
          CORE_ADDR cs1_addr
            = (pc + 4 + (ivar_field (hs, "s") ? 4 : 0)
               + (4 * number_alses (ivar_field (hs, "al")))
               /* Is CS0 present? */
               + 4 * (ivar_field (hs, "c") & 0x1));

          set_ivar_field (cs1, "word",
                          read_memory_unsigned_integer (cs1_addr, 4,
                                                        byte_order));

          opc = (int) ivar_field (cs1, "opc");

          /* Check if this is SETR{0,1} or SETBR respectively. */
          if (opc == 0 || opc == 1 || opc == 4)
            {
              /* It is. */
              pc += (ivar_field (hs, "lng") + 1) * 8;
              continue;
            }
        }

      break;
    }

  free_ivar (cs1);
  free_ivar (al0);
  free_ivar (hs);

  return pc;
}

constexpr gdb_byte e2k_stale_break_insn[]
= { 0x01, 0x00, 0x00, 0x04, 0x80, 0xc0, 0xc0, 0x0d };

constexpr gdb_byte e2k_setsft[]
= { 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28 };

static int
e2k_breakpoint_kind_from_pc (struct gdbarch *gdbarch, CORE_ADDR *pcptr)
{
  /* Fortunately both SETSFT and the legacy breakpoint instruction have the
     minimal possible instruction size of 8 bytes on E2K.  */
  return 8;
}

static const gdb_byte *
e2k_sw_breakpoint_from_kind (struct gdbarch *gdbarch, int kind, int *size)
{
  const struct target_desc *tdesc;

  *size = kind;

  /* FIXME: this function is called several times before target description is
     read on the native side and the inferior is run. For now I conservatively
     use the legacy breakpoint in such a case, which may turn out to be
     unworkable if its opcode is reused starting from `elbrus-v{X>=6}'.
     Therefore I wonder, if a breakpoint inserted at such an early stage does
     actually have any chance of being hit during execution. In case it's sure
     to be reinserted before running the inferior this is not a problem,
     otherwise . . .  */
  tdesc = gdbarch_target_desc (gdbarch);
  if (tdesc && tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v2.linux"))
    return e2k_setsft;

  return e2k_stale_break_insn;
}


static CORE_ADDR
e2k_read_pc (readable_regcache *regcache)
{
  ULONGEST cr0_hi_value;

  regcache->cooked_read (E2K_CR0_HI_REGNUM, &cr0_hi_value);
  return (cr0_hi_value >> 3) << 3;
}

static void
e2k_write_pc (struct regcache *regcache, CORE_ADDR new_pc)
{
  ULONGEST cr0_hi_value;
  ULONGEST cr1_lo_value;

  regcache_cooked_read_unsigned (regcache, E2K_CR0_HI_REGNUM, &cr0_hi_value);
  cr0_hi_value &= ~(-8LL);
  cr0_hi_value |= (ULONGEST)(new_pc >> 3) << 3;

  regcache_cooked_write_unsigned (regcache, E2K_CR0_HI_REGNUM, cr0_hi_value);

  /* Zero out `%cr1.lo.cui.ic' to avoid `exc_illegal_instr_addr' when resuming
     in another "Compilation Unit" in Protected Mode. This is required to make
     it possible to CALL functions coming from PM dynamic libraries (say, `call
     printf ("var == %d\n", var)' from within GDB when stopped in the main
     dynamic executable.  */
  regcache_cooked_read_unsigned (regcache, E2K_CR1_LO_REGNUM, &cr1_lo_value);
  cr1_lo_value &= 0xfeffffffffffffffULL;
  regcache_cooked_write_unsigned (regcache, E2K_CR1_LO_REGNUM, cr1_lo_value);

  /* ? ? ?  */
  regcache_cooked_write_unsigned (regcache, E2K_SYS_NUM_REGNUM, -1);
}


enum frame_cache_tag {
  E2K_FRAME_CACHE,
  E2K_SIGTRAMP_FRAME_CACHE
};

struct e2k_frame_cache
{
  enum frame_cache_tag tag;

  /* These ones are intended for the current frame. */

  CORE_ADDR psp_base;
  CORE_ADDR pcsp_base;

  /* User stack base for the current frame should be
     certainly used instead of procedure stack base
     (this_psp). Meanwhile I don't understand how the
     former can be obtained. */
  CORE_ADDR this_psp;
  CORE_ADDR func_pc;
  CORE_ADDR this_pcsp;

  /* These ones are intended for the previous one. */

  /* FIXME: I wonder whether the standalone (and redundant)
     caching of %b's may lead to an error or not. What if
     someone modifies %b[0] say as %r16 and then reads it
     as %b[0]? */

  CORE_ADDR r[224];
  CORE_ADDR b[128];

  /* These ones are to be unwound for all isets.  */
  ULONGEST psp_hi;
  ULONGEST pcsp_hi;

  /* These ones are to be unwound only on elbrus-v7.  */
  ULONGEST psp_lo;
  ULONGEST pcsp_lo;

  ULONGEST cr[4];
  ULONGEST wd;
  ULONGEST br;
  ULONGEST psp;
  ULONGEST pcsp;
  ULONGEST sp;
  ULONGEST pc;


};

/* Allocate and initialize a frame cache.  */

static struct e2k_frame_cache *
e2k_alloc_frame_cache (void)
{
  struct e2k_frame_cache *cache;

  cache = FRAME_OBSTACK_ZALLOC (struct e2k_frame_cache);
  cache->tag = E2K_FRAME_CACHE;
  return cache;
}

static struct e2k_frame_cache *
e2k_frame_cache (frame_info_ptr this_frame, void **this_cache,
                 CORE_ADDR pcsp_base)
{
  struct e2k_frame_cache *cache;
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);

  struct internalvar *prev_pcsp_hi;
  struct internalvar *prev_psp_hi;


  ULONGEST prev_pcsp, prev_psp;

  struct internalvar *cr0_hi;
  struct internalvar *cr1_lo;
  struct internalvar *cr1_hi;

  struct internalvar *wd;
  struct internalvar *prev_wd;

  struct internalvar *usd_lo;
  struct internalvar *usd_hi;

  int prev_wsz;

  struct internalvar *prev_br;
#if 0
    = create_zero_ivar (register_type (gdbarch, VBR_REGNUM));
#endif /* 0  */

  int prev_rbs;
  int prev_rsz;
  int prev_rcur;
  int i, j;
  int protected_mode;

  e2k_gdbarch_tdep *tdep;
  int is_elbrus_8c2;
  int psp_delta;

  if (*this_cache)
    return (struct e2k_frame_cache *) *this_cache;

  /* We may be called with `pcsp_base' explicity set to zero when getting the
     previous frame's registers. As far as I understand, this always happens
     when the previos frame has already been unwound and therefore the current
     frame's cache has already been filled in. In such a case we shouldn't find
     ourselves here.  */

  /* However, the `pcsp_base' parameter may turn out to be set to zero
     implicitly regardless of my intent when GDB is stopped with
     PTRACE_EVENT_EXEC. Therefore, there's no  assert here. Take this case into
     account when obtaining %cr's later so as not to try to load their contents
     from non-existing memory addresses.  */
  /* gdb_assert (pcsp_base != 0);  */

  protected_mode = gdbarch_ptr_bit (gdbarch) == 128;

  cache = e2k_alloc_frame_cache ();
  *this_cache = cache;


  prev_pcsp_hi = create_ivar_from_value
    (get_frame_register_value (this_frame, VPCSP_HI_REGNUM));

  prev_psp_hi = create_ivar_from_value
    (get_frame_register_value (this_frame, VPSP_HI_REGNUM));

  cr0_hi = create_ivar_from_value
    (get_frame_register_value (this_frame, VCR0_HI_REGNUM));

  cr1_lo = create_ivar_from_value
    (get_frame_register_value (this_frame, VCR1_LO_REGNUM));

  cr1_hi = create_ivar_from_value
    (get_frame_register_value (this_frame, VCR1_HI_REGNUM));

  wd = create_ivar_from_value
    (get_frame_register_value (this_frame, VWD_REGNUM));

  prev_wd = create_zero_ivar
    (register_type (gdbarch, VWD_REGNUM));


  prev_br = create_zero_ivar
    (register_type (gdbarch, VBR_REGNUM));

  usd_lo = create_ivar_from_value
    (get_frame_register_value (this_frame,
                               (protected_mode
                                ? E2K_PUSD_LO_REGNUM
                                : E2K_USD_LO_REGNUM)));

  usd_hi = create_ivar_from_value
    (get_frame_register_value (this_frame,
                               (protected_mode
                                ? E2K_PUSD_HI_REGNUM
                                : E2K_USD_HI_REGNUM)));



  cache->func_pc = get_frame_func (this_frame);

  cache->pc = ivar_field (cr0_hi, "ip") << 3;

  if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
    {
      set_ivar_field (prev_pcsp_hi, "ind",
		      ivar_field (prev_pcsp_hi, "ind") - 32);
      cache->pcsp_hi = ivar_field (prev_pcsp_hi, "dword");
    }
  else
    {
      struct internalvar *prev_pcsp_lo
	= create_ivar_from_value (get_frame_register_value (this_frame,
							    VPCSP_LO_REGNUM));
      set_ivar_field (prev_pcsp_lo, "ptr",
		      ivar_field (prev_pcsp_lo, "ptr") - 32);
      cache->pcsp_lo = ivar_field (prev_pcsp_lo, "dword");
      free_ivar (prev_pcsp_lo);

      /* The evaluation of the "previous" %pcsp_hi is to be implemented on
	 elbrus-v7 yet.  */
    }

  /* Cache the real Chain Stack base which may differ from the "resident" (or
     how should it be named?) one in %pcsp.lo.base in "deep" case.  */
  cache->pcsp_base = get_frame_register_unsigned (this_frame, E2K_PCSP_BASE);

  cache->this_pcsp
    = get_frame_register_unsigned (this_frame, VPCSP_REGNUM);

  if (cache->this_pcsp != 0)
    cache->pcsp = prev_pcsp = cache->this_pcsp - 32;
  else
    /* All this is because of the kernel incapable of providing us with
       valid values when the inferior is stopped with PTRACE_EVENT_EXEC. */
    cache->pcsp = prev_pcsp = 0;

  if (pcsp_base != 0 && prev_pcsp >= pcsp_base)
    {
      for (i = 0; i < 4; i++)
        cache->cr[i] =
          read_memory_integer (prev_pcsp + 8 * i, 8, byte_order);
    }
  else
    {
      for (i = 0; i < 4; i++)
        cache->cr[i] = 0;
    }


  if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
    {
      set_ivar_field (prev_psp_hi, "ind",
		      (ivar_field (prev_psp_hi, "ind")
		       - (ivar_field (cr1_lo, "wbs") << 5)));
      cache->psp_hi = ivar_field (prev_psp_hi, "dword");
    }
  else
    {
      struct internalvar *prev_psp_lo
	= create_ivar_from_value (get_frame_register_value (this_frame,
							    VPSP_LO_REGNUM));
      set_ivar_field (prev_psp_lo, "ptr",
		      (ivar_field (prev_psp_lo, "ptr")
		       - (ivar_field (cr1_lo, "wbs") << 5)));
      cache->psp_lo = ivar_field (prev_psp_lo, "dword");
      free_ivar (prev_psp_lo);

      /* The evaluation of the "previous" %psp_hi is to be implemented on
	 elbrus-v7 yet.  */
    }


  /* Cache the real Procedure Stack base which may differ from the "resident"
     (or how should it be named?) one in %psp.lo.base in "deep" case.  */
  cache->psp_base = get_frame_register_unsigned (this_frame, E2K_PSP_BASE);

  cache->this_psp
    = get_frame_register_unsigned (this_frame, VPSP_REGNUM);
  cache->psp = prev_psp =
    cache->this_psp - (ivar_field (cr1_lo, "wbs") << 5);

  if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
    {
      cache->sp = (ivar_field (usd_lo, "base") - ivar_field (usd_hi, "size")
		   + (ivar_field (cr1_hi, "ussz") << 4));

      if (protected_mode)
	cache->sp += (get_frame_register_unsigned (this_frame, E2K_USBR_REGNUM)
		      & 0xffffffff00000000ULL);
    }
  else
    {
#if 0
      cache->sp = (get_frame_register_unsigned (this_frame, VSP_REGNUM)
		   + get_frame_register_unsigned (this_frame, VUSFS_REGNUM));
#endif
    }


#define MAXSR_q 112

  set_ivar_field (prev_wd, "dword", 0);
  set_ivar_field
    (prev_wd, "base", ((((ivar_field (wd, "base") >> 4)
                         - ivar_field (cr1_lo, "wbs") + MAXSR_q)
                        % MAXSR_q) << 4));

  set_ivar_field (prev_wd, "size", ((ivar_field (wd, "psize") >> 4)
                                     + ivar_field (cr1_lo, "wbs")
                                     ) << 4);

  set_ivar_field (prev_wd, "psize",
                   ivar_field (cr1_lo, "wpsz") << 4);

  set_ivar_field (prev_wd, "fx", ivar_field (cr1_lo, "wfx"));
  cache->wd = ivar_field (prev_wd, "dword");

  prev_wsz = ivar_field (prev_wd, "size") >> 4;

  tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);
  is_elbrus_8c2 = tdep->num_elbrus_v5_pseudo_regs != 0;
  psp_delta = is_elbrus_8c2 ? 16 : 8;

  for (i = 0; i < 2 * prev_wsz; i++)
    cache->r[i]
      = (CORE_ADDR) (prev_psp + 32 * (i >> 1) + psp_delta * (i & 0x1));

  for (; i < 64; i++)
    cache->r[i] = 0;

  cache->br = ivar_field (cr1_hi, "br");
  set_ivar_field (prev_br, "dword", cache->br);

  prev_rbs = 2 * ivar_field (prev_br, "rbs");
  prev_rsz = 2 * (ivar_field (prev_br, "rsz") + 1);
  prev_rcur = 2 * ivar_field (prev_br, "rcur");

  for (i = 0; i < prev_rsz; i++)
    {
      j = prev_rbs + (prev_rcur + i) % prev_rsz;
      cache->b[i]
        = (CORE_ADDR) (prev_psp + 32 * (j >> 1) + psp_delta * (j & 0x1));
    }

  for (; i < 128; i++)
    cache->b[i] = 0;

  free_ivar (usd_hi);
  free_ivar (usd_lo);
  free_ivar (prev_br);
  free_ivar (prev_wd);
  free_ivar (wd);
  free_ivar (cr1_hi);
  free_ivar (cr1_lo);
  free_ivar (cr0_hi);
  free_ivar (prev_psp_hi);
  free_ivar (prev_pcsp_hi);

  return cache;
}

static void
e2k_frame_this_id (const frame_info_ptr &this_frame, void **this_cache,
                   struct frame_id *this_id)
{
  struct e2k_frame_cache *cache;
  CORE_ADDR hw_pcsp_base;

  /* HW_PCSP_BASE determined as `%pcsp_lo.base' may turn out to be not the real
     base of  chain stack, but of its resident area only (see Bug #75095 and
     external Bug #809, Comment #8), which may cut off backtrace output in case
     of deep recursion. To prevent this from happening, try to extract the
     actual base a specially designed register called `%pcsp_base'.  */

  hw_pcsp_base = (CORE_ADDR) get_frame_register_unsigned (this_frame,
                                                          E2K_PCSP_BASE);

  if (hw_pcsp_base == 0)
    {
      struct internalvar *hw_pcsp_lo
	= create_ivar_from_value (get_frame_register_value
				  (this_frame, E2K_PCSP_LO_REGNUM));

      if (! gdbarch_tdep<e2k_gdbarch_tdep> (get_frame_arch (this_frame))->is_elbrus_v7)
	{
	  /* If we were unable to obtain `%pcsp_base' (e.g. the Kernel
	     doesn't provide it via `/proc/PID/maps' yet) fall back to
	     `%pcsp_lo.base'.  */
	  hw_pcsp_base = ivar_field (hw_pcsp_lo, "base");
	}
      else
	{
	  /* FIXME: the underlying calculations are done as though
	     `AP.al_mode == 0' without even ensuring that this is
	     the case for now.  */
	  ULONGEST ind_biased;
	  LONGEST ind;
	  struct internalvar *hw_pcsp_hi
	    = create_ivar_from_value (get_frame_register_value
				      (this_frame, E2K_PCSP_HI_REGNUM));
	  ind_biased = ivar_field (hw_pcsp_hi, "ind_bsd_code");
	  if (ivar_field (hw_pcsp_hi, "ind_bsd_sign"))
	    ind_biased |= 0xfffffffff8000000;

	  /* += 2 ** (ind_size - 1) == 2 ** 26  */
	  ind = ((LONGEST) ind_biased + 0x4000000);
	  hw_pcsp_base = (ULONGEST) ((LONGEST) ivar_field (hw_pcsp_lo, "ptr")
				     - ind);
	  free_ivar (hw_pcsp_hi);
	}

      free_ivar (hw_pcsp_lo);
    }

  cache = e2k_frame_cache (this_frame, this_cache, hw_pcsp_base);

  if (/* When stopped with PTRACE_EVENT_EXEC we may have no available registers
         at all. There is no point in unwinding previous frames then.  */
      cache->pcsp == 0
      /* This is an actual outermost frame.  */
      || cache->pcsp <= hw_pcsp_base - 0x40
      /* We may not want to reach the actual outermost frame mentioned above
         since it almost certainly belongs to the kernel. Stop unwinding further
         if %cr0.hi of the current frame corresponds to the Kernel space. In
         order not to mix this situation up with signal frames, check %pcsp for
         the previous frame  as well. The two values below correspond to
         linux-2.6.33 and linux-3.10 respectively. The former lets us unwind
         two Kernel frames, while the latter only one. Don't abuse these
         shortcomings. */
      || ((cache->pcsp == hw_pcsp_base || cache->pcsp == hw_pcsp_base - 0x20)
          && (get_frame_register_unsigned (this_frame, VCR0_HI_REGNUM)
              & 0xff0000000000ull) == 0xe20000000000ull))
    return;

  /* Use offsets from the actual Procedure and Chain stack bases instead of
     absolute PSP and PCSP values respectively to let the frame be recognized
     after the Kernel relocates the inferior's HW stacks: this may turn out to
     be the case by the moment the analysis if bp_single_step breakpoint has
     been hit is done (the reason for Bug #146859).  */
  (*this_id) = frame_id_build_special (cache->this_psp - cache->psp_base,
				       cache->pc,
				       cache->this_pcsp - cache->pcsp_base);
}

static struct frame_id
e2k_dummy_id (struct gdbarch *gdbarch, const frame_info_ptr &this_frame)
{
  CORE_ADDR sp;

  /* How is it going to match `dummy_id' pushed into `dummy_frame_stack'
     if I build it in the same way as in `e2k_frame_this_id'? DUMMY_ID
     is obtained by means of frame_id_build (). I wonder why this works
     at IA-64. */

  sp = get_frame_register_unsigned (this_frame, VSP_REGNUM);

  return frame_id_build (sp, get_frame_pc (this_frame));
}

struct tagged_value_closure
{
  struct gdbarch *gdbarch;
  CORE_ADDR addr;
  int reg;
};

void
get_color_tags_from_mtags (gdb_byte mtags, gdb_byte *color, gdb_byte *tags)
{
  *color = mtags >> 5;
  if ((mtags & 0x10) == 0)
    {
      int i;
      for (i = 0; i < 4; i++)
	tags[i] = ((mtags & (0x1 << i)) == 0) ? 0x0 : 0x1;
    }
  else /* mtags.mt4 == 1  */
    {
      if ((mtags & 0x4) == 0 && (mtags & 0x8) == 0)
	{
	  int i;
	  for (i = 0; i < 2; i++)
	    tags[i] = ((mtags & (0x1 << i)) == 0) ? 0x0 : 0x1;

	  tags[3] = tags[2] = 0x3;
	}
      else if ((mtags & 0x4) != 0 && (mtags & 0x8) == 0)
	{
	  int i;
	  tags[1] = tags[0] = 0x3;

	  for (i = 0; i < 2; i++)
	    tags[i + 2] = (mtags & (0x1 << i) == 0) ? 0x0 : 0x1;
	}
      else if ((mtags & 0x1) != 0 && (mtags & 0x2) != 0
	       && (mtags & 0x4) != 0 && (mtags & 0x8) != 0)
	{
	  tags[3] = tags[2] = tags[1] = tags[0] = 0x3;
	}
      else
	{
	  /* If the currently "reserved" (according to iset-v7.single) case
	     turns out to be met stupidly set the external tags and the color
	     to 0.  */
	  tags[3] = tags[2] = tags[1] = tags[0] = 0x0;
	  *color = 0x0;
	}
    }
}

/* As far as I understand here one has to just "un-lazy" a
   value. */
static void
tagged_value_read (struct value *val)
{
  gdb_byte *buf;
  CORE_ADDR addr;
  int need_tagged;
  int size;
  struct tagged_value_closure *closure;
  struct gdbarch *gdbarch;
  struct e2k_gdbarch_data *data;
  struct type *val_type;
  int ext_off;

  closure = (struct tagged_value_closure *) val->computed_closure ();
  gdbarch = closure->gdbarch;
  data = get_e2k_gdbarch_data (gdbarch);

  /* I don't quite understand whether it may turn out that this
     function is called e.g. for a bitfield or not.
     For `tagged_value_write' it's certainly possible. */

  val_type = val->type ();
  need_tagged = (val_type == data->tagged64_type
                 || val_type == data->tagged80_type
		 || val_type == data->tagged128_type
		 || val_type == data->mem_tagged32_type
		 || val_type == data->mem_tagged64_type
                 || val_type == data->mem_signed_tagged32_type
                 || val_type == data->mem_signed_tagged64_type);

  if (need_tagged)
    {
      if (val_type == data->mem_tagged32_type
          || val_type == data->mem_signed_tagged32_type)
        size = 4;
      else if (val_type == data->tagged64_type
	       || val_type == data->mem_tagged64_type
               || val_type == data->mem_signed_tagged64_type)
        size = 8;
      else if (val_type == data->tagged80_type)
        size = 10;
      else /* if (val_type == data->tagged128_type)  */
	size = 16;
    }
  else
    size = val_type->length ();

  gdb_assert (size == 4 || size == 8 || size == 10 || size == 16);

  addr = closure->addr;

  /* Zero address is currently set for unavailable window registers.
     See the corresponding comment in e2k_frame_prev_register ().  */
  if (closure->reg && addr == 0)
    {
      val->mark_bytes_unavailable (0, val_type->length ());
      return;
    }

  buf = val->contents_raw ().data ();
  read_memory (addr, buf, size <= 8 ? size : 8);

  struct e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);
  ext_off = tdep->num_elbrus_v5_pseudo_regs != 0 ? 8 : 16;

  if (val_type == data->tagged80_type || val_type == data->tagged128_type)
    read_memory (addr + ext_off, buf + 8, size - 8);

  if (need_tagged)
    {
      if (! tdep->is_elbrus_v7)
	{
	  gdb_byte tag;
	  int i;

	  for (i = 0; i < size / 4; i++)
	    {
	      target_read (current_inferior ()->top_target (), TARGET_OBJECT_TAG, NULL,
			   &tag, addr + 4 * i + (i * 4 < 8 ? 0 : ext_off - 8), 1);
	      modify_field (val->type (), buf + size, (LONGEST) tag,
			    2 * i, 2);
	    }
	}
      else
	{
	  CORE_ADDR aligned_addr = addr & (-16ULL);
	  gdb_byte mtags = 0;
	  gdb_byte color;
	  gdb_byte tags[4];
	  int i;

	  for (i = 3; i >= 0; i--)
	    {
	      gdb_byte mtag;
	      target_read (current_inferior ()->top_target (), TARGET_OBJECT_TAG,
			   NULL, &mtag, aligned_addr + 4 * i, 1);
	      mtags <<= 2;
	      mtags |= mtag;
	    }

	  get_color_tags_from_mtags (mtags, &color, &tags[0]);

	  for (i = 0; i < size / 4; i++)
	    {
	      /* FIXME(?): tags[] should probably be assigned starting from
		 `(addr - aligned_addr) / 4', not from 0. The case in which
		 tags from 2 consequent 16-byte QWORDs could be required
		 should be impossible, though.  */
	      modify_field (val->type (), buf + size,
			    (LONGEST) tags[i + (addr - aligned_addr) / 4],
			    2 * i, 2);
	    }

	  if (val_type == data->mem_tagged32_type
	      || val_type == data->mem_signed_tagged32_type
	      || val_type == data->mem_tagged64_type
	      || val_type == data->mem_signed_tagged64_type)
	    modify_field (val->type (), buf + size, (LONGEST) color,
			  2 * i, 3);
	}
    }
}

/* FIXME: consider getting rid of this macro now that it's no longer provided
   by `gdb/defs.h'.  */
#define MAX_REGISTER_SIZE 64

static void
tagged_value_write (struct value *toval, struct value *fromval)
{

  /* This piece of code is mostly (except setting tags)
     borrowed from `value_assign' for `lval_memory'-toval. */

  gdb_byte buffer[MAX_REGISTER_SIZE];
  gdb_byte tag[2];
  struct type *type;
  CORE_ADDR regaddr;

  struct tagged_value_closure *closure;
  struct gdbarch *gdbarch;
  struct e2k_gdbarch_data *data;
  struct value *parent;
  struct type *parent_type;
  struct type *struct_type;
  int need64 = 0;

  type = toval->type ();

  /* FIXME: this piece of code needs a better understanding. */
  gdb_assert (toval->bitsize () != 0);

  parent = toval->parent ();
  parent_type = parent->type ();

  closure = (struct tagged_value_closure *) parent->computed_closure ();
  gdbarch = closure->gdbarch;
  data = get_e2k_gdbarch_data (gdbarch);

  gdb_assert (parent_type == data->mem_tagged64_type
              || parent_type == data->mem_tagged32_type
              || parent_type == data->mem_signed_tagged64_type
              || parent_type == data->mem_signed_tagged32_type);

  need64 = (parent_type == data->mem_tagged64_type
            || parent_type == data->mem_signed_tagged64_type);

  /* Try this so as not to replicate here `read_memory'
     and `target_read (TARGET_OBJECT_TAG)'. */
  tagged_value_read (parent);

  memcpy (buffer, parent->contents ().data (), parent_type->length ());

  modify_field (type, (buffer + parent->offset ()
                       + toval->offset ()),
                value_as_long (fromval),
                toval->bitpos (),
                toval->bitsize ());

  regaddr = closure->addr;
  write_memory (regaddr, buffer, need64 ? 8 : 4);

  /* I don't know whether  observer_notify_memory_changed (. . . )
     is really required here and if "yes" what it is needed
     for. */

  struct_type = parent_type->field (1).type ();
  tag[0] = (gdb_byte) unpack_field_as_long (struct_type, buffer, 1);

  if (need64)
    tag[1] = (gdb_byte) unpack_field_as_long (struct_type, buffer, 2);

  target_write (current_inferior ()->top_target (), TARGET_OBJECT_TAG, NULL,
                tag, regaddr, need64 ? 2 : 1);
}

static void *
tagged_copy_closure (const struct value *v)
{
  struct tagged_value_closure *copy =
    (struct tagged_value_closure *)
    xzalloc (sizeof (struct tagged_value_closure));

  memcpy (copy, v->computed_closure (),
          sizeof (struct tagged_value_closure));

  return copy;
}

static void
tagged_free_closure (struct value *v)
{
  xfree (v->computed_closure ());
}

/* Return an address of a tagged register output by `info frame'.  */
static CORE_ADDR
tagged_get_addr (struct value *v)
{
  struct tagged_value_closure *closure;
  closure = (struct tagged_value_closure *) v->computed_closure ();

  return closure->addr;
}


static struct lval_funcs tagged_value_funcs =
  {
    tagged_value_read,
    tagged_value_write,
    NULL, /* is_optimized_out  */
    NULL, /* indirect  */
    NULL, /* coerce_ref  */
    NULL, /* check_synthetic_pointer  */
    tagged_copy_closure,
    tagged_free_closure,
    tagged_get_addr
  };

static int
real_pred_num (struct internalvar *br, int rnum)
{
  if (rnum <= (int) ivar_field (br, "psz"))
    rnum = (((int) ivar_field (br, "pcur") + rnum)
            % ((int) ivar_field (br, "psz") + 1));

  return rnum;
}


/* FIXME: the usage of VCR0_LO_NEXT_REGNUM for preds as well as the fact, that
   VALUE_FRAME_ID (pred_val) corresponds to the CURRENT frame rather than to
   the NEXT one, is probably a bad idea. As a result I cannot get access to
   preds of the frame previous to the outermost, because this frame turns out
   to be NULL. E.g., when `backtrace past-main' is not set, the frame previous
   to that of main () is NULL. If we were to output any info on previous frame's
   preds via `info frame', which would lead to invocation of
   `pred_value_read ()', we would definitely crash inside it.  */
static void
pred_value_read (struct value *val)
{
  char vfld_name[8];
  char tfld_name[8];

  struct internalvar *pf;
  struct internalvar *tmp;
  int rnum;
  frame_info_ptr this_frame;
  struct gdbarch *gdbarch;
  struct e2k_gdbarch_data *data;

  this_frame = frame_find_by_id (val->next_frame_id ());

  if (this_frame == NULL)
    {
      /* This happens when running `info frame' in the outermost frame, see
         also the comment above. Luckily, we don't output predicates via
         `info frame' . . . because they are not saved to particular memory
         addresses in the "traditional" sense. Therefore, just mark VAL as
         unavailable.  */

      val->mark_bytes_unavailable (0, val->type ()->length ());
      return;
    }

  gdbarch = get_frame_arch (this_frame);
  data = get_e2k_gdbarch_data (gdbarch);

  gdb_assert (val->type () == data->pred_type);

  tmp = create_zero_ivar (val->type ());



  rnum = ((int *) val->computed_closure ())[0];



  sprintf (vfld_name, "val%d", rnum);
  sprintf (tfld_name, "tag%d", rnum);

  pf = create_ivar_from_value
    (get_frame_register_value (this_frame, VCR0_LO_NEXT_REGNUM));

  set_ivar_field (tmp, "bval", ivar_field (pf, vfld_name));
  set_ivar_field (tmp, "t", ivar_field (pf, tfld_name));

  memcpy (val->contents_raw ().data (),
          value_of_internalvar (gdbarch, tmp)->contents ().data (),
          val->type ()->length ());

  free_ivar (tmp);
  free_ivar (pf);
}


static void
pred_value_write (struct value *toval, struct value *fromval)
{
  frame_info_ptr this_frame;
  struct gdbarch *gdbarch;
  struct e2k_gdbarch_data *data;


  this_frame = frame_find_by_id (toval->next_frame_id ());
  gdbarch = get_frame_arch (this_frame);
  data = get_e2k_gdbarch_data (gdbarch);

  if (toval->bitsize ())
    {
#if 0
      /* To be removed along with the setting of this variable below.  */
      struct type *type;
#endif /* 0  */
      struct value *parent;
      struct type *parent_type;
      int rnum;
      struct value *pf;
      struct internalvar *src;
      struct internalvar *dst;
      char vfld_name[8];
      char tfld_name[8];

#if 0
      type = toval->type ();
#endif /* 0  */
      parent = toval->parent ();
      parent_type = parent->type ();

      gdb_assert (parent_type == data->pred_type);

      rnum = ((int *) parent->computed_closure ())[0];

      pred_value_read (parent);

      src = create_ivar_from_value (parent);

      /* A rather suspicious piece of code . . . */
      set_internalvar_component
        (src, parent->offset () + toval->offset (),
         toval->bitpos (), toval->bitsize (),
         fromval);


      pf = get_frame_register_value (this_frame, VCR0_LO_NEXT_REGNUM);
      dst = create_ivar_from_value (pf);

      sprintf (vfld_name, "val%d", rnum);
      sprintf (tfld_name, "tag%d", rnum);

      set_ivar_field (dst, vfld_name, ivar_field (src, "bval"));
      set_ivar_field (dst, tfld_name, ivar_field (src, "t"));

      value_assign (pf, value_of_internalvar (gdbarch, dst));

    }
}

static void *
pred_copy_closure (const struct value *v)
{
  int *copy = (int *) xzalloc (sizeof (int));
  *copy = * (int *) v->computed_closure ();
  return copy;
}

static void
pred_free_closure (struct value *v)
{
  xfree (v->computed_closure ());
}

static struct lval_funcs pred_value_funcs =
  {
    pred_value_read,
    pred_value_write,
    NULL, /* is_optimized_out  */
    NULL, /* indirect  */
    NULL, /* coerce_ref  */
    NULL, /* check_synthetic_pointer  */
    pred_copy_closure,
    pred_free_closure,
    NULL,
  };

static struct value *
e2k_frame_prev_register (const frame_info_ptr &this_frame,
                         void **this_cache, int regnum)
{
  struct gdbarch *gdbarch = get_frame_arch (this_frame);
  /* The exact value of PCSP_BASE parameter should be insignificant here, since
     THIS_FRAME's cache has already been built by the time we find ourselves
     here, hasn't it? See `gdb_assert (pcsp_base != 0)' within the callee.  */
  struct e2k_frame_cache *cache
    = e2k_frame_cache (this_frame, this_cache, 0);

  int based = 0, rnum;

  if ((regnum >= VR0_REGNUM && regnum <= VR223_REGNUM
       && ((rnum = regnum - VR0_REGNUM) >= 0))
      || (regnum >= VXR0_REGNUM && regnum <= VXR223_REGNUM
          && ((rnum = regnum - VXR0_REGNUM) >= 0))
      || (regnum >= VQPR0_REGNUM && regnum <= VQPR223_REGNUM
          && ((rnum = regnum - VQPR0_REGNUM) >= 0))
      || (regnum >= VB0_REGNUM && regnum <= VB127_REGNUM
          && (based = 1, (rnum = regnum - VB0_REGNUM) >= 0))
      || (regnum >= VXB0_REGNUM && regnum <= VXB127_REGNUM
          && (based = 1, (rnum = regnum - VXB0_REGNUM) >= 0))
      || (regnum >= VQPB0_REGNUM && regnum <= VQPB127_REGNUM
          && (based = 1, (rnum = regnum - VQPB0_REGNUM) >= 0)))
    {

      CORE_ADDR *r = (based ? cache->b : cache->r);
      struct value *ret;
      struct tagged_value_closure *closure
        = ((struct tagged_value_closure *)
	   xzalloc (sizeof (struct tagged_value_closure)));

      /* Probably in this very case it's not necessary to copy closure.
         However, in other cases where we also use tagged values this becomes
         necessary. */
      closure->gdbarch = gdbarch;

      /* Keep in mind that cache->r[rnum] is set to zero for unavailable window
         registers. The corresponding values are going to be marked as
         unavailable in their read method further.  */
      closure->addr = r[rnum];

      /* This is required in order to find out whether the user tries to access
         an unavailable window register or a zero memory address. In the latter
         case an exception should be thrown.  */
      closure->reg = 1;

      ret = value::allocate_computed
        (register_type (gdbarch, regnum), &tagged_value_funcs,
         closure);

      ret->set_next_frame_id (get_frame_id (this_frame));
      return ret;
    }
  else if (regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM)
    {
      return frame_unwind_got_memory (this_frame, regnum,
                                      cache->r[regnum - VDWR0_REGNUM]);
    }
  else if (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM)
    {
      return frame_unwind_got_memory (this_frame, regnum,
                                      cache->b[regnum - VDWB0_REGNUM]);
    }
  else if (regnum >= VP0_REGNUM && regnum <= VP31_REGNUM)
    {
      struct value *ret;
      int *prnum = (int *) xzalloc (sizeof (int));
      struct internalvar *br;

      br = create_ivar_from_value
        (frame_unwind_register_value (this_frame, VBR_REGNUM));
      *prnum = real_pred_num (br, regnum - VP0_REGNUM);
      free_ivar (br);

      /* FIXME: passing `rnum' as a closure. */
      ret = value::allocate_computed (register_type (gdbarch, regnum),
				      &pred_value_funcs, prnum);

      /* `this_frame' here means actually `next frame'. */
      ret->set_next_frame_id (get_frame_id (get_prev_frame (this_frame)));
      return ret;

    }
  /* Missing predicates meanwhile. */

  /* The value of VPSP_LO_REGNUM is frame-independent on elbrus-v{X<7}. */
  else if (regnum == VPSP_LO_REGNUM && gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->psp_lo);
    }
  else if (regnum == VPSP_HI_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->psp_hi);
    }
  else if (regnum >= VCR0_LO_REGNUM && regnum <= VCR1_HI_REGNUM)
    {
      rnum = regnum - VCR0_LO_REGNUM;
      return frame_unwind_got_constant (this_frame, regnum, cache->cr[rnum]);
    }
  else if (regnum == VCR0_LO_NEXT_REGNUM)
    {
      /* Unlike `%cr0.lo' and others `%cro.lo_for_the_NEXT_frame'
         should be writeable. */
      return frame_unwind_got_memory (this_frame, regnum, cache->this_pcsp);
    }
  /* The value of VPCSP_LO_REGNUM is frame-independent on elbrus-v{X<7}. */
  else if (regnum == VPCSP_LO_REGNUM && gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->pcsp_lo);
    }
  else if (regnum == VPCSP_HI_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->pcsp_hi);
    }
  else if (regnum == VWD_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->wd);
    }
  else if (regnum == VBR_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->br);
    }
  else if (regnum == VPSP_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->psp);
    }
  else if (regnum == VPCSP_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->pcsp);
    }
  else if (regnum == VPC_REGNUM || regnum == VIP_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->pc);
    }
  else if (regnum == VSP_REGNUM)
    {
      return frame_unwind_got_constant (this_frame, regnum, cache->sp);
    }
  else if (regnum == VFP_REGNUM)
    {
      return frame_unwind_register_value (get_prev_frame (this_frame),
                                          VSP_REGNUM);
    }

  return frame_unwind_got_register (this_frame, regnum, regnum);
}



static const struct frame_unwind e2k_frame_unwind =
{
  "e2k unwinder",
  NORMAL_FRAME,
  default_frame_unwind_stop_reason,
  e2k_frame_this_id,
  e2k_frame_prev_register,
  NULL,
  default_frame_sniffer
};

struct e2k_sigtramp_cache
{
  enum frame_cache_tag tag;
  readonly_detached_regcache *regcache;
};

static void
e2k_sigtramp_frame_this_id (const frame_info_ptr &this_frame, void **this_cache,
                            struct frame_id *this_id)
{
  struct internalvar *hw_pcsp_lo;
  CORE_ADDR hw_pcsp_base;

  CORE_ADDR pcsp_base;
  CORE_ADDR psp_base;
  CORE_ADDR this_pcsp, pcsp;
  CORE_ADDR this_psp;
  CORE_ADDR pc;
  struct internalvar *cr0_hi;

  if (*this_cache == NULL)
    {
      e2k_frame_this_id (this_frame, this_cache, this_id);
      return;
    }

  pcsp_base = get_frame_register_unsigned (this_frame, E2K_PCSP_BASE);
  psp_base = get_frame_register_unsigned (this_frame, E2K_PSP_BASE);

  this_pcsp = get_frame_register_unsigned (this_frame, VPCSP_REGNUM);
  if (this_pcsp != 0)
    pcsp = this_pcsp - 32;
  else
    pcsp = 0;

  this_psp = get_frame_register_unsigned (this_frame, VPSP_REGNUM);

  cr0_hi = create_ivar_from_value
    (get_frame_register_value (this_frame, VCR0_HI_REGNUM));
  pc = ivar_field (cr0_hi, "ip") << 3;

  hw_pcsp_lo = create_ivar_from_value
    (get_frame_register_value (this_frame, E2K_PCSP_LO_REGNUM));

  if (! gdbarch_tdep<e2k_gdbarch_tdep> (get_frame_arch (this_frame))->is_elbrus_v7)
    {
      /* If we were unable to obtain `%pcsp_base' (e.g. the Kernel
	 doesn't provide it via `/proc/PID/maps' yet) fall back to
	 `%pcsp_lo.base'.  */
      hw_pcsp_base = ivar_field (hw_pcsp_lo, "base");
    }
  else
    {
      /* FIXME: the underlying calculations are done as though
	 `AP.al_mode == 0' without even ensuring that this is
	 the case for now.  */
      ULONGEST ind_biased;
      LONGEST ind;
      struct internalvar *hw_pcsp_hi
	= create_ivar_from_value (get_frame_register_value
				  (this_frame, E2K_PCSP_HI_REGNUM));
      ind_biased = ivar_field (hw_pcsp_hi, "ind_bsd_code");
      if (ivar_field (hw_pcsp_hi, "ind_bsd_sign"))
	ind_biased |= 0xfffffffff8000000;

      /* += 2 ** (ind_size - 1) == 2 ** 26  */
      ind = ((LONGEST) ind_biased + 0x4000000);
      hw_pcsp_base = (ULONGEST) ((LONGEST) ivar_field (hw_pcsp_lo, "ptr")
				 - ind);
      free_ivar (hw_pcsp_hi);
    }

  free_ivar (hw_pcsp_lo);


  /* Let's consider the next-to-outermost frame to be outermost.
     This is justified by the following considerations:

     a. a user shouldn't get access to the outermost frame which is
        located inside the Kernel;

     b. no additional check is required in e2k_frame_cache () when
        obtaining register values related to the previous frame since
        it always physically exists (in case it doesn't physically
        exist we may very well get a memory access error when trying
        to obtain its CR's and so on).

     Here we compare %pcsp for the previous frame with %pcsp_lo.base.  */

  if (pcsp == hw_pcsp_base)
    return;

  /* See the respective comment in e2k_frame_this_id () on why offsets from the
     actual HW stacks' bases are used here.  */
  (*this_id) = frame_id_build_special (this_psp - psp_base, pc,
				       this_pcsp - pcsp_base);
}


static struct value *
e2k_sigtramp_frame_prev_register (const frame_info_ptr &this_frame,
                                  void **this_cache, int regnum)
{
  struct e2k_sigtramp_cache *cache = (struct e2k_sigtramp_cache *) *this_cache;

  /* If our cache isn't ready yet use ordinary frame's methods to unwind
     registers for previous frame.  */
  if (cache == NULL || cache->tag == E2K_FRAME_CACHE)
    return e2k_frame_prev_register (this_frame, this_cache, regnum);

  return cache->regcache->cooked_read_value (regnum);
}


static enum register_status
get_prev_to_sigtramp_register (frame_info_ptr fi,
			       int regnum,
			       gdb::array_view<gdb_byte> buf)
{
  /* This function is `void'. How is it going to signalize an error if one is
     possible here at all?  */
  try
    {
      get_frame_register (fi, regnum, buf.data ());
    }
  catch (const gdb_exception_error &ex)
    {
      if (ex.reason < 0 && ex.error == NOT_AVAILABLE_ERROR)
	return REG_UNAVAILABLE;
    }

  /* What meaningful value can I return?  */
  return REG_VALID;
}

static int
e2k_sigtramp_frame_sniffer (const struct frame_unwind *self,
                            const frame_info_ptr &this_frame,
                            void **this_prologue_cache)
{
  CORE_ADDR pc = get_frame_pc (this_frame);
  if ((pc >> 40) == 0xff)
    return 1;

  return 0;
}

static const struct frame_unwind e2k_sigtramp_frame_unwind =
{
  "e2k sigtramp unwinder",
  SIGTRAMP_FRAME,
  default_frame_unwind_stop_reason,
  e2k_sigtramp_frame_this_id,
  e2k_sigtramp_frame_prev_register,
  NULL,
  e2k_sigtramp_frame_sniffer,
  NULL // e2k_sigtramp_dealloc_cache
};

static CORE_ADDR
e2k_unwind_pc (struct gdbarch *gdbarch, const frame_info_ptr &next_frame)
{
  return frame_unwind_register_unsigned (next_frame, VPC_REGNUM);
}


static enum register_status
e2k_pseudo_register_read (struct gdbarch *gdbarch,
			  readable_regcache *regcache,
                          int regnum, gdb_byte *buf)
{
  enum register_status ret = REG_VALID;
  /* Inside these function "raw" register reads provide the values
     for the current sentinel frame, while "cooked" ones for the
     previous frame. */

  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);

  if ((regnum >= VR0_REGNUM && regnum <= VR223_REGNUM)
      || (regnum >= VXR0_REGNUM && regnum <= VXR223_REGNUM)
      || (regnum >= VQPR0_REGNUM && regnum <= VQPR223_REGNUM)
      || (regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM))
    {
      e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);
      int is_elbrus_8c2 = tdep->num_elbrus_v5_pseudo_regs != 0;
      struct internalvar *cr1_lo = create_ivar_from_reg
        (gdbarch, regcache, E2K_CR1_LO_REGNUM);

      struct internalvar *wd;
      int ext, dwarf, qp;
      int rnum;
      struct type *rtype;

      ext = (regnum >= VXR0_REGNUM && regnum <= VXR223_REGNUM);
      dwarf = (regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM);
      qp = (regnum >= VQPR0_REGNUM && regnum <= VQPR223_REGNUM);

      if (ext)
        rnum = regnum - VXR0_REGNUM;
      else if (dwarf)
        rnum = regnum - VDWR0_REGNUM;
      else if (qp)
	rnum = regnum - VQPR0_REGNUM;
      else
        rnum = regnum - VR0_REGNUM;

      rtype = (ext ? data->tagged80_type : data->tagged64_type);

      if (rnum < 2 * ivar_field (cr1_lo, "wbs"))
        {
          CORE_ADDR addr;
          ULONGEST psp;
          gdb_byte tag[2];

          regcache->cooked_read (VPSP_REGNUM, &psp);
          addr = (psp + 32 * (rnum >> 1)
                  + (is_elbrus_8c2 ? 16 : 8) * (rnum & 0x1));

          read_memory (addr, buf, 8);
          if (ext || qp)
            read_memory (addr + (is_elbrus_8c2 ? 8 : 16), buf + 8,
			 ext ? 2 : 8);

          if (!dwarf)
            {
	      int i;
	      for (i = 0; i < (qp ? 2 : 1); i++)
		{
		  int j;

		  /* Note that qp case always implies elbrus-v5-specific layout
		     of procedure stack. This is implicitly used below in `addr
		     + 8 * i'.  */
		  target_read (current_inferior ()->top_target (), TARGET_OBJECT_TAG, NULL, tag,
			       addr + 8 * i, 2);
		  // This is inappropriate for elbrus-v7!!!  */
		  for (j = 0; j < 2; j++)
		    modify_field (rtype, buf + (qp ? 16 : (ext ? 10 : 8)),
				  (LONGEST) tag[j], 4 * i +  2 * j, 2);
		}
            }

          free_ivar (cr1_lo);
          /* FIXME: maybe it's better to use `do {...} while (0);' and
             to `break' here so that we have only one valid `return' ? */
          return REG_VALID;
        }

      wd = create_ivar_from_reg (gdbarch, regcache, VWD_REGNUM);


      if (rnum < (ivar_field (wd, "size") >> 3)
          && (rnum -= 2 * ivar_field (cr1_lo, "wbs")) <= 6)
        {
          /* As a matter of fact, E2K_{RVAL,SYS_NUM,ARG*}_REGNUM's are
             not tagged and I can't find where their tags in asm/user.h.
             What am I going to obtain here then?!!!
          */
          regcache->raw_read (E2K_SYS_NUM_REGNUM + rnum, buf);
        }
      else
        ret = REG_UNAVAILABLE;

      free_ivar (wd);
      free_ivar (cr1_lo);
    }
  else if ((regnum >= VB0_REGNUM && regnum <= VB127_REGNUM)
           || (regnum >= VXB0_REGNUM && regnum <= VXB127_REGNUM)
           || (regnum >= VQPB0_REGNUM && regnum <= VQPB127_REGNUM)
	   || (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM))
    {
      int base, rbase, rnum;
      struct internalvar *br;

      if (regnum >= VQPB0_REGNUM && regnum <= VQPB127_REGNUM)
        {
          base = VQPB0_REGNUM;
          rbase = VQPR0_REGNUM;
        }
      else if (regnum >= VXB0_REGNUM && regnum <= VXB127_REGNUM)
        {
          base = VXB0_REGNUM;
          rbase = VXR0_REGNUM;
        }
      else if (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM)
	{
	  base = VDWB0_REGNUM;
	  rbase = VDWR0_REGNUM;
	}
      else
        {
          base = VB0_REGNUM;
          rbase = VR0_REGNUM;
        }
      
      rnum = regnum - base;

      br = create_ivar_from_reg (gdbarch, regcache, VBR_REGNUM);

      if (rnum < 2 * (ivar_field (br, "rsz") + 1))
        {
          /* Now that we can access the whole window via register aliases
             %r0 . . . %r223 this should be correct. */

          rnum = (2 * ivar_field (br, "rbs")
                  + ((2 * ivar_field (br, "rcur") + rnum)
                     % (2 * (ivar_field (br, "rsz") + 1))));

          ret = regcache->cooked_read (rnum + rbase, buf);
        }
      else
        ret = REG_UNAVAILABLE;

      free_ivar (br);
    }
  else if (regnum >= VP0_REGNUM && regnum <= VP31_REGNUM)
    {
      struct internalvar *br;
      struct internalvar *cr0_lo;
      struct internalvar *pred;
      int rnum;
      char vfld_name[8];
      char tfld_name[8];


      /* All these tricks with getting `dw' and further setting
         `dword' field look boring . . . */
      br = create_ivar_from_reg (gdbarch, regcache, VBR_REGNUM);
      rnum = real_pred_num (br, regnum - VP0_REGNUM);
      sprintf (vfld_name, "val%d", rnum);
      sprintf (tfld_name, "tag%d", rnum);
      free_ivar (br);

      cr0_lo = create_ivar_from_reg (gdbarch, regcache, VCR0_LO_NEXT_REGNUM);

      pred = create_zero_ivar (register_type (gdbarch, rnum + VP0_REGNUM));
      set_ivar_field (pred, "bval", ivar_field (cr0_lo, vfld_name));
      set_ivar_field (pred, "t", ivar_field (cr0_lo, tfld_name));
      free_ivar (cr0_lo);

      /* This also looks a bit complicated . . . Why should I
         temporarily migrate to integers? */
      store_unsigned_integer (buf, register_size (gdbarch, rnum + VP0_REGNUM),
                              byte_order, ivar_field (pred, "word"));

      free_ivar (pred);
    }
  else if (regnum == VPSP_LO_REGNUM)
    {
      if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	regcache->raw_read (E2K_PSP_LO_REGNUM, buf);
      else
	{
	  struct internalvar *cr1_lo = create_ivar_from_reg (gdbarch, regcache,
							     E2K_CR1_LO_REGNUM);
	  struct internalvar *psp_lo = create_ivar_from_reg (gdbarch, regcache,
							     E2K_PSP_LO_REGNUM);

	  set_ivar_field (psp_lo, "ptr",
			  (ivar_field (psp_lo, "ptr")
			   - 32 * ivar_field (cr1_lo, "wbs")));

	  store_unsigned_integer (buf, register_size (gdbarch, regnum),
				  byte_order,
				  ivar_field (psp_lo, "dword"));
	  free_ivar (psp_lo);
	  free_ivar (cr1_lo);
	}
    }
  else if (regnum == VPSP_HI_REGNUM)
    {
      if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	{
	  struct internalvar *cr1_lo = create_ivar_from_reg (gdbarch, regcache,
							     E2K_CR1_LO_REGNUM);
	  struct internalvar *psp_hi = create_ivar_from_reg (gdbarch, regcache,
							     E2K_PSP_HI_REGNUM);

	  set_ivar_field (psp_hi, "ind",
			  (ivar_field (psp_hi, "ind")
			   - 32 * ivar_field (cr1_lo, "wbs")));

	  store_unsigned_integer (buf, register_size (gdbarch, regnum),
				  byte_order,
				  ivar_field (psp_hi, "dword"));

	  free_ivar (cr1_lo);
	}
      else
	{
	  /* FIXME: E2K_PSP_HI_REGNUM should be "unwound" for each frame as
	     well as E2K_PSP_LO_REGNUM on elbrus-v7. However, this is not
	     crucial for evaluation of "pcsp" for chain stack access in each
	     frame as it is provided by `%PCSP_LO.ptr'.  */
	  regcache->raw_read (E2K_PSP_HI_REGNUM, buf);
	}
    }
  else if (regnum >= VCR0_LO_REGNUM && regnum <= VCR1_HI_REGNUM)
    {
      ULONGEST pcsp, val;
      CORE_ADDR addr;

      regcache->cooked_read (VPCSP_REGNUM, &pcsp);
      if (pcsp)
        {
          addr = pcsp + 8 * (regnum - VCR0_LO_REGNUM);
          /* Should one use register_size () here ? */
          val = read_memory_unsigned_integer (addr, 8, byte_order);
          store_unsigned_integer (buf, register_size (gdbarch, regnum),
                                  byte_order, val);
        }
      else
        /* When stopped with PTRACE_EVENT_EXEC we don't actually have
           chain stack. Long live our Kernel! */
        memset (buf, 0, register_size (gdbarch, regnum));
    }
  else if (regnum >= VCR0_LO_NEXT_REGNUM && regnum <= VCR1_HI_NEXT_REGNUM)
    {
      /* I use `E2K_CR0_LO_REGNUM' directly meanwhile (see in this function
         above). This is because I don't understand how to get a
         `struct value' with regcache-functions. There seems to be a drastic
         difference in interface when dealing with regcaches and frames . . .
         Because of this at present I shouldn't find myself here. */
      /* gdb_assert (0); */
      regcache->raw_read ((E2K_CR0_LO_REGNUM
			   + (regnum - VCR0_LO_NEXT_REGNUM)),
			  buf);
    }
  else if (regnum == VPCSP_LO_REGNUM)
    {
      if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	regcache->raw_read (E2K_PCSP_LO_REGNUM, buf);
      else
	{
	  struct internalvar *pcsp_lo
	    = create_ivar_from_reg (gdbarch, regcache, E2K_PCSP_LO_REGNUM);
	  ULONGEST pcsp_lo_ptr = ivar_field (pcsp_lo, "ptr");

	  if (pcsp_lo_ptr)
	    pcsp_lo_ptr -= 32;

	  set_ivar_field (pcsp_lo, "ptr", pcsp_lo_ptr);
	  store_unsigned_integer (buf, register_size (gdbarch, regnum),
				  byte_order, ivar_field (pcsp_lo, "dword"));
	  free_ivar (pcsp_lo);
	}
    }
  else if (regnum == VPCSP_HI_REGNUM)
    {
      if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	{
	  struct internalvar *pcsp_hi
	    = create_ivar_from_reg (gdbarch, regcache, E2K_PCSP_HI_REGNUM);
	  ULONGEST pcsp_hi_ind = ivar_field (pcsp_hi, "ind");

	  if (pcsp_hi_ind)
	    pcsp_hi_ind -= 32;

	  set_ivar_field (pcsp_hi, "ind", pcsp_hi_ind);
	  store_unsigned_integer (buf, register_size (gdbarch, regnum),
				  byte_order, ivar_field (pcsp_hi, "dword"));
	  free_ivar (pcsp_hi);
	}
      else
	/* FIXME: E2K_PCSP_HI_REGNUM should be updated for each frame as well as
	   E2K_PCSP_LO_REGNUM on elbrus-v7. However, this is not crucial for
	   evaluation of "pcsp" for chain stack access in each frame as it is
	   provided by `%PCSP_LO.ptr'.  */
	regcache->raw_read (E2K_PCSP_HI_REGNUM, buf);
    }
  else if (regnum == VWD_REGNUM)
    {
      struct internalvar *wd = create_ivar_from_reg
        (gdbarch, regcache, E2K_WD_REGNUM);

      struct internalvar *new_wd = create_zero_ivar
        (register_type (gdbarch, E2K_WD_REGNUM));

      struct internalvar *cr1_lo = create_ivar_from_reg
        (gdbarch, regcache, E2K_CR1_LO_REGNUM);

      set_ivar_field
        (new_wd, "base", ((((ivar_field (wd, "base") >> 4)
                            - ivar_field (cr1_lo, "wbs") + MAXSR_q) % MAXSR_q)
                                        << 4));
      set_ivar_field
        (new_wd, "size", ((ivar_field (wd, "psize") >> 4)
                          + ivar_field (cr1_lo, "wbs")) << 4);

      set_ivar_field
        (new_wd, "psize", ivar_field (cr1_lo, "wpsz") << 4);

      set_ivar_field
        (new_wd, "fx", ivar_field (cr1_lo, "wfx"));

      store_unsigned_integer
        (buf, register_size (gdbarch, regnum),
         byte_order, ivar_field (new_wd, "dword"));

      free_ivar (cr1_lo);
      free_ivar (new_wd);
      free_ivar (wd);
    }
  else if (regnum == VBR_REGNUM)
    {
      struct internalvar *br = create_zero_ivar
        (register_type (gdbarch, E2K_BR_REGNUM));

      struct internalvar *cr1_hi = create_ivar_from_reg
        (gdbarch, regcache, E2K_CR1_HI_REGNUM);

      set_ivar_field (br, "dword", ivar_field (cr1_hi, "br"));

      store_unsigned_integer (buf, register_size (gdbarch, regnum),
                              byte_order, ivar_field (br, "dword"));

      free_ivar (cr1_hi);
      free_ivar (br);
    }
  else if (regnum == VPSP_REGNUM || regnum == VPCSP_REGNUM)
    {
      ULONGEST val;

      if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	{
	  struct internalvar *rwap_lo;
	  struct internalvar *rwap_hi;
	  regnum = (regnum == VPSP_REGNUM ?  VPSP_LO_REGNUM : VPCSP_LO_REGNUM);

	  rwap_lo = create_ivar_from_reg (gdbarch, regcache, regnum);
	  rwap_hi = create_ivar_from_reg (gdbarch, regcache, regnum + 1);

	  val = (ivar_field (rwap_lo, "base")
		 + ivar_field (rwap_hi, "ind"));

	  free_ivar (rwap_hi);
	  free_ivar (rwap_lo);
	}
      else
	{
	  struct internalvar *rwap_lo;
	  regnum = (regnum == VPSP_REGNUM ?  VPSP_LO_REGNUM : VPCSP_LO_REGNUM);
	  rwap_lo = create_ivar_from_reg (gdbarch, regcache, regnum);
	  val = ivar_field (rwap_lo, "ptr");
	  free_ivar (rwap_lo);
	}

      store_unsigned_integer (buf, register_size (gdbarch, regnum), byte_order, val);
    }
    else if (regnum == VPC_REGNUM || regnum == VIP_REGNUM)
      {
        regcache->raw_read (E2K_CR0_HI_REGNUM, buf);
      }
    else if ((regnum >= VG0_REGNUM && regnum <= VG31_REGNUM)
             || (regnum >= VXG0_REGNUM && regnum <= VXG31_REGNUM)
             || (regnum >= VQPG0_REGNUM && regnum <= VQPG31_REGNUM))
      {
        int i;
        int ext = (regnum >= VXG0_REGNUM && regnum <= VXG31_REGNUM);
        int qp = (regnum >= VQPG0_REGNUM && regnum <= VQPG31_REGNUM);
        int r[2];
        int rtag[2];
        /* The type of a global register under consideration.  */
        struct type *gtype = register_type (gdbarch, regnum);
        /* Offset of tags within GTYPE.  */
        size_t tagoff = qp ? 16 : (ext ? 10 : 8);

        if (ext)
          {
            r[0] = E2K_G0_REGNUM + (regnum - VXG0_REGNUM);
            r[1] = E2K_GEXT0_REGNUM + (r[0] - E2K_G0_REGNUM);
          }
        else if (qp)
          {
            r[0] = E2K_G0_REGNUM + (regnum - VQPG0_REGNUM);
            r[1] = E2K_GEXT_V5_0_REGNUM + (r[0] - E2K_G0_REGNUM);

            /* In case the kernel doesn't provide us any part of `%qpgX',
               e.g. the upper 64 bits, the whole register should be considered
               as unavailable.  */
            if (regcache->get_register_status (r[1]) == REG_UNAVAILABLE)
              ret = REG_UNAVAILABLE;
              
            rtag[1] = E2K_GTAG_V5_0_REGNUM + (r[0] - E2K_G0_REGNUM);
          }
        else
          r[0] = E2K_G0_REGNUM + (regnum - VG0_REGNUM);

        rtag[0] = E2K_GTAG0_REGNUM + (r[0] - E2K_G0_REGNUM);


        /* Hopefully, the most significant part of `%{x,qp}gX' register will
           be filled in with appropriate number of bytes, which is two for
           `%xgX' and 8 for `%qpgX'.  */
        for (i = 0; i < ((ext || qp) ? 2 : 1); i++)
          regcache->raw_read (r[i], buf + i * 8);


        for (i = 0; i < (qp ? 2 : 1); i++)
          {
            ULONGEST tag;
            regcache->raw_read (rtag[i], &tag);

            modify_field (gtype, buf + tagoff, tag & 0x3, 4 * i, 2);
            modify_field (gtype, buf + tagoff, (tag >> 2) & 0x3,
                          4 * i + 2, 2);
          }
      }
    else if (regnum == VSP_REGNUM || regnum == VFP_REGNUM)
      {
        struct internalvar *usd_lo;
        ULONGEST sp;
        int protected_mode = gdbarch_ptr_bit (gdbarch) == 128;

        usd_lo = create_ivar_from_reg (gdbarch, regcache,
                                       (protected_mode
                                        ? E2K_PUSD_LO_REGNUM
                                        : E2K_USD_LO_REGNUM));

	/* We are likely to implicitly believe that the Kernel does not modify
	   the user's %USD by the moment it's saved to user_regs_struct. On
	   elbrus-v{X<7} this means that the values of  %USD.size and
	   %CR1.hi.ussz in user_regs struct are equal, which can and should
	   be checked. As for elbrus-v7, this should mean that %USFS on the
	   kernel side is zero by the moment it's saved to user_regs_struct,
	   but the problem is that the kernel does not provide it, which is
	   why this can't be verified.  */
	sp = ivar_field (usd_lo, (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7
				  ? "base" : "ptr"));
	if (protected_mode)
	  {
	    ULONGEST usbr;
	    regcache_cooked_read_unsigned ((struct regcache *)regcache,
					   E2K_USBR_REGNUM, &usbr);
	    sp += usbr & 0xffffffff00000000ULL;
	  }

        free_ivar (usd_lo);

        if (regnum == VFP_REGNUM)
          {
	    if (! gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch)->is_elbrus_v7)
	      {
		struct internalvar *usd_hi;
		struct internalvar *cr1_hi;

		usd_hi = create_ivar_from_reg
		  (gdbarch, regcache, (protected_mode
				       ? E2K_PUSD_HI_REGNUM
				       : E2K_USD_HI_REGNUM));

		cr1_hi = create_ivar_from_reg
		  (gdbarch, regcache, VCR1_HI_REGNUM);

		sp += ((ivar_field (cr1_hi, "ussz") << 4)
		       - ivar_field (usd_hi, "size"));

		free_ivar (cr1_hi);
		free_ivar (usd_hi);
	      }
	    else
	      {
#if 0
		ULONGEST usfs;
		regcache_cooked_read_unsigned ((struct regcache *) regcache,
					       VUSFS_REGNUM, &usfs);
		sp += usfs;
#endif
	      }
          }

        store_unsigned_integer (buf, register_size (gdbarch, regnum),
                                byte_order, sp);
      }
    else
      ret = REG_UNKNOWN;

  return ret;
}

static void
e2k_pseudo_register_write (struct gdbarch *gdbarch,
                           struct regcache *regcache,
                           int regnum,
			   const gdb_byte *buf)
{
  if ((regnum >= VR0_REGNUM && regnum <= VR223_REGNUM)
      || (regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM))
    {
      int rnum;
      struct internalvar *cr1_lo;
      int dwarf = regnum >= VDWR0_REGNUM && regnum <= VDWR223_REGNUM;
      struct internalvar *wd;

      rnum = regnum - (dwarf ? VDWR0_REGNUM : VR0_REGNUM);
      cr1_lo = create_ivar_from_reg (gdbarch, regcache, E2K_CR1_LO_REGNUM);

      if (rnum < 2 * ivar_field (cr1_lo, "wbs"))
        {
          CORE_ADDR addr;
          ULONGEST psp;
          gdb_byte tag[2];
	  e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);
	  int is_elbrus_8c2 = tdep->num_elbrus_v5_pseudo_regs != 0;
          struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
          struct type *tagged64_type = data->tagged64_type;
          struct type *etags_type = tagged64_type->field (1).type ();

          regcache_cooked_read_unsigned (regcache, VPSP_REGNUM, &psp);
          addr = (psp + 32 * (rnum >> 1)
                  + (is_elbrus_8c2 ? 16 : 8) * (rnum & 0x1));
          write_memory (addr, buf, 8);

          if (!dwarf)
            {
              tag[0] = (gdb_byte) unpack_field_as_long (etags_type, &buf[8], 0);
              tag[1] = (gdb_byte) unpack_field_as_long (etags_type, &buf[8], 1);

              target_write (current_inferior ()->top_target (), TARGET_OBJECT_TAG, NULL, tag,
                            addr, 2);
            }

          free_ivar (cr1_lo);
          return;
        }

      wd = create_ivar_from_reg (gdbarch, regcache, VWD_REGNUM);

      if (rnum < (ivar_field (wd, "size") >> 3)
          && (rnum -= 2 * ivar_field (cr1_lo, "wbs")) <= 6)
        {
          regcache->raw_write (E2K_SYS_NUM_REGNUM + rnum, buf);
        }
      free_ivar (wd);
      free_ivar (cr1_lo);
    }
  else if ((regnum >= VB0_REGNUM && regnum <= VB127_REGNUM)
	   || (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM))
    {
      int base, rbase, rnum;
      struct internalvar *br;

      if (regnum >= VDWB0_REGNUM && regnum <= VDWB127_REGNUM)
	{
	  base = VDWB0_REGNUM;
	  rbase = VDWR0_REGNUM;
	}
      else
        {
          base = VB0_REGNUM;
          rbase = VR0_REGNUM;
        }
      
      rnum = regnum - base;
      br = create_ivar_from_reg (gdbarch, regcache, VBR_REGNUM);

      if (rnum < 2 * (ivar_field (br, "rsz") + 1))
        {
          /* Now that we can access the whole window via register aliases
             %r0 . . . %r223 this should be correct. */

          rnum = (2 * ivar_field (br, "rbs")
                  + ((2 * ivar_field (br, "rcur") + rnum)
                     % (2 * (ivar_field (br, "rsz") + 1))));

          regcache->cooked_write (rnum + rbase, buf);
        }
      else
        {
          /* No such register. */
        }

      free_ivar (br);
    }
  else if (regnum >= VP0_REGNUM && regnum <= VP31_REGNUM)
    {
      struct internalvar *br;
      struct internalvar *cr0_lo;
      struct internalvar *pred;
      int rnum;
      char vfld_name[8];
      char tfld_name[8];

      /* This awful duplication . . . */


      /* All these tricks with getting `dw' and further setting
         `dword' field look boring . . . */
      br = create_ivar_from_reg (gdbarch, regcache, VBR_REGNUM);
      rnum = real_pred_num (br, regnum - VP0_REGNUM);
      sprintf (vfld_name, "val%d", rnum);
      sprintf (tfld_name, "tag%d", rnum);
      free_ivar (br);

      cr0_lo = create_ivar_from_reg (gdbarch, regcache, VCR0_LO_NEXT_REGNUM);

      pred = create_zero_ivar (register_type (gdbarch, rnum + VP0_REGNUM));
      set_ivar_field (pred, "word",
                      extract_unsigned_integer
                      (buf, register_size (gdbarch, rnum + VP0_REGNUM),
                       gdbarch_byte_order (gdbarch)));

      set_ivar_field (cr0_lo, vfld_name, ivar_field (pred, "bval"));
      set_ivar_field (cr0_lo, tfld_name, ivar_field (pred, "t"));
      free_ivar (pred);

      regcache_cooked_write_unsigned
        (regcache, VCR0_LO_NEXT_REGNUM, ivar_field (cr0_lo, "dword"));

      free_ivar (cr0_lo);
    }
  else if ((regnum >= VG0_REGNUM && regnum <= VG31_REGNUM)
	   || (regnum >= VXG0_REGNUM && regnum <= VXG31_REGNUM)
	   || (regnum >= VQPG0_REGNUM && regnum <= VQPG31_REGNUM))
    {
      int ext = (regnum >= VXG0_REGNUM && regnum <= VXG31_REGNUM);
      int qp = (regnum >= VQPG0_REGNUM && regnum <= VQPG31_REGNUM);

      int i;
      int r[3];
      int rtag[2];
      /* The type of a global register under consideration.  */
      struct type *gtype = register_type (gdbarch, regnum);
      /* Offset of tags within GTYPE.  */
      size_t tagoff = qp ? 16 : (ext ? 10 : 8);

      struct type *etags_type = gtype->field ((ext || qp) ? 2 : 1).type ();

      r[0] = (E2K_G0_REGNUM + (regnum
			       - (qp ? VQPG0_REGNUM : (ext
						       ? VXG0_REGNUM
						       : VG0_REGNUM))));

      rtag[0] = E2K_GTAG0_REGNUM + (r[0] - E2K_G0_REGNUM);
      rtag[1] = E2K_GTAG_V5_0_REGNUM + (r[0] - E2K_G0_REGNUM);
      r[1] = E2K_GEXT0_REGNUM + (r[0] - E2K_G0_REGNUM);
      r[2] = E2K_GEXT_V5_0_REGNUM + (r[0] - E2K_G0_REGNUM);

      /* Should the case when the kernel doesn't provide us with any
	 part of `%qpgX', e.g. the upper 64 bits, be considered here
	 at all?.  */
      // if (regcache->get_register_status (r[1]) == REG_UNAVAILABLE)
      //   ret = REG_UNAVAILABLE;

      
      /* Fill in the lower 64 bits. This is common for all formats.  */
      regcache->raw_write (r[0], buf);

      if (ext || qp)
	{
	  /* Fill in E2K_GEXT*_REGNUM: this is done in the same way for EXT and
	     QP registers.  */
	  regcache->raw_write (r[1], buf + 8);

	  if (qp)
	    regcache->raw_write (r[2], buf + 8);
	  else
	    {
	      gdb_byte hibuf[8];
	      /* Borrow the highermost 6 bytes (indexed from 10 to 15) from
		 the current value of %qpgX ...  */
	      regcache->raw_read (r[2], &hibuf[0]);
	      /* ... and bytes #8 and #9 from the provided value for %xgX.  */
	      hibuf[0] = buf[8];
	      hibuf[1] = buf[9];
	      regcache->raw_write (r[2], hibuf);
	    }
	}

      for (i = 0; i < (qp ? 2 : 1); i++)
	{
	  ULONGEST tag;
	  tag = unpack_field_as_long (etags_type, &buf[tagoff], 2 * i + 1);
	  tag <<= 2;
	  tag += unpack_field_as_long (etags_type, &buf[tagoff], 2 * i);

	  regcache_raw_write_unsigned (regcache, rtag[i], tag);
	}
    }
  else if (regnum >= VCR0_LO_NEXT_REGNUM && regnum <= VCR1_HI_NEXT_REGNUM)
    {
      /* I use `E2K_CR0_LO_REGNUM' directly meanwhile (see in this function
         above). This is because I don't understand how to get a
         `struct value' with regcache-functions. There seems to be a drastic
         difference in interface when dealing with regcaches and frames . . .
         Because of this at present I shouldn't find myself here. */
      /* gdb_assert (0); */
      regcache->raw_write ((E2K_CR0_LO_REGNUM
			    + (regnum - VCR0_LO_NEXT_REGNUM)),
			   buf);
    }
  else if (regnum == VSP_REGNUM)
    {
      struct internalvar *cr1_hi = create_ivar_from_reg
        (gdbarch, regcache, E2K_CR1_HI_REGNUM);

      ULONGEST new_sp = extract_unsigned_integer
        (buf, register_size (gdbarch, VSP_REGNUM),
         gdbarch_byte_order (gdbarch));
      ULONGEST old_sp;

      regcache_cooked_read_unsigned (regcache, VSP_REGNUM,
                                     &old_sp);

      /* REMINDER: this mechanism looks pretty bogus . . . */
      set_ivar_field (cr1_hi, "ussz",
                      ivar_field (cr1_hi, "ussz")
                      + (((LONGEST) (new_sp - old_sp)) >> 4));


      regcache_raw_write_unsigned (regcache, E2K_CR1_HI_REGNUM,
                                   ivar_field (cr1_hi, "dword"));

      free_ivar (cr1_hi);
    }
#if 0
  else if (regnum == VPCSP_REGNUM)
    {
      ULONGEST new_pcsp;
      ULONGEST old_pcsp;
      CORE_ADDR pc;
      enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
      ssize_t ret_size;
      int i;
      e2k_gdbarch_tdep *tdep = (e2k_gdbarch_tdep *) gdbarch_tdep (gdbarch);
      gdb_byte *original_code;

      new_pcsp =
        (extract_unsigned_integer (buf, register_size (gdbarch, VPCSP_REGNUM),
                                   byte_order));

      regcache_cooked_read_unsigned (regcache, VPCSP_REGNUM, &old_pcsp);
      pc = e2k_read_pc (regcache) & ~0xfffull;

      byte_order = gdbarch_byte_order (gdbarch);
      ret_size = tdep->before_param_in_dreg_bp_offset - tdep->call_bp_offset;
      original_code = (gdb_byte *) alloca (ret_size);

      /* Save original code at place `return %ctpr3; ct %ctpr3' in place of it.  */
      read_memory (pc, original_code, ret_size);
      for (i = tdep->call_bp_offset / 4;
           i < (tdep->call_bp_offset + ret_size) / 4; i++)
        write_memory_unsigned_integer (pc - tdep->call_bp_offset + 4 * i, 4,
                                       byte_order, tdep->call_trampoline[i]);


      for (i = 0; i < (old_pcsp - new_pcsp) / 32; i++)
        {
          CORE_ADDR ret;
          regcache = get_current_regcache ();

          regcache_cooked_read_unsigned (regcache, VCR0_HI_REGNUM, &ret);
          create_momentary_breakpoint (gdbarch, 0, 0, ret);
          
          proceed (pc, GDB_SIGNAL_0);
          wait_for_inferior ();
          normal_stop ();
        }

      write_memory (pc, original_code, ret_size);
    }
#endif /* 0  */
}

static std::vector<CORE_ADDR>
e2k_software_single_step (struct regcache *regcache)
{
  std::vector<CORE_ADDR> next_pcs;
  CORE_ADDR pc, next_pc;

  /* FIXME: an ugly hack just to make it compilable. Eventually I should get
     rid of FRAME below somehow . . .  */
  frame_info_ptr frame = get_current_frame ();

  struct gdbarch *gdbarch = get_frame_arch (frame);
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
  struct type *hs_type = tdesc_find_type (gdbarch, "hs");
  struct internalvar *hs = create_zero_ivar (hs_type);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);

  pc = (CORE_ADDR) get_frame_register_unsigned (frame, VPC_REGNUM);

  set_ivar_field (hs, "word",
                  read_memory_unsigned_integer (pc, 4, byte_order));

  next_pc = pc + 8 * (ivar_field (hs, "lng") + 1);

  next_pcs.push_back (next_pc);

  if (ivar_field (hs, "s") != 0)
    {
      struct internalvar *ss = create_zero_ivar (data->ss_type);
      unsigned int ctpr_ind;

      set_ivar_field (ss, "word",
                      read_memory_unsigned_integer
                      (pc + 4, 4, byte_order));

      /* What about IBRANCH? I don't see where it may be processed.
         This is a reason for Bug #50096. */

      if ((ctpr_ind = ivar_field (ss, "ctop")) != 0)
        {
          struct internalvar *ctpr = create_zero_ivar (data->ctpr_rwp_type);

          set_ivar_field
            (ctpr, "dword",
             (CORE_ADDR) get_frame_register_unsigned
             (frame, E2K_CTPR1_REGNUM + ctpr_ind - 1));

          if (ivar_field (ctpr, "opc") == 0)
            {
              /* In case this is a DISP . . . */
              CORE_ADDR branch_pc;

              branch_pc = (CORE_ADDR) ivar_field (ctpr, "ta_base");

              /* When removing the second single-step breakpoint the
                 memory contents spoiled by the first one is restored
                 if both are set to the same address. Therefore don't
                 allow this (Bug #49419). */

              /* FIXME: warn a user somehow when `branch_pc == pc'. */
              if (branch_pc != next_pc && branch_pc != pc)
                {
                  /* Note, that branch_pc may contain something inappropriate
                     for a breakpoint, e.g NULL as it happens in Bug #79103.
                     This may either turn out to be harmless if the branch isn't
                     actually performed , as it happens in the aforementioned
                     bug (%predX == FALSE), or will lead to a fault. In either
                     case it makes sense to prevent GDB from processing an
                     exception with an error message about its inability to set
                     a breakpoint and thus make it impossible for a user to
                     perform a 'stepi'. Indeed, in the first case branch_pc
                     breakpoint isn't actually needed, while in the second one
                     a user should be stopped via a fault.

                     REMINDER: find out, who is going to "ui_file_delete ()"
                     tmp_error_stream filled in with (potential) error messages
                     in insert_breakpoint_locations?  */
                  try
                    {
                      next_pcs.push_back (branch_pc);
                    }
                  catch (const gdb_exception_error &ex)
                    {
                    }
                }
            }
          else if (ctpr_ind == 3 && ivar_field (ctpr, "opc") == 3)
            {
              /* This is a RETURN case, %ctpr.base is undefined. */

              CORE_ADDR ret_pc = (CORE_ADDR)
                ((get_frame_register_unsigned (frame, VCR0_HI_REGNUM) >> 3)
                 << 3);

              /* FIXME: warn a user somehow when ret_pc == pc. That
                 should be impossible though . . . */
              if (ret_pc != next_pc && ret_pc != pc)
                next_pcs.push_back (ret_pc);
            }

          free_ivar (ctpr);
        }
      else if (ivar_field (hs, "c") & 0x1)
        {
          /* We have CS0 */
          struct internalvar *cs0 = create_zero_ivar (data->cs0_dummy_type);
          ULONGEST alses = ivar_field (hs, "al");
          CORE_ADDR cs0_addr
            = (pc
               /* Skip HS and SS */
               + 8
               /* Skip ALSes */
               + (((alses & 0x1) + ((alses & 0x2) >> 1) + ((alses & 0x4) >> 2)
                   + ((alses & 0x8) >> 3) + ((alses & 0x10) >> 4)
                   + ((alses & 0x20) >> 5)) << 2));

          set_ivar_field
            (cs0, "word",
             read_memory_unsigned_integer (cs0_addr, 4, byte_order));

          if (ivar_field (cs0, "opc") == 0)
            {
              /* This is IBRANCH (see B.4) */
              LONGEST disp = ivar_field (cs0, "disp");
              CORE_ADDR ibranch_pc;

              if (disp & (1 << 27))
                disp -= (1 << 28);

              ibranch_pc = pc + (disp << 3);

              if (ibranch_pc != next_pc)
                next_pcs.push_back (ibranch_pc);

              free_ivar (cs0);
            }
        }

      free_ivar (ss);
    }

  free_ivar (hs);
  return next_pcs;
}

static int
e2k_remote_register_number (struct gdbarch *gdbarch, int regno)
{
  /* All registers in `e2k-regs.inc' have been grouped in such a way that
     those not provided to GDBSERVER follow E2K_R0_REGNUM.  */
  if (regno >= E2K_R0_REGNUM)
    return -1;

  return regno;
}


/* This function partially duplicates `c_e2k_val_print' in
   c-e2k-lang.c. Keep in mind that the `info' command has
   its peculiarities when printing registers as compared
   with `p'. */
static void
e2k_print_register_info (/* struct gdbarch *gdbarch,  */
			 struct ui_file *file,
			 const frame_info_ptr &frame,
			 int regnum,
			 int print_all,
			 struct type *type,
			 gdb_byte *buffer)
{
  struct value_print_options formatted_opts;
  struct value_print_options user_opts;
  struct gdbarch *gdbarch;
  struct e2k_gdbarch_data *data;
  char format;
  gdbarch = type->arch ();
  gdb_assert (gdbarch != NULL);
  data = get_e2k_gdbarch_data (gdbarch);
  format = type == data->tagged80_type ? '\0' : 'x';

  get_formatted_print_options (&formatted_opts, format);
  get_user_print_options (&user_opts);

#if 0
  c_e2k_val_print_ex (type, buffer, 0, 0, file, 0, NULL, &formatted_opts,
		      &user_opts, 0);
#endif /* 0  */

  default_print_registers_info (gdbarch, file, frame, regnum, print_all);
}


static void
e2k_print_registers_info (struct gdbarch *gdbarch,
                          struct ui_file *file,
                          const frame_info_ptr &frame,
                          int regnum, int print_all)
{
  int i;
  const int numregs = gdbarch_num_regs (gdbarch)
		      + gdbarch_num_pseudo_regs (gdbarch);
  gdb_byte buffer[MAX_REGISTER_SIZE];
  int res;


  for (i = 0; i < numregs; i++)
    {
      /* Decide between printing all regs, non-float / vector regs, or
         specific reg.  */
      if (regnum == -1)
	{
	  if (print_all)
	    {
	      if (!gdbarch_register_reggroup_p (gdbarch, i, all_reggroup))
		continue;
	    }
	  else
	    {
	      if (!gdbarch_register_reggroup_p (gdbarch, i, general_reggroup))
		continue;
	    }
	}
      else
	{
	  if (i != regnum)
	    continue;
	}

      /* If the register name is empty, it is undefined for this
         processor, so don't display anything.  */
      if (gdbarch_register_name (gdbarch, i) == NULL
	  || *(gdbarch_register_name (gdbarch, i)) == '\0')
	continue;

      /* Don't use throw_exception () when reading unavailable window
	 registers anymore. Unavailable values are employed instead.  */
      res = deprecated_frame_register_read (frame, i, buffer);

      if (res != 1)
        continue;

      gdb_puts (gdbarch_register_name (gdbarch, i), file);
      print_spaces (30 - strlen (gdbarch_register_name
				 (gdbarch, i)), file);

      /* Get the data in raw format.  */
      if (! res)
	{
	  gdb_printf (file, "*value not available*\n");
	  continue;
	}

      /* If virtual format is floating, `default_print_registers_info'
         prints it that way, and in raw hex. I am not sure whether
         we have any registers at present which are FLOATING from
         GDB's point of view. In any case, gdb-5.2 doesn't do that
         and I act in a compatible manner. */
      e2k_print_register_info (/*gdbarch,*/ file, frame, i, print_all,
			       register_type (gdbarch, i), buffer);
    }

}

static void
e2k_override_examine_val_type (struct gdbarch *gdbarch,
                               CORE_ADDR addr,
                               char size,
                               struct type **type)
{ // ! ! !
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);

  if (size == 'g' && ((addr & 0x7) == 0))
    *type = ((*type)->is_unsigned ()
	     ? data->mem_tagged64_type : data->mem_signed_tagged64_type);
  else if (size == 'w' && ((addr & 0x3) == 0))
    *type = ((*type)->is_unsigned ()
             ? data->mem_tagged32_type : data->mem_signed_tagged32_type);
}

static struct value *
e2k_examine_value (struct gdbarch *gdbarch,
                   char format,
                   struct type *type,
                   CORE_ADDR addr)
{
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);

  if (type == data->mem_tagged64_type
      || type == data->mem_tagged32_type
      || type == data->mem_signed_tagged64_type
      || type == data->mem_signed_tagged32_type)
    {
      struct tagged_value_closure *closure
        = ((struct tagged_value_closure *)
	   xzalloc (sizeof (struct tagged_value_closure)));

      closure->gdbarch = gdbarch;
      closure->addr = addr;
      return value::allocate_computed (type, &tagged_value_funcs, closure);
    }

  return value_at_lazy (type, addr);
}


static void
e2k_next_address (struct gdbarch *gdbarch,
                  struct value *val, CORE_ADDR *addr)
{
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
  struct type *type = check_typedef (val->type ());
  int len = type->length ();

  if (type == data->mem_tagged64_type || type == data->mem_signed_tagged64_type)
    *addr += 8;
  else if (type == data->mem_tagged32_type || type == data->mem_signed_tagged32_type)
    *addr += 4;
  /* The standard behavior. */
  else if (val->lval () == lval_memory)
    *addr = val->address() + len;
}

static CORE_ADDR
e2k_unwind_sp (struct gdbarch *gdbarch, const frame_info_ptr &next_frame)
{
  return frame_unwind_register_unsigned (next_frame, VSP_REGNUM);
}


static enum return_value_convention
e2k_return_value (struct gdbarch *gdbarch, struct value *function,
                  struct type *valtype, struct regcache *regcache,
                  gdb_byte *readbuf, const gdb_byte *writebuf)
{
  if (writebuf != NULL)
    {
      int i;
      int len = valtype->length ();
      for (i = 0; 8 * i < len; i++)
        regcache->cooked_write_part (VB0_REGNUM + i, 0,
				     8 * (i + 1) > len ? len - 8 * i : 8,
				     &writebuf[8 * i]);
      return RETURN_VALUE_REGISTER_CONVENTION;
    }

  /* It's not their business how we actually get our parameters. For our
     implementation of CALL it's crucial that this function is called in all
     cases. So, tell them that we use a register.  */
  if (readbuf == NULL)
    return RETURN_VALUE_REGISTER_CONVENTION;

  int protected_mode = gdbarch_ptr_bit (gdbarch) == 128;
  int max_res_size_on_regs = protected_mode ? 128 : 64;

  /* FIXME: find out whether structures should be returned only on stack
     according to E2K ABI.  */
  if (valtype->length () > max_res_size_on_regs
      /* TYPE_CODE (valtype) == TYPE_CODE_STRUCT  */)
    {
#if 0
      struct internalvar *sp_var;
      ULONGEST sp;
      sp_var = create_ivar_from_reg (gdbarch, regcache, VR0_REGNUM);
      sp = ivar_field (sp_var, "dword");
      free_ivar (sp_var);
#endif /* 0  */

      ULONGEST sp;
      regcache_cooked_read_unsigned (regcache, VSP_REGNUM, &sp);
      read_memory ((CORE_ADDR) sp, readbuf, valtype->length ());
    }
  else
    {
      int i;
      int len = valtype->length ();
      for (i = 0; 8 * i < len; i++)
        regcache->cooked_read_part (VB0_REGNUM + i, 0,
				    8 * (i + 1) > len ? len - 8 * i : 8,
				    &readbuf[8 * i]);
    }

  return RETURN_VALUE_REGISTER_CONVENTION;
}

static struct value *
tagged_value_at_addr (struct gdbarch *gdbarch, CORE_ADDR addr)
{
  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
  struct tagged_value_closure *closure
    = ((struct tagged_value_closure *)
       xzalloc (sizeof (struct tagged_value_closure)));

  closure->gdbarch = gdbarch;
  closure->addr = addr;
  return value::allocate_computed (data->tagged64_type, &tagged_value_funcs,
				   closure);
}

static CORE_ADDR
e2k_push_dummy_call_new (struct gdbarch *gdbarch, struct value *function,
			 struct regcache *regcache, CORE_ADDR bp_addr,
			 int nargs, struct value **args, CORE_ADDR sp,
			 function_call_return_method return_method,
			 CORE_ADDR struct_addr)
{
  int i;
  int regno;
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  int ptr_bit = gdbarch_ptr_bit (gdbarch);
  int protected_mode = ptr_bit == 128;
  int arch_idx = protected_mode ? 2 : (ptr_bit == 64 ? 0 : 1);
  int size = (protected_mode && nargs > 0) ? 0x10 : 0;
  /* The size of the result which needs to be returned on stack. Currently this
     can be non-zero only in PM in case `sizeof (result) > 128'. Thus this
     value is greater than 128 if non-zero.  */
  int rval_size = 0;
  /* This contains the negated SIZE of input function's arguments in its low 32
     bits and the negated RVAL_SIZE in high 32 bits.  */
  ULONGEST neg_size;
  gdb_byte zero_out[40];

  memset (zero_out, 0, sizeof (zero_out));

  regcache_raw_write_unsigned (regcache, E2K_ARCH_IDX,
                               (ULONGEST) (arch_idx + 1));
  regcache->raw_supply (E2K_ARCH_IDX, zero_out);

  /* I don't see another way to tell GDBSERVER where CALL prologue and other
     subsidiary code should be executed.  */
  regcache_raw_write_unsigned (regcache, E2K_ENTRY_POINT,
			       (ULONGEST) (entry_point_address () | 0x1));
  regcache->raw_supply (E2K_ENTRY_POINT, zero_out);

  /* Enter the DUMMY frame.  */
  regcache_raw_write_unsigned (regcache, E2K_CALL_DUMMY, 1);
  regcache->raw_supply (E2K_CALL_DUMMY, zero_out);

  for (i = 0; i < nargs; i++)
    {
      struct type *type = args[i]->type ();
      int len = type->length ();
      /* Set parameter alignment according to MDES_E2K_PARAM_ALIGN() defined
         in `mdes/mdes_e2k_abi.h'. In PM all parameters have an alignment of
	 2 in terms of registers, whereas in ordinary modes only those the
	 size of which is greater than 8 bytes.  */
      int align = (protected_mode || len > 8) ? 16 : 8;

      size = (size + align - 1) & ~(align - 1);
      size += len;
    }

  if (!protected_mode)
    size = (size + 0xf) & ~0xf;
  else
    size = (size + 0x1f) & ~0x1f;

  if (protected_mode)
    {
      struct type *rval_type, *ftype;
      (void) find_function_addr (function, &rval_type, &ftype);
      rval_type = check_typedef (rval_type);
      rval_size = (rval_type->length () + 0x1f) & ~0x1f;

      /* Return values (results) up to 128 bytes in size are returned on
	 registers and thus don't require a special area on stack in PM
	 along with an extra parameter providing its descriptor in %qb[2].  */
      if (rval_size <= 128)
	rval_size = 0;

      neg_size = ((((ULONGEST) (unsigned int) -rval_size) << 32)
		  + (ULONGEST) (unsigned int) -size);
    }
  else
    neg_size = (ULONGEST) (unsigned int) -size;

  /* Execute prologue, in particular allocate space on stack.  */
  regcache_raw_write_unsigned (regcache, E2K_PROLOGUE, neg_size | 0x1);
  regcache->raw_supply (E2K_PROLOGUE, zero_out);

  /* In case of a result returned on stack in PM the "user" function's
     arguments are allocated starting from %qb[4] because of an extra
     AP argument (see above).   */
  for (i = 0, regno = (protected_mode ? (rval_size > 128 ? 4 : 2) : 0);
       i < nargs; i++)
    {
      int j;
      const gdb_byte *valbuf = args[i]->contents ().data ();
      struct type *type = args[i]->type ();
      int len = type->length ();
      /* See the above comment on the parameters' alignment.  */
      int align = (protected_mode || len > 8) ? 16 : 8;
      int reg_align;
      int in_regs;

      reg_align = align / 8;
      regno = (regno + reg_align - 1) & ~(reg_align - 1);

      /* Keep in mind that if a parameter cannot be passed entirely on
         registers, it's passed in stack (see eir2e2k_e2k_CreateLayoutParam
         ()).
         FIXME: find out whether a parameter can have a greater alignment in
         bytes than 8. In that case REGNO should be additionally aligned as
         well.  */
      in_regs = regno + (len + 7) / 8 - 1 < (!protected_mode ? 8 : 16);

      for (j = 0; j < (len + 7) / 8;)
	{
          int k;
	  struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);
	  ULONGEST tags = 0;
	  int nregs = (j % 2 == 0 && j + 1 < (len + 7) / 8) ? 2 : 1;
	  struct value *param_val;
	  struct internalvar *param = create_zero_ivar
	    (nregs == 2 ? data->quad_param_type : data->dbl_param_type);

          for (k = j; k < j + nregs; k++, regno++)
            {
	      if (args[i]->lval () == lval_memory)
		{
		  struct internalvar *s;
		  ULONGEST dw, t0, t1;
                  CORE_ADDR addr = args[i]->address () + k * 8;
		  s = create_ivar_from_value
                    (tagged_value_at_addr (gdbarch, addr));
                    
		  dw = ivar_field (s, "dword");

                  /* A raw hack which lets me avoid picking inappropriate
                     external tags. Consider the case of a 4-byte parameter
                     aligned exactly on a 4-byte boundary. A tagged double word
                     composed by stupidly concatinating it and the next 4-byte
                     word belonging to the subsequent double word may turn out
                     to have invalid external tags, which will result in SIGILL
                     on an attempt to copy it into the area of the callee's
                     parameters.  */
                  if (addr % 4 == 0 && k * 8 + 3 < len)
                    {
                      t0 = ivar_field (s, "tag0");
                      t1 = k * 8 + 7 < len ? ivar_field (s, "tag1") : 0;
                    }
                  else
                    t1 = t0 = 0;

		  /* If this is a SAP convert it into AP by zeroing out its
		     `psl' and internal tag `itagsap == 0x4', which is used
		     to distinguish it from AP as well. Otherwise, we'll get
		     an error (recall whether it's an exception or not) when
		     copying SAP from %g0 either into a window register or
		     on stack. */
		  if (k == j && t0 == 3 && t1 == 3 && ((dw >> 61) & 0x7) == 0x4)
		    dw &= 0x1fff0000ffffffffULL;

		  set_ivar_field
		    (param,
		     nregs == 1 ? "val" : (k == j ? "val1" : "val2"), dw);

		  tags <<= 4;
		  tags |= (t1 << 2) | t0;

		  free_ivar (s);
		}
	      else
		{
		  ULONGEST subval;

		  subval = extract_unsigned_integer (&valbuf[k * 8], 8,
						     byte_order);

		  if (args[i]->type ()->code () == TYPE_CODE_PTR)
		    {
                      /* FIXME: note that one may find himself here when a
                         pointer is retrieved from a register (but not from
                         memory as in the case above) in which case its tags
                         are in place and need not be synthesized. By analogy
                         with the case of a pointer residing in memory it may
                         be needed to convert SAP into AP though (see
                         below).  */

		      /* Append appropriate external tags to a pointer
			 depending on whether it's AP or PL.  */
		      if (protected_mode
			  && (args[i]->type ()->target_type ()->code ()
			      == TYPE_CODE_FUNC))
			{
			  const struct target_desc *tdesc
			    = gdbarch_target_desc (gdbarch);
			  tags <<= 4;
			  if (! tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v6.linux"))
			    tags |= k == j ? 0 : ((2 << 2) | 2);
			  else
			    tags |= (3 << 2) | 3;
			}
		      else if (args[i]->type ()->length () == 16)
			{
                          /* FIXME? Note that here I produce a tag for either
                             the next or previous double word. Alternatively the
                             way they are packed into tags could be changed.  */
			  tags <<= 4;
			  tags |= (3 << 2) | (k == j ? 0 : 3);

                          /* Take care of converting SAP into AP. This is
                             required since `%gX' registers can't be used to
                             place SAPs into parameters of a function being
                             called. FIXME: this is a duplicate of the analogous
                             code in case a pointer resides in memory (see
                             above).  */
                          if (k == j && ((subval >> 61) & 0x7) == 0x4)
                            subval &= 0x1fff0000ffffffffULL;
			}
		    }

		  set_ivar_field
		    (param,
		     nregs == 1 ? "val" : (k == j ? "val1" : "val2"), subval);

		}

	      set_ivar_field (param, "tags", tags);
	    }

	  set_ivar_field (param, "set", 1);

          for (k = 0; k <= in_regs; k++)
            {
              int param_regno =
                (k
                 ? (nregs == 2 ? E2K_QUAD_REG : E2K_DBL_REG)
                 : (nregs == 2 ? E2K_QUAD_STACK : E2K_DBL_STACK));

              set_ivar_field
                (param, "offset",
                 k
                 ? (regno - nregs) : 8 * (regno - nregs));

              param_val = value_of_internalvar (gdbarch, param);

              regcache->raw_write (param_regno,
				   param_val->contents ().data ());
              regcache->raw_supply (param_regno, zero_out);
            }

          /* FIXME: with `value_free ()' below I get an assertion failure.
             Stupidly shut this up for now.  */
	  // value_free (param_val);
          free_ivar (param);


          j += nregs;
	}
    }

  /* Enter the frame in which the target function is to be executed.  */
  regcache_raw_write_unsigned (regcache, E2K_CALL_TARGET, 1);
  regcache->raw_supply (E2K_CALL_TARGET, zero_out);

  return sp - (size + rval_size);
}

static const struct reggroup *e2k_aau_reggroup;
static const struct reggroup *e2k_b_reggroup;
static const struct reggroup *e2k_chain_reggroup;
static const struct reggroup *e2k_dbg_reggroup;
static const struct reggroup *e2k_g_reggroup;
static const struct reggroup *e2k_mem_reggroup;
static const struct reggroup *e2k_os_reggroup;
static const struct reggroup *e2k_dam_reggroup;
static const struct reggroup *e2k_mlt_reggroup;
static const struct reggroup *e2k_pred_reggroup;
static const struct reggroup *e2k_r_reggroup;
static const struct reggroup *e2k_rpr_reggroup;
/* %xb-registers */
static const struct reggroup *e2k_xb_reggroup;
/* %xg-registers */
static const struct reggroup *e2k_xg_reggroup;
/* %xr-registers */
static const struct reggroup *e2k_xr_reggroup;

/* %qpb-registers.  */
static const struct reggroup *e2k_qpb_reggroup;
/* %qpr-registers.  */
static const struct reggroup *e2k_qpr_reggroup;

static void
e2k_init_reggroups (void)
{
  e2k_aau_reggroup = reggroup_new ("aau", USER_REGGROUP);
  e2k_b_reggroup = reggroup_new ("b", USER_REGGROUP);
  e2k_chain_reggroup = reggroup_new ("chain", USER_REGGROUP);
  e2k_dbg_reggroup = reggroup_new ("dbg", USER_REGGROUP);
  e2k_g_reggroup = reggroup_new ("g", USER_REGGROUP);
  e2k_mem_reggroup = reggroup_new ("mem", USER_REGGROUP);
  e2k_os_reggroup = reggroup_new ("os", USER_REGGROUP);
  e2k_dam_reggroup = reggroup_new ("dam", USER_REGGROUP);
  e2k_mlt_reggroup = reggroup_new ("mlt", USER_REGGROUP);
  e2k_pred_reggroup = reggroup_new ("pred", USER_REGGROUP);
  e2k_r_reggroup = reggroup_new ("r", USER_REGGROUP);
  e2k_rpr_reggroup = reggroup_new ("rpr", USER_REGGROUP);

  e2k_xb_reggroup = reggroup_new ("xb", USER_REGGROUP);
  e2k_xg_reggroup = reggroup_new ("xg", USER_REGGROUP);
  e2k_xr_reggroup = reggroup_new ("xr", USER_REGGROUP);

  e2k_qpb_reggroup = reggroup_new ("qpb", USER_REGGROUP);
  e2k_qpr_reggroup = reggroup_new ("qpr", USER_REGGROUP);
}

static void
e2k_add_reggroups (struct gdbarch *gdbarch)
{
  reggroup_add (gdbarch, e2k_aau_reggroup);
  reggroup_add (gdbarch, e2k_b_reggroup);
  reggroup_add (gdbarch, e2k_chain_reggroup);
  reggroup_add (gdbarch, e2k_dbg_reggroup);
  reggroup_add (gdbarch, e2k_g_reggroup);
  reggroup_add (gdbarch, e2k_mem_reggroup);
  reggroup_add (gdbarch, e2k_os_reggroup);
  reggroup_add (gdbarch, e2k_dam_reggroup);
  reggroup_add (gdbarch, e2k_mlt_reggroup);
  reggroup_add (gdbarch, e2k_pred_reggroup);
  reggroup_add (gdbarch, e2k_r_reggroup);
  reggroup_add (gdbarch, e2k_rpr_reggroup);

  reggroup_add (gdbarch, e2k_xb_reggroup);
  reggroup_add (gdbarch, e2k_xg_reggroup);
  reggroup_add (gdbarch, e2k_xr_reggroup);

  reggroup_add (gdbarch, e2k_qpb_reggroup);
  reggroup_add (gdbarch, e2k_qpr_reggroup);
}


static int
e2k_register_reggroup_p (struct gdbarch *gdbarch, int regnum,
                         const struct reggroup *group)
{
  if (group == save_reggroup)
    return 1;

  if (group == e2k_aau_reggroup)
    return (regnum >= E2K_AAD_0_LO && regnum <= E2K_AASTI_15);
  else if (group == e2k_b_reggroup)
    return (regnum >= VB0_REGNUM && regnum <= VB127_REGNUM);
  else if (group == e2k_chain_reggroup)
    return ((regnum >= E2K_USBR_REGNUM && regnum <= E2K_PCSHTP_REGNUM)
            || (regnum >= VPSP_LO_REGNUM && regnum <= VPCSP_HI_REGNUM));
  else if (group == e2k_dbg_reggroup)
    return (regnum >= E2K_CLKR_REGNUM && regnum <= E2K_DTART_REGNUM);
  else if (group == float_reggroup)
    return (regnum >= E2K_PFPFR_REGNUM && regnum <= E2K_FPSR_REGNUM);
  else if (group == e2k_g_reggroup)
    return (regnum >= VG0_REGNUM && regnum <= VG31_REGNUM);
  else if (group == e2k_mem_reggroup)
    return (regnum >= E2K_CUD_LO_REGNUM && regnum <= E2K_SS_HI_REGNUM);
  else if (group == e2k_os_reggroup)
    return (regnum >= E2K_PSR_REGNUM && regnum <= E2K_OSR0_REGNUM);
  else if (group == e2k_dam_reggroup)
    return (regnum >= E2K_DAM_0 && regnum <= E2K_DAM_31);
  else if (group == e2k_mlt_reggroup)
    return (regnum >= E2K_MLT_0 && regnum <= E2K_MLT_15);
  else if (group == e2k_pred_reggroup)
    return (regnum >= VP0_REGNUM && regnum <= VP31_REGNUM);
  else if (group == e2k_r_reggroup)
    return (regnum >= VR0_REGNUM && regnum <= (VR0_REGNUM + 63));
  else if (group == e2k_rpr_reggroup)
    return (regnum >= E2K_RPR_HI && regnum <= E2K_RPR_LO);
  else if (group == e2k_xb_reggroup)
    return (regnum >= VXB0_REGNUM && regnum <= (VXB0_REGNUM + 127));
  else if (group == e2k_xg_reggroup)
    return (regnum >= VXG0_REGNUM && regnum <= (VXG0_REGNUM + 31));
  else if (group == e2k_xr_reggroup)
    return (regnum >= VXR0_REGNUM && regnum <= (VXR0_REGNUM + 223));
  else if (group == e2k_qpb_reggroup)
    return regnum >= VQPB0_REGNUM && regnum <= VQPB0_REGNUM + 127;
  else if (group == e2k_qpr_reggroup)
    return regnum >= VQPR0_REGNUM && regnum <= VQPR0_REGNUM + 223;
  else if (group == general_reggroup)
    {
      /* Our notion of general registers is different from that of
         default_register_reggroup_p. */
      return ((regnum >= VR0_REGNUM && regnum <= (VR0_REGNUM + 63))
              || (regnum >= VB0_REGNUM && regnum <= VB127_REGNUM));
    }

  /* Keep this misery to let the old implementation of CALLs work somehow. When
     the new one is used it prevents some important raw registers (e.g. `%cr1.
     {lo,hi}') from being restored properly when popping a dummy frame.  */

  if (group == all_reggroup)
    {
      /* Prevent "fake" and other auxiliary registers having names starting
         with '_' from being displayed via `info all-registers'.  */
      const char *name = gdbarch_register_name (gdbarch, regnum);
      if (name != NULL && name[0] == '_')
        return 0;
    }

  return default_register_reggroup_p (gdbarch, regnum, group);
}


static void
e2k_adjust_binop_arg (struct gdbarch *gdbarch, struct value **pval)
{
struct e2k_gdbarch_data *data = get_e2k_gdbarch_data (gdbarch);

 if ((*pval)->type () == data->tagged64_type)
   *pval = value_struct_elt (pval, {}, "dword", 0, "struct");
}

static int
e2k_convert_register_p (struct gdbarch *gdbarch, int regnum, struct type *type)
{
  /* The following condition doesn't work, since we may (and do!)
     have numerous long doubles in addition to the architectural
     one . . .:
     `type == builtin_type (gdbarch)->builtin_long_double' */

  /* Distinguish `long double' from other types. */
  return (type->length () == 16
          && type->code () == TYPE_CODE_FLT);
}

static int
e2k_register_to_value (const frame_info_ptr &frame, int regnum,
                       struct type *type, gdb_byte *to,
                       int *optimizedp, int *unavailablep)
{
  gdb_assert (type->length () == 16
              && type->code () == TYPE_CODE_FLT);

  /* Do I actually need to copy all 16 bytes? Probably 12 or
     even 10 will do . . . */

  if (!get_frame_register_bytes (frame, regnum, 0, {to, 8},
                                 optimizedp, unavailablep)
      || !get_frame_register_bytes (frame, regnum + 1, 0, {to + 8, 8},
                                    optimizedp, unavailablep))
    return 0;

  /* Success. */
  *optimizedp = *unavailablep = 0;
  return 1;
}


static int
e2k_get_longjmp_target (const frame_info_ptr &frame, CORE_ADDR *pc)
{
  gdb_byte buf[8];
  CORE_ADDR jb_addr;
  struct gdbarch *gdbarch = get_frame_arch (frame);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);

  /* What do I actually have to do with them ? */
  int optimized, unavailable;

  get_frame_register_bytes (frame, VR0_REGNUM, 0, {buf, 8},
                            &optimized, &unavailable);
  jb_addr = extract_unsigned_integer (buf, 8, byte_order);

  if (target_read_memory (jb_addr + 8, buf, 8))
    return 0;

  *pc = extract_unsigned_integer (buf, 8, byte_order);
  return 1;
}

static CORE_ADDR
e2k_frame_align (struct gdbarch *gdbarch, CORE_ADDR address)
{
  /* The ABI requires double-word alignment.  */
  return address & ~0xf;
}

static std::string
e2k_gcc_target_options (struct gdbarch *gdbarch)
{
  return string_printf ("-mptr%d", gdbarch_ptr_bit (gdbarch));
}

static int
e2k_memory_insert_breakpoint (struct gdbarch *gdbarch,
			      struct bp_target_info *bp_tgt)
{
  int val;
  bfd_byte hs_mdl_lng_nop;

  val = default_memory_insert_breakpoint (gdbarch, bp_tgt);
  if (val != 0)
    return val;

  /* Inherit `HS.lng' from the original instruction as proposed in Bug #86419,
     Comment #37 for the sake of Bug #90514 workaround.  */
  hs_mdl_lng_nop = bp_tgt->shadow_contents[0] & 0x70;

  /* Here `HS.mdl == 0x1' and the lowermost bit of `HS.nop == 0x0' both of the
     stale breakpoint instruction and SETSFT are implicitly set up below.
     Fortunately the lowermost byte in SETSFT is the same as in the stale
     breakpoint instruction.  */
  hs_mdl_lng_nop |= (0x01 & 0x8f);

  val = target_write_raw_memory (bp_tgt->reqstd_address, &hs_mdl_lng_nop, 1);
  return val;
}

static int
e2k_memory_remove_breakpoint (struct gdbarch *gdbarch,
			      struct bp_target_info *bp_tgt)
{
  CORE_ADDR addr = bp_tgt->reqstd_address;
  const unsigned char *bp;
  int val;
  int bplen;
  gdb_byte old_contents[BREAKPOINT_MAX];

  /* Determine appropriate breakpoint contents and size for this address.  */
  bp = gdbarch_breakpoint_from_pc (gdbarch, &addr, &bplen);

  /* Make sure we see the memory breakpoints.  */
  scoped_restore restore_memory
    = make_scoped_restore_show_memory_breakpoints (1);
  val = target_read_memory (addr, old_contents, bplen);

  if (val == 0)
    {
      /* If our breakpoint is no longer at the address, this means that the
	 program modified the code on us, so it is wrong to put back the
	 old value (Bug #34592). Note that code modifications leaving the
	 breakpoint intact can't be detected in principle.  */
      if ((bp[0] & 0x8f) == (old_contents[0] & 0x8f)
	  && (bp_tgt->shadow_contents[0] & 0x70) == (old_contents[0] & 0x70)
	  && memcmp (bp + 1, old_contents + 1, bplen - 1) == 0)
	val = target_write_raw_memory (addr, bp_tgt->shadow_contents, bplen);
      else
	warning (_("Cannot remove breakpoint at address %s "
		   "as memory has changed underneath"),
		 paddress (gdbarch, bp_tgt->placed_address));
    }

  return val;
}


static void
e2k_dwarf2_frame_init_reg (struct gdbarch *gdbarch, int regnum,
			   struct dwarf2_frame_state_reg *reg,
			   const frame_info_ptr &this_frame)
{
#if 0
  /* This is incorrect in principle, because `e2k_frame_prev_register ()'
     believes that a frame being passed has a cache of `struct e2k_frame_cache'
     type associated with it. A frame created by `dwarf2-frame.c' has a `struct
     dwarf2_frame_cache' associated with it, therefore it shouldn't be passed to
     `e2k_frame_prev_register ()'. If only I could support our cache along with
     DWARF2-specific one for such frames . . . Currently I don't see how this
     can be achieved.  */
  reg->how = DWARF2_FRAME_REG_FN;
  reg->loc.fn = e2k_frame_prev_register;
#endif /* 0  */
}


static int
e2k_tdesc_numbered_register (const struct tdesc_feature *feature,
			     struct tdesc_arch_data *data,
			     int regno, const char *name)
{
  if (name[0] != '_')
    return tdesc_numbered_register (feature, data, regno, name);

  return tdesc_invisible_numbered_register (feature, data, regno, name);
}

/* Return a floating-point format for a floating-point variable of
   length LEN in bits.  If non-NULL, NAME is the name of its type.
   If no suitable type is found, return NULL.  */

static const struct floatformat **
e2k_floatformat_for_type (struct gdbarch *gdbarch,
			  const char *name, int len)
{
  if (len == 128 && name)
    if (strcmp (name, "__float128") == 0
	|| strcmp (name, "_Float128") == 0
	|| strcmp (name, "complex _Float128") == 0
	/* LCC unlike GCC makes use of this type name in debug info. Find out
	   if this is a bug.  */
	|| strcmp (name, "complex __float128") == 0
	/* These type names are used by Fortran.  */
	|| strcmp (name, "real(kind=16)") == 0
	|| strcmp (name, "complex(kind=16)") == 0)
      return floatformats_ieee_quad;

  return default_floatformat_for_type (gdbarch, name, len);
}


static int
e2k_validate_tdesc_p (e2k_gdbarch_tdep *tdep,
                      const struct target_desc *tdesc,
                      struct tdesc_arch_data *tdesc_data)
{
  const struct tdesc_feature *generic;
  const struct tdesc_feature *elbrus_v2;
  const struct tdesc_feature *elbrus_v3;
  const struct tdesc_feature *elbrus_v5;
  const struct tdesc_feature *elbrus_v6;
  const struct tdesc_feature *elbrus_v7;
  const struct tdesc_feature *dam_feature;
  const struct tdesc_feature *rwap_feature;
  const struct tdesc_feature *tagged_feature;
  int i, valid_p;

  generic = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k.linux");
  if (generic == NULL)
    return 0;

  elbrus_v2 = tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v2.linux");
  elbrus_v3 = tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v3.linux");
  elbrus_v5 = tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v5.linux");
  elbrus_v6 = tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v6.linux");
  elbrus_v7 = tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v7.linux");

  /* The implementation of DAM and thus the types of %damX registers are
     iset-specific: according to Bug #147177, Comment #1 there are 4 different
     implementations: elbrus-v1 specific one, elbrus-v2 (with a couple of
     bitfields removed), elbrus-v{3,4,5} and elbrus-v{6,7}. The underlying
     selection of appropriate feature for %damX registers takes this into
     account.  */
  dam_feature = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k-dam.linux");
  rwap_feature = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k-rwap.linux");
  tagged_feature = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k-tagged.linux");

  /* Tagged values are also iset (elbrus-v{X{<,>=}7})-specific nowadays.  */
  tagged_feature = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k-tagged.linux");

  valid_p = 1;

  for (i = 0; i < NUM_E2K_RAW_REGS;
       /* Skip `elbrus-v{2,3,5}'...  */
       (i == E2K_MLT_15
	? i = E2K_PCSP_BASE
	/* ... and `elbrus-v6'-specific raw registers.  */
	: (i == E2K_DIMTP_LO_REGNUM - 1
	   ? i = E2K_CTPR3_HI_REGNUM + 1
	   : i++)))
    {
      const struct tdesc_feature *feature;
      if (i >= E2K_DAM_0 && i <= E2K_DAM_31)
	feature = dam_feature;
      else if ((i >= E2K_USD_LO_REGNUM && i <= E2K_PSP_HI_REGNUM)
	       || (i >= E2K_PCSP_LO_REGNUM && i <= E2K_PCSP_HI_REGNUM)
	       || (i >= E2K_CUD_LO_REGNUM && i <= E2K_GD_HI_REGNUM)
	       || (i >= E2K_PUSD_LO_REGNUM && i <= E2K_PUSD_HI_REGNUM))
	feature = rwap_feature;
      else if (i == E2K_FAKE_MEM_TAGGED32_REGNUM
	       || i == E2K_FAKE_MEM_TAGGED64_REGNUM
	       || i == E2K_FAKE_MEM_SIGNED_TAGGED32_REGNUM
	       || i == E2K_FAKE_MEM_SIGNED_TAGGED64_REGNUM)
	feature = tagged_feature;
      else
	feature = generic;

      valid_p &= e2k_tdesc_numbered_register (feature, tdesc_data, i,
					      e2k_register_names[i]);
    }

  if (elbrus_v2)
    valid_p &=
      e2k_tdesc_numbered_register (elbrus_v2, tdesc_data, E2K_IDR_REGNUM,
                                   e2k_register_names[E2K_IDR_REGNUM]);

  if (elbrus_v3)
    valid_p &=
      e2k_tdesc_numbered_register (elbrus_v3, tdesc_data, E2K_CORE_MODE_REGNUM,
                                   e2k_register_names[E2K_CORE_MODE_REGNUM]);

  if (elbrus_v5)
    {
      for (i = E2K_LSR1_REGNUM; i <= E2K_GTAG_V5_31_REGNUM; i++)
	valid_p &= e2k_tdesc_numbered_register (elbrus_v5, tdesc_data, i,
						e2k_register_names[i]);

      /* Take into account `MAXS(tack)R_d == 224' stack %qprX registers covering
         the whole register window of the maximal possible size, of which only
         the first 64 ones are available via assembler, 128 %qpbX and 32 %qpgX
         registers.  */
      tdep->num_elbrus_v5_pseudo_regs = 224 + 128 + 32;
    }
  else
    /* This can be avoided because TDEP is `XZALLOCC ()'ed in `e2k_gdbarch_
       init ()'.  */
    tdep->num_elbrus_v5_pseudo_regs = 0;

  if (elbrus_v6)
    {
      for (i = E2K_DIMTP_LO_REGNUM; i <= E2K_CTPR3_HI_REGNUM; i++)
	valid_p &= e2k_tdesc_numbered_register (elbrus_v6, tdesc_data, i,
						e2k_register_names[i]);
    }

  /* Are we debugging on elbrus-v7?  */
  tdep->is_elbrus_v7 = elbrus_v7 != NULL ? 1 : 0;

  return valid_p;
}

void
e2k_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  set_gdbarch_long_bit (gdbarch, 64);
  set_gdbarch_long_long_bit (gdbarch, 64);
  set_gdbarch_ptr_bit (gdbarch, 64);
}



static struct gdbarch *
e2k_gdbarch_init (struct gdbarch_info info, struct gdbarch_list *arches)
{
  struct gdbarch *gdbarch;

  /* If there is already a candidate, use it.  */
  arches = gdbarch_list_lookup_by_info (arches, &info);
  if (arches != NULL)
    return arches->gdbarch;

  gdbarch = gdbarch_alloc (&info, gdbarch_tdep_up (new e2k_gdbarch_tdep));
  e2k_gdbarch_tdep *tdep = gdbarch_tdep<e2k_gdbarch_tdep> (gdbarch);


  /* GDBARCH without target description is actually unusable at E2K. Set the
     number of registers to zero so that nobody ever attempts to call non-target
     description methods to obtain their names and types.  */
  set_gdbarch_num_regs (gdbarch, 0);
  set_gdbarch_num_pseudo_regs (gdbarch, 0);
  set_gdbarch_register_name (gdbarch, e2k_register_name);
  set_gdbarch_register_type (gdbarch, e2k_register_type);
  set_gdbarch_pseudo_register_read (gdbarch, e2k_pseudo_register_read);
  set_gdbarch_deprecated_pseudo_register_write (gdbarch, e2k_pseudo_register_write);

  if (! tdesc_has_registers (info.target_desc))
    info.target_desc = tdesc_e2k_linux;

  gdb_assert (tdesc_has_registers (info.target_desc));

  if (tdesc_has_registers (info.target_desc))
    {
      tdesc_arch_data_up tdesc_data = tdesc_data_alloc ();

      if (!e2k_validate_tdesc_p (tdep, info.target_desc, tdesc_data.get ()))
        {
	  delete tdep;
          gdbarch_free (gdbarch);
          return NULL;
        }

      set_gdbarch_num_regs (gdbarch, NUM_E2K_RAW_REGS);
      set_gdbarch_num_pseudo_regs (gdbarch,
                                   (NUM_E2K_PSEUDO_REGS +
                                    tdep->num_elbrus_v5_pseudo_regs));
      set_tdesc_pseudo_register_type (gdbarch, e2k_pseudo_register_type);
      set_tdesc_pseudo_register_name (gdbarch, e2k_pseudo_register_name);
      tdesc_use_registers (gdbarch, info.target_desc, std::move (tdesc_data));
    }

  set_gdbarch_skip_prologue (gdbarch, e2k_skip_prologue);

  set_gdbarch_breakpoint_kind_from_pc (gdbarch, e2k_breakpoint_kind_from_pc);
  set_gdbarch_sw_breakpoint_from_kind (gdbarch, e2k_sw_breakpoint_from_kind);

  /* FIX this back to `core_addr_lessthan' when ready to
     use User Stack instead of Procedure Stack for
     creating frame IDs (see the comment before `this_psp'
     field in e2k_frame_cache struct. */
  set_gdbarch_inner_than (gdbarch, core_addr_greaterthan);

  set_gdbarch_read_pc (gdbarch, e2k_read_pc);
  set_gdbarch_write_pc (gdbarch, e2k_write_pc);
  set_gdbarch_unwind_pc (gdbarch, e2k_unwind_pc);
  set_gdbarch_dwarf2_reg_to_regnum (gdbarch, e2k_dwarf_reg_to_regnum);

  set_gdbarch_remote_register_number (gdbarch,
                                      e2k_remote_register_number);

  set_gdbarch_print_registers_info (gdbarch, e2k_print_registers_info);


  /* These hooks are required to support tagged values' output
     via `x' command (see `printcmd.c') */
  set_gdbarch_override_examine_val_type
    (gdbarch, e2k_override_examine_val_type);
  set_gdbarch_examine_value (gdbarch, e2k_examine_value);
  set_gdbarch_next_address (gdbarch, e2k_next_address);

  set_gdbarch_call_dummy_location (gdbarch, AT_ENTRY_POINT);
  set_gdbarch_push_dummy_call (gdbarch, e2k_push_dummy_call_new);
  
  set_gdbarch_unwind_sp (gdbarch, e2k_unwind_sp);
  set_gdbarch_return_value (gdbarch, e2k_return_value);

  set_gdbarch_dummy_id (gdbarch, e2k_dummy_id);
  set_gdbarch_register_reggroup_p (gdbarch, e2k_register_reggroup_p);

  set_gdbarch_adjust_binop_arg (gdbarch, e2k_adjust_binop_arg);

  set_gdbarch_long_double_format (gdbarch, floatformats_i387_ext);
  set_gdbarch_long_double_bit (gdbarch, 128);

  /* Support for floating-point data type variants.  */
  set_gdbarch_floatformat_for_type (gdbarch, e2k_floatformat_for_type);

  set_gdbarch_convert_register_p (gdbarch, e2k_convert_register_p);
  set_gdbarch_register_to_value (gdbarch, e2k_register_to_value);

  set_gdbarch_get_longjmp_target (gdbarch, e2k_get_longjmp_target);

  /* Register numbers of various important registers.  */
  set_gdbarch_sp_regnum (gdbarch, VSP_REGNUM);

  set_gdbarch_frame_align (gdbarch, e2k_frame_align);

  set_gdbarch_gcc_target_options (gdbarch, e2k_gcc_target_options);

  set_gdbarch_memory_insert_breakpoint (gdbarch, e2k_memory_insert_breakpoint);
  set_gdbarch_memory_remove_breakpoint (gdbarch, e2k_memory_remove_breakpoint);

  /* Add the e2k-specific register groups. I wonder why
     `e2k_init_reggroups' is called from _initialize_e2k_tdep ()
     and what's the difference between these two functions. */

  e2k_add_reggroups (gdbarch);

  /* Hook in ABI-specific overrides, if they have been registered.  */
  gdbarch_init_osabi (info, gdbarch);

  dwarf2_frame_set_init_reg (gdbarch, e2k_dwarf2_frame_init_reg);

  /* Note that E2K-specific unwinder should be probably appended after DWARF2
     one if I want the latter to take the precedence when sniffing a frame.
     The DWARF2 unwinder is appended in `e2k-linux-tdep.c' while initializing
     OSABI one line above.  */

  frame_unwind_append_unwinder (gdbarch, &e2k_sigtramp_frame_unwind);
  frame_unwind_append_unwinder (gdbarch, &e2k_frame_unwind);



  return gdbarch;
}

/* Methods required for `e2k' target implementation. */

static void
e2k_target_open (const char *arg, int from_tty)
{
}



struct tags_xfer_info
{
  ULONGEST offset;
  LONGEST len;
  gdb_byte *buf;
};

static bfd_boolean
section_contains_tags (bfd *abfd, asection *asec, void *info)
{
  flagword aflag;
  ULONGEST sec_addr, sec_endaddr;
  struct tags_xfer_info *tags_xfer_info;
  LONGEST i, len;
  ULONGEST xfer_addr, xfer_endaddr;
  ULONGEST offs, byte_offs, bit_offs;
  gdb_byte c, *buf;

  aflag = bfd_section_flags (asec);
  /* To ensure that TAGS sections are not mixed with LOAD sections within
     a corefile, I'd prefer them to be unallocated.  */
  if (aflag & SEC_ALLOC)
    return FALSE;

  if (strncmp (bfd_section_name (asec), "proc", 4) != 0)
    return FALSE;

  /* This is an actual address range covered by the section.  */
  sec_addr = (ULONGEST) bfd_section_vma (asec);
  sec_endaddr = sec_addr + (bfd_section_size (asec) << 4);

  tags_xfer_info = (struct tags_xfer_info *) info;
  len = tags_xfer_info->len;
  /* This is an actual address range covered by this request.  */
  xfer_addr = tags_xfer_info->offset;
  xfer_endaddr = xfer_addr + (tags_xfer_info->len << 2);

  if (xfer_addr < sec_addr || xfer_endaddr > sec_endaddr)
    return FALSE;

  buf = tags_xfer_info->buf;
  offs = xfer_addr - sec_addr;
  if (len == 1)
    gdb_assert ((offs & 3) == 0);
  else /* len == 2, see the corresponding assert in `e2k_xfer_partial'  */
    gdb_assert ((offs & 7) == 0);
    
  byte_offs = offs >> 4;
  bit_offs = ((offs >> 2) & 3) << 1;

  if (bfd_get_section_contents (abfd, asec, &c, byte_offs, 1) == FALSE)
    return FALSE;

  for (i = 0; i < len; i++)
    {
      buf[i] = (c & (3 << bit_offs)) >> bit_offs;
      bit_offs += 2;
    }


  return TRUE;
}


/* Override the to_xfer_partial routine. This is required because tags stored
   within a core file should be accessed in a non-standard way as well.  */
static enum target_xfer_status
e2k_xfer_partial (struct target_ops *ops, enum target_object object,
		  const char *annex, gdb_byte *readbuf,
		  const gdb_byte *writebuf,
		  ULONGEST offset, ULONGEST len,
		  ULONGEST *xfered_len)
{
  struct target_ops *ops_beneath;
  enum target_object final_object = TARGET_OBJECT_MEMORY;

  if (object == TARGET_OBJECT_TAG && writebuf == NULL
      && current_program_space->core_bfd ())
    {
      struct tags_xfer_info tags_xfer_info;

      gdb_assert (len == 1 || len == 2);
      tags_xfer_info.offset = offset;
      tags_xfer_info.len = len;
      tags_xfer_info.buf = readbuf;

      if (bfd_sections_find_if (current_program_space->core_bfd (),
				section_contains_tags,
                                (void *) &tags_xfer_info) == FALSE)
        {
          LONGEST i;
          for (i = 0; i < len; i++)
            readbuf[i] = 0;
        }

      *xfered_len = len;
      return TARGET_XFER_OK;
    }


  /* In order to support TARGET_OBJECT_TAG and . . .  */
  final_object = object;

  ops_beneath = ops->beneath ();
  gdb_assert (ops_beneath);

  return ops_beneath->xfer_partial (final_object, annex,
				    readbuf, writebuf, offset, len,
				    xfered_len);
}


/* Override the to_thread_architecture routine.  */
static struct gdbarch *
e2k_thread_architecture (struct e2k_target *targ, ptid_t ptid)
{
  return current_inferior ()->arch ();
}

static ptid_t
e2k_wait (struct target_ops *ops,
          ptid_t ptid, struct target_waitstatus *status,
	  target_wait_flags options)
{

  struct target_ops *ops_beneath = ops->beneath ();
  gdb_assert (ops_beneath);

  return ops_beneath->wait (ptid, status, options);
}

static void
e2k_mourn_inferior (struct target_ops *ops)
{
  struct inferior *inf = current_inferior ();
  struct target_ops *ops_beneath = ops->beneath ();
  gdb_assert (ops_beneath);
  ops_beneath->mourn_inferior ();

  inf->priv = NULL;
}

/* The underlying three routines are used when generating a corefile
   via gcore.  */
static void
make_tags_section (bfd *obfd, asection *lsec, void *ignored)
{
  asection *tsec;
  flagword flags;
  bfd_vma vma;
  bfd_vma start_tags_vma, end_tags_vma;
  bfd_size_type size;

  if (strncmp (bfd_section_name (lsec), "load", 4) != 0)
    return;

  flags = SEC_HAS_CONTENTS;
  tsec = bfd_make_section_anyway_with_flags (obfd, "tags", flags);

  vma = bfd_section_vma  (lsec);
  size = bfd_section_size (lsec);

  /* Tags section corresponds to 4-byte aligned contents of the Load
     section. . . . Finally I understood that I want a whole number
     of bytes per tags section, not a "fractional" one. Taking into
     account that a byte of tags corresponds to 16 bytes of data,
     I obtained the following:  */
  start_tags_vma = vma & -16;
  end_tags_vma = (vma + size + 15) & -16;
  if (start_tags_vma >= end_tags_vma)
    size = 0;
  else
    /* 4 bytes of data correspond to 2 bits of tags.  */
    size = (end_tags_vma - start_tags_vma) >> 4;

  bfd_set_section_size (tsec, size);
  bfd_set_section_vma (tsec, start_tags_vma);

  bfd_record_phdr (obfd, PT_E2K_TAG, 1, PF_R, 0, 0, 0, 0, 1, &tsec);
}

/* FIXME: this definition used to duplicate `MAX_COPY_BYTES == 1 Mb' in
   `gcore.c'. However, it has been drastically reduced to 4 Kb because I
   suspect that a problem arised when attempting to transfer the previously
   used MAX_COPY_BYTES via  remote protocol: 1 Mb doesn't fit a packet which is
   limited by a few (dozens?) of Kb. To be revisited.
   

   The largest amount of memory to read from the target at once.  We
   must throttle it to limit the amount of memory used by GDB during
   generate-core-file for programs with large resident data.  */
#define MAX_COPY_BYTES (4 * 1024)

static void
fill_tags_section (bfd *obfd, asection *tsec, void *ignored)
{
  bfd_size_type size, total_size = bfd_section_size (tsec);
  file_ptr offset = 0;
  gdb_byte *memhunk;
  

  /* Only interested in "tags" sections.  */
  if (strncmp ("tags", bfd_section_name (tsec), 4) != 0)
    return;

  size = std::min (total_size, (bfd_size_type) MAX_COPY_BYTES);
  memhunk = (gdb_byte *) xmalloc (size);

  auto cleanup = make_scope_exit ([&] ()
    {
      xfree (memhunk);
    });

  while (total_size > 0)
    {
      if (size > total_size)
        /* This may happen at the last iteration.  */
	size = total_size;

      if (target_read (current_inferior ()->top_target (), TARGET_OBJECT_TAG, NULL, memhunk,
                       bfd_section_vma (tsec) + (offset << 4),
                       size << 2) != size << 2)
	{
	  /* This is likely to happen for Procedure and Chain stacks as well as
	     for some Dummy area at the top of the inferior's address space.
	     Whereas external tags in the Chain stack may make no sense (I
	     cannot think of the one in fact), it's not clear how the ones of
	     spilled window registers are to be obtained without the ability
	     to read them from the Procedure stack. As for the Dummy area, its
	     role is to be clarified before making a conclusion.

	     The warning is commented out until the aforesaid is done so as not
	     to confuse users (see Bug #133762, Comment #0).  */
#if 0
	  warning (_("Obtaining tags failed for corefile "
		     "section, %s bytes at %s."),
		   plongest (size),
		   paddress (current_inferior ()->arch (), bfd_section_vma (tsec)));
#endif /* 0  */
	  break;
	}
      if (!bfd_set_section_contents (obfd, tsec, memhunk, offset, size))
	{
	  warning (_("Failed to write corefile contents (%s)."),
		   bfd_errmsg (bfd_get_error ()));
	  break;
	}

      total_size -= size;
      offset += size;
    }
}

static void
e2k_make_corefile_sections (struct target_ops *self, bfd *obfd)
{

  bfd_map_over_sections (obfd, make_tags_section, NULL);
  bfd_map_over_sections (obfd, fill_tags_section, NULL);
}


static void
e2k_aau_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("aau", 0);
}

static void
e2k_br_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("b", 0);
}

static void
e2k_chain_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("chain", 0);
}

static void
e2k_dbg_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("dbg", 0);
}

static void
e2k_g_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("g", 0);
}

static void
e2k_mem_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("mem", 0);
}

static void
e2k_os_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("os", 0);
}

static void
e2k_dam_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("dam", 0);
}


static void
e2k_mlt_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("mlt", 0);
}


static void
e2k_pred_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("pred", 0);
}

static void
e2k_r_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("r", 0);
}

static void
e2k_xbr_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("xb", 0);
}

static void
e2k_xg_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("xg", 0);
}


static void
e2k_xr_registers_info (const char *gregs_exp, int from_tty)
{
  registers_info ("xr", 0);
}


/* Decide whether to output this register via `info frame'. We have too many
   registers (e.g., %r's and %xr's) to output them all. I don't want to output
   info on %pred's and %fp's either, because they require previous frame which
   may turn out to be NULL in case we are dealing with the outermost frame.
   Keep in mind that `info frame' prints info on previous frame's regs
   in fact.  */
int
e2k_consider_reg_for_info_frame (int regnum)
{
  if ((regnum >= VR0_REGNUM && regnum <= VR223_REGNUM)
      || (regnum >= VB0_REGNUM && regnum <= VB127_REGNUM))
    return 1;

  return 0;
}

static const target_info e2k_target_info = {
  "e2k",
  N_("e2k specific target for native-independent hw breakpoint support"),
  N_("This target is added automatically")
};


struct e2k_target final : public target_ops
{
  strata stratum () const override { return arch_stratum; }

  const target_info &info () const override
  { return e2k_target_info; }

  enum target_xfer_status xfer_partial (enum target_object object,
					const char *annex,
					gdb_byte *readbuf,
					const gdb_byte *writebuf,
					ULONGEST offset, ULONGEST len,
					ULONGEST *xfered_len) override
  { return e2k_xfer_partial (this, object, annex, readbuf, writebuf,
			     offset, len, xfered_len); }



  struct gdbarch *thread_architecture (ptid_t ptid) override
  { return e2k_thread_architecture (this, ptid); }

  /* FIXME: the use of OVERRIDE here breaks the compilation as open doesn't
     seem to be a (virtual) method in the base class. What about numerous other
     places?  */
  void open (const char *arg, int from_tty)/* override  */
  { return e2k_target_open (arg, from_tty); }

  ptid_t wait (ptid_t ptid, struct target_waitstatus *status, target_wait_flags options) override
  { return e2k_wait (this, ptid, status, options); }

  void mourn_inferior () override
  { e2k_mourn_inferior (this); }

  void make_corefile_sections (bfd *obfd) override
  { e2k_make_corefile_sections (this, obfd); }
};

static e2k_target e2k_ops;

static void
e2k_inferior_created (inferior *inf)
{
  // struct inferior *inf = current_inferior ();

  current_inferior ()->push_target (&e2k_ops);

  /* In my target-based approach to watchpoints (as opposed to a
     native-based one, see i386-nat.c and others) an appropriate
     target has not been setup by the time of `breakpoint_re_set'
     call in `post_create_inferior' (see infcmd.c). Therefore
     repeat this call here to make software watchpoints a chance
     of being converted to hardware ones. */

  /* Software watchpoints  require single-stepping, therefore if
     a watchpoint had been created before the very first `run'
     the program used to be executed in a single-step manner which
     was very slowly. Moreover, our atomic operations (inside
     `longjmp' and others) cannot be passed in a single-step manner. */

  breakpoint_re_set ();

  e2k_inferior *priv = new e2k_inferior;
  inf->priv.reset (priv);
}

void _initialize_e2k_tdep ();
void
_initialize_e2k_tdep ()
{
  gdbarch_register (bfd_arch_e2k, e2k_gdbarch_init, NULL);

  gdb::observers::inferior_created.attach (e2k_inferior_created, "e2k");

  /* Push it at as soon as possible so that it can
     override all these clumsy `nat'- and `remote'-specific
     methods for setting hardware {break,watch}points. */

  /* It'll be removed afterwards when opening `remote'
     target. Defer it until . . .  */
  /* push_target (t);  */

  /* Initialize the e2k-specific register groups. */
  e2k_init_reggroups ();

  add_info ("aau-registers", e2k_aau_registers_info, _(""));
  /* I'd prefer to have `info b-registers' since `br' reggroup
     name conflicts with the register `$br'. However for
     compatibility with gdb-5.2 leave it this way. */
  add_info ("br-registers", e2k_br_registers_info, _(""));
  add_info ("chain-registers", e2k_chain_registers_info, _(""));
  add_info ("dbg-registers", e2k_dbg_registers_info, _(""));
  add_info ("g-registers", e2k_g_registers_info, _(""));
  add_info ("mem-registers", e2k_mem_registers_info, _(""));
  add_info ("os-registers", e2k_os_registers_info, _(""));
  add_info ("dam", e2k_dam_registers_info, _(""));
  add_info ("mlt", e2k_mlt_registers_info, _(""));
  add_info ("pred-registers", e2k_pred_registers_info, _(""));
  add_info ("r-registers", e2k_r_registers_info, _(""));
  add_info ("xbr-registers", e2k_xbr_registers_info, _(""));
  add_info ("xg-registers", e2k_xg_registers_info, _(""));
  add_info ("xr-registers", e2k_xr_registers_info, _(""));


  initialize_tdesc_e2k_linux ();
  initialize_tdesc_elbrus_v2_linux ();
  initialize_tdesc_elbrus_v3_linux ();
  initialize_tdesc_elbrus_v5_linux ();
  initialize_tdesc_elbrus_v6_linux ();
  initialize_tdesc_elbrus_v7_linux ();
  initialize_tdesc_elbrus_maket32c_linux ();
}
