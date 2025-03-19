/* E2K ELF specific backend routines.
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

/* E2K ELF linker hash table */

#ifdef __cplusplus
extern "C" {
#endif

struct export_pl_list
{
  struct export_pl_list *next;
  struct elf_link_hash_entry *h;
};

struct _bfd_e2k_elf_link_hash_table
{
  struct elf_link_hash_table elf;

  /* Short-cuts to get to dynamic linker sections.  */
  asection *sdynbss;
  asection *srelbss;

  /* A section containing code performing static initialization of pointers
     in Protected Mode.  */
  asection *getpl;
  // bfd_vma selfinit_off;

  /* Small local sym cache. For example, it's used when we need local
     symbols to account for dynamic relocs against them (see
     check_relocs ()). Does this cache actually save any resources?  */
  struct sym_cache sym_cache;

  void (* put_word) (bfd *, bfd_vma, void *);
  bfd_vma (* r_info) (bfd_vma, bfd_vma);

  /* Adjust offset of the corresponding dynamic relocation in a lazy PLT
     entry as soon as this offset is known.  */
  void (* adjust_plt_lazy_entry_reloc_offset)
  (bfd *,
   struct _bfd_e2k_elf_link_hash_table *htab,
   asection *,
   bfd_vma,
   bfd_vma);

  unsigned int word_align_power;

  /* Interestingly enough, unlike Sparc i386 holds `plt_entry_size'
     in elf_backend_arch_data rather than in the hash table. Moreover, only
     i386 makes use of `elf_backend_arch_data' at present . . .  */


  /* PLTGOT header, its size and offsets at which it should be adjusted at
     link time.  */
  const unsigned int *plt_got_header;
  unsigned int plt_got_header_nop_offset;
  unsigned int plt_got_link_map_ld_offset;
  unsigned int plt_got_dl_fixup_ld_offset;
  unsigned int plt_got_header_size;


  const unsigned int *plt_got_primary_entry;
  unsigned int plt_got_entry_nop_offset;
  unsigned int plt_got_target_ld_offset;
  unsigned int plt_got_primary_entry_size;

  const unsigned int *plt_got_secondary_entry;
  unsigned int plt_got_reloc_arg_offset;
  unsigned int plt_got_disp_offset;
  unsigned int plt_got_secondary_entry_size;

  int bytes_per_word;

  /* Stores `sizeof (Elfxx_External_Sym)'.  */
  int bytes_per_sym;

  int bytes_per_rela;
  int abs_reloc;
  int abs_lit_reloc;
  int copy_reloc;
  int relative_reloc;
  int relative_lit_reloc;
  int dtpmod_reloc;
  int dtpoff_reloc;
  int tpoff_reloc;
  int jmp_slot_reloc;
  int irelative_reloc;

  /* Ancient semantics value is stored here depending on the output file's
     ABI. Used when producing an old-style output ELF.  */
  int ancient_semantics;

  /* Throw them away from our hash table so that we don't need to duplicate
     these fields in PM hash table and then decide which hash table should
     be used within common code.  */
#if 0
  /* `--e2k-ipd' option may take values 0, 1 and 2 only.  */
  int e2k_ipd:2;
  int e2k_is_x86app:1;
  int e2k_is_4mpages:1;
#endif /* 0  */

  /* `relaxed_e2k_machine_check' is required when merging private bfd data
     where link_info is not available. Therefore it's not present here.

     Probably `output_new_e_machine' may be set when link_info does not exist
     at all. Therefore, it's absent here as well. This issue is to be
     revisited. */

  /* Offset of a GOT entry holding runtime index of the module being linked
     (OBFD). To specify this module a runtime relocation against the dynamic
     symbol #0, which is local by its nature, is used.  */
  bfd_vma gdmod_zero_off;

  /* The numbers of primary and secondary PLT entries in the current link.  */
  bfd_vma primary_plt_num;
  bfd_vma secondary_plt_num;

  int ranges_num;
  void *ranges;
};

/* Get the E2K ELF linker hash table from a link_info structure.  */

#define _bfd_e2k_elf_hash_table(p) \
  (elf_hash_table_id  ((struct elf_link_hash_table *) ((p)->hash)) \
  == E2K_ELF_DATA ? ((struct _bfd_e2k_elf_link_hash_table *) ((p)->hash)) : NULL)



/* Methods of struct bfd_target */

extern bool _bfd_e2k_elf_link_add_symbols
  (bfd *, struct bfd_link_info *);

extern reloc_howto_type * _bfd_e2k_elf_reloc_type_lookup
  (bfd *, bfd_reloc_code_real_type);

extern reloc_howto_type * _bfd_e2k_elf_reloc_name_lookup
  (bfd *, const char *);

extern bool _bfd_e2k_elf_merge_private_bfd_data_1
  (bfd *, bfd *);

extern bool _bfd_e2k_elf_merge_private_bfd_data
  (bfd *, struct bfd_link_info *);

extern bool _bfd_e2k_elf_mkobject
  (bfd *);

extern struct bfd_link_hash_table * _bfd_e2k_elf_link_hash_table_create
  (bfd *);

extern bool _bfd_e2k_elf_create_dynamic_sections
  (bfd *, struct bfd_link_info *);

extern bool _bfd_e2k_elf_final_link
  (bfd *abfd, struct bfd_link_info *info);


/* Methods of struct elf_backend_data */

extern bool _bfd_e2k_elf_info_to_howto
  (bfd *, arelent *, Elf_Internal_Rela *);

extern bool _bfd_e2k_elf_add_symbol_hook
  (bfd *, struct bfd_link_info *, Elf_Internal_Sym *, const char **,
   flagword *, asection **, bfd_vma *);


extern void _bfd_e2k_elf_copy_indirect_symbol (struct bfd_link_info *,
                                               struct elf_link_hash_entry *,
                                               struct elf_link_hash_entry *);

extern bool _bfd_e2k_elf_check_relocs
  (bfd *, struct bfd_link_info *,
   asection *, const Elf_Internal_Rela *);

extern bool _bfd_e2k_elf_gc_sweep_hook
  (bfd *abfd,
   struct bfd_link_info *info,
   asection *sec,
   const Elf_Internal_Rela *relocs);

extern bool _bfd_e2k_elf_adjust_dynamic_symbol
  (struct bfd_link_info *, struct elf_link_hash_entry *);

extern bool _bfd_e2k_elf_size_dynamic_sections
  (bfd *, struct bfd_link_info *);

extern unsigned int _bfd_e2k_elf_action_discarded
  (asection *);

extern bool simulating_mode;

//extern bool pack_cud_gd;

extern int simulate_relocate_section (bfd *input_bfd,
                                      asection *input_section,
                                      bfd_byte *contents,
                                      Elf_Internal_Rela *relocs);

extern int _bfd_e2k_elf_relocate_section
  (bfd *, struct bfd_link_info *, bfd *,
   asection *, bfd_byte *, Elf_Internal_Rela *,
   Elf_Internal_Sym *, asection **);

extern bool _bfd_e2k_elf_finish_dynamic_symbol
  (bfd *, struct bfd_link_info *,
   struct elf_link_hash_entry *, Elf_Internal_Sym *sym);

extern enum elf_reloc_type_class
_bfd_e2k_elf_reloc_type_class (const struct bfd_link_info *,
                               const asection *,
                               const Elf_Internal_Rela *);

extern bool _bfd_e2k_elf_finish_dynamic_sections
  (bfd *, struct bfd_link_info *);

extern bool _bfd_e2k_elf_init_file_header
  (bfd *, struct bfd_link_info *);

extern bool _bfd_e2k_elf_ignore_discarded_relocs
  (asection *);

extern void _bfd_e2k_elf_hide_symbol_1
  (struct bfd_link_info *,
   struct elf_link_hash_entry *,
   bool,
   bool);

extern void _bfd_e2k_elf_hide_symbol
  (struct bfd_link_info *,
   struct elf_link_hash_entry *,
   bool);

extern bool _bfd_e2k_elf_write_object_contents
  (bfd *);

extern bool _bfd_e2k_elf_copy_private_bfd_data_1
  (bfd *, bfd *, bool);

extern bool _bfd_e2k_elf_copy_private_bfd_data
  (bfd *, bfd *);

extern bool _bfd_e2k_elf_object_p_1
  (bfd *, bool);

extern bool _bfd_e2k_elf_object_p
  (bfd *);

extern bfd * _bfd_e2k_elf_link_setup_gnu_properties
  (struct bfd_link_info *);

extern long _bfd_e2k_elf_get_synthetic_symtab
  (bfd *, long, asymbol **, long, asymbol **, asymbol **);

extern void _bfd_e2k_elf_after_parse (int);

extern void _bfd_e2k_elf_after_open (int, int, int, bool, bool,
                                     bool, bool, bool,
				     bool, bool, bool,
				     bool);

extern const struct bfd_elf_special_section _bfd_e2k_elf_special_sections[];

extern bool _bfd_e2k_elf_grok_prstatus (bfd *, Elf_Internal_Note *);

extern char * _bfd_e2k_elf_write_core_note (bfd *, char *, int *, int, ...);

extern bool _bfd_e2k_elf_relax_section (bfd *, struct bfd_section *,
					struct bfd_link_info *, bool *);

struct pm_range
{
  bfd_vma min;
  bfd_vma max;
  unsigned long align;
  long delta;
  int in_cud;
};

extern unsigned int _bfd_e2k_elf_get_range_num (bfd *abfd);
extern void _bfd_e2k_elf_fill_ranges (bfd *abfd, unsigned int range_num,
				      struct pm_range *ranges);
extern long _bfd_e2k_elf_get_offset_delta (unsigned int range_num,
					   struct pm_range *ranges,
					   bfd_vma off);

#ifdef __cplusplus
     }
#endif
