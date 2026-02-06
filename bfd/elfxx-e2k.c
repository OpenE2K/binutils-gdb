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

#include "sysdep.h"
#include "bfd.h"
#include "libiberty.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/e2k.h"
#include "elfxx-e2k.h"

/* In case we're on a 32-bit machine, construct a 64-bit "-1" value.  */
#define MINUS_ONE (0xffffffffffffffffULL)

#define ELF64_P(abfd) (get_elf_backend_data (abfd)->s->elfclass == ELFCLASS64)

#define ABI_PM_P(abfd) \
  ((elf_elfheader (abfd)->e_flags & EF_E2K_PM) == EF_E2K_PM)

#define ABI_64_P(abfd) (ELF64_P (abfd) && ! ABI_PM_P (abfd))

#define ELF_R_TYPE(abfd, i)                     \
  (ELF64_P (abfd) ? ELF64_R_TYPE (i) : ELF32_R_TYPE (i))

#define ELF_R_SYM(abfd, i)                      \
  (ELF64_P (abfd) ? ELF64_R_SYM (i) : ELF32_R_SYM (i))


/* REMINDER: this function has been originally implemented in commit
   525c9ec6527259f0017dea91547b9ab0502ea30b to resolve issues related to LD
   tests producing SREC output. However, it turns out to be that when invoked
   from within e2k-linux-as it fills in literals with inappropriate for a RELA
   target assembly-time symbol values, which makes it difficult to compare
   relocatable objects produced by GAS and LAS. */
static bfd_reloc_status_type
_bfd_e2k_elf_64_abs_lit_reloc (bfd *abfd,
                               arelent *reloc_entry,
                               asymbol *symbol,
                               void *data,
                               asection *input_section ATTRIBUTE_UNUSED,
                               bfd *output_bfd ATTRIBUTE_UNUSED,
                               char **error_message ATTRIBUTE_UNUSED)
{
  bfd_vma res;

  res = (symbol->section->output_section->vma
         + symbol->section->output_offset
         + symbol->value
         + reloc_entry->addend);

  res = ((res & 0xffffffffULL) << 32) + (res >> 32);
  bfd_put_64 (abfd, res, (unsigned char *) data + reloc_entry->address);

  return bfd_reloc_ok;
}

/* For non-ELF targets (e.g. srec) don't relocate anything, just return
   `bfd_reloc_ok' so that generic code in reloc.c doesn't attempt to do this
   itself and thus cause an overflow.  */
static bfd_reloc_status_type
_bfd_e2k_elf_islocal_reloc (bfd *abfd ATTRIBUTE_UNUSED,
                            arelent *reloc_entry ATTRIBUTE_UNUSED,
                            asymbol *symbol ATTRIBUTE_UNUSED,
                            void *data ATTRIBUTE_UNUSED,
                            asection *input_section ATTRIBUTE_UNUSED,
                            bfd *output_bfd ATTRIBUTE_UNUSED,
                            char **error_message ATTRIBUTE_UNUSED)
{
  return bfd_reloc_ok;
}



/* The underlying two functions have been implemented for the sake of GDB
   compile command which uses them to handle `R_E2K_{GOT_OFF,64_PC_LIT}' in a
   just compiled relocatable object file. A special treatment of these
   relocations is required because _GLOBAL_OFFSET_TABLE_ remains undefined in
   a compiled object file. Having taken into account that R_E2K_GOTOFF is 32-
   bit by its nature, one can't use "default" zero value for GOT. Below I
   believe that GOT is placed at the start of the first section relocated
   against it. A reversed order of 32-bit literals within a 64-bit one is taken
   into account when handling R_E2K_64_PC_LIT as well.

   On i386 bfd_elf_generic_reloc () does the "right" thing when processing
   analogous relocations because in 32-bit address space they may (silently) let
   GOT be equal to zero without a subsequent relocation overflow. There's no
   issue related to a special order of sub-literals as well. We wonder how
relocations of these types are processed on x86_64 though . . .  */
static bfd_reloc_status_type
_bfd_e2k_elf_64_pc_lit_reloc (bfd *abfd,
                              arelent *reloc_entry,
                              asymbol *symbol,
                              void *data,
                              asection *input_section,
                              bfd *output_bfd,
                              char **error_message)
{
  bfd_vma gp;
  const char *name = bfd_asymbol_name (symbol);
  bfd_vma res;

  /* For now let them produce whatever they like for dummy cases I'm not
     interested in. FIXME: can't We obtain R_E2K_64_PC_LIT against other symbols
     via GDB's `compile'? Find out how the containing section of GOT turns out
     to be ABS rather than UND.  */
  if (! bfd_is_abs_section (symbol->section)
      || strcmp (name, "_GLOBAL_OFFSET_TABLE_") != 0)
    return bfd_elf_generic_reloc (abfd, reloc_entry, symbol, data,
                                  input_section, output_bfd, error_message);

  /* Use ABFD's GP (hopefully it's not used otherwise on E2K) to hold the
     synthetic value of GOT, which is the start of the first section relocated
     against it. FIXME: We should probably verify that this section belongs to
     the address space of an inferior (i.e. isn't a debug section or something
     like that) to avoid potential relocation overflows. At the same time what
     should We do if the first section relocated against GOT turns out to be a
     debug one? Where am We going to take address of GOT from in such a case?
     Hopefully, this should be almost impossible . . .  */
  gp = _bfd_get_gp_value (abfd);
  if (gp == 0)
    {
      gp = input_section->vma;
      _bfd_set_gp_value (abfd, gp);
    }

  res = (gp + reloc_entry->addend
         - (input_section->vma + reloc_entry->address));

  res = ((res & 0xffffffffULL) << 32) + (res >> 32);
  bfd_put_64 (abfd, res, (unsigned char *) data + reloc_entry->address);

  return bfd_reloc_ok;
}

static bfd_reloc_status_type
_bfd_e2k_elf_got_off_reloc (bfd *abfd,
                            arelent *reloc_entry,
                            asymbol *symbol,
                            void *data,
                            asection *input_section,
                            bfd *output_bfd ATTRIBUTE_UNUSED,
                            char **error_message ATTRIBUTE_UNUSED)
{
  bfd_vma gp;
  bfd_vma res;

  /* See the corresponding comment one function above.  */
  gp = _bfd_get_gp_value (abfd);
  if (gp == 0)
    {
      gp = input_section->vma;
      _bfd_set_gp_value (abfd, gp);
    }

  res = (symbol->section->output_section->vma
         + symbol->section->output_offset
         + symbol->value
         + reloc_entry->addend
         - gp);

  bfd_put_32 (abfd, res, (unsigned char *) data + reloc_entry->address);
  return bfd_reloc_ok;
}


