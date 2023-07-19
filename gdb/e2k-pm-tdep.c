/* Target-dependent code for E2K Protected Mode.

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
#include "frame.h"
#include "gdbtypes.h"
#include "gdbsupport/gdb_assert.h"
#include "value.h"
#include "gdbarch.h"
#include "e2k-pm-tdep.h"

static int
e2k_pm_convert_register_p (struct gdbarch *gdbarch, int regnum, struct type *type)
{
  /* Distinguish pointers in Protected Mode from other types */
  return (TYPE_CODE (type) == TYPE_CODE_PTR);
}


static int
e2k_pm_register_to_value (struct frame_info *frame, int regnum,
                          struct type *type, gdb_byte *to,
                          int *optimizedp, int *unavailablep)
{
  gdb_assert (TYPE_CODE (type) == TYPE_CODE_PTR);
  get_frame_register_bytes (frame, regnum, 0, 8, to,
                            optimizedp, unavailablep);
  get_frame_register_bytes (frame, regnum + 1, 0, 8, to + 8,
                            optimizedp, unavailablep);

  *optimizedp = *unavailablep = 0;
  return 1;
}

static void
e2k_pm_value_to_register (struct frame_info *frame,
			 int regnum,
			 struct type *type,
			 const gdb_byte *from)
{
  gdb_assert (TYPE_CODE (type) == TYPE_CODE_PTR);
  put_frame_register_bytes (frame, regnum, 0, 8, from);
  put_frame_register_bytes (frame, regnum + 1, 8, 8, from + 8);
}

static CORE_ADDR
e2k_pm_pointer_to_address (struct gdbarch *gdbarch,
                           struct type *type, const gdb_byte *buf)
{
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  CORE_ADDR ap_lo;
  CORE_ADDR base;
  unsigned int offset;

  /* This method may be called for a reference as well as for a pointer. */
  gdb_assert (TYPE_CODE (type) == TYPE_CODE_PTR
	      || TYPE_CODE (type) == TYPE_CODE_REF);

  offset = extract_unsigned_integer (buf + 8, 4, byte_order);

  ap_lo = extract_unsigned_integer (buf, 8, byte_order);
  /* TODO: external tags should be verified here too in addition to internal
     ones.  */
  if ((ap_lo & 0xe000000000000000ULL) == 0x0ULL)
    /* This is AP.  */
    base = ap_lo & 0xffffffffffffULL;
  else
    {
      /* This is SAP.  */
      ULONGEST usbr;
      struct regcache *regcache = get_current_regcache ();
      regcache_cooked_read_unsigned (regcache, E2K_USBR_REGNUM, &usbr);
      base = (usbr & 0xffff00000000ULL)  + (ap_lo & 0xffffffffULL);
    }

  return base + offset;
}

/* Stupidly produce a PM-pointer from a raw address.  */
static void
e2k_pm_address_to_pointer (struct gdbarch *gdbarch,
                           struct type *type, gdb_byte *buf, CORE_ADDR addr)
{
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);

  /* Determine whether we are constructing AP or PL.  */
  if (TYPE_CODE (TYPE_TARGET_TYPE (type)) == TYPE_CODE_FUNC)
    {
      /* FIXME: here I make use of the fact that `itagpl == 0', while the
         contents of other fields except for TARGET and ITAG is undetermined
         and can be probably zeroed out. However, some sort of check that ADDR
         fits within VA_MSB bits is required.  */
      store_unsigned_integer (buf, 8, byte_order, addr);
      store_unsigned_integer (&buf[8], 8, byte_order, 0);
    }
  else if (TYPE_LENGTH (type) == 16)
    {
      /* Base.  */
      store_unsigned_integer (buf, 6, byte_order, addr);
      /* RW & itag == itagap == 0  */
      store_unsigned_integer (&buf[6], 2, byte_order, 0x1800);
      /* CURPTR.  */
      store_unsigned_integer (&buf[8], 4, byte_order, 0x0);
      /* SIZE.  */
      store_unsigned_integer (&buf[12], 4, byte_order,
                              (CORE_ADDR) 0x100000000ULL - addr);
    }
}


#if ! defined NEW_E2K_CALLS

