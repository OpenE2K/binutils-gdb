/* Target-dependent code for GNU/Linux E2K32.

   Copyright (C) 2003, 2004, 2005, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "defs.h"
#include "osabi.h"
#include "solib-svr4.h"
#include "symtab.h"
#include "gdbarch.h"
#include "e2k32-tdep.h"
#include "linux-tdep.h"

static void
e2k32_linux_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  linux_init_abi (info, gdbarch);
  e2k32_init_abi (info, gdbarch);

  /* GNU/Linux has SVR4-style shared libraries...  */
  set_gdbarch_skip_trampoline_code (gdbarch, find_solib_trampoline_target);
  set_solib_svr4_fetch_link_map_offsets
    (gdbarch, svr4_ilp32_fetch_link_map_offsets);

  /* Enable TLS support.  */
  set_gdbarch_fetch_tls_load_module_address (gdbarch,
                                             svr4_fetch_objfile_link_map);


  set_gdbarch_iterate_over_regset_sections
    (gdbarch, e2k_linux_iterate_over_regset_sections);

  set_gdbarch_handle_segmentation_fault (gdbarch,
                                         e2k_linux_handle_segmentation_fault);

#if 0
  /* ...which means that we need some special handling when doing
     prologue analysis.  */
  tdep->plt_entry_size = 64;
#endif /* 0 */

  set_gdbarch_gcore_bfd_target (gdbarch, "elf64-e2k");
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
extern void _initialize_e2k32_linux_tdep (void);

void
_initialize_e2k32_linux_tdep (void)
{
  gdbarch_register_osabi (bfd_arch_e2k,
			  /* The use of generic below ensures that
			     `GDBARCH_INFO.bfd_arch_info' whatever it's set to
			     is believed to be capable of running our code in
			     gdbarch_init_osabi () which makes `e2k32_linux_
			     init_abi ()' invoked.
			     FIXME: a special macro should be introduced to
			     obtain the 32-bit ABI machine number.  */
			  4 * bfd_mach_e2k_generic + 1,
			  GDB_OSABI_LINUX, e2k32_linux_init_abi);
}