static reloc_howto_type _bfd_e2k_elf_howto_table[] =
{
  [R_E2K_32_ABS] =
  HOWTO (R_E2K_32_ABS, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_ABS", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_32_DYNOPT] =
  HOWTO (R_E2K_32_DYNOPT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_DYNOPT", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_32_PC] =
  HOWTO (R_E2K_32_PC, 0, 4, 32, true, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_PC", false,
         0x00000000, 0xffffffff, true),

  [R_E2K_AP_GOT] =
  HOWTO (R_E2K_AP_GOT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_AP_GOT", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_PL_GOT] =
  HOWTO (R_E2K_PL_GOT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_PL_GOT", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_64_ABS] =
  HOWTO (R_E2K_64_ABS, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_ABS", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_DYNOPT] =
  HOWTO (R_E2K_64_DYNOPT, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_DYNOPT", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_ABS_LIT] =
  HOWTO (R_E2K_64_ABS_LIT, 0, 8, 64, false, 0, complain_overflow_bitfield,
         _bfd_e2k_elf_64_abs_lit_reloc, "R_E2K_64_ABS_LIT", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_PC_LIT] =
  HOWTO (R_E2K_64_PC_LIT, 0, 8, 64,
         /* Even though it _is_ really pc-relative we set pc_relative
            to false so that _bfd_final_link_relocate doesn't
            attempt to subtract address from relocation value. */
         false,
         0, complain_overflow_bitfield,
         _bfd_e2k_elf_64_pc_lit_reloc, "R_E2K_64_PC_LIT", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_PC] =
  HOWTO (R_E2K_64_PC, 0, 8, 64, true, 0, complain_overflow_bitfield,
	 _bfd_e2k_elf_64_pc_lit_reloc, "R_E2K_64_PC", false,
	 0x0000000000000000ULL, MINUS_ONE, true),

  [R_E2K_32_JMP_SLOT] =
  HOWTO (R_E2K_32_JMP_SLOT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_JMP_SLOT", false,
	 0x00000000, 0xffffffff, false),

  [R_E2K_32_COPY] =
  HOWTO (R_E2K_32_COPY, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_COPY", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_32_RELATIVE] =
  HOWTO (R_E2K_32_RELATIVE, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_RELATIVE", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_32_IRELATIVE] =
  HOWTO (R_E2K_32_IRELATIVE, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_IRELATIVE", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_64_JMP_SLOT] =
  HOWTO (R_E2K_64_JMP_SLOT, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_JMP_SLOT", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_COPY] =
  HOWTO (R_E2K_64_COPY, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_COPY", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_RELATIVE] =
  HOWTO (R_E2K_64_RELATIVE, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_RELATIVE", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_RELATIVE_LIT] =
  HOWTO (R_E2K_64_RELATIVE_LIT, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_RELATIVE_LIT", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_IRELATIVE] =
  HOWTO (R_E2K_64_IRELATIVE, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_IRELATIVE", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_TLS_GDMOD] =
  HOWTO (R_E2K_TLS_GDMOD, 0, 4, 32, false, 0, complain_overflow_unsigned,
         bfd_elf_generic_reloc, "R_E2K_TLS_GDMOD", false, 0,
         0xffffffff, false),

  [R_E2K_TLS_GDREL] =
  HOWTO (R_E2K_TLS_GDREL, 0, 4, 32, false, 0, complain_overflow_unsigned,
         bfd_elf_generic_reloc, "R_E2K_TLS_GDREL", false, 0,
         0xffffffff, false),         

  [R_E2K_TLS_IE] =
  HOWTO (R_E2K_TLS_IE, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_IE", false, 0x00000000,
         0xffffffff, false),


  [R_E2K_32_TLS_LE] =
  HOWTO (R_E2K_32_TLS_LE, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_32_TLS_LE", false, 0x00000000,
         0xffffffff, false),

  [R_E2K_64_TLS_LE] =
  HOWTO (R_E2K_64_TLS_LE, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_64_TLS_LE", false, 0x0000000000000000ULL,
         MINUS_ONE, false),

  /* The underlying two are normally emitted by LD but GAS may also produce them
     when generating debug info for __thread variables. The latter is an actual
     reason for putting them here.  */
  [R_E2K_TLS_32_DTPREL] =
  HOWTO (R_E2K_TLS_32_DTPREL, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_32_DTPREL", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_TLS_64_DTPREL] =
  HOWTO (R_E2K_TLS_64_DTPREL, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_64_DTPREL", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  /* These ones are not emitted by GAS but HOWTOs for them are required to
     prevent GDB from barfing on them.  */
  [R_E2K_TLS_32_DTPMOD] =
  HOWTO (R_E2K_TLS_32_DTPMOD, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_32_DTPMOD", false,
	 0x00000000, 0xffffffff, false),
     
  [R_E2K_TLS_64_DTPMOD] =
  HOWTO (R_E2K_TLS_64_DTPMOD, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_64_DTPMOD", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_TLS_TPOFF32] =
  HOWTO (R_E2K_TLS_TPOFF32, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_TPOFF32", false,
	 0x00000000, 0xffffffff, false),

  [R_E2K_TLS_TPOFF64] =
  HOWTO (R_E2K_TLS_TPOFF64, 0, 8, 64, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_TLS_TPOFF64", false,
	 0x0000000000000000ULL, MINUS_ONE, false),

  /* The next two howtos aren't used by BFD in fact, except for producing
     relocation dumps. Therefore, the fields are initialized in a rather random
     manner. We wonder, how `{src,dst}_mask' fields can be expressed for 128-bit
     items using the 64-bit `bfd_vma' type . . .  */

  /* Now that `struct reloc_howto_struct' has been packed and `size == 8'
     (this value used to match `bfd_get_reloc_size () == 16') and `bitsize ==
     128' can be no longer encoded, stupidly set these fileds to 0 for `R_E2K_
     {AP,PL}' and get ready to process these relocations specially wherever
     needed.  */
  [R_E2K_AP] =
  HOWTO (R_E2K_AP, 0, 1, 0, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_AP", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_PL] =
  HOWTO (R_E2K_PL, 0, 1, 0, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_PL", false,
         0x0000000000000000ULL, MINUS_ONE, false),


  [R_E2K_GOT] =
  HOWTO (R_E2K_GOT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_GOT", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_GOTOFF] =
  HOWTO (R_E2K_GOTOFF, 0, 4, 32, false, 0, complain_overflow_signed,
         _bfd_e2k_elf_got_off_reloc, "R_E2K_GOTOFF", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_DISP] =
  HOWTO_EX (R_E2K_DISP, 3, 4, 28, true, 0, complain_overflow_signed,
	    bfd_elf_generic_reloc, "R_E2K_DISP", false,
	    0x00000000, 0x0fffffff, true, 64),

  /* This relocation is treated very specially by E2K backend. Set all useless
     fields (i.e., those ones which don't get processed by the common code in
     reloc.c) to false. E.g., no matter that this relocation is PC_RELATIVE in
     principle, the corresponding field is set to false.  */
  [R_E2K_PREF] =
  HOWTO (R_E2K_PREF, 7, 4, 32, false, 4, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_DISP", false,
         0x00000000, 0x0ffffff0, false),


  [R_E2K_GOTPLT] =
  HOWTO (R_E2K_GOTPLT, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_GOTPLT", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_ISLOCAL] =
  HOWTO (R_E2K_ISLOCAL, 0, 4, 1, false, 16, complain_overflow_bitfield,
         _bfd_e2k_elf_islocal_reloc, "R_E2K_ISLOCAL", false,
         0xff00ffff, 0x00ff0000, false),

  [R_E2K_ISLOCAL32] =
  HOWTO (R_E2K_ISLOCAL32, 0, 4, 32, false, 0, complain_overflow_bitfield,
         bfd_elf_generic_reloc, "R_E2K_ISLOCAL32", false,
         0x00000000, 0xffffffff, false),

  [R_E2K_32_SIZE] =
  HOWTO(R_E2K_32_SIZE, 0, 4, 32, false, 0, complain_overflow_unsigned,
	bfd_elf_generic_reloc, "R_E2K_32_SIZE", false, 0xffffffff, 0xffffffff,
	false),

  [R_E2K_64_SIZE] =
  HOWTO(R_E2K_64_SIZE, 0, 8, 64, false, 0, complain_overflow_unsigned,
	bfd_elf_generic_reloc, "R_E2K_64_SIZE", false, MINUS_ONE, MINUS_ONE,
	false),

  [R_E2K_64_GOTOFF] =
  HOWTO (R_E2K_64_GOTOFF, 0, 8, 64, false, 0, complain_overflow_signed,
         bfd_elf_generic_reloc, "R_E2K_64_GOTOFF", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  [R_E2K_64_GOTOFF_LIT] =
  HOWTO (R_E2K_64_GOTOFF_LIT, 0, 8, 64, false, 0, complain_overflow_bitfield,
         _bfd_e2k_elf_64_abs_lit_reloc, "R_E2K_64_GOTOFF_LIT", false,
         0x0000000000000000ULL, MINUS_ONE, false),

  /* Note that it's crucial for R_E2K_NONE to have `size == 3' so as to ensure
     that `bfd_get_reloc_size ()' returns 0 for it. The latter is important
     because R_E2K_NONE may be assigned an offset at the very end of the output
     section during the relocatable link if the discarded input section to which
     the original relocation was applied was located correspondingly. Otherwise,
     processing R_E2K_NONE in such a case during the final link will result in
     `bfd_reloc_outofrange'.  */
  [R_E2K_NONE] =
  HOWTO (R_E2K_NONE, 0,	 0, 0, false, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_E2K_NONE", false,
	 0, 0, false),

  [R_E2K_ALIGN_RELAX] =
  HOWTO (R_E2K_ALIGN_RELAX, 0, 0, 0, false, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_E2K_ALIGN_RELAX", false,
	 0, 0, false),

  [R_E2K_MCSTBUG_140436_RELAX] =
  HOWTO (R_E2K_MCSTBUG_140436_RELAX, 0, 0, 0, false, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_E2K_MCSTBUG_140436_RELAX", false,
	 0, 0, false),
};

reloc_howto_type *
_bfd_e2k_elf_reloc_type_lookup (bfd *abfd ATTRIBUTE_UNUSED,
                                bfd_reloc_code_real_type code)
{
  switch (code)
    {
    case BFD_RELOC_32:
      return &_bfd_e2k_elf_howto_table[R_E2K_32_ABS];
    case BFD_RELOC_64:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_ABS];
    case BFD_RELOC_32_PCREL:
      return &_bfd_e2k_elf_howto_table[R_E2K_32_PC];
    case BFD_RELOC_64_PCREL:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_PC];
    case BFD_RELOC_E2K_64_PCREL_LIT:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_PC_LIT];
    case BFD_RELOC_32_GOTOFF:
      return &_bfd_e2k_elf_howto_table[R_E2K_GOTOFF];
    case BFD_RELOC_E2K_64_ABS_LIT:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_ABS_LIT];
    case BFD_RELOC_E2K_DISP:
      /* Keep in mind that our DISP relocation is very different from
         PCREL ones though at other architectures like i386 they may be
         the same. That is the reason for having a separate
         BFD_RELOC_E2K_DISP.  */
      return &_bfd_e2k_elf_howto_table[R_E2K_DISP];
    case BFD_RELOC_E2K_PLT:
      /* This one shouldn't be used by any of our components at present.  */
      return NULL;
    case BFD_RELOC_E2K_GOTPLT:
      return &_bfd_e2k_elf_howto_table[R_E2K_GOTPLT];
    case BFD_RELOC_E2K_GOT:
      return &_bfd_e2k_elf_howto_table[R_E2K_GOT];
    case BFD_RELOC_E2K_TLS_GDMOD:
      return &_bfd_e2k_elf_howto_table[R_E2K_TLS_GDMOD];
    case BFD_RELOC_E2K_TLS_GDREL:
      return &_bfd_e2k_elf_howto_table[R_E2K_TLS_GDREL];
    case BFD_RELOC_E2K_TLS_IE:
      return &_bfd_e2k_elf_howto_table[R_E2K_TLS_IE];
    case BFD_RELOC_E2K_32_TLS_LE:
      return &_bfd_e2k_elf_howto_table[R_E2K_32_TLS_LE];
    case BFD_RELOC_E2K_64_TLS_LE:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_TLS_LE];
    case BFD_RELOC_E2K_32_DTPREL:
      return &_bfd_e2k_elf_howto_table[R_E2K_TLS_32_DTPREL];
    case BFD_RELOC_E2K_64_DTPREL:
      return &_bfd_e2k_elf_howto_table[R_E2K_TLS_64_DTPREL];
    case BFD_RELOC_E2K_ISLOCAL:
      return &_bfd_e2k_elf_howto_table[R_E2K_ISLOCAL];
    case BFD_RELOC_E2K_ISLOCAL32:
      return &_bfd_e2k_elf_howto_table[R_E2K_ISLOCAL32];
    case BFD_RELOC_SIZE32:
      return &_bfd_e2k_elf_howto_table[R_E2K_32_SIZE];
    case BFD_RELOC_SIZE64:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_SIZE];
    case BFD_RELOC_E2K_PREF:
      return &_bfd_e2k_elf_howto_table[R_E2K_PREF];
    case BFD_RELOC_E2K_GOTOFF64:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_GOTOFF];
    case BFD_RELOC_E2K_GOTOFF64_LIT:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_GOTOFF_LIT];
    case BFD_RELOC_E2K_AP_GOT:
      return &_bfd_e2k_elf_howto_table[R_E2K_AP_GOT];
    case BFD_RELOC_E2K_PL_GOT:
      return &_bfd_e2k_elf_howto_table[R_E2K_PL_GOT];

    case BFD_RELOC_E2K_AP:
      return &_bfd_e2k_elf_howto_table[R_E2K_AP];
    case BFD_RELOC_E2K_PL:
      return &_bfd_e2k_elf_howto_table[R_E2K_PL];
    case BFD_RELOC_E2K_DYNOPT64:
      return &_bfd_e2k_elf_howto_table[R_E2K_64_DYNOPT];
    case BFD_RELOC_E2K_DYNOPT32:
      return &_bfd_e2k_elf_howto_table[R_E2K_32_DYNOPT];
    case BFD_RELOC_E2K_ALIGN_RELAX:
      return &_bfd_e2k_elf_howto_table[R_E2K_ALIGN_RELAX];
    case BFD_RELOC_E2K_MCSTBUG_140436_RELAX:
      return &_bfd_e2k_elf_howto_table[R_E2K_MCSTBUG_140436_RELAX];
    default:
      break;
    }

  return NULL;
}

reloc_howto_type *
_bfd_e2k_elf_reloc_name_lookup (bfd *abfd ATTRIBUTE_UNUSED,
				const char *r_name)
{
  unsigned int i;

  for (i = 0;
       i < (sizeof (_bfd_e2k_elf_howto_table)
	    / sizeof (_bfd_e2k_elf_howto_table[0]));
       i++)
    {
      if (_bfd_e2k_elf_howto_table[i].name != NULL
	  && strcasecmp (_bfd_e2k_elf_howto_table[i].name, r_name) == 0)
	return &_bfd_e2k_elf_howto_table[i];
    }

  return NULL;
}


/* These ones are set to values of the respective options. See my comments
   in `elfxx-e2k.h' on why they are not placed into e2k link hash table.  */
static int e2k_ipd;
static int e2k_is_x86app;
static int e2k_is_4mpages;
static bool arch_set_via_cmdline;
static bool restrict_to_arch;
static bool relaxed_e2k_machine_check;
static bool output_new_e_machine = true;
bool simulating_mode;
static bool pack_cud_gd;
static bool mcstbug_140436_workaround;
static bool plt_via_movtd_ct = false;
static bool relaxed_e2k_pm_check = false;

static int link_mixed_eir_phase;

struct cud_gd_range
{
  bfd_vma min;
  bfd_vma max;
  bfd_vma align;
  bfd_signed_vma delta;
  /* This field should be of no use except for during the initialization
     of htab->ranges[]. Consider eliminating it.  */
  bool in_cud;
};

static int
compare_cud_gd_ranges (const void *a, const void *b)
{
  const struct cud_gd_range *first = (const struct cud_gd_range *) a;
  const struct cud_gd_range *second = (const struct cud_gd_range *) b;

  /* Taking into account that the ranges are not allowed to overlap (at least
     at present) which is going to be checked during the initialization of
     htab->ranges[] below, just use MIN field to order them.  */

  return first->min < second->min ? -1 : (first->min > second->min ? 1 : 0);
}

#ifdef HAVE_e2k_elf64_vec
bfd_vma
orig_offset_in_cud (struct bfd_link_info *info, bfd_vma offset)
{
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);

  if (! ABI_PM_P (htab->elf.dynobj)
      || htab->ranges == NULL)
    return offset;

  int i;
  struct cud_gd_range *ranges = htab->ranges;
  for (i = 0; i < htab->ranges_num; i++)
    {
      if (! ranges[i].in_cud)
	continue;

      bfd_vma orig_off = offset - ranges[i].delta;
      if (orig_off >= ranges[i].min && orig_off < ranges[i].max)
	return orig_off;
    }

  return offset;
}
#endif

#ifndef HAVE_e2k_elf64_vec
static
#endif
bfd_vma
adjust_offset_in_cud_gd (struct bfd_link_info *info, bfd_vma offset)
{
  int i;
  struct _bfd_e2k_elf_link_hash_table *htab;
  struct cud_gd_range *ranges;

  /* Zero offset corresponds to NULL both in CUD and GD. It's probably the
     only valid offset not belonging to any of PT_LOAD segments.  */
  if (offset == 0)
    return 0;

  if (! pack_cud_gd)
    return offset;

  htab = _bfd_e2k_elf_hash_table (info);

  if (! ABI_PM_P (htab->elf.dynobj))
    return offset;

  if (htab->ranges == NULL)
    {
      struct elf_segment_map *m;
      Elf_Internal_Phdr *phdrs = elf_tdata (info->output_bfd)->phdr;
      Elf_Internal_Phdr *p;
      int num = 0;
      bfd_vma max_page_aligned;
      bfd_vma cud_size, gd_size;

      for (m = elf_seg_map (info->output_bfd), p = phdrs; m != NULL;
	   m = m->next, p++)
	{
	  if (p->p_type == PT_LOAD)
	    num++;
	}

      ranges = (struct cud_gd_range *) bfd_alloc (htab->elf.dynobj,
						  (sizeof (struct cud_gd_range)
						   * num));

      /* FIXME ...  */
      if (ranges == NULL)
	{
	  /* Hopefully this will make the linkage fail.  */
	  _bfd_error_handler (_("allocation of address ranges for CUD and GD "
				"failed"));
	  /* There's no point in trying anymore.  */
	  pack_cud_gd = false;
	  return offset;
	}

      for (m = elf_seg_map (info->output_bfd), p = phdrs, i = 0; m != NULL;
	   m = m->next, p++)
	{
	  if (p->p_type == PT_LOAD)
	    {
	      if (p->p_align < 0x1000
		  || ((p->p_vaddr - p->p_offset) & (p->p_align - 1)) != 0)
		{
		  _bfd_error_handler (_("inappropriately aligned segments "
					"cannot be packed"));
		  pack_cud_gd = false;
		  return offset;
		}
		  
	      ranges[i].min = p->p_vaddr;
	      ranges[i].max = p->p_vaddr + p->p_memsz;
	      ranges[i].align = p->p_align;
	      ranges[i].in_cud = (p->p_flags & PF_X) ? true : false;
	      i++;
	    }
	}

      qsort (ranges, num, sizeof (struct cud_gd_range), compare_cud_gd_ranges);

      cud_size = gd_size = 0;
      max_page_aligned = 0;
      for (i = 0; i < num; i++)
	{
	  bfd_vma min_page_aligned = ranges[i].min & ~(ranges[i].align - 1);
	  bfd_vma b, r, pos;

	  /* MAX_PAGE_ALIGNED corresponds to the preceding segment in this
	     comparison, of course.  */
	  if (min_page_aligned < max_page_aligned)
	    {
	      _bfd_error_handler (_("compactification of CUD/GD segments "
				    "with overlapping pages is not supported"));
	      pack_cud_gd = false;
	      return offset;
	    }

	  max_page_aligned = (ranges[i].max + 0xfffULL) & ~(0xfffULL);


	  if (ranges[i].in_cud)
	    pos = cud_size;
	  else
	    pos = gd_size;

	  pos = (pos + 0xfffULL) & ~0xfffULL;
	  r = ranges[i].min & (ranges[i].align - 1);
	  b = (pos + ranges[i].align - (r + 1)) / ranges[i].align;
	  pos = b * ranges[i].align + r;

	  ranges[i].delta = pos - ranges[i].min;
	  pos += ranges[i].max - ranges[i].min;

	  if (ranges[i].in_cud)
	    cud_size = pos;
	  else
	    gd_size = pos;
	}

      htab->ranges_num = num;
      htab->ranges = ranges;
    }
  else
    ranges = htab->ranges;

  /* FIXME: consider optimizing this search.  */
  for (i = 0; i < htab->ranges_num; i++)
    {
      if (offset < ranges[i].min)
	break;

      if (offset >= ranges[i].max)
	continue;

      return offset + ranges[i].delta;
    }

  /* Give a chance to an "_end"-like symbol formally lying one byte beyond
     its range.  */
  int j;
  j = htab->ranges_num - 1;
  if (offset == ranges[j].max)
    return offset + ranges[j].delta;

  /* If the trailing address range in CUD (GD) didn't match look for another
     trailing range GD (CUD) respectively.  */
  bool in_cud = !ranges[j].in_cud;
  for (i = j - 1; i >= 0; i--)
    {
      if (ranges[i].in_cud == in_cud)
	{
	  if (offset == ranges[i].max)
	    return offset + ranges[i].delta;
	  else
	    /* No point in trying any longer as we have checked trailing ranges
	       both in CUD and GD.  */
	    break;
	}
    }
    
    

  /* FIXME: this may happen for ABS symbols.  */
#if 0
  _bfd_error_handler (_("address 0x%lx doesn't correspond to any "
			"PT_LOAD segment and thus can't be reliably "
			"compactified"), offset);
#endif /* 0  */
  return offset;
}

void
_bfd_e2k_elf_after_parse (int phase)
{
  link_mixed_eir_phase = phase;
}



/* This function should be called from `after_open' rather than from
   `after_parse' since a hash table should have already been allocated
   by the time it gets called.  */
void
_bfd_e2k_elf_after_open (int ipd,
                         int is_x86app,
                         int is_4mpages,
                         bool arch_via_cmdline,
                         bool restrict_to,
                         bool machine_check,
                         bool new_e_machine,
                         bool simulate,
			 bool pack_cg,
			 bool mcstbug_140436,
			 bool movtd_ct_plt,
			 bool pm_check)
{
  /* Note that in S-records test INFO->HTAB turns out to be zero somehow when
     this function gets called . . .  */
  e2k_ipd = ipd;
  e2k_is_x86app = is_x86app;
  e2k_is_4mpages = is_4mpages;

  arch_set_via_cmdline = arch_via_cmdline;
  restrict_to_arch = restrict_to;
  relaxed_e2k_machine_check = machine_check;
  output_new_e_machine = new_e_machine;
  simulating_mode = simulate;
  pack_cud_gd = pack_cg;
  mcstbug_140436_workaround = mcstbug_140436;
  plt_via_movtd_ct = movtd_ct_plt;
  relaxed_e2k_pm_check = pm_check;
}

static bool
check_magic (bfd *abfd, asection *magic_sec)
{
  char *magic = getenv ("MAGIC");
  size_t magic_size;
  char *data;
  bool res = false;

  BFD_ASSERT (magic);
  magic_size = strlen (magic) + 1;

  data = xmalloc (magic_sec->size);
  if (! bfd_get_section_contents (abfd, magic_sec, data, 0, magic_sec->size))
    {
      _bfd_error_handler (_("%pB: cannot read contents of section %pA\n"),
                          abfd, magic_sec);
    }

  if (magic_sec->size == (12 + ((sizeof ("MCST") + 3) & 0xfffffffc)
                          + ((magic_size + 3) & 0xfffffffc))
      && bfd_get_32 (abfd, data) == sizeof ("MCST")
      && bfd_get_32 (abfd, data + 4) == magic_size
      && bfd_get_32 (abfd, data + 8) == NT_MAGIC
      && data[12 + sizeof ("MCST") - 1] == '\0'
      && data[12 + ((sizeof ("MCST") + 3) & 0xfffffffc)
              + magic_size - 1] == '\0'
      && strncmp (data + 12, "MCST", sizeof ("MCST") - 1) == 0
      && strncmp (data + 12 + ((sizeof ("MCST") + 3) & 0xfffffffc), magic,
                  magic_size - 1) == 0)
    res = true;

  free (data);  
  return res;
}

/* This function is used to produce neat error messages when merging BFDs
   below. As for `bfd_printable_name ()', it's not quite perfect since it
   contains redundant ":{32,64,pm}" info which is guaranteed to coincide by
   the time `merge_private_bfd_data ()' is called. On the other hand, forward
   incompatible `elbrus-v{2,3}' BFDs should be identified as `elbrus-{2c+,4c}'
   specific respectively for now. The decorated names more or less match the
   ones output by `readelf --headers'.  */
static const char *
decorated_arch_name (bfd *abfd)
{
  Elf_Internal_Ehdr *hdr = elf_elfheader (abfd);
  /* FIXME: it's too early to check `hdr->e_machine == EM_MCST_ELBRUS' for
     OBFD here, since it may have not been set up so far.  */
  bool fi = (hdr->e_flags & EF_E2K_INCOMPAT) != 0;
  unsigned long mach = abfd->arch_info->mach / 4;

  switch (mach)
    {
    case bfd_mach_e2k_generic:
      return fi ? "forward incompatible generic" : "generic";
    case bfd_mach_e2k_ev1:
      return fi ? "forward incompatible elbrus-v1" : "elbrus-v1";
    case bfd_mach_e2k_ev2:
      return fi ? "elbrus-2c+" : "elbrus-v2";
    case bfd_mach_e2k_ev3:
      return fi ? "elbrus-4c" : "elbrus-v3";
    case bfd_mach_e2k_ev4:
      return fi ? "forward incompatible elbrus-v4" : "elbrus-v4";
    case bfd_mach_e2k_ev5:
      return fi ? "elbrus-8c2" : "elbrus-v5";
    case bfd_mach_e2k_ev6:
      return fi ? "forward incompatible elbrus-v6" : "elbrus-v6";
    case bfd_mach_e2k_ev7:
      return fi ? "forward incompatible elbrus-v7" : "elbrus-v7";
    case bfd_mach_e2k_8c:
      return "elbrus-8c";
    case bfd_mach_e2k_1cplus:
      return "elbrus-1c+";
    case bfd_mach_e2k_12c:
      return "elbrus-12c";
    case bfd_mach_e2k_16c:
      return "elbrus-16c";
    case bfd_mach_e2k_2c3:
      return "elbrus-2c3";
    case bfd_mach_e2k_48c:
      return "elbrus-48c";
    case bfd_mach_e2k_8v7:
      return "elbrus-8v7";
    case bfd_mach_e2k_maket32c:
      return "elbrus-maket32c";
    default:
      BFD_ASSERT (0);
      return NULL;
    }
}

static const char *
bitness (unsigned long mach)
{
  static const char *names[] = {"64-bit", "32-bit", "PM", "any"};
  return names[mach % 4];
}
  

bool
_bfd_e2k_elf_merge_private_bfd_data_1 (bfd *ibfd, bfd *obfd)
{
  unsigned long imach, omach;
  int incompatible_input;
  int incompatible_output;

  Elf_Internal_Ehdr *ihdr;
  Elf_Internal_Ehdr *ohdr;

  int protected_mode;

  /* This is used internally in this function to enumerate all currently
     recognized E2K processor types when it comes to determining if `bfd_mach_
     e2k_*' BFD can be executed on this or that processor.  */
  enum
  {
    ev1,
    ev2,
    ev3,
    e8c,
    e1cplus,
    ev5,
    e12c,
    e16c,
    e2c3,
    e48c,
    e8v7,
    emaket32c,
    /* The related bit in mask stands for "all future processor models".  */
    ev8
  };

  /* Specify P in the mask of processors at which the BFD under consideration
     can be executed.  */
#define AT(p) (1L << p)

#define AT_ev6 (AT (e12c) | AT (e16c) | AT (e2c3))

/* Note the absence of emaket32c in this mask. This is because the execution
   of code coming from elbrus-v{X<=7} object files is considered to be
   impossible on elbrus-maket32c and thus the linkage of these object files
   into elbrus-maket32c executable should be prohibited.  */
#define AT_ev7 (AT (e48c) | AT (e8v7))

  /* This is a machine compatibility table. It provides the mask of machines an
     object file compiled (or linked) for a given machine (specified by the row)
     can be executed on in either compatible (column 0) or incompatible (column
     1) mode. Incompatible mode means that the object file contains code which
     is incompatible with subsequent machines, which isn't usually the case.  */
  static const unsigned long mask[][2] = 
    {
      [bfd_mach_e2k_generic] =  {(AT (ev1) | AT (ev2) | AT (ev3) | AT (e8c)
				  | AT (e1cplus) | AT (ev5) | AT_ev6
				  | AT_ev7 | AT (ev8)),
				 (AT (ev1) | AT (ev2))},

      [bfd_mach_e2k_ev1] =      {AT (ev1),
				 AT (ev1)},

      [bfd_mach_e2k_ev2] =      {(AT (ev2) | AT (ev3) | AT (e8c) | AT (e1cplus)
				  | AT (ev5) | AT_ev6 | AT_ev7
				  /* emaket32c is present here only because
				     elbrus-v2 is currently used as the "initial
				     approximation" of the output machine. This
				     bit will be zeroed out below if it turns
				     out to be irrelevant. TODO: consider
				     falling back to use of e2k_generic for
				     this purpose.  */
				  | AT (emaket32c)
				  | AT (ev8)),
				 (AT (ev2))},

      [bfd_mach_e2k_ev3] =      {(AT (ev3) | AT (e8c) | AT (e1cplus) | AT (ev5)
				  | AT_ev6 | AT_ev7 | AT (ev8)),
				 AT (ev3)},
      
      [bfd_mach_e2k_ev4] =      {(AT (e8c) | AT (e1cplus) | AT (ev5) | AT_ev6
				  | AT_ev7 | AT (ev8)),
				 (AT (e8c) | AT (e1cplus))},
      [bfd_mach_e2k_ev5] =      {(AT (ev5) | AT_ev6 | AT_ev7 | AT (ev8)),
				 AT (ev5)},

      [bfd_mach_e2k_ev6] =      {(AT_ev6 | AT_ev7 | AT (ev8)),
				 AT_ev6},

      [bfd_mach_e2k_ev7] =      {(AT_ev7 | AT (ev8)),
				 AT_ev7},

      [bfd_mach_e2k_8c] =	{AT (e8c),
				 AT (e8c)},

      [bfd_mach_e2k_1cplus] =	{AT (e1cplus),
				 AT (e1cplus)},

      [bfd_mach_e2k_12c] =	{AT (e12c),
				 AT (e12c)},

      [bfd_mach_e2k_16c] =	{AT (e16c),
				 AT (e16c)},

      [bfd_mach_e2k_2c3] =	{AT (e2c3),
				 AT (e2c3)},

      [bfd_mach_e2k_48c] =	{AT (e48c),
				 AT (e48c)},

      [bfd_mach_e2k_8v7] =	{AT (e8v7),
				 AT (e8v7)},

      [bfd_mach_e2k_maket32c] =	{AT (emaket32c),
				 AT (emaket32c)},
    };

  if (bfd_get_flavour (ibfd) == bfd_target_elf_flavour && getenv ("MAGIC"))
    {
      asection *magic_sec;
      static bool first_ibfd_saved = true;
      bool res, first_ibfd = first_ibfd_saved;

      /* Next time `first_ibfd' will be set to false.  */
      first_ibfd_saved = false;

      magic_sec = bfd_get_section_by_name (ibfd, ".magic");
      if (magic_sec == NULL)
        {
          _bfd_error_handler (_("Input object %pB doesn't have a .magic "
                                "section"), ibfd);
          return false;
        }

      res = check_magic (ibfd, magic_sec);
      /* Exclude this section from output no matter what `check_magic ()'
         returned, though it's not absolutely necessary if it failed: we are
         not going to have any output in this case.  */
      if (! first_ibfd)
        {
          magic_sec->flags |= SEC_EXCLUDE;
          magic_sec->size = 0;
        }

      if (! res)
        {
          _bfd_error_handler (_("Input object %pB contains wrong MAGIC "),
                              ibfd);
            return false;
        }
    }  

  /* My further checks are meaningful if both input and output files are
     ELFs only. Well, probably the check for `obfd' is redundant, because
     this method is related to an ELF-specific backend. As for `ibfd' we
     may very well have a binary here, e.g. when building the Kernel
     (see  MCSTBug #58954).

     P.S. This test has been borrowed from `elfxx-mips.c' and seems to be
     OK for my purposes. Maybe, it can be replaced with the one from
     `bfd_arch_get_compatible ()' in `archures.c' where a `binary' case
     is considered explicitly.  */
  if (bfd_get_flavour (ibfd) != bfd_target_elf_flavour
      || bfd_get_flavour (obfd) != bfd_target_elf_flavour)
    return true;

  ihdr = elf_elfheader (ibfd);
  ohdr = elf_elfheader (obfd);

  imach = bfd_get_mach (ibfd);
  omach = bfd_get_mach (obfd);

  /* It should be impossible to find ourselves here if `bfd_e2k_compatible ()'
     failed, shouldn't it?  */
  if (imach % 4 != omach % 4)
    {
      _bfd_error_handler
	(_("%s input file `%pB' is incompatible with %s output"),
	 bitness (imach), ibfd, bitness (omach));
      return false;
    }

  /* Input object file with "any bitness" mach should not appear in
     principle.  */
  BFD_ASSERT (imach % 4 != 3);

  if ((ihdr->e_ident[EI_OSABI] == ELFOSABI_KPDA
       || get_elf_backend_data (obfd)->elf_osabi == ELFOSABI_KPDA)
      && ihdr->e_ident[EI_OSABI] != get_elf_backend_data (obfd)->elf_osabi)
    {
      bool kpda_input = ihdr->e_ident[EI_OSABI] == ELFOSABI_KPDA;
      const char *linux_abi = "Linux";
      const char *kpda_abi = "KPDA";

      _bfd_error_handler
        (_("%pB: input with `%s' ABI cannot be processed by `%s' target"),
         ibfd, kpda_input ? kpda_abi : linux_abi,
         kpda_input ? linux_abi : kpda_abi);
      return false;
    }

  /* Shared objects' machine shouldn't have an impact on the one eventually set
     for OBFD as they can be very different from the ones used at runtime in
     this respect. The above tests not allowing for the mixture of different
     ABIs and GNU, Uclibc and KPDA object files seem to be reasonable because
     the user should NOT allow for such mixtures at link-time.  */
  if ((ibfd->flags & DYNAMIC) != 0)
    return true;

  /* Are we linking in PM? The above test ensures that this coincides
     with `OMACH % 4'.  */
  protected_mode = (imach % 4 == 2) ? 1 : 0;

  /* Now that we are guaranteed that input and output bfds have the same mode,
     migrate to e2k machine masks defined in `MCST E2K' section of
     `bfd/archures.c'.  */
  imach /= 4;
  omach /= 4;

  /* Explicitly prohibit the linkage of "generic" and "elbrus-v1" input ELFs as
     proposed in MCSTBug #96498, Comment #11 so as to make it impossible in
     principle.  */
  if (imach == bfd_mach_e2k_generic || imach == bfd_mach_e2k_ev1)
    {
      _bfd_error_handler
	(_("%pB: link of `%s' input files is no longer supported"),
	 ibfd,
	 imach == bfd_mach_e2k_generic ? "generic" : "elbrus-v1");
      return false;
    }

  /* Further machine compatibility checks should not be performed in
     `--relaxed-e2k-machine' mode.  */
  if (relaxed_e2k_machine_check)
    return true;

  /* Is the currently considered input file incompatible?  */
  incompatible_input = (((ihdr->e_machine == EM_MCST_ELBRUS)
			 && (ihdr->e_flags & EF_E2K_INCOMPAT))
			? 1
			: 0);

  if (! output_new_e_machine)
    {
      if (incompatible_input )
        {
          _bfd_error_handler (_("New style object %pB with `EF_E2K_INCOMPAT' "
                                "flag set cannot be linked into an old "
                                "style %pB"), ibfd, obfd);
          return false;
        }

      /* If we are still alive here when producing an old style output,
         we haven't come across a new style incompatible object file.  */
      incompatible_output = 0;
    }
  else
    {
      /* Have we already come across an incompatible object file which
         resulted in an incompatible output? */
      incompatible_output = (ohdr->e_flags & EF_E2K_INCOMPAT) ? 1 : 0;
    }


  /* Provided that `--restrict-to-arch OUTPUT_ARCH' has been specified, an
     input file's architecture should exactly match OUTPUT_ARCH.  */
  if (restrict_to_arch && imach != omach)
    {
      _bfd_error_handler
        (_("input file `%pB' of `%s' architecture does not match "
           "`%s' specified via `--restrict-to-arch' option"),
	 ibfd, decorated_arch_name (ibfd), decorated_arch_name (obfd));
      return false;
    }

  /* Get masks of machines input and output files can be executed at.  */
  imach = mask[imach][incompatible_input];

  /* PM code suitable for execution on elbrus-v{X<7} should NOT be considered
     forward-compatible with elbrus-v{X>=7} contrary to the general rule yet
     applicable in this case to ordinary modes (Bug #143326).  */
  if (protected_mode
      && (imach & (AT_ev7 | AT (ev8))) != imach)
    imach &= ~(AT_ev7 | AT (ev8));

  /* Are there any bits except for emaket32c set? Zero out irrelevant emaket32c
     bit (for elbrus-v2 (see comment on `mask[bfd_mach_e2k_ev2]' above) IBFD)
     then.  */
  if ((imach & AT (emaket32c)) != imach)
    imach &= ~AT (emaket32c);

  /* VERIFY: hopefully `omach' is set to `bfd_mach_e2k_generic' via LD script
     if it's not explicitly specified via `-A' by the user. This is crucial
     for my scheme to work properly.  */
  omach = mask[omach][incompatible_output];
  {
    static int already_invoked = 0;
    if (already_invoked)
      {
	/* elbrus-v{7,8}-compatibility bits should be disabled for elbrus-v{X<7}
	   PM output starting from the 2nd invocation of this function (i.e.
	   before the 2nd merge) as we don't actually know that the output is
	   intended for elbrus-v{X<7} during the 1st invocation because the
	   "initial elbrus-v2 approximation" for OMACH we start with claims
	   support for all machines including elbrus-v{7,8}. The failure to
	   realize that has resulted in a false linkage failure when linking
	   a single elbrus-v7 input object (see MCSTBug #143326, Comments #7
	   and #8).  */
	if (protected_mode
	    && ((omach & (AT_ev7 | AT (ev8))) != omach))
	  omach &= ~(AT_ev7 | AT (ev8));

	/* The aforesaid applies to irrelevant emaket32c bit as well no matter
	   which mode the link is done in.  */
	if ((omach & AT (emaket32c)) != omach)
	  omach &= ~AT (emaket32c);
      }
    else
      already_invoked = 1;
  }

  /* Update the mask for the output and see if it becomes incompatible after
     the next input file has been brought into play.  */
  omach = omach & imach;
  incompatible_output = (incompatible_input || incompatible_output);

  /* If the output arch has been specified explicitly, fail if we get
     something different (e.g. the user wants E3S while the combination
     of input files makes us choose E2S).  */
  if (arch_set_via_cmdline
      && omach != mask[obfd->arch_info->mach / 4][incompatible_output])
    omach = 0;

  if (omach != 0)
    {
      unsigned int i;

      if (output_new_e_machine && incompatible_input)
        {
          /* Don't care about this case when producing old style output. It
             should be impossible (see call to bfd_error_handler above).  */
          ohdr->e_flags |= EF_E2K_INCOMPAT;
        }

      /* Get the machine number corresponding to the updated output mask. It
         should be one of our candidates provided that We don't have a logical
         error here.  */
      for (i = 0; i < sizeof (mask) / sizeof (mask[0]); i++)
        {
	  unsigned long msk = mask[i][incompatible_output];
	  /* When searching for the matching entry, take into account that
	     we have filtered out these bits in PM for IMACH and OMACH
	     corresponding to elbrus-v{X<7}.  */
	  if (protected_mode
	      && (msk & (AT_ev7 | AT (ev8))) != msk)
	    msk &= ~(AT_ev7 | AT (ev8));

	  /* Zero out irrelevant emaket32c bit if other ones are present
	     no matter which mode the link is done in.  */
	  if ((msk & AT (emaket32c)) != msk)
	    msk &= ~AT (emaket32c);

	  if (omach == msk)
	    break;
        }

      BFD_ASSERT (i < sizeof (mask) / sizeof (mask[0]));

      i *= 4;
      i += obfd->arch_info->mach % 4;

      if (obfd->arch_info->mach != (unsigned long) i)
        bfd_set_arch_mach (obfd, bfd_arch_e2k, (unsigned long) i);

      return true;
    }

  _bfd_error_handler
    (_("%sinput file `%pB' for `%s' architecture is incompatible "
       "with `%s' output"),
     /* Stupidly mention PM when linking in this mode (though the merge failure
	may have no relation to extra control implemented in MCSTBug #143326) to be
	on the safe side.  */
     protected_mode ? "protected mode " : "",
     ibfd, decorated_arch_name (ibfd), decorated_arch_name (obfd));

  return false;
}

#define is_e2k_elf(abfd)                                 \
  (bfd_get_flavour (abfd) == bfd_target_elf_flavour      \
   && elf_tdata (abfd) != NULL                           \
   && elf_object_id (abfd) == E2K_ELF_DATA)


bool
_bfd_e2k_elf_merge_private_bfd_data (bfd *ibfd, struct bfd_link_info *info)
{
  return _bfd_e2k_elf_merge_private_bfd_data_1 (ibfd, info->output_bfd);
}

/* We need this structure because of an extra TYPE field missing from `struct
   elf_dyn_relocs' required to distinguish between references via `R_E2K_{AP,
   PL}'. FIXME: eventually it should be derived from the latter.  */
struct e2k_elf_dyn_relocs
{
  struct e2k_elf_dyn_relocs *next;

  /* The input section of the reloc.  */
  asection *sec;

  /* Total number of relocs copied for the input section.  */
  bfd_size_type count;

  /* Number of pc-relative relocs copied for the input section.  */
  bfd_size_type pc_count;

  int type;
};


/* E2K ELF linker hash entry.  */

struct _bfd_e2k_elf_link_hash_entry
{
  struct elf_link_hash_entry elf;

  /* Track dynamic relocs copied for this symbol.  */
  struct e2k_elf_dyn_relocs *dyn_relocs;

#define GOT_UNKNOWN     0
#define GOT_NORMAL      1
#define GOT_TLS_GDMOD   2
#define GOT_TLS_GDREL   4
#define GOT_TLS_IE      8
  char tls_type;

  union gotplt_union gdmod;

  /* This is used to account for IE-related GOT entries. We need a separate
     counter/offset field because a symbol may be accessed both via GD and IE
     model. FIXME: find out whether the scheme employing GLIST field in h->got
     can be used instead.  */
  union gotplt_union ie;

  /* Offset of the entry within '.got.plt'. Used together with the
     secondary PLT entry, but can remain alone if the corresponding function
     can be resolved locally and no secondary entry is actually needed.  */
  bfd_vma gotplt_offset;

  /* Information about the GOT PLT entry. Filled when there are both GOT and PLT
     relocations against the same function. Once it's set, both `plt.offset' and
     `secondary_plt.offset' should be set to `-1' since no one of them is needed
     any longer.  */
  union gotplt_union plt_got;

  char relgot_cntr;

  /* Set to 1 if this symbol's value should be set to its PLT offset once it
     can be determined reliably.  */
  char finalize_plt_offset;

  /* Whether this symbol is accessed via `R_E2K_AP_GOT' or `R_E2K_PL_GOT' in
     Protected Mode.  */
  char pm_got_type;
};

#define _bfd_e2k_elf_hash_entry(ent) ((struct _bfd_e2k_elf_link_hash_entry *)(ent))


struct plt_entry
{
  union
  {
    bfd_signed_vma refcount;
    bfd_vma idx;
  } primary, secondary;
};

static bool
positive_plt_refcount (struct elf_link_hash_entry *h)
{
  if (h->plt.plist == NULL)
    return false;

      BFD_ASSERT (h->plt.plist->secondary.refcount
                  >= h->plt.plist->primary.refcount);

  if (h->plt.plist->primary.refcount > 0)
    return true;

  return false;
}

static bool
positive_secondary_plt_refcount (struct elf_link_hash_entry *h)
{
  if (h->plt.plist == NULL)
    return false;

  if (h->plt.plist->secondary.refcount > 0)
    return true;

  return false;
}


static struct plt_entry *
make_plt_record (bfd *abfd)
{
  struct plt_entry *entry;

  entry = bfd_zalloc (abfd, sizeof (*entry));
  return entry;
}

/* Implementation of this one as well as of 'decrease_plt_refcount ()' which
   is not implemented yet requires additional consideration.  */
static void
decrease_secondary_plt_refcount (struct elf_link_hash_entry *h)
{
  if (h->plt.plist && h->plt.plist->secondary.refcount > 0)
    h->plt.plist->secondary.refcount -= 1;
}

static void
discard_plt_refcount (struct elf_link_hash_entry *h)
{
  BFD_ASSERT (h->plt.plist != NULL
              && h->plt.plist->primary.refcount > 0
              && (h->plt.plist->secondary.refcount
                  >= h->plt.plist->primary.refcount));

  h->plt.plist->secondary.refcount -= h->plt.plist->primary.refcount;
  h->plt.plist->primary.refcount = 0;
}

static bool
increase_secondary_plt_refcount (bfd *abfd, struct elf_link_hash_entry *h)
{
  if (h->plt.plist == NULL)
    h->plt.plist = make_plt_record (abfd);

  if (h->plt.plist == NULL)
    return false;

  h->plt.plist->secondary.refcount += 1;
  return true;
}


static bool
increase_plt_refcount (bfd *abfd, struct elf_link_hash_entry *h)
{
  if (! increase_secondary_plt_refcount (abfd, h))
    return false;

  h->plt.plist->primary.refcount += 1;
  return true;
}

static void
copy_plt_refcount (struct elf_link_hash_entry *dst,
                   struct elf_link_hash_entry *src)
{
  if (src->plt.plist == NULL
      || (src->plt.plist->primary.refcount == 0
          && src->plt.plist->secondary.refcount == 0))
    return;

  if (dst->plt.plist == NULL)
    dst->plt.plist = src->plt.plist;
  else
    {
      dst->plt.plist->primary.refcount += src->plt.plist->primary.refcount;
      dst->plt.plist->secondary.refcount += src->plt.plist->secondary.refcount;
    }
}

static bfd_vma
safe_plt_offset (bfd_vma off, bfd_vma idx, bfd_vma entry_size)
{
  if (! mcstbug_140436_workaround)
    return off + idx * entry_size;

  while (true)
    {
      bfd_vma pgoff = off & 0xfff;
      if (pgoff >= 0xdc0 && pgoff < 0xe00)
	off += 0xe00 - pgoff;

      if (idx == 0)
	break;

      pgoff = off & 0xfff;
      BFD_ASSERT (pgoff < 0xdc0 || pgoff >= 0xe00);

      bfd_vma lo = pgoff < 0xdc0 ? 0xdc0 : 0x1dc0;
      bfd_vma n = (lo - pgoff) / entry_size;

      if ((n * entry_size == lo - pgoff && idx < n)
	  || (n * entry_size != lo - pgoff && idx <= n))
	{
	  off += idx * entry_size;
	  break;
	}

      if (n * entry_size == lo - pgoff)
	{
	  idx -= n;
	  off += n * entry_size;
	}
      else
	{
	  idx -= n + 1;
	  off += (n + 1) * entry_size;
	}
    }

  return off;
}

static bfd_vma
secondary_plt_idx (struct elf_link_hash_entry *h)
{
  if (h->plt.plist == NULL)
    return (bfd_vma) -1;

  return h->plt.plist->secondary.idx;
}

/* This should be called only if `secondary_plt_idx ()' returns an index
   different from `-1'.  */
static bfd_vma
secondary_plt_offset (struct elf_link_hash_entry *h,
                      struct _bfd_e2k_elf_link_hash_table *htab)
{
  int idx;
  BFD_ASSERT (h->plt.plist && h->plt.plist->secondary.idx != (bfd_vma) -1);

  idx = h->plt.plist->secondary.idx;
  return safe_plt_offset (htab->plt_got_header_size, idx,
			  htab->plt_got_secondary_entry_size);
}

static bfd_vma
plt_idx (struct elf_link_hash_entry *h)
{
  if (h->plt.plist == NULL)
    return (bfd_vma) -1;

  return h->plt.plist->primary.idx;
}

/* This should be called only if `plt_idx ()' returns an index different
   from `-1'.  */
static bfd_vma
plt_offset (struct elf_link_hash_entry *h,
            struct _bfd_e2k_elf_link_hash_table *htab)
{
  int idx;
  BFD_ASSERT (h->plt.plist && h->plt.plist->primary.idx != (bfd_vma) -1);

  idx = h->plt.plist->primary.idx;
  bfd_vma off = htab->plt_got_header_size;

  if (htab->secondary_plt_num)
    off = (safe_plt_offset (off, htab->secondary_plt_num - 1,
			    htab->plt_got_secondary_entry_size)
	   + htab->plt_got_secondary_entry_size);

  off = safe_plt_offset (off, idx, htab->plt_got_primary_entry_size);
  return off;
}


/* Set the next available index for a secondary PLT entry. Pass NULL for HTAB
   to specify that it should be set to -1.  */
static void
set_secondary_plt_idx (struct elf_link_hash_entry *h,
                       struct _bfd_e2k_elf_link_hash_table *htab)
{
  if (h->plt.plist == NULL && htab == NULL)
    return;

  BFD_ASSERT (h->plt.plist != NULL
              && (h->plt.plist->secondary.refcount > 0
                  || htab == NULL));

  h->plt.plist->secondary.idx = htab ? htab->secondary_plt_num++ : (bfd_vma) -1;
}

/* Set the next available index for a primary PLT entry. Pass NULL for HTAB
   to specify that it should be set to -1.  */
static void
set_plt_idx (struct elf_link_hash_entry *h,
             struct _bfd_e2k_elf_link_hash_table *htab)
{
  if (h->plt.plist == NULL && htab == NULL)
    return;

  BFD_ASSERT (h->plt.plist != NULL
              && (h->plt.plist->primary.refcount > 0
                  || htab == NULL));

  h->plt.plist->primary.idx = htab ? htab->primary_plt_num++ : (bfd_vma) -1;
}



struct _bfd_e2k_elf_obj_tdata
{
  struct elf_obj_tdata root;

  union
  {
    bfd_signed_vma *refcounts;
    bfd_vma *offsets;
  } local_ie;

  /* tls_type for each local got entry.  */
  char *local_got_tls_type;

  /* How many .rela.got entries have been reserved for each local symbol.  */
  char *local_relgot_cntr;
};

#define _bfd_e2k_elf_tdata(abfd) \
  ((struct _bfd_e2k_elf_obj_tdata *) (abfd)->tdata.any)

#define _bfd_e2k_elf_local_ie_refcounts(abfd) \
  (_bfd_e2k_elf_tdata (abfd)->local_ie.refcounts)

#define _bfd_e2k_elf_local_ie_offsets(abfd) \
  (_bfd_e2k_elf_tdata (abfd)->local_ie.offsets)

#define _bfd_e2k_elf_local_got_tls_type(abfd) \
  (_bfd_e2k_elf_tdata (abfd)->local_got_tls_type)

#define _bfd_e2k_elf_local_relgot_cntr(abfd) \
  (_bfd_e2k_elf_tdata (abfd)->local_relgot_cntr)



static void
e2k_put_word_32 (bfd *abfd, bfd_vma val, void *ptr)
{
  bfd_put_32 (abfd, val, ptr);
}

static void
e2k_put_word_64 (bfd *abfd, bfd_vma val, void *ptr)
{
  bfd_put_64 (abfd, val, ptr);
}


static bfd_vma
e2k_elf_r_info_32 (bfd_vma rel_index, bfd_vma type)
{
  return ELF32_R_INFO (rel_index, type);
}

static bfd_vma
e2k_elf_r_info_64 (bfd_vma rel_index, bfd_vma type)
{
  return ELF64_R_INFO (rel_index, type);
}



/* Patterns of 32-bit PLT entries and headers relying on '.got.plt'.  */

static const unsigned int plt32_got_pic_header[] =
{
  /* 0000<000000000000> HS    */ 0x04100091, /* M_0: nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14500122, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x11111111 ], %r8  */
  /*                    ALS2  */ 0x6688d98a, /*  ldgdw,2 [ %r8 + _f32s,_lts1 0x22222222 ], %r10  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f08ad1, /*  getpl,0 %r10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f088d1, /*  getpl,0 %r8, %ctpr1  */
  /* 0005<000000000048> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

#define PLT32_GOT_PIC_HEADER_NOP_OFFSET  0x10
#define PLT32_GOT_PIC_LINK_MAP_LD_OFFSET 0x24
#define PLT32_GOT_PIC_DL_FIXUP_LD_OFFSET 0x20
#define PLT32_GOT_PIC_HEADER_SIZE sizeof (plt32_got_pic_header)


static const unsigned int plt32_elbrus_v7_got_pic_header[] =
{
  /* 0000<000000000000> HS    */ 0x04100091, /* M_0: nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14500122, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x11111111 ], %r8  */
  /*                    ALS2  */ 0x6688d98a, /*  ldgdw,2 [ %r8 + _f32s,_lts1 0x22222222 ], %r10  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f08ad1, /*  getpl,0 %r10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04101012, /* :  */
  /*                    SS    */ 0xc0000020, /*  ipd 3  */
  /*                    ALS0  */ 0x53c088df, /*  ibranchd,0 %dr8, %empty  */
  /*                    ALES  */ 0x01c00000,
};

#define PLT32_ELBRUS_V7_GOT_PIC_HEADER_NOP_OFFSET  0x10
#define PLT32_ELBRUS_V7_GOT_PIC_LINK_MAP_LD_OFFSET 0x24
#define PLT32_ELBRUS_V7_GOT_PIC_DL_FIXUP_LD_OFFSET 0x20
#define PLT32_ELBRUS_V7_GOT_PIC_HEADER_SIZE sizeof (plt32_elbrus_v7_got_pic_header)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT32_GOT_PIC_HEADER_SIZE == PLT32_ELBRUS_V7_GOT_PIC_HEADER_SIZE);


static const unsigned int plt32_got_non_pic_header[] =
{
  /*    0:	*/
  /* HS    */ 0x92400112,  /* nop 2  */
  /* ALS2  */ 0x66c0d888,  /* ldgdw,2 0x0, _f32s,_lts0 0x76543210, %dr8  */
  /* ALS5  */ 0x66c4d88a,  /* ldgdw,5 0x4, _f32s,_lts0 0x76543210, %dr10  */
  /* LTS0  */ 0x76543210,

  /*   10:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x63f08ad1,  /* getpl,0 %r10, %ctpr1  */

  /*   18:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,
  /*                          ipd 2  */
  /* CS1   */ 0x50000004,  /* call %ctpr1, wbs = 0x4  */
  /* LTS0  */ 0x00000000,

  /*   28:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x63f088d1,  /* getpl,0 %r8, %ctpr1  */

  /*   30:	*/
  /* HS    */ 0x00001001,
  /* SS    */ 0x80000420,  /* ct %ctpr1  */
  /*                          ipd 2  */
};

#define PLT32_GOT_NON_PIC_HEADER_NOP_OFFSET  0x0
#define PLT32_GOT_NON_PIC_LINK_MAP_LD_OFFSET 0xc
#define PLT32_GOT_NON_PIC_HEADER_SIZE sizeof (plt32_got_non_pic_header)

static const unsigned int plt32_elbrus_v7_got_non_pic_header[] =
{
  /*    0:	*/
  /* HS    */ 0x92400112,  /* nop 2  */
  /* ALS2  */ 0x66c0d888,  /* ldgdw,2 0x0, _f32s,_lts0 0x76543210, %dr8  */
  /* ALS5  */ 0x66c4d88a,  /* ldgdw,5 0x4, _f32s,_lts0 0x76543210, %dr10  */
  /* LTS0  */ 0x76543210,

  /*   10:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x63f08ad1,  /* getpl,0 %r10, %ctpr1  */

  /*   18:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,
  /*                          ipd 2  */
  /* CS1   */ 0x50000004,  /* call %ctpr1, wbs = 0x4  */
  /* LTS0  */ 0x00000000,

  /*   28:  */
  /* HS    */ 0x04101012,  /* :  */
  /* SS    */ 0xc0000020,  /*  ipd 3  */
  /* ALS0  */ 0x53c088df,  /*  ibranchd,0 %dr8, %empty  */
  /* ALES  */ 0x01c00000,
};

#define PLT32_ELBRUS_V7_GOT_NON_PIC_HEADER_NOP_OFFSET  0x0
#define PLT32_ELBRUS_V7_GOT_NON_PIC_LINK_MAP_LD_OFFSET 0xc
#define PLT32_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE sizeof (plt32_elbrus_v7_got_non_pic_header)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT32_GOT_NON_PIC_HEADER_SIZE == PLT32_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE);

static const unsigned int plt32_got_pic_primary_entry[] = 
{
  /* 0000<000000000000> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0001<000000000018> HS    */ 0x04100111, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x44444444 ], %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x44444444,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f088d1, /*  getpl,0 %r8, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

#define PLT32_GOT_PIC_ENTRY_NOP_OFFSET 0x18
#define PLT32_GOT_PIC_TARGET_LD_OFFSET 0x24
#define PLT32_GOT_PIC_PRIMARY_ENTRY_SIZE sizeof (plt32_got_pic_primary_entry)

static const unsigned int plt32_elbrus_v7_got_pic_primary_entry[] = 
{
  /* 0000<000000000000> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0001<000000000018> HS    */ 0x04100111, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x44444444 ], %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x44444444,
  /* 0002<000000000028> HS    */ 0x04101012, /* :  */
  /*                    SS    */ 0xc0000020, /*  ipd 3  */
  /*                    ALS0  */ 0x53c088df, /*  ibranchd,0 %dr8, %empty  */
  /*                    ALES  */ 0x01c00000,
};

#define PLT32_ELBRUS_V7_GOT_PIC_ENTRY_NOP_OFFSET 0x18
#define PLT32_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET 0x24
#define PLT32_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE sizeof (plt32_elbrus_v7_got_pic_primary_entry)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT32_GOT_PIC_TARGET_LD_OFFSET == PLT32_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET
		&& PLT32_GOT_PIC_PRIMARY_ENTRY_SIZE == PLT32_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE);


static const unsigned int plt32_got_non_pic_primary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x10408122,  /* nop 2  */
  /* ALS2  */ 0x66c0d988,  /* ldgdw,2 0x0, _f32s,_lts1 0x76543210, %dr8  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /*  18:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x63f088d1,  /* getpl,0 %r8, %ctpr1  */

  /*  20:	*/
  /* HS    */ 0x00001001,
  /* SS    */ 0x80000420,  /* ct %ctpr1  */
  /*                          ipd 2  */

};

#define PLT32_GOT_NON_PIC_ENTRY_NOP_OFFSET 0x0
#define PLT32_GOT_NON_PIC_TARGET_LD_OFFSET 0x10
#define PLT32_GOT_NON_PIC_PRIMARY_ENTRY_SIZE sizeof (plt32_got_non_pic_primary_entry)


static const unsigned int plt32_elbrus_v7_got_non_pic_primary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x10408122,  /* nop 2  */
  /* ALS2  */ 0x66c0d988,  /* ldgdw,2 0x0, _f32s,_lts1 0x76543210, %dr8  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /*   18:  */
  /* HS    */ 0x04101012,  /* :  */
  /* SS    */ 0xc0000020,  /*  ipd 3  */
  /* ALS0  */ 0x53c088df,  /*  ibranchd,0 %dr8, %empty  */
  /* ALES  */ 0x01c00000,
};

#define PLT32_ELBRUS_V7_GOT_NON_PIC_ENTRY_NOP_OFFSET 0x0
#define PLT32_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET 0x10
#define PLT32_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE sizeof (plt32_elbrus_v7_got_non_pic_primary_entry)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT32_GOT_NON_PIC_TARGET_LD_OFFSET == PLT32_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET
		&& PLT32_GOT_NON_PIC_PRIMARY_ENTRY_SIZE == PLT32_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE);

static void
build_plt_entry (struct bfd_link_info *info,
                 asection *splt,
                 bfd_vma offset,
                 bfd_vma gotplt_offset)
{
  bfd *output_bfd = info->output_bfd;
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);

  unsigned int i;
  bfd_vma slot_addr;
  asection *sgotplt = htab->elf.sgotplt;
  unsigned char *plt_literal =
    splt->contents + offset + htab->plt_got_target_ld_offset;

  /* Take into account that delay between load and its consumer has been
     increased from 3 to 5 ticks starting from elbrus-v6 (see MCSTBug #112004,
     Comment #8).  */
  unsigned long omach = bfd_get_mach (output_bfd);
  unsigned int nops = e2k_arch_info_mach_to_iset (omach) >= 6 ? 4 : 2;

  unsigned int hs_nop =
    htab->plt_got_primary_entry[htab->plt_got_entry_nop_offset / 4];



  for (i = 0; i < htab->plt_got_primary_entry_size / 4; i++)
    bfd_put_32 (output_bfd, htab->plt_got_primary_entry[i],
		(splt->contents + offset + 4 * i));

  /* Adjust HS.nop according to the aforesaid.  */
  hs_nop = (hs_nop & 0xfffffc7fu) | (nops << 7);
  bfd_put_32 (output_bfd, hs_nop,
	      (htab->elf.splt->contents
	       + offset
	       + htab->plt_got_entry_nop_offset));


  slot_addr = adjust_offset_in_cud_gd (info,
				       (sgotplt->output_section->vma
					+ sgotplt->output_offset
					+ gotplt_offset));

  if (! ABI_PM_P (htab->elf.dynobj) && bfd_link_pic (info))
    {
      /* Adjust primary PLT entry: write out 32-bit offset of the
	 corresponding '.got.plt' slot relative to it. It's involved in
	 `ld{,gd}w [%r8 == primary_entry_pc + CALCULATED_OFFSET], %r8'.  */
      bfd_put_32 (output_bfd,
		  (slot_addr
		   - (splt->output_section->vma
		      + splt->output_offset
		      + offset)),
		  plt_literal);
    }
  else
    {
      /* In non-PIC case it's just enough to encode the address of the
	 related '.got.plt' slot into PLT entry as a literal of an
	 appropriate size.  */
      if (ABI_64_P (output_bfd))
	{
	  bfd_put_32 (output_bfd, slot_addr >> 32, plt_literal);
	  plt_literal += 4;
	}

      bfd_put_32 (output_bfd, slot_addr & 0xffffffff, plt_literal);

      if (ABI_PM_P (output_bfd)
	  && e2k_arch_info_mach_to_iset (bfd_get_mach (output_bfd)) >= 7)
	{
	  /* FIXME: consider adjusting PLT128_GOT_TARGET_LD_OFFSET in PM so
	     as to re-use the above 64-bit specific code instead of doing the
	     following ...  */
	  /* FIXME (?): does it actually make any sense to rework .got accesses
	     from .plt by analogy with "regular" code, i.e. via a 32-bit offset
	     from the base of .got evaluated on a subsidiary register? Whereas
	     in "regular" compiler generated code the evaluation of such a
	     register could be shared among multiple accesses, within a .plt
	     entry it would require more space than migration from a 64-bit
	     "absolute" offset  to a 32-bit "relative" one would save.  */
	  bfd_put_32 (output_bfd, slot_addr >> 32, plt_literal - 4);
	}
    }

  /* Relocation offset cannot be encoded within this function because unlike
     e.g. Sparc we don't have a trivial correspondence between an index of
     an entry in `.plt' and that of the corresponding relocation in
     `.rela.plt'  */
}

static void
build_secondary_plt_entry (struct bfd_link_info *info,
                           bfd_vma offset,
                           bfd_vma gotplt_offset,
                           bfd_vma *r_offset
#if 0
                           , const char *name
#endif
			   )
{
  unsigned int i;
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);
  bfd *output_bfd = info->output_bfd;
  asection *splt = htab->elf.splt;
  asection *sgotplt = htab->elf.sgotplt;

  /* Set R_OFFSET of the run-time relocation which is to fix the above
     '.got.plt' slot.  */
  *r_offset = (sgotplt->output_section->vma + sgotplt->output_offset
               + gotplt_offset);

  if (htab->plt_got_secondary_entry_size == 0)
    return;

  for (i = 0; i < htab->plt_got_secondary_entry_size / 4; i++)
    bfd_put_32 (output_bfd, htab->plt_got_secondary_entry[i],
                splt->contents + offset + 4 * i);

  /* Adjust secondary PLT entry: write out CS0 syllable of "ibranch to PLT
     header". It seems to be the same both in 32  and 64-bit mode.  */
  bfd_put_32 (output_bfd, (((unsigned int) -offset) >> 3) & 0x0fffffff,
              splt->contents + offset + htab->plt_got_disp_offset);

  /* Adjust the corresponding `.got.plt' slot, which is to be lazily
     relocated at run-time. Initially it should be set to the link-time
     address of the just created secondary PLT entry.  */
  htab->put_word (output_bfd,
		  splt->output_section->vma + splt->output_offset + offset,
		  sgotplt->contents + gotplt_offset);
}

/* FIXME: this function is to be unified with its 64-bit counterpart.  */
static void
e2k32_plt_lazy_entry_adjust_reloc_offset (bfd *output_bfd,
                                          struct _bfd_e2k_elf_link_hash_table *htab,
                                          asection *splt,
                                          bfd_vma offset,
                                          bfd_vma dynrel_offset)
{

  /* Adjust secondary PLT entry: write out the corresponding 32-bit offset
     within `.rela.plt', which is the second parameter of `_dl_fixup ().  */
  bfd_put_32 (output_bfd, dynrel_offset,
	      splt->contents + offset + htab->plt_got_reloc_arg_offset);
}


static const unsigned int plt64_got_pic_header[] = 
{
  /* 0000<000000000000> HS    */ 0x04100091, /* header: nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14000122, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x11111111 ], %dr8  */
  /*                    ALS2  */ 0x6788d98a, /*  ldd,2 [ %dr8 + _f32s,_lts1 0x22222222 ], %dr10  */
  /*                    LTS2  */ 0x00000000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c08ad1, /*  movtd,0 %dr10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c088d1, /*  movtd,0 %dr8, %ctpr1  */
  /* 0005<000000000048> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */

};

#define PLT64_GOT_PIC_HEADER_NOP_OFFSET	 0x10
#define PLT64_GOT_PIC_LINK_MAP_LD_OFFSET 0x24
#define PLT64_GOT_PIC_DL_FIXUP_LD_OFFSET 0x20
#define PLT64_GOT_PIC_HEADER_SIZE sizeof (plt64_got_pic_header)

static const unsigned int plt64_elbrus_v7_got_pic_header[] = 
{
  /* 0000<000000000000> HS    */ 0x04100091, /* header: nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14000122, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x11111111 ], %dr8  */
  /*                    ALS2  */ 0x6788d98a, /*  ldd,2 [ %dr8 + _f32s,_lts1 0x22222222 ], %dr10  */
  /*                    LTS2  */ 0x00000000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c08ad1, /*  movtd,0 %dr10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04101012, /* :  */
  /*                    SS    */ 0xc0000020, /*  ipd 3  */
  /*                    ALS0  */ 0x53c088df, /*  ibranchd,0 %dr8, %empty  */
  /*                    ALES  */ 0x01c00000,
};

#define PLT64_ELBRUS_V7_GOT_PIC_HEADER_NOP_OFFSET 0x10
#define PLT64_ELBRUS_V7_GOT_PIC_LINK_MAP_LD_OFFSET 0x24
#define PLT64_ELBRUS_V7_GOT_PIC_DL_FIXUP_LD_OFFSET 0x20
#define PLT64_ELBRUS_V7_GOT_PIC_HEADER_SIZE sizeof (plt64_elbrus_v7_got_pic_header)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT64_GOT_PIC_HEADER_SIZE == PLT64_ELBRUS_V7_GOT_PIC_HEADER_SIZE);


static const unsigned int plt64_got_non_pic_header[] = 
{
  /*   0:	*/
  /* HS    */ 0x14000122,  /* nop 2  */
  /* ALS0  */ 0x67c0dc88,  /* ldd,0 0x0, _f64,_lts0 0xfedcba9876543210, %dr8  */
  /* ALS2  */ 0x67c8dc8a,  /* ldd,2 0x8, _f64,_lts0 0xfedcba9876543210, %dr10  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0xfedcba98,
  /* LTS0  */ 0x76543210,

  /*  18:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x61c08ad1,  /* movtd,0 %dr10, %ctpr1  */

  /*  20:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ 0x50000004,  /* call %ctpr1, wbs = 0x4  */
  /* LTS0  */ 0x00000000,

  /*  30:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x61c088d1,  /* movtd,0 %dr8, %ctpr1  */

  /*  38:	*/
  /* HS    */ 0x00001001,
  /* SS    */ 0x80000420,  /* ct %ctpr1  */
  /*                          ipd 2  */

};

#define PLT64_GOT_NON_PIC_HEADER_NOP_OFFSET  0x0
#define PLT64_GOT_NON_PIC_LINK_MAP_LD_OFFSET 0x10
#define PLT64_GOT_NON_PIC_HEADER_SIZE sizeof (plt64_got_non_pic_header)


static const unsigned int plt64_elbrus_v7_got_non_pic_header[] = 
{
  /*   0:	*/
  /* HS    */ 0x14000122,  /* nop 2  */
  /* ALS0  */ 0x67c0dc88,  /* ldd,0 0x0, _f64,_lts0 0xfedcba9876543210, %dr8  */
  /* ALS2  */ 0x67c8dc8a,  /* ldd,2 0x8, _f64,_lts0 0xfedcba9876543210, %dr10  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0xfedcba98,
  /* LTS0  */ 0x76543210,

  /*  18:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x61c08ad1,  /* movtd,0 %dr10, %ctpr1  */

  /*  20:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ 0x50000004,  /* call %ctpr1, wbs = 0x4  */
  /* LTS0  */ 0x00000000,

  /*  30:  */
  /* HS    */ 0x04101012,  /* :  */
  /* SS    */ 0xc0000020,  /*  ipd 3  */
  /* ALS0  */ 0x53c088df,  /*  ibranchd,0 %dr8, %empty  */
  /* ALES  */ 0x01c00000,
};

#define PLT64_ELBRUS_V7_GOT_NON_PIC_HEADER_NOP_OFFSET  0x0
#define PLT64_ELBRUS_V7_GOT_NON_PIC_LINK_MAP_LD_OFFSET 0x10
#define PLT64_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE sizeof (plt64_elbrus_v7_got_non_pic_header)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT64_GOT_NON_PIC_HEADER_SIZE == PLT64_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE);


static const unsigned int plt64_got_pic_primary_entry[] = 
{
  /* 0000<000000000000> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0001<000000000018> HS    */ 0x04000111, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x44444444 ], %dr8  */
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x44444444,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c088d1, /*  movtd,0 %dr8, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

#define PLT64_GOT_PIC_ENTRY_NOP_OFFSET	    0x18
#define PLT64_GOT_PIC_TARGET_LD_OFFSET      0x24
#define PLT64_GOT_PIC_PRIMARY_ENTRY_SIZE    sizeof (plt64_got_pic_primary_entry)

static const unsigned int plt64_elbrus_v7_got_pic_primary_entry[] = 
{
  /* 0000<000000000000> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0001<000000000018> HS    */ 0x04000111, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x44444444 ], %dr8  */
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x44444444,
  /* 0002<000000000028> HS    */ 0x04101012, /* :  */
  /*                    SS    */ 0xc0000020, /*  ipd 3  */
  /*                    ALS0  */ 0x53c088df, /*  ibranchd,0 %dr8, %empty  */
  /*                    ALES  */ 0x01c00000,
};

#define PLT64_ELBRUS_V7_GOT_PIC_ENTRY_NOP_OFFSET      0x18
#define PLT64_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET      0x24
#define PLT64_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE    sizeof (plt64_elbrus_v7_got_pic_primary_entry)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT64_GOT_PIC_TARGET_LD_OFFSET == PLT64_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET
		&& PLT64_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE == PLT64_GOT_PIC_PRIMARY_ENTRY_SIZE);


static const unsigned int plt64_got_non_pic_primary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x04008122,  /* nop 2  */
  /* ALS0  */ 0x67c0dd88,  /* ldd,0 0x0, _f64,_lts1 0xfedcba9876543210, %dr8  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0xfedcba98,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /*  18:	*/
  /* HS    */ 0x04000001,
  /* ALS0  */ 0x61c088d1,  /* movtd,0 %dr8, %ctpr1  */

  /*  20:	*/
  /* HS    */ 0x00001001,
  /* SS    */ 0x80000420,  /* ct %ctpr1  */
  /*                          ipd 2  */

};

