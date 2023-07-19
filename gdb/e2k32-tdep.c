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

#if ! defined NEW_E2K_CALLS

static void
adjust_call_target (struct e2k_call_thread_fsm *sm)
{
  gdb_byte buf[4];
  struct regcache *regcache = get_current_regcache ();
  struct gdbarch *gdbarch = get_regcache_arch (regcache);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);

  store_signed_integer (buf, 4, byte_order, sm->funaddr);
  write_memory (sm->bp - 32 + 12, buf, 4);
}


static e2k_instr call_target = {
  32,
  &adjust_call_target,
  {
    /* 0000<000000000000> HS    */ 0x04000011, /* :  */
    /*                    ALS0  */ 0x63f0d8d1,  /* getpl,0 _f32s,_lts0 0x76543210, %ctpr1  */
    /*                    LTS1  */ 0x00000000,
    /*                    LTS0  */ 0x76543210,
    /* 0000<000000000010> HS    */ 0x00009012, /* :  */
    /*                    SS    */ 0x80000420, /*  ipd 2  */
    /*                    CS1   */ 0x50000001, /*  call %ctpr1, wbs = 0x1  */
    /*                    LTS0  */ 0x00000000,
  }
};

static e2k_instr prepare_dbl_slot = {
  16,
  &adjust_prepare_dbl_slot,
  {
    /* 0000<000000000000> HS    */ 0x10400011, /* :  */
    /*                    ALS2  */ 0x2780d8e0, /*  stgdd,2 %dg0, [ %r0 + _f32s,_lts0 0x12345678 ]  */
    /*                    LTS1  */ 0x00000000,
    /*                    LTS0  */ 0x12345678,
  }
};

static e2k_instr prepare_quad_slot = {
  16,
  &adjust_prepare_dbl_slot,
  {
    /* 0002<0000000000a8> HS    */ 0x92400012, /* :  */
    /*                    ALS2  */ 0x3980d8e0, /*  stgdq,2 %qg0, [ %r0 + _f32s,_lts0 0x12345678 ]  */
    /*                    ALS5  */ 0x3980d8e1,
    /*                    LTS0  */ 0x12345678,
  }
};

#else /* defined NEW_E2K_CALLS  */




#endif /* defined NEW_E2K_CALLS  */


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
