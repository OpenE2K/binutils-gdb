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
#include "gdbcore.h"
#include "gdbtypes.h"
#include "gdbsupport/gdb_assert.h"
#include "target-descriptions.h"
#include "value.h"
#include "extract-store-integer.h"
#include "gdbarch.h"
#include "e2k-pm-tdep.h"

static int
e2k_pm_convert_register_p (struct gdbarch *gdbarch, int regnum, struct type *type)
{
  /* Distinguish pointers in Protected Mode from other types */
  return (type->code () == TYPE_CODE_PTR);
}


static int
e2k_pm_register_to_value (const frame_info_ptr &frame, int regnum,
                          struct type *type, gdb_byte *to,
                          int *optimizedp, int *unavailablep)
{
  frame_info_ptr next_frame = get_next_frame_sentinel_okay (frame);
  gdb_assert (type->code () == TYPE_CODE_PTR);
  get_frame_register_bytes (next_frame, regnum, 0, {to, 8},
                            optimizedp, unavailablep);
  get_frame_register_bytes (next_frame, regnum + 1, 0, {to + 8, 8},
                            optimizedp, unavailablep);

  *optimizedp = *unavailablep = 0;
  return 1;
}

static CORE_ADDR
e2k_pm_pointer_to_address (struct gdbarch *gdbarch,
                           struct type *type, const gdb_byte *buf)
{
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  const struct target_desc *tdesc
    = gdbarch_target_desc (current_inferior ()->arch ());
  CORE_ADDR ap_lo;
  CORE_ADDR base;
  unsigned int offset;

  /* This method may be called for a reference as well as for a pointer. */
  gdb_assert (type->code () == TYPE_CODE_PTR
	      || type->code () == TYPE_CODE_REF);

  if (! tdesc
      || ! tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v7.linux"))
    {
      offset = extract_unsigned_integer (buf + 8, 4, byte_order);

      ap_lo = extract_unsigned_integer (buf, 8, byte_order);
      /* TODO: external tags should be verified here too in addition to
	 internal ones.  */
      if ((ap_lo & 0xe000000000000000ULL) == 0x0ULL)
	/* This is AP.  */
	base = ap_lo & 0xffffffffffffULL;
      else if ((ap_lo & 0xe000000000000000ULL) == 0x8000000000000000ULL)
	{
	  /* This is SAP.  */
	  ULONGEST usbr;
	  struct regcache *regcache = get_thread_regcache (inferior_thread ());
	  regcache_cooked_read_unsigned (regcache, E2K_USBR_REGNUM, &usbr);
	  base = (usbr & 0xffff00000000ULL)  + (ap_lo & 0xffffffffULL);
	}
      else if (! tdesc
	       || ! tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v6.linux")
	       /* This test makes sense for elbrus-v{X>=6} only.  */
	       || (ap_lo & 0xe000000000000000ULL) == 0x2000000000000000ULL)
	{
	  /* This is PL.  */
	  return (ap_lo & 0xffffffffffffULL);
	}
      else
	{
	  /* Unrecognized.  */
	  base = 0;
	  offset = 0;
	}
    }
  else
    {
      /* elbrus-v7 is to be supported yet.  */
      ap_lo = extract_unsigned_integer (buf, 8, byte_order);
      /* On elbrus-v7 this is NOT BASE, but PTR, in fact, and it already
	 contains OFFSET.  */
      base = (ap_lo & 0xffffffffffffULL);
      offset = 0;
    }

  return base + offset;
}

/* Stupidly produce a PM-pointer from a raw address.  */
static void
e2k_pm_address_to_pointer (struct gdbarch *gdbarch,
                           struct type *type, gdb_byte *buf, CORE_ADDR addr)
{
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  const struct target_desc *tdesc
    = gdbarch_target_desc (current_inferior ()->arch ());

  /* Determine whether we are constructing AP or PL.  */
  if (type->target_type ()->code () == TYPE_CODE_FUNC)
    {
      if (! tdesc
	  || ! tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v6.linux"))
	{
	  /* FIXME: here I make use of the fact that `itagpl == 0', while the
	     contents of other fields except for TARGET and ITAG is
	     undetermined and can probably be zeroed out. However, some sort
	     of check that ADDR fits within VA_MSB bits is required.  */
	  store_unsigned_integer (buf, 8, byte_order, addr);
	  store_unsigned_integer (&buf[8], 8, byte_order, 0);
	}
      else
	{
	  store_unsigned_integer (buf, 8, byte_order,
				  addr | 0x2000000000000000ULL);
	  int i = 0;
	  if (target_has_execution)
	    {

	      struct regcache *regcache
		= get_thread_regcache (inferior_thread ());
	      ULONGEST cutd;
	      regcache_cooked_read_unsigned (regcache, E2K_CUTD_REGNUM, &cutd);
	      enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
	      int met_nonzero = 0;
	      for (i = 0; ; i++)
		{
		  ULONGEST cud_base
		    = read_memory_unsigned_integer (cutd + 32 * i,
						    6, byte_order);
		  ULONGEST cud_size
		    = read_memory_unsigned_integer (cutd + 32 * i + 12,
						    4, byte_order);
		  if (cud_base == 0)
		    {
		      if (! met_nonzero)
			continue;
		      else
			{
			  /* There's no matching I, in fact, stupidly use 0
			     in such a case.  */
			  i = 0;
			  break;
			}
		    }

		  met_nonzero = 1;
		  if (addr >= cud_base && addr < cud_base + cud_size)
		    break;
		}
	    }

	  store_unsigned_integer (&buf[8], 8, byte_order, i);
	}
    }
  else if (type->length () == 16)
    {
      if (! tdesc
	  || ! tdesc_find_feature (tdesc, "org.mcst.gdb.elbrus-v7.linux"))
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
      else
	{
	  /* TODO: elbrus-v7 is to be supported yet.  */
	  int i;
	  for (i = 0; i < 2; i++)
	    store_unsigned_integer (&buf[8 * i], 8, byte_order, 0x0);
	}
      
    }
}


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
  set_gdbarch_pointer_to_address (gdbarch, e2k_pm_pointer_to_address);
  set_gdbarch_address_to_pointer (gdbarch, e2k_pm_address_to_pointer);
}