#define PLT64_GOT_NON_PIC_ENTRY_NOP_OFFSET	0x0
#define PLT64_GOT_NON_PIC_TARGET_LD_OFFSET      0xc
#define PLT64_GOT_NON_PIC_PRIMARY_ENTRY_SIZE    sizeof (plt64_got_non_pic_primary_entry)


static const unsigned int plt64_elbrus_v7_got_non_pic_primary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x04008122,  /* nop 2  */
  /* ALS0  */ 0x67c0dd88,  /* ldd,0 0x0, _f64,_lts1 0xfedcba9876543210, %dr8  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0xfedcba98,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /*  18:	*/
  /* HS    */ 0x04101012,  /* :  */
  /* SS    */ 0xc0000020,  /*  ipd 3  */
  /* ALS0  */ 0x53c088df,  /*  ibranchd,0 %dr8, %empty  */
  /* ALES  */ 0x01c00000,
};

#define PLT64_ELBRUS_V7_GOT_NON_PIC_ENTRY_NOP_OFFSET	0x0
#define PLT64_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET	0xc
#define PLT64_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE	sizeof (plt64_elbrus_v7_got_non_pic_primary_entry)

/* To let _bfd_e2k_elf_plt_sym_val () remain workable both in elbrus-v{X<7} and
   elbrus-v7 cases without a change, it's crucial that the following parameters
   have the same values in these two implementations.  */
_Static_assert (PLT64_GOT_NON_PIC_TARGET_LD_OFFSET == PLT64_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET
		&& PLT64_GOT_NON_PIC_PRIMARY_ENTRY_SIZE == PLT64_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE);


#define MOVTD_TARGET(ind)						\
  /* HS    */ 0x04000001,						\
  /* ALS0  */ (0x61c080d1 | (ind << 8))  /* movtd,0 %dr{ind}, %ctpr1  */

#define LOAD_LINK_MAP_DL_FIXUP(reg1, reg2)				\
  /* HS    */ 0xb6d00034,						\
    /* ALS0  */ (0x79c0d880 | reg1),  /* ldgdq,0 0x0, _f32s,_lts0 0x12345678, %qr{reg1}  */ \
    /* ALS2  */ (0x79c0d880 | (reg1 + 1)),				\
    /* ALS3  */ (0x79d0d880 | reg2),  /* ldgdq,3 0x10, _f32s,_lts0 0x12345678, %qr{reg2}  */ \
    /* ALS5  */ (0x79d0d880 | (reg2 + 1)),				\
    /* ALES03*/ 0x01c001c0,						\
    /* LTS1  */ 0x00000000,						\
    /* LTS0  */ 0x12345678

#define MOVTQ_PAIR(src, dst)						\
  /* HS    */ 0x6db00034,						\
  /* ALS0  */ (0x57c08080 | ((src + 0) << 8) | (dst + 0)),  /* movtq,0 %qr{src}, %qr{dst}  */ \
  /* ALS1  */ (0x57c08080 | ((src + 1) << 8) | (dst + 1)),		\
  /* ALS3  */ (0x57c08080 | ((src + 2) << 8) | (dst + 2)),  /* movtq,3 %qr{src+2}, %qr{dst+2}  */ \
  /* ALS4  */ (0x57c08080 | ((src + 3) << 8) | (dst + 3)),		\
  /* ALES  */ 0x01c001c0,						\
  /* ALES  */ 0x01c001c0,						\
  /* LTS0  */ 0x00000000



#define CALL_WBS(wbs)							\
  /* CS1   */ (0x50000000 | wbs)  /* call %ctpr1, wbs = wbs  */


static const unsigned int plt128_got_header[] = 
{
  LOAD_LINK_MAP_DL_FIXUP (
#ifndef NEW_PM_ABI
			  10, 14
#else /* defined NEW_PM_ABI  */
			  18, 22
#endif
			  ),

  MOVTD_TARGET(
#ifndef NEW_PM_ABI
	       14
#else /* defined NEW_PM_ABI  */
	       22
#endif /* defined NEW_PM_ABI  */
	       ),

  /*  28:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (
#ifndef NEW_PM_ABI
			0x4
#else /* defined NEW_PM_ABI  */
			0x8
#endif /* defined NEW_PM_ABI  */
			),
  /* LTS0  */ 0x00000000,

  MOVTD_TARGET (
#ifndef NEW_PM_ABI
		8
#else /* defined NEW_PM_ABI  */
		16
#endif /* defined NEW_PM_ABI  */
		),
		
#ifndef NEW_PM_ABI
  MOVTQ_PAIR (0, 8),
  MOVTQ_PAIR (4, 12),
#else /* defined NEW_PM_ABI  */
  MOVTQ_PAIR (0, 16),
  MOVTQ_PAIR (4, 20),
  MOVTQ_PAIR (8, 24),
  MOVTQ_PAIR (12, 28),
#endif /* defined NEW_PM_ABI  */

  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (
#ifndef NEW_PM_ABI
			0x4
#else /* defined NEW_PM_ABI  */
			0x8
#endif /* defined NEW_PM_ABI  */
			),			
  /* LTS0  */ 0x00000000,

  /* HS    */ 0x00004001,
  /* CS0   */ 0xf0000000,  /* return %ctpr3  */

#ifndef NEW_PM_ABI
  MOVTQ_PAIR (8, 0),
  MOVTQ_PAIR (12, 4),
#else /* defined NEW_PM_ABI  */
  MOVTQ_PAIR (16, 0),
  MOVTQ_PAIR (20, 4),
  MOVTQ_PAIR (24, 8),
  MOVTQ_PAIR (28, 12),
#endif /* defined NEW_PM_ABI  */

  /* HS    */ 0x00001001,
  /* SS    */ 0x80000c20,  /* ct %ctpr3  */
  /*                          ipd 2  */

};

#define PLT128_GOT_HEADER_NOP_OFFSET  0x0
#define PLT128_GOT_LINK_MAP_LD_OFFSET 0x1c
#define PLT128_GOT_HEADER_SIZE sizeof (plt128_got_header);

/* TODO: migrate to a 64-bit offset (i.e. _f32s,_lts1 --> _f64,_lts1) in GD
   on elbrus-v7.  */
#define LOAD_TARGET(ind)						\
  /* ALS0  */ (0x79c0d980 | ind),  /* ldgdq,0 0x0, _f32s,_lts1 0x0, %qr{ind}  */ \
  /* ALS2  */ (0x79c0d980 | (ind + 1))

#define WSZ(wsz) \
  /* LTS0  */ (0x00000010 | (wsz << 5))

static const unsigned int plt128_got_primary_entry[] = 
{
  /*   0:  */
  /* HS    */ 0x14508033,
  /* ALS{0,2} */ LOAD_TARGET (
#ifndef NEW_PM_ABI
			   8
#else /* defined NEW_PM_ABI  */
			   16
#endif /* defined NEW_PM_ABI  */
			      ),
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x{8,10}, nfx = 0x1  */
  /* ALES0 */ 0x01c00000,
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x00000000,
  /* LTS0  */ WSZ (
#ifndef NEW_PM_ABI
		   0x8
#else /* defined NEW_PM_ABI  */
		   0x10
#endif /* defined NEW_PM_ABI  */
		   ),

#ifndef NEW_PM_ABI
  MOVTD_TARGET (8),
  MOVTQ_PAIR (0, 8),
  MOVTQ_PAIR (4, 12),
#else  /* defined NEW_PM_ABI  */
  MOVTD_TARGET (16),
  MOVTQ_PAIR (0, 16),
  MOVTQ_PAIR (4, 20),
  MOVTQ_PAIR (8, 24),
  MOVTQ_PAIR (12, 28),
#endif /* defined NEW_PM_ABI  */

  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (
#ifndef NEW_PM_ABI
			0x4
#else /* defined NEW_PM_ABI  */
			0x8
#endif /* defined NEW_PM_ABI  */
			),
  /* LTS0  */ 0x00000000,

  /* HS    */ 0x00005012,
  /* SS    */ 0x80000000,  /* ipd 2  */
  /* CS0   */ 0xf0000000,  /* return %ctpr3  */
  /* LTS0  */ 0x00000000,

#ifndef NEW_PM_ABI
  MOVTQ_PAIR (8, 0),
  MOVTQ_PAIR (12, 4),
#else /* defined NEW_PM_ABI  */
  MOVTQ_PAIR (16, 0),
  MOVTQ_PAIR (20, 4),
  MOVTQ_PAIR (24, 8),
  MOVTQ_PAIR (28, 12),
#endif /* defined NEW_PM_ABI  */

  /* HS    */ 0x00001001,
  /* SS    */ 0x80000c20,  /* ct %ctpr3  */
  /*                          ipd 2  */
};

#define PLT128_GOT_ENTRY_NOP_OFFSET	 0x0
#define PLT128_GOT_TARGET_LD_OFFSET      0x18
#define PLT128_GOT_PRIMARY_ENTRY_SIZE    sizeof (plt128_got_primary_entry)


#define RELOC_ARG(ind)							\
  /* ALS0  */ (0x10c0d980 | ind)  /* adds,0 0x0, _f32s,_lts1 0x12345678, %r{ind}  */

static const unsigned int plt128_got_secondary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x0400d034,
  /* SS    */ 0x80000020,  /* ipd 2  */
  /* ALS0  */ RELOC_ARG (
#ifndef NEW_PM_ABI
			 12
#else /* defined NEW_PM_ABI  */
			 20
#endif /* defined NEW_PM_ABI  */
			 ),
  /* CS0   */ 0x00000000,  /* ibranch 0x0  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x{8,10}, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x12345678,
  /* LTS0  */ WSZ (
#ifndef NEW_PM_ABI
		   0x8
#else /* defined NEW_PM_ABI  */
		   0x10
#endif /* defined NEW_PM_ABI  */
		   )
};

#define PLT128_GOT_DISP_OFFSET		0xc
#define PLT128_GOT_RELOC_ARG_OFFSET	0x18
#define PLT128_GOT_SECONDARY_ENTRY_SIZE sizeof (plt128_got_secondary_entry)





static const unsigned int plt_got_secondary_entry[] = 
{
  /*   0:	*/
  /* HS    */ 0x0400d034,
  /* SS    */ 0x80000020,  /* ipd 2  */
  /* ALS0  */ 0x11c0d989,  /* addd,0 0x0, _f32s,_lts1 0x76543210, %r9  */
  /* CS0   */ 0x00000000,  /* ibranch 0x0  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

};

#define PLT_GOT_DISP_OFFSET 0xc
#define PLT_GOT_RELOC_ARG_OFFSET 0x18
#define PLT_GOT_SECONDARY_ENTRY_SIZE sizeof (plt_got_secondary_entry)





static void
e2k64_plt_lazy_entry_adjust_reloc_offset (bfd *output_bfd,
                                          struct _bfd_e2k_elf_link_hash_table *htab,
                                          asection *splt,
                                          bfd_vma offset,
                                          bfd_vma dynrel_offset)
{
  /* Adjust secondary PLT entry: write out the corresponding 32-bit offset
     within `.rela.plt', which is the second parameter of `_dl_fixup ().  */
  bfd_put_32 (output_bfd, dynrel_offset,
	      splt->contents + offset + htab->plt_got_reloc_arg_offset);
}



/* Create an entry in an E2k ELF linker hash table.  */

static struct bfd_hash_entry *
_bfd_e2k_elf_link_hash_newfunc (struct bfd_hash_entry *entry,
                                struct bfd_hash_table *table,
                                const char *string)
{
  /* Allocate the structure if it has not already been allocated by a
     subclass.  */
  if (entry == NULL)
    {
      entry = bfd_hash_allocate (table,
				 sizeof (struct _bfd_e2k_elf_link_hash_entry));
      if (entry == NULL)
	return entry;
    }

  /* Call the allocation method of the superclass.  */
  entry = _bfd_elf_link_hash_newfunc (entry, table, string);
  if (entry != NULL)
    {
      struct elf_link_hash_table *htab = (struct elf_link_hash_table *) table;
      struct _bfd_e2k_elf_link_hash_entry *eh;

      eh = (struct _bfd_e2k_elf_link_hash_entry *) entry;
      eh->dyn_relocs = NULL;
      eh->tls_type = GOT_UNKNOWN;
      eh->gdmod = htab->init_got_refcount;
      eh->ie = htab->init_got_refcount;
      eh->gotplt_offset = (bfd_vma) -1;
      eh->plt_got = htab->init_got_refcount;

      /* Initially there are no .rela.got relocs required for this symbol.  */
      eh->relgot_cntr = 0;
      eh->finalize_plt_offset = 0;

      eh->pm_got_type = 0;
    }

  return entry;
}

static void
_bfd_e2k_elf_link_hash_table_finalize (struct bfd_link_info *info)
{
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);
  BFD_ASSERT (htab != NULL);
  unsigned long omach = bfd_get_mach (info->output_bfd);
  unsigned long iset = e2k_arch_info_mach_to_iset (omach);

  /* Setup members related to the latest PLT implementation making use of
     '.got.plt'.  */
  if (ABI_64_P (info->output_bfd))
    {
      if (bfd_link_pic (info))
        {
	  if (iset < 7 || plt_via_movtd_ct)
	    {
	      htab->plt_got_header = plt64_got_pic_header;
	      htab->plt_got_header_nop_offset = PLT64_GOT_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset = PLT64_GOT_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_dl_fixup_ld_offset = PLT64_GOT_PIC_DL_FIXUP_LD_OFFSET;
	      htab->plt_got_header_size = PLT64_GOT_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt64_got_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT64_GOT_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT64_GOT_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size = PLT64_GOT_PIC_PRIMARY_ENTRY_SIZE;
	    }
	  else /* iset >= 7 && ! plt_via_movtd_ct  */
	    {
	      htab->plt_got_header = plt64_elbrus_v7_got_pic_header;
	      htab->plt_got_header_nop_offset = PLT64_ELBRUS_V7_GOT_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset = PLT64_ELBRUS_V7_GOT_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_dl_fixup_ld_offset = PLT64_ELBRUS_V7_GOT_PIC_DL_FIXUP_LD_OFFSET;
	      htab->plt_got_header_size = PLT64_ELBRUS_V7_GOT_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt64_elbrus_v7_got_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT64_ELBRUS_V7_GOT_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT64_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size = PLT64_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE;
	    }
	}
      else
	{
	  if (iset < 7 || plt_via_movtd_ct)
	    {
	      htab->plt_got_header = plt64_got_non_pic_header;
	      htab->plt_got_header_nop_offset = PLT64_GOT_NON_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset =
		PLT64_GOT_NON_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_header_size = PLT64_GOT_NON_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt64_got_non_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT64_GOT_NON_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT64_GOT_NON_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size =
		PLT64_GOT_NON_PIC_PRIMARY_ENTRY_SIZE;
	    }
	  else /* iset >= 7 && ! plt_via_movtd_ct  */
	    {
	      htab->plt_got_header = plt64_elbrus_v7_got_non_pic_header;
	      htab->plt_got_header_nop_offset = PLT64_ELBRUS_V7_GOT_NON_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset =
		PLT64_ELBRUS_V7_GOT_NON_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_header_size = PLT64_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt64_elbrus_v7_got_non_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT64_ELBRUS_V7_GOT_NON_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT64_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size =
		PLT64_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE;
	    }
        }
    }
  else if (! ABI_PM_P (info->output_bfd))
    {
      if (bfd_link_pic (info))
        {
	  if (iset < 7 || plt_via_movtd_ct)
	    {
	      htab->plt_got_header = plt32_got_pic_header;
	      htab->plt_got_header_nop_offset = PLT32_GOT_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset = PLT32_GOT_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_dl_fixup_ld_offset = PLT32_GOT_PIC_DL_FIXUP_LD_OFFSET;
	      htab->plt_got_header_size = PLT32_GOT_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt32_got_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT32_GOT_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT32_GOT_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size = PLT32_GOT_PIC_PRIMARY_ENTRY_SIZE;
	    }
	  else /* iset >= 7 && ! plt_via_movtd_ct  */
	    {
	      htab->plt_got_header = plt32_elbrus_v7_got_pic_header;
	      htab->plt_got_header_nop_offset = PLT32_ELBRUS_V7_GOT_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset = PLT32_ELBRUS_V7_GOT_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_dl_fixup_ld_offset = PLT32_ELBRUS_V7_GOT_PIC_DL_FIXUP_LD_OFFSET;
	      htab->plt_got_header_size = PLT32_ELBRUS_V7_GOT_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt32_elbrus_v7_got_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT32_ELBRUS_V7_GOT_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT32_ELBRUS_V7_GOT_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size = PLT32_ELBRUS_V7_GOT_PIC_PRIMARY_ENTRY_SIZE;
	    }
        }
      else
        {
	  if (iset < 7 || plt_via_movtd_ct)
	    {
	      htab->plt_got_header = plt32_got_non_pic_header;
	      htab->plt_got_header_nop_offset = PLT32_GOT_NON_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset =
		PLT32_GOT_NON_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_header_size = PLT32_GOT_NON_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt32_got_non_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT32_GOT_NON_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT32_GOT_NON_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size =
		PLT32_GOT_NON_PIC_PRIMARY_ENTRY_SIZE;
	    }
	  else /* iset >= 7 && ! plt_via_movtd_ct  */
	    {
	      htab->plt_got_header = plt32_elbrus_v7_got_non_pic_header;
	      htab->plt_got_header_nop_offset = PLT32_ELBRUS_V7_GOT_NON_PIC_HEADER_NOP_OFFSET;
	      htab->plt_got_link_map_ld_offset =
		PLT32_ELBRUS_V7_GOT_NON_PIC_LINK_MAP_LD_OFFSET;
	      htab->plt_got_header_size = PLT32_ELBRUS_V7_GOT_NON_PIC_HEADER_SIZE;

	      htab->plt_got_primary_entry = plt32_elbrus_v7_got_non_pic_primary_entry;
	      htab->plt_got_entry_nop_offset = PLT32_ELBRUS_V7_GOT_NON_PIC_ENTRY_NOP_OFFSET;
	      htab->plt_got_target_ld_offset = PLT32_ELBRUS_V7_GOT_NON_PIC_TARGET_LD_OFFSET;
	      htab->plt_got_primary_entry_size =
		PLT32_ELBRUS_V7_GOT_NON_PIC_PRIMARY_ENTRY_SIZE;
	    }
        }
    }

  if (! ABI_PM_P (htab->elf.dynobj))
    {
      /* This one could be set in `_bfd_e2k_elf_link_hash_table_create ()' since
	 the secondary entry is common in all modes. We setup it here just for
	 "symmetry".  */
      htab->plt_got_secondary_entry = plt_got_secondary_entry;
      htab->plt_got_reloc_arg_offset = PLT_GOT_RELOC_ARG_OFFSET;
      htab->plt_got_disp_offset = PLT_GOT_DISP_OFFSET;
      htab->plt_got_secondary_entry_size = PLT_GOT_SECONDARY_ENTRY_SIZE;
    }
    else /* if (ABI_PM_P (info->output_bfd))  */
    {
      htab->plt_got_header = plt128_got_header;
      htab->plt_got_header_nop_offset = PLT128_GOT_HEADER_NOP_OFFSET;
      htab->plt_got_link_map_ld_offset = PLT128_GOT_LINK_MAP_LD_OFFSET;
      htab->plt_got_header_size = PLT128_GOT_HEADER_SIZE;

      htab->plt_got_primary_entry = plt128_got_primary_entry;
      htab->plt_got_entry_nop_offset = PLT128_GOT_ENTRY_NOP_OFFSET;
      htab->plt_got_target_ld_offset = PLT128_GOT_TARGET_LD_OFFSET;
      htab->plt_got_primary_entry_size = PLT128_GOT_PRIMARY_ENTRY_SIZE;

      htab->plt_got_secondary_entry = plt128_got_secondary_entry;
      htab->plt_got_reloc_arg_offset = PLT128_GOT_RELOC_ARG_OFFSET;
      htab->plt_got_disp_offset = PLT128_GOT_DISP_OFFSET;
      htab->plt_got_secondary_entry_size = PLT128_GOT_SECONDARY_ENTRY_SIZE;
    }


}

/* Ancient "semantics" values for 32 and 64-bit ABIs. We don't think
   that it makes sense to make them public via `include/elf/e2k.h'.
   Let them exist here hidden from the outside World.  */
#define E2K_MPTR_32        1
#define E2K_MPTR_64        2



/* Create E2K ELF linker hash table.  */

struct bfd_link_hash_table *
_bfd_e2k_elf_link_hash_table_create (bfd *abfd)
{
  struct _bfd_e2k_elf_link_hash_table *ret;
  bfd_size_type amt = sizeof (struct _bfd_e2k_elf_link_hash_table);

  ret = (struct _bfd_e2k_elf_link_hash_table *) bfd_zmalloc (amt);
  if (ret == NULL)
    return NULL;

  /* FIXME: this is a bit of a duplication of _bfd_e2k_elf_init_file_header_1
     () which is likely to be called after all input files have been opened
     which is too late for ABI_{64,PM}_P (OUTPUT_BFD) to work properly in all
     places of interest.  */
  if (abfd->arch_info->mach % 4 == 2)
    elf_elfheader (abfd)->e_flags |= EF_E2K_PM;


  if (ELF64_P (abfd))
    {
      ret->r_info = e2k_elf_r_info_64;
      ret->bytes_per_sym = sizeof (Elf64_External_Sym);
      ret->bytes_per_rela = sizeof (Elf64_External_Rela);

      ret->ancient_semantics = E2K_MPTR_64;
    }
  else
    {
      ret->r_info = e2k_elf_r_info_32;
      ret->bytes_per_sym = sizeof (Elf32_External_Sym);
      ret->bytes_per_rela = sizeof (Elf32_External_Rela);

      ret->ancient_semantics = E2K_MPTR_32;
    }

  if (ABI_64_P (abfd))
    {
      ret->put_word = e2k_put_word_64;
      ret->adjust_plt_lazy_entry_reloc_offset
        = e2k64_plt_lazy_entry_adjust_reloc_offset;
      ret->word_align_power = 3;
      ret->bytes_per_word = 8;

      ret->abs_reloc = R_E2K_64_ABS;
      ret->abs_lit_reloc = R_E2K_64_ABS_LIT;
      ret->copy_reloc = R_E2K_64_COPY;
      ret->relative_reloc = R_E2K_64_RELATIVE;
      ret->relative_lit_reloc = R_E2K_64_RELATIVE_LIT;
      ret->dtpmod_reloc = R_E2K_TLS_64_DTPMOD;
      ret->dtpoff_reloc = R_E2K_TLS_64_DTPREL;
      ret->tpoff_reloc = R_E2K_TLS_TPOFF64;
      ret->jmp_slot_reloc = R_E2K_64_JMP_SLOT;
      ret->irelative_reloc = R_E2K_64_IRELATIVE;
    }
  else
    {
      ret->put_word = ! ABI_PM_P (abfd) ? e2k_put_word_32 : e2k_put_word_64;
      ret->adjust_plt_lazy_entry_reloc_offset
        = e2k32_plt_lazy_entry_adjust_reloc_offset;
      ret->word_align_power = 2;
      ret->bytes_per_word = 4;

      ret->abs_reloc = R_E2K_32_ABS;
      ret->abs_lit_reloc = R_E2K_32_ABS;
      ret->copy_reloc = R_E2K_32_COPY;
      ret->relative_reloc = R_E2K_32_RELATIVE;
      ret->relative_lit_reloc = R_E2K_32_RELATIVE;
      ret->dtpmod_reloc = R_E2K_TLS_32_DTPMOD;
      ret->dtpoff_reloc = R_E2K_TLS_32_DTPREL;
      ret->tpoff_reloc = R_E2K_TLS_TPOFF32;
      ret->jmp_slot_reloc = R_E2K_32_JMP_SLOT;
      ret->irelative_reloc = R_E2K_32_IRELATIVE;
    }

  ret->gdmod_zero_off = (bfd_vma) -1;

  if (!_bfd_elf_link_hash_table_init (&ret->elf, abfd,
                                      _bfd_e2k_elf_link_hash_newfunc,
				      sizeof (struct _bfd_e2k_elf_link_hash_entry),
                                      E2K_ELF_DATA))
    {
      free (ret);
      return NULL;
    }

  /* Note that in the new scheme of dealing with PLT entries it should be enough
     to set initial values for PLIST fields only. We set REFCOUNT and OFFSET as
     well to take into account the case when they may turn out to be wider than
     PLIST in order to make debug inspection of them look nicer.  */
  ret->elf.init_plt_refcount.refcount = 0;
  ret->elf.init_plt_refcount.plist = NULL;

  /* Note that `_bfd_elf_link_hash_table_init ()' sets initial OFFSET to
     `-(bfd_vma) 1' which doesn't look compatible with the initial PLIST
     value. */
  ret->elf.init_plt_offset.offset = 0;
  ret->elf.init_plt_offset.plist = NULL;

  return &ret->elf.root;
}

/* Create .dynbss and .rela.bss sections in DYNOBJ required to support copy
   relocations. Currently it's unlikely that some generic function will do this
   for me.  */
bool
_bfd_e2k_elf_create_dynamic_sections (bfd *dynobj,
                                      struct bfd_link_info *info)
{
  struct _bfd_e2k_elf_link_hash_table *htab;

  htab = _bfd_e2k_elf_hash_table (info);
  BFD_ASSERT (htab != NULL);

  if (!_bfd_elf_create_dynamic_sections (dynobj, info))
    return false;

  /* .got should be aligned to 2**4 in PM.  */
  if (ABI_PM_P (dynobj)
      && ! bfd_set_section_alignment (htab->elf.sgot, 4))
    return false;

  htab->sdynbss = bfd_get_linker_section (dynobj, ".dynbss");
  if (!htab->sdynbss)
    abort ();

  if (! bfd_link_dll (info))
    {
      htab->srelbss = bfd_get_linker_section (dynobj, ".rela.bss");
      if (!htab->srelbss)
        abort ();
    }

  return true;
}



static bool met_eir_section;
static bool eir_in_this_bfd;

static void
search_eir (bfd *abfd ATTRIBUTE_UNUSED, asection *sect, void *obj ATTRIBUTE_UNUSED)
{
  if (strcmp (sect->name, ".pack_pure_eir") == 0
      || strcmp (sect->name, ".pack_mixed_eir") == 0)
    {
      met_eir_section = true;
      eir_in_this_bfd = true;
    }
}


static void
discard_unsuitable_section (bfd *abfd ATTRIBUTE_UNUSED, asection *sect, void *obj ATTRIBUTE_UNUSED)
{
  
  if ((link_mixed_eir_phase == 1 && met_eir_section)
      || (link_mixed_eir_phase == 3
          && (!(met_eir_section && !eir_in_this_bfd)
              /* Don't include an archive member into an output file at the
                 third EIR linkage stage by analogy with Sparc. Now that we
                 massively use libraries without EIR when compiling in '-fwhole'
                 mode (e.g. libc.a) (at Sparc we've probably been having such a
                 situation for years) almost all archive members may be very
                 well collected into the third intermediate obect file, which
                 will cause conflicts during the final linkage, like the one
                 described in MCSTBug #73608. So, let's prohibit this.  */
              || abfd->my_archive)))
    {
      /* SEC_DEBUGGING is required to fool lang_gc_sections in ldlang.c */
      sect->flags |= (SEC_EXCLUDE | SEC_DEBUGGING);
    }
}

static void
search_pure_eir (bfd *abfd, asection *sec, void *no_pure_eir)
{
  if (strcmp (sec->name, ".pack_pure_eir") == 0)
    {
      *((bool *) no_pure_eir) = false;
      _bfd_error_handler ("%pB with '.pack_pure_eir' is illegal during "
                          "non-relocatable linkage", abfd);
      bfd_set_error (bfd_error_wrong_format);
    }
}


bool
_bfd_e2k_elf_link_add_symbols (bfd *abfd, struct bfd_link_info *info)
{
  bool ret;

  /* Check for the absence of `.pack_pure_eir' sections during
     non-relocatable linkage (see MCSTBug #41413). */
  if (bfd_get_format (abfd) == bfd_object && info && !bfd_link_relocatable (info))
    {
      bool no_pure_eir = true;
      bfd_map_over_sections (abfd, search_pure_eir, &no_pure_eir);

      if (! no_pure_eir)
        return false;

    }

  ret = bfd_elf_link_add_symbols (abfd, info);

  /* COMMON sections are created while COMMON symbols are being
     read rather than while parsing input file's section headers.
     Therefore, a call to `bfd_elf_link_add_symbols ()' should
     precede the following, provided that we need to be able to
     discard COMMON sections. And we actually need this (see
     MCSTBug #57962).  */

  if ((link_mixed_eir_phase == 1
       || link_mixed_eir_phase == 3)
      && bfd_get_format (abfd) == bfd_object)
    {
      eir_in_this_bfd = false;
      bfd_map_over_sections (abfd, search_eir, NULL);
      bfd_map_over_sections (abfd, discard_unsuitable_section, NULL);
    }

  return ret;
}