static e2k_instr pm_inner_prologue = {
  24,
  &adjust_inner_prologue,
  {
    /* 0000<000000000000> HS    */ 0x0c008023, /* g:  */
    /*                    ALS0  */ 0x62ecd980, /*  getsap,0 _f32s,_lts1 0xdeadbeef, %qr0  */
    /*                    ALS1  */ 0x62ecd981,
    /*                    CS1   */ 0x040000c0, /*  setwd wsz = 0x4, nfx = 0x1  */
    /*                                             setbn rsz = 0x3, rbs = 0x0, rcur = 0x0  */
    /*                    LTS1  */ 0xdeadbeef,
    /*                    LTS0  */ 0x00000090,
  }
};

static void
adjust_call_target (struct e2k_call_thread_fsm *sm)
{
  struct regcache *regcache = get_current_regcache ();
  struct gdbarch *gdbarch = get_regcache_arch (regcache);

  struct internalvar *g0;
  struct value *val;
  /* In protected mode hack %g0 instead of hacking code.  */
  g0 = create_ivar_from_reg (gdbarch, regcache, VG0_REGNUM);

  /* Note, that funaddr should fit into 48 bits. Do we need to guarantee
     this explicitly? ITAGPL for Procedure Label seems to be zero, so
     it's not set here explicitly.  */
  set_ivar_field (g0, "dword", sm->funaddr);
  set_ivar_field (g0, "tag0", 2);
  set_ivar_field (g0, "tag1", 2);

  val = value_of_internalvar (gdbarch, g0);
  regcache_cooked_write (regcache, VG0_REGNUM, value_contents (val));

  free_ivar (g0);
}

static e2k_instr call_target = {
  24,
  &adjust_call_target,
  {
    /* 0000<000000000000> HS    */ 0x04000001, /* :  */
    /*                    ALS0  */ 0x61c0e0d1,  /* movtd,0 %dg0, %ctpr1  */
    /* 0001<000000000008> HS    */ 0x00009012, /* :  */
    /*                    SS    */ 0x80000420, /*  ipd 2  */
    /*                    CS1   */ 0x50000000, /*  call %ctpr1, wbs = 0x0  */
    /*                    LTS0  */ 0x00000000,
  }
};


static e2k_instr prepare_dbl_slot = {
  16,
  &adjust_prepare_dbl_slot,
  {
  /* 0000<000000000000> HS    */ 0x10400011, /* :  */
  /*                    ALS2  */ 0x2b80d8e0, /*  stapd,2 %dg0, [ %qr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x12345678,
  }
};

static e2k_instr prepare_quad_slot = {
  16,
  &adjust_prepare_dbl_slot,
  {
  /* 0000<000000000000> HS    */ 0x92400012, /* :  */
  /*                    ALS2  */ 0x3a80d8e0, /*  stapq,2 %qg0, [ %qr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    ALS5  */ 0x3a80d8e1,
  /*                    LTS0  */ 0x12345678,
  }
};

#else /* defined NEW_E2K_CALLS  */





#endif /* defined NEW_E2K_CALLS  */

void
e2k_pm_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  /* Let gdb output 8 rather than 4 for things like `p sizeof (5L)' or
     `p sizeof (long) (Bug #121014). Note that this has never been a problem
     for `p sizeof (var)' of type described in DWARF sections. */
  set_gdbarch_long_bit (gdbarch, 64);

  /* We should be able to transfer data from 64-bit application
     memory addresses since all these hardware stacks seem to
     lie outside of the memory area addressed by GD. */
  set_gdbarch_addr_bit (gdbarch, 64);

  /* This value is used by GDB when producing pointer-to-value
     types to determine the pointer's size. */
  set_gdbarch_ptr_bit (gdbarch, 128);

  /* Are we sure to override e2k_convert_register_p ? */
  set_gdbarch_convert_register_p (gdbarch, e2k_pm_convert_register_p);
  set_gdbarch_register_to_value (gdbarch, e2k_pm_register_to_value);
  set_gdbarch_value_to_register (gdbarch, e2k_pm_value_to_register);
  set_gdbarch_pointer_to_address (gdbarch, e2k_pm_pointer_to_address);
  set_gdbarch_address_to_pointer (gdbarch, e2k_pm_address_to_pointer);
}
