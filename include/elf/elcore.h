/* This file holds definitions specific to the ELCORE ELF */

#ifndef _ELF_ELCORE_H
#define _ELF_ELCORE_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_elcore_reloc_type)
  RELOC_NUMBER (R_ELCORE_NONE, 200)
  RELOC_NUMBER (R_ELCORE_I5, 201)
  RELOC_NUMBER (R_ELCORE_I16, 202)
  RELOC_NUMBER (R_ELCORE_I16PC, 203)
  RELOC_NUMBER (R_ELCORE_S16, 204)
  RELOC_NUMBER (R_ELCORE_S16PC, 205)
  RELOC_NUMBER (R_ELCORE_I32, 206)
  RELOC_NUMBER (R_ELCORE_I5_FAKE, 207)
  RELOC_NUMBER (R_ELCORE_I16_FAKE, 208)
  RELOC_NUMBER (R_ELCORE_I16PC_FAKE, 209)
  RELOC_NUMBER (R_ELCORE_S16_FAKE, 210)
  RELOC_NUMBER (R_ELCORE_S16PC_FAKE, 211)
  RELOC_NUMBER (R_ELCORE_I32_FAKE, 212)
END_RELOC_NUMBERS (R_ELCORE_max)

/* Processor specific flags for the ELF header e_flags field.  */

/* Four bit ... machine type field.  */

/* Various CPU types.  */

/* Leave bits 0xf0 alone in case we ever have more than 16 cpu types.
   Highly unlikely, but what the heck.  */

/* File contains position independent code.  */

#define SHN_DSP_COMMON_00      SHN_LORESERVE
#define SHN_DSP_COMMON_01      (SHN_LORESERVE + 1)
#define SHN_DSP_COMMON_02      (SHN_LORESERVE + 2)
#define SHN_DSP_COMMON_03      (SHN_LORESERVE + 3)
#define SHN_DSP_COMMON_04      (SHN_LORESERVE + 4)
#define SHN_DSP_COMMON_05      (SHN_LORESERVE + 5)
#define SHN_DSP_COMMON_06      (SHN_LORESERVE + 6)
#define SHN_DSP_COMMON_07      (SHN_LORESERVE + 7)
#define SHN_DSP_COMMON_08      (SHN_LORESERVE + 8)
#define SHN_DSP_COMMON_09      (SHN_LORESERVE + 9)
#define SHN_DSP_COMMON_10      (SHN_LORESERVE + 10)
#define SHN_DSP_COMMON_11      (SHN_LORESERVE + 11)
#define SHN_DSP_COMMON_12      (SHN_LORESERVE + 12)
#define SHN_DSP_COMMON_13      (SHN_LORESERVE + 13)
#define SHN_DSP_COMMON_14      (SHN_LORESERVE + 14)
#define SHN_DSP_COMMON_15      (SHN_LORESERVE + 15)

#endif /* _ELF_ELCORE_H */
