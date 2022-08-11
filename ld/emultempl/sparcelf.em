# This shell script emits a C file. -*- C -*-
#

LDEMUL_GET_SCRIPT=${EMULATION_NAME}_get_script
LDEMUL_AFTER_PARSE=${EMULATION_NAME}_after_parse
LDEMUL_RECOGNIZED_FILE=${EMULATION_NAME}_recognized_file
LDEMUL_ALLOW_DYNAMIC_ENTRIES_IN_RELOCATABLE_LINK=\
${EMULATION_NAME}_allow_dynamic_entries_in_relocatable_link

fragment <<EOF

#include "hashtab.h"
#include "elfxx-sparc.h"

static int link_mixed_eir = 0;
static bfd_boolean mark_objects;
static bfd_boolean inside_marked_objects;
static bfd_boolean ignore_pure_eir_files;

static char * gld${EMULATION_NAME}_get_script (int *);

static char *
${LDEMUL_GET_SCRIPT} (int *isfile)
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
${LDEMUL_AFTER_PARSE} (void)
{
  _bfd_sparc_elf_after_parse (link_mixed_eir);
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
${LDEMUL_RECOGNIZED_FILE} (lang_input_statement_type *entry)
{
  if (link_mixed_eir != 0 && (entry->the_bfd->flags & DYNAMIC) != 0)
    return TRUE;

  if (ignore_pure_eir_files
      && bfd_sections_find_if (entry->the_bfd, pure_eir_finder, NULL))
    return TRUE;

  /* Otherwise, the standard implementation from 'ldelf.c' will do.  */
  return ldelf_load_symbols (entry);
}

static bfd_boolean
${LDEMUL_ALLOW_DYNAMIC_ENTRIES_IN_RELOCATABLE_LINK} (void)
{
  if (link_mixed_eir != 0)
    return TRUE;

  return FALSE;
}

EOF



PARSE_AND_LIST_PROLOGUE='
#define OPTION_LINK_MIXED_EIR                   301
#define OPTION_BINARY_EIR_OUTPUT                302
#define OPTION_MARK_REGULAR_OBJECTS             303
#define OPTION_START_REGULAR_OBJECTS            304
#define OPTION_END_REGULAR_OBJECTS              305
#define OPTION_IGNORE_PURE_EIR_FILES            306
'

PARSE_AND_LIST_LONGOPTS='
  { "link-mixed-eir", required_argument, NULL, OPTION_LINK_MIXED_EIR },
  { "binary-eir-output", no_argument, NULL, OPTION_BINARY_EIR_OUTPUT},
  { "mark-regular-objects", no_argument, NULL, OPTION_MARK_REGULAR_OBJECTS},
  { "start-regular-objects", no_argument, NULL, OPTION_START_REGULAR_OBJECTS},
  { "end-regular-objects", no_argument, NULL, OPTION_END_REGULAR_OBJECTS},
  { "ignore-pure-eir-files", no_argument, NULL, OPTION_IGNORE_PURE_EIR_FILES},
'


PARSE_AND_LIST_OPTIONS='
  fprintf (file, _("     --link-mixed-eir={1,2,3}\n"));
  fprintf (file, _("\t\t\tLink mixed EIR\n"));
'

PARSE_AND_LIST_ARGS_CASES='
    case OPTION_LINK_MIXED_EIR:
      if ((optarg[0] != '\''1'\'' && optarg[0] != '\''2'\'' && optarg[0] != '\''3'\'')
          || optarg[1] != '\''\0'\'')
        einfo (_("%P%F: invalid value for `--link-mixed-eir'\'' option: '\''%s'\''\n"), optarg);
      link_mixed_eir = optarg[0] - '\''0'\'';
      break;

    case OPTION_BINARY_EIR_OUTPUT:
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

   case OPTION_IGNORE_PURE_EIR_FILES:
      ignore_pure_eir_files = TRUE;
      break;

    case 1:
      if (!mark_objects || inside_marked_objects)
        return FALSE;

      {
        bfd_boolean ret = FALSE;
        bfd *abfd = bfd_openr (optarg, "default");
        if (abfd == NULL)
          return FALSE;

        if (bfd_check_format (abfd, bfd_object))
          ret = TRUE;

        bfd_close (abfd);
        return ret;
      }

      break;
'
