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

#ifndef ELFCPP_E2K_H
#define ELFCPP_E2K_H

namespace elfcpp
{

enum
{
  R_E2K_32_ABS = 0,
  R_E2K_32_PC = 2,
  R_E2K_AP_GOT = 3,
  R_E2K_PL_GOT = 4,
  R_E2K_32_JMP_SLOT = 8,
  R_E2K_32_RELATIVE = 10,
  R_E2K_64_ABS = 50,
  R_E2K_64_ABS_LIT = 51,
  R_E2K_64_PC_LIT = 54,
  R_E2K_64_JMP_SLOT = 63,
  R_E2K_64_RELATIVE = 65,
  R_E2K_64_RELATIVE_LIT = 66,
  R_E2K_64_GOTOFF = 69,
  R_E2K_TLS_GDMOD = 70,
  R_E2K_TLS_GDREL = 71,
  R_E2K_TLS_IE = 74,
  R_E2K_32_TLS_LE = 75,
  R_E2K_64_TLS_LE = 76,
  R_E2K_TLS_32_DTPMOD = 80,
  R_E2K_TLS_32_DTPREL = 81,
  R_E2K_TLS_64_DTPMOD = 82,
  R_E2K_TLS_64_DTPREL = 83,
  R_E2K_TLS_TPOFF32 = 84,
  R_E2K_TLS_TPOFF64 = 85,
  R_E2K_AP = 100,
  R_E2K_PL = 101,
  R_E2K_GOT = 108,
  R_E2K_GOTOFF = 109,
  R_E2K_DISP = 110,
  R_E2K_GOTPLT = 114,
  R_E2K_ISLOCAL = 115,
  R_E2K_ISLOCAL32 = 118,
  R_E2K_64_GOTOFF_LIT = 256,
};

// e_flags values defined for e2k
enum
{
  EF_E2K_PM = 0x20,	// Protected Mode
};

} // End namespace elfcpp.

#endif // !defined(ELFCPP_E2K_H)
