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
      if (((pcolon[1] == '3' && pcolon[2] == '2' && (mode = 32))
           || (pcolon[1] == '6' && pcolon[2] == '4' && (mode = 64))
           || (pcolon[1] == 'p' && pcolon[2] == 'm' && (mode = 128)))
          && pcolon[3] == '\0')
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

  if (STRNCMP (name, "generic", len) == 0
      /* FIXME: `ARCH=e2k' is still used within the generated LD scripts for
         E2K. Changing it to "generic" would result in a reference to some dummy
         `bfd_arch_generic' which is definitely not the thing I need.  */
      || STRNCMP (name, "e2k", len) == 0)
    name = "generic";
  else if (STRNCMP (name, "elbrus-v1", len) == 0
           || STRNCMP (name, "elbrus", len) == 0)
    name = "elbrus-v1";
  else if (STRNCMP (name, "elbrus-v2", len) == 0
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
  static const int modes[] = {64, 32, 128};
  const char *canon;
  int mode;

  canon = canonicalize_arch_name (string, &mode);
  if (canon != NULL
      && mode == modes[info->mach % 3]
      && strncmp (canon, info->printable_name, strlen (canon)) == 0)
    return TRUE;

  return FALSE;
}

extern const bfd_arch_info_type bfd_e2k_arch;

static const bfd_arch_info_type *
bfd_e2k_compatible (const bfd_arch_info_type *i, const bfd_arch_info_type *o)
{
  if (i->arch != o->arch)
    return NULL;

  /* Check whether input and output BFDs have the same ABI.  */
  if (i->mach % 3 != o->mach % 3)
    return NULL;

  /* Nowadays that we should be able to dynamically choose an output
     machine without `-A' (see Bug #58358) any further checks here
     are meaningless. They are moved to `_bfd_e2k_merge_private_bfd_data'.
     Just return our "generic" arch info in order not to upset
     `lang_check ()'. It turns out that a value returned by this function
     is not actually used at all except for aforementioned formal(?) check and

     . . . GDB's `can_run_code_for ()' which expects us to return the "more
     featureful" of the two arches. For it to succeed the returned arch should
     coincide with that of the executable, which is the `I' argument of this
     function). I think that it's quite reasonable to return `I' for now, since
     its arch can't certainly turn out to be "less featureful" than the minimal
     arch of the GDB's handler, represented by `O'. But this may very well
     change once GDB for E2K gets "non-minimal" handlers!

     By the way, why don't they want to let GDB's handler have a more advanced
     arch than that of the executable? As far as I remember, this is because a
     more "featureful" handler may require registers which aren't provided by
     the executable's primitive ABI.  */

  return i;
}


#define BITS_ADDR_64    64
#define BITS_ADDR_32    32
#define BITS_ADDR_pm    32

#define MACH_64(mach) (3 * (mach))
#define MACH_32(mach) (3 * (mach) + 1)
#define MACH_pm(mach) (3 * (mach) + 2)

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
      NEXT                                                              \
  }

/* These indices are used to refer to the next arch_info entry. I_generic_64
   is not needed here since the corresponding entry is defined apart.  */
enum
  {
    I_generic_32,
    I_generic_pm,

    I_ev1_64,
    I_ev1_32,
    I_ev1_pm,

    I_ev2_64,
    I_ev2_32,
    I_ev2_pm,

    I_ev3_64,
    I_ev3_32,
    I_ev3_pm,

    I_ev4_64,
    I_ev4_32,
    I_ev4_pm,

    I_ev5_64,
    I_ev5_32,
    I_ev5_pm,

    I_ev6_64,
    I_ev6_32,
    I_ev6_pm,

    I_8c_64,
    I_8c_32,
    I_8c_pm,

    I_1cplus_64,
    I_1cplus_32,
    I_1cplus_pm,
  };

#define NN(index) (&arch_info_struct[(index) + 1])

