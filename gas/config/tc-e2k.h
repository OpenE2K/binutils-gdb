/* tc-e2k.h - Macros and type defines for the E2k.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2,
   or (at your option) any later version.

   GAS is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with GAS; see the file COPYING.  If not, write
   to the Free Software Foundation, 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef TC_E2K
#define TC_E2K 1

#define LEX_HASH        (LEX_NAME|LEX_BEGIN_NAME) /* allow `#' inside symbol name */

extern const char *e2k_target_format (void);
#define TARGET_FORMAT e2k_target_format ()

#define TARGET_ARCH bfd_arch_e2k

extern unsigned long e2k_mach (void);
#define TARGET_MACH (e2k_mach ())

extern void e2k_elf_final_processing (void);
#define elf_tc_final_processing e2k_elf_final_processing


#define TARGET_BYTES_BIG_ENDIAN	0
#define MD_APPLY_FIX3

#define tc_fix_adjustable(X)  tc_e2k_fix_adjustable(X)
extern int tc_e2k_fix_adjustable (struct fix *);

/* Values passed to md_apply_fix don't include the symbol value.  */
#define MD_APPLY_SYM_VALUE(FIX) 0


#define md_convert_frag(b,s,f) \
  as_fatal (_("e2k convert_frag\n"))
#define md_estimate_size_before_relax(f,s) \
  (as_fatal(_("estimate_size_before_relax called")), 1)

#define md_start_line_hook() e2k_start_line_hook (input_line_pointer[-1])
#define md_cleanup() e2k_cleanup_hook ();

#define md_number_to_chars number_to_chars_littleendian

extern void e2k_start_line_hook (char);
extern void e2k_cleanup_hook (void);

extern void e2k_adjust_symtab (void);
#define tc_adjust_symtab()	e2k_adjust_symtab ()

extern char *e2k_canonicalize_symbol_name (char *);
#define tc_canonicalize_symbol_name(s)  e2k_canonicalize_symbol_name (s)

#define tc_init_after_args()    e2k_init ()
extern void e2k_init (void);

extern int e2k_parse_name (char *, expressionS *, char *);
#define md_parse_name(name, e, m, nextP) e2k_parse_name (name, e, nextP)

extern void e2k_cons_fix_new (struct frag *, int,
                              int, struct expressionS *);
#define TC_CONS_FIX_NEW(FRAG, WHERE, NBYTES, EXP, RELOC)      \
  e2k_cons_fix_new (FRAG, WHERE, NBYTES, EXP)


/* This is probably required in order to make arithmetic on symbols coming
   from different sections. Isn't it?  */
#define DIFF_EXPR_OK            1

extern void e2k_end (void);
#define md_end() e2k_end ()

/* We want .cfi_* pseudo-ops for generating unwind info.  */
#define TARGET_USE_CFIPOP               1
#define DWARF2_CIE_DATA_ALIGNMENT       (-8)
#define DWARF2_DEFAULT_RETURN_COLUMN    0

/* This lets one ensure that `.eh_frame' is writable in PM.  */
#define DWARF2_EH_FRAME_READ_ONLY e2k_dwarf2_eh_frame_read_only ()
extern int e2k_dwarf2_eh_frame_read_only (void);


#define md_register_arithmetic 0

#define tc_allow_U_suffix 0


/* Note that these are the powers of 2.  */

#define EH_FRAME_ALIGNMENT				\
  (e2k_eh_frame_alignment () == 4			\
   ? 4 : (bfd_get_arch_size (stdoutput) == 64 ? 3 : 2))

extern int e2k_eh_frame_alignment (void);


#define tc_cfi_reloc_for_encoding e2k_cfi_reloc_for_encoding
extern bfd_reloc_code_real_type e2k_cfi_reloc_for_encoding (int encoding);

#endif /* TC_E2K  */
