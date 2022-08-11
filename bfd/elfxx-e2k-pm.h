extern bfd_boolean _bfd_e2k_pm_elf_modify_segment_map
  (bfd *, struct bfd_link_info *);

extern bfd_boolean _bfd_e2k_pm_elf_object_p
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
