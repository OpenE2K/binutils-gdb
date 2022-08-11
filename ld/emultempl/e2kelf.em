# This shell script emits a C file. -*- C -*-
#   Copyright 2003, 2005, 2006, 2007, 2009 Free Software Foundation, Inc.
#
# This file is part of the GNU Binutils.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
# MA 02110-1301, USA.
#

# This file is sourced from elf.em, and defines extra e2k-elf
# specific routines.
#
# Define some shell vars to insert bits of code into the standard elf
# parse_args and list_options functions.
#

# Create packed PM ELFs for glibc by default and never for uclibc.
if test -z "$E2K_UCLIBC"; then
	PACK_CG=TRUE
else
	PACK_CG=FALSE
fi

fragment <<EOF

#include "safe-ctype.h"
#include "elfxx-e2k.h"

static int e2k_ipd;
static int e2k_is_x86app;
static int e2k_is_4mpages;

/* Specifies that an architecture has been explicitly set via a command
   line.  */
static bfd_boolean arch_set_via_cmdline;
/* Whether the target should restrict itself to input files having an
   architecture set via cmdline by means of '--restrict-to-arch ARCH' only (see
   Bug #82047). Provided that this variable is TRUE, the former should be TRUE
   as well, since --restrict-to-arch specifies output ARCH at the same
   time.  */
static bfd_boolean restrict_to_arch;

static bfd_boolean relaxed_e2k_machine_check;
static int link_mixed_eir;
static bfd_boolean output_new_e_machine = TRUE;
static bfd_boolean mark_objects;
static bfd_boolean inside_marked_objects;
/* A simulating mode which should make it possible to "link" any input object
   file alone in a reproducible way. The goal is to get rid of relocations
   which make it so difficult to compare output files produced by different
   assemblers.  */
static bfd_boolean simulate;

/* Use the default based on the above PACK_CG setting.  */
static bfd_boolean pack_cg = $PACK_CG;

static bfd_boolean ignore_pure_eir_files;

/* Placeholders used to restore the corresponding values set
   via cmdline.  */
static enum bfd_architecture cmdline_output_architecture;
static unsigned long cmdline_output_machine;
EOF

# This code gets inserted into the generic elf32.sc linker script
# and allows us to define our own command line switches.

PARSE_AND_LIST_PROLOGUE='
#define OPTION_E2K_IPD                          301
#define OPTION_E2K_X86APP                       302
#define OPTION_E2K_4MPAGES                      303
#define OPTION_RELAXED_E2K_MACHINE_CHECK        304
#define OPTION_LINK_MIXED_EIR			305
#define OPTION_OLD_E_MACHINE                    306
#define OPTION_NEW_PM_SEMANTICS                 307
#define OPTION_DSP_LINUX_MODE                   308
#define OPTION_MARK_REGULAR_OBJECTS             309
#define OPTION_START_REGULAR_OBJECTS            310
#define OPTION_END_REGULAR_OBJECTS              311
#define OPTION_BINARY_EIR_OUTPUT                312
#define OPTION_RESTRICT_TO_ARCH                 313
#define OPTION_SIMULATE                         314
#define OPTION_IGNORE_PURE_EIR_FILES            315
'

if test -z "$E2K_UCLIBC" ; then
PARSE_AND_LIST_PROLOGUE=$PARSE_AND_LIST_PROLOGUE'
#define OPTION_UNPACKED_CUD_GD			316
'
fi

PARSE_AND_LIST_LONGOPTS='
  { "e2k-ipd", required_argument, NULL, OPTION_E2K_IPD },
  { "e2k-x86app", no_argument, NULL, OPTION_E2K_X86APP },
  { "e2k-4mpages", no_argument, NULL, OPTION_E2K_4MPAGES },
  { "relaxed-e2k-machine-check", no_argument, NULL, OPTION_RELAXED_E2K_MACHINE_CHECK },
  { "link-mixed-eir", required_argument, NULL, OPTION_LINK_MIXED_EIR},
  { "old-e-machine", no_argument, NULL, OPTION_OLD_E_MACHINE},
  { "force-new-pm-semantics", no_argument, NULL, OPTION_NEW_PM_SEMANTICS},
  { "dsp-linux-mode", no_argument, NULL, OPTION_DSP_LINUX_MODE},
  { "mark-regular-objects", no_argument, NULL, OPTION_MARK_REGULAR_OBJECTS},
  { "start-regular-objects", no_argument, NULL, OPTION_START_REGULAR_OBJECTS},
  { "end-regular-objects", no_argument, NULL, OPTION_END_REGULAR_OBJECTS},
  { "binary-eir-output", no_argument, NULL, OPTION_BINARY_EIR_OUTPUT},
  { "restrict-to-arch", required_argument, NULL, OPTION_RESTRICT_TO_ARCH},
  { "simulate", no_argument, NULL, OPTION_SIMULATE},
  { "ignore-pure-eir-files", no_argument, NULL, OPTION_IGNORE_PURE_EIR_FILES},