bool
_bfd_e2k_elf_mkobject (bfd *abfd)
{
  return bfd_elf_allocate_object (abfd, sizeof (struct _bfd_e2k_elf_obj_tdata),
                                  E2K_ELF_DATA);
}


/* What's the point in this function provided that elf backend doesn't use
   arelents? It turns out to be that when `elf_link_add_object_symbols ()' meets
   a `.gnu.warning.SYMBOL' section it calls `_bfd_generic_link_add_one_symbol
   ()' which requires all this canonicalization. */

bool
_bfd_e2k_elf_info_to_howto (bfd *abfd,
                            arelent *bfd_reloc,
                            Elf_Internal_Rela *elf_reloc)
{
  unsigned int r_type;
  r_type = ELF_R_TYPE (abfd, elf_reloc->r_info);

  if (r_type < (sizeof (_bfd_e2k_elf_howto_table)
		/ sizeof (_bfd_e2k_elf_howto_table[0])))
    bfd_reloc->howto = &_bfd_e2k_elf_howto_table[r_type];
  else
    bfd_reloc->howto = NULL;

  if (bfd_reloc->howto == NULL || bfd_reloc->howto->name == NULL)
    {
      _bfd_error_handler (_("%pB: unsupported relocation type %#x"),
			  abfd, r_type);
      bfd_set_error (bfd_error_bad_value);
      return false;
    }

  return true;
}

static asection *
create_magic_section (bfd *abfd, const char *magic)
{
  asection *s;
  bfd_byte *contents;
  size_t name_size, name_size_aligned;
  size_t magic_size, magic_size_aligned;
  static const char name[] = "MCST";

  s = bfd_make_section_anyway_with_flags (abfd, ".magic",
                                          (SEC_LINKER_CREATED
                                           | SEC_HAS_CONTENTS | SEC_READONLY));

  if (s == NULL)
    return NULL;

  name_size = sizeof (name);
  name_size_aligned = (name_size + 3) & 0xfffffffc;
  magic_size = strlen (magic) + 1;
  magic_size_aligned = (magic_size + 3) & 0xfffffffc;

  s->size = 12 + name_size_aligned + magic_size_aligned;
  s->contents = (bfd_byte *) bfd_zalloc (abfd, s->size);
  if (s->contents == NULL)
    return NULL;

  contents = s->contents;

  /* Follow the standard note section layout:
     First write the length of the name string.  */
  bfd_put_32 (abfd, (bfd_vma) name_size, contents);
  contents += 4;

  /* Next comes the length of the "MAGIC" itself, i.e., the actual data.  */
  bfd_put_32 (abfd, (bfd_vma) magic_size, contents);
  contents += 4;

  /* Write the note NT_MAGIC type.  */
  bfd_put_32 (abfd, (bfd_vma) NT_MAGIC, contents);
  contents += 4;

  /* Write the name field.  */
  memcpy (contents, name, name_size);
  contents += name_size_aligned;

  /* Finally, write the descriptor.  */
  memcpy (contents, magic, magic_size);

  return s;
}

static bool
dummy_traverse (struct bfd_hash_entry *bh, void *data ATTRIBUTE_UNUSED)
{
  struct _bfd_e2k_elf_link_hash_entry *eh;
  eh = (struct _bfd_e2k_elf_link_hash_entry *) bh;

  if (eh->relgot_cntr > 0)
    {
      static int here_we_are;
      here_we_are++;
    }

  return true;
}

static const unsigned getpl_body[] =
  {
    0x24005224, /* foo: nop 4  */
    0x80000000, /*  ipd 2  */
    0x11c0c081, /*  addd,0 0x0, 0x0, %dr1  */
    0x63f08280, /*  getpl,3 %r2, %dr0  */
    0xf0000000, /*  return %ctpr3  */
    0x00000000,

    0x00009012, /* :  */
    0xc0000c20, /*  ct %ctpr3  */
                /*  ipd 3  */
    0x30000002, /*  wait trap = 0, ma_c = 0, fl_c = 0, ld_c = 0, st_c = 0, all_e = 1, all_c = 0  */
    0x00000000
  };


bool
_bfd_e2k_elf_final_link (bfd *abfd, struct bfd_link_info *info)
{
  char *magic;
  asection *magic_sec = NULL;

  /* There is nothing to be done here if we are going to output
     a binary file when linking EIR (see MCSTBug #59012, Comment # ).  */
  if (link_mixed_eir_phase == 2)
    return true;

  /* There is no point in creating a `.magic' section in the OBFD if it has
     already been borrowed from one of the IBFD's. Do we have the corresponding
     output section at this stage? Fortunately, output sections have already
     been assigned.  */
  if ((magic = getenv ("MAGIC")) != NULL
      && !bfd_get_section_by_name (abfd, ".magic"))
    {
      if ((magic_sec = create_magic_section (abfd, magic)) == NULL)
        return false;
    }

  if (! bfd_elf_final_link (abfd, info))
    return false;


  /* FIXME(?): it may seem inappropriately late to check for 4Gb overflows in
     32-bit mode and in PM on elbrus-v{X<6} after all relocations have been
     evaluated, but on the other hand "segment_map" should hopefully not be
     subject to any change (have "Program Headers", .rela.dyn, .dynamic and
     other subsidiary sections already been mapped to the address space?) at
     this stage, which is why this check is expected to provide a reliable
     result here.

     TODO: consider finding a better place for it: ideally this check should
     be done before processing of relocations, but after everything has been
     allocated and mapped.  */

  /* No point in checking for 4 Gb overflow in 64-bit mode as well as in PM on
     elbrus-v{X>=7}.  */
  if (!(ABI_64_P (abfd)
	|| (ABI_PM_P (abfd)
	    && e2k_arch_info_mach_to_iset (bfd_get_mach (abfd)) >= 7)))
    {
      struct elf_segment_map *m;
      Elf_Internal_Phdr *phdrs = elf_tdata (info->output_bfd)->phdr;
      Elf_Internal_Phdr *p;
      /* Stands for the maximal text address in PM.  */
      bfd_vma max_text_addr = 0;
      /* Stands for the maximal data address in PM and for the maximal address
	 across "text & data" in ordinary 32-bit mode.  */
      bfd_vma max_data_addr = 0;

      for (m = elf_seg_map (info->output_bfd), p = phdrs; m != NULL;
	   m = m->next, p++)
	{
	  /* adjust_offset_in_cud_gd () may be in trouble determining the
	     offset matching the address of a zero-size segment in packed PM
	     case. Taking into account that such segments shouldn't be mapped
	     into the address spac, ignore them.  */
	  if (p->p_type == PT_LOAD && p->p_memsz > 0)
	    {
	      if (ABI_PM_P (abfd) && (p->p_flags & PF_X) != 0)
		{
		  if (max_text_addr < p->p_vaddr + p->p_memsz - 1)
		    max_text_addr = p->p_vaddr + p->p_memsz - 1;
		}
	      else if (max_data_addr < p->p_vaddr + p->p_memsz - 1)
		max_data_addr = p->p_vaddr + p->p_memsz - 1;
	    }
	}

      bool overflow = false;

      if (ABI_PM_P (abfd)
	  && max_text_addr != 0
	  && adjust_offset_in_cud_gd (info, max_text_addr) > 0xffffffffULL)
	{
	  _bfd_error_handler (_("4 Gb text segment overflow in PM"));
	  overflow = true;
	}

      if (max_data_addr !=0
	  && adjust_offset_in_cud_gd (info, max_data_addr) > 0xffffffffULL)
	{
	  _bfd_error_handler (_("4 Gb %s overflow in %s"),
			      (ABI_PM_P (abfd)
			       ? "data segment" : "address space"),
			      ABI_PM_P (abfd) ? "PM" : "32-bit mode");
	  overflow = true;
	}

      if (overflow)
	return false;
    }


  bfd_hash_traverse (&info->hash->table, dummy_traverse, NULL);

  if (magic_sec != NULL)
    {
      if (! bfd_set_section_contents (abfd, magic_sec, magic_sec->contents,
                                      (bfd_vma) 0, magic_sec->size))
        return false;
    }

  return true;
}


bool
_bfd_e2k_elf_add_symbol_hook (bfd *abfd, struct bfd_link_info *info,
                              Elf_Internal_Sym *sym,
                              const char **name ATTRIBUTE_UNUSED,
                              flagword *flags ATTRIBUTE_UNUSED,
                              asection **sec ATTRIBUTE_UNUSED,
                              bfd_vma *value ATTRIBUTE_UNUSED)
{
  if ((abfd->flags & DYNAMIC) == 0
      && bfd_get_flavour (info->output_bfd) == bfd_target_elf_flavour
      && (ELF_ST_TYPE (sym->st_info) == STT_GNU_IFUNC
          || ELF_ST_BIND (sym->st_info) == STB_GNU_UNIQUE))
    elf_tdata (info->output_bfd)->has_gnu_osabi = true;

  /* When not linking EIR, special symbols related to sections containing EIR
     should be ignored.

     In my new external EIR linkage scheme these symbols are not employed
     anymore, however this check is required in case someone links with
     older libraries containing such symbols.  */
  if (!link_mixed_eir_phase && startswith (*name, "#@EIR@#_"))
    *name = NULL;

  return true;
}

/* This function is borrowed from `elfxx-sparc.c'. Why isn't the common
   functionality implemented in `elf-ifunc.c' used there? Probably because
   the latter deals with `.got.plt' which has no role at Sparc. Find out
   if we can use this common functionality instead of stupidly duplicating
   Sparc implementation.  */
static bool
create_ifunc_sections (bfd *abfd, struct bfd_link_info *info)
{
  const struct elf_backend_data *bed = get_elf_backend_data (abfd);
  struct elf_link_hash_table *htab = elf_hash_table (info);
  flagword flags, pltflags;
  asection *s;

  if (htab->irelifunc != NULL || htab->iplt != NULL)
    return true;

  flags = bed->dynamic_sec_flags;
  pltflags = flags | SEC_ALLOC | SEC_CODE | SEC_LOAD | SEC_READONLY;

  s = bfd_make_section_with_flags (abfd, ".iplt", pltflags);
  if (s == NULL
      || ! bfd_set_section_alignment (s, bed->plt_alignment))
    return false;
  htab->iplt = s;

  s = bfd_make_section_with_flags (abfd, ".rela.iplt",
				   flags | SEC_READONLY);
  if (s == NULL
      || ! bfd_set_section_alignment (s, bed->s->log_file_align))
    return false;
  htab->irelplt = s;

  return true;
}

void
_bfd_e2k_elf_copy_indirect_symbol (struct bfd_link_info *info,
                                   struct elf_link_hash_entry *dir,
                                   struct elf_link_hash_entry *ind)
{
  struct _bfd_e2k_elf_link_hash_entry *edir, *eind;
  struct elf_link_hash_table *htab;
  union gotplt_union saved;

  edir = (struct _bfd_e2k_elf_link_hash_entry *) dir;
  eind = (struct _bfd_e2k_elf_link_hash_entry *) ind;

  /* Once We started discarding dynamic relocs for non-dynamic symbols (see
     allocate_dynrelocs ()) it became clear how important it is to copy
     its reloc to its direct (versioned, i.e. having `@GLIBC_2. . .' in its
     name) dynamic counterpart. Without that no space used to be allocated
     for dynamic relocs against the direct symbol which lead to assertion
     failure while swapping them out into the output file.  */

  if (eind->dyn_relocs != NULL)
    {
      if (edir->dyn_relocs != NULL)
	{
	  struct e2k_elf_dyn_relocs **pp;
	  struct e2k_elf_dyn_relocs *p;

	  /* Add reloc counts against the indirect sym to the direct sym
	     list.  Merge any entries against the same section.  */
	  for (pp = &eind->dyn_relocs; (p = *pp) != NULL; )
	    {
	      struct e2k_elf_dyn_relocs *q;

	      for (q = edir->dyn_relocs; q != NULL; q = q->next)
		if (q->sec == p->sec)
		  {
		    q->pc_count += p->pc_count;
		    q->count += p->count;
		    *pp = p->next;
		    break;
		  }
	      if (q == NULL)
		pp = &p->next;
	    }
	  *pp = edir->dyn_relocs;
	}

      edir->dyn_relocs = eind->dyn_relocs;
      eind->dyn_relocs = NULL;
    }

  if (ind->root.type == bfd_link_hash_indirect
      /* This function may be called several times with the same EDIR (e.g.
         "errno@@GLIBC_PRIVATE") but different EINDs (e.g. "errno" and
         "errno@GLIBC_PRIVATE"). Whereas the first EIND has `TLS_TYPE ==
         GOT_TLS_IE', the second one turns out to be `GOT_UNKNOWN'. The
         previously employed condition `dir->got.refcount <= 0' adopted from
         sparc backend saved us from re-setting `EIND->TLS_TYPE' to
         `GOT_UNKNOWN' provided that the first EIND had been really accessed
         via GOT (i.e. had `GOT.REFCOUNT > 0'). Now that IE relocations are
         tracked via a separate IE.REFCOUNT, this is not going to work. Try
         to verify explicitly that EIND is not GOT_UNKNOWN instead.  */
      && eind->tls_type != GOT_UNKNOWN)
    {
      edir->tls_type |= eind->tls_type;
      /* Probably this may happen somehow if different EINDs having incompatible
         TLS types are merged to the same EDIR. An error message should be used
         then rather than ASSERT.  */
      BFD_ASSERT ((edir->tls_type & GOT_NORMAL) == 0
                  || (edir->tls_type & (GOT_TLS_GDMOD | GOT_TLS_GDREL
                                        | GOT_TLS_IE)) == 0);

      /* There is analogous code in `_bfd_elf_link_hash_copy_indirect ()'
         adjusting DIR->GOT.REFCOUNT.  */

      if ((eind->tls_type & GOT_TLS_GDMOD) != 0
          && eind->gdmod.refcount > 0)
        {
          edir->gdmod.refcount += eind->gdmod.refcount;
          eind->gdmod.refcount = 0;
        }

      if ((eind->tls_type & GOT_TLS_IE) != 0
          && eind->ie.refcount > 0)
        {
          edir->ie.refcount += eind->ie.refcount;
          eind->ie.refcount = 0;
        }

      eind->tls_type = GOT_UNKNOWN;
    }

  htab = elf_hash_table (info);
  if (ind->plt.plist != NULL)
    {
      copy_plt_refcount (dir, ind);
      ind->plt = htab->init_plt_refcount;
    }

  if (eind->relgot_cntr > 0)
    {
      edir->relgot_cntr += eind->relgot_cntr;
      eind->relgot_cntr = 0;
    }

  /* Prevent `_bfd_elf_link_hash_copy_indirect ()' from manipulating `{dir,ind}
     ->plt.refcount'. It's obviously wrong now that these fields contain junk
     while PLIST is actually used. I've already done this job a few lines above.

     We wonder why they don't care about this in elfxx-mips.c and what they get
     in the end if `ind->plt.refcount > htab->init_plt_refcount.refcount' turns
     out to be true . . .*/
  saved = ind->plt;
  ind->plt = htab->init_plt_refcount;

  _bfd_elf_link_hash_copy_indirect (info, dir, ind);

  ind->plt = saved;
}


bool
_bfd_e2k_elf_check_relocs (bfd *abfd, struct bfd_link_info *info,
                           asection *sec, const Elf_Internal_Rela *relocs)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  const Elf_Internal_Rela *rel;
  const Elf_Internal_Rela *rel_end;
  asection *sreloc;

  if (bfd_link_relocatable (info))
    return true;

  htab = _bfd_e2k_elf_hash_table (info);
  if (htab == NULL)
    return false;

  BFD_ASSERT (is_e2k_elf (abfd));

  if (!create_ifunc_sections (htab->elf.dynobj, info))
    return false;

  symtab_hdr = &elf_symtab_hdr (abfd);
  sym_hashes = elf_sym_hashes (abfd);

  sreloc = NULL;

  rel = relocs;
  rel_end = relocs + sec->reloc_count;

  for (; rel < rel_end; rel++)
    {
      unsigned int r_type;
      unsigned int r_symndx;
      struct elf_link_hash_entry *h;
      Elf_Internal_Sym *isym;
      bool size_reloc = false;

      r_type = ELF_R_TYPE (abfd, rel->r_info);
      r_symndx = ELF_R_SYM (abfd, rel->r_info);

      if (r_symndx >= NUM_SHDR_ENTRIES (symtab_hdr))
        {
          _bfd_error_handler (_("%pB: bad symbol index: %d"),
                              abfd, r_symndx);
          return false;
        }

      isym = NULL;
      if (r_symndx < symtab_hdr->sh_info)
        {
          /* This is a local symbol.  */
          isym = bfd_sym_from_r_symndx (&htab->sym_cache,
                                        abfd, r_symndx);
          if (isym == NULL)
            return false;

          h = NULL;
        }
      else
        {
          h = sym_hashes[r_symndx - symtab_hdr->sh_info];
          while (h->root.type == bfd_link_hash_indirect
		 || h->root.type == bfd_link_hash_warning)
	    h = (struct elf_link_hash_entry *) h->root.u.i.link;
        }

       /* This fragment is borrowed from `elfxx-sparc.c'. Forcing
         `h->ref_regular' to be equal to one should be enough to satisfy the
         outermost condition in `allocate_dynrelocs ()' and reserve space in
         PLT. What's the point in setting `PLT.REFCOUNT'? Anyway, We don't
         understand for sure what's the point in setting `REF_REGULAR'. Probably
         this indicates that the symbol has been REFERED to, no matter that from
         the same regular object where it's defined (for IFUNC only).  */
      if (h && h->type == STT_GNU_IFUNC)
	{
	  if (h->def_regular)
	    {
	      h->ref_regular = 1;
              if (! increase_plt_refcount (abfd, h))
                return false;
	    }
	}

      /* Fix the build of ld-plugin/pr15323 this way.  */
      if (h != NULL)
        h->root.non_ir_ref_regular = 1;

      switch (r_type)
        {
        case R_E2K_GOT:
	case R_E2K_AP_GOT:
	case R_E2K_PL_GOT:
        case R_E2K_TLS_GDMOD:
        case R_E2K_TLS_GDREL:
        case R_E2K_TLS_IE:
          /* This symbol requires a GOT entry.  */
          {
            /* FIXME: gcc when compiling with `-O2' cannot determine that
               TLS_TYPE is ALWAYS initialized below in fact . . .  */
            int tls_type = GOT_NORMAL;
            int old_tls_type;

            switch (r_type)
              {
              case R_E2K_GOT:
	      case R_E2K_AP_GOT:
	      case R_E2K_PL_GOT:
                tls_type = GOT_NORMAL;
                break;
              case R_E2K_TLS_GDMOD:
                tls_type = GOT_TLS_GDMOD;
                break;
              case R_E2K_TLS_GDREL:
                tls_type = GOT_TLS_GDREL;
                break;
              case R_E2K_TLS_IE:
                tls_type = GOT_TLS_IE;
                break;

              }

            if (h != NULL)
              {
                if (r_type == R_E2K_TLS_IE)
                  _bfd_e2k_elf_hash_entry (h)->ie.refcount += 1;
                else if (r_type == R_E2K_TLS_GDMOD)
                  _bfd_e2k_elf_hash_entry (h)->gdmod.refcount += 1;
                else
		  {
		    char pm_got_type = 0;
		    struct _bfd_e2k_elf_link_hash_entry *eh
		      = _bfd_e2k_elf_hash_entry (h);

		    if (r_type == R_E2K_AP_GOT)
		      pm_got_type = 1;
		    else if (r_type == R_E2K_PL_GOT)
		      pm_got_type = 2;

		    if (pm_got_type)
		      {
			if (eh->pm_got_type == 0)
			  eh->pm_got_type = pm_got_type;
			else if (eh->pm_got_type != pm_got_type)
			  _bfd_error_handler
			    (_("a symbol is accessed both via "
			       "`R_E2K_{AP,PL}_GOT'"));
		      }

		    h->got.refcount += 1;
		  }

                old_tls_type = _bfd_e2k_elf_hash_entry (h)->tls_type;
              }
            else
              {
                bfd_signed_vma *local_got_refcounts, *local_ie_refcounts;
                local_got_refcounts = elf_local_got_refcounts (abfd);
                if (local_got_refcounts == NULL)
                  {
                    bfd_size_type size;
                    size = symtab_hdr->sh_info;
                    size *= (2 * sizeof (bfd_signed_vma) + sizeof (char)
                             + sizeof (unsigned char));
                    local_got_refcounts = (bfd_signed_vma *)
                      bfd_zalloc (abfd, size);
                    if (local_got_refcounts == NULL)
                      return false;
                    elf_local_got_refcounts (abfd) = local_got_refcounts;
                    _bfd_e2k_elf_local_ie_refcounts (abfd)
                      = local_got_refcounts + symtab_hdr->sh_info;

                    _bfd_e2k_elf_local_got_tls_type (abfd)
                      = (char *) (local_got_refcounts + 2 * symtab_hdr->sh_info);

                    _bfd_e2k_elf_local_relgot_cntr (abfd)
                      = ((char *) _bfd_e2k_elf_local_got_tls_type (abfd)
                         + symtab_hdr->sh_info);
                  }

                local_ie_refcounts = _bfd_e2k_elf_local_ie_refcounts (abfd);

                if (r_type == R_E2K_TLS_IE)
                  local_ie_refcounts[r_symndx] += 1;
                else
                  local_got_refcounts[r_symndx] += 1;

                old_tls_type = _bfd_e2k_elf_local_got_tls_type (abfd) [r_symndx];
              }

            if (old_tls_type != GOT_UNKNOWN
                && (tls_type & GOT_NORMAL) != (old_tls_type & GOT_NORMAL))
              {
                _bfd_error_handler
                  (_("%pB: `%s' accessed both as normal and thread local symbol"),
                   abfd, h ? h->root.root.string : "<local>");
                return false;
              }

            if (h != NULL)
              _bfd_e2k_elf_hash_entry (h)->tls_type |= tls_type;
            else
              _bfd_e2k_elf_local_got_tls_type (abfd) [r_symndx] |= tls_type;
          }

	  /* Fall through  */
        case R_E2K_GOTOFF:
	case R_E2K_64_GOTOFF:
	case R_E2K_64_GOTOFF_LIT:
        create_got:
	  /* .got should be created here if create_dynamic_sections () isn't
	     called during the link, but there are relocations requiring it.
	     FIXME: consider moving this code to setup_gnu_properties () by
	     analogy with x86.  */
          if (htab->elf.sgot == NULL)
            {
              if (!_bfd_elf_create_got_section (htab->elf.dynobj, info))
                return false;

	      /* .got should be aligned to 2**4 in PM.  */
	      if (ABI_PM_P (htab->elf.dynobj)
		  && ! bfd_set_section_alignment (htab->elf.sgot, 4))
		  return false;
            }
          break;

        case R_E2K_GOTPLT:
          if (h != NULL)
            {
              if (! increase_secondary_plt_refcount (abfd, h))
                return false;

              /* This ensures that PLT related info  won't be discarded in
                 `_bfd_elf_adjust_dynamic_symbol ()' if this call is resolved
                 locally. Without it I'll be unable to make a decision that this
                 symbol requires a .got entry in `allocate_dynrelocs ()' and may
                 very well get SIGSEGV later in relocate_section.  */
              h->needs_plt = 1;
            }
          goto create_got;

        case R_E2K_DISP:
          /* Sparc has `!bfd_link_pic (info)' in the condition below, while i386
             uses `bfd_link_executable (info)'. Why shouldn't we increase PLT refcount
             when linking a shared library??? Because both sparc and i386 have
             a special reloc (e.g., R_386_PLT32) which instructs LD to jump via
             a PLT entry in fPIC mode.  */
          if (h != NULL)
            {
              /* Ensure that `_bfd_e2k_elf_size_dynamic_sections' gets called
                 so that NEEDS_PLT and PLT.REFCOUNT are reset appropriately
                 in case a PLT entry isn't required for this symbol (see
                 `allocate_dynrelocs ()'.  */
              
              h->needs_plt = 1;

              if (! increase_plt_refcount (abfd, h))
                return false;
            }
          break;

        case R_E2K_32_SIZE:
        case R_E2K_64_SIZE:
          size_reloc = true;
          goto do_size;

	case R_E2K_32_ABS:
        case R_E2K_64_ABS_LIT:
        case R_E2K_64_ABS:
          if (h != NULL && ! bfd_link_dll (info))
            {
              /* Set this flag for now until adjust_dynamic_symbol where it may
                 be cleared if there are no relocations related to this symbol
                 against readonly sections. Once again, the name of this flag
                 seems to be a misnomer.  */
              h->non_got_ref = 1;

              /* h->non_got_ref is likely to be never cleared in adjust_dynamic
                 _symbol for functions, even if all `R_E2K_XX_ABS{,LIT}'
                 relocations against it are applied to RW-sections. Therefore,
                 no corresponding dynamic relocations are going to be generated
                 in relocate_section now that we set this flag. They should be
                 resolved to a primary PLT entry instead.  */
              if (! increase_plt_refcount (abfd, h))
                return false;

              h->pointer_equality_needed = 1;
            }
	  /* Fall through  */

	  /* These relocations shouldn't call for copy relocs or PLT entries,
	     which is why there's probably no point in setting NON_GOT_REF for
	     the associated symbol.  */
	case R_E2K_AP:
	case R_E2K_PL:
	  /* Fall through  */
        do_size:
          if (/* No dynamic relocations should be created for ABS ones
		 in PM.  */
	      ! (ABI_PM_P (abfd)
		 && (r_type == R_E2K_32_ABS
		     || r_type == R_E2K_64_ABS_LIT
		     || r_type == R_E2K_64_ABS))
	      && ((ABI_PM_P (abfd)
		   /* Relocations of these types should be always tracked in PM
		      even when linking a static executable.  */
		   && (r_type == R_E2K_AP || r_type == R_E2K_PL))
		  || (bfd_link_pic (info)
		      && (sec->flags & SEC_ALLOC) != 0)
		  /* Hopefully the following is going to help when we are dealing
		     with these relocations in dynamic executables without creating
		     copy relocs.  */
		  || (!bfd_link_pic (info)
		      && (sec->flags & SEC_ALLOC) != 0
		      && h != NULL
		      && !h->def_regular)))
            {
              struct e2k_elf_dyn_relocs *p;
              struct e2k_elf_dyn_relocs **head;

              /* Create a dynamic reloc section associated with the section
                 being considered.  */
              if (sreloc == NULL)
                {
                  sreloc = _bfd_elf_make_dynamic_reloc_section
                    (sec, htab->elf.dynobj, htab->word_align_power,
                     abfd, true);

                  if (sreloc == NULL)
                    return false;
                }

              /* If this is a global symbol, we count the number of
                 relocations we need for this symbol.  */
              if (h != NULL)
                head = &((struct _bfd_e2k_elf_link_hash_entry *) h)->dyn_relocs;
              else
                {
                  void **vpp;
                  /* S is a section which this local symbol is defined in.  */
                  asection *s;

                  BFD_ASSERT (isym != NULL);
                  s = bfd_section_from_elf_index (abfd, isym->st_shndx);
                  /* Other backends set S to SEC in case the former turns out
                     to be NULL. We cannot imagine how this may happen and what
                     is the point in `s = sec'. These sections have different
                     relation to the symbol after all . . .  */
                  BFD_ASSERT (s != NULL);
                  vpp = &elf_section_data (s)->local_dynrel;
                  head = (struct e2k_elf_dyn_relocs **) vpp;
                }

              p = *head;
              if (p == NULL || p->sec != sec)
                {
                  bfd_size_type amt = sizeof (*p);
                  p = ((struct e2k_elf_dyn_relocs *)
                       bfd_alloc (htab->elf.dynobj, amt));
                  if (p == NULL)
                    return false;

                  p->next = *head;
                  *head = p;
                  p->sec = sec;
                  p->count = 0;
                  p->pc_count = 0;
		  p->type = 0;
                }

              p->count += 1;

              /* Count size relocations as PC-relative relocations so as to make
                 it possible to discard them if the symbol is referenced
                 locally within a shared library. Funnily enough, PC-relative
                 relocations are not actually counted in this backend yet.  */
              if (size_reloc || ((r_type == R_E2K_32_ABS
				  || r_type == R_E2K_64_ABS_LIT
				  || r_type == R_E2K_64_ABS)
				 && ABI_PM_P (abfd)))
                p->pc_count += 1;

	      if (ABI_PM_P (abfd) && (r_type == R_E2K_AP || r_type == R_E2K_PL))
		{
		  int type = (r_type == R_E2K_AP ? 1 : 2);
		  if (p->type == 0)
		    p->type = type;
		    else if (p->type != type)
		      _bfd_error_handler
			(_("a symbol is accessed both via `R_E2K_{AP,PL}'"));
		}
              
            }
          break;
        }
    }
  return true;
}

/* Update the got entry reference counts for the section being removed.  */

bool
_bfd_e2k_elf_gc_sweep_hook (bfd *abfd,
                            struct bfd_link_info *info,
                            asection *sec,
                            const Elf_Internal_Rela *relocs)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  bfd_signed_vma *local_got_refcounts;
  bfd_signed_vma *local_ie_refcounts;
  const Elf_Internal_Rela *rel, *relend;

  if (bfd_link_relocatable (info))
    return true;

  htab = _bfd_e2k_elf_hash_table (info);
  if (htab == NULL)
    return false;

  elf_section_data (sec)->local_dynrel = NULL;

  symtab_hdr = &elf_symtab_hdr (abfd);
  sym_hashes = elf_sym_hashes (abfd);
  local_got_refcounts = elf_local_got_refcounts (abfd);
  local_ie_refcounts = _bfd_e2k_elf_local_ie_refcounts (abfd);

  relend = relocs + sec->reloc_count;
  for (rel = relocs; rel < relend; rel++)
    {
      unsigned long r_symndx;
      unsigned int r_type;
      struct elf_link_hash_entry *h = NULL;

      r_symndx = ELF_R_SYM (abfd, rel->r_info);
      if (r_symndx >= symtab_hdr->sh_info)
	{
	  h = sym_hashes[r_symndx - symtab_hdr->sh_info];
	  while (h->root.type == bfd_link_hash_indirect
		 || h->root.type == bfd_link_hash_warning)
	    h = (struct elf_link_hash_entry *) h->root.u.i.link;
	}
      else
	{

	  /* At i386 they handle the case of local STT_GNU_IFUNC symbol here
             and obtain a hash entry for it! This is rather unusual.  */
	}

      if (h)
	{
	  struct _bfd_e2k_elf_link_hash_entry *eh;
	  struct e2k_elf_dyn_relocs **pp;
	  struct e2k_elf_dyn_relocs *p;

          /* As far as We understand, the underlying code lets us get rid of
             all dynamic relocations against H, applied to the section to be
             removed. It doesn't matter whether they have any relation to the
             currently considered REL or not.  */
	  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;
	  for (pp = &eh->dyn_relocs; (p = *pp) != NULL; pp = &p->next)
	    if (p->sec == sec)
	      {
		/* Everything must go for SEC.  */
		*pp = p->next;
		break;
	      }
	}
      else
        {
          Elf_Internal_Sym *isym;
          asection *s;
          struct e2k_elf_dyn_relocs **pp;
          struct e2k_elf_dyn_relocs *p;

          /* Take care of discarding dynamic relocations applied to a section
             being garbage collected against local symbols (defined in other
             sections). The failure to do so led to an assertion failure in Bug
             #82835 due to redundant space in '.rela.data'. Interestingly
             enough, I've not noticed analogous code for x86 . . .  */

          isym = bfd_sym_from_r_symndx (&htab->sym_cache, abfd, r_symndx);
          /* S is the section the related local symbol comes from.  */
          s = bfd_section_from_elf_index (abfd, isym->st_shndx);
          pp = (struct e2k_elf_dyn_relocs **) &elf_section_data (s)->local_dynrel;

	  for (; (p = *pp) != NULL; pp = &p->next)
	    if (p->sec == sec)
	      {
		/* Everything must go for SEC.  */
		*pp = p->next;
		break;
	      }
        }

      r_type = ELF32_R_TYPE (rel->r_info);

      switch (r_type)
	{
        case R_E2K_GOT:
	case R_E2K_AP_GOT:
	case R_E2K_PL_GOT:
        case R_E2K_TLS_GDREL:
	  if (h != NULL)
	    {
	      if (h->got.refcount > 0)
		h->got.refcount -= 1;
	    }
	  else if (local_got_refcounts != NULL)
	    {
	      if (local_got_refcounts[r_symndx] > 0)
		local_got_refcounts[r_symndx] -= 1;
	    }
	  break;

        case R_E2K_GOTPLT:
          BFD_ASSERT (h != NULL);
          decrease_secondary_plt_refcount (h);
          break;

        case R_E2K_TLS_GDMOD:
          /* Note that there's no point in tracing gdmod.refcount for local TLS
             symbols. Thererefore, there is nothing to be decreased here in
             this case.  */
          if (h != NULL)
            {
              struct _bfd_e2k_elf_link_hash_entry *eh;
              eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

	      if (eh->gdmod.refcount > 0)
		eh->gdmod.refcount -= 1;
            }

	  /* Fall through  */
        case R_E2K_TLS_IE:
	  if (h != NULL)
	    {
              struct _bfd_e2k_elf_link_hash_entry *eh;
              eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

	      if (eh->ie.refcount > 0)
		eh->ie.refcount -= 1;
	    }
	  else if (local_ie_refcounts != NULL)
	    {
	      if (local_ie_refcounts[r_symndx] > 0)
		local_ie_refcounts[r_symndx] -= 1;
	    }
	  break;

          /* Currently We don't tackle PLT refcounts and the case of ifuncs
             because I've not got a clear understanding of these issues yet.  */
	}
    }

  return true;
}

bool
_bfd_e2k_elf_adjust_dynamic_symbol (struct bfd_link_info *info,
                                    struct elf_link_hash_entry *h)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  struct e2k_elf_dyn_relocs *p;
  struct _bfd_e2k_elf_link_hash_entry *eh;
  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

  if (h->type == STT_FUNC
      || h->type == STT_GNU_IFUNC
      || h->needs_plt)
    {
      if (SYMBOL_CALLS_LOCAL (info, h)
          || (ELF_ST_VISIBILITY (h->other) != STV_DEFAULT
	      && h->root.type == bfd_link_hash_undefweak))
	{
	  /* This case can occur if there is no point in building a PLT entry
             for this symbol. For example, when making a function call within
             an executable (either PIE or not).  */
          if (h->plt.plist)
            {
              if (h->plt.plist->primary.refcount == 0)
                {
                  h->plt.plist->primary.idx = (bfd_vma) -1;
                  h->needs_plt = 0;
                }

              if (h->plt.plist->secondary.refcount == 0)
                h->plt.plist->secondary.idx = (bfd_vma) -1;
            }
	}

      return true;
    }
  else
    {
      /* It's possible that we incorrectly decided a .plt reloc was needed for
         a `R_E2K_XX_ABS{,_LIT}' to a non-function symbol in check_relocs. They
         say that we can't decide accurately between function and non-function
         symbols in check_relocs, so fix it now.  */
      set_plt_idx (h, NULL);
      set_secondary_plt_idx (h, NULL);
    }

  /* If this is a weak symbol, and there is a real definition, the
     processor independent code will have arranged for us to see the
     real definition first, and we can just use the same value.  */
  if (h->is_weakalias)
    {
      struct elf_link_hash_entry *def = weakdef (h);
      BFD_ASSERT (def->root.type == bfd_link_hash_defined);
      h->root.u.def.section = def->root.u.def.section;
      h->root.u.def.value = def->root.u.def.value;
      h->non_got_ref = def->non_got_ref;
      return true;
    }


  /* This is a reference to a symbol defined by a dynamic object which
     is not a function.  */

  /* If we are creating a shared library, we must presume that the
     only references to the symbol are via the global offset table.
     For such cases we need not do anything here; the relocations will
     be handled correctly by relocate_section.  */
  if (bfd_link_dll (info))
    return true;

  /* If there are no references to this symbol that do not use the
     GOT, we don't need to generate a copy reloc.  */
  if (!h->non_got_ref)
    return true;

  /* If -z nocopyreloc was given, we won't generate them either.  */
  if (info->nocopyreloc)
    {
      h->non_got_ref = 0;
      return true;
    }

  htab = _bfd_e2k_elf_hash_table (info);
  if (htab == NULL)
    return false;

  p = eh->dyn_relocs;
  if (! ABI_PM_P (htab->elf.dynobj))
    {
      for (; p != NULL; p = p->next)
	{
	  asection *s;
	  s = p->sec->output_section;
	  if (s != NULL && (s->flags & SEC_READONLY) != 0)
	    break;
	}
    }

  /* If the underlying condition fulfills, a copy relocation won't be
     created. PM is special as dynamic relocations do not help with
     R_E2K_32_ABS, only copy ones do. Therefore, the absence of read-only
     dynamic relocations, which may not be even created if all references
     go through  R_E2K_32_ABS, cannot be used as a criterium for
     eliminating copy ones.  */
  if (! ABI_PM_P (htab->elf.dynobj) && p == NULL)
    {
      /* It turns out that this flag might be cleared in case there are actually
         non-GOT relocations only in rw sections, mightn't it? Isn't it a
         misnomer?
         Later in `relocate_section ()' its zero value along with other
         conditions instructs LD to create dynamic relocations against these
         sections.  */
      h->non_got_ref = 0;
      return true;
    }

  /* We guess that if either of the two underlying conditions fails there is no
     point in creating a copy relocation for the symbol.  */
  if ((h->root.u.def.section->flags & SEC_ALLOC) != 0 && h->size != 0)
    {
      htab->srelbss->size += htab->bytes_per_rela;
      h->needs_copy = 1;
    }

  return _bfd_elf_adjust_dynamic_copy (info, h, htab->sdynbss);
}