static const bfd_arch_info_type arch_info_struct[] =
{
  /* The two remaining generic entries.  */
  N (bfd_mach_e2k_generic, 32, "generic", FALSE, NN (I_generic_32)),
  N (bfd_mach_e2k_generic, pm, "generic", FALSE, NN (I_generic_pm)),

  /* `elbrus-v1' entries.  */
  N (bfd_mach_e2k_ev1, 64, "elbrus-v1", FALSE, NN (I_ev1_64)),
  N (bfd_mach_e2k_ev1, 32, "elbrus-v1", FALSE, NN (I_ev1_32)),
  N (bfd_mach_e2k_ev1, pm, "elbrus-v1", FALSE, NN (I_ev1_pm)),

  /* `elbrus-v2' entries.  */
  N (bfd_mach_e2k_ev2, 64, "elbrus-v2", FALSE, NN (I_ev2_64)),
  N (bfd_mach_e2k_ev2, 32, "elbrus-v2", FALSE, NN (I_ev2_32)),
  N (bfd_mach_e2k_ev2, pm, "elbrus-v2", FALSE, NN (I_ev2_pm)),

  /* `elbrus-v3' entries.  */
  N (bfd_mach_e2k_ev3, 64, "elbrus-v3", FALSE, NN (I_ev3_64)),
  N (bfd_mach_e2k_ev3, 32, "elbrus-v3", FALSE, NN (I_ev3_32)),
  N (bfd_mach_e2k_ev3, pm, "elbrus-v3", FALSE, NN (I_ev3_pm)),

  /* `elbrus-v4' entries.  */
  N (bfd_mach_e2k_ev4, 64, "elbrus-v4", FALSE, NN (I_ev4_64)),
  N (bfd_mach_e2k_ev4, 32, "elbrus-v4", FALSE, NN (I_ev4_32)),
  N (bfd_mach_e2k_ev4, pm, "elbrus-v4", FALSE, NN (I_ev4_pm)),

  /* `elbrus-v5' entries.  */
  N (bfd_mach_e2k_ev5, 64, "elbrus-v5", FALSE, NN (I_ev5_64)),
  N (bfd_mach_e2k_ev5, 32, "elbrus-v5", FALSE, NN (I_ev5_32)),
  N (bfd_mach_e2k_ev5, pm, "elbrus-v5", FALSE, NN (I_ev5_pm)),

  /* `elbrus-v6' entries.  */
  N (bfd_mach_e2k_ev6, 64, "elbrus-v6", FALSE, NN (I_ev6_64)),
  N (bfd_mach_e2k_ev6, 32, "elbrus-v6", FALSE, NN (I_ev6_32)),
  N (bfd_mach_e2k_ev6, pm, "elbrus-v6", FALSE, NN (I_ev6_pm)),

  /* Entries, describing the specific `elbrus-8c' processor also known as
     Processor-1 (elbrus-v4).  */
  N (bfd_mach_e2k_8c, 64, "elbrus-8c", FALSE, NN (I_8c_64)),
  N (bfd_mach_e2k_8c, 32, "elbrus-8c", FALSE, NN (I_8c_32)),
  N (bfd_mach_e2k_8c, pm, "elbrus-8c", FALSE, NN (I_8c_pm)),

  /* Entries, describing the specific `elbrus-1c+' processor also known as
     Processor-2 (elbrus-v4).  */
  N (bfd_mach_e2k_1cplus, 64, "elbrus-1c+", FALSE, NN (I_1cplus_64)),
  N (bfd_mach_e2k_1cplus, 32, "elbrus-1c+", FALSE, NN (I_1cplus_32)),
  N (bfd_mach_e2k_1cplus, pm, "elbrus-1c+", FALSE, NULL)
};

/* I don't remember for sure what DEFAULT actually means here. We should
   probably only one default arch, however. Let it be a 64-bit elbrus
   generic arch.  */
const bfd_arch_info_type bfd_e2k_arch =
  N (bfd_mach_e2k_generic, 64, "generic", TRUE, &arch_info_struct[0]);