'

if test -z "$E2K_UCLIBC" ; then
PARSE_AND_LIST_LONGOPTS=$PARSE_AND_LIST_LONGOPTS'
  { "dont-pack-cud-gd", no_argument, NULL, OPTION_UNPACKED_CUD_GD},
'
fi

PARSE_AND_LIST_OPTIONS='
  fprintf (file, _("  --link-mixed-eir={1,2,3}\n"));
  fprintf (file, _("\t\t\tLink mixed EIR\n"));
'

PARSE_AND_LIST_ARGS_CASES='
    case OPTION_E2K_IPD:
      {
        const char *end;
        e2k_ipd = (int) bfd_scan_vma (optarg, &end, 0);
        if (*end
            || e2k_ipd < 0
            || e2k_ipd > 2)
	  einfo (_("%P%F: invalid argument '\''%s'\'' to option '\''%s'\''\n"), optarg, "--e2k-ipd");
        e2k_ipd += 1;
      }
      break;

    case OPTION_E2K_X86APP:
      e2k_is_x86app = 1;
      break;

    case OPTION_E2K_4MPAGES:
      e2k_is_4mpages = 1;
      break;

    case OPTION_DSP_LINUX_MODE:
      e2k_dsp_linux_mode = TRUE;
      break;

    case OPTION_RESTRICT_TO_ARCH:
      restrict_to_arch = TRUE;
      /* Fall through.  */

    case '\'A\'':
      /* This option has a very special meaning for E2k. It is not
         absolutely necessary at present though. TODO: find out whether the
         underlying code (especially "ldfile_set_output_arch ()") is needed at
         all now that the output architecture is finally set in
         _bfd_e2k_elf_merge_private_bfd_data (). Probably it is, because the
         latter function makes use of OBFD->arch_info.  */
      {
        char *arch_name = xmalloc (strlen (optarg) + 4);
        sprintf (arch_name, "%s:%s", optarg, "'$MACHINE'");
        ldfile_set_output_arch (arch_name, bfd_arch_e2k);
        arch_set_via_cmdline = TRUE;
        free (arch_name);
      }
      /* Save architecture and machine values obtained two lines above in
         order to be able to restore them later in set_output_arch method.  */
      cmdline_output_architecture = ldfile_output_architecture;
      cmdline_output_machine = ldfile_output_machine;
      break;

    case OPTION_RELAXED_E2K_MACHINE_CHECK:
      relaxed_e2k_machine_check = TRUE;
      break;

    case OPTION_LINK_MIXED_EIR:
      if ((optarg[0] != '\''1'\'' && optarg[0] != '\''2'\''
           && optarg[0] != '\''3'\'')
          || optarg[1] != '\''\0'\'')
        einfo (_("%P%F: invalid value for '\''--link-mixed-eir'\'' option: '\''%s'\''\n"), optarg);
      link_mixed_eir = optarg[0] - '\''0'\'';
      break;

    case OPTION_OLD_E_MACHINE:
      output_new_e_machine = FALSE;
      break;

    case OPTION_NEW_PM_SEMANTICS:
      break;

    case OPTION_MARK_REGULAR_OBJECTS:
      mark_objects = TRUE;
      break;

    case OPTION_START_REGULAR_OBJECTS:
      inside_marked_objects = TRUE;
      break;

    case OPTION_END_REGULAR_OBJECTS:
      inside_marked_objects = FALSE;
      break;
 
   case OPTION_BINARY_EIR_OUTPUT:
      break;

   case OPTION_SIMULATE:
      simulate = TRUE;
      break;

   case OPTION_IGNORE_PURE_EIR_FILES:
      ignore_pure_eir_files = TRUE;
      break;


    case 1:
      /* Beware that this macro becomes part of emulation-specific "handle_
         option ()" method. Returning TRUE for a filename below prevents
         parse_args () in ld/lexsup.c from adding it as an input file.  */
      if (!mark_objects || inside_marked_objects)
        return FALSE;

      {
        bfd_boolean ret = FALSE;
        bfd *abfd = bfd_openr (optarg, "default");
        if (abfd == NULL)
          return FALSE;

        /* My goal is to prevent relocatable objects not surrounded by
           "--{start,end}-regular-objects" options from being included into
           the final link. As you remember such a situation emerges if an object
           is passed via "-Wl,f.o". This should apply neither to static nor to
           shared libraries explicitly passed by their filenames (i.e. not via
           -l option). Indeed, one may need to fetch some objects from the
           former in case the mixed EIR contained in them has not been linked
           into total EIR at "--link-mixed-eir=2" stage, while the latter never
           take part in EIR linkage at all. It was Bug #81255 that made me
           revisit the latter case.  */
        if (bfd_check_format (abfd, bfd_object)
            && (bfd_get_flavour (abfd) != bfd_target_elf_flavour
                || elf_elfheader (abfd)->e_type != ET_DYN))
          ret = TRUE;

        bfd_close (abfd);
        return ret;
      }

      break;