static bool
allocate_dynrelocs (struct elf_link_hash_entry *h, void *inf)
{
  struct bfd_link_info *info;
  struct _bfd_e2k_elf_link_hash_table *htab;
  struct _bfd_e2k_elf_link_hash_entry *eh;
  struct e2k_elf_dyn_relocs *p;
  int i;

  info = (struct bfd_link_info *) inf;
  htab = _bfd_e2k_elf_hash_table (info);
  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

  if ((htab->elf.dynamic_sections_created
       && positive_plt_refcount (h))
      || (h->type == STT_GNU_IFUNC
          && h->def_regular
          && h->ref_regular))
    {
      if (! SYMBOL_CALLS_LOCAL (info, h)
          // WILL_CALL_FINISH_DYNAMIC_SYMBOL (1, 0, h)
          || (h->type == STT_GNU_IFUNC
              && h->def_regular))
	{
          asection *s;

          s = htab->elf.splt;
          if (s == NULL)
            s = htab->elf.iplt;

          if (positive_plt_refcount (h))
	    set_plt_idx (h, htab);

          /* 1. Other backends have a `! bfd_link_pic (info)' condition which I
             don't quite understand yet. PLT entries for functions defined in
	     other dynamic objects referenced via ABS-like relocations may
	     probably be needed only in executables, but not shared libraries.
	     At the same time there's probably no point in prohibiting the use
	     of ABS-like relocations in PIEs, which is why `! bfd_link_dll ()'
	     seems more appropriate to me.
             2. What if this symbol is defined in a regular object? Should we
             substitute it with its PLT entry then?
             3. Keep in mind that other architectures have a special
             fPIC-specific variant of R_E2K_DISP, which lets them calculate an
             offset to the corresponding PLT entry in `relocate_section ()' in
             addition to the underlying hack.  */
          if (!bfd_link_dll (info)
              && !h->def_regular)
            {
              h->root.u.def.section = s;
              /* Primary offset in .plt can't be determined reliably now that
                 primary entries are allocated after secondary ones because not
                 all symbols have been assigned their secondary PLT offsets so
                 far. Mark this symbol as requiring its value to be set to its
                 primary PLT offset once it can be determined.  */
              eh->finalize_plt_offset = 1;
            }
        }
      else
	{
          /* Provided that a primary PLT entry is not required to call this
             function it shouldn't contribute into the corresponding secondary
             PLT entry refcount. Note, that the secondary entry may still be
             needed on its own because of the code making use of so-called
             inlined PLT entries (i.e. `@GOTPLT' relocations). */
          if (positive_plt_refcount (h))
            discard_plt_refcount (h);

	  set_plt_idx (h, NULL);
	  h->needs_plt = 0;
	}
    }
  else
    {
      if (positive_plt_refcount (h))
        discard_plt_refcount (h);

      set_plt_idx (h, NULL);
    }

  /* A few other entries may need to be allocated here under the following
     circumstances:

     R_E2K_DISP can't be resolved  at linktime and an accompanying secondary PLT
     entry is required along with entries in `.got.plt' and `.rela.plt'.

     The very same entries may be required because R_E2K_GOTPLT can't be
     resolved at linktime on its own.

  */
  if (positive_secondary_plt_refcount (h))
    {
      bool dyn = htab->elf.dynamic_sections_created;

      /* Ensure that an undefined weak symbol becomes dynamic (it may remain
         non-dynamic when linking an executable in fact) so that `WILL_CALL_
         FINISH_DYNAMIC_SYMBOL ()' below could return true for it. It's really
         necessary since undefined weak symbols aren't considered to be resolved
         locally within an executable.

         Currently this is the only case I'm aware of when a symbol should be
         explicitly recorded as dynamic. At the same time I'd like to avoid the
         trouble of recording all symbols accessed this way as dynamic (consider
         the case when a PIC object is linked into an executable). Therefore,
         unlike other backends We explicitly check for the type of a symbol.  */
      if (dyn
          && h->dynindx == -1
          && !h->forced_local
          && h->root.type == bfd_link_hash_undefweak)
        {
          if (! bfd_elf_link_record_dynamic_symbol (info, h))
            return false;
        }

      /* If the address of this function is accessed via GOT, we don't need
         any other entries.  */
      if (h->got.refcount > 0 && !h->pointer_equality_needed)
        set_secondary_plt_idx (h, NULL);
      else if ((SYMBOL_CALLS_LOCAL (info, h)
                && h->type != STT_GNU_IFUNC)
               /* How can this rather special case be treated in a more regular
                  way?  */
               || (!dyn && h->root.type == bfd_link_hash_undefweak))
        {
          /* This function is called locally within an executable via a load
             from GOT. Therefore, it requires a '.got' entry the value of which
             should be known at link-time.  */
          set_secondary_plt_idx (h, NULL);
          BFD_ASSERT (eh->tls_type == GOT_UNKNOWN
                      || eh->tls_type == GOT_NORMAL);
          eh->tls_type = GOT_NORMAL;
          h->got.refcount = 1;
        }
      else if (dyn
               || h->type == STT_GNU_IFUNC)
#if 0
        if (bfd_link_pic (info)
            || WILL_CALL_FINISH_DYNAMIC_SYMBOL (dyn, 0, h))
#endif /* 0  */
        {
          /* The function will be resolved at run-time. Allocate the secondary
             PLT entry and the corresponding entries in '.got.plt' and '.rela
             .got.plt'.  */

          asection *srela;
          asection *s = htab->elf.splt;

          if (s != NULL)
            srela = htab->elf.srelplt;
          else
            {
              s = htab->elf.iplt;
              srela = htab->elf.irelplt;
            }

          set_secondary_plt_idx (h, htab);

          eh->gotplt_offset = htab->elf.sgotplt->size;
          htab->elf.sgotplt->size
	    += ABI_PM_P (htab->elf.dynobj) ? 16 : htab->bytes_per_word;

          srela->size += htab->bytes_per_rela;
        }
      /* One may find himself here, for example, if the symbol is not defined
         anywhere. What should be done then?  */
    }
  else
    set_secondary_plt_idx (h, NULL);


  for (i = 0; i < 4; i++)
    {
      static const int types[] = {GOT_NORMAL, GOT_TLS_GDMOD, GOT_TLS_GDREL,
                                  GOT_TLS_IE};
      union gotplt_union *pgot;

      if ((eh->tls_type & types[i]) == 0)
        continue;

      if (types[i] == GOT_TLS_GDMOD)
        pgot = &eh->gdmod;
      else if (types[i] == GOT_TLS_IE)
        pgot = &eh->ie;
      else
        pgot = &h->got;

      if (pgot->refcount > 0)
        {
          bool dyn;

          dyn = htab->elf.dynamic_sections_created;

          /* What a hack it is! Don't forget to find out why undefined weak
             symbols are not marked as dynamic without it. This awful hack
             is present in almost all backends.
             What's the point in having dynamic symbols if we are doing a static
             link though?  */
          if (dyn
              && h->root.type == bfd_link_hash_undefweak
              && h->dynindx == -1
              && !h->forced_local)
            {
              if (! bfd_elf_link_record_dynamic_symbol (info, h))
                return false;
            }

          pgot->offset = htab->elf.sgot->size;

	  /* FIXME: excessive space is allocated for TLS .got entries in PM
	     both for elbrus-v{X<7,7}. 4 and 8 bytes are sufficient for a PM
	     TLS entry on these architectures respectively. However, such a
	     stupid approach ensures the appropriate alignment of {AP,PL}s
	     in .got without an additional effort.  */
	  htab->elf.sgot->size
	    += ABI_PM_P (htab->elf.dynobj) ? 16 : htab->bytes_per_word;

          if ((types[i] == GOT_NORMAL || types[i] == GOT_TLS_IE)
              && (ELF_ST_VISIBILITY (h->other) == STV_DEFAULT
                  || h->root.type != bfd_link_hash_undefweak)
              && (WILL_CALL_FINISH_DYNAMIC_SYMBOL (dyn, bfd_link_pic (info), h)
                  || (bfd_link_pic (info) && SYMBOL_REFERENCES_LOCAL (info, h))))
            {
              htab->elf.srelgot->size += htab->bytes_per_rela;
              eh->relgot_cntr += 1;
            }
          else if (types[i] == GOT_TLS_GDMOD || types[i] == GOT_TLS_GDREL)
            {
              if (h->dynindx != -1)
                {
                  htab->elf.srelgot->size += htab->bytes_per_rela;
                  eh->relgot_cntr += 1;
                }
              else if (types[i] == GOT_TLS_GDMOD)
                {
                  if (htab->gdmod_zero_off == (bfd_vma) -1)
                    {
                      htab->gdmod_zero_off = htab->elf.sgot->size;
                      htab->elf.sgot->size
			+= (ABI_PM_P (htab->elf.dynobj)
			    ? 16 : htab->bytes_per_word);

                      if (bfd_link_pic (info))
                        htab->elf.srelgot->size += htab->bytes_per_rela;
                    }
                }
            }
        }
      else
        pgot->offset = -1;
    }

  if ((eh->tls_type & (GOT_NORMAL | GOT_TLS_GDREL)) == 0)
    h->got.offset = (bfd_vma) -1;

  if ((eh->tls_type & GOT_TLS_IE) == 0)
    eh->ie.offset = (bfd_vma) -1;

  if (eh->dyn_relocs == NULL)
    return true;


  /* See if we can discard the previously allocated dynamic relocs.  */
  if (bfd_link_pic (info))
    {
      /* Ensure that place isn't reserved for excessive dynamic SIZE relocations
         against locally referenced symbols in a shared library. Note that they
         aren't created in this case as well as PC-relative relocations. This
         doesn't relate to ABS relocations, of course.  */
      if (SYMBOL_CALLS_LOCAL (info, h))
        {
          struct e2k_elf_dyn_relocs **pp;

          for (pp = &eh->dyn_relocs; (p = *pp) != NULL; )
            {
              p->count -= p->pc_count;
              p->pc_count = 0;
              if (p->count == 0)
                *pp = p->next;
              else
                pp = &p->next;
	    }
	}

      /* Discard relocs on undefined weak syms with non-default visibility.  */
      if (eh->dyn_relocs != NULL
          && h->root.type == bfd_link_hash_undefweak)
        {
          if (ELF_ST_VISIBILITY (h->other) != STV_DEFAULT)
            eh->dyn_relocs = NULL;

	  /* Make sure undefined weak symbols are output as a dynamic
	     symbol in PIEs.  */
	  else if (h->dynindx == -1
		   && !h->forced_local)
	    {
	      if (! bfd_elf_link_record_dynamic_symbol (info, h))
		return false;
	    }
        }
    }
  else
    {
      /* For the non-shared case, discard space for relocs against symbols
         which turn out to need copy relocs or are not dynamic.

         The beginning of this comment has been borrowed from `elf32-i386.c'.
         In fact below we also get rid of relocs against dynamic symbols unless
         they are defined by a shared library taking part in the link.  */

      if (!h->non_got_ref
          && ((h->def_dynamic
               && !h->def_regular)
              || (htab->elf.dynamic_sections_created
                  && (h->root.type == bfd_link_hash_undefweak
                      || h->root.type == bfd_link_hash_undefined))))
        {
          /* Here should be a machinery for making symbol dynamic in case it
             hasn't been made before, see `elf32-i386.c'. By the way, they say
             that  undefined weak symbols `won't yet be marked as dynamic'.
             Let's skip it for now and implement when we have an appropriate
             test to understand this in detail . . .  */

          if (h->dynindx != -1)
            goto keep;
        }

      eh->dyn_relocs = NULL;

    keep: ;
    }

  /* Allocate space for various `.rela. . . ' dynamic relocation sections.  */
  for (p = eh->dyn_relocs; p != NULL; p = p->next)
    {
      asection *sreloc = elf_section_data (p->sec)->sreloc;
      sreloc->size += p->count * htab->bytes_per_rela;
    }

  return true;
}

static bool
finalize_plt_offsets (struct elf_link_hash_entry *h, void *inf)
{
  struct bfd_link_info *info = (struct bfd_link_info *) inf;
  struct _bfd_e2k_elf_link_hash_table *htab
    = _bfd_e2k_elf_hash_table (info);

  struct _bfd_e2k_elf_link_hash_entry *eh
    = (struct _bfd_e2k_elf_link_hash_entry *) h;

  if (eh->finalize_plt_offset)
    {
      h->root.u.def.value = plt_offset (h, htab);
      eh->finalize_plt_offset = 0;
    }

  return true;
}

/* Find any dynamic relocs that apply to read-only sections.  */

static bool
readonly_dynrelocs (struct elf_link_hash_entry *h, void * inf)
{
  struct _bfd_e2k_elf_link_hash_entry *eh;
  struct e2k_elf_dyn_relocs *p;

  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;
  for (p = eh->dyn_relocs; p != NULL; p = p->next)
    {
      asection *s = p->sec->output_section;

      if (s != NULL && (s->flags & SEC_READONLY) != 0)
	{
	  struct bfd_link_info *info = (struct bfd_link_info *) inf;

	  info->flags |= DF_TEXTREL;

          if (bfd_link_textrel_check (info))
	    info->callbacks->einfo (_("%P: %pB: warning: relocation against `%s' "
                                      "in readonly section `%pA'.\n"),
				    p->sec->owner, h->root.root.string,
				    p->sec);

	  /* Not an error, just cut short the traversal.  */
	  return false;
	}
    }
  return true;
}

bool
_bfd_e2k_elf_size_dynamic_sections (bfd *output_bfd ATTRIBUTE_UNUSED,
                                    struct bfd_link_info *info)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  bfd *dynobj;
  bfd *ibfd;
  asection *s;

  htab = _bfd_e2k_elf_hash_table (info);
  if (htab == NULL)
    return false;
  dynobj = htab->elf.dynobj;
  if (dynobj == NULL)
    abort ();

  for (ibfd = info->input_bfds; ibfd != NULL; ibfd = ibfd->link.next)
    {
      bfd_signed_vma *local_got, *local_ie;
      bfd_signed_vma *end_local_got;
      char *local_tls_type;
      char *local_relgot_cntr;
      bfd_size_type locsymcount;
      Elf_Internal_Shdr *symtab_hdr;
      asection *srel;

      if (! is_e2k_elf (ibfd))
	continue;

      for (s = ibfd->sections; s != NULL; s = s->next)
        {
          struct e2k_elf_dyn_relocs *p;
          for (p = elf_section_data (s)->local_dynrel; p != NULL; p = p->next)
            {
              /* Local symbols shouldn't require an entry in `.rela.xxx' when
                 referenced via a SIZE relocation.  */
              p->count -= p->pc_count;
              p->pc_count = 0;

              if (p->count != 0)
                {
#if 0
		  if (! ABI_PM_P (dynobj))
#endif
		    {
		      srel = elf_section_data (p->sec)->sreloc;
		      srel->size += p->count * htab->bytes_per_rela;
		      if ((p->sec->output_section->flags & SEC_READONLY) != 0
			  && (info->flags & DF_TEXTREL) == 0)
			{
			  info->flags |= DF_TEXTREL;
			  if (bfd_link_textrel_check (info))
			    info->callbacks->einfo
			      (_("%P: %pB: warning: relocation in readonly "
				 "section `%pA'.\n"), p->sec->owner, p->sec);
			}
		    }
		}
	    }
	}

      local_got = elf_local_got_refcounts (ibfd);
      if (local_got == NULL)
        continue;

      /* These ones are always allocated right after local_got in
         check_relocs (), therefore We don't compare them with NULL.  */
      local_ie = _bfd_e2k_elf_local_ie_refcounts (ibfd);
      /* An array containing a number of '.rela.got' entries related to each
         local symbol.  */
      local_relgot_cntr = _bfd_e2k_elf_local_relgot_cntr (ibfd);

      symtab_hdr = &elf_symtab_hdr (ibfd);
      locsymcount = symtab_hdr->sh_info;
      end_local_got = local_got + locsymcount;
      local_tls_type = _bfd_e2k_elf_local_got_tls_type (ibfd);
      s = htab->elf.sgot;
      srel = htab->elf.srelgot;

      for (; local_got < end_local_got;
           ++local_got, ++local_ie, ++local_tls_type, ++local_relgot_cntr)
        {
          int i;
          static const int types[] = {GOT_NORMAL, GOT_TLS_GDMOD, GOT_TLS_GDREL,
                                      GOT_TLS_IE};
          for (i = 0; i < 4; i++)
            {
              bfd_signed_vma *entry;

              if ((*local_tls_type & types[i]) == 0)
                continue;

              if (types[i] == GOT_TLS_IE)
                entry = local_ie;
              else
                entry = local_got;

              /* See if there are any references related to the type of access
                 under consideration.  */
              if (*entry > 0)
                {
                  /* For local symbols we need one GOT entry to store the result
                     of R_E2K_TLS_XX_DTPMOD processing against a dynamic symbol
                     with zero index. Certainly, when linking a shared library
                     we need one entry in .rela.got for the mentioned dynamic
                     relocation as well. Note that since this symbol turns out
                     to be LOCAL the result of this relocation's processing by
                     ld.so is a runtime index of the containing dynamic object.
                     For an executable it's known at linktime and turns out to
                     be equal to 1 (see processing of R_E2K_TLS_GDMOD in
                     `relocate_section ()').  */
                  if (types[i] == GOT_TLS_GDMOD
                      && htab->gdmod_zero_off == (bfd_vma) -1)
                    {
                      htab->gdmod_zero_off = s->size;
                      s->size += ABI_PM_P (dynobj) ? 16 : htab->bytes_per_word;
                      if (bfd_link_pic (info))
                        srel->size += htab->bytes_per_rela;
                      /* We don't increase *local_relgot_cntr here intentionally
                         since this relocation may be shared among multiple
                         local symbols.  */
                    }

                  /* One GOT entry is required to store the symbol's runtime
		     offset (in case of IE and GDREL) or address (in case of
                     GOT_NORMAL) depending on the type of access under
                     consideration.  */
                  if (types[i] != GOT_TLS_GDMOD)
                    {
                      *entry = s->size;
                      s->size += ABI_PM_P (dynobj) ? 16 : htab->bytes_per_word;
                    }


                  /* Allocate space for the corresponding entry in .rela.got
                     required to produce a valid runtime offset (address). This
                     value can't be determined at linktime in GOT_{NORMAL,
                     TLS_IE} cases only when producing a shared library.  */
                  if (bfd_link_pic (info)
                      && (types[i] == GOT_NORMAL
                          || types[i] == GOT_TLS_IE))
                    {
                      srel->size += htab->bytes_per_rela;
                      *local_relgot_cntr += 1;
                    }
                }
            }
        }
    }

  elf_link_hash_traverse (&htab->elf, allocate_dynrelocs, info);

  if (htab->primary_plt_num || htab->secondary_plt_num)
    {
      s = htab->elf.splt;
      if (s == NULL)
	s = htab->elf.iplt;

      BFD_ASSERT (s != NULL);

      /* Setup hash table members related to PLT trampolines which coudn't be
	 set in `_bfd_e2k_elf_link_hash_table_create ()' because of the
	 unavailability of INFO.  */
      _bfd_e2k_elf_link_hash_table_finalize (info);
      s->size = htab->plt_got_header_size;
      BFD_ASSERT (s->size < 0xdc0);

      if (htab->secondary_plt_num)
	s->size = (safe_plt_offset (s->size, htab->secondary_plt_num - 1,
				    htab->plt_got_secondary_entry_size)
		   + htab->plt_got_secondary_entry_size);

      if (htab->primary_plt_num)
	s->size = (safe_plt_offset (s->size, htab->primary_plt_num - 1,
				    htab->plt_got_primary_entry_size)
		   + htab->plt_got_primary_entry_size);
    }

  /* Now that space has been allocated for all primary and secondary PLT
     entries it should be possible to set values to final primary PLT offsets
     for symbols requiring this.  */
  elf_link_hash_traverse (&htab->elf, finalize_plt_offsets, info);

  /* The sizes of the various dynamic sections have been determined by now.
     Allocate memory for them.  */
  for (s = dynobj->sections; s != NULL; s = s->next)
    {
      if ((s->flags & SEC_LINKER_CREATED) == 0)
	continue;

      if (startswith (bfd_section_name (s), ".rela"))
        {
          /* The "reloc_count" field is used as a counter if one needs
	     to copy relocs into the output file.  */
	  s->reloc_count = 0;
        }
      else if (s != htab->elf.sgot
               && s != htab->elf.sgotplt
               && s != htab->elf.splt
               && s != htab->elf.iplt)
	{
	  /* It's not one of our sections, so don't allocate space.  */
	  continue;
	}

      if (s->size == 0)
        {
          /* This lets us get rid of such sections as `.rela.iplt' in case they
             are not really needed. The failure to do so may result in an empty
             `.rela.dyn' section in the output BFD: it won't be excluded because
             of its input sections (e.g., the aforementioned `.rela.iplt')
             without SEC_EXCLUDE flag set.  */
          s->flags |= SEC_EXCLUDE;
          continue;
        }

      if ((s->flags & SEC_HAS_CONTENTS) == 0)
	continue;

      /* Allocate memory for the section contents.  bfd_zalloc () is
	 used here in case unused entries are not reclaimed before the
	 section's contents are written out.  This should not happen,
	 but this way if it does, we get a R_E2K_NONE reloc instead
	 of garbage.  */
      s->contents = (unsigned char *) bfd_zalloc (dynobj, s->size);
      if (s->contents == NULL)
	return false;
    }

#if 0
  if (ABI_PM_P (dynobj)
      && (s = bfd_get_linker_section (dynobj, ".dynamic")) != NULL)
    {
      const struct elf_backend_data *bed;
      bfd_byte *dyncon, *dynconend;
      size_t dynsize;

      bed = get_elf_backend_data (dynobj);
      dynsize = bed->s->sizeof_dyn;
      dynconend = s->contents + s->size;
    }
#endif

  if (htab->getpl)
    {
      htab->getpl->contents
	= (unsigned char *) bfd_zalloc (dynobj, sizeof (getpl_body));
      memcpy (htab->getpl->contents, getpl_body, sizeof (getpl_body));
    }



  if (htab->elf.dynamic_sections_created)
    {
#define add_dynamic_entry(TAG, VAL)             \
      _bfd_elf_add_dynamic_entry (info, TAG, VAL)

      if (bfd_link_executable (info))
        {
          if (!add_dynamic_entry (DT_DEBUG, 0))
            return false;
        }

      if (!add_dynamic_entry (DT_RELA, 0)
	  || !add_dynamic_entry (DT_RELASZ, 0)
	  || !add_dynamic_entry (DT_RELAENT, htab->bytes_per_rela))
	return false;

      /* If any dynamic relocs apply to a read-only section,
         then we need a DF_TEXTREL flag.  */
      if ((info->flags & DF_TEXTREL) == 0)
        elf_link_hash_traverse (&htab->elf, readonly_dynrelocs, info);

      /* Finally the presence of a DF_TEXTREL flag leads to the creation
         of a DT_TEXTREL entry. As far as We understand, this is needed
         since new dynamic tags are not created by default (see a description
         of the `--enable-new-dtags' option). Are we going to obtain both
         DT_FLAGS and DT_TEXTREL in case the aforementioned option is set?  */
      if (info->flags & DF_TEXTREL)
	{
	  if (!add_dynamic_entry (DT_TEXTREL, 0))
	    return false;
	}

      if (htab->elf.srelplt->size > 0)
        {
	  if (! add_dynamic_entry (DT_E2K_LAZY_GOT, 0))
	    return false;
	}

      if (htab->elf.srelplt->size > 0
	  /* In Protected Mode DT_PLTGOT has a special meaning unrelated to
	     `.plt', therefore, it should be always present.  */
	  || ABI_PM_P (htab->elf.dynobj))
	{
	  if (! add_dynamic_entry (DT_PLTGOT, 0))
	    return false;
	}

      if (htab->elf.srelplt->size > 0
	  && ABI_PM_P (htab->elf.dynobj))
	{
	  /* However, we do need the real DT_PLTGOT too if we are to implement
	     lazy binding in PM.  */
	  if (! add_dynamic_entry (DT_REAL_PLTGOT, 0))
	    return false;
	  
	}

      if (htab->elf.srelplt->size > 0)
	{
	  if (! add_dynamic_entry (DT_PLTRELSZ, 0)
	      || ! add_dynamic_entry (DT_PLTREL, DT_RELA)
	      || ! add_dynamic_entry (DT_JMPREL, 0))
	    return false;
        }

      /* These ones are purely PM-specific.  */
      if (ABI_PM_P (htab->elf.dynobj))
	{
	  if (! add_dynamic_entry (DT_PLTGOTSZ, 0)
	      || ! add_dynamic_entry (DT_INIT_GOT, 0)
	      || ! add_dynamic_entry (DT_E2K_NO_SELFINIT, 0x1))
	    return false;
	}
    }

  return true;
}

unsigned int
_bfd_e2k_elf_action_discarded (asection *sec)
{
  if (strcmp (".mcst.parallelism", sec->name) == 0)
    return PRETEND;

  return _bfd_elf_default_action_discarded (sec);
}

/* Return the base VMA address which should be subtracted from real addresses
   when resolving @dtpoff relocation.
   This is PT_TLS segment p_vaddr.  */

static bfd_vma
_bfd_e2k_elf_dtpoff_base (struct bfd_link_info *info)
{
  /* If tls_sec is NULL, we should have signalled an error already.  */
  if (elf_hash_table (info)->tls_sec == NULL)
    return 0;
  return elf_hash_table (info)->tls_sec->vma;
}


/* Return the base VMA address which should be subtracted from real addresses
   when resolving @tprel() relocation.
   Main program TLS (whose template starts at PT_TLS p_vaddr)
   is assigned offset round(sizeof tcbhead_t) == 2 * size_of_pointer,
   PT_TLS p_align).  */

static bfd_vma
_bfd_e2k_elf_tpoff_base (struct bfd_link_info *info,
			 bool protected_mode)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  asection *tls_sec;

  htab = _bfd_e2k_elf_hash_table (info);
  tls_sec = elf_hash_table (info)->tls_sec;

  /* FIXME: this may happen if we have no TLS data in any of the input BFDs but
     some of them contain references to such variables via the Local Exec TLS
     model. Such an invalid situation happens within libm.so compiled with my
     rudimentary `e2k-linux-gcc': there are no `__thread'-variables defined
     within it but there are numerous references to `errno'. To let the linkage
     succeed and not crash here just return something . . .  */
  if (tls_sec == NULL)
    return 0;

  return (tls_sec->vma
	  - align_power ((protected_mode
			  /* This somehow takes into account that 2 Array
			     Pointers are likely to be allocated at the start
			     of __thread area at runtime in Protected Mode.  */
			  ? 2 * 16
			  : (bfd_vma) 2 * htab->bytes_per_word),
			 tls_sec->alignment_power));
}


int
simulate_relocate_section (bfd *input_bfd,
                           asection *input_section,
                           bfd_byte *contents,
                           Elf_Internal_Rela *relocs)
{
  Elf_Internal_Rela *rel = relocs;
  Elf_Internal_Rela *relend = relocs + input_section->reloc_count;

  for (; rel < relend; rel++)
    {
      bfd_vma relocation = 0;
      unsigned int r_type = ELF_R_TYPE (input_bfd, rel->r_info);
      reloc_howto_type *howto = _bfd_e2k_elf_howto_table + r_type;

      /* FIXME? LAS seems to be incapable of treating "preprocessed" expressions
         (i.e. those ones produced by `e2k-linux-as --preprocess') like
         `$inmask-2' properly (i.e. as a sum of `inmask' symbol and `-2'
         addend). It emits a relocation against `inmask-2' symbol instead with
         zero addend. To eliminate divergences in linked files due to such a
         stupid behaviour of LAS, the actual relocation's addend is replaced
         with zero below.  */
      _bfd_final_link_relocate (howto, input_bfd, input_section,
                                contents, rel->r_offset,
                                relocation,
                                rel->r_addend);
    }

  return true;
}


