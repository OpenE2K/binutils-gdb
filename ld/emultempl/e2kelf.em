# This shell script emits a C file. -*- C -*-
#   Copyright (C) 2009-2025 AO MCST.
#   Copyright (C) 2009-2025 Free Software Foundation, Inc.
#
# This file is part of GNU Binutils.
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
# along with this program; see the file COPYING3. If not,
# see <http://www.gnu.org/licenses/>.
#

# This file is sourced from elf.em, and defines extra e2k-elf
# specific routines.
#
# Define some shell vars to insert bits of code into the standard elf
# parse_args and list_options functions.
#

# Create packed PM ELFs for glibc by default.
PACK_CG=true

if test -n "$ENABLE_FIX_LCC_BUG_142105"; then
MCSTBUG_140436_DEFAULT_VALUE="true";
else
MCSTBUG_140436_DEFAULT_VALUE="true";
fi

fragment <<EOF

#include "ldlex.h"
#include "safe-ctype.h"
#include "elfxx-e2k.h"

static int e2k_ipd;
static int e2k_is_x86app;
static int e2k_is_4mpages;

/* Specifies that an architecture has been explicitly set via a command
   line.  */
static bool arch_set_via_cmdline;
/* Whether the target should restrict itself to input files having an
   architecture set via cmdline by means of '--restrict-to-arch ARCH' only (see
   Bug #82047). Provided that this variable is true, the former should be true
   as well, since --restrict-to-arch specifies output ARCH at the same
   time.  */
static bool restrict_to_arch;

static bool relaxed_e2k_machine_check;
static int link_mixed_eir;
static bool output_new_e_machine = true;
static bool mark_objects;
static bool inside_marked_objects;
/* A simulating mode which should make it possible to "link" any input object
   file alone in a reproducible way. The goal is to get rid of relocations
   which make it so difficult to compare output files produced by different
   assemblers.  */
static bool simulate;

/* Use the default based on the above PACK_CG setting.  */
static bool pack_cg = $PACK_CG;
static bool mcstbug_140436 = $MCSTBUG_140436_DEFAULT_VALUE;
static bool movtd_ct_plt = false;

/* Disable PM-specific checks, for example, that variables are not defined in
   code segment (executable sections). Such checks make no sense if CUD
   coincides with GD which can presumably be achieved by means of non-standard
   LD scripts (see MCSTBug #156213, Comment #4).  */
static bool relaxed_e2k_pm_check = false;

static bool ignore_pure_eir_files;

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
#define OPTION_MARK_REGULAR_OBJECTS             309
#define OPTION_START_REGULAR_OBJECTS            310
#define OPTION_END_REGULAR_OBJECTS              311
#define OPTION_BINARY_EIR_OUTPUT                312
#define OPTION_RESTRICT_TO_ARCH                 313
#define OPTION_SIMULATE                         314
#define OPTION_IGNORE_PURE_EIR_FILES            315
#define OPTION_UNPACKED_CUD_GD			316
#define OPTION_FIX_LCC_BUG_142105		317
#define OPTION_MOVTD_CT_PLT			318
#define OPTION_RELAXED_E2K_PM_CHECK		319
'


PARSE_AND_LIST_LONGOPTS='
  { "e2k-ipd", required_argument, NULL, OPTION_E2K_IPD },
  { "e2k-x86app", no_argument, NULL, OPTION_E2K_X86APP },
  { "e2k-4mpages", no_argument, NULL, OPTION_E2K_4MPAGES },
  { "relaxed-e2k-machine-check", no_argument, NULL, OPTION_RELAXED_E2K_MACHINE_CHECK },
  { "link-mixed-eir", required_argument, NULL, OPTION_LINK_MIXED_EIR},
  { "old-e-machine", no_argument, NULL, OPTION_OLD_E_MACHINE},
  { "force-new-pm-semantics", no_argument, NULL, OPTION_NEW_PM_SEMANTICS},
  { "mark-regular-objects", no_argument, NULL, OPTION_MARK_REGULAR_OBJECTS},
  { "start-regular-objects", no_argument, NULL, OPTION_START_REGULAR_OBJECTS},
  { "end-regular-objects", no_argument, NULL, OPTION_END_REGULAR_OBJECTS},
  { "binary-eir-output", no_argument, NULL, OPTION_BINARY_EIR_OUTPUT},
  { "restrict-to-arch", required_argument, NULL, OPTION_RESTRICT_TO_ARCH},
  { "simulate", no_argument, NULL, OPTION_SIMULATE},
  { "ignore-pure-eir-files", no_argument, NULL, OPTION_IGNORE_PURE_EIR_FILES},
  { "dont-pack-cud-gd", no_argument, NULL, OPTION_UNPACKED_CUD_GD},
'

if test -n "$ENABLE_FIX_LCC_BUG_142105"; then
PARSE_AND_LIST_LONGOPTS=$PARSE_AND_LIST_LONGOPTS'
  { "fix-lcc-bug142105", optional_argument, NULL, OPTION_FIX_LCC_BUG_142105},
'
fi

PARSE_AND_LIST_LONGOPTS=$PARSE_AND_LIST_LONGOPTS'
  { "plt-via-movtd-ct", no_argument, NULL, OPTION_MOVTD_CT_PLT},
  { "relaxed-e2k-pm-check", no_argument, NULL, OPTION_RELAXED_E2K_PM_CHECK },