'

if test -z "$E2K_UCLIBC" ; then
PARSE_AND_LIST_ARGS_CASES=$PARSE_AND_LIST_ARGS_CASES'
   case OPTION_UNPACKED_CUD_GD:
      pack_cg = FALSE;
      break;
'
fi

fragment <<EOF

  /* This is called before the hash table is allocated.  */
static void
e2k_after_parse (void)
{
  /* Inhibit '--export-dynamic' in '--link-mixed-eir=X' mode. These options turn
     out to be passed together by LCC when it's invoked with '-fsanitize=address
     -fwhole' (see Bug #82854). Now that '--export-dynamic' enforces creation of
     dynamic sections, it would lead to appearance of a bogus '.dynamic' section
     in the relocatable output at '--linux-mixed-eir=1' stage. If this
     irrelevant '.dynamic' coming from an input file was eventually linked into
     the executable at the final stage, its bogus entries would override the
     ones created by LD during the final link, which would lead to a runtime
     failure described in the above bug.  */
  if (link_mixed_eir >=1 && link_mixed_eir <= 3)
    link_info.export_dynamic = FALSE;

  /* LINK_MIXED_EIR should be available by the time we open each input
     file.  */
  _bfd_e2k_elf_after_parse (link_mixed_eir);
  ldelf_after_parse ();
}


static bfd_boolean
pure_eir_finder (bfd *abfd ATTRIBUTE_UNUSED,
		 asection *section,
		 void *ptr ATTRIBUTE_UNUSED)
{
  return strcmp (section->name, ".pack_pure_eir") == 0;
}


static bfd_boolean
e2k_recognized_file (lang_input_statement_type *entry)
{
  if (link_mixed_eir != 0 && (entry->the_bfd->flags & DYNAMIC) != 0)
    return TRUE;

  if (ignore_pure_eir_files
      && bfd_sections_find_if (entry->the_bfd, pure_eir_finder, NULL))
    return TRUE;

  /* Otherwise, the standard implementation from 'elf.em' will do.  */
  return ldelf_load_symbols (entry);
}

static bfd_boolean
e2k_allow_dynamic_entries_in_relocatable_link (void)
{
  if (link_mixed_eir != 0)
    return TRUE;

  return FALSE;
}



/* This is called after the input files have been opened. TODO: some of the
   parameters below could be probably set via
   e2k_create_output_section_statements () which doesn't exist at
   present . . .  */
static void
e2k_after_open (void)
{
  /* Hash table has been already allocated by the time I call this
     function (see the end of 'open_output ()' in 'ldlang.c'.  */
  _bfd_e2k_elf_after_open (e2k_ipd, e2k_is_x86app, e2k_is_4mpages,
                           arch_set_via_cmdline, restrict_to_arch,
                           relaxed_e2k_machine_check, output_new_e_machine,
                           simulate, pack_cg);

  gld${EMULATION_NAME}_after_open ();
}