int
_bfd_e2k_elf_relocate_section (bfd *output_bfd,
                               struct bfd_link_info *info,
                               bfd *input_bfd,
                               asection *input_section,
                               bfd_byte *contents,
                               Elf_Internal_Rela *relocs,
                               Elf_Internal_Sym *local_syms,
                               asection **local_sections)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  bfd_vma *local_got_offsets, *local_ie_offsets;
  char *local_relgot_cntr;
  Elf_Internal_Rela *rel;
  Elf_Internal_Rela *relend;
  int res = true;

  BFD_ASSERT (is_e2k_elf (input_bfd));

  htab = _bfd_e2k_elf_hash_table (info);
  if (htab == NULL)
    return false;

  if (simulating_mode)
    return simulate_relocate_section (input_bfd, input_section, contents,
                                      relocs);

  symtab_hdr = &elf_symtab_hdr (input_bfd);
  sym_hashes = elf_sym_hashes (input_bfd);
  local_got_offsets = elf_local_got_offsets (input_bfd);
  local_ie_offsets = _bfd_e2k_elf_local_ie_offsets (input_bfd);
  local_relgot_cntr = _bfd_e2k_elf_local_relgot_cntr (input_bfd);
  
  rel = relocs;
  relend = relocs + input_section->reloc_count;
  for (; rel < relend; rel++)
    {
      unsigned int r_type;
      reloc_howto_type *howto;
      unsigned long r_symndx;
      asection *sec;
      bfd_vma relocation;
      bool unresolved_reloc;
      struct elf_link_hash_entry *h;
      struct _bfd_e2k_elf_link_hash_entry *eh;
      Elf_Internal_Sym *sym;
      bfd_vma r_addend;
      bfd_vma off;
      bfd_vma st_size;
      bfd_reloc_status_type r;

      r_type = ELF_R_TYPE (input_bfd, rel->r_info);

      switch (r_type)
        {
        case R_E2K_32_ABS:
        case R_E2K_32_PC:
        case R_E2K_64_ABS:
        case R_E2K_64_ABS_LIT:
        case R_E2K_64_PC_LIT:
	case R_E2K_64_PC:
        case R_E2K_TLS_GDMOD:
        case R_E2K_TLS_GDREL:
        case R_E2K_TLS_IE:
        case R_E2K_32_TLS_LE:
        case R_E2K_64_TLS_LE:
        case R_E2K_TLS_32_DTPMOD:
        case R_E2K_TLS_32_DTPREL:
        case R_E2K_TLS_64_DTPMOD:
        case R_E2K_TLS_64_DTPREL:
        case R_E2K_GOT:
	case R_E2K_AP_GOT:
	case R_E2K_PL_GOT:
        case R_E2K_GOTPLT:
        case R_E2K_GOTOFF:
	case R_E2K_64_GOTOFF:
	case R_E2K_64_GOTOFF_LIT:
        case R_E2K_DISP:
        case R_E2K_PREF:
        case R_E2K_ISLOCAL:
        case R_E2K_ISLOCAL32:
        case R_E2K_32_SIZE:
        case R_E2K_64_SIZE:
	case R_E2K_AP:
	case R_E2K_PL:
        case R_E2K_NONE:
	case R_E2K_64_DYNOPT:
	case R_E2K_32_DYNOPT:
	case R_E2K_ALIGN_RELAX:
	case R_E2K_MCSTBUG_140436_RELAX:
          break;
        default:
          _bfd_error_handler
	    (_("%pB: unrecognized relocation (0x%x) in section `%pA'"),
	     input_bfd, r_type, input_section);
	  bfd_set_error (bfd_error_bad_value);
	  return false;
        }

      howto = _bfd_e2k_elf_howto_table + r_type;

      r_symndx = ELF_R_SYM (input_bfd, rel->r_info);
      h = NULL;
      eh = NULL;
      sym = NULL;
      sec = NULL;

      if (r_symndx < symtab_hdr->sh_info)
        {
          sym = local_syms + r_symndx;
          sec = local_sections[r_symndx];
          /* Keep in mind that rel->r_addend may very well change after this
             call if we migrate to a new MERGED section. Therefore, set our
             local R_ADDEND variable below.  */
          relocation = _bfd_elf_rela_local_sym (output_bfd, sym, &sec, rel);
          st_size = sym->st_size;

	  /* Let --relaxed-e2k-pm-check inhibit these checks (Bug #156213,
	     Comment #4).  */
	  if (! relaxed_e2k_pm_check
	      && ABI_PM_P (input_bfd))
	    {
	      if (ELF_ST_TYPE (sym->st_info) == STT_OBJECT
		  && (sec->flags & SEC_CODE) != 0)
		{
		  _bfd_error_handler
		    (_("%pB(%pA+0x%lx): cannot resolve relocation `%s' against `%s' "
		       "variable defined in text segment: references to "
		       "data in text segment are not supported yet in PM"),
		     input_bfd, input_section, (long) rel->r_offset,
		     howto->name,
		     bfd_elf_string_from_elf_section (input_bfd,
						      symtab_hdr->sh_link,
						      sym->st_name));
		  res = false;
		  continue;
		}
	      else if (ELF_ST_TYPE (sym->st_info) == STT_FUNC
		       && (sec->flags & SEC_CODE) == 0)
		{
		  _bfd_error_handler
		    (_("%pB(%pA+0x%lx): cannot resolve relocation `%s' against `%s' "
		       "function defined in data segment: references to "
		       "code in data segment make no sense"),
		     input_bfd, input_section, (long) rel->r_offset,
		     howto->name,
		     bfd_elf_string_from_elf_section (input_bfd,
						      symtab_hdr->sh_link,
						      sym->st_name));
		  res = false;
		  continue;
		}
	    }
        }
      else
        {
          bool warned ATTRIBUTE_UNUSED;
          bool ignored ATTRIBUTE_UNUSED;

          RELOC_FOR_GLOBAL_SYMBOL (info, input_bfd, input_section, rel,
                                   r_symndx, symtab_hdr, sym_hashes,
                                   h, sec, relocation,
                                   unresolved_reloc, warned, ignored);
          st_size = h->size;
	  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

	  /* Let --relaxed-e2k-pm-check inhibit these checks (Bug #156213,
	     Comment #4).  */
	  if (! relaxed_e2k_pm_check
	      && ABI_PM_P (input_bfd)
	      && (h->root.type == bfd_link_hash_defined
		  || h->root.type == bfd_link_hash_defweak))
	    {
	      if (h->type == STT_OBJECT
		  && (h->root.u.def.section->flags & SEC_CODE) != 0)
		{
		  _bfd_error_handler
		    (_("%pB(%pA+0x%lx): cannot resolve relocation `%s' against `%s' "
		       "variable defined in text segment: references to "
		       "data in text segment are not supported yet in PM"),
		     input_bfd, input_section, (long) rel->r_offset,
		     howto->name, h->root.root.string);
		  res = false;
		  continue;
		}
	      else if (h->type == STT_FUNC
		       && (h->root.u.def.section->flags & SEC_CODE) == 0)
		{
		  _bfd_error_handler
		    (_("%pB(%pA+0x%lx): cannot resolve relocation `%s' against `%s' "
		       "function defined in data segment: references to "
		       "code in data segment make no sense"),
		     input_bfd, input_section, (long) rel->r_offset,
		     howto->name, h->root.root.string);
		  res = false;
		  continue;
		}

	    }
        }

      /* It turns out that relocs against symbols coming from discarded
         sections should either be removed (as it happens when doing a
         relocatable link and input section contains debugging info)
         or their `r_{info,addend}' zeroed out. The corresponding contents
         in INPUT_SECTION is cleared as well. Unfortunately at E2K
         `R_E2K_32_ABS is 0' and because of this zeroing out `r_info' is a
         bad idea. In order to set up R_E2K_NONE instead, We need the underlying
         hack with an additional loop (see also an implementation of
         RELOC_AGAINS_DISCARDED_SECTION in elf-bfd.h). Funny enough, METAG has
         the same trouble as we do, but they use their own version of this
         macro.  */
      if (sec != NULL && discarded_section (sec))
        {
          int i;
          Elf_Internal_Rela *prev_rel = rel;
          for (i = 0; i < 1; i++)
            {
              RELOC_AGAINST_DISCARDED_SECTION (info, input_bfd, input_section,
                                               rel, 1, relend, howto, 0, contents);
            }

          if (rel >= prev_rel)
            {
              /* This means that the relocation was not removed, its
                 `r_{info,addend}' were zeroed out instead.  */

              prev_rel->r_info = htab->r_info (0, R_E2K_NONE);
            }

          /* Really continue now rather than inside
             RELOC_AGAINST_DISCARDED_SECTION  */
          continue;
        }

      if (bfd_link_relocatable (info))
        continue;

      /* We suppose, We may set R_ADDEND now.  */
      r_addend = rel->r_addend;

      if (h != NULL
          && h->type == STT_GNU_IFUNC
          && h->def_regular)
        {
          asection *plt_sec;

          plt_sec = htab->elf.splt;
          if (plt_sec == NULL)
            plt_sec = htab->elf.iplt;

          switch (r_type)
            {
              /* Indirect functions should be never considered local in
                 fact.  */
            case R_E2K_ISLOCAL:
              relocation = 0xc0;
              goto do_relocation;

            case R_E2K_ISLOCAL32:
              relocation = 0x0;
              goto do_relocation;

            case R_E2K_GOT:
	    case R_E2K_AP_GOT:
	    case R_E2K_PL_GOT:
            case R_E2K_GOTPLT:
              break;

            case R_E2K_64_ABS:
            case R_E2K_64_ABS_LIT:
              relocation = (plt_sec->output_section->vma
                            + plt_sec->output_offset
                            + plt_offset (h, htab));

              if (r_type == R_E2K_64_ABS_LIT)
                goto process_r_e2k_64_abs_lit;
              else
                goto common_processing;

              /* The usage of R_E2K_GOTOFF against IFUNC symbols shouldn't
                 cause any problems on E2K unlike i386: one can just use the
                 related PLT entry to resolve it. On i386 that's impossible
                 since `%ebx' should be specially initialized when performing a
                 CALL via PLT.  */
            case R_E2K_GOTOFF:
	    case R_E2K_64_GOTOFF:
              relocation = (plt_sec->output_section->vma
			    + plt_sec->output_offset
                            + plt_offset (h, htab)
                            - htab->elf.sgotplt->output_section->vma
                            - htab->elf.sgotplt->output_offset);

	      if (r_type == R_E2K_64_GOTOFF)
		{
		  relocation += r_addend;
		  r_addend = 0;
		  relocation = ((relocation >> 32)
				| ((relocation & 0xffffffff) << 32));
		}

              goto do_relocation;

            case R_E2K_DISP:
              relocation = (plt_sec->output_section->vma
			    + plt_sec->output_offset + plt_offset (h, htab));
              goto do_relocation;

            default:
              /* FIXME: perform some output here and call `bfd_set_error ()'.
                 Otherwise LD will finish without a meaningful error message.
                 Moreover, it'll output something like "final link failed:
                 bfd_errmsgs[coresponding_to_a_stale_bfd_error]".  */
              return false;
            }
        }

      switch (r_type)
        {
	case R_E2K_ALIGN_RELAX:
	case R_E2K_MCSTBUG_140436_RELAX:
	  continue;

        case R_E2K_GOT:
	case R_E2K_AP_GOT:
	case R_E2K_PL_GOT:
        case R_E2K_GOTPLT:
	  /* Relocation is to the entry for this symbol in the global
	     offset table.  */
          if (htab->elf.sgot == NULL)
            abort ();

          if (h != NULL)
            {
              bool dyn;
              bool entry_created = false;

              if (r_type == R_E2K_GOTPLT
                  && secondary_plt_idx (h) != (bfd_vma) -1)
                off = eh->gotplt_offset;
              else
                off = h->got.offset;

              if (off == (bfd_vma) -1)
                break;

	      dyn = elf_hash_table (info)->dynamic_sections_created;

              if (bfd_link_pic /* dll  */ (info)
                  && SYMBOL_REFERENCES_LOCAL (info, h)
                  && ! WILL_CALL_FINISH_DYNAMIC_SYMBOL (dyn, bfd_link_pic (info), h))
                {
                  if ((off & 1) != 0)
                    off &= ~1;
                  else
                    {
                      asection *s;
                      Elf_Internal_Rela outrel;

                      /* R_E2K_XX_RELATIVE reloc needs to be generated for the
			 dynamic linker here.  */
                      s = htab->elf.srelgot;
                      BFD_ASSERT (s != NULL);

                      outrel.r_offset = (htab->elf.sgot->output_section->vma
                                         + htab->elf.sgot->output_offset
                                         + off);

		      outrel.r_addend = relocation;
                      relocation = 0;

		      if (! ABI_PM_P (input_bfd))
			outrel.r_info = htab->r_info (0, htab->relative_reloc);
		      else
			{
			  outrel.r_info
			    = htab->r_info (0, (eh->pm_got_type == 1
						? R_E2K_AP : R_E2K_PL));
			  outrel.r_offset
			    = adjust_offset_in_cud_gd (info, outrel.r_offset);

			  outrel.r_addend
			    = adjust_offset_in_cud_gd (info, outrel.r_addend);
			}

                      BFD_ASSERT (--eh->relgot_cntr >= 0);
                      elf_append_rela (output_bfd, s, &outrel);

		      if (ABI_PM_P (input_bfd) && eh->pm_got_type == 1)
			htab->put_word (output_bfd, h->size << 32,
					htab->elf.sgot->contents + off + 8);

                      entry_created = true;
                    }
                }
              else if (! WILL_CALL_FINISH_DYNAMIC_SYMBOL (dyn, bfd_link_pic (info), h)
		       || ((r_type == R_E2K_AP_GOT || r_type == R_E2K_PL_GOT)
			   && SYMBOL_REFERENCES_LOCAL (info, h)))
		{
		  // ? ? ? sleep (500);
                  if ((off & 1) != 0)
                    off &= ~1;
                  else
                    {
                      unsigned char *got_contents;
                      if (r_type == R_E2K_GOTPLT
                          && secondary_plt_idx (h) != (bfd_vma) -1)
                        got_contents = htab->elf.sgotplt->contents;
                      else
                        got_contents = htab->elf.sgot->contents;

                      htab->put_word (output_bfd, 
				      ((r_type == R_E2K_AP_GOT
					|| r_type == R_E2K_PL_GOT)
				       ? 0
				       : relocation),
                                      got_contents + off);

                      entry_created = true;
                    }
                }

              if (entry_created)
                {
                  if (r_type == R_E2K_GOTPLT
                      && secondary_plt_idx (h) != (bfd_vma) -1)
                    eh->gotplt_offset |= 1;
                  else
                    h->got.offset |= 1;
                }
            }
          else
            {
              if (local_got_offsets == NULL)
                abort ();

              off = local_got_offsets[r_symndx];
              if ((off & 1) != 0)
                off &= ~1;
              else
                {
                  if (bfd_link_pic (info))
                    {
                      asection *s;
                      Elf_Internal_Rela outrel;

                      /* R_E2K_XX_RELATIVE reloc needs to be generated for the
			 dynamic linker here.  */
                      s = htab->elf.srelgot;
                      BFD_ASSERT (s != NULL);

                      outrel.r_offset = (htab->elf.sgot->output_section->vma
                                         + htab->elf.sgot->output_offset
                                         + off);
		      outrel.r_addend = relocation;

		      if (! ABI_PM_P (input_bfd))
			outrel.r_info = htab->r_info (0, htab->relative_reloc);
		      else
			{
			  BFD_ASSERT (r_type == R_E2K_AP_GOT
				      || r_type == R_E2K_PL_GOT);
			  outrel.r_info
			    = htab->r_info (0, (r_type == R_E2K_AP_GOT
						? R_E2K_AP : R_E2K_PL));
			  outrel.r_offset
			    = adjust_offset_in_cud_gd (info, outrel.r_offset);
			  outrel.r_addend
			    = adjust_offset_in_cud_gd (info, outrel.r_addend);

			  if (r_type == R_E2K_AP_GOT)
			    htab->put_word (output_bfd, st_size << 32,
					    htab->elf.sgot->contents + off + 8);
			}

		      /* 0 in place of the eventual AP.{base,rw,itag} fields
			 should not spoil anything in PM as well as in place
			 of the final address in ordinary modes (see put_word
			 () a few lines below).  */
                      relocation = 0;

                      BFD_ASSERT (--local_relgot_cntr[r_symndx] >= 0);
                      elf_append_rela (output_bfd, s, &outrel);
                    }
		  else
		    /* PM objects should not be linked in non-PIC way
		       nowadays. In other ("ordinary") modes the evaluated
		       "relocation" value is just output in place instead
		       of creating a relative dynamic one.  */
		    BFD_ASSERT (! ABI_PM_P (input_bfd));

                  htab->put_word (output_bfd, relocation,
                                  htab->elf.sgot->contents + off);
                  local_got_offsets[r_symndx] |= 1;
                }
            }

	  /* In Protected Mode a GOT entry is accessed directly via its address
	     in the data segment.  */
	  if (r_type == R_E2K_AP_GOT || r_type == R_E2K_PL_GOT)
	    {
	      relocation = (htab->elf.sgot->output_section->vma
			    + htab->elf.sgot->output_offset
			    + off);

	      /* Starting from elbrus-v7 the evaluation of these relocations
		 should result in offsets from _GLOBAL_OFFSET_TABLE_, not from
		 GD.base as it takes place on elbrus-v{X<=6}.  */
	      if (e2k_arch_info_mach_to_iset (input_bfd->arch_info->mach) >= 7)
		relocation -= (htab->elf.sgotplt->output_section->vma
			       - htab->elf.sgotplt->output_offset);
	    }
          /* Offset with respect to '_GLOBAL_OFFSET_TABLE' symbol should be
             substituted during the link process in non-protected modes.  */
	  else
	    relocation = ((r_type == R_E2K_GOT
			   || secondary_plt_idx (h) == (bfd_vma) -1)
			  ? (htab->elf.sgot->output_section->vma
			     + htab->elf.sgot->output_offset
			     + off
			     - htab->elf.sgotplt->output_section->vma
			     - htab->elf.sgotplt->output_offset)
			  : off);
          break;

	relocate_gotoff:
        case R_E2K_GOTOFF:
	case R_E2K_64_GOTOFF:
	case R_E2K_64_GOTOFF_LIT:
	  /* Relocation is relative to the start of the global offset
	     table.  */

          /* Check to make sure it isn't a protected function or data
	     symbol for shared library since it may not be local when
	     used as function address or with copy relocation.  One also
	     needs to ensure that the symbol is referenced locally.  */
	  if (!bfd_link_executable (info) && h)
	    {
              if (!h->def_regular)
                {
                  const char *v;

		  switch (ELF_ST_VISIBILITY (h->other))
		    {
                    case STV_HIDDEN:
                      v = _("hidden symbol");
                      break;
                    case STV_INTERNAL:
                      v = _("internal symbol");
                      break;
                    case STV_PROTECTED:
                      v = _("protected symbol");
                      break;
                    default:
                      v = _("symbol");
                      break;
                    }

                  _bfd_error_handler
                    (_("%pB: relocation `%s' against undefined %s `%s' can not be used when making a shared object"),
                     input_bfd, howto->name, v, h->root.root.string);
                  bfd_set_error (bfd_error_bad_value);
                  return false;
		}
              else if (!SYMBOL_REFERENCES_LOCAL (info, h)
                       && (h->type == STT_FUNC
                           || h->type == STT_OBJECT)
                       && ELF_ST_VISIBILITY (h->other) == STV_PROTECTED
		       /* In PM R_E2K_32_ABS may be used not only as an analog
			  of R_E2K_GOTOFF but also in exactly the same sense as
			  in ordinary modes when it comes to debug info.
			  FIXME(?): shouldn't one introduce some sort of
			  "R_E2K_PM_GOTOFF" to distinguish it from
			  R_E2K_32_ABS.  */
		       && ! (ABI_PM_P (input_bfd)
			     && r_type == R_E2K_32_ABS))
		{
		  _bfd_error_handler
		    (_("%pB: relocation `%s' against protected %s `%s' can not be used when making a shared object"),
		     input_bfd,
		     howto->name,
		     h->type == STT_FUNC ? "function" : "data",
		     h->root.root.string);

		  bfd_set_error (bfd_error_bad_value);
		  return false;
		}
	    }

	  /* In an ordinary (i.e. non-PM) mode one finds himself here for one
	     of GOTOFF relocations.  */
	  if (! ABI_PM_P (input_bfd))
	    relocation -= (htab->elf.sgotplt->output_section->vma
			   + htab->elf.sgotplt->output_offset);

	  if (r_type == R_E2K_64_GOTOFF_LIT)
	    {
	      relocation += r_addend;
	      r_addend = 0;
	      relocation = ((relocation >> 32)
			    | ((relocation & 0xffffffff) << 32));
	    }

          break;

        case R_E2K_DISP:
          if (h != NULL && plt_idx (h) != (bfd_vma) -1)
            {
              relocation = (htab->elf.splt->output_section->vma
                            + htab->elf.splt->output_offset
                            + plt_offset (h, htab));
            }
          break;

        case R_E2K_PREF:
          {
            bfd_vma hline_mask = ~0x7f;
            bfd_vma wc_offs;

            /* Get the contents of PDISP field which should contain the offset
               of this syllable within the current wide command. By convention
               it's stored within the `pdisp' field (see MCSTBug #68612,
               Comment #24).  */
            wc_offs = bfd_get_32 (input_bfd, contents + rel->r_offset);
            wc_offs &= 0x0ffffff0;
            wc_offs >>= 4;

            relocation = (((relocation
                            + r_addend)
                           & hline_mask)
                          - ((input_section->output_section->vma
                              + input_section->output_offset
                              + rel->r_offset
                              - wc_offs)
                             & hline_mask));
          }

          /* This relocation may become too peculiar to process it via
             `_bfd_final_link_relocate ()', though at present it's almost
             possible (see the formula in MCSTBug #68612, Comment #0). Anyway, it
             may be a better idea to call `_bfd_relocate_contents ()' rather
             than to set `r_addend' to zero as We used to do . . .  */
          _bfd_relocate_contents (howto, input_bfd, relocation,
                                  contents + rel->r_offset);
          continue;

        case R_E2K_32_SIZE:
        case R_E2K_64_SIZE:
          /* Set to symbol size.  */
          relocation = st_size;
          goto common_processing;

          /* Prevent _bfd_final_link_relocate from its usual actions when
	     dealing with bogus LIT-relocs. It is going to be passed a
	     swapped value which shouldn't be modified. That's why we take
	     care of these things ourselves.  */
        case R_E2K_64_PC_LIT:
          relocation -= (input_section->output_section->vma
                         + input_section->output_offset
                         + rel->r_offset);

          /* Fall through  */
        case R_E2K_64_ABS_LIT:
        process_r_e2k_64_abs_lit:
	  if (ABI_PM_P (input_bfd))
	    goto relocate_gotoff;
	  /* Fall through.  */
          relocation += r_addend;
          relocation = (relocation >> 32) | ((relocation & 0xffffffff) << 32);
          /* Don't zero `R_ADDEND' out unconditionally because its initial
             value may be required while creating a dynamic relocation
             corresponding to R_E2K_64_ABS_LIT.  */
          if (r_type == R_E2K_64_PC_LIT)
            {
              r_addend = 0;
              break;
            }

          /* Fall through  */
        case R_E2K_32_ABS:
	case R_E2K_64_ABS:
	  if (ABI_PM_P (input_bfd))
	    goto relocate_gotoff;
	  /* Fall through  */
	case R_E2K_AP:
	case R_E2K_PL:
        common_processing:
          /* This check is borrowed from elf32-i386.c . It's needed because
             for some reason we don't create sreloc section for an unallocated
             section (see check_relocs). Shouldn't we relocate sections
             containing debug info at all?  */
          if ((input_section->flags & SEC_ALLOC) == 0)
            break;
          if ((bfd_link_pic (info)
               && (h == NULL
                   /* Weak undefined symbols with non-default visibility are
                      hidden from dynamic linker, i.e. they are explicitly
                      marked as non-dynamic in `_bfd_elf_fix_symbol_flags'.
                      Creating a relative reloc against such a symbol definitely
                      leads to erroneous result: one is going to obtain library
                      base address instead of zero. As an example, consider a
                      `visibility (hidden_weak) (non PIC)' test.  */
                   || ELF_ST_VISIBILITY (h->other) == STV_DEFAULT
                   || h->root.type != bfd_link_hash_undefweak)
               && ((r_type != R_E2K_32_SIZE && r_type != R_E2K_64_SIZE)
                   || !SYMBOL_CALLS_LOCAL(info, h)))
              || (!bfd_link_pic (info)
                  && h != NULL
                  && h->dynindx != -1
                  && !h->non_got_ref
                  && h->def_dynamic
                  && !h->def_regular))
            {
              Elf_Internal_Rela outrel;
              bool skip;
	      bool relocate;
              asection *sreloc;

	      skip = false;
	      relocate = false;

              /* Take into account that the initial relocation offset may have
                 changed for "adjusted" sections like '.eh_frame' (see
                 _bfd_elf_discard_section_eh_frame () in elf-eh-frame.c for an
                 example). Alternatively the relocatable contents corresponding
                 to the current relocation may have been removed, in which case
                 it returns -1. There's also the third case, which We don't quite
                 understand yet, when -2 is returned. The i386 backend just
                 outputs a zeroed-out dynamic relocation then.

                 It's possible that `outrel.r_offset' should be calculated this
                 way not only here.  */
              outrel.r_offset =
                _bfd_elf_section_offset (output_bfd, info, input_section,
                                         rel->r_offset);

              if (outrel.r_offset == (bfd_vma) -1)
                skip = true;
              else if (outrel.r_offset == (bfd_vma) -2)
                skip = true, relocate = true;

              outrel.r_offset += (input_section->output_section->vma
                                  + input_section->output_offset);


              if (skip)
		{
		  outrel.r_offset = 0;
		  outrel.r_info = htab->r_info (0, R_E2K_NONE);
		  outrel.r_addend = 0;
		}
              else if (h != NULL
                       && h->dynindx != -1
                       && (! SYMBOLIC_BIND (info, h)
			   /* SYMBOLIC_BIND may very well return 1 for a symbol
			      mkssing from the shared library being linked with,
			      say, `-Bsymbolic-functions'. This will result in a
			      defective relative relocation against its base
			      (i.e. zero link-time address) as it happened in
			      MCSTBug #100946. This extra check borrowed from
			      `COPY_INPUT_RELOC_P()' in `bfd/elfxx-x86.h' lets
			      us prevent this from happening.  */
			   || ! h->def_regular))
                {
                  outrel.r_info = htab->r_info (h->dynindx, r_type);
                  outrel.r_addend = r_addend;
                }
              else
                {
		  if (ABI_PM_P (input_bfd))
		    {
		      outrel.r_info = htab->r_info (0, r_type);
		      outrel.r_addend
			= adjust_offset_in_cud_gd (info,
						   relocation + (r_type == R_E2K_PL ? r_addend : 0) );

		      if (r_type == R_E2K_AP)
			{
			  bfd_put_32 (output_bfd, r_addend,
				      contents + rel->r_offset + 8);
			  bfd_put_32 (output_bfd, st_size,
				      contents + rel->r_offset + 12);
			}

		      outrel.r_offset
			= adjust_offset_in_cud_gd (info, outrel.r_offset);
		    }
		  else if (r_type != R_E2K_64_ABS_LIT)
                    {
                      outrel.r_info = htab->r_info (0, htab->relative_reloc);
                      outrel.r_addend = relocation + r_addend;
                    }
                  else
                    {
                      outrel.r_info = htab->r_info (0,
                                                    htab->relative_lit_reloc);
                      /* This relocation value is not to be output into a pair
                         of literal syllables, therefore undo our preparations
                         a few dozens of lines above. Keep in mind that
                         R_ADDEND has already been taken into account during
                         these preparations.  */
                      outrel.r_addend = ((relocation >> 32)
                                         | ((relocation & 0xffffffff) << 32));
                    }
                }

              /* Keep in mind that sreloc belongs to htab->dynobj, rather than
                 to output_bfd. It's created in `check_relocs ()'.  */
              sreloc = elf_section_data (input_section)->sreloc;
              elf_append_rela (output_bfd, sreloc, &outrel);

	      /* There's no point in relocating if `_bfd_elf_section_offset ()'
		 returned `-1'. However, we should have output R_E2K_NONE
		 dynamic relocation above to avoid assertion failures due to
		 redundant space for dynamic relocations later.  */
	      if (skip && !relocate)
		continue;

              /* TODO: find out what's going to be output to this position in
                 the output section after we perform a subsequent BREAK. I
                 guess that it's `RELOCATION + R_ADDEND'. Shouldn't we zero
                 them out here? Anyway, this value is to be replaced by LDSO
                 at runtime.  */

              /* `_bfd_elf_eh_frame_section_offset ()' returns `-2', in which
                 case we set SKIP above, if it thinks that we don't need a run-
                 time relocation against '.eh_frame' section (e.g. FDE's initial
                 _location field). In this case perform a link-time relocation
                 "somehow" (currently We don't know what should be done with its
                 result at run-time). To obtain sensible results we shouldn't
                 zero out RELOCATION and R_ADDEND, otherwise we'll definitely
                 fail when checking for FDEs' potential overlaps in
                 `_bfd_elf_write_section_eh_frame_hdr ()'.  */
              if (!skip)
                {
                  relocation = 0;
                  r_addend = 0;
                }
            }
          else if (r_type == R_E2K_64_ABS_LIT)
            /* It's time to zero R_ADDEND out for this sort of relocation.
               Otherwise, it'll be taken into account twice.  */
            r_addend = 0;

          break;

        case R_E2K_TLS_GDMOD:
        case R_E2K_TLS_GDREL:
        case R_E2K_TLS_IE:
          {
            long indx;
            bfd_vma *poff;
            Elf_Internal_Rela outrel;
            char *prelgot_cntr
              = h ? &eh->relgot_cntr : &local_relgot_cntr[r_symndx];
            asection *sreloc = htab->elf.srelgot;

            indx = h && h->dynindx != -1 ? h->dynindx : 0;

            /* FIXME: stupid GCC doesn't see that OFF is sure to be initialized
               within switch below.  */
            off = 0;

            switch (r_type)
              {
              case R_E2K_TLS_GDMOD:
                poff = indx != 0 ? &eh->gdmod.offset : &htab->gdmod_zero_off;
                off = *poff;
                BFD_ASSERT (off != (bfd_vma) -1);

                if ((off & 1) != 0)
                  {
                    off &= ~1;
                    break;
                  }

                /* For a local symbol within an executable substitute the known
                   at linktime module index. Otherwise, emit DTPMOD reloc.
                   FIXME: We guess the former can be done for any symbol defined
                   within an executable.  */
                if (indx == 0 && ! bfd_link_pic (info))
                  htab->put_word (output_bfd, 1,
                                  htab->elf.sgot->contents + off);
                else
                  {
                    outrel.r_offset = (htab->elf.sgot->output_section->vma
                                       + htab->elf.sgot->output_offset
                                       + off);

                    outrel.r_addend = 0;
                    outrel.r_info = htab->r_info (indx, htab->dtpmod_reloc);

                    /* Keep in mind that gdmod_zero GOT entry isn't associated
                       with any particular local symbol, but is shared among all
                       of them. Therefore, We don't increase any symbol's relgot
                       _cntr in size_dynamic_sections () to account for the
                       underlying dynamic relocation.  */
                    if (indx != 0)
                      BFD_ASSERT (--*prelgot_cntr >= 0);

                    elf_append_rela (output_bfd, sreloc, &outrel);
                  }

                *poff |= 1;
                break;

              case R_E2K_TLS_GDREL:
                poff = h ? &h->got.offset : &local_got_offsets[r_symndx];
                off = *poff;

                if ((off & 1) != 0)
                  {
                    off &= ~1;
                    break;
                  }

                /* For a locally-defined symbol its offset with respect to the
                   beginning of PT_TLS segment (that one provided as the second
                   argument to __tls_getaddr () can be determined at link time.
                   Otherwise output a DTPOFF reloc.  */
                if (indx == 0)
                  htab->put_word (output_bfd,
                                  relocation - _bfd_e2k_elf_dtpoff_base (info),
                                  htab->elf.sgot->contents + off);
                else
                  {
                    outrel.r_addend = 0;
                    outrel.r_info = htab->r_info (indx, htab->dtpoff_reloc);
                    outrel.r_offset = (htab->elf.sgot->output_section->vma
                                       + htab->elf.sgot->output_offset
                                       + off);

                    BFD_ASSERT (--*prelgot_cntr >= 0);
                    elf_append_rela (output_bfd, sreloc, &outrel);
                  }

                *poff |= 1;
                break;

              case R_E2K_TLS_IE:
                poff = h ? &eh->ie.offset : &local_ie_offsets[r_symndx];
                off = *poff;

                if ((off & 1) != 0)
                  {
                    off &= ~1;
                    break;
                  }

                /* FIXME: to be revisited ...
		   Why should we need a dynamic IE TLS relocation in PIE
		   case?  */
                if (bfd_link_dll /* _pic  */ (info) || indx != 0)
                  {
                    if (indx == 0)
                      outrel.r_addend = (relocation
                                         - _bfd_e2k_elf_dtpoff_base (info));
                    else
                      outrel.r_addend = 0;

                    outrel.r_info = htab->r_info (indx, htab->tpoff_reloc);
                    outrel.r_offset = (htab->elf.sgot->output_section->vma
                                       + htab->elf.sgot->output_offset
                                       + off);

                    BFD_ASSERT (--*prelgot_cntr >= 0);
                    elf_append_rela (output_bfd, sreloc, &outrel);
                  }
                else
		  {
		    bfd_vma recalc
		      = (relocation
			 - _bfd_e2k_elf_tpoff_base (info, ABI_PM_P (input_bfd)));

		    htab->put_word (output_bfd, recalc,
				    htab->elf.sgot->contents + off);
		  }

                *poff |= 1;
                break;
              }

          /* Finally, calculate the value to be substituted in place the
	     processed relocation is pointing to. Note that in ordinary modes
	     and in PM on elbrus-v7 this is an offset from _GLOBAL_OFFSET_TABLE_
	     whereas in PM on elbrus-v{X<=6} - an offset within the data segment
	     (from GD.base).  */
            relocation = (htab->elf.sgot->output_section->vma
                          + htab->elf.sgot->output_offset
                          + off
			  - ((ABI_PM_P (input_bfd)
			      && (e2k_arch_info_mach_to_iset
				  (input_bfd->arch_info->mach) < 7))
			     ? 0
			     : (htab->elf.sgotplt->output_section->vma
				+ htab->elf.sgotplt->output_offset)));
          }
          break;

        case R_E2K_32_TLS_LE:
        case R_E2K_64_TLS_LE:
          relocation -= _bfd_e2k_elf_tpoff_base (info, ABI_PM_P (input_bfd));

          /* Ensure that `_bfd_final_link_relocate ()' isn't going to
             interfere with us in 64-bit case.  */
          if (r_type == R_E2K_64_TLS_LE)
            {
              relocation += r_addend;
              r_addend = 0;
              relocation = ((relocation >> 32)
                            | ((relocation & 0xffffffff) << 32));
            }
          break;

        case R_E2K_TLS_32_DTPREL:
        case R_E2K_TLS_64_DTPREL:
          relocation -= _bfd_e2k_elf_dtpoff_base (info);
          break;

        case R_E2K_ISLOCAL:
          /* For `0xc0' see encoding of 5-bit values within ALS in 6.3.1 of
             iset.single.  */
          relocation = 0xc0 | (SYMBOL_CALLS_LOCAL (info, h) ? 0x1 : 0x0);
          break;

        case R_E2K_ISLOCAL32:
          relocation = SYMBOL_CALLS_LOCAL (info, h) ? 0x1 : 0x0;
          break;

	case R_E2K_32_DYNOPT:
	case R_E2K_64_DYNOPT:
	  /* According to the purpose of @DYNOPT expressed in MCSTBug #117734,
	     Comment #11 leave relocation intact for local ELF symbols and
	     those global ones which are sure to be defined in the same
	     compilation unit, otherwise zero it out.  */
	  if (h != NULL
	      && (h->root.type != bfd_link_hash_defined
		  || h->root.u.def.section->owner != input_bfd))
	    relocation = 0;
	  break;
        }

    do_relocation:
      if (r_type == R_E2K_AP || r_type == R_E2K_PL)
	continue;

      bool restore_output_section_vma = false;
      bfd_vma saved_output_section_vma;
      /* Do not adjust relocations having other meanings than offset by
	 mistake. Are all of them taken into account below?  */
      if (ABI_PM_P (input_bfd)
	  && (input_section->flags & SEC_ALLOC) != 0 /* ???  */
	  /* What else relocations operate on offsets in CUD and GD?  */
	  && (((r_type == R_E2K_32_ABS
		|| r_type == R_E2K_64_ABS
		|| r_type == R_E2K_64_ABS_LIT
		|| r_type == R_E2K_DISP)
	       && ! (h != NULL
		     && h->root.type == bfd_link_hash_defined
		     && bfd_is_abs_section (h->root.u.def.section)))
	      /* For these relocations the offset (i.e. with respect to GD.base)
		 of a .got entry is evaluated here. It obviously needs to be
		 adjusted no matter if the target symbol is absolute or not.  */
	      || ((r_type == R_E2K_AP_GOT
		   || r_type == R_E2K_PL_GOT
		   || r_type == R_E2K_TLS_IE
		   || r_type == R_E2K_TLS_GDMOD
		   || r_type == R_E2K_TLS_GDREL)
		  /* Because starting from elbrus-v7 the evaluation of these
		     relocations results in offsets from _GLOBAL_OFFSET_TABLE_,
		     not from GD.base, there's no point in "adjusting" them as
		     GOT is not "densified" unlike the containing data
		     segment.  */
		  && (e2k_arch_info_mach_to_iset (input_bfd->arch_info->mach)
		      < 7)
		  )
	      || r_type == R_E2K_32_PC))
	{
	  /* All this idiotism is required for PC-relative relocations to be
	     performed properly in "packed mode".  */
	  saved_output_section_vma = input_section->output_section->vma;
	  input_section->output_section->vma
	    = adjust_offset_in_cud_gd (info, saved_output_section_vma);
	  restore_output_section_vma = true;

	  /* This adjustment is obviously required both for absolute and
	     PC-relative relocations.  */
	  relocation = adjust_offset_in_cud_gd (info, relocation);
	}

      if (ABI_PM_P (input_bfd) && r_type == R_E2K_64_ABS_LIT)
	{
	  relocation += r_addend;
	  r_addend = 0;
	  relocation = ((relocation >> 32)
			| ((relocation & 0xffffffff) << 32));
	}

      r = _bfd_final_link_relocate (howto, input_bfd, input_section,
				    contents, rel->r_offset,
                                    relocation, r_addend);

      if (restore_output_section_vma)
	input_section->output_section->vma = saved_output_section_vma;

      if (r != bfd_reloc_ok)
	{
	  const char *name;

	  if (h != NULL)
	    name = h->root.root.string;
	  else
	    {
	      name = bfd_elf_string_from_elf_section (input_bfd,
						      symtab_hdr->sh_link,
						      sym->st_name);
	      if (name == NULL)
		return false;
	      if (*name == '\0')
		name = bfd_section_name (sec);
	    }

	  if (r == bfd_reloc_overflow)
	    {
	      (*info->callbacks->reloc_overflow)
                (info, (h ? &h->root : NULL), name, howto->name,
                 (bfd_vma) 0, input_bfd, input_section,
                 rel->r_offset);
	    }
	  else
	    {
	      _bfd_error_handler
		(_("%pB(%pA+0x%lx): reloc against `%s': error %d"),
		 input_bfd, input_section,
		 (long) rel->r_offset, name, (int) r);
	      return false;
	    }
	}
    }

  return res;
}

