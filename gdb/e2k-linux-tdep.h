/* Copyright (c) 2009-2025 AO MCST.
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

#ifndef E2K_LINUX_TDEP_H
#define E2K_LINUX_TDEP_H 1

/* Include this file shared between GDB and GDBSERVER at target level for the
   sake of `e2k_linux_ptrace_offsets[]' required for manipulations with core
   files (recall that the corresponding offsets in `user_regs_struct' and
   `.reg' corefile section are the same).  */
#include "gdbsupport/e2k-linux-regs.h"


extern struct target_desc *tdesc_e2k_linux;
extern struct target_desc *tdesc_elbrus_v2_linux;
extern struct target_desc *tdesc_elbrus_v3_linux;
extern struct target_desc *tdesc_elbrus_v5_linux;
extern struct target_desc *tdesc_elbrus_v6_linux;
extern struct target_desc *tdesc_elbrus_v7_linux;
extern struct target_desc *tdesc_elbrus_maket32c_linux;


extern LONGEST e2k_linux_get_syscall_number (struct gdbarch *gdbarch,
                                             thread_info *thread);

extern void e2k_supply_gregset (struct regcache *regcache,
                                int regnum,
				const e2k_linux_gregset_t gregs,
				size_t len);

extern void e2k_supply_fpregset (const int *reg_offsets,
                                 struct regcache *regcache,
                                 int regnum,
                                 const void *fpregs);

extern void e2k_collect_gregset (const int *reg_offsets,
                                 const struct regcache *regcache,
                                 int regnum,
                                 void *gregs,
                                 int to_core);

extern const struct target_desc *
e2k_linux_core_read_description (struct gdbarch *gdbarch,
                                 struct target_ops *target,
                                 bfd *abfd);

#endif /* E2K_LINUX_TDEP_H  */
