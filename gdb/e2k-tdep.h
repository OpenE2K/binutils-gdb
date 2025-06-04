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

#ifndef E2K_TDEP_H
#define E2K_TDEP_H 1

/* For private_inferior which e2k_inferior is derived from.  */
#include "inferior.h"

/* Register offsets for the general-purpose register set.  */

struct e2k_gregset
{
  int r_cr0_hi_offset;
  int r_pcsp_lo_offset;
  int r_pcsp_hi_offset;
};

struct e2k_insn_seq;

/* E2K architecture-specific information.  */

struct e2k_gdbarch_tdep : gdbarch_tdep_base
{
  /* FIXME: this should definitely be removed from here. I just needed to
     remember it somewhere to restore when creating a momentary breakpoint when
     fetching the return value of a CALL. It seems that this breakpoint may very
     well manage with NULL_FRAME_ID, it doesn't require its ID to coincide with
     the one of the respective DUMMY FRAME.  */
  struct frame_id outer_trampoline_id;

  int num_elbrus_v5_pseudo_regs;
  int is_elbrus_v7;
};

/* Get common info on register numbers.  */
#include "gdbsupport/e2k-regs.h"

/* The e2k-specific description of an inferior. */
struct e2k_inferior : public private_inferior
{
};

/* Return the e2k_inferior attached to INF.  */

static inline e2k_inferior *
get_e2k_inferior (inferior *inf)
{
  return static_cast<e2k_inferior *> (inf->priv.get ());
}


extern void e2k_init_abi (struct gdbarch_info info,
                          struct gdbarch *gdbarch);


/* FIXME: these ones are now required in `e2k32-tdep.c' as well.
   Probably they should be moved from e2k-tdep.c as well as these
   declarations from here. */

extern struct internalvar * create_ivar_from_reg
(struct gdbarch * gdbarch, readable_regcache *regcache, int regnum);

extern ULONGEST ivar_field (struct internalvar *var, const char *name);

extern void set_ivar_field (struct internalvar *var, const char *name,
                            ULONGEST num);

struct internalvar * create_ivar_from_value (struct value *val);

extern void free_ivar (struct internalvar *var);

extern void create_momentary_breakpoint (struct gdbarch *gdbarch,
					 int dummy,
					 CORE_ADDR sp,
					 CORE_ADDR pc);


/* This one is probably in its place. */
extern CORE_ADDR e2k_allocate_arguments (struct gdbarch *gdbarch,
					 struct regcache *regcache,
					 int nargs,
                                         struct value **args,
					 CORE_ADDR bp_addr,
					 CORE_ADDR sp,
                                         int struct_return);

extern int e2k_common_stopped_data_address (struct gdbarch *gdbarch,
                                           struct target_ops *target,
                                           CORE_ADDR *addr_p,
                                           int via_linux_ops);

extern int e2k_common_stopped_by_watchpoint (struct gdbarch *gdbarch,
					     struct target_ops *ops,
                                             int via_linux_ops);

/* This prototype is required in stack.c for `info frame' implementation
   (see commits related to Bug #63058).  */
extern int e2k_consider_reg_for_info_frame (int regnum);


struct e2k_gdbarch_data
{
  e2k_gdbarch_data (struct gdbarch *);
  struct type *hword_type;
  struct type *word_type;

  /* These types are used for reading and manipulating different syllables.  */
  struct type *hs_type;
  struct type *alf2_type;
  struct type *c1f1_type;
  struct type *cs0_dummy_type;
  struct type *cs1_setwd_type;
  struct type *cs1_call_type;
  struct type *lts0_setwd_type;
  struct type *ss_type;
  struct type *ctpr_rwp_type;

  /* Types for values with external tags on registers.  */
  struct type *tagged64_type;
  struct type *tagged80_type;
  /* This type is intended for use with `%qprX' registers. Shouldn't it be
     renamed somehow? Currently it may be unintentionally associated with
     `%qrX' registers which are yet to be supported in GDB.  */
  struct type *tagged128_type;


  /* Types for values with external tags in memory.  */
  struct type *mem_tagged32_type;
  struct type *mem_tagged64_type;

  /* Types for signed values with external types which may emerge as a result
     of `x' command. For example, `x/wd' should be output as signed . . .  */
  struct type *mem_signed_tagged32_type;
  struct type *mem_signed_tagged64_type;


  /* Type of a predicate register.  */
  struct type *pred_type;

  struct type *cut_zero_type;
  struct type *cut_two_type;

  /* Type of a "predicate file" stored in `%cr0.lo'.  */
  struct type *pf_type;

  struct type *mlt_type;

  struct type *dbl_param_type;
  struct type *quad_param_type;
};

extern struct e2k_gdbarch_data *get_e2k_gdbarch_data (struct gdbarch *gdbarch);


/* FIXME: this declaration is used in `e2k{,32,-pm}-linux-tdep.c' and should be
   probably moved to `e2k-linux-tdep.h', which is to be created yet.  */
extern void e2k_linux_iterate_over_regset_sections
(struct gdbarch *, iterate_over_regset_sections_cb,
 void *, const struct regcache *);



extern void c_e2k_val_print_ex
(struct type *type, const gdb_byte *valaddr,
 int embedded_offset, CORE_ADDR address,
 struct ui_file *stream, int recurse,
 struct value *original_value,
 const struct value_print_options *options,
 const struct value_print_options *options_2,
 int mlt_i);


extern void e2k_linux_report_signal_info
(struct gdbarch *gdbarch, struct ui_out *uiout,
 enum gdb_signal siggnal);


extern const struct e2k_insn_seq dummy_prologue_np;
extern const struct e2k_insn_seq dbl_on_reg;
extern const struct e2k_insn_seq quad_on_reg;

#endif /* e2k-tdep.h */
