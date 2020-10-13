// e2k.h -- ELF definitions specific to EM_MCST_ELBRUS  -*- C++ -*-

// Copyright (C) 2008-2015 Free Software Foundation, Inc.
// Written by Ilya Yu. Malakhov <malakhov@mcst.ru>.

// This file is part of elfcpp.
   
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public License
// as published by the Free Software Foundation; either version 2, or
// (at your option) any later version.

// In addition to the permissions in the GNU Library General Public
// License, the Free Software Foundation gives you unlimited
// permission to link the compiled version of this file into
// combinations with other programs, and to distribute those
// combinations without any restriction coming from the use of this
// file.  (The Library Public License restrictions do apply in other
// respects; for example, they cover modification of the file, and
/// distribution when not linked into a combined executable.)

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.

// You should have received a copy of the GNU Library General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
// 02110-1301, USA.

#ifndef ELFCPP_E2K_H
#define ELFCPP_E2K_H

namespace elfcpp
{

enum
{
  R_E2K_32_ABS = 0,
  R_E2K_32_PC = 2,
  R_E2K_64_ABS = 50,
  R_E2K_64_ABS_LIT = 51,
  R_E2K_64_PC_LIT = 54,
  R_E2K_TLS_IE = 74,
  R_E2K_64_TLS_LE = 76,
  R_E2K_GOT = 108,
  R_E2K_GOTOFF = 109,
  R_E2K_DISP = 110,
  R_E2K_GOTPLT = 114,
  R_E2K_ISLOCAL = 115,
  R_E2K_ISLOCAL32 = 118,
};

} // End namespace elfcpp.

#endif // !defined(ELFCPP_E2K_H)