'

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

    case OPTION_RESTRICT_TO_ARCH:
      restrict_to_arch = true;
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
        arch_set_via_cmdline = true;
        free (arch_name);
      }
      /* Save architecture and machine values obtained two lines above in
         order to be able to restore them later in set_output_arch method.  */
      cmdline_output_architecture = ldfile_output_architecture;
      cmdline_output_machine = ldfile_output_machine;
      break;

    case OPTION_RELAXED_E2K_MACHINE_CHECK:
      relaxed_e2k_machine_check = true;
      break;

    case OPTION_LINK_MIXED_EIR:
      if ((optarg[0] != '\''1'\'' && optarg[0] != '\''2'\''
           && optarg[0] != '\''3'\'')
          || optarg[1] != '\''\0'\'')
        einfo (_("%P%F: invalid value for '\''--link-mixed-eir'\'' option: '\''%s'\''\n"), optarg);
      link_mixed_eir = optarg[0] - '\''0'\'';
      break;

    case OPTION_OLD_E_MACHINE:
      output_new_e_machine = false;
      break;

    case OPTION_NEW_PM_SEMANTICS:
      break;

    case OPTION_MARK_REGULAR_OBJECTS:
      mark_objects = true;
      break;

    case OPTION_START_REGULAR_OBJECTS:
      inside_marked_objects = true;
      break;

    case OPTION_END_REGULAR_OBJECTS:
      inside_marked_objects = false;
      break;
 
   case OPTION_BINARY_EIR_OUTPUT:
      break;

   case OPTION_SIMULATE:
      simulate = true;
      break;

   case OPTION_IGNORE_PURE_EIR_FILES:
      ignore_pure_eir_files = true;
      break;


    case 1:
      /* Beware that this macro becomes part of emulation-specific "handle_
         option ()" method. Returning true for a filename below prevents
         parse_args () in ld/lexsup.c from adding it as an input file.  */
      if (!mark_objects || inside_marked_objects)
        return false;

      {
        bool ret = false;
        bfd *abfd = bfd_openr (optarg, "default");
        if (abfd == NULL)
          return false;

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
          ret = true;

        bfd_close (abfd);
        return ret;
      }

      break;

   case OPTION_UNPACKED_CUD_GD:
      pack_cg = false;
      break;
'

if test -n "$ENABLE_FIX_LCC_BUG_142105"; then
PARSE_AND_LIST_ARGS_CASES=$PARSE_AND_LIST_ARGS_CASES'
   case OPTION_FIX_LCC_BUG_142105:
      if (optarg == NULL)
	mcstbug_140436 = true;
      else
	{
	  if (optarg[0] == '\'0\'' && optarg[1] == '\'\\0\'')
	    mcstbug_140436 = false;
	  else
	    einfo (_("%P: error: unrecognized option for "
		     "--fix-lcc-bug-142105: %s\n"), optarg);
	}
      break;
'
fi

PARSE_AND_LIST_ARGS_CASES=$PARSE_AND_LIST_ARGS_CASES'
   case OPTION_MOVTD_CT_PLT:
      movtd_ct_plt = true;
      break;
   case OPTION_RELAXED_E2K_PM_CHECK:
      relaxed_e2k_pm_check = true;
      break;
'


if test -n "$E2K_MODE_SPECIFIC_OPTIONS"; then
PARSE_AND_LIST_ARGS_CASES=$PARSE_AND_LIST_ARGS_CASES"
$E2K_MODE_SPECIFIC_OPTIONS
"
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
    link_info.export_dynamic = false;

  /* LINK_MIXED_EIR should be available by the time we open each input
     file.  */
  _bfd_e2k_elf_after_parse (link_mixed_eir);
  ldelf_after_parse ();
}


static bool
pure_eir_finder (bfd *abfd ATTRIBUTE_UNUSED,
		 asection *section,
		 void *ptr ATTRIBUTE_UNUSED)
{
  return strcmp (section->name, ".pack_pure_eir") == 0;
}


static bool
e2k_recognized_file (lang_input_statement_type *entry)
{
  if (link_mixed_eir != 0 && (entry->the_bfd->flags & DYNAMIC) != 0)
    return true;

  if (ignore_pure_eir_files
      && bfd_sections_find_if (entry->the_bfd, pure_eir_finder, NULL))
    return true;

  /* Otherwise, the standard implementation from 'elf.em' will do.  */
  return ldelf_load_symbols (entry);
}

static bool
e2k_allow_dynamic_entries_in_relocatable_link (void)
{
  if (link_mixed_eir != 0)
    return true;

  return false;
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
                           simulate, pack_cg, mcstbug_140436, movtd_ct_plt,
			   relaxed_e2k_pm_check);

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
                                            NULL, NULL, NULL, NULL, 0, 0);
  lang_leave_output_section_statement (0, "*default*", NULL, NULL);
  return os;
}

EOF
fi


if [ "${EMULATION_NAME}" = "elf64_e2k_pm" ]; then
fragment <<EOF
static void
gld${EMULATION_NAME}_set_symbols (void)
{
  if (bfd_link_pde (&link_info))
    link_info.type = type_pie;

  /* "nointerp" ensures that `link_info.dynamic_undefined_weak' is set to 0
     in `ldelf_after_parse ()' when linking an executable, which prevents an
     undefined WEAK symbol from being output as dynamic.  */
  if (/* Equivalent to bfd_link_pie (...) with the hack a few lines ago
         in mind.  */
      bfd_link_executable (&link_info)
      /* Check for `-static' aka `-dn' on the linkage line.   */
      && input_flags.dynamic == false)
    link_info.nointerp = 1;
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
LDEMUL_DISABLE_STANDARD_COMPATIBILITY_TESTS=true

if [ "${EMULATION_NAME}" = "elf64_e2k_pm" ]; then
LDEMUL_SET_SYMBOLS=gld${EMULATION_NAME}_set_symbols
fi
