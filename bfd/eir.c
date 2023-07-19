/* BFD back-end for objects containing EIR.
   Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003,
   2004, 2005, 2006, 2007 Free Software Foundation, Inc.
   Written by Ian Lance Taylor, Cygnus Support, <ian@cygnus.com>

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

#define eir_set_arch_mach _bfd_generic_set_arch_mach

static bfd_boolean
eir_set_section_contents (bfd *abfd,
                          asection *sec,
                          const void *data,
                          file_ptr offset,
                          bfd_size_type size)
{
  static file_ptr crnt_pos;
  file_ptr mask;

  if (size == 0 || (strcmp (sec->name, ".pack_pure_eir") != 0
                    && strcmp (sec->name, ".pack_mixed_eir") != 0))
    return TRUE;

  mask = (1 << sec->alignment_power) - 1;
  crnt_pos = (crnt_pos + mask) & ~mask;
  sec->filepos = crnt_pos;
  crnt_pos += size;

  return _bfd_generic_set_section_contents (abfd, sec, data, offset, size);
}

const bfd_target eir_vec =
{
  "eir",			/* name */
  bfd_target_unknown_flavour,	/* flavour */
  BFD_ENDIAN_UNKNOWN,		/* byteorder */
  BFD_ENDIAN_UNKNOWN,		/* header_byteorder */
  EXEC_P,			/* object_flags */
  (SEC_ALLOC | SEC_LOAD | SEC_READONLY | SEC_CODE | SEC_DATA
   | SEC_ROM | SEC_HAS_CONTENTS), /* section_flags */
  0,				/* symbol_leading_char */
  ' ',				/* ar_pad_char */
  16,				/* ar_max_namelen */
  255,				/* match priority.  */
  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
  bfd_getb32, bfd_getb_signed_32, bfd_putb32,
  bfd_getb16, bfd_getb_signed_16, bfd_putb16,	/* data */
  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
  bfd_getb32, bfd_getb_signed_32, bfd_putb32,
  bfd_getb16, bfd_getb_signed_16, bfd_putb16,	/* hdrs */
  {				/* bfd_check_format */
    _bfd_dummy_target,
    _bfd_dummy_target,
    _bfd_dummy_target,
    _bfd_dummy_target,
  },
  {				/* bfd_set_format */
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_true,
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_false_error,
  },
  {				/* bfd_write_contents */
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_true,
    _bfd_bool_bfd_false_error,
    _bfd_bool_bfd_false_error,
  },

  BFD_JUMP_TABLE_GENERIC (_bfd_generic),
  BFD_JUMP_TABLE_COPY (_bfd_generic),
  BFD_JUMP_TABLE_CORE (_bfd_nocore),
  BFD_JUMP_TABLE_ARCHIVE (_bfd_noarchive),
  BFD_JUMP_TABLE_SYMBOLS (_bfd_nosymbols),
  BFD_JUMP_TABLE_RELOCS (_bfd_norelocs),
  BFD_JUMP_TABLE_WRITE (eir),
  BFD_JUMP_TABLE_LINK (_bfd_nolink),
  BFD_JUMP_TABLE_DYNAMIC (_bfd_nodynamic),

  NULL,

  NULL
};
