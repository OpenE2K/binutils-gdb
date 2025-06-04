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
