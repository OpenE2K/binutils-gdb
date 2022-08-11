/* BFD support for the E2K architecture.
   Copyright 1992, 1995, 1996, 1998, 2000, 2002, 2005, 2007
   Free Software Foundation, Inc.

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

struct archname_item
{
  const char *str;
  size_t len;
};

static const char *
canonicalize_arch_name (const char *name, int *pmode)
{
  int mode;
  size_t len;
  const char *pcolon = strchr (name, ':');

  if (pcolon != NULL)
    {
      if ((((pcolon[1] == '3' && pcolon[2] == '2' && (mode = 32))
	    || (pcolon[1] == '6' && pcolon[2] == '4' && (mode = 64))
	    || (pcolon[1] == 'p' && pcolon[2] == 'm' && (mode = 128)))
	   && pcolon[3] == '\0')
	  || (pcolon[1] == 'a' && pcolon[2] == 'n' && pcolon[3] == 'y'
	      && pcolon[4] == '\0' && (mode = 256)))
        len = pcolon - name;
      else
        return NULL;
    }
  else
    {
      mode = 64;
      len = strlen (name);
    }


#define STRNCMP(s1, s2, n) \
  ((n == sizeof (s2) - 1 &&  strncmp (s1, s2, n) == 0) ? 0 : 1)

  if (STRNCMP (name, "e2k", len) == 0
      || STRNCMP (name, "elbrus-v2", len) == 0
      || STRNCMP (name, "elbrus-2c+", len) == 0
      || STRNCMP (name, "elbrus-2cm", len) == 0)
    name = "elbrus-v2";
  else if (STRNCMP (name, "elbrus-v3", len) == 0
           || STRNCMP (name, "elbrus-4c", len) == 0)
    name = "elbrus-v3";
  else if (STRNCMP (name, "elbrus-v4", len) == 0)
    name = "elbrus-v4";    
  else if (STRNCMP (name, "elbrus-8c", len) == 0)
    name = "elbrus-8c";
  else if  (STRNCMP (name, "elbrus-1c+", len) == 0)
    name = "elbrus-1c+";
  else if (STRNCMP (name, "elbrus-v5", len) == 0
           || STRNCMP (name, "elbrus-8c2", len) == 0)
    name = "elbrus-v5";
  else if (STRNCMP (name, "elbrus-v6", len) == 0)
    name = "elbrus-v6";
  else
    return NULL;

#undef STRNCMP

  *pmode = mode;
  return name;
}

static bfd_boolean
e2k_scan (const struct bfd_arch_info *info, const char *string)
{
  static const int modes[] = {64, 32, 128, 256};
  const char *canon;
  int mode;

  canon = canonicalize_arch_name (string, &mode);
  if (canon != NULL
      && mode == modes[info->mach % 4]
      && strncmp (canon, info->printable_name, strlen (canon)) == 0)
    return TRUE;

  return FALSE;
}

extern const bfd_arch_info_type bfd_e2k_arch;

static const bfd_arch_info_type *
bfd_e2k_compatible (const bfd_arch_info_type *i, const bfd_arch_info_type *o)
{
  /* FIXME: while reworking this function to make it return the "least common
     denominator" of I and O a limited amount of code was copy/pasted from
     `_bfd_e2k_elf_merge_private_bfd_data_1 ()'. Moreover, it was simplified
     so as not to take EF_E2K_INCOMPAT case into account. The latter means
     that GDB won't emit a warning (not an error?) on an attempt to execute a
     forward-incompatible ELF for elbrus-vX on elbrus-v{Y > X} at it'll be the
     Kernel that will prevent this. To make such a control possible here info
     on the presence of EF_E2K_INCOMPAT should probably be encoded in `bfd_arch
     _info_type.mach' along with 32-, 64-bit or PM ABIs. Once this is done, it
     should be possible to delegate similar activities from `_bfd_e2k_elf_merge
     _private_bfd_data_1 ()' to this function.  */
  enum
  {
    ev1,
    ev2,
    ev3,
    e8c,
    e1cplus,
    ev5,
    e12c,
    e16c,
    e2c3,
    /* The related bit in mask stands for "all future processor models".  */
    ev7
  };

