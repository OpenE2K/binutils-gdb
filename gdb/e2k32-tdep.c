/* Target-dependent code for E2K32.

   Copyright (C) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "defs.h"
#include "gdbcore.h"
#include "gdbtypes.h"
#include "infcall.h"
#include "value.h"
#include "gdbarch.h"
#include "e2k32-tdep.h"

void
e2k32_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  /* We should be able to transfer data from 64-bit application
     memory addresses since all these hardware stacks seem to
     lie outside of the memory area addressed by GD. */
  set_gdbarch_addr_bit (gdbarch, 64);

  /* This value is used by GDB when producing pointer-to-value
     types to determine the pointer's size. */
  set_gdbarch_ptr_bit (gdbarch, 32);
}
