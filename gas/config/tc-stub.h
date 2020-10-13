#define TARGET_FORMAT "elf64-e2k"
#define TARGET_ARCH bfd_arch_e2k

#define md_number_to_chars number_to_chars_littleendian

#define md_convert_frag(b,s,f) \
  as_fatal (_("stub convert_frag\n"))

#define md_estimate_size_before_relax(f,s) \
  (as_fatal(_("estimate_size_before_relax called")), 1)