static char * gld${EMULATION_NAME}_get_script (int *);

static char *
e2k_get_script (int *isfile)
{
  if (link_mixed_eir == 2)
    {
      *isfile = 0;
      return ("SECTIONS\n"
              "{\n"
              "\t.pack_pure_eir : { *(.pack_pure_eir) }\n"
              "\t.pack_mixed_eir : { *(.pack_mixed_eir) }\n"
              "\t/DISCARD/ : { *(*) }\n"
              "}\n");
    }

  return gld${EMULATION_NAME}_get_script (isfile);
}

static void
e2k_set_output_arch (void)
{
EOF
if test -z "$KPDA"; then

if test "$MACHINE" = "64"; then
fragment <<EOF
  int addend = 0;
EOF
elif test "$MACHINE" = "32"; then
fragment <<EOF
  int addend = 1;
EOF
else
fragment <<EOF
  int addend = 2;
EOF
fi

fi
fragment <<EOF
  if (arch_set_via_cmdline)
    {
      /* Restore the values obtained from the commandline. They've
         already been spoiled by . . . ???  */
      ldfile_output_architecture = cmdline_output_architecture;
      ldfile_output_machine = cmdline_output_machine;
    }

  /* Now make the output file machine number match the TARGET vector. Keep in
     mind that currently we have a one to one correspondence between a target
     vector and the corresponding ABI, which is encoded in the machine number.
     E.g., ELF32 targets for E2K cannot be used to produce output for the 64-bit
     ABI and so on.

     This way, the 'OUTPUT_FORMAT ()' directive will SILENTLY (because currently
     I don't need a public discussion) take precedence over ABI which a user
     might have specified via the 'OUTPUT_ARCH(...:XX)' directive.  */

EOF

if test -z "$KPDA"; then
fragment <<EOF
  ldfile_output_machine = (ldfile_output_machine / 4) * 4 + addend;
EOF
fi

fragment <<EOF
  
  set_output_arch_default ();
}


EOF

if test -n "$LDEMUL_PLACE_ORPHAN"; then
fragment <<EOF

static lang_output_section_statement_type *
insert_output_section_statement (const char *name)
{
  lang_statement_list_type add;
  lang_output_section_statement_type *os;

  lang_list_init (&add);
  os = lang_enter_output_section_statement (name, NULL, 0,
                                            NULL, NULL, NULL, 0, 0);
  lang_leave_output_section_statement (0, "*default*", NULL, NULL);
  return os;
}

static lang_output_section_statement_type *
place_dsp_section (asection *s, const char *os_name)
{
  lang_output_section_statement_type *os;

  os = lang_output_section_find (os_name);
  if (os == NULL)
    {
      os = insert_output_section_statement (os_name);
      /* 2 ^ 17 == 128 Kb: align a DSP-specific output section in E2K space to
         maximal possible alignment at DSP side. This is probably the only way
         to ensure that the section and its symbols are aligned appropriately
         from the point of view of DSP.  */
      os->section_alignment = exp_intop (1U << 17);
    }

  lang_add_section (&os->children, s, NULL, os);
  return os;
}


static const char *
dsp_output_section_name (const char *sec_name)
{
  int is_text;
  int sid;
  const char *c;
  static char os_name[32];

  if (! (is_text = CONST_STRNEQ (sec_name, ".dsp_text"))
      && ! CONST_STRNEQ (sec_name, ".dsp_data")
      && ! CONST_STRNEQ (sec_name, ".dsp_rodata")
      && ! CONST_STRNEQ (sec_name, ".dsp_bss")
      && ! CONST_STRNEQ (sec_name, "DSP_COMMON"))
    return NULL;

  c = sec_name;
  while (*c != '\0' && ! ISDIGIT (*c))
    c++;

  if (! ISDIGIT (*c) || !ISDIGIT (c[1]) || c[2] != '\0')
    return NULL;

  sid = 10 * (c[0] - '0') + (c[1] - '0');
  if (sid >= 16)
    return NULL;

  sprintf (os_name, "%s%02d", is_text ? ".dsp_text" : ".dsp_data", sid);
  return xstrdup (os_name);
}

