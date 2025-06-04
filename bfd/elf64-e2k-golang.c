/* E2K-specific support for ELF

   Copyright (c) 2009-2025 AO MCST.
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

/* The only macro that should be defined prior to inclusion of
   elf64-e2k.c so as to prevent it from including elf64-target.h
   before we redefine all other macros of interest.  */
#define TARGET_LITTLE_NAME		"elf64-e2k-golang"
#include "elf64-e2k.c"

static bool
_bfd_e2k_golang_elf_object_p (bfd *abfd)
{
  Elf_Internal_Ehdr *i_ehdrp = elf_elfheader (abfd);

  /* Does this ELF actually implement GOLANG ABI?  */
  if ((i_ehdrp->e_flags & EF_E2K_GOLANG) == 0)
    return false;

  /* GOLANG for e2k may currently produce only 64-bit forward-compatible
     elbrus-v2 ELFs.  */
  if (EF_E2K_FLAG_TO_MACH (i_ehdrp->e_flags) != E_E2K_MACH_EV2
      || (i_ehdrp->e_flags & EF_E2K_INCOMPAT) != 0)
    return false;

  return bfd_default_set_arch_mach (abfd, bfd_arch_e2k_golang,
				    4 * bfd_mach_e2k_ev2);
}


#undef elf_backend_object_p
#define elf_backend_object_p		_bfd_e2k_golang_elf_object_p

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM		e2k_golang_elf64_vec

#undef ELF_ARCH
#define ELF_ARCH			bfd_arch_e2k_golang


#include "elf64-target.h"
