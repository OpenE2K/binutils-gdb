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

#ifndef E2K_REGS_H
#define E2K_REGS_H

/* This header contains info on E2K register numbers shared at target level
   between GDB and GDBSERVER.  */

/* Currently this reserves numbers for all possible raw registers including
   potentially (un)available `elbrus-v5'-specific ones.

   913 == (599 generic + 66 `elbrus-v5' specific + 5 `elbrus-v6' ones)
   registers transferred to GDBSERVER + 243 which are not transferred.  */
#define NUM_E2K_RAW_REGS        914

/* Unlike the preceding definition this DOESN'T reserve numbers for
   `elbrus-v5'-specific pseudo registers. They'll be accounted for in `TDEP->
   num_elbrus_v5_pseudo_regs' addend if present.  */
#define NUM_E2K_PSEUDO_REGS     1172

/* This macro takes into account all pseudo registers including potentially
   (un)available `elbrus-v5'-specific ones. Currently it's used to initialize
   `e2k_register_names []' having the maximal possible size.  */
#define NUM_E2K_ALL_PSEUDO_REGS 1556

enum e2k_regnum
{
#define E2K_RAW_REG(a, b, c) c,
#define E2K_PSEUDO_REG(a, b) b,

#include "e2k-regs.inc"

#undef E2K_PSEUDO_REG
#undef E2K_RAW_REG
};


#endif /* E2K_REGS_H  */
