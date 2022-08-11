/* The only macro that should be defined prior to inclusion of
   elf32-e2k.c so as to prevent it from including elf32-target.h
   before we redefine all other macros of interest.  */
#define TARGET_LITTLE_NAME		"elf32-e2k-pm"
#include "elf32-e2k.c"

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM		e2k_pm_elf32_vec

#include "elfxx-e2k-pm.h"

#include "elf32-target.h"