static lang_output_section_statement_type *
${LDEMUL_PLACE_ORPHAN} (asection *s, const char *secname, int constraint)
{
  struct _bfd_e2k_elf_link_hash_table *htab;
  htab = _bfd_e2k_elf_hash_table (&link_info);
  if (e2k_dsp_linux_mode && htab->have_dsp_output)
    {
      const char *os_name = dsp_output_section_name (s->name);
      if (os_name)
        return place_dsp_section (s, os_name);
    }

  return ldelf_place_orphan (s, secname, constraint);
}
EOF
fi

if test -n "$LDEMUL_AFTER_ALLOCATION" ; then
fragment <<EOF


static void
define_dsp_symbol (const char *name, asection *section, bfd_vma value)
{
  struct bfd_link_hash_entry *h;

  h = bfd_link_hash_lookup (link_info.hash, name, TRUE,
                            TRUE, TRUE);
  h->type = bfd_link_hash_defined;
  h->u.def.value = value;
  h->u.def.section = section;
}

static void
${LDEMUL_AFTER_ALLOCATION} (void)
{
  unsigned int i;
  struct _bfd_e2k_elf_link_hash_table *htab;
  htab = _bfd_e2k_elf_hash_table (&link_info);

  /* We don't need any segment map tuning when using a
     hand-made linker script for producing an executable to
     be loaded with BOOT. */
  if (!e2k_dsp_linux_mode || !htab->have_dsp_output)
    {
      gld${EMULATION_NAME}_after_allocation ();
      return;
    }

  /* The call of this function currently undoes all my attempts to assign VMA
     addresses to DSP sections . . .  */
  gld${EMULATION_NAME}_after_allocation ();

  for (i = 0; i < 16; i++)
    {
      static char os_name[64], sym_name[64];
      lang_output_section_statement_type *os;
      bfd_vma true_vma;

      true_vma = (bfd_get_section_by_name (link_info.output_bfd, ".dsp_mem")->vma
                  + 32 * 1024 * i);
      sprintf (os_name, ".dsp_text%02d",i);
      os = lang_output_section_find (os_name);
      if (os && os->bfd_section)
        {
          os->bfd_section->vma = true_vma;

          sprintf (sym_name, "__DSP%02d_CODE_BEGIN_VMA", i);
          define_dsp_symbol (sym_name, os->bfd_section, 0);

          sprintf (sym_name, "__DSP%02d_CODE_BEGIN_LMA", i);
          define_dsp_symbol (sym_name, bfd_abs_section_ptr,
                             os->bfd_section->lma);


          sprintf (sym_name, "__DSP%02d_CODE_END_LMA", i);
          define_dsp_symbol (sym_name, bfd_abs_section_ptr,
                             (os->bfd_section->lma
                              + os->bfd_section->size));
        }
      
      true_vma = (bfd_get_section_by_name (link_info.output_bfd, ".dsp_mem")->vma
                  + (512 + 128 * i) * 1024);

      sprintf (os_name, ".dsp_data%02d", i);
      os = lang_output_section_find (os_name);
      if (os && os->bfd_section)
        {
          os->bfd_section->vma = true_vma ;

          sprintf (sym_name, "__DSP%02d_DATA_BEGIN_VMA", i);
          define_dsp_symbol (sym_name, os->bfd_section, 0);

          sprintf (sym_name, "__DSP%02d_DATA_BEGIN_LMA", i);
          define_dsp_symbol (sym_name, bfd_abs_section_ptr,
                             os->bfd_section->lma);

          sprintf (sym_name, "__DSP%02d_DATA_END_LMA", i);
          define_dsp_symbol (sym_name, bfd_abs_section_ptr,
                             (os->bfd_section->lma + os->bfd_section->size));
        }
    }
}
EOF
fi


LDEMUL_GET_SCRIPT=e2k_get_script
LDEMUL_AFTER_PARSE=e2k_after_parse
LDEMUL_RECOGNIZED_FILE=e2k_recognized_file
LDEMUL_ALLOW_DYNAMIC_ENTRIES_IN_RELOCATABLE_LINK=\
e2k_allow_dynamic_entries_in_relocatable_link
LDEMUL_AFTER_OPEN=e2k_after_open
LDEMUL_SET_OUTPUT_ARCH=e2k_set_output_arch
LDEMUL_DISABLE_STANDARD_COMPATIBILITY_TESTS=TRUE
