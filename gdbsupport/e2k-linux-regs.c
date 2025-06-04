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

#include "gdbsupport/e2k-linux-regs.h"

const int e2k_linux_ptrace_offsets[NUM_E2K_RAW_REGS] =
{
#define E2K_RAW_REG(a, b, c) b,
#define E2K_PSEUDO_REG(a, b)

  /* Define it for symmetry with inclusions of "e2k-regs.inc" into other files
     (wouldn't it be better to include "config.h" instead?). Otherwise the
     values in `e2k_linux_ptrace_offsets[]' won't match the actual target
     register numbers.  */
#include "e2k-regs.inc"

#undef E2K_PSEUDO_REG
#undef E2K_RAW_REG
};
