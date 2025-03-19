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


#ifndef _ELF_E2K_H
#define _ELF_E2K_H

#include "elf/reloc-macros.h"

/* Relocation types on E2K are assigned their values according to the
   following logic:  */
START_RELOC_NUMBERS (elf_e2k_reloc_type)
  /* 32-bit ones.  */
  RELOC_NUMBER (R_E2K_32_ABS, 0)
  RELOC_NUMBER (R_E2K_32_PC, 2)

  /* A couple of bogus 32-bit relocations for Protected Mode.  */
  RELOC_NUMBER (R_E2K_AP_GOT, 3)
  RELOC_NUMBER (R_E2K_PL_GOT, 4)

  /* 32-bit ones.  */
  RELOC_NUMBER (R_E2K_32_JMP_SLOT, 8)
  RELOC_NUMBER (R_E2K_32_COPY, 9)
  RELOC_NUMBER (R_E2K_32_RELATIVE, 10)
  RELOC_NUMBER (R_E2K_32_IRELATIVE, 11)
  RELOC_NUMBER (R_E2K_32_SIZE, 12)
  RELOC_NUMBER (R_E2K_32_DYNOPT, 13)

  /* 64-bit ones.  */
  RELOC_NUMBER (R_E2K_64_ABS, 50)
  RELOC_NUMBER (R_E2K_64_ABS_LIT, 51)
  RELOC_NUMBER (R_E2K_64_PC_LIT, 54)
  RELOC_NUMBER (R_E2K_64_JMP_SLOT, 63)
  RELOC_NUMBER (R_E2K_64_COPY, 64)
  RELOC_NUMBER (R_E2K_64_RELATIVE, 65)
  RELOC_NUMBER (R_E2K_64_RELATIVE_LIT, 66)
  RELOC_NUMBER (R_E2K_64_IRELATIVE, 67)
  RELOC_NUMBER (R_E2K_64_SIZE, 68)
  RELOC_NUMBER (R_E2K_64_GOTOFF, 69)
  /* Because of the originally stupid order of assigning numbers to relocations
     we have reached the upper border for pure 64-bit ones. To avoid possible
     collisions with pure 32-bit relocations We prefer to go on with the
     increasing sequence of numbers starting from 256 rather than with the
     decreasing one starting from 49 (see MCSTBug #91797, Comment #3). Note that
     this will make it impossible to use these relocations in 32-bit mode, but
     they shouldn't be intended for that in fact . . .  */
  RELOC_NUMBER (R_E2K_64_GOTOFF_LIT, 256)
  RELOC_NUMBER (R_E2K_64_DYNOPT, 257)
  RELOC_NUMBER (R_E2K_64_PC, 258)

  /* All TLS-specific 32, 64-bit and common relocations are grouped here,
     which is rather inconsistent.  */
  RELOC_NUMBER (R_E2K_TLS_GDMOD, 70)
  RELOC_NUMBER (R_E2K_TLS_GDREL, 71)
  RELOC_NUMBER (R_E2K_TLS_IE, 74)
  RELOC_NUMBER (R_E2K_32_TLS_LE, 75)
  RELOC_NUMBER (R_E2K_64_TLS_LE, 76)
  RELOC_NUMBER (R_E2K_TLS_32_DTPMOD, 80)
  RELOC_NUMBER (R_E2K_TLS_32_DTPREL, 81)
  RELOC_NUMBER (R_E2K_TLS_64_DTPMOD, 82)
  RELOC_NUMBER (R_E2K_TLS_64_DTPREL, 83)
  RELOC_NUMBER (R_E2K_TLS_TPOFF32, 84)
  RELOC_NUMBER (R_E2K_TLS_TPOFF64, 85)


  /* These two are for protected mode dynamic linker.  */
  RELOC_NUMBER (R_E2K_AP, 100)
  RELOC_NUMBER (R_E2K_PL, 101)


  /* Common relocations for 32 and 64-bit modes.  */
  RELOC_NUMBER (R_E2K_GOT, 108)
  RELOC_NUMBER (R_E2K_GOTOFF, 109)
  RELOC_NUMBER (R_E2K_DISP, 110)
  RELOC_NUMBER (R_E2K_PREF, 111)
  RELOC_NUMBER (R_E2K_NONE, 112)
  RELOC_NUMBER (R_E2K_GOTPLT, 114)
  RELOC_NUMBER (R_E2K_ISLOCAL, 115)
  RELOC_NUMBER (R_E2K_ISLOCAL32, 118)
  RELOC_NUMBER (R_E2K_ALIGN_RELAX, 119)
  RELOC_NUMBER (R_E2K_MCSTBUG_140436_RELAX, 120)
END_RELOC_NUMBERS (R_E2K_max)

/* Processor specific flags for the ELF header e_flags field.  */

