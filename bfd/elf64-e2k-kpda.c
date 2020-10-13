/* Signalize that elf64-e2k.c shouldn't set up bfd target vector for us.
   We'll do it ourselves after redefining a few macros.  */
#define TARGET_KPDA
#include "elf64-e2k.c"
#undef TARGET_KPDA

#if 0
static void
_bfd_e2k_kpda_elf64_post_process_headers (bfd *abfd,
                                          struct bfd_link_info *link_info)
{
  Elf_Internal_Ehdr *i_ehdrp;

  i_ehdrp = elf_elfheader (abfd);
  i_ehdrp->e_ident[EI_OSABI] = ELFOSABI_KPDA;

  _bfd_elf_post_process_headers (abfd, link_info);
}

#undef elf_backend_post_process_headers
#define elf_backend_post_process_headers        _bfd_e2k_kpda_elf64_post_process_headers

#endif /* 0  */

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM       e2k_kpda_elf64_vec

#undef TARGET_LITTLE_NAME
#define TARGET_LITTLE_NAME      "elf64-e2k-kpda"

#define ELF_OSABI               ELFOSABI_KPDA

/* Now set up the target vector.  */
#include "elf64-target.h"