#define AT(p) (1L << p)
#define AT_ev6 (AT (e12c) | AT (e16c) | AT (e2c3))


  /* A reduced version of mask[] from `_bfd_e2k_elf_merge_private_bfd_data_1 ()'
     without an "incompatible" column.  */
  static const unsigned long mask[] =
    {
     [bfd_mach_e2k_generic] =   (AT (ev1) | AT (ev2) | AT (ev3) | AT (e8c)
				 | AT (e1cplus) | AT (ev5) | AT_ev6
				 | AT (ev7)),

     [bfd_mach_e2k_ev1] =       AT (ev1),

     [bfd_mach_e2k_ev2] =       (AT (ev2) | AT (ev3) | AT (e8c) | AT (e1cplus)
				 | AT (ev5) | AT_ev6 | AT (ev7)),

     [bfd_mach_e2k_ev3] =       (AT (ev3) | AT (e8c) | AT (e1cplus) | AT (ev5)
				 | AT_ev6 | AT (ev7)),

     [bfd_mach_e2k_ev4] =       (AT (e8c) | AT (e1cplus) | AT (ev5) | AT_ev6
				 | AT (ev7)),

     [bfd_mach_e2k_ev5] =       (AT (ev5) | AT_ev6 | AT (ev7)),

     [bfd_mach_e2k_ev6] =       (AT_ev6 | AT (ev7)),

     [bfd_mach_e2k_8c] =	AT (e8c),

     [bfd_mach_e2k_1cplus] =	AT (e1cplus),

     [bfd_mach_e2k_12c] =	AT (e12c),

     [bfd_mach_e2k_16c] =	AT (e16c),

     [bfd_mach_e2k_2c3] =	AT (e2c3),
    };

  unsigned long imach, omach, remind;
  unsigned int j;


  if (i->arch != o->arch)
    return NULL;

  imach = i->mach;
  omach = o->mach;

  /* Check whether input and output BFDs have the same ABI. 3 stands for
     "any ABI will do" and is currently used when assigning bfd_arch_info
     to TARGET_DESC in gdb as there is probably no way to determine which
     mode the inferior is started in.  */
  if (imach % 4 != 3 && omach % 4 != 3 && imach % 4 != omach % 4)
    return NULL;

  remind = (imach % 4 != 3) ? imach % 4 : omach % 4;

  imach /= 4;
  omach /= 4;

  imach = mask[imach];
  omach = mask[omach];

  omach = omach & imach;
  if (omach != 0)
    {
      for (j = 0; j < sizeof (mask) / sizeof (mask[0]); j++)
	{
	  if (omach == mask[j])
	    return bfd_lookup_arch (o->arch, 4 * j + remind);
	}
    }

  return NULL;
}


#define BITS_ADDR_64    64
#define BITS_ADDR_32    32
#define BITS_ADDR_pm    32
/* This is a formal definition as we are unaware of "BITS_ADDR" when "any"
   bfd_arch_info_type is used.  */
#define BITS_ADDR_any	64

#define MACH_64(mach) (4 * (mach))
#define MACH_32(mach) (4 * (mach) + 1)
#define MACH_pm(mach) (4 * (mach) + 2)
#define MACH_any(mach) (4 * (mach) + 3)

#define PRINT_PREFIX_64         "64-bit ABI for "
#define PRINT_PREFIX_32         "32-bit ABI for "
#define PRINT_PREFIX_PM         "Protected ABI for "



#define N(ARCH, MODE, PRINT, DEFAULT, NEXT)                             \
  {                                                                     \
    /* We believe that E2k has 32 bits in a word for all architectures  \
       in all supported ABIs. I wonder whether it's actually so from    \
       the point of view of binutils.  */                               \
    32,                                                                 \
      /* Number of bits in an address  */                               \
      BITS_ADDR_##MODE,                                                 \
      /* We have 8 bits in a byte everywhere.  */                       \
      8,                                                                \
      bfd_arch_e2k,                                                     \
      /* Get an actual machine number used inside binutils while        \
         performing further checks.  */                                 \
      MACH_##MODE (ARCH),                                               \
      "e2k",                                                            \
      PRINT ":" #MODE,                                                  \
      /* Section alignment power. This should probably be               \
         revisited.  */                                                 \
      4,                                                                \
      DEFAULT,                                                          \
      bfd_e2k_compatible,                                               \
      e2k_scan,                                                         \
      bfd_arch_default_fill,                                            \
      NEXT,								\
      0 /* Maximum offset of a reloc from the start of an insn.  */	\
  }