#define EF_E2K_IPD              3
#define EF_E2K_X86APP           4
#define EF_E2K_4MB_PAGES        8
#define EF_E2K_INCOMPAT         16
#define EF_E2K_PM               32
#define EF_E2K_PACK_SEGMENTS    64

/* Three bit E2K machine type field.  */

#define EF_E2K_MACH_TO_OLD_FLAG(x)      ((x) << 28)
#define EF_E2K_OLD_FLAG_TO_MACH(x)      (((x) >> 28) & 7)

/* A particular E2K machine ELF is intended for is determined by the 8
   uppermost bits of its header's e_flags containing one of
   E_E2K_MACH_* codes listed below.  */
#define EF_E2K_MACH_TO_FLAG(x)      ((x) << 24)
#define EF_E2K_FLAG_TO_MACH(x)      (((x) >> 24) & 255)

/* Codes of supported E2K machines.  */
#define E_E2K_MACH_BASE     0	/* Legacy. Shouldn't be created nowadays.  */
#define E_E2K_MACH_EV1      1	/* Legacy. Shouldn't be created nowadays.  */
#define E_E2K_MACH_EV2      2	/* -march=elbrus-v2 code.  */
#define E_E2K_MACH_EV3      3	/* -march=elbrus-v3 code.  */
#define E_E2K_MACH_EV4      4	/* -march=elbrus-v4 code.  */
#define E_E2K_MACH_EV5      5	/* -march=elbrus-v5 code.  */
#define E_E2K_MACH_EV6      6	/* -march=elbrus-v6 code.  */
#define E_E2K_MACH_EV7      7	/* -march=elbrus-v7 code.  */

/* Values 16, 17 and 18 used to be reserved for `E_E2K_MACH_CUBE_{1,2,3}'
   respectively, which have never been used in ELF files in practice. However,
   they can't be reused right now because they are recognized in all Kernel
   versions installed on many E2K hosts all over the World and at MCST.
   Otherwise, it would be possible to mistakenly execute ELFs for `elbrus-{8c,
   1c+}' at respective iterations of `elbrus-2c+'. Reuse them a few years later
   after they are eliminated from the Kernel.  */

#define E_E2K_MACH_8C	    19	/* -mtune=elbrus-8c code.  */
#define E_E2K_MACH_1CPLUS   20	/* -mtune=elbrus-1c+ code.  */
#define E_E2K_MACH_12C	    21	/* -mtune=elbrus-12c code.  */
#define E_E2K_MACH_16C	    22	/* -mtune=elbrus-16c code.  */
#define E_E2K_MACH_2C3	    23	/* -mtune=elbrus-2c3 code.  */
#define E_E2K_MACH_48C	    24  /* -mtune=elbrus-48c code.  */
#define E_E2K_MACH_8V7	    25  /* -mtune=elbrus-8v7 code.  */
#define E_E2K_MACH_MAKET32C 26  /* -mtune=elbrus-maket32c code.  */

static inline unsigned long
e2k_arch_info_mach_to_iset (unsigned long mach)
{
  mach /= 4;
  switch (mach)
    {
    case E_E2K_MACH_8C:
    case E_E2K_MACH_1CPLUS:
      return 4;
    case E_E2K_MACH_12C:
    case E_E2K_MACH_16C:
    case E_E2K_MACH_2C3:
      return 6;
    case E_E2K_MACH_48C:
    case E_E2K_MACH_8V7:
    case E_E2K_MACH_MAKET32C:
      return 7;
    default:
      return mach;
    }
}

/* E2K-specific program header types.  */
#define PT_E2K_TAG      (PT_LOPROC + 0)

enum
{
  /* Defective "prior to MCSTBug #60151" lazy binding implementation which requires
     additional fixup of all PLT entries. It's not used starting with this
     version of binutils.  */
  DT_E2K_LAZY_DEFECTIVE = DT_LOPROC,
  DT_E2K_LAZY,

  /* This dynamic tag marks objects with lazy binding implementation requiring
     no modification of the text segment at runtime.  */
  DT_E2K_LAZY_GOT = DT_LOPROC + 3,

  /* There's no standard DT-entry intended to hold the size of `.got'. This one
     is named by analogy with DT_PLTGOT holding the address of this section.
     Its value is inherited from binutils-2.18 where numerous entries used to
     be reserved for C++ hardware support.  */
  DT_PLTGOTSZ = DT_LOPROC + 0x101b,

  /* This entry is used to obtain PL of `__selfinit ()' in the containing
     dynamic object.  */
  DT_INIT_GOT,

  DT_EXPORT_PL,
  DT_EXPORT_PLSZ,

  DT_REAL_PLTGOT,
  DT_E2K_NO_SELFINIT,
};

#endif /* _ELF_E2K_H */
