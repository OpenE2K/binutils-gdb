/* Target-dependent code for E2K Protected Mode.

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

#ifndef E2K_PM_TDEP_H
#define E2K_PM_TDEP_H 1

#include "e2k-tdep.h"

extern void e2k_pm_init_abi (struct gdbarch_info info,
                             struct gdbarch *gdbarch);

#endif /* e2k-pm-tdep.h */
