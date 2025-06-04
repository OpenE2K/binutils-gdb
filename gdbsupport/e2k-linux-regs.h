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

#ifndef E2K_LINUX_REGS_H
#define E2K_LINUX_REGS_H

#include "gdbsupport/e2k-regs.h"

#define SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT	4784
#define SIZE_OF_ELBRUS_V5_USER_REGS_STRUCT	4744
#define SIZE_OF_ELBRUS_V1_USER_REGS_STRUCT	4408

extern const int e2k_linux_ptrace_offsets[NUM_E2K_RAW_REGS];

/* `sizeof (new_user_regs_struct_in_the_kernel) == 4744', I add one extra dword
   at the very tail of `e2k_linux_gregset_t' for `%_pcsp_offset' and therefore
   obtain `4744 + 8 == 594 * 8' bytes.  */
typedef unsigned long long
e2k_linux_gregset_t[(SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT + 8) / 8];


#define byte_offset(r) (e2k_linux_ptrace_offsets[r])
#define gregset_idx(r) (e2k_linux_ptrace_offsets[r] / 8)

#endif /* E2K_LINUX_REGS_H  */