bool
_bfd_e2k_elf_finish_dynamic_symbol (bfd *output_bfd,
                                    struct bfd_link_info *info,
				    struct elf_link_hash_entry *h,
                                    Elf_Internal_Sym *sym)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  struct _bfd_e2k_elf_link_hash_entry *eh;
  Elf_Internal_Rela rela;
  /* FIXME: find out if there is actually any risk of using an uninitialized
     variable below.  */
  bfd_vma gotplt_offset = 0;
  asection *splt;
  asection *srela;
  bool ifunc = false;

  htab = _bfd_e2k_elf_hash_table (info);
  BFD_ASSERT (htab != NULL);
  eh = (struct _bfd_e2k_elf_link_hash_entry *) h;

  if (secondary_plt_idx (h) != (bfd_vma) -1)
    gotplt_offset = eh->gotplt_offset & ~(bfd_vma) 1;

  if (htab->elf.splt != NULL)
    {
      splt = htab->elf.splt;
      srela = htab->elf.srelplt;
    }
  else
    {
      splt = htab->elf.iplt;
      srela = htab->elf.irelplt;
    }


  if (plt_idx (h) != (bfd_vma) -1)
    {
      if (h->type == STT_GNU_IFUNC)
        ifunc = true;

      if (secondary_plt_idx (h) == (bfd_vma) -1)
        gotplt_offset = (htab->elf.sgot->output_section->vma
                         + htab->elf.sgot->output_offset
                         + (h->got.offset & ~(bfd_vma) 1)
                         - (htab->elf.sgotplt->output_section->vma
                            + htab->elf.sgotplt->output_offset));

      build_plt_entry (info, splt, plt_offset (h, htab), gotplt_offset);

      if (!h->def_regular)
        {
          /* In case this symbol is swapped out to the symbol table as defined
             in `.plt' (see the code where We set `h->root.u.def.section' to
             `.plt' in `allocate_dynrelocs ()'), the dynamic linker will bind
             the corresponding PLT entry to itself.  */
          sym->st_shndx = SHN_UNDEF;

          if (!h->pointer_equality_needed)
            sym->st_value = 0;
        }
    }

  if (secondary_plt_idx (h) != (bfd_vma) -1)
    {
      build_secondary_plt_entry (info, secondary_plt_offset (h, htab),
                                 gotplt_offset, &rela.r_offset
                                 //, h->root.root.string
				 );
    }

  if (secondary_plt_idx (h) != (bfd_vma) -1)
    {

      if (ifunc && SYMBOL_CALLS_LOCAL (info, h))
        {
          rela.r_addend = (h->root.u.def.section->output_section->vma
                           + h->root.u.def.section->output_offset
                           + h->root.u.def.value);
          rela.r_info = htab->r_info (0, htab->irelative_reloc);
        }
      else if (bfd_link_pic (info) && SYMBOL_CALLS_LOCAL (info, h))
	/* One shouldn't find himself here . . .  */
	abort ();
      else if (h->dynindx != -1)
        {
          rela.r_addend = 0;
          rela.r_info = htab->r_info (h->dynindx, htab->jmp_slot_reloc);
        }
      else
        abort ();

      /* Why don't other backends use elf_append_rela here? They prefer to
         explicitly call swap_reloca_out instead. This is probably because they
         need to guarantee that an entry in `PLT' and the corresponding
         relocation in `.RELA.PLT' have the same index (maybe plus/minus some
         constant). This correspondence is used when calculating the relocation
         offset (relative to the value stored in  DT_JMPREL) which is to be
         encoded in the PLT entry for lazy binding to work. At present We don't
         know whether We can guarantee such a correspondence for E2K at all,
         therefore the relocation offset should be encoded separately after it
         has been appended to `.RELA.PLT'.  */

      /* The underlying assert keeps track of relocations in .rela.got, not in
         .{i,}rela.plt sections. Therefore, it's not appropriate here.
         REMINDER: probably it makes sense to implement dedicated counters for
         the latter relocation sections as well.  */
      /* BFD_ASSERT (--eh->relgot_cntr >= 0);  */
      elf_append_rela (output_bfd, srela, &rela);

      /* FIXME: in order to get rid of the need to adjust PLT entries, We should
         guarantee that the same index matches related entries within '.plt',
         '.rela.plt' (and '.got.plt' in case it's required in the current PLT
         implementation) sections. I've forgotten the reason, because of which
         We can't be sure that this condition holds right now (see my comment
         above).  */
      /* The secondary entry is not currently used in Protected Mode which is
	 made clear by setting its size to 0.  */
      if (htab->plt_got_secondary_entry_size)
        {
          const struct elf_backend_data *bed = get_elf_backend_data (output_bfd);
          bfd_vma dynrel_offset
            = (srela->reloc_count - 1) * bed->s->sizeof_rela;

          htab->adjust_plt_lazy_entry_reloc_offset
            (output_bfd, htab, splt, secondary_plt_offset (h, htab),
             dynrel_offset);
        }
    }

  if (h->got.offset != (bfd_vma) -1 && eh->tls_type == GOT_NORMAL)
    {
      if (htab->elf.sgot == NULL || htab->elf.srelgot == NULL)
	abort ();

      rela.r_offset = (htab->elf.sgot->output_section->vma
                       + htab->elf.sgot->output_offset
                       + (h->got.offset & ~(bfd_vma) 1));

      if (bfd_link_pic (info)
          && SYMBOL_REFERENCES_LOCAL (info, h))
	{
	  if (ABI_PM_P (htab->elf.dynobj))
	    {
	      rela.r_info = htab->r_info (0,
					  /* FIXME: consider keeping this info
					     in pm_got_type.  */
					  eh->pm_got_type == 1
					  ? R_E2K_AP : R_E2K_PL);

	      rela.r_offset = adjust_offset_in_cud_gd (info, rela.r_offset);
	    }
	  else
	    {
	      /* FIXME: improve your checks in `relocate_section ()' so as
		 to ensure that we don't do the same work twice. Aren't we
		 going to overflow `.rela.got' with duplicating relative
		 relocations?  */
	      /* BFD_ASSERT((h->got.offset & 1) != 0);  */
	      rela.r_info = htab->r_info (0, htab->relative_reloc);
	    }

          /* Note that we may find ourselves here in case the linkage is going
             to fail due to the fact that the symbol under consideration turns
             out to be undefined. This problem is present in elfxx-sparc.c and
             probably in some other rela-specific (rather than rel) backends.
             Don't bother about setting appropriate addend than, but avoid a
             possible SIGSEGV.  */

          if (h->def_regular)
            {
              asection *sec = h->root.u.def.section;
              rela.r_addend = (h->root.u.def.value
                               + sec->output_section->vma
                               + sec->output_offset);

	      if (ABI_PM_P (htab->elf.dynobj))
		rela.r_addend = adjust_offset_in_cud_gd (info, rela.r_addend);
            }
	  else if (h->root.type == bfd_link_hash_undefweak)
	    {
	      rela.r_info = htab->r_info (0, R_E2K_NONE);
	      rela.r_addend = 0;
	    }
          else
            rela.r_addend = 0;
        }
      else
	{
	  int reloc = htab->abs_reloc;

	  if (eh->pm_got_type == 1)
	    reloc = R_E2K_AP;
	  else if (eh->pm_got_type == 2)
	    reloc = R_E2K_PL;

	  BFD_ASSERT((h->got.offset & 1) == 0);
	  rela.r_info = htab->r_info (h->dynindx, reloc);
          rela.r_addend = 0;
	}

      /* Keep in mind that `got.offset' may still contain `1' in its least
         significant bit. Otherwise you may very well spoil a subsequent
         section!  */
      htab->put_word (output_bfd, (bfd_vma) 0,
		      htab->elf.sgot->contents
                      + (h->got.offset & ~(bfd_vma) 1));

      if (ABI_PM_P (htab->elf.dynobj))
	htab->put_word (output_bfd, (bfd_vma) h->size << 32,
			htab->elf.sgot->contents
			+ (h->got.offset & ~(bfd_vma) 1)
			+ 8);

      BFD_ASSERT (--eh->relgot_cntr >= 0);
      elf_append_rela (output_bfd, htab->elf.srelgot, &rela);
    }

  if (h->needs_copy)
    {
      /* This symbol needs a copy reloc.  Set it up.  */

      if (h->dynindx == -1
	  || (h->root.type != bfd_link_hash_defined
	      && h->root.type != bfd_link_hash_defweak)
	  || htab->srelbss == NULL)
	abort ();

      rela.r_offset = (h->root.u.def.value
                       + h->root.u.def.section->output_section->vma
                       + h->root.u.def.section->output_offset);
      rela.r_info = htab->r_info (h->dynindx, htab->copy_reloc);
      rela.r_addend = 0;
      elf_append_rela (output_bfd, htab->srelbss, &rela);
    }


  return true;
}

/* Finish up `.dynamic' section.  */
static bool
e2k_finish_dyn (bfd *output_bfd, struct bfd_link_info *info,
                bfd *dynobj, asection *sdyn,
                asection *splt ATTRIBUTE_UNUSED)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  const struct elf_backend_data *bed;
  bfd_byte *dyncon, *dynconend;
  size_t dynsize;

  htab = _bfd_e2k_elf_hash_table (info);
  BFD_ASSERT (htab != NULL);
  bed = get_elf_backend_data (output_bfd);
  dynsize = bed->s->sizeof_dyn;
  dynconend = sdyn->contents + sdyn->size;

  for (dyncon = sdyn->contents; dyncon < dynconend; dyncon += dynsize)
    {
      Elf_Internal_Dyn dyn;
      const char *name;
      bool size;

      bed->s->swap_dyn_in (dynobj, dyncon, &dyn);

      switch (dyn.d_tag)
        {
        case DT_PLTGOT:
	case DT_REAL_PLTGOT:
	  if (! ABI_PM_P (htab->elf.dynobj)
	      || dyn.d_tag == DT_REAL_PLTGOT)
	    {
	      /* In non-PM case this entry is setup in the standard way.
		 As far as We understand, OUTPUT_BFD may very well have no
		 '.got.plt' section in case it's linked into '.got'.
		 Therefore, treat this case specially. FIXME: shouldn't I
		 implement all other cases by analogy with this one?  */
	      asection *s = htab->elf.sgotplt;
	      dyn.d_un.d_ptr = s->output_section->vma + s->output_offset;
	    }
	  else
	    {
	      /* In Protected Mode the purpose of this entry is to fool the
		 Kernel so as to make it provide AP describing the whole
		 OBFD's GD to ld.so. To achieve that it contains "zero offset
		 from the start of GD".  */
	      dyn.d_un.d_ptr = 0;
	    }

	  bed->s->swap_dyn_out (output_bfd, &dyn, dyncon);

	  /* Ensure that this entry isn't reset once again below.  */
	  name = NULL;
          break;

	case DT_PLTGOTSZ:
	  {
	    struct elf_link_hash_entry *h;
	    h = elf_link_hash_lookup (elf_hash_table (info), "_end", false,
				      false, true);
	    if (h != NULL
		&& h->def_regular
		&& (h->root.type == bfd_link_hash_defined
		    || h->root.type == bfd_link_hash_defweak))
	      {
		asection *o = h->root.u.def.section;
		dyn.d_un.d_val
		  = (adjust_offset_in_cud_gd (info,
					      (h->root.u.def.value
					       + o->output_section->vma
					       + o->output_offset
					       /* Ensures that address of "_end"
						  fits within the range.  */
					       - 1))
		     /* Account for -1 hack above.  */
		     + 1);
		bed->s->swap_dyn_out (output_bfd, &dyn, dyncon);
	      }
	    else
	      {
		_bfd_error_handler (_(" The value of `DT_PLTGOTSZ' cannot be "
				      "determined"));
		return false;
	      }
	  }

	  name = NULL;
	  break;

	case DT_INIT_GOT:
	  dyn.d_un.d_val = (htab->getpl->output_section->vma
			    + htab->getpl->output_offset);
	  bed->s->swap_dyn_out (output_bfd, &dyn, dyncon);

	  name = NULL;
	  break;

        case DT_PLTRELSZ:
          name = ".rela.plt";
          size = true;
          break;

        case DT_JMPREL:
          name = ".rela.plt";
          size = false;
          break;

        default:
          name = NULL;
          size = false;
          break;
        }

      if (name != NULL)
        {
          asection *s;
          
          s = bfd_get_section_by_name (output_bfd, name);
          if (s == NULL)
            dyn.d_un.d_val = 0;
          else
            {
              if (! size)
                dyn.d_un.d_ptr = s->vma;
              else
                dyn.d_un.d_val = s->size;
            }
          bed->s->swap_dyn_out (output_bfd, &dyn, dyncon);
        }
    }

  return true;
}

/* Used to decide how to sort relocs in an optimal manner for the
   dynamic linker, before writing them out.  */

enum elf_reloc_type_class
_bfd_e2k_elf_reloc_type_class (const struct bfd_link_info *info,
                               const asection *rel_sec ATTRIBUTE_UNUSED,
                               const Elf_Internal_Rela *rela)
{
  bfd *abfd = info->output_bfd;
  const struct elf_backend_data *bed = get_elf_backend_data (abfd);
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);

  if (htab->elf.dynsym != NULL
      && htab->elf.dynsym->contents != NULL)
    {
      /* Check relocation against STT_GNU_IFUNC symbol if there are
         dynamic symbols.  */
      unsigned long r_symndx = ELF_R_SYM (abfd, rela->r_info);
      if (r_symndx != STN_UNDEF)
	{
	  Elf_Internal_Sym sym;
	  if (!bed->s->swap_symbol_in (abfd,
				       (htab->elf.dynsym->contents
					+ r_symndx * htab->bytes_per_sym),
				       0, &sym))
	    abort ();

          /* It's crucial to ensure that relocations against IFUNC symbols
             which depend on invocation of resolve functions are processed after
             the ones which may be required for the proper functioning of the
             resolvers. See `ld_ifunc/pr18841{b,c}' tests for such a
             situation.  */
	  if (ELF_ST_TYPE (sym.st_info) == STT_GNU_IFUNC)
	    return reloc_class_ifunc;
	}
    }

  if (ABI_PM_P (htab->elf.dynobj)
      && (ELF_R_TYPE (abfd, rela->r_info) == R_E2K_AP
	  || ELF_R_TYPE (abfd, rela->r_info) == R_E2K_PL)
      && ELF_R_SYM (abfd, rela->r_info) == STN_UNDEF)
    return reloc_class_relative;

  /* We wonder if it makes sense to sort other classes of relocations . . .  */
  return reloc_class_normal;
}

bool
_bfd_e2k_elf_finish_dynamic_sections (bfd *output_bfd,
				      struct bfd_link_info *info)
{
  bfd *dynobj;
  asection *sdyn;
  struct _bfd_e2k_elf_link_hash_table *htab;

  htab = _bfd_e2k_elf_hash_table (info);
  BFD_ASSERT (htab != NULL);
  dynobj = htab->elf.dynobj;

  /* May we look for this section in OUTPUT_BFD rather than in DYNOBJ? It
     seems that the corresponding output_section has the SEC_LINKER_CREATED
     flag as well.  */
  sdyn = bfd_get_linker_section (dynobj, ".dynamic");

  if (elf_hash_table (info)->dynamic_sections_created)
    {
      asection *splt;

      splt = htab->elf.splt;
      BFD_ASSERT (splt != NULL && sdyn != NULL);

      if (!e2k_finish_dyn (output_bfd, info, dynobj, sdyn, splt))
	return false;
    }

  /* Setup PLT header required for lazy binding support.  */
  if (htab->elf.splt
      && htab->elf.splt->size > 0)
    {
      unsigned i;
      for (i = 0; i < htab->plt_got_header_size / 4; i++)
	bfd_put_32 (output_bfd, htab->plt_got_header[i],
		    htab->elf.splt->contents + 4 * i);
    }

  /* Customize the PLT header in case it's actually used. Note that in Protected
     Mode lacking support for lazy binding it's not needed which is made clear
     by setting its size to zero.  */
  if (htab->elf.splt
      && htab->elf.splt->size > 0
      && htab->plt_got_header_size > 0)
    {
      asection *splt;
      asection *sgotplt;

      /* Take into account that delay between load and its consumer has been
	 increased from 3 to 5 ticks starting from elbrus-v6 (see MCSTBug #112004,
	 Comment #8).  */
      unsigned long omach = bfd_get_mach (output_bfd);
      unsigned int nops = e2k_arch_info_mach_to_iset (omach) >= 6 ? 4 : 2;

      unsigned int hs_nop =
	htab->plt_got_header[htab->plt_got_header_nop_offset / 4];

      /* Adjust HS.nop according to the aforesaid.  */
      hs_nop = (hs_nop & 0xfffffc7fu) | (nops << 7);
      bfd_put_32 (output_bfd, hs_nop,
		  htab->elf.splt->contents + htab->plt_got_header_nop_offset);

      // BFD_ASSERT (htab->elf.splt->size >= htab->plt_lazy_header_size);

      splt = htab->elf.splt;
      sgotplt = htab->elf.sgotplt;

      if (bfd_link_pic (info) && ! ABI_PM_P (dynobj))
        {
	  
          /* Offset to the start of .gotplt from 'RR %ip' insn in PLT
             header.  */
          bfd_vma off = (sgotplt->output_section->vma + sgotplt->output_offset
                         - splt->output_section->vma - splt->output_offset);

          /* This puts an offset to the entry in .got.plt containing the run-
             time address of the link map corresponding to the output
             object.  */
          bfd_put_32 (output_bfd, off + htab->bytes_per_word,
                      splt->contents + htab->plt_got_link_map_ld_offset);

          /* This puts an offset to the entry, containing the run-time address
             of `_dl_fixup ()'.  */
          bfd_put_32 (output_bfd, off + 2 * htab->bytes_per_word,
                      splt->contents + htab->plt_got_dl_fixup_ld_offset);
        }
      else
        {
	  int starting_got_entry_size
	    = (ABI_PM_P (dynobj) ? 16 : htab->bytes_per_word);
          /* In non-PIC and PM cases it's just enough to write the address of
	     `.got.plt' entry number 1 containing `struct link_map *'. The
	     address of the next entry containing `&_dl_fixup' is accessed by
	     means of specifying `size_of_PLT_entry' for SRC1 and the same
	     32-bit LTS for SRC2 for another load within the same wide
	     instruction.  */
          bfd_vma addr = adjust_offset_in_cud_gd (info,
						  (sgotplt->output_section->vma
						   + sgotplt->output_offset
						   + starting_got_entry_size));
          unsigned int ld_offset = htab->plt_got_link_map_ld_offset;

          if (ABI_64_P (output_bfd))
            {
              bfd_put_32 (output_bfd, addr >> 32, splt->contents + ld_offset);
              ld_offset += 4;
            }

          bfd_put_32 (output_bfd, addr & 0xffffffff,
                      splt->contents + ld_offset);
        }
    }

  /* Set the first entry in the global offset table to the address of
     the dynamic section.  */
  if (htab->elf.sgotplt && htab->elf.sgotplt->size > 0)
    {
      int i;
      bfd_vma val;
      const struct elf_backend_data *bed = get_elf_backend_data (output_bfd);
      BFD_ASSERT (htab->elf.sgotplt->size >= bed->got_header_size);

      val = (sdyn
	     ? adjust_offset_in_cud_gd (info,
					(sdyn->output_section->vma
					 + sdyn->output_offset))
	     : 0);
      htab->put_word (output_bfd, val, htab->elf.sgotplt->contents);

      /* The second and the third entries will be filled in by ld.so with the
         address of the map and that of '_dl_fixup ()' respectively.  */
      for (i = 0; i < 2; i++)
        htab->put_word (output_bfd, 0,
                        (htab->elf.sgotplt->contents
                         + htab->bytes_per_word * (i + 1)));
    }

  return true;
}

bool
_bfd_e2k_elf_object_p_1 (bfd *abfd,
			 bool protected_mode)
{
  Elf_Internal_Ehdr *i_ehdrp = elf_elfheader (abfd);
  int elf_osabi = get_elf_backend_data (abfd)->elf_osabi;
  unsigned int mach;
  bool res;
  int pm = 0;

  /* Prevent KPDA target from recognizing non-KPDA input file and vice
     versa.  */
  if (elf_osabi != i_ehdrp->e_ident[EI_OSABI]
      && (elf_osabi == ELFOSABI_KPDA
          || i_ehdrp->e_ident[EI_OSABI] == ELFOSABI_KPDA))
    return false;

  if (i_ehdrp->e_machine == EM_E2K_OLD)
    {
      /* Check code semantics for old Elf files.  */
      if (!protected_mode)
        {
          if (ABI_64_P (abfd))
            {
              if (i_ehdrp->e_ident[7] != E2K_MPTR_64)
                return false;
            }
          else
            {
              if (i_ehdrp->e_ident[7] != E2K_MPTR_32)
                return false;
            }
        }
      else
        {
          if (i_ehdrp->e_ident[7] != 5)
            return false;
        }

      mach = EF_E2K_OLD_FLAG_TO_MACH (i_ehdrp->e_flags);
    }
  else
    {
      if ((!protected_mode && (i_ehdrp->e_flags & EF_E2K_PM) != 0)
          || (protected_mode && (i_ehdrp->e_flags & EF_E2K_PM) != EF_E2K_PM))
        return false;

      pm = (i_ehdrp->e_flags & EF_E2K_PM) == EF_E2K_PM;
      mach = EF_E2K_FLAG_TO_MACH (i_ehdrp->e_flags);
    }


  /* Information about ABI is encoded into machine number nowadays.  */
  mach *= 4;
  if (pm)
    mach += 2;
  else if (! ABI_64_P (abfd))
    mach += 1;

  /* We suppose that `bfd_default_set_arch_mach ()' should be used instead
     of `bfd_set_arch_mach ()', when setting ARCH for an IBFD. The latter
     expands into a call a target-specific hook, which is
     `_bfd_elf_set_arch_mach ()' for most of ELF targets. This hook performs a
     number of checks, which probably don't make much sense right now, prior to
     calling `bfd_default_set_arch_mach ()'

     If we correct MACH of the OBFD later, e.g. when merging  private bfd data,
     then `bfd_set_arch_mach ()' should be used.  */
  res = bfd_default_set_arch_mach (abfd, bfd_arch_e2k, mach);

  return res;
}

bool
_bfd_e2k_elf_object_p (bfd *abfd)
{
  return _bfd_e2k_elf_object_p_1 (abfd, false);
}

bfd *
_bfd_e2k_elf_link_setup_gnu_properties (struct bfd_link_info *info)
{
  bfd *pbfd;
  struct _bfd_e2k_elf_link_hash_table *htab;


  htab = _bfd_e2k_elf_hash_table (info);
  pbfd = _bfd_elf_link_setup_gnu_properties (info);

  if (htab == NULL
      || bfd_link_relocatable (info))
    return pbfd;

  /* DYNOBJ may have already been set up in generic ELF code, for example, in
     `_bfd_elf_link_create_dynstrtab ()'.  */
  if (htab->elf.dynobj == NULL)
    {
      if (pbfd != NULL)
	htab->elf.dynobj = pbfd;
      else
	{
	  bfd *abfd;

	  /* Find a normal input file to hold linker created
	     sections.  */
	  for (abfd = info->input_bfds;
	       abfd != NULL;
	       abfd = abfd->link.next)
	    if (bfd_get_flavour (abfd) == bfd_target_elf_flavour
		&& (abfd->flags
		    & (DYNAMIC | BFD_LINKER_CREATED | BFD_PLUGIN)) == 0)
	      {
		htab->elf.dynobj = abfd;
		break;
	      }
	}
    }

    /* Hopefully this is the right place for creation of PM-specific subsidiary
       `.text.getpl' section.  */
  if (htab->elf.dynobj && ABI_PM_P (htab->elf.dynobj))
    {
      /* Now that "_end" is defined conditionally (i.e. via PROVIDE ()) in
         shared libraries we need to refer to it so as not to be left without
         its definition when it comes to setting the value of DT_PLTGOTSZ. Note
         that it seems to be too late to take care of that both in `{size,
         finish}_dynamic_sections ()', but quite OK to do this here.  */
      if (bfd_link_dll (info)
          /* This should prevent us from creating a reference if "_end" has
             already been referred to from an input relocatable object. FIXME:
             can't this happen after we create a reference here? Aren't the two
             references going to interfere in some unpredictable way?  */
          && elf_link_hash_lookup (elf_hash_table (info), "_end", false,
                                   false, true) == NULL)
        {
          if (! _bfd_generic_link_add_one_symbol (info, htab->elf.dynobj,
                                                  "_end", 0,
                                                  bfd_und_section_ptr, 0,
                                                  NULL, false, false,
                                                  NULL))
            return false;
        }

      /* FIXME: the use of `bfd_make_section ()' here results in a section
	 filled in with zeroes despite the fact that We allocate its contents
	 and set it up appropriately.  */
      htab->getpl = bfd_make_section_anyway_with_flags
	(htab->elf.dynobj, ".text.getpl",
	 (SEC_LINKER_CREATED | SEC_HAS_CONTENTS));

      if (htab->getpl == NULL
	  || ! bfd_set_section_size (htab->getpl, sizeof (getpl_body)))
	return NULL;
    }

  return pbfd;
}

struct plt_symbol_indices
{
  int *rel_indices;
};

static bfd_vma *
_bfd_e2k_elf_plt_sym_val (bfd *abfd,
                          asymbol **dynsyms,
                          asection *plt,
			  asection *relplt,
                          int kind,
			  void *dummy)
{
  bool (*slurp_relocs) (bfd *, asection *, asymbol **, bool);
  asection *got = NULL;
  bfd_byte *got_contents = NULL;
  bfd_byte *plt_contents = plt->contents;
  long i, count;
  long j;
  bfd_vma *plt_sym_val;
  Elf_Internal_Shdr *hdr;
  bfd_vma off;
  bool abi128 = ABI_PM_P (plt->owner);
  bool abi64 = ABI_64_P (plt->owner);
  bfd_vma addr_in_got;
  int max_plt_entries_num;
  int *plt_rel_idx;
  arelent *rel = relplt->relocation;

  if (plt_contents == NULL)
    {
      plt_contents = (bfd_byte *) bfd_malloc (plt->size);

      if (plt_contents == NULL)
        return NULL;

      /* FIXME: find out why we are passed PLT as `const asection *' while
         `asection *' is required to get its contents.  */
      if (! bfd_get_section_contents (plt->owner, (asection *) plt,
                                      plt_contents, 0, plt->size))
        {
          free (plt_contents);
          return NULL;
        }

      /* FIXME: how do you like changing the field in a const object? Verify if
         it's constant in fact or is just presented this way to us.  */
      ((asection *) plt)->contents = plt_contents;
    }

  if (kind == 1)
    {
      /* .got is required only for calculation of "@secondary_plt" synthetic
	 symbols.  */
      got = bfd_get_section_by_name (abfd, ".got");
      if (got == NULL)
	return NULL;

      got_contents = got->contents;
      if (got_contents == NULL)
        {
          got_contents = (bfd_byte *) bfd_malloc (got->size);
          if (got_contents == NULL)
            return NULL;

          if (! bfd_get_section_contents (got->owner, got, got_contents, 0,
                                          got->size))
            {
              free (got_contents);
              return NULL;
            }

          got->contents = got_contents;
        }
    }

  slurp_relocs = get_elf_backend_data (abfd)->s->slurp_reloc_table;
  if (! (*slurp_relocs) (abfd, relplt, dynsyms, true))
    return NULL;

  hdr = &elf_section_data (relplt)->this_hdr;
  /* The number of relocations in .rela.plt for `kind == {0,1}' and in
     .rela.dyn for `kind == 2'.  */
  count = relplt->size / hdr->sh_entsize;

  plt_sym_val = (bfd_vma *) bfd_malloc (sizeof (bfd_vma) * count);
  if (plt_sym_val == NULL)
    return NULL;

  if (kind == 0)
    {
      /* Allocate array storing relocation indices matching primary PLT entries
	 in the assumption that there are at most 8 entries for now. It'll be
	 reallocated later if needed.  */
      max_plt_entries_num = 8;
      plt_rel_idx = (int *) bfd_malloc (max_plt_entries_num * sizeof (int));
      if (plt_rel_idx == NULL)
	{
	  free (plt_sym_val);
	  return NULL;
	}
    }
  else
    {
      /* Use the array prepared during invocation with KIND == 0.  */
      struct plt_symbol_indices *plt_inds
	= (struct plt_symbol_indices *) dummy;
      plt_rel_idx = plt_inds->rel_indices;
    }


  /* -1 means that no symbol of KIND matching the i-th relocation entry has
     been found.  */
  for (i = 0; i < count; i++)
    plt_sym_val[i] = -1;


  unsigned int range_num = _bfd_e2k_elf_get_range_num (abfd);
  struct pm_range *ranges = xmalloc (range_num * sizeof (ranges[0]));
  _bfd_e2k_elf_fill_ranges (abfd, range_num, ranges);

  /* Not actually used if kind != 1.  */
  bfd_vma packed_got_vma
    = (kind == 1
       ? got->vma + _bfd_e2k_elf_get_offset_delta (range_num, ranges, got->vma)
       : 0);

  for (off = 0, j = 0; off < plt->size;)
    {
      bfd_vma next_off;
      bfd_vma hs = H_GET_32 (plt->owner, plt_contents + off);

      /* Skip NOP of a potentially variable length (on practice "unsafe" address
	 ranges in .plt are currently eliminated by filling them in with zero
	 dwords encoding sequences of "standard" 8-byte NOPs as they are not
	 executed anyway) inserted for the sake of MCSTBug #140436 workaround.
	 This issue was realized while working on MCSTBug #144538.  */
      if ((hs & 0xffffff8f) == 0)
	{
	  off += (((hs & 0x70) >> 4) + 1) << 3;
	  continue;
	}
      /* Secondary PLT entries are shared between 32/64-bit modes. Skip a
	 new-style secondary PLT entry.  */
      else if (!abi128 && hs == plt_got_secondary_entry[0])
	{
	  off += 0x20;
	  continue;
	}
      /* Skip an old-style secondary PLT entry. It's not used within this
	 backend anywhere except for this point, therefore an immediate
	 value for it is used in the comparison below.  */
      else if (!abi128 && hs == 0x0400c023)
	{
	  off += PLT_GOT_SECONDARY_ENTRY_SIZE;
	  continue;
	}
      else if (abi128 && hs == plt128_got_secondary_entry[0])
	{
	  off += PLT128_GOT_SECONDARY_ENTRY_SIZE;
	  continue;
	}
      else if (abi128)
	{
	  /* Skip PLT header.  */
	  if ((hs & 0xfffffc7fu) == plt128_got_header[0])
	    {
	      off += PLT128_GOT_HEADER_SIZE;
	      continue;
	    }
	  else if ((hs & 0xfffffc7fu) == plt128_got_primary_entry[0])
	    {
	      addr_in_got
		= (/* The first term will be required for elbrus-v7 with its
		      64-bit offsets, however, it won't harm on elbrus-v{X<7}
		      as well because LTS2 preceding _f32s,_lts1 contains 0
		      (see binary content of the entry).  */
		   (H_GET_32 (plt->owner,
			      plt_contents + off
			      /* FIXME: adjust PLT128_GOT_TARET_LD_OFFSET so as
				 to migrate from this non-uniform `- 4' to
				 `+ 4'.  */
			      + PLT128_GOT_TARGET_LD_OFFSET - 4) << 32)
		   + H_GET_32 (plt->owner,
			       plt_contents + off
			       + PLT128_GOT_TARGET_LD_OFFSET));
	      next_off = off + PLT128_GOT_PRIMARY_ENTRY_SIZE;
	    }
	  /* PLT is damaged and can't be parsed to the end. Let the caller
	     benefit from partial results of our job. Note that for subsequent
	     KINDs we should break here as well, which is why there is no risk
	     of violating plt_rel_idx[] boundaries.  */
	  else
	    goto done;
	}
      else if (abi64)
	{
	  /* Skip PIC and non-PIC PLT headers.  */
	  if ((hs & 0xfffffc7fu)
	      == (plt64_got_non_pic_header[0] & 0xfffffc7fu))
	    {
	      off += sizeof (plt64_got_non_pic_header);
	      continue;
	    }
	  else if (hs == plt64_got_pic_header[0])
	    {
	      off += sizeof (plt64_got_pic_header);
	      continue;
	    }
	  /* This is a primary PLT entry which the address of the related entry
	     in .got may be extracted from and thereby the correspondence with
	     the dynamic relocation be established.  */
	  else if (((hs & 0xfffffc7fu)
		    == (plt64_got_non_pic_primary_entry[0] & 0xfffffc7fu))
		   || (hs == plt64_got_pic_primary_entry[0]))
	    {
	      /* Handle non-PIC primary PLT entry.  */
	      if ((hs & 0xfffffc7fu)
		  == (plt64_got_non_pic_primary_entry[0] & 0xfffffc7fu))
		{
		  addr_in_got = ((H_GET_32 (plt->owner,
					    plt_contents + off
					    + PLT64_GOT_NON_PIC_TARGET_LD_OFFSET) << 32)
				 + H_GET_32 (plt->owner,
					     plt_contents + off
					     + PLT64_GOT_NON_PIC_TARGET_LD_OFFSET
					     + 4));
		  next_off = off + sizeof (plt64_got_non_pic_primary_entry);
		}
	      else
		/* Process PIC one.  */
		{
		  addr_in_got = plt->vma + off;
		  addr_in_got += (int) H_GET_32 (plt->owner,
						 plt_contents + off
						 + PLT64_GOT_PIC_TARGET_LD_OFFSET);
		  next_off = off + sizeof (plt64_got_pic_primary_entry);
		}
	    }
	  /* PLT is damaged and can't be parsed to the end. Let the caller
	     benefit from partial results of our job. Note that for subsequent
	     KINDs we should break here as well, which is why there is no risk
	     of violating plt_rel_idx[] boundaries.  */
	  else
	    goto done;
	}
      else /* if (!abi64)  */
	{
	  /* Skip PIC and non-PIC PLT headers.  */
	  if ((hs & 0xfffffc7fu)
	      == (plt32_got_non_pic_header[0] & 0xfffffc7fu))
	    {
	      off += sizeof (plt32_got_non_pic_header);
	      continue;
	    }
	  else if (hs == plt32_got_pic_header[0])
	    {
	      off += sizeof (plt32_got_pic_header);
	      continue;
	    }
	  /* This is a primary PLT entry which the address of the related entry
	     in .got may be extracted from and thereby the correspondence with
	     the dynamic relocation be established.  */
	  else if (((hs & 0xfffffc7fu)
		    == (plt32_got_non_pic_primary_entry[0] & 0xfffffc7fu))
		   || (hs == plt32_got_pic_primary_entry[0]))
	    {
	      /* Handle non-PIC primary PLT entry.  */
	      if ((hs & 0xfffffc7fu)
		    == (plt32_got_non_pic_primary_entry[0] & 0xfffffc7fu))
		{
		  addr_in_got = H_GET_32 (plt->owner,
					  plt_contents + off
					  + PLT32_GOT_NON_PIC_TARGET_LD_OFFSET);
		  next_off = off + sizeof (plt32_got_non_pic_primary_entry);
		}
	      /* Process PIC one.  */
	      else
		{
		  addr_in_got = plt->vma + off;
		  addr_in_got += (int) H_GET_32 (plt->owner,
						 plt_contents + off
						 + PLT32_GOT_PIC_TARGET_LD_OFFSET);
		  next_off = off + sizeof (plt32_got_pic_primary_entry);
		}
	    }
	  /* PLT is damaged and can't be parsed to the end. Let the caller
	     benefit from partial results of our job. Note that for subsequent
	     KINDs we should break here as well, which is why there is no risk
	     of violating plt_rel_idx[] boundaries.  */
	  else
	    goto done;
	}

      /* We are looking for either "@plt" or "@plt.got" symbol matching the
	 currently processed primary PLT entry. Searching the latter makes
	 sense only if the former hasn't been found, since there should be no
	 .rela.dyn and .rela.plt dynamic relocations corresponding to the same
	 primary PLT entry. This saves one the trouble of iterating through a
	 potentially huge .rela.dyn for most hopeless primary PLT entries.*/
      if (kind == 0
	  || (kind == 2
	      /* If there's .rela.dyn but no .rela.plt in ABFD this function
		 may be called with KIND == 2 only, in which case there's no
		 `plt_rel_idx[]'.  */
	      && (plt_rel_idx == NULL
		  || plt_rel_idx[j] == -1)))
	{
	  if (kind == 0 && j == max_plt_entries_num)
	    {
	      /* There are more primary PLT entries than one supposed.  */
	      max_plt_entries_num *= 2;
	      plt_rel_idx = bfd_realloc (plt_rel_idx,
					 max_plt_entries_num * sizeof (int));
	      if (plt_rel_idx == NULL)
		{
		  free (plt_sym_val);
		  free (ranges);
		  return NULL;
		}
	    }

	  /* Look for the matching dynamic relocation in `.rela.{plt,dyn}'
	     starting from the index next to the previous hit in hope that
	     primary PLT entries have more or less the same order as their
	     matching relocations.  */
	  for (i = 0; i < count; i++, rel++)
	    {
	      /* Resume from the beginning if the upper boundary has been
		 crossed.  */
	      if (rel == relplt->relocation + count)
		rel = relplt->relocation;

	      /* Dynamic relocations' `r_offset's are written out in non-packed
		 form by LD (in order to be as clear as possible to standard ELF
		 "readers") which is taken into account by ld.so during their
		 processing. On the other hand, the matching offsets of .got.plt
		 entries encoded in primary PLT ones are written out in packed
		 form because ld.so won't adjust RX .plt section (and there's
		 no point in doing so in fact).  */
	      if (addr_in_got
		  == (rel->address
		      + _bfd_e2k_elf_get_offset_delta (range_num, ranges,
						       rel->address)))
		{
		  int k = rel - relplt->relocation;
		  /* OBJDUMP needs a NON-packed ELF symbol value rather than
		     the runtime one. Hopefully, GDB requires the same and will
		     convert it to the runtime representation itself.  */
		  plt_sym_val[k] = plt->vma + off;

		  /* Save the index of the matching .rela.plt entry. There's no
		     point in doing so when processing .rela.dyn as there'll be
		     no subsequent invocations.  */
		  if (kind == 0)
		    plt_rel_idx[j] = k;

		  /* Ensure that the search for the relocation matching the
		     next primary PLT entry starts from the next one in
		     `.rela.{plt,dyn}'.  */
		  rel++;
		  break;
		}
	    }

	  /* No .rela.plt relocation matching this primary PLT entry has
	     been found. Make it clear that one may hope to find the one
	     in .rela.dyn.  */
	  if (kind == 0 && i == count)
	    plt_rel_idx[j] = -1;
	}
      /* "@secondary_plt" symbol may exist only if the related "@plt"
	 one does. */
      else if (kind == 1 && plt_rel_idx[j] != -1)
	{
	  /* There is no point in looking for its relocation index as it
	     coincides with the one of the "@plt" one. As for its address
	     it's read from .got. Recall that ADDR_IN_GOT is "packed" (see
	     above).  */
	  if (addr_in_got >= packed_got_vma
	      && addr_in_got < packed_got_vma + got->size)
	    {
	      bfd_vma secondary_plt_vma;
#define H_GET_XX(o, p) abi64 ? H_GET_64 (o, p) : H_GET_32 (o, p)
		secondary_plt_vma
		  = H_GET_XX (got->owner,
			      got_contents + addr_in_got - packed_got_vma);
#undef H_GET_XX
		/* Ensure that the obtained "@secondary_plt" symbol's address
		   does actually belong to .plt to be on the safe side.
		   Symmetrically to dynamic relocations' `r_offset's, offsets
		   of secondary PLT entries are written out to .got.plt in non-
		   packed form in PM.  */
		if (secondary_plt_vma >= plt->vma
		    && secondary_plt_vma < plt->vma + plt->size)
		  /* Provide the disasembler with ELF symbol value rather than
		     runtime one (see analogous comment when evaluating the
		     value of a primary PLT entry above).  */
		  plt_sym_val[plt_rel_idx[j]] = secondary_plt_vma;
	    }
	}

      /* Proceed to the next J'th anticipated primary PLT entry which may be
	 located at NEXT_OFF or further.  */
      j++;
      off = next_off;
    }

 done:
  /* Save plt_rel_idx[] for subsequent invocations.  */
  if (kind == 0)
    {
      struct plt_symbol_indices *plt_inds
	= (struct plt_symbol_indices *) dummy;
      plt_inds->rel_indices = plt_rel_idx;
    }

  free (ranges);
  return plt_sym_val;
}

