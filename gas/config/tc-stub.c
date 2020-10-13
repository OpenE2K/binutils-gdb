#include "as.h"
#include <stdio.h>

/* All definitions below are needed just to build  GAS.  */

const char comment_chars[] = "!";
const char line_comment_chars[] = "#";
const char line_separator_chars[] = "{};";

const char EXP_CHARS[] = "eE";
const char FLT_CHARS[] = "rRsSfFdDxXpP";

int md_long_jump_size;
int md_short_jump_size;


const char *md_shortopts = "";

struct option md_longopts[] = {
  {"", no_argument, NULL, 0},
};

size_t md_longopts_size = sizeof (md_longopts);

const pseudo_typeS md_pseudo_table[] =
{
  {0, 0, 0}
}; 

void
md_show_usage (FILE *stream ATTRIBUTE_UNUSED)
{
}

int
md_parse_option (int c ATTRIBUTE_UNUSED, char *arg ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_begin ()
{
  as_fatal (_("this is a stub version of GAS incapable of generating code"));
}

void
md_operand (expressionS * expressionP ATTRIBUTE_UNUSED)
{
}


symbolS *
md_undefined_symbol (char *name ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_create_short_jump (ptr, from_addr, to_addr, frag, to_symbol)
     char *ptr ATTRIBUTE_UNUSED;
     addressT from_addr ATTRIBUTE_UNUSED;
     addressT to_addr ATTRIBUTE_UNUSED;
     fragS * frag ATTRIBUTE_UNUSED;
     symbolS * to_symbol ATTRIBUTE_UNUSED;
{
}

void
md_create_long_jump (ptr, from_addr, to_addr, frag, to_symbol)
     char *ptr ATTRIBUTE_UNUSED;
     addressT from_addr ATTRIBUTE_UNUSED;
     addressT to_addr ATTRIBUTE_UNUSED;
     fragS * frag ATTRIBUTE_UNUSED;
     symbolS * to_symbol ATTRIBUTE_UNUSED;
{
}

void
md_assemble (char *str ATTRIBUTE_UNUSED)
{
}

valueT
md_section_align (segT segment ATTRIBUTE_UNUSED, valueT size)
{
  return size;
}

char *
md_atof (type, litP, sizeP)
     char type ATTRIBUTE_UNUSED;
     char *litP ATTRIBUTE_UNUSED;
     int *sizeP ATTRIBUTE_UNUSED;
{
  return 0;
}

void
md_apply_fix (fixS *fixP ATTRIBUTE_UNUSED, valueT *valP ATTRIBUTE_UNUSED,
              segT seg ATTRIBUTE_UNUSED)
{
}

long
md_pcrel_from (fixS *fixP ATTRIBUTE_UNUSED)
{
  return 0;
}

arelent *
tc_gen_reloc (asection *section ATTRIBUTE_UNUSED, fixS *fixp ATTRIBUTE_UNUSED)
{
  return NULL;
}
