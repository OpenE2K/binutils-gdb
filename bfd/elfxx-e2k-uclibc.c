#include "sysdep.h"
#include "bfd.h"
#include "elf-bfd.h"
#include "elfxx-e2k.h"
#include "elfxx-e2k-uclibc.h"

bfd_boolean
_bfd_e2k_uclibc_elf_merge_private_bfd_data (bfd *ibfd,
					    struct bfd_link_info *info)
{
  return _bfd_e2k_elf_merge_private_bfd_data_1 (ibfd, info->output_bfd, TRUE);
}