/* Similar to _bfd_elf_get_synthetic_symtab.  */

long
_bfd_e2k_elf_get_synthetic_symtab (bfd *abfd,
			       long symcount,
			       asymbol **syms,
			       long dynsymcount,
			       asymbol **dynsyms,
			       asymbol **ret)
{
  int i;
  asection *plt = bfd_get_section_by_name (abfd, ".plt");
  long l, res[3];
  asymbol *s, *sarr[3];
  size_t size;
  char *names;
  long n;
  struct plt_symbol_indices plt_sym_ind;

  /* This may remain uninitialized if `_bfd_e2k_elf_plt_sym_val ()' is not
     called, for example, if there's no PLT in the disassembled file.  */
  plt_sym_ind.rel_indices = NULL;

  for (i = 0; i < 3; i++)
    {
      res[i] = _bfd_elf_ifunc_get_synthetic_symtab
        (abfd, symcount, syms, dynsymcount, dynsyms,
         &sarr[i], plt,
         /* Primary or secondary PLT entry or `plt.got' entry.  */
         i,
	 &plt_sym_ind,
         & _bfd_e2k_elf_plt_sym_val);
    }

  /* Free it only if it has really been allocated.  */
  if (plt_sym_ind.rel_indices)
    free (plt_sym_ind.rel_indices);

  if (res[0] == -1 && res[1] == -1 && res[2] == -1)
    return -1;

  /* Create a @plt_header synthetic symbol if any PLT entries exist at all.
     This is done symmetrically to how e2k-linux-ld creates PLT header at
     present in spite of the fact that it may actually be used only for the
     purpose of lazy binding by secondary PLT entries being the only species
     transferring control to it.  */
  bool plt_header_symbol_needed = (res[0] > 0 || res[1] > 0 || res[2] > 0);
  static const char plt_header_name[] = "@plt_header";
  size = (plt_header_symbol_needed
	  ? sizeof (asymbol) + sizeof (plt_header_name) : 0);

  for (i = 0; i < 3; i++)
    {
      /* If one of `get_synthetic_symtab ()' has failed just don't take
         its result into account.  */

      if (res[i] != -1)
        size += res[i] * sizeof (asymbol);

      for (l = 0; l < res[i]; l++)
        size += strlen (sarr[i][l].name) + 1;
    }

  s = *ret = (asymbol *) bfd_malloc (size);
  names = (char *) s;

  for (i = 0; i < 3; i++)
    names += (res[i] != -1 ? res[i] : 0) * sizeof (asymbol);

  n = 0;

  if (plt_header_symbol_needed)
    {
      /* Take into account extra "@plt_header" symbol being created here.  */
      names += sizeof (asymbol);

      /* Fill in the symbol. The way this is done is mostly borrowed from
	 _bfd_mips_elf_get_synthetic_symtab ().  */
      s->the_bfd = abfd;
      s->flags = BSF_SYNTHETIC | BSF_FUNCTION | BSF_LOCAL;
      s->section = plt;
      /* It's at the start of .plt.  */
      s->value = 0;
      s->name = names;
      s->udata.p = NULL;

      /* Advance S and NAMES for subsequent synthetic symbols.  */
      n++;
      names = mempcpy (names, plt_header_name, sizeof (plt_header_name));
    }

  for (i = 0; i < 3; i++)
    {
      for (l = 0; l < res[i]; l++)
        {
          size_t len;

          len = strlen (sarr[i][l].name) + 1;
          memcpy (names, sarr[i][l].name, len);
          s[n] = sarr[i][l];
          s[n].name = names;
          n++;
          names += len;
        }

      /* Free the intermediate array now that its contents has been copied to
         the unified one.  */
      if (res[i] != -1)
        free (sarr[i]);
    }

  return n;
}



bool
_bfd_e2k_elf_init_file_header (bfd *abfd,
			       struct bfd_link_info *info)
{
  Elf_Internal_Ehdr *i_ehdrp;
  unsigned int mach;

  i_ehdrp = elf_elfheader (abfd);

  /* Filter out info concerning ABI.  */
  mach = bfd_get_mach (abfd) / 4;

  /* Presumably this function is useless when called either by OBJCOPY or
     STRIP because all `e_flags' should be converted via the `copy_private
     _bfd_data ()' hook. To avoid duplication, just return in such a case.  */
  if (info == NULL)
    {
      /* Ensure that `e_ident[EI_OSABI]' is set properly when GAS produces
         output with the new `e_machine' in ELF header. Isn't it going to
         introduce unfounded differences between input and output when this
         function is invoked on behalf of OBJCOPY or STRIP?  */
      if (output_new_e_machine)
        goto set_elf_osabi;

      return true;
    }

  /* These flags are the same both for EM_E2K_OLD and EM_MCST_ELBRUS. We guess
     that they shouldn't be set explicitly here when an output bfd is produced
     via OBJCOPY or STRIP. Also see a note concerning semantics below.  */
  if (_bfd_e2k_elf_hash_table (info))
    i_ehdrp->e_flags |= (e2k_ipd
                         | (e2k_is_x86app ? EF_E2K_X86APP : 0)
                         | (e2k_is_4mpages ? EF_E2K_4MB_PAGES : 0));

  if (! output_new_e_machine)
    {
      /* `e_machine' should be set explicitly to the old "alternative"
         value now that we have the right one which isn't supported
         anywhere yet.  */
      i_ehdrp->e_machine = EM_E2K_OLD;

      /* Keep in mind that this function also gets called by OBJCOPY and STRIP
         with `info == NULL'. At present We don't remember a true reason for
         that. In that case "semantics" (and probably `e_flags') gets copied via
         `bfd_e2k_elf_copy_private_bfd_data ()' and one shouldn't attempt to
         set it up here (see Bugs #31435, #33851).

         FIXME: this check is going to work both for non-PM and PM modes
         provided that the corresponding hash tables have the same
         `HASH_TABLE_ID's equal to `E2K_ELF_DATA'.  */
      if (_bfd_e2k_elf_hash_table (info))
        {
          /* In protected mode set an ancient PM semantic == 5.  */
          if (abfd->arch_info->mach % 4 == 2)
            i_ehdrp->e_ident[7] = 5;
          else
            {
              struct _bfd_e2k_elf_link_hash_table *htab;
              htab = _bfd_e2k_elf_hash_table (info);
              i_ehdrp->e_ident[7] = htab->ancient_semantics;
            }
        }


      i_ehdrp->e_flags |= EF_E2K_MACH_TO_OLD_FLAG (mach);
      /* Find out what this `0x80000000' is needed for.  */
      i_ehdrp->e_flags |= 0x80000000;
    }
  else
    {
    set_elf_osabi:
      i_ehdrp->e_flags |= EF_E2K_MACH_TO_FLAG (mach);

      if (abfd->arch_info->mach % 4 == 2)
	{
	  i_ehdrp->e_flags |= EF_E2K_PM;
	  if (pack_cud_gd)
	    i_ehdrp->e_flags |= EF_E2K_PACK_SEGMENTS;
	}

      /* This sets e_ident[EI_OSABI == 7] in ELF header only. Nevertheless I
         wonder how We managed to do without it when creating new-style ELFs
         via binutils-2.18. Probably it worked because ELFOSABI_NONE, which is
         set by default, equals to zero.  */
      if (! _bfd_elf_init_file_header (abfd, info))
	return false;
    }

  return true;
}

bool
_bfd_e2k_elf_copy_private_bfd_data_1 (bfd *ibfd, bfd *obfd,
                                      bool protected_mode)
{
  if (! _bfd_elf_copy_private_bfd_data (ibfd, obfd))
    return false;

  if (elf_elfheader (obfd)->e_machine == EM_E2K_OLD)
    {
      /* Nobody is going to set `e_ident[7]' for us no matter whether we
         are copying from an old-style (e_machine == EM_E2K_OLD) object
         where it is already set or converting a new-style one.  */
      if (!protected_mode)
        elf_elfheader (obfd)->e_ident[7]
          = ABI_64_P (obfd) ? E2K_MPTR_64 : E2K_MPTR_32;
      else
        /* Currently PM objects with C++ hardware support turned off are
           assumed. There is no point in copying this value from an input
           file even if it is an old-style one.  */
        elf_elfheader (obfd)->e_ident[7] = 5;

      /* The `e_flags' field has already been copied by
         `_bfd_elf_copy_private_bfd_data', however when converting to an
         old-styled object it should be converted as well.  */
      if (elf_elfheader (ibfd)->e_machine == EM_MCST_ELBRUS)
        {
          unsigned long iflags = elf_elfheader (ibfd)->e_flags;
          unsigned long mach = EF_E2K_FLAG_TO_MACH (iflags);

          /* `EF_E2K_INCOMPAT'-specific behaviour should not be supported
             for old-styled objects and executables, since it requires
             changes to the Kernel which are to be done simultaneously
             with support for new-styled executables.  */
          if (iflags & EF_E2K_INCOMPAT)
            {
              _bfd_error_handler
                (_("New style object %pB with `EF_E2K_INCOMPAT' flag cannot be "
                   "converted to an old style %pB"), ibfd, obfd);
              return false;
            }

          elf_elfheader (obfd)->e_flags
            = (EF_E2K_MACH_TO_OLD_FLAG (mach) | (iflags & 0xf));
        }
    }
  /* One can find himself here only if `obfd->e_machine == EM_MCST_ELBRUS'.  */
  else if (elf_elfheader (ibfd)->e_machine == EM_E2K_OLD)
    {
      unsigned long iflags = elf_elfheader (ibfd)->e_flags;
      unsigned long mach = EF_E2K_OLD_FLAG_TO_MACH (iflags);

      /* When converting old objects, `EF_E2K_INCOMPAT' should definitely
         not be set.  */
      elf_elfheader (obfd)->e_flags
        = (EF_E2K_MACH_TO_FLAG (mach) | (protected_mode ? EF_E2K_PM : 0)
           | (iflags & 0xf));
    }

  /* Otherwise a straightforward replication of `e_flags' performed by
     `_bfd_elf_copy_private_bfd_data' will do.  */

  return true;
}

bool
_bfd_e2k_elf_copy_private_bfd_data (bfd *ibfd, bfd *obfd)
{
  return _bfd_e2k_elf_copy_private_bfd_data_1 (ibfd, obfd, false);
}


bool
_bfd_e2k_elf_ignore_discarded_relocs (asection *sec)
{
  bfd *abfd;
  size_t locsymcount;
  Elf_Internal_Shdr *symtab_hdr;
  Elf_Internal_Rela *internal_relocs;
  Elf_Internal_Rela *rel, *relend;
  struct elf_link_hash_entry **sym_hashes;
  const struct elf_backend_data *bed;
  int r_sym_shift;

  if (link_mixed_eir_phase != 1
      && link_mixed_eir_phase !=3)
    return false;

  abfd = sec->owner;
  symtab_hdr = &elf_tdata (abfd)->symtab_hdr;
  locsymcount = symtab_hdr->sh_info;

  bed = get_elf_backend_data (abfd);

  internal_relocs = _bfd_elf_link_read_relocs (abfd, sec, NULL, NULL, false);
  rel = internal_relocs;
  relend = rel + sec->reloc_count * bed->s->int_rels_per_ext_rel;

  r_sym_shift = (bed->s->arch_size == 32) ? 8 : 32;


  sym_hashes = elf_sym_hashes (abfd);
  for ( ; rel < relend; rel++)
    {
      unsigned long r_symndx = rel->r_info >> r_sym_shift;
      struct elf_link_hash_entry *h = NULL;

      if (r_symndx == STN_UNDEF)
        continue;

      if (r_symndx >= locsymcount)
        {
          h = sym_hashes[r_symndx - locsymcount];

          while (h->root.type == bfd_link_hash_indirect
                 || h->root.type == bfd_link_hash_warning)
            h = (struct elf_link_hash_entry *) h->root.u.i.link;

          if (((h->root.type == bfd_link_hash_defined 
                || h->root.type == bfd_link_hash_defweak)
               && discarded_section (h->root.u.def.section))
              /* Don't forget about common symbols. Their sections may
                 very well be discarded as well.  */
              || (h->root.type == bfd_link_hash_common
                  && discarded_section (h->root.u.c.p->section)))
#if 0
              /* We don't have legal access to this (link) info . . . */
              && (h->root.u.def.next || . . .)
#endif /* 0 */
            {
              /* Stupidly make it undefined. Is it going to work? */
              h->root.type = bfd_link_hash_undefined;
              
            }
        }
    }

  /* free (internal_relocs); */
  return true;
}

void
_bfd_e2k_elf_hide_symbol_1 (struct bfd_link_info *info,
                            struct elf_link_hash_entry *h,
                            bool force_local,
                            bool protected_mode)
{
  /* We don't want to hide (make local) symbols from unsuitable
     (SEC_EXCLUDE | SEC_DEBUGGING) sections
     (see discard_unsuitable_section () before) in EIR linkage
     mode. Prevent the code in `elf_link_add_object_symbols ()'
     from achieving this. Interestingly enough, there is no attempt
     to hide these symbols in binutils-2.21.  */

  if (link_mixed_eir_phase != 1 && link_mixed_eir_phase != 3)
    {
      /* Take care that space in .got is reserved for this symbol for the sake
         of processing R_E2K_GOTPLT against it in relocate_section before any
         mention of its PLT entries is destroyed in `_bfd_elf_link_hash_hide_
         symbol ()' below.  */
      if (!protected_mode && h->type != STT_GNU_IFUNC)
        {
          if (positive_plt_refcount (h))
            discard_plt_refcount (h);

          if (positive_secondary_plt_refcount (h))
            {
              struct _bfd_e2k_elf_link_hash_entry *eh;
              eh = (struct _bfd_e2k_elf_link_hash_entry *) h;
              BFD_ASSERT (eh->tls_type == GOT_UNKNOWN
                          || eh->tls_type == GOT_NORMAL);
              h->got.refcount = 1;
              eh->tls_type = GOT_NORMAL;
            }
        }

      _bfd_elf_link_hash_hide_symbol (info, h, force_local);
    }
}

void
_bfd_e2k_elf_hide_symbol (struct bfd_link_info *info,
                          struct elf_link_hash_entry *h,
                          bool force_local)
{
  _bfd_e2k_elf_hide_symbol_1 (info, h, force_local, false);
}


struct write_eir_info
{
  bfd_size_type max_size;
  bfd_byte *contents;
  /* This is set to false if `_bfd_e2k_write_eir_contens ()' fails
     for any section.  */
  bool res;
};

static void
_bfd_e2k_write_eir_contents (bfd *abfd ATTRIBUTE_UNUSED,
                             asection *s,
                             void *param)
{
  static bfd_vma s_offset;
  bfd_vma next_s_offset;
  bfd_vma mask;
  struct bfd_link_order *p;
  struct write_eir_info *wei;

  /* There is nothing to do for non-EIR sections.  */
  if (strcmp (s->name, ".pack_pure_eir") != 0
      && strcmp (s->name, ".pack_mixed_eir") != 0)
    return;

  wei = (struct write_eir_info *) param;
  /* If we've already failed, there is no point in continuing.  */
  if (wei->res == false)
    return;

  mask = (1 << s->alignment_power) - 1;
  s_offset = (s_offset + mask) & ~mask;
  next_s_offset = s_offset;

  for (p = s->map_head.link_order; p != NULL; p = p->next)
    {
      asection *i;

      if (p->type != bfd_indirect_link_order)
        continue;

      i = p->u.indirect.section;

      if (i->size > 0)
        {
          if (i->size > wei->max_size)
            {
              wei->max_size = i->size;
              wei->contents = (bfd_byte *) bfd_realloc (wei->contents,
                                                        wei->max_size);
            }

          if (s_offset + i->output_offset + i->size > next_s_offset)
            next_s_offset = s_offset + i->output_offset + i->size;

          if (! bfd_get_section_contents (i->owner, i, wei->contents,
                                          0, i->size)
	      || bfd_seek (abfd, s_offset + i->output_offset, SEEK_SET) != 0
	      || bfd_bwrite (wei->contents, i->size, abfd) != i->size)
            {
              wei->res = false;
              return;
            }
        }
    }

  /* Setting initial `s_offset' value for the next invocation.  */
  s_offset = next_s_offset;
}


/* This function gets called when BFD is being closed. Avoid calling
   an ELF-specific method (which outputs strtab, . . .) when a raw
   binary for EIR is required.  */
bool
_bfd_e2k_elf_write_object_contents (bfd *abfd)
{
  struct write_eir_info wei;

  if (link_mixed_eir_phase != 2)
    return _bfd_elf_write_object_contents (abfd);

  wei.max_size = 0;
  wei.contents = NULL;
  wei.res = true;

  /* Calculating positions of EIR sections and setting their contents.  */
  bfd_map_over_sections (abfd, _bfd_e2k_write_eir_contents, &wei);

  if (wei.contents)
    free (wei.contents);

  return wei.res;
}


const struct bfd_elf_special_section
_bfd_e2k_elf_special_sections[] =
{
  { STRING_COMMA_LEN (".magic"),             0,  SHT_NOTE,     0 },
  { NULL,                0,          0, 0,            0 }
};

/* Support for core dump NOTE sections.  */

bool
_bfd_e2k_elf_grok_prstatus (bfd *abfd, Elf_Internal_Note *note)
{
  /* pr_cursig  */
  elf_tdata (abfd)->core->signal = bfd_get_16 (abfd, note->descdata + 12);

  /* Get pr_pid field.  */
  elf_tdata (abfd)->core->lwpid = bfd_get_32 (abfd, note->descdata + 32);


  /* Make a ".reg/999" section.
     FIXME: get rid of hardcoded numerical values for size and offset.  */
  return _bfd_elfcore_make_pseudosection
    (abfd, ".reg", note->descsz - 120, note->descpos + 112);
}


char *
_bfd_e2k_elf_write_core_note (bfd *abfd, char *buf, int *bufsiz,
                              int note_type, ...)
{
  switch (note_type)
    {
    default:
      return NULL;

    case NT_PRPSINFO:
      {
        /* `sizeof (struct elf_prpsinfo) == 136' within the Kernel.  */
	char data[136];
	va_list ap;

	va_start (ap, note_type);
	memset (data, 0, sizeof (data));

        /* Set `char pr_fname[16]' located at offset 40 within `struct
           elf_prpsinfo'.  */
	strncpy (data + 40, va_arg (ap, const char *), 16);

        /* Set `char pr_psargs[80]' located at offset 56 within `struct
           elf_prpsinfo'.  */
	strncpy (data + 56, va_arg (ap, const char *), 80);
	va_end (ap);

	return elfcore_write_note (abfd, buf, bufsiz,
				   "CORE", note_type, data, sizeof (data));
      }

    case NT_PRSTATUS:
      {
        /* This is the `sizeof (struct elf_prstatus)' within the Kernel:
           `4904 == (sizeof (user_regs_struct) == 4784) + 120 bytes distributed
           over a few other fields'.  */
	char data[4784 + 120];
	va_list ap;
	long pid;
	int cursig;
	const void *greg;

	va_start (ap, note_type);
	memset (data, 0, sizeof (data));

        /* Set `pr_pid' 32-bit field located at offset 32 within `struct
           elf_prstatus'.  */
	pid = va_arg (ap, long);
	bfd_put_32 (abfd, pid, data + 32);

        /* Set `pr_cursig' 16-bit field located at offset 12 within `struct
           elf_prstatus'.  */
	cursig = va_arg (ap, int);
	bfd_put_16 (abfd, cursig, data + 12);

        /* Set `elf_gregset_t pr_reg' field (it has a type of `user_regs_struct'
           in fact occupying 4784 bytes at offset 112 within `struct elf_
           prstatus'.  */
	greg = va_arg (ap, const void *);
	memcpy (data + 112, greg, 4784);
	va_end (ap);

	return elfcore_write_note (abfd, buf, bufsiz,
				   "CORE", note_type, data, sizeof (data));
      }
    }
}

typedef struct
{
  Elf_Internal_Sym *sym;
  bfd_vma end;
} loc_sym_with_end;

static int
compare_local_sym_starts (const void *l, const void *r)
{
  loc_sym_with_end * const *lhs = l;
  loc_sym_with_end * const *rhs = r;

  if ((*lhs)->sym->st_value < (*rhs)->sym->st_value)
    return -1;

  if ((*lhs)->sym->st_value > (*rhs)->sym->st_value)
    return 1;

  return 0;
}

static int
compare_local_sym_ends (const void *l, const void *r)
{
  loc_sym_with_end * const *lhs = l;
  loc_sym_with_end * const *rhs = r;

  if ((*lhs)->end < (*rhs)->end)
    return -1;

  if ((*lhs)->end > (*rhs)->end)
    return 1;

  return 0;
}

typedef struct
{
  struct elf_link_hash_entry *hash;
  bfd_vma end;
} glob_hash_with_end;

static int
compare_glob_hash_starts (const void *l, const void *r)
{
  glob_hash_with_end * const *lhs = l;
  glob_hash_with_end * const *rhs = r;

  if ((*lhs)->hash->root.u.def.value < (*rhs)->hash->root.u.def.value)
    return -1;

  if ((*lhs)->hash->root.u.def.value > (*rhs)->hash->root.u.def.value)
    return 1;

  return 0;
}

static int
compare_glob_hash_ends (const void *l, const void *r)
{
  glob_hash_with_end * const *lhs = l;
  glob_hash_with_end * const *rhs = r;

  if ((*lhs)->end < (*rhs)->end)
    return -1;

  if ((*lhs)->end > (*rhs)->end)
    return 1;

  return 0;
}

bool
_bfd_e2k_elf_relax_section (bfd *abfd,
			    struct bfd_section *sec,
			    struct bfd_link_info *info,
			    bool *again)
{
  if (bfd_link_relocatable (info))
    (*info->callbacks->einfo)
      (_("%P%F: --relax and -r may not be used together\n"));

  unsigned int i, j, k, l, m;
  unsigned int sec_shndx = _bfd_elf_section_from_bfd_section (abfd, sec);
  struct bfd_elf_section_data *data = elf_section_data (sec);
  bfd_byte *contents;
  Elf_Internal_Rela *relocs;

  unsigned int loc_sym_count = 0;
  loc_sym_with_end *loc_sym = NULL;
  loc_sym_with_end **loc_sym_start = NULL, **loc_sym_end = NULL;

  unsigned int glob_hash_count = 0;
  glob_hash_with_end *glob_hash = NULL;
  glob_hash_with_end **glob_hash_start = NULL, **glob_hash_end = NULL;

  Elf_Internal_Shdr *symtab_hdr = &elf_tdata (abfd)->symtab_hdr;
  struct _bfd_e2k_elf_link_hash_table *htab = _bfd_e2k_elf_hash_table (info);

  /* Read this BFD's contents if we haven't done so already.  */
  if (!data->this_hdr.contents)
    bfd_malloc_and_get_section (abfd, sec, &data->this_hdr.contents);

  if (symtab_hdr->contents == NULL)
    {
      symtab_hdr->contents =
	(unsigned char *) bfd_elf_get_elf_syms (abfd, symtab_hdr,
						symtab_hdr->sh_info,
						0, NULL, NULL, NULL);
    }

  contents = data->this_hdr.contents;

  if ( data->relocs)
    relocs = data->relocs;
  else if (sec->reloc_count != 0)
    {
      if (!(relocs = _bfd_elf_link_read_relocs (abfd, sec, NULL, NULL,
						info->keep_memory)))
	goto fail;
    }
  else
    relocs = NULL;

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < symtab_hdr->sh_info; j++)
	{
	  Elf_Internal_Sym *sym
	    = (Elf_Internal_Sym *) symtab_hdr->contents + j;
	  if (sym->st_shndx == sec_shndx)
	    {
	      if (i == 0)
		loc_sym_count++;
	      else
		{
		  loc_sym[loc_sym_count].sym = sym;
		  loc_sym[loc_sym_count].end = sym->st_value + sym->st_size;
		  loc_sym_start[loc_sym_count]
		    = loc_sym_end[loc_sym_count]
		    = &loc_sym[loc_sym_count];

		  loc_sym_count++;
		}
	    }
	}

      if (i == 0)
	{
	  loc_sym = bfd_malloc (loc_sym_count * sizeof (loc_sym[0]));

	  loc_sym_start = bfd_malloc (loc_sym_count
				      * sizeof (loc_sym_start[0]));
	  loc_sym_end = bfd_malloc (loc_sym_count
				    * sizeof (loc_sym_end[0]));

	  if (loc_sym == NULL
	      || loc_sym_start == NULL
	      || loc_sym_end == NULL)
	    goto fail;

	  loc_sym_count = 0;
	}
    }

  qsort (loc_sym_start, loc_sym_count, sizeof (loc_sym_start[0]),
	 compare_local_sym_starts);

  qsort (loc_sym_end, loc_sym_count, sizeof (loc_sym_end[0]),
	 compare_local_sym_ends);

  for (i = 0; i < 2; i++)
    {
      struct elf_link_hash_entry **sym_hashes = elf_sym_hashes (abfd);
      for (j = 0; j < ((symtab_hdr->sh_size / htab->bytes_per_sym)
		       - symtab_hdr->sh_info); j++)
	{
	  struct elf_link_hash_entry *sym_hash = sym_hashes[j];

	  /* The '--wrap SYMBOL' option is causing a pain when the object file,
	     containing the definition of __wrap_SYMBOL, includes a direct
	     call to SYMBOL as well. Since both __wrap_SYMBOL and SYMBOL reference
	     the same symbol (which is __wrap_SYMBOL), but still exist as two
	     different symbols in 'sym_hashes', we don't want to adjust
	     the global symbol __wrap_SYMBOL twice.

	     The same problem occurs with symbols that are versioned_hidden, as
	     foo becomes an alias for foo@BAR, and hence they need the same
	     treatment.  */
	  if (info->wrap_hash != NULL
	      || sym_hash->versioned != unversioned)
	    {
	      struct elf_link_hash_entry **cur_sym_hashes;
	      /* Loop only over the symbols which have already been seen.  */
	      for (cur_sym_hashes = sym_hashes; cur_sym_hashes < &sym_hashes[j];
		   cur_sym_hashes++)
		{
		  /* If the current symbol is identical to 'sym_hash', that means
		     the symbol has already been seen.  */
		  if (*cur_sym_hashes == sym_hash)
		    break;
		}
	      /* Don't take the symbol into account again.  */
	      if (cur_sym_hashes < &sym_hashes[j])
		continue;
	    }

	  if ((sym_hash->root.type == bfd_link_hash_defined
	       || sym_hash->root.type == bfd_link_hash_defweak)
	      && sym_hash->root.u.def.section == sec)
	    {
	      if (i == 0)
		glob_hash_count++;
	      else
		{
		  glob_hash[glob_hash_count].hash = sym_hash;
		  glob_hash[glob_hash_count].end = (sym_hash->root.u.def.value
						    + sym_hash->size);
		  glob_hash_start[glob_hash_count]
		    = glob_hash_end[glob_hash_count]
		    = &glob_hash[glob_hash_count];

		  glob_hash_count++;
		}
	    } 
	}

      if (i == 0)
	{
	  glob_hash = bfd_malloc (glob_hash_count * sizeof (glob_hash[0]));
	  glob_hash_start = bfd_malloc (glob_hash_count
					* sizeof (glob_hash_start[0]));
	  glob_hash_end = bfd_malloc (glob_hash_count
				      * sizeof (glob_hash_end[0]));

	  if (glob_hash == NULL
	      || glob_hash_start == NULL
	      || glob_hash_end == NULL)
	    goto fail;

	  glob_hash_count = 0;
	}
    }

  qsort (glob_hash_start, glob_hash_count, sizeof (glob_hash_start[0]),
	 compare_glob_hash_starts);
  qsort (glob_hash_end, glob_hash_count, sizeof (glob_hash_end[0]),
	 compare_glob_hash_ends);

  /* Reset local and global symbols' indices. */
  j = k = l = m = 0;
  /* The initial SHIFT is zero, of course.  */
  int shift = 0;

  for (i = 0; i < sec->reloc_count; i++)
    {
      if (ELF_R_TYPE (abfd, relocs[i].r_info) == R_E2K_MCSTBUG_140436_RELAX)
	{
	  bfd_vma addr = ((sec->output_section->vma + sec->output_offset
			   + relocs[i].r_offset - relocs[i].r_addend)
			  + shift);

	  bfd_vma new_r_addend = (((addr & 0xfff) >= 0xdc0
				   && (addr & 0xfff) < 0xe00)
				  ? 0xe00 - (addr & 0xfff)
				  : 0x0);

	  int delta = new_r_addend - relocs[i].r_addend;
	  if (delta != 0)
	    {
	      bfd_byte *ptr_to_label = contents + relocs[i].r_offset + shift;
	      memmove (ptr_to_label + delta, ptr_to_label,
		       sec->size - (relocs[i].r_offset + shift));

	      if (new_r_addend)
		{
		  /* Adjust the preceding NOP appropriately: encode the right
		     HS.lng and zero out the remaining part.  */
		  bfd_put_32 (abfd, ((new_r_addend / 8 - 1) << 4),
			      ptr_to_label + delta - new_r_addend);
		  memset (ptr_to_label + delta - new_r_addend + 4, 0,
			  new_r_addend - 4);
		}
	    }

	  sec->size += delta;

	  /* Look for local and global symbols preceding the label subject to
	     the workaround. Note that symbol values and `r_offset's prior to
	     the shift are used.  */
	  for (;
	       (j < loc_sym_count
		&& loc_sym_start[j]->sym->st_value < relocs[i].r_offset);
	       j++)
	    loc_sym_start[j]->sym->st_value += shift;

	  for (;
	       (k < glob_hash_count
		&& (glob_hash_start[k]->hash->root.u.def.value
		    < relocs[i].r_offset));
	       k++)
	    glob_hash_start[k]->hash->root.u.def.value += shift;

	  for (;
	       (l < loc_sym_count
		&& loc_sym_end[l]->end < relocs[i].r_offset);
	       l++)
	    loc_sym_end[l]->end += shift;

	  for (;
	       (m < glob_hash_count
		&& glob_hash_end[m]->end < relocs[i].r_offset);
	       m++)
	    glob_hash_end[m]->end += shift;


	  relocs[i].r_addend += delta;
	  shift += delta;
	}

      relocs[i].r_offset += shift;
    }


  /* Shift the remaining symbols lying after the last label subject to
     the workaround.  */
  for (; j < loc_sym_count; j++)
    loc_sym_start[j]->sym->st_value += shift;

  for (; k < glob_hash_count; k++)
    glob_hash_start[k]->hash->root.u.def.value += shift;

  for (; l < loc_sym_count; l++)
    loc_sym_end[l]->end += shift;

  for (; m < glob_hash_count; m++)
    glob_hash_end[m]->end += shift;

  for (j = 0; j < loc_sym_count; j++)
    loc_sym[j].sym->st_size = loc_sym[j].end - loc_sym[j].sym->st_value;

  for (k = 0; k < glob_hash_count; k++)
    glob_hash[k].hash->size = (glob_hash[k].end
			      - glob_hash[k].hash->root.u.def.value);


  free (glob_hash_end);
  free (glob_hash_start);
  free (glob_hash);

  free (loc_sym_end);
  free (loc_sym_start);
  free (loc_sym);

  *again = false;
  return true;

 fail:
  if (loc_sym)
    free (loc_sym);

  if (loc_sym_start)
    free (loc_sym_start);

  if (loc_sym_end)
    free (loc_sym_end);

  if (glob_hash)
    free (glob_hash);

  if (glob_hash_start)
    free (glob_hash_start);

  if (glob_hash_end)
    free (glob_hash_end);

 
  return false;
}

unsigned int
_bfd_e2k_elf_get_range_num (bfd *abfd)
{
  if ((elf_tdata (abfd)->elf_header->e_flags & EF_E2K_PACK_SEGMENTS) == 0)
    return 0;

  unsigned int i = 0;
  unsigned int phnum = elf_tdata (abfd)->elf_header->e_phnum;
  Elf_Internal_Phdr *phdr;

  for (phdr = elf_tdata (abfd)->phdr;
       phdr < &elf_tdata (abfd)->phdr[phnum];
       phdr++)
    {
      if (phdr->p_type == PT_LOAD)
	++i;
    }

  return i;
}

void
_bfd_e2k_elf_fill_ranges (bfd *abfd, unsigned int range_num,
			  struct pm_range *ranges)
{
  if ((elf_tdata (abfd)->elf_header->e_flags & EF_E2K_PACK_SEGMENTS) == 0)
    return;

  unsigned int i;
  unsigned int phnum = elf_tdata (abfd)->elf_header->e_phnum;
  Elf_Internal_Phdr *phdr;

  for (phdr = elf_tdata (abfd)->phdr, i = 0;
       (phdr < &elf_tdata (abfd)->phdr[phnum]
	/* Just to be on the safe side.  */
	&& i < range_num);
       ++phdr)
    {
      if (phdr->p_type == PT_LOAD)
	{
	  ranges[i].min = phdr->p_vaddr;
	  ranges[i].max = phdr->p_vaddr + phdr->p_memsz;
	  ranges[i].align = phdr->p_align;
	  ranges[i].in_cud = (phdr->p_flags & PF_X) ? 1 : 0;
	  i++;
	}
    }

  /* Stupidly sort the obtained ranges. I believe that qsort () may be
     unavailable in context of ld.so  */
  for (i = 0; i < range_num - 1; i++)
    {
      unsigned int j;
      for (j = i + 1; j < range_num; j++)
	{
	  if (ranges[j].min < ranges[i].min)
	    {
	      struct pm_range tmp = ranges[i];
	      ranges[i] = ranges[j];
	      ranges[j] = tmp;
	    }
	}
    }

  bfd_vma max_page_aligned = 0;
  bfd_vma cud_size = 0, gd_size = 0;

  for (i = 0; i < range_num; i++)
    {
      bfd_vma min_page_aligned = ranges[i].min & ~(ranges[i].align - 1);
      bfd_vma b, r, pos;

      /* MAX_PAGE_ALIGNED corresponds to the preceding segment in this
	 comparison, of course.  */
      if (min_page_aligned < max_page_aligned)
	{
	  /* The Kernel should have failed to load this executable
	     in such a case.  */
	}

      max_page_aligned = (ranges[i].max + 0xfffULL) & ~(0xfffULL);

      if (ranges[i].in_cud)
	pos = cud_size;
      else
	pos = gd_size;

      pos = (pos + 0xfffULL) & ~0xfffULL;
      r = ranges[i].min & (ranges[i].align - 1);
      b = (pos + ranges[i].align - (r + 1)) / ranges[i].align;
      pos = b * ranges[i].align + r;

      ranges[i].delta = pos - ranges[i].min;
      pos += ranges[i].max - ranges[i].min;

      if (ranges[i].in_cud)
	cud_size = pos;
      else
	gd_size = pos;
    }
}

long
_bfd_e2k_elf_get_offset_delta (unsigned int range_num, struct pm_range *ranges,
			       bfd_vma off)
{
  unsigned int j;
  for (j = 0; j < range_num; j++)
    {
      if (off >= ranges[j].min && off < ranges[j].max)
	  return ranges[j].delta;
    }

  return 0;
}
