/* The only macro that should be defined prior to inclusion of
   elf64-e2k.c so as to prevent it from including elf64-target.h
   before we redefine all other macros of interest.  */
#define TARGET_LITTLE_NAME		"elf64-e2k-uclibc"
#include "elf64-e2k.c"

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM		e2k_uclibc_elf64_vec

#include "elfxx-e2k-uclibc.h"

#undef bfd_elf64_bfd_merge_private_bfd_data
#define bfd_elf64_bfd_merge_private_bfd_data	\
  _bfd_e2k_uclibc_elf_merge_private_bfd_data

#include "elf64-target.h"