/* These indices are used to refer to the next arch_info entry. I_generic_64
   is not needed here since the corresponding entry is defined apart.  */
enum
  {
    I_generic_64 = -1,
    I_generic_32,
    I_generic_pm,
    I_generic_any,

    I_ev1_64,
    I_ev1_32,
    I_ev1_pm,
    I_ev1_any,

    I_ev2_64,
    I_ev2_32,
    I_ev2_pm,
    I_ev2_any,

    I_ev3_64,
    I_ev3_32,
    I_ev3_pm,
    I_ev3_any,

    I_ev4_64,
    I_ev4_32,
    I_ev4_pm,
    I_ev4_any,

    I_ev5_64,
    I_ev5_32,
    I_ev5_pm,
    I_ev5_any,

    I_ev6_64,
    I_ev6_32,
    I_ev6_pm,
    I_ev6_any,

    I_8c_64,
    I_8c_32,
    I_8c_pm,
    I_8c_any,

    I_1cplus_64,
    I_1cplus_32,
    I_1cplus_pm,
    I_1cplus_any,

    I_12c_64,
    I_12c_32,
    I_12c_pm,
    I_12c_any,

    I_16c_64,
    I_16c_32,
    I_16c_pm,
    I_16c_any,

    I_2c3_64,
    I_2c3_32,
    I_2c3_pm,
    I_2c3_any
  };

#define NN(index) (&arch_info_struct[(index) + 1])

#define FIRST_TRIP(mach, name)						\
  N (bfd_mach_e2k_##mach, 32, name, FALSE, NN (I_##mach##_32)),		\
  N (bfd_mach_e2k_##mach, pm, name, FALSE, NN (I_##mach##_pm)),		\
  N (bfd_mach_e2k_##mach, any, name, FALSE, NN (I_##mach##_any))

#define TRIP(mach, name)						\
  N (bfd_mach_e2k_##mach, 64, name, FALSE, NN (I_##mach##_64)),		\
  N (bfd_mach_e2k_##mach, 32, name, FALSE, NN (I_##mach##_32)),		\
  N (bfd_mach_e2k_##mach, pm, name, FALSE, NN (I_##mach##_pm))

#define QUAD(mach, name)						\
  TRIP (mach, name),							\
  N (bfd_mach_e2k_##mach, any, name, FALSE, NN (I_##mach##_any))

#define LAST_QUAD(mach, name)						\
  TRIP (mach, name),							\
  N (bfd_mach_e2k_##mach, any, name, FALSE, NULL)
    

    

const bfd_arch_info_type arch_info_struct[] =
{
  /* The two remaining generic entries.  */
  FIRST_TRIP (generic, "generic"),

  /* `elbrus-v1' entries.  */
  QUAD (ev1, "elbrus-v1"),
 
  /* `elbrus-v2' entries.  */
  QUAD (ev2, "elbrus-v2"),

  /* `elbrus-v3' entries.  */
  QUAD (ev3, "elbrus-v3"),

  /* `elbrus-v4' entries.  */
  QUAD (ev4, "elbrus-v4"),

  /* `elbrus-v5' entries.  */
  QUAD (ev5, "elbrus-v5"),

  /* `elbrus-v6' entries.  */
  QUAD (ev6, "elbrus-v6"),

  /* Entries, describing the specific `elbrus-8c' processor also known as
     Processor-1 (elbrus-v4).  */
  QUAD (8c, "elbrus-8c"),

  /* Entries, describing the specific `elbrus-1c+' processor also known as
     Processor-2 (elbrus-v4).  */
  QUAD (1cplus, "elbrus-1c+"),

  /* Entries, describing the specific `elbrus-12c' processor of elbrus-v6
     series.  */
  QUAD (12c, "elbrus-12c"),

  /* Entries, describing the specific `elbrus-16c' processor of elbrus-v6
     series.  */
  QUAD (16c, "elbrus-16c"),

  /* Entries, describing the specific `elbrus-2c3' processor of elbrus-v6
     series.  */
  LAST_QUAD (2c3, "elbrus-2c3")
};

/* I don't remember for sure what DEFAULT actually means here. We should
   probably only one default arch, however. Let it be a 64-bit elbrus
   generic arch.  */
const bfd_arch_info_type bfd_e2k_arch =
  N (bfd_mach_e2k_generic, 64, "generic", TRUE, NN (I_generic_64));
