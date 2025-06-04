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

extern bool _bfd_e2k_pm_elf_modify_segment_map
  (bfd *, struct bfd_link_info *);

extern bool _bfd_e2k_pm_elf_object_p
  (bfd *);

#undef elf_backend_modify_segment_map
#define elf_backend_modify_segment_map	_bfd_e2k_pm_elf_modify_segment_map

#undef elf_backend_object_p
#define elf_backend_object_p		_bfd_e2k_pm_elf_object_p

/* The first Elf32_Addr GOT entry containing link-time "address" of `_DYNAMIC'
   is followed by two 16 bytes long appropriately aligned descriptors containing
   `struct link_map *' and `&_dl_fixup ()'.  */
#undef elf_backend_got_header_size
#define elf_backend_got_header_size	48
