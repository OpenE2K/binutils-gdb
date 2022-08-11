/* tc-e2k.c -- Assemble for the E2k
   Free Software Foundation, Inc.
   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with GAS; see the file COPYING.  If not, write
   to the Free Software Foundation, 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include "as.h"
#include "safe-ctype.h"
#include "subsegs.h"
#include "dw2gencfi.h"

#include <limits.h>
#include <stdio.h>

/* Used for the sake of the related option.  */
static int no_strict_delay;

/* Either 32 or 64, selects file format. */
static int e2k_arch_size = 64;

/* Controls LAS-compatible "permissive" mode for the sake of defective E2KT
   tests. When turned on this mode should allow for some incorrectnesses in
   assembler code and replace related error messages with warnings. (see Bugs
   #82825 and #82960).  */
static int permissive_mode;

static int preprocess_mode;
static int preprocess_insn_cntr;

/* If TRUE then the opening brace hasn't been output yet.  */
static int pending_preprocess_brace;

/* TRUE when preprocessync asynchronous instructions which are to be put into
   a separate .fapb section.  */
static int preprocess_async;


typedef struct
{
  /* 11 is the maximal possible number of a literal's placements taking into
     account all possible formats. It equals to the number of non-zero elements
     in the table above.  */
  /* The number of the first 16-bit half-syllable.  */
  int pos[11];

  /*  This size is measured in half-syllable and may be either of 1, 2 or 4.
      It does not hold LITERAL_xx!   */
  size_t size[11];

  /* Число возможных размещений (элементов в массивах pos, size). */
  int plcmnt_nmb;
  /* Индекс оптимального размещения для данного литерала (в том случае, конечно,
     если вообще удалось уместить все литералы). */
  int optimal_plcmnt_idx;

  expressionS exp;

  /* "Back reference" to the index of ALS referring to this LTS if it has
     been explicitly specified by the user or 6 otherwise. Used to simulate
     the stupid behaviour of LAS which places literal syllables according to
     the order of ALSes referring to them.  */
  int als_idx;
} literal_placement;

#include "opcode/e2k.h"

/* A list of internal labels attached to the same location witin a wide
   instruction.  */
struct ilabel_list
{
  struct ilabel_list *prev;
  /* Extended by malloc ().  */
  char name[1];
};


typedef struct e2k_als {
  /* Now that I don't want to introduce specific e2k_alf{1,2,3,...}
     structs GENERIC_ALS seems redundant. I should get rid of it. */
  GENERIC_ALS;

  /* Each ALS can be connected at most with one long literal,
     associated with src2. In fact this field is only required
     for ALF{1,2,3,5,7,8} but now it is convinient to have a
     single pool for free ALSes. */
  literal_placement *src2;

  /* This flag should be set if this ALS needs ALES. */
  int need_ales;
  e2k_ales ales;

  /* I copy these ones from e2k_alopf**_opcode_templ when
     parsing an instruction and use them after all ALSES
     have been placed to their appropriate positions. */
  int need_mas;
  u_int8_t mas;

  /* PRED_NUM[0] should be non-negative if an operation in this ALS
     is under %pred{PRED_NUM}, PRED_NUM[1] should be non-negative
     only for merge operations - it's a merge pred. */
  e2k_pred preds[4];

  expressionS exp;

  const u_int8_t *opc2_arr;

  struct ilabel_list *label;

  int explicit_ales25_v4;
} e2k_als;


/* Массив с достаточным запасом ALS-слогов для формирования
   любой широкой команды. Насколько я понимаю, иметь их
   больше 6 смысла не имеет? */
static e2k_als free_alses[6], *free_als;


#ifdef OBJ_ELF
#include "elf/e2k.h"
#include "dwarf2dbg.h"
#endif





/* FIXME всё затычки - чтобы собирался gas */

const char comment_chars[] = "!";
const char line_comment_chars[] = "#";
const char line_separator_chars[] = "{};";

const char EXP_CHARS[] = "eE";
const char FLT_CHARS[] = "rRsSfFdDxXpP";

/* These machine-dependent (-z, -march) options are set just to
   prevent error messages when we are executed with LAS options.
   I should find out what they really mean. */

/* LAS employs -M for protected mode. At the same time it is
   a standard GAS option (-mri) which doesn't make any sense
   for us. Do I have to add it here? Probably it's just enough
   to handle it properly in md_parse_option. */

const char *md_shortopts = "z";

struct option md_longopts[] = {
#define OPTION_CPU              (OPTION_MD_BASE)
  {"mcpu", required_argument, NULL, OPTION_CPU},

#if ! defined TE_KPDA && ! defined TE_E2K_UCLIBC
#define OPTION_32               (OPTION_MD_BASE + 1)
  {"mptr32", no_argument, NULL, OPTION_32},
#endif /* ! TE_KPDA && ! TE_E2K_UCLIBC  */

  /* Let lcc_q pass us `-mptr64'.  */
#define OPTION_64               (OPTION_MD_BASE + 2)
  {"mptr64", no_argument, NULL, OPTION_64},

#if ! defined TE_KPDA
#define OPTION_128              (OPTION_MD_BASE + 3)
  {"mptr128", no_argument, NULL, OPTION_128},
#endif /* ! TE_KPDA  */

  /* What does lcc pass this option to las for?  */
#define OPTION_SAVE_TEMPS       (OPTION_MD_BASE + 4)
  {"save-temps", no_argument, NULL, OPTION_SAVE_TEMPS},
#define OPTION_OLD_EMACHINE     (OPTION_MD_BASE + 5)
  {"mold-e-machine", no_argument, NULL, OPTION_OLD_EMACHINE},
#define OPTION_MESSAGE_LENGTH   (OPTION_MD_BASE + 6)
  {"fmessage-length", required_argument, NULL, OPTION_MESSAGE_LENGTH},
#define OPTION_NO_STRICT_DELAY  (OPTION_MD_BASE + 7)
  {"no_strict_delay", no_argument, NULL, OPTION_NO_STRICT_DELAY},
#define OPTION_PERMISSIVE       (OPTION_MD_BASE + 8)
  {"permissive", no_argument, NULL, OPTION_PERMISSIVE},
#define OPTION_PREPROCESS       (OPTION_MD_BASE + 9)
  {"preprocess", no_argument, NULL, OPTION_PREPROCESS},
#if ! defined TE_KPDA && ! defined TE_E2K_UCLIBC
#define OPTION_128_64           (OPTION_MD_BASE + 10)
  {"mptr128-64", no_argument, NULL, OPTION_128_64},
#endif /* ! TE_KPDA && ! TE_E2K_UCLIBC  */

  {"", no_argument, NULL, 0},
};

size_t md_longopts_size = sizeof (md_longopts);

static int ignore_ld_st;

static void
s_e2k_ignore (int ignore)
{
  /* FIXME: while I don't understand the meaning of .ignore ld_st_style
     and .ignore strict_delay directives let's ignore the rest of the
     line so that it doesn't confuse md_assemble (). */

  size_t len;
  const char *beg = input_line_pointer;
  ignore_rest_of_line ();
  len = (input_line_pointer - beg) - 1;

  if (len == 11 && strncmp (beg, "ld_st_style", len) == 0)
    {
      if (preprocess_mode)
        printf ("%s ld_st_style\n", ignore ? ".ignore" : ".accept");

      ignore_ld_st = ignore;
    }
  else if (len == 12 && strncmp (beg, "strict_delay", len) == 0)
    {
      if (preprocess_mode)
        printf ("%s strict_delay\n", ignore ? ".ignore" : ".accept");

      no_strict_delay = ignore;
    }
}

static void
s_uacons (int bytes)
{
  /* Well, there exists a backend-specific callback from
     cons () which lets us adjust an alignment. Here I
     should set a "no align"-flag for it. However, this
     callback is not employed yet. */
  cons (bytes);
}

static segT rodata_section;

/* Our E2k compilers output "@progbits" section attribute before(!) its
   rwe-flags and puts it in quotes. The standard ELF method cannot
   process that.  */
   
static void
s_e2k_section (int push)
{
  /* Probably there is a more "standard" way to achieve this goal in
     terms of GAS.  */
  char *replace = strstr (input_line_pointer, ",\"@progbits\"");
  char *next_line = strchr (input_line_pointer, '\n') + 1;
  if (replace && next_line > replace)
    {
      char *tmp = (char *) xmalloc (next_line - input_line_pointer);


      strncpy (tmp, input_line_pointer, replace - input_line_pointer);
      /* Skip this awful `,"@progbits"', it is 12 characters long. Don't
         copy `\n' as well. Thus one obtains `-13'.  */
      strncpy (tmp + (replace - input_line_pointer), replace + 12,
               next_line - replace - 13);
      /* Append `, @progbits\n\0' to the end of line, which is 13 characters
         long. As a result the trailing `\0' goes to
         `tmp[next_line - input_line_pointer - 1]' (see the allocated size
         of TMP above).  */
      strcpy (tmp + (next_line - input_line_pointer - 13), ", @progbits\n");

      input_line_pointer = tmp;
      obj_elf_section (push);
      input_line_pointer = next_line;

      free (tmp);
    }
  else
    obj_elf_section (push);

  if (strcmp (bfd_section_name (now_seg), ".rodata") == 0)
    rodata_section = now_seg; /* record_alignment (now_seg, 4);  */
}

static void
s_e2k_bss (int ignore ATTRIBUTE_UNUSED)
{
  int temp;

  if (IS_ELF)
    obj_elf_section_change_hook ();

  temp = get_absolute_expression ();
  subseg_set (bss_section, (subsegT) temp);
  demand_empty_rest_of_line ();
}

static int last_ilabel_used;
static struct ilabel_list *last_ilabel;
static struct ilabel_list *ss_ilabel, *cs0_ilabel, *cs1_ilabel;
static struct ilabel_list *aa2f1_ilabel[4];

/* FIXME: what's the maximal number of different ilabel locations per wide
   instruction? I used to believe that it was 10 until I met a wide instruction
   containing 11 different ilabels. Hopefully, 20 will be enough for now. To be
   revisited . . .  */
static struct {
  struct ilabel_list *list;
  u_int32_t off;
} ilabels[20];

int ilabels_num;

static void
start_cs1 (void)
{
  if (last_ilabel != NULL)
    {
      cs1_ilabel = last_ilabel;
      last_ilabel_used++;
    }
}


static void
s_e2k_label (int ignore ATTRIBUTE_UNUSED)
{
  char *tmp;
  size_t len;
  struct ilabel_list *next;

  get_symbol_name (&tmp);
  len = strlen (tmp);
  next = (struct ilabel_list *) xmalloc (sizeof (struct ilabel_list) + len);
  next->prev = last_ilabel;
  strncpy (next->name, tmp, len + 1);
  last_ilabel = next;
}

static void
s_e2k_lcomm (int ignore ATTRIBUTE_UNUSED)
{
  /* Unlike the generic ELF method called `obj_elf_lcomm ()' we probably want
     to support the third ALIGNMENT argument of `.lcomm' (see `dis/dis_print.c'
     for how our compiler emits this directive). Therefore, invoke `s_comm_
     internal ()' with non-zero first argument. In particular, the use of `2'
     (i.e. not `1') implies that alignment is expected in bytes, not as a power
     of two. Interestingly enough, this "alignment" is hardcoded into `dis/
     dis_print.c' as 8! So what's the point in having it at all?  */
  symbolS *symbolP = s_comm_internal (2, s_lcomm_internal);

  if (symbolP)
    symbol_get_bfdsym (symbolP)->flags |= BSF_OBJECT;
}

static int parse_generic_register (char **pstr, e2k_generic_register *preg);
static void encode_reg_in_src1 (u_int8_t *src1, e2k_generic_register *preg);

/* Здесь могут кодироваться еще некие нечисловые регистры, так что define'ом
   в общем случае не обойдешься. */
#define encode_reg_in_dst(dst, preg) encode_reg_in_src1 (dst, preg)


static void
s_e2k_reg (int ignore ATTRIBUTE_UNUSED)
{
  e2k_generic_register reg;
  u_int8_t code;
  int i;
  char *save_input_line_pointer;
  char buf[5] = "0x00";

  if (! parse_generic_register (&input_line_pointer, &reg))
    {
      as_bad (_("general-purpose register should be specified as an argument "
		"to .reg directive"));
      return;
    }

  /* Get the register's code suitable for ALS.{SRC{1,2,3},DST} (special
     registers that may be used only for DST canNOT be encoded by .reg),
     ...  */
  encode_reg_in_dst (&code, &reg);

  /* , ... get its string representation and ...  */
  for (i = 0; i < 2; i++)
    {
      u_int8_t digit = code & 0xf;
      buf[3 - i] = digit <= 9 ? '0' + digit : 'a' + digit - 10;
      code >>= 4;
    }

  /* ... pretend that it has been provided by the user via `.byte'. This
     saves one the trouble of copy/pasting the internals of the `.byte'
     handler.  */
  save_input_line_pointer = input_line_pointer;
  input_line_pointer = buf;
  cons (1);
  input_line_pointer = save_input_line_pointer;
}


const pseudo_typeS md_pseudo_table[] =
{
  {"accept", s_e2k_ignore, 0},
  /* By default the argument of `.align' is treated as a power of
     two (see `potable[]' in read.c) which is different from our
     point of view (see Bug #49893, Comments #4, #6).  */
  {"align", s_align_bytes, 0},

  /* FIXME: what attitude to `.ignore' does this directive have?  */
  {"ias_line", s_e2k_ignore, 0},

  {"ignore", s_e2k_ignore, 1},
  /* As far as I understand in LAS (and also in sparc
     GAS) this means unaligned word. By the way, an
     ordinary "word" should be also redefined by the
     e2k backend since by default it is considered to
     be 2 bytes long (see read.c). */
  {"uahalf", s_uacons, 2},
  {"uaword", s_uacons, 4},
  {"uadword", s_uacons, 8},
  {"word", cons, 4},
  {"dword", cons, 8},
  {"ptr", cons, 16},
  {"seg", obj_elf_section, 0},
  {"section", s_e2k_section, 0},
  {"bss", s_e2k_bss, 0},
  {"label", s_e2k_label, 0},
  {"lcomm", s_e2k_lcomm, 0},
  {"reg", s_e2k_reg, 0},
  {0, 0, 0}
};

const char *
e2k_target_format ()
{
#if !defined TE_KPDA
  if (e2k_arch_size == 128)
    return (
# if ! defined TE_E2K_UCLIBC
	    "elf64-e2k-pm"
# else /* defined TE_E2K_UCLIBC  */
	    "elf32-e2k-pm-uclibc"
# endif /* define TE_E2K_UCLIBC  */
	    );

#if ! defined TE_E2K_UCLIBC
  return e2k_arch_size == 64 ? "elf64-e2k" : "elf32-e2k";
#else /* defined TE_E2K_UCLIBC  */
  gas_assert (e2k_arch_size == 64);
  return "elf64-e2k-uclibc";
#endif /* defined TE_E2K_UCLIBC  */

#else /* TE_KPDA  */

  gas_assert (e2k_arch_size == 64);
  return "elf64-e2k-kpda";

#endif /* TE_KPDA  */
  
}

static int forward_incompat;
static unsigned long output_mach;

/* This one is invoked via a TARGET_MACH macro when creating an output
   file.  */
unsigned long
e2k_mach (void)
{
  unsigned long addend;
  /* FIXME: we are going to get a GAS internal error before having a chance to
     use an uninitialized MACH below.  */
  unsigned long mach = 0;

  switch (mcpu)
    {
    case 5:
      mach = bfd_mach_e2k_ev5;
      break;
    case 4:
    case 6:
      {
	/* Currently we distinguish binaries for different processors only for
	   `elbrus-v{4,6}'. Particularly, the output binary may be intended for
	   execution only on `elbrus-8c', `elbrus-1c+' or any `elbrus-v{X>=4}'
	   processor when we are talking about elbrus-v4. With respect to
	   elbrus-v6 the output may be intended for execution only on one of
	   elbrus-{1{2,6}c,2c3} processors of this series or any
	   `elbrus-v{X>=6}'.  */
	mach = output_mach;
	break;
      }
    case 3:
      mach = bfd_mach_e2k_ev3;
      break;
    case 2:
      mach = bfd_mach_e2k_ev2;
      break;
    case 1:
      mach = bfd_mach_e2k_ev1;
      break;
    case 0:
      mach = bfd_mach_e2k_generic;
      break;
    default:
      gas_assert (0);
    }

  /* FIXME: probably a standard macro is required for calculating machine
     number. Currently I have local `MACH_{64,32,pm}' macros in
     `bfd/cpu-e2k.c'.  */

  if (e2k_arch_size == 128)
    addend = 2;
  else
    addend = e2k_arch_size == 64 ? 0 : 1;

  return 4 * mach + addend;
}

void
e2k_elf_final_processing (void)
{
  if (forward_incompat)
    elf_elfheader (stdoutput)->e_flags |= EF_E2K_INCOMPAT;
}



void
md_show_usage (FILE *stream)
{
  fprintf (stream, _("E2K options:\n"));
  fprintf (stream, _("\
-mptr32			create 32 bit object file\n\
-mptr64			create 64 bit object file\n\
-mptr128		create Protected Mode object file\n"));

  fprintf (stream, _("\
-no_strict_delay	don't enforce implicit delay between instructions\n\
-permissive		replace some errors with warnings for compatibility\n\
			with las\n"));
}

int
md_parse_option (int c, const char *arg)
{
  /* Meanwhile I am satisfied with any option, since
     it doesn't affect me. */

  switch (c)
    {
#if ! defined TE_KPDA
# if ! defined TE_E2K_UCLIBC
    case OPTION_32:
    case OPTION_128_64:
# endif /* ! defined TE_E2K_UCLIBC  */
    case OPTION_64:
    case OPTION_128:

      {
	const char **list, **l;

        if (c == OPTION_128)
          e2k_arch_size = 128;
        else
          e2k_arch_size = (
#if ! defined TE_E2K_UCLIBC
			   c == OPTION_32
			   ? 32
			   :
#endif /* ! defined TE_E2K_UCLIBC  */
			   64
			   );
        
	list = bfd_target_list ();
	for (l = list; *l != NULL; l++)
	  {
            if (e2k_arch_size == 32)
	      {
		if (CONST_STRNEQ (*l, "elf32-e2k"))
		  break;
	      }
	    else if (e2k_arch_size == 64)
	      {
		if (CONST_STRNEQ (*l, "elf64-e2k"))
		  break;
	      }
	    else
	      {
		if (CONST_STRNEQ (*l, "elf64-e2k"))
		  break;
	      }
          }
        if (*l == NULL)
          as_fatal (_("No compiled in support for %d bit object file format"),
                    e2k_arch_size);
        free (list);
      }
      break;

#else /* TE_KPDA  */
    case OPTION_64:
      /* Currently there's nothing to do.  */
      break;
#endif /* TE_KPDA  */

    case OPTION_CPU:
      if (strcmp (arg, "elbrus-v2") == 0
               || strcmp (arg, "elbrus-2cm") == 0)
	mcpu = 2;
      else if (strcmp (arg, "elbrus-2c+") == 0)
	{
	  mcpu = 2;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-v3") == 0)
	mcpu = 3;
      else if (strcmp (arg, "elbrus-4c") == 0)
	{
	  mcpu = 3;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-v4") == 0)
	{
	  mcpu = 4;
	  output_mach = bfd_mach_e2k_ev4;
	}
      else if (strcmp (arg, "elbrus-8c") == 0)
	{
	  mcpu = 4;
	  output_mach = bfd_mach_e2k_8c;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-1c+") == 0)
	{
	  mcpu = 4;
	  output_mach = bfd_mach_e2k_1cplus;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-v5") == 0)
	mcpu = 5;
      else if (strcmp (arg, "elbrus-8c2") == 0)
	{
	  mcpu = 5;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-v6") == 0)
	{
	  mcpu = 6;
	  output_mach = bfd_mach_e2k_ev6;
	}
      else if (strcmp (arg, "elbrus-12c") == 0)
	{
	  mcpu = 6;
	  output_mach = bfd_mach_e2k_12c;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-16c") == 0)
	{
	  mcpu = 6;
	  output_mach = bfd_mach_e2k_16c;
	  forward_incompat = 1;
	}
      else if (strcmp (arg, "elbrus-2c3") == 0)
	{
	  mcpu = 6;
	  output_mach = bfd_mach_e2k_2c3;
	  forward_incompat = 1;
	}
      else
        {        
          as_bad (_("invalid -mcpu argument"));
          return 0;
        }

      break;

    case OPTION_MESSAGE_LENGTH:
      break;

    case OPTION_NO_STRICT_DELAY:
      no_strict_delay = 1;
      break;

    case OPTION_PERMISSIVE:
      permissive_mode = 1;
      break;

    case OPTION_PREPROCESS:
      preprocess_mode = 1;
      /* Avoid creating output object file this way . . .  */
      as_bad (_("No output object file is to be created in preprocessing "
                "mode"));
      break;
    }

  return 1;
}

static const char *
cpu_name (void)
{
  static const char *names[] = {"", "",
				"elbrus-v2", "elbrus-v3",
				"elbrus-v4", "elbrus-v5"};

  gas_assert (mcpu >= 2 && mcpu <= 5);
  return names[mcpu];
}

struct hsyll
{
  literal_placement *owner;
  unsigned int sub_idx;
};

struct wc_reloc
{
  int where;
  int size;
  expressionS *exp;
  int pcrel;
  enum bfd_reloc_code_real r_type;
};

typedef struct {
  unsigned setcmd_args[10];
  int setsft_seen;

  u_int32_t hs;

  struct {
    union {
      u_int32_t word;

      struct {
        u_int32_t ctcond : 9;
        u_int32_t x1 : 1;
        u_int32_t ctop : 2;
        u_int32_t aa : 4;
        u_int32_t alct : 1;
        u_int32_t alcf : 1;
        u_int32_t abpt : 1;
        u_int32_t abpf : 1;
        u_int32_t x2 : 1;
        u_int32_t abnt : 1;
        u_int32_t abnf : 1;
        u_int32_t abg : 2;
        u_int32_t crp : 1;
        u_int32_t vfdi : 1;
        u_int32_t srp : 1;
        u_int32_t bap : 1;
        u_int32_t eap : 1;
        u_int32_t ipd : 2;
      } fields;
    } val;

    struct {
      u_int32_t ctcond : 1;
      u_int32_t ctop : 1;
      u_int32_t alct : 1;
      u_int32_t alcf : 1;
      u_int32_t abpt : 1;
      u_int32_t abpf : 1;
      u_int32_t abnt : 1;
      u_int32_t abnf : 1;
      u_int32_t abg : 1;
      u_int32_t crp : 1;
      u_int32_t vfdi : 1;
      u_int32_t srp : 1;
      u_int32_t bap : 1;
      u_int32_t eap : 1;
      u_int32_t ipd : 1;
    } set, dflt;

    u_int8_t started;
  } ss;

  unsigned char busy_al;

  struct {
    u_int32_t val;
    struct ilabel_list *label;
    expressionS *exp;
  } al[ALS_CHANNELS_NUMBER];

  unsigned char busy_ales;
  u_int16_t ales[ALS_CHANNELS_NUMBER];

  struct {
    u_int8_t dst[2];
  } aa0f1[2];

  unsigned char busy_aa2f1;
#if 0
  struct {
    u_int16_t am : 1;
    u_int16_t ind : 5;
    u_int16_t area : 5;
    u_int16_t x : 1;
    u_int16_t opc : 3;
    u_int16_t be : 1;
  };
#endif /* 0   */
  u_int16_t aa2f1[4];
  
  struct {
    union {
      u_int32_t word;
      struct {
        u_int32_t disp:28;
        u_int32_t ctp_opc:2;
        u_int32_t ctpr:2;
      } fields;
    } val;

    u_int8_t set;
    expressionS *pexp;
  } cs0;

  struct {
    union {
      u_int32_t word;
      union {
        struct {
	  u_int32_t rbs : 6;
	  u_int32_t rsz : 6;
	  u_int32_t rcur : 6;
	  u_int32_t psz : 5;
	  u_int32_t x : 2;
	  u_int32_t settr : 1;
	  u_int32_t setbn : 1;
	  u_int32_t setbp : 1;
	  u_int32_t opc : 4;
	} setcmd;

	struct {
	  u_int32_t mas5 : 7;
	  u_int32_t mas3 : 7;
	  u_int32_t mas2 : 7;
	  u_int32_t mas0 : 7;
	  u_int32_t opc : 4;
	} mas;

        struct {
          u_int32_t param : 28;
          u_int32_t opc : 4;
        } call;
      } fields;
    } val;
    u_int8_t set;
  } cs1;

  u_int32_t cs[2];
  unsigned char busy_lts;

  struct hsyll lts[8];

  struct {
    union {
      u_int32_t word;
      struct {
        u_int32_t clp_pdst : 5;
        u_int32_t clp_vdst : 1;
        u_int32_t clp_p1 : 3;
        u_int32_t clp_neg1 : 1;
        u_int32_t clp_p0 : 3;
        u_int32_t clp_neg0 : 1;
        u_int32_t clp_opc : 2;

        u_int32_t elp1 : 7;
        u_int32_t x1 : 1;
        u_int32_t elp0 : 7;
        u_int32_t x2 : 1;
      } fields;
    } val;

    struct {
        u_int32_t clp_pdst : 1;
        u_int32_t clp_vdst : 1;
        u_int32_t clp_p1 : 1;
        u_int32_t clp_neg1 : 1;
        u_int32_t clp_p0 : 1;
        u_int32_t clp_neg0 : 1;
        u_int32_t clp_opc : 1;

        u_int32_t elp1 : 1;
        u_int32_t x1 : 1;
        u_int32_t elp0 : 1;
        u_int32_t x2 : 1;
    } dflt, set;

    /* For pack_wide_command. */
    int needed;
  } pls[3];


  union {
    struct {
      u_int16_t pred : 7;
      u_int16_t neg : 3;
      u_int16_t mask : 4;
      u_int16_t opc : 2;
    } rlp_mrgc;
    u_int16_t val;
  } cds[6];
  u_int8_t nop_nmb;

  int lm;
  int sw;

  unsigned char busy_aps;
  u_int32_t aps[2];
  u_int32_t apls[2];

  /* 10 should certainly be replaced by something meaningful. */
  struct wc_reloc relocs[10];
  int reloc_cntr;

  int explicit_ales25;

  /* Track all explicitly specified ALCes. Note that for a quad instruction
     a pair of ALCes should be considered as explicitly specified.  */
  int explicit_alces;

  /* Track integer comparison instructions with an explicitly specified
     ALC.  */
  int explicit_int_cmp_mask;

  /* Track explicitly encoded ELP and {C/M}LP instructions along with PASSes
     related to MLP. This is required for further consistency checks and to
     verify the validity of `%clpX' control transfer conditions.  */
  int explicit_lp_mask;

  /* The numbers of {C/M}LP incoming local predicates are also used during
     consistency checks. Alternatively they could be extracted from encoded
     PLSx syllables.  */
  int clp_incoming_lp[3][2];
} wide_command;

static wide_command wc;

/* Non-default value always overrides a default one. */
#define SET_FIELD(syl, fld, value, dfl)         \
  if (! wc.syl.set.fld                          \
      || (!dfl && wc.syl.dflt.fld))             \
    {                                           \
      wc.syl.val.fields.fld = value;            \
      wc.syl.set.fld = 1;                       \
      wc.syl.dflt.fld = dfl;                    \
    }                                           \
  else if (!dfl)                                \
    as_bad("explicitly overriding non-default " \
           "value of " #syl "." #fld )



/* If CS0 needs expression then cs0.pexp is set to &cs0_exp. */
expressionS cs0_exp;


static struct hash_control *op_hash;

static int default_ipd;

void
md_begin ()
{
  const char *retval;
  int lose = 0;
  register unsigned int i = 0;

  /* FIXME: this is a temporary assert inserted simultaneously with the
     elimination of `mcpu < 2' case when deciding on default IPD.  */
  gas_assert (mcpu >= 2);

  /* IPD should be set to 3 by default starting from elbrus-v2.  */
  default_ipd = 3;

  /* Set the default alignment for the `.text' `section to (2**3) == 8'. As far
     as I understand, all subsequent `.align' directives setting smaller
     alignment won't have effect, since they also make use of `record_alignment
     ()', which doesn't let to reduce alignment once set for the section.  */
  record_alignment (text_section, 3);

  /* This mimics the behaviour of LAS, though I can't understand what the point
     for these sections to be aligned on a 16-byte boundary by default is.  */
#if 0
  record_alignment (data_section, 4);
  record_alignment (bss_section, 4);
#endif /* 0  */

  op_hash = hash_new ();

  while (i < e2k_num_opcodes)
    {
      struct e2k_opcode_templ *entry;
      const char *name = e2k_opcode_templs[i]->name;
      entry = hash_find (op_hash, name);

      if (entry != NULL && e2k_opcode_templs[i]->merge == NULL)
        as_warn (_("no merge function for `%s'"), name);

      if (entry == NULL
          || e2k_opcode_templs[i]->merge == NULL
          || ((retval = e2k_opcode_templs[i]->merge (entry,
                                                     e2k_opcode_templs[i]))
              != NULL))
        retval = hash_jam (op_hash, name, (PTR) e2k_opcode_templs[i]);

      if (retval != NULL)
	{
	  as_bad (_("Internal error: can't hash `%s': %s\n"),
		  e2k_opcode_templs[i]->name, retval);
	  lose = 1;
	}

      ++i;
    }

  if (lose)
    as_fatal (_("Broken assembler.  No assembly attempted."));
  
}

#define CHECK_MSG(res, ...)                             \
  if (!(res)) {                                         \
    as_bad (__VA_ARGS__);                               \
    break;                                              \
  }

#define CHECK(res)                                      \
  if (!(res))                                           \
    break;


static inline int
slurp_char (char **s, char c)
{
  char *t;

  /* This is a fast path. Do I actually need it?  */
  if (**s == c)
    {
      ++(*s);
      return 1;
    }

  /* Take care of skipping spaces.  */
  for (t = *s; *t == ' ';)
    t++;

  if (*t == c)
    {
      *s = t + 1;
      return 1;
    }

  return 0;
}

static inline int
slurp_str (char **s, const char *str)
{
  char *l;
  const char *r;

  /* Take care of skipping spaces.  */
  for (l = *s; *l == ' ';)
    l++;

  for (r = str; *r != '\0'; l++, r++)
    {
      if (*l != *r)
        break;
    }

  if (*r != '\0')
    return 0;

  *s = l;
  return 1;
}


typedef unsigned long long longest;

static int
parse_number (char **pstr, void *pres, size_t res_sz, int sgnd)
{
  unsigned long long res;
  char *endptr;

  if (sgnd != 2)
    {
      res = (sgnd ? ((unsigned long long) strtoll (*pstr, &endptr, 0))
             : strtoull (*pstr, &endptr, 0));

      /* No digits have been found.  */
      if (endptr == *pstr)
        return 0;
    }
  else
    {
      /* FIXME: the value of `sgnd == 2' is a hack which instructs this function
         to treat a possible numeric expression . . .  */
      expressionS exp;
      char *save = input_line_pointer;

      input_line_pointer = *pstr;
      expression (&exp);
      endptr = input_line_pointer;
      input_line_pointer = save;

      if (exp.X_op != O_constant)
        return 0;

      res = (unsigned long long) exp.X_add_number;
    }

  switch (res_sz)
    {
    case 1:
      *((u_int8_t *) pres) = (u_int8_t) res;
      break;
    case 2:
      *((u_int16_t *) pres) = (u_int16_t) res;
      break;
    case 4:
      *((u_int32_t *) pres) = (u_int32_t) res;
      break;
    case 8:
      *((u_int64_t *) pres) = (u_int64_t) res;
      break;
    }
  

  *pstr = endptr;
  return 1;
}


static int
parse_pred_generic (char **pstr, e2k_pred *ppred, int global, int allow_pcnt)
{
  char *s = *pstr;
  int mask = 0;
  do {
    if (slurp_char (&s, '~'))
      ppred->negated = 1;
    else
      ppred->negated = 0;

    if (global)
      {
        if (slurp_str (&s, "%pred"))
          mask = 0x60;
        else if (allow_pcnt && slurp_str (&s, "%pcnt"))
          mask = 0x40;
        else
          break;
      }
    else if (! slurp_str (&s, "@p"))
      break;

    CHECK (parse_number (&s, &ppred->pred_num, sizeof (ppred->pred_num), 0));

    if (global)
      ppred->pred_fld = mask | ppred->pred_num;

    *pstr = s;
    return 1;
  }
  while (0);

  /* Currently I make use of this value to find out which of `parse_{,s}pred
     ()' has succeeded when parsing the source of ELP.  */
  ppred->pred_num = -1;
  return 0;
}

static int
parse_pred (char **pstr, e2k_pred *ppred, int allow_pcnt)
{
  return parse_pred_generic (pstr, ppred, 1, allow_pcnt);
}

static int
parse_spred (char **pstr, u_int8_t *spred)
{
  u_int8_t idx;
  char *s = *pstr;

  if (slurp_str (&s, "%lcntex"))
    {
      *spred = 0;
      *pstr = s;
      return 1;
    }
  else if (slurp_str (&s, "%spred"))
    {
      idx = 0;
      while (s[0] >= '0' && s[0] <= '5')
	{
	  int shift = *s++ - '0';
	  idx |= 1 << shift;
	}

      if (idx != 0)
	{
	  *spred = idx;
	  *pstr = s;
	  return 1;
	}
    }
  else if (mcpu >= 3
	   && slurp_str (&s, "%rndpred")
	   && parse_number (&s, &idx, sizeof (idx), 0)
	   && idx >= 1
	   && idx <= 15)
    {
      *spred = 0x40 | idx;
      *pstr = s;
      return 1;
    }

  return 0;
}


static int
parse_local_pred (char **pstr, e2k_pred *ppred)
{
  int res = parse_pred_generic (pstr, ppred, 0, 0);

  if (res && (ppred->pred_num < 0 || ppred->pred_num > 6))
    {
      as_bad (_("invalid local predicate `@p%d'"), ppred->pred_num);
      res = 0;
    }

  return res;
}

static int
parse_als_pred_optional (char **pstr)
{
  char *s = *pstr;
  slurp_char (&s, ' ');

  if (slurp_char (&s, '?'))
    {
      int i;
      for (i = 0; i < 2; i++)
        {
          int idx;
          e2k_pred pred;
          if (i == 1 && !slurp_char (&s, ','))
            break;

          /* What about other types of conditions which apply to
             ALS not just plain predicates? */
          if (! parse_pred (&s, &pred, 1))
            {
              as_bad (_("invalid predicate `%s'"), s);
              return 0;
            }

          idx = ((pred.pred_fld >> 5) == 0x3) ? 0 : 2;
          if (free_als->preds[idx].pred_num != -1)
            {
              as_bad (_("two %%%s predicates acting on the same ALS are not "
                        "allowed"), idx == 0 ? _("pred") : _("pcnt"));
              return 0;
            }

          free_als->preds[idx] = pred;
        }

      *pstr = s;
    }

  return 1;
}

static int
parse_generic_register (char **pstr, e2k_generic_register *preg)
{
  char *s = *pstr;

  if (!slurp_char (&s, '%'))
    return 0;

  if (slurp_char (&s, 'd') || slurp_char (&s, 'x'))
    preg->fmt = DOUBLE;
  /* FIXME: stupidly interpret `%qp' registers as having SINGLE format, because
     I've not implemented the related format for them yet. At the same time
     there are stupid E2KT tests (see src_76569/gen.h) which specify `%qp'
     registers at unsuitable positions. For example,

     qpfstoid %g24, %qpr24
     qpfstofd %g24, %qpg27

     Hopefully, this hack is going to help me pass them without an error.  */
  else if (slurp_str (&s, "qp"))
    preg->fmt = SINGLE; /* QPACKED  */
  /* FIXME: temporarely interpret `%qr'-registers as SINGLE until Bug #79092 is
     fixed.  */
  else if (slurp_char (&s, 'q'))
    preg->fmt = SINGLE; /* QUAD;  */
  else
    preg->fmt = SINGLE;

  if (slurp_str (&s, "b[") || slurp_str (&s, "r["))
    preg->type = BASED;
  else if (slurp_char (&s, 'g'))
    preg->type = GLOBAL;
    else if (slurp_char (&s, 'r'))
      preg->type = WINDOW;
    else if (slurp_str (&s, "aasti"))
      preg->type = AASTI;
    else
      return 0;

  if (!parse_number (&s, &preg->idx, sizeof (preg->idx), 0))
    return 0;

  if (preg->type == BASED
      && ! slurp_char (&s, ']'))
    {
      as_bad ("`]' expected");
      return 0;
    }

  if ((preg->type == BASED && preg->idx >= 128)
      || (preg->type == WINDOW && preg->idx >= 64)
      || (preg->type == GLOBAL && preg->idx >= 32)
      || (preg->type == AASTI && preg->idx >= 16))
    {
      /* FIXME: specify the type of register somehow.  */
      as_bad (_("Illegal register index"));
      return 0;
    }

  *pstr = s;
  return 1;
}

typedef struct
{
  const char *id;
  e2k_literal_format fmt;
  
} literal_format_specifier;

static const literal_format_specifier literal_format_specifiers[] = {
  {"_f16s", {LITERAL_16, 1}},
  {"_f16", {LITERAL_16, 0}},
  {"_f32s",{LITERAL_32, 1}},
  {"_f32", {LITERAL_32, 0}},
  {"_f64", {LITERAL_64, 0}},
  /*  {"_f128_hi", },
      {"_f128_lo", },
      {"_f128", }*/

  /* A rather naive attempt to support literal references. Just
     treat them as regular literals with (hopefully) specified
     format and placement. In the end they'll be placed exactly
     to the same places as the prototypes they refer to. But
     in case a  user specifies a wrong value for the reference
     we are going to get a conflict. I believe no value should
     be specified for references, otherwise their concept is
     bogus. */

  /* What should happen if the prototype does not exist? */

  /* `sgnd' seems to be meaningless for these ones
     because their values should not be parsed. */  
};

typedef struct
{
  int min_col;
  int max_col;
} placement_range;

typedef struct
{
  const char *id;
  placement_range rng;
} literal_placement_specifier;



literal_placement_specifier  literal_placement_specifiers[] = {
  {"_lts0lo", {0, 0}},
  {"_lts0hi", {1, 1}},
  {"_lts0", {0, 1}},
  {"_lts1lo", {2, 2}},
  {"_lts1hi", {3, 3}},
  {"_lts1", {2, 3}},
  {"_lts2", {4, 4}},
  {"_lts3", {6, 6}}
};

static const int dummy_table[3][8] =
{
  /* literal size  _lts0lo _lts0hi _lts1lo _lts1hi _lts2lo _lts2hi _lts3lo _lts3hi */
  /* LITERAL_16 */ {  1,      1,      1,      1,      0,      0,      0,      0    },
  /* LITERAL_32 */ {  1,      0,      1,      0,      1,      0,      1,      0    },
  /* LITERAL_64 */ {  1,      0,      1,      0,      1,      0,      0,      0    }
};

/* There may be at most 6 ALS* commands (including GETSP and {LD,ST}AA*) and 1
   SETWD referencing LTSx syllables. GAS parser shouldn't allow to encode more
   than (6 + 1) commands of this kind which could potentially overflow this
   array.  */
#define MAX_LITERAL_NMB (6 + 1)
static literal_placement allowed_placements[MAX_LITERAL_NMB];


static int inside_wide_command = 0;

/* Текущие порядковые номера для ресурсов, сохраняемых до фазы формирования
   широкой команды. Пока это размещения (длинных) литералов и слоги ALF1. */

static int crnt_lit;

static void encode_long_lit_in_src2 (u_int8_t *, literal_placement *);

/* Extra expression types.  */
#define O_gotoff        O_md1
#define O_got           O_md2
#define O_tls_le        O_md3
#define O_tls_ie        O_md4
#define O_tls_gdmod     O_md5
#define O_tls_gdrel     O_md6
#define O_plt           O_md7
#define O_gotplt        O_md8
/* This one is required to issue debug info for __thread-variables (see
   Bug #47210).  */
#define O_tls_dtprel    O_md9
/* This is needed for `R_E2K_{32_PC,64_PC_LIT}' which are used to obtain
   _GLOBAL_OFFSET_TABLE_ address in PIC code. Are these relocations used
   for any other symbols?  */
#define O_pc            O_md10
#define O_islocal       O_md11
#define O_size          O_md12
#define O_ap_got        O_md14
#define O_pl_got        O_md15
#define O_pref          O_md16
#define O_islocal32     O_md17
#define O_ap            O_md18
#define O_pl            O_md19
#define O_dynopt	O_md20


static int
get_literal_explicit_fmt (char **pstr, const e2k_literal_format **ppfmt,
                          const char **pfmt_id)
{
  unsigned int i;
  unsigned int fmt_spec_nmb = (sizeof (literal_format_specifiers)
                               / sizeof (literal_format_specifiers[0]));

  for (i = 0; i < fmt_spec_nmb; i++)
    {
      if (slurp_str (pstr, literal_format_specifiers[i].id))
        {
          *ppfmt = &literal_format_specifiers[i].fmt;
          *pfmt_id = literal_format_specifiers[i].id;
          return 1;
        }
    }

  return 0;
}

static int
get_literal_explicit_plcmnt (char **pstr, const placement_range **pprng)
{
  unsigned int i;
  for (i = 0; i < (sizeof (literal_placement_specifiers)
                   / sizeof (literal_placement_specifiers[0])); i++)
    {
      if (slurp_str (pstr, literal_placement_specifiers[i].id))
        {
          *pprng = &literal_placement_specifiers[i].rng;
          return 1;
        }
    }

  return 0;
}

static int
parse_literal (char **pstr, e2k_literal_size max_short_lit_size,
               literal_placement **pplcmnt, u_int8_t *pval,
               expressionS *ret_exp, e2k_register_format lit_fmt)
{
  unsigned int i, j;
  char *val_start;

  unsigned int min_col, max_col;
  unsigned int min_row = 0, max_row = 0;
  const e2k_literal_format *pfmt = NULL;
  const char *fmt_id = NULL;
  const placement_range *prng = NULL;
  int fmt_obtained, plcmnt_obtained;

  literal_placement *plcmnt;

  /* Минимальный размер литерала, пригодный для размещения val. */
  e2k_literal_size min_size;

  expressionS exp;

  slurp_char (pstr, '[');

  {
    /* References seem to be vaild for src2 only. So, probably, I should
       move this code from here somewhere somehow. */

    static const char *lit_refs[] = {"_lit16_ref", "_lit32_ref", "_lit64_ref"};
    for (i = 0; i < 3; i++)
      if (slurp_str (pstr, lit_refs[i]))
        {
          slurp_char (pstr, ',');

          for (j = 0; j < sizeof (literal_placement_specifiers) / sizeof (literal_placement_specifiers[0]); j++)
            {
              if (slurp_str (pstr, literal_placement_specifiers[j].id))
                break;
            }

          if (j == sizeof (literal_placement_specifiers) / sizeof (literal_placement_specifiers[0]))
            {
              as_bad (_("unambiguous literal position expected for reference, found none"));
              return 0;
            }

          min_col = literal_placement_specifiers[j].rng.min_col;
          max_col = literal_placement_specifiers[j].rng.max_col;

          if ((min_col == max_col && dummy_table[i][min_col])
              || (dummy_table[i][min_col] && !dummy_table[i][max_col]))
            {
              size_t lit_size = ((i == LITERAL_16) ? 1 : ((i == LITERAL_32) ? 2 : 4));
              for (j = 0; j < (unsigned) crnt_lit; j++)
                {
                  if (allowed_placements[j].plcmnt_nmb == 1
                      && allowed_placements[j].pos[0] == (int) min_col
                      && allowed_placements[j].size[0] == lit_size)
                    {
                      *pplcmnt = &allowed_placements[j];
                      break;
                    }
                }
              gas_assert (*pplcmnt != NULL);
            }
          else
            {
              as_bad (_("ambiguous or invalid literal position for literal reference"));
              return 0;
            }

          /* Blindly skip any expression following `_litXX_ref, _ltsY{hi,lo,}' even
             if it's invalid. */

          /* TODO: verify that the target literal with an explicitly specified position
             will have been added by the end of wide instruction parsing. */
          while ((*pstr)[0] != ',')
            (*pstr)++;
         
          return 1;
        }
  }

  fmt_obtained = get_literal_explicit_fmt (pstr, &pfmt, &fmt_id);
  if (fmt_obtained)
    slurp_char (pstr, ',');

  plcmnt_obtained = get_literal_explicit_plcmnt (pstr, &prng);
  if (plcmnt_obtained && !fmt_obtained)
    {
      slurp_char (pstr, ',');
      /* This is the second and the last chance to find the explicitly specified
         format of the literal.  */
      get_literal_explicit_fmt (pstr, &pfmt, &fmt_id);
    }


  val_start = *pstr;
  {
    char *str = *pstr, *save_input_line_pointer;
    char *copy_str = (char *) xmalloc (strlen (str) + 1);
    unsigned idx = 0;

    while (str[0] != ',')
      {
	if (str[0] != ']')
	  copy_str[idx++] = str[0];
	str++;
      }
    copy_str[idx] = '\0';

    save_input_line_pointer = input_line_pointer;
    input_line_pointer = copy_str;
    expression (&exp);

    if (input_line_pointer[0] != '\0')
      /* FIXME: not quite perfect as it displays only a substring limited
	 by COPY_STR[] of the remaining to parse string.  */
      as_bad (_("junk at `%s'"), input_line_pointer);

    input_line_pointer = save_input_line_pointer;

    *pstr = str;
    free (copy_str);
  }

  /* This is a common action for both numeric values
     and symbols. */

  if (prng)
    {
      min_col = prng->min_col;
      max_col = prng->max_col;
    }
  else
    {
      min_col = 0;
      max_col = 7;
    }

  /* Currently it's required only when parsing short literals because of the
     potential need to output ISLOCAL relocation.  */
  if (ret_exp)
    *ret_exp = exp;

  if (exp.X_op == O_constant)
    {
      /* Считываемое значение. */
      int64_t sval;
      u_int64_t val;

      sval = exp.X_add_number;
      val = (u_int64_t) sval;

      /* Keep in mind that 4 and 5 bit literals unlike 16 and 32 bit ones are
         extended by zeroes rather than by sign. As far as I understand, this
         means that they can encode positive values only.  */

      if (pfmt)
        {
          /* FIXME: verify that the provided value fits the corresponding range.
             Note that negative 16 and 32-bit literals can be output by our
             compilers both as 32 and 64-bit values depending on the format of
             the respective instruction.  */
          if (pfmt->size == LITERAL_4)
            {
              exp.X_add_number = val = (val & 0xf);
            }
          else if (pfmt->size == LITERAL_5)
            {
              exp.X_add_number = val = (val & 0x1f);
            }
          else if (pfmt->size == LITERAL_16)
            {
              exp.X_add_number = val = (u_int16_t) val;
            }
          else if (pfmt->size == LITERAL_32)
            {
              exp.X_add_number = val = (u_int32_t) val;
            }

            min_size = pfmt->size;
        }
      else
        {
          if (sval >= 0 && sval <= 15)
            min_size = LITERAL_4;
          else if (sval >=0 && sval <= 31)
            min_size = LITERAL_5;
          else if (sval >= SHRT_MIN && sval <= SHRT_MAX)
            min_size = LITERAL_16;
          else if ((sval >= INT_MIN && sval <= INT_MAX)
                   || lit_fmt == SINGLE)
            min_size = LITERAL_32;
          else
            min_size = LITERAL_64;
        }

      /* Currently this check won't catch anything . . .  */
      if (pfmt && pfmt->size < min_size)
	{
	  char c = (*pstr)[0];
	  (*pstr)[0] = 0;
	  as_bad ("`%s' does not fit `%s'", fmt_id, val_start);
	  (*pstr)[0] = c;

	  return 0;
	}

  /* If neither the format nor the literal binding is explicitly
     specified and it can be accomodated within a short literal
     there is no point in taking care of its placement. Find out
     whether some of these things (format or binding) can be
     explicitly specified for short literals using our traditional
     (LAS) syntax. */

      if (pfmt == NULL && prng == NULL && (min_size <= max_short_lit_size))
	{
	  if (pplcmnt)
	    *pplcmnt = NULL;
	  *pval = (u_int8_t) val;
          /* A rather bogus solution. `2' means encode as a short
             literal. */
	  return 2;
	}
      else if (pplcmnt == NULL)
	{
	  /* Long literals don't suit our caller (as far as I remember
	     that can take place for some E2K instructions), while a
	     short one (see the first `if') is not large enough to store
	     the obtained value. */
	  return 0;
	}

      /* We are going to initialize a next structure from
	 allowed_placements[] array for this literal. */

      if (pfmt)
	max_row = min_row = pfmt->size;
      else
	{
	  min_row = min_size;
	  max_row = LITERAL_64;
	}
    }
  else if (exp.X_op == O_islocal)
    {
      /* This relocation should be applied to a short literal only. Make this
         literal look as zero in the relocatable output file.  */
      *pval = 0;
      return 2;
    }       
  else if (exp.X_op == O_symbol
           || exp.X_op == O_gotoff
           || exp.X_op == O_got
           || exp.X_op == O_gotplt
           || exp.X_op == O_tls_le
           || exp.X_op == O_tls_ie
           || exp.X_op == O_tls_gdmod
           || exp.X_op == O_tls_gdrel
           || exp.X_op == O_tls_dtprel
           || exp.X_op == O_pc
           || exp.X_op == O_size
           || exp.X_op == O_ap_got
           || exp.X_op == O_pl_got
           || exp.X_op == O_islocal32)
    {
      e2k_literal_size symbol_size;

      if (exp.X_op == O_got
          || exp.X_op == O_gotplt
          || exp.X_op == O_tls_ie
          || exp.X_op == O_tls_gdmod
          || exp.X_op == O_tls_gdrel
          || exp.X_op == O_size
          || exp.X_op == O_islocal32)
        symbol_size = LITERAL_32;
      else
	{
	  if (exp.X_op == O_gotoff && e2k_arch_size == 128)
	    as_bad (_("`@GOTOFF' is not supported in protected mode"));

	  symbol_size = ((e2k_arch_size == 32 || e2k_arch_size == 128 )
			 ? LITERAL_32
			 : LITERAL_64);
	}

      if (pfmt && pfmt->size != symbol_size)
	{
	  as_bad (_("`%s' is not suitable for storing symbol "
		    "value"), fmt_id);
	  return 0;
	}
      min_row = max_row = symbol_size;
    }

  if (pplcmnt == NULL)
    return 0;

  plcmnt = *pplcmnt = &allowed_placements[crnt_lit];
  plcmnt->plcmnt_nmb = 0;
  plcmnt->exp = exp;

  /* Индекс, соответствующий размеру литерала, изменяется во внешнем цикле. Это
     гарантирует, что массив allowed_placements[].size будет возрастающим. */
  for (i = ((int) min_row >= 0 ? min_row : 0); i <=  max_row; i++)
    {
      for (j = min_col; j <= max_col; j++)
        {
          static unsigned int conv[8] = {1, 0, 3, 2, 4, 5, 6, 7};
          /* Avoid conversion if a 16-bit literal has been specified
             unambiguously, say as `_f16s,_lts0lo'. Otherwise you'll get
             `_f16s,_lts0hi' instead. In other cases when there's some
             uncertainty (e.g. `_f16s,_lts0' or no location at all) the
             conversion will do the right thing, i.e. let one prefer the `hi'
             part for a 16-bit literal.  */
          unsigned int k = (i == 0 && min_col != max_col) ? conv[j] : j;

          if (dummy_table[i][k])
            {
              plcmnt->size[plcmnt->plcmnt_nmb] = ((i == LITERAL_16) ? 1 : ((i == LITERAL_32) ? 2 : 4));
              plcmnt->pos[(plcmnt->plcmnt_nmb)++] = k;
            }
        }
    }

  plcmnt->optimal_plcmnt_idx = -1;
  crnt_lit++;
  return 1;
}

/* В этих функциях я (наивно?) полагаюсь на то, что никто не вылезет за пределы
   отведенных ему полей и не провожу дополнительную очистку. Все поле val будет
   чиститься целиком после выделения. Конечно, дополнительные проверки будут совсем
   не лишними. */
static void
encode_reg_in_src1 (u_int8_t *src1, e2k_generic_register *preg)
{
  /* Никто сюда случайно не нагадил? */
  gas_assert (*src1 == 0);

  if (preg->type == BASED)
    {
      gas_assert ((preg->idx & 0x80) == 0);
      *src1 |= preg->idx;
    }
  else if (preg->type == WINDOW)
    {
      gas_assert ((preg->idx & 0xc0) == 0);
      *src1 |= (0x80 | preg->idx);
    }
  else if (preg->type == GLOBAL)
    {
      gas_assert ((preg->idx & 0xe0) == 0);
      *src1 |= (0xe0 | preg->idx);
    }
}

static void
encode_reg (int arg_idx, e2k_register_format fmt,
            u_int8_t reg)
{
  unsigned int i;

  /* See special registers' encodings in parse_special_register () and 6.3.2
     of iset-vX.single.  */
  if ((reg >= 192 && reg <= 223)
      && (arg_idx >= 1 && arg_idx <= 3))
    as_bad (_("special register not allowed in position of SRC%d"), arg_idx);

  for (i = 0; i < free_als->real_als_nmb; i++)
    {
      u_int8_t *p;
      u_int8_t val = reg;

      if (free_als->real_als_nmb == 2
          && fmt == QUAD
          && (arg_idx != 1
              || ! free_als->same_src1_quad))
        /* FIXME: `& 0xfe' will hopefully let me treat special quad registers
           properly (e.g., `%empty' destination), on the other hand it "fixes"
           illegal arguments of instructions like `movtq %qr33, . . .' to
           `movtq %qr32, . . .'. A strict control should be implemented in the
           latter case instead.  */
        val = (val & 0xfe) + i;

      if (arg_idx == 1)
        p = &free_als->u[i].alf1.src1;
      else if (arg_idx == 2)
        p = &free_als->u[i].alf1.src2;
      else if (arg_idx == 3)
        p = &free_als->u[i].alf3.src3;
      else if (arg_idx == 4)
        p = &free_als->u[i].alf1.dst;
      else
        gas_assert (0);

      *p = val;
    }
}

static void
encode_short_lit_in_src1 (u_int8_t short_lit_val)
{
  unsigned i;

  /* The value should fit into 5 bits. */
  gas_assert ((short_lit_val & 0xe0) == 0);

  for (i = 0; i < free_als->real_als_nmb; i++)
    {
      gas_assert (free_als->u[i].alf1.src1 == 0);
      free_als->u[i].alf1.src1 = (0xc0 | short_lit_val);
    }
}

#define encode_reg_in_src2(src2, preg) encode_reg_in_src1 (src2, preg)
#define encode_reg_in_src3(src3, preg) encode_reg_in_src1 (src3, preg)

static void
encode_short_lit_in_src2 (u_int8_t short_lit_val)
{
  unsigned i;

  /* The value should fit into 4 bits. */
  gas_assert ((short_lit_val & 0xf0) == 0);

  for (i = 0; i < free_als->real_als_nmb; i++)
    {
      gas_assert (free_als->u[i].alf1.src2 == 0);
      free_als->u[i].alf1.src2 = (0xc0 | short_lit_val);
    }
}

static void
encode_lit_ref_in_src2 (int f, int p)
{
  unsigned i;
  u_int8_t v;

  gas_assert (f == LITERAL_16 || f == LITERAL_32 || f == LITERAL_64);

  if (f == LITERAL_16)
    {
      gas_assert (p >= 0 && p <= 3);
      v = (((p & 2) != 0) ? 1 : 0) | (((p & 1) != 0) ? 4 : 0) | 208;
    }
 else if (f == LITERAL_32)
   {
     gas_assert (p == 0 || p == 2 || p == 4 || p == 6);
     v = (p >> 1) | 216;
   }
 else
   {
     gas_assert (p == 0 || p == 2 || p == 4);
     v = (p >> 1) | 220;
   }

  for (i = 0; i < free_als->real_als_nmb; i++)
    {
      gas_assert (free_als->u[i].alf1.src2 == 0);
      free_als->u[i].alf1.src2 = v;
    }
}


#if 0
static int
slurp_src1 (char **pstr, e2k_register_format fmt)
{
  e2k_generic_register reg;
  u_int8_t short_lit_val;
  expressionS exp;
  char *s = *pstr;

  slurp_char (&s, ' ');

  if (parse_generic_register (&s, &reg)
      || parse_literal (&s, LITERAL_5, NULL, &short_lit_val, &exp, fmt) == 2)
    return 1;

  return 0;
}
#endif /* 0  */

static int
parse_src1 (char **pstr, e2k_register_format fmt)
{
  char *s = *pstr;
  e2k_generic_register reg;
  u_int8_t short_lit_val;
  int ret;
  expressionS exp;

  /* In cases when CHN is not explicitly specified SRC1 turns out
     not to be preceeded with space. */

  slurp_char (&s, ' ');

  if (parse_generic_register (&s, &reg))
    {
      /* LIBMCST sources contain such lines as `cmpesb %dr0, 0, %pred0'
         which are generated from macros. Such checks have become almost
         useless. */
      if (reg.fmt != fmt
	  && reg.fmt != SINGLE
	  && reg.fmt != DOUBLE
          && reg.fmt != QUAD
	  && reg.fmt != QPACKED)
        {
          as_bad ("register of invalid format in first operand (src1)");
          return 0;
        }
      encode_reg_in_src1 (&free_als->u[0].alf1.src1, &reg);
      if (free_als->real_als_nmb == 2)
        {
          e2k_generic_register fake_reg;
          fake_reg = reg;
          /* Should we have assert for this condition?
             Note that for LDAPQ and STAPQ (and a number of "object-oriented"
             PM-specific load and stores which aren't currently(?) supported)
             the same regno should be encoded in src1!  */
          if (fmt == QUAD && ! free_als->same_src1_quad)
            fake_reg.idx++;
          encode_reg_in_src1 (&free_als->u[1].alf1.src1, &fake_reg);
        }
    }
  else if ((ret = parse_literal (&s, LITERAL_5, NULL, &short_lit_val, &exp,
                                 fmt)) != 0)
    {
      /* Здесь может быть только короткий литерал. Поэтому в parse_literal
         и не передается указатель на literal_placement. */
      gas_assert (ret == 2);
      encode_short_lit_in_src1 (short_lit_val);
      free_als->exp = exp;
      
    }
  else
    {
      as_bad (_("invalid first argument (src1)"));
      return 0;
    }

  *pstr = s;
  return 1;
}


static char *
enclosing_bracket (char *s, int replace_plus, char **plus);

/* FIXME: is INTO_ALES absolutely necessary here? Where can we extract info
   on current instruction encoding from?  */
static int
parse_src3 (char **pstr, e2k_register_format fmt, int into_ales,
            int comma_expected)
{
  char *s = *pstr;
  e2k_generic_register reg;
  char *enclosing = NULL;

  /* Like parse_src1. I hope that src2 is always preceeded by `,'. */
  if (comma_expected && ! slurp_char (&s, ','))
    {
      as_bad (_("comma followed by src3 expected at `%s'"), s);
      return 0;
    }

  slurp_char (&s, ' ');

  if (slurp_char (&s, '['))
    {
      enclosing = enclosing_bracket (s, 0, NULL);
      if (enclosing == NULL)
        {
          as_bad (_("can't find enclosing bracket at `%s'"), s - 1);
          return 0;
        }
    }

  if (parse_generic_register (&s, &reg))
    {
      if (reg.fmt != fmt && reg.fmt != SINGLE && reg.fmt != DOUBLE)
        {
          as_bad (_("register of invalid format at position of src3"));
          return 0;
        }

      encode_reg_in_src3 (into_ales
                          ? &free_als->ales.alef1.src3
                          : &free_als->u[0].alf3.src3,
                          &reg);

      if (free_als->real_als_nmb == 2)
        {
          e2k_generic_register fake_reg;
          fake_reg = reg;
          /* Should we have assert for this condition? */
          if (fmt == QUAD)
            fake_reg.idx++;
          encode_reg_in_src3 (&free_als->u[1].alf3.src3, &fake_reg);
        }
    }
  else
    {
      as_bad (_("invalid src3 at `%s'"), s);
      return 0;
    }

  if (enclosing)
    {
      gas_assert (s == enclosing);
      if (! slurp_char (&s, ','))
        gas_assert (0);

      *enclosing = ']';
    }

  *pstr = s;
  return 1;
}

static u_int8_t
parse_special_register (char **pstr)
{
  /* See 6.3.2 3). */

  /* Certainly this function needs to be re-written like almost everything
     else.  */

  int i;

  static struct {
    const char *reg_name;
    u_int8_t dst_code;
  } specials[] =
      {
        {"%tst", 0xcd},
        /* Note that the order of `%tcd' and `%tc' is currently crucial for my
           "profound" parser.  */
        {"%tcd", 0xcf}, {"%tc", 0xce},
        {"%ctpr1", 0xd1}, {"%ctpr2", 0xd2}, {"%ctpr3", 0xd3}, {"%empty", 0xdf},
        {NULL, 0x0}
      };

  for (i = 0; specials[i].reg_name; i++)
    {
      if (slurp_str (pstr, specials[i].reg_name))
        return specials[i].dst_code;
    }

  return 0;
}

static int
parse_special_register_for_dst (char **pstr, u_int8_t *pdst)
{
  u_int8_t code = parse_special_register (pstr);

  /* Is this OK to use this condition as a sign of failure?  */
  if (code == 0)
    return 0;

  *pdst = code;
  return 1;
}

static int
parse_dst (char **pstr, e2k_register_format fmt)
{
  char *s = *pstr;
  e2k_generic_register reg;

  /* Like similar conditions in parse_src{1,2} - I hope that dst is
     always preceeded by `,' to avoid code duplication. */
  if (! slurp_char (&s, ','))
    {
      as_bad (_("comma followed by dst expected at `%s'"), s);
      return 0;
    }

  if (parse_generic_register (&s, &reg))
    {
      if (reg.fmt != fmt && reg.fmt != SINGLE && reg.fmt != DOUBLE)
        {
          as_bad ("register of invalid format in third operand (dst)");
          return 0;
        }

      /* DST occupies the same bits for each ALF where it is apropriate.
         Let us use ALF1 to access them. */
      encode_reg_in_dst (&free_als->u[0].alf1.dst, &reg);
      if (free_als->real_als_nmb == 2)
        {
          e2k_generic_register fake_reg;
          fake_reg = reg;
          /* Should we have assert for this condition? */
          if (fmt == QUAD)
            fake_reg.idx++;
          encode_reg_in_dst (&free_als->u[1].alf1.dst, &fake_reg);
        }
    }
  else
    {
      unsigned i;
      u_int8_t special_dst;
      if (! parse_special_register_for_dst (&s, &special_dst))
        {
          as_bad (_("invalid third argument (dst) at `%s'"), s);
          return 0;
        }

      /* FIXME: take `%empty' DST which should be encoded as a pair of
         `%empy.{lo,hi}' destinations into account in such a stupid way.  */
      if (free_als->real_als_nmb == 2)
        special_dst &= 0xfe;

      for (i = 0; i < free_als->real_als_nmb; i++)
        free_als->u[i].alf1.dst = special_dst | i;
    }

  *pstr = s;
  return 1;
}

static int
finish_alf123578 (e2k_als *pals);

/* FIXME: this variable is currently needed in parse_cpl_args () and parse_alf
   _args () to determine if we are inside an explicitly specified wide command
   or not.  */
static int brace_cntr = 0;



struct cu_reg
{
  int min_cpu;
  int max_cpu;
  const char *name;
  u_int8_t reg_num;
  int rw_wait;
  int rr_nop;
};


static struct hash_control *
init_state_register_hash (void)
{
  size_t i;
  struct hash_control *res;

  static struct cu_reg reg_tbl [] = {
#define ALT_ENTRY ENTRY
#define ENTRY(a,b,c,d,e) {a, 6, b, c, d, e},
#define STALE_ENTRY(a,b,c,d,e,f) {a, b, c, d, e, f},
#include "opcode/e2k/state-regs.def.new"
#undef STALE_ENTRY
#undef ENTRY
#undef ALT_ENTRY
  };

  res = hash_new ();
  for (i = 0; i < sizeof (reg_tbl) / sizeof (reg_tbl[0]); i++)
    {
      if (hash_insert (res, reg_tbl[i].name, (void *) &reg_tbl[i]))
	as_fatal (_("hash_insert () failed"));
    }

  return res;
}

static void *
reg_hash_entry (struct hash_control *hash, const char *flavour, char **s)
{
  void *entry;
  char c;
  char *l, *m;

  /* Take care of skipping spaces to be on the safe side.  */
  for (l = *s; *l == ' ';)
    l++;

  if (*l != '%')
    {
      as_bad (_("%s register expected at `%s'"), flavour, *s);
      return NULL;
    }

  m = l + 1;
  if (*m < 'a' || *m > 'z')
    {
      as_bad (_("invalid register name at `%s'"), *s);
      return NULL;
    }

  for (;; m++)
    {
      c = *m;
      if ((c < 'a' || c > 'z')
	  && (c < '0' || c > '9')
	  && c != '.'
	  && c != '_')
	break;
    }

  *m = '\0';
  entry = hash_find (hash, l);
  /* Restore the original character.  */
  *m = c;

  if (entry)
    *s = m;
  else
    as_bad (_("invalid %s register at `%s'"), flavour, *s);

  return entry;
}

static int
parse_state_register (char **str, u_int8_t als_fmt)
{
  struct cu_reg *reg;
  static struct hash_control *hash;
  char *s = *str;

  gas_assert ((als_fmt == 5) || (als_fmt == 6));

  if (hash == NULL)
    hash = init_state_register_hash ();

  reg = reg_hash_entry (hash, "CU", &s);
  if (reg == NULL)
    return 0;

  if ((mcpu != 0 || reg->min_cpu != 1 || reg->max_cpu != 6)
      && (mcpu < reg->min_cpu || mcpu > reg->max_cpu))
    {
      /* This is a temporary assert inserted simultaneously with the
	 removal of the below user error message in "generic" case.  */
      gas_assert (mcpu >= 2);
      as_bad (_("CU register `%s' is not available on elbrus-v%d"),
	      reg->name, mcpu);

      return 0;
    }

  if (als_fmt == 5)
    free_als->u[0].alf5.regn = reg->reg_num;
  else
    free_als->u[0].alf6.regn = reg->reg_num;

  if (brace_cntr == 0 && !no_strict_delay)
    {
      if (als_fmt == 5 && reg->rw_wait)
	{
	  start_cs1 ();
	  /* Stupidly encode `wait all_e = 1' for a subset of state
	     registers in uncompound command by analogy with `parse_
	     wait_args ()'. CS1 should definitely be empty of course
	     provided that the command is uncompound.  */
	  gas_assert (wc.cs1.set == 0);
	  wc.cs1.set = 1;
	  wc.cs1.val.fields.call.opc = 0x3;
	  /* The underlying value corresponds to the only `all_e = 1'
	     parameter to WAIT.  */
	  wc.cs1.val.fields.call.param = 0x2;
	}
      else if (als_fmt == 6 && reg->rr_nop)
	{
	  wc.nop_nmb = 4;
	}
    }

  *str = s;
  return 1;
}

#define NONE_VALUE      0xc0
#define EXT_VALUE       0x01
#define EXT1_VALUE      0x02


/* parse_chn_optional returns zero only if CHN looks bogus
   and 1 if it is missing or OK. */
static int
parse_chn_optional (char **pstr, const e2k_alf_opcode_templ *tpl, int second)
{
  char *s = *pstr;

  /* If we are invoked for the second time and the first invocation obtained a
     channel, do nothing.  */
  if (second && free_als->plcmnt_nmb == 1)
    return 1;

  /* FIXME: under some idiotic circumstances one may obtain here ` ,chn'. For
     now this lets me avoid the trouble of leaving it unparsed and obtaining
     another trouble when parsing arguments of the related instruction . . .  */
  slurp_char (&s, ' ');

  do {
    unsigned chn;
    if (slurp_char (&s, ',')
        && parse_number (&s, &chn, sizeof (chn), 0))
      {
        if (! (chn < (sizeof (tpl->allowed_channels)
                      / sizeof (tpl->allowed_channels[0]))
               && tpl->allowed_channels[chn]))
          {
            as_bad (_("illegal channel number for `%s'"), tpl->name);
            break;
          }

        /* Set up an explicitly specified placement for this ALS. */
        free_als->plcmnt_nmb = 1;
        free_als->pos[0] = chn;

        /* Channel number has been parsed successfully. */
        *pstr = s;
      }
    else if (second)
      {
        /* Since the channel hasn't been explicitly specified for this ALS set
	   up all valid placements. Obviously, there is no point in doing this
	   during the first invocation, because the situation may change during
	   the second one.  */

	/* Moreover, if I were to set up them here during the first invocation,
	   this would make me mistakenly believe that the channel number has
	   already been explicitly specified at the beginning of the second one
	   for instructions having exactly one suitable channel such as
	   divisions (Bug #95134).  */
        int i;
        free_als->plcmnt_nmb = 0;
        for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
          {
            if (tpl->allowed_channels[i])
              free_als->pos[free_als->plcmnt_nmb++] = i;
          }
      }

    return 1;
  } while (0);

  return 0;
}

static int
parse_sm_optional (char **pstr)
{
  if (slurp_str (pstr, ",sm")
      /* Fuck them off! When these stupid users specify `insn, sm %arg1, . . .'
         (note the absence of explicit ALS and space before `sm') we eventually
         get here `, sm', not `,sm'. FIX this in a more regular way.  */
      || slurp_str (pstr, ", sm")
      || slurp_str (pstr, ",s")
      || slurp_str (pstr, ", s"))
    {
      unsigned i;
      for (i = 0; i < free_als->real_als_nmb; i++)
        free_als->u[i].alf1.opc.spec = 1;
    }

  return 1;
}

static void
almost_finish_alf (const e2k_alf_opcode_templ *alf)
{
  unsigned i;
  for (i = 0; i < free_als->real_als_nmb; i++)
    free_als->u[i].alf1.opc.cop = alf->opc;

  free_als->finish = finish_alf123578;
  free_als++;
}

static int
parse_mas (char **pstr, int mas_spec_expected)
{
  int explicit;
  char *s = *pstr;

  if (*s == '?')
    return 1;

  /* FIXME: what's the point in explicitly resetting MAS here? Isn't it zeroed
     out when I prepare free_alses? Currently that this function may be invoked
     twice to take two forms of syntax into account, this is harmful, since the
     second invocation may very well discard the result of the first one.  */
  /* free_als->need_mas = 0;  */

  explicit = slurp_str (&s, ",mas=");

  if (!mas_spec_expected || explicit)
    {
      expressionS exp;
      char *save = input_line_pointer;
      input_line_pointer = s;
      expression (&exp);
      s = input_line_pointer;
      input_line_pointer = save;

      if (exp.X_op != O_constant)
        {
          if (mas_spec_expected)
            {
              as_bad ("mas value expected after mas=");
              return 0;
            }

          *pstr = s;
          return 1;
        }

      free_als->mas = exp.X_add_number;
      if (free_als->mas >= 0x80)
        {
          as_bad ("illegal mas value `0x%x'", (unsigned) free_als->mas);
          return 0;
        }
      else 
        {
          /* Zero MAS seems to be assumed by default for all types of memory
             access (at least 0 is a default value for MAS.mod according to
             C.11.1.3.{1,2}). Therefore, don't waste CS1 to encode it even if a
             user has explicitly specified it.  */
          if (free_als->mas != 0)
            free_als->need_mas = 1;

          *pstr = s;
        }
    }
  return 1;
}

static char *
enclosing_bracket (char *s, int replace_plus, char **plus)
{
  int level = 1;
  int comma_met = 0;

  if (plus)
    *plus = NULL;

  for (; *s != '\0'; s++)
    {
      if (*s == '[' || *s == '(')
        level++;
      else if (*s == ']' || *s == ')')
        level--;
      else if (!comma_met && level == 1 && *s == ',')
        comma_met = 1;
      /* We should replace only the leftmost plus at level 1 provided that
         it hasn't been preceded by comma. If it has been preceded by comma,
         then it means that the plus is within SRC2.  */
      else if (replace_plus && level == 1 && !comma_met
               && *plus == NULL && *s == '+')
        {
          *plus = s;
          *s = ',';
        }

      if (level == 0)
        {
          *s = ',';
          return s;
        }
    }

  return NULL;
}

struct args_closure
{
  /* Remember if `const' comes first in the "outermost" expression of the form
     `%rX + const' or `const + %rX'. For example, in `0xa + %rX + 0xb' const
     comes first. This is required to preserve the order between `const' and
     `%rX' specified by the user even if the latter could be encoded more
     efficiently than the former (consider `const == 0x1e' matching a 5-bit
     literal but not a 4-bit one as an example). All this is needed to obtain
     the code as similar as possible to the one produced by LAS.

     Note that unlike LAS we remain capable of swapping arguments in an
     expression like `(const > 31) + %rX'. This doesn't lead to a divergence in
     the assembled code since LAS just returns an error in such a case.  */
  int const_first;
  expressionS reg1_expr;
  expressionS reg2_expr;
  expressionS lit_expr;
};

static int
is_symbol (expressionS *e)
{
  if (e->X_op == O_symbol
      || e->X_op == O_gotoff
      || e->X_op == O_got
      || e->X_op == O_gotplt
      || e->X_op == O_tls_le
      || e->X_op == O_tls_ie
      || e->X_op == O_tls_gdmod
      || e->X_op == O_tls_gdrel
      || e->X_op == O_tls_dtprel
      || e->X_op == O_pc
      || e->X_op == O_size
      || e->X_op == O_ap_got
      || e->X_op == O_pl_got
      || e->X_op == O_islocal32)
    return 1;

  return 0;
}

static int
get_symbol_size (expressionS *e)
{
  gas_assert (is_symbol (e));

  if (e->X_op == O_got
      || e->X_op == O_gotplt
      || e->X_op == O_tls_ie
      || e->X_op == O_tls_gdmod
      || e->X_op == O_tls_gdrel
      || e->X_op == O_size
      || e->X_op == O_islocal32)
    return LITERAL_32;

  /* FIXME: barf on other unsupported relocations in PM too. Consider returning
     an error in such a case and treating it appropriately at this function's
     call point.  */
  if (e->X_op == O_gotoff && e2k_arch_size == 128)
    as_bad (_("`@GOTOFF' is not supported in protected mode"));

  return ((e2k_arch_size == 32 || e2k_arch_size == 128)
	  ? LITERAL_32 : LITERAL_64);
}

static int
handle (struct args_closure *closure, expressionS *e)
{
  expressionS *reg1_expr = &closure->reg1_expr;
  expressionS *reg2_expr = &closure->reg2_expr;
  expressionS *lit_expr = &closure->lit_expr;

  /* This sign should be set appropriately in the "outermost" expression.  */
  if (closure->const_first == -1)
    closure->const_first
      = ((e->X_op == O_add
          && symbol_get_value_expression (e->X_add_symbol)->X_op == O_constant)
         ? 1 : 0);


  if (e->X_op == O_add)
    {
      expressionS *e1 = symbol_get_value_expression (e->X_add_symbol);
      expressionS *e2 = symbol_get_value_expression (e->X_op_symbol);

      if (! handle (closure, e1) || ! handle (closure, e2))
        return 0;

      if (e->X_add_number != 0)
        {
          expressionS e3;

          e3.X_op = O_constant;
          e3.X_add_number = e->X_add_number;

          if (! handle (closure, &e3))
            return 0;
        }

    }
  else if (is_symbol (e))
    {
      offsetT addend = 0;

      if (is_symbol (lit_expr))
        return 0;

      if (lit_expr->X_op == O_constant)
        addend = lit_expr->X_add_number;

      *lit_expr = *e;
      lit_expr->X_add_number += addend;
    }
  else if (e->X_op == O_constant)
    {
      /* Note that here I may need to create a zero constant to avoid an empty
         operand error.  */
      if (lit_expr->X_op == O_constant || is_symbol (lit_expr))
        lit_expr->X_add_number += e->X_add_number;
      else
        {
          gas_assert (lit_expr->X_op == O_absent);
          *lit_expr = *e;
        }
    }
  else if (e->X_op == O_register)
    {
      if (reg1_expr->X_op == O_absent)
        *reg1_expr = *e;
      else if (reg2_expr->X_op == O_absent)
        *reg2_expr = *e;
      else
        return 0;
    }
  else
    return 0;

  return 1;
}

int min_col;
int max_col;
int min_row;
int max_row;

int lit_reference;

static void
encode_src2 (expressionS *e, const e2k_register_format arg_fmt)
{
  int i;

  if (e->X_op == O_register)
    encode_reg (2, arg_fmt, e->X_add_number);
  else if (e->X_op == O_constant
           && (e->X_add_number >= 0
               && e->X_add_number <= 15
               /* The underlying test checks that no placement specifiers have
                  been explicitly specified.  */
               && min_col == 0
               && max_col == 7
               && min_row == LITERAL_16
               && max_row == LITERAL_64))
    {
      gas_assert (lit_reference == 0);
      encode_short_lit_in_src2 (e->X_add_number);
    }
  else if (lit_reference != 0)
    {
      gas_assert (min_row == max_row
                  && (min_col == max_col
                      || dummy_table[min_row][max_col] ==0));
      encode_lit_ref_in_src2 (min_row, min_col);
    }
  else
    {
      literal_placement *plcmnt;

      free_als->src2 = plcmnt = &allowed_placements[crnt_lit++];
      plcmnt->plcmnt_nmb = 0;
      plcmnt->exp = *e;

      plcmnt->als_idx = (free_als->plcmnt_nmb == 1
                         ? free_als->pos[0] : 6);

      if (is_symbol (e))
        {
          int symbol_size = get_symbol_size (e);

          if (min_row == LITERAL_16 && max_row == LITERAL_64)
            min_row = max_row = symbol_size;
          else if ((min_row != symbol_size || max_row != symbol_size)
		   /* Allow for explicitly specified 32-bit variants of abs
		      and gotoff relocations no matter in which mode the
		      assembly is done.  */
		   && ! ((e->X_op == O_symbol
			  || e->X_op == O_gotoff)
			 && min_row == LITERAL_32
			 && max_row == LITERAL_32))
            as_bad (_("Wrong size for symbol specified"));
        }
      else if (min_row == LITERAL_16 && max_row == LITERAL_64)
        {
          offsetT val = e->X_add_number;
          if (arg_fmt == DOUBLE
              && (val < -2147483648LL || val > 2147483647LL))
            min_row = LITERAL_64;
          else if (val < -32768 || val > 32767)
            min_row = LITERAL_32;
        }

      for (i = min_row; i <=  max_row; i++)
        {
          int j;
          for (j = min_col; j <= max_col; j++)
            {
              static int conv[8] = {1, 0, 3, 2, 4, 5, 6, 7};
              /* Avoid conversion if a 16-bit literal has been specified
                 unambiguously, say as `_f16s,_lts0lo'. Otherwise you'll
                 get `_f16s,_lts0hi' instead. In other cases when there's
                 some uncertainty (e.g. `_f16s,_lts0' or no location at all)
                 the conversion will do the right thing, i.e. let one prefer
                 the `hi' part for a 16-bit literal.  */
              int k = (i == 0 && min_col != max_col) ? conv[j] : j;

              if (dummy_table[i][k])
                {
                  plcmnt->size[plcmnt->plcmnt_nmb] = ((i == LITERAL_16) ? 1 : ((i == LITERAL_32) ? 2 : 4));
                  plcmnt->pos[(plcmnt->plcmnt_nmb)++] = k;
                }
            }
        }
    }
}

static int
parse_src2 (char **pstr, e2k_register_format fmt)
{
  char *s = *pstr;
  expressionS exp;
  struct args_closure cl;
  int is_register;
  char *save_input_line_pointer = input_line_pointer;

  input_line_pointer = s;
  hack_for_e2k = 1;
  expression (&exp);
  hack_for_e2k = 0;
  s = input_line_pointer;
  input_line_pointer = save_input_line_pointer;

  cl.const_first = -1;
  cl.lit_expr.X_op = O_absent;
  cl.reg1_expr.X_op = O_absent;
  cl.reg2_expr.X_op = O_absent;

  if (! handle (&cl, &exp))
    {
      as_bad (_("invalid operand at position of SRC2"));
      return 0;
    }

  if (cl.reg1_expr.X_op == O_absent
      && cl.lit_expr.X_op == O_absent)
    {
      as_bad (_("empty operand at position of SRC2"));
      return 0;
    }

  if (cl.reg2_expr.X_op != O_absent
      || (cl.reg1_expr.X_op != O_absent && cl.lit_expr.X_op != O_absent))
    {
      as_bad (_("illegal operand at position of SRC2"));
      return 0;
    }


  is_register = cl.reg1_expr.X_op != O_absent;
  encode_src2 (is_register ? &cl.reg1_expr : &cl.lit_expr, fmt);

  *pstr = s;
  return 1;
}


static int
parse_three_args_for_ld_st (char **pstr,
                            const e2k_register_format *arg_fmt,
                            int for_store,
                            int need_mas,
                            int extra_arg __attribute__ ((unused)))
{
  int i;
  expressionS exp;
  struct args_closure cl[3];
  int len = 0;
  expressionS *args[3];
  expressionS zero;
  char *s = *pstr;

#define add_arg(e)                                                      \
  {                                                                     \
    if (len == 3)                                                       \
      {                                                                 \
        as_bad (_("excessive number of operands for an instruction"));  \
        return 0;                                                       \
      }                                                                 \
                                                                        \
    args[len++] = e;                                                    \
  }
  
  for (i = 0; i < 3; i++)
    {
      /* Remember the start of the current operand to produce meaningful
         error messages below if needed.  */
      const char *operand = s;
      char *save_input_line_pointer = input_line_pointer;

      input_line_pointer = s;
      hack_for_e2k = 1;
      expression (&exp);
      hack_for_e2k = 0;
      s = input_line_pointer;
      input_line_pointer = save_input_line_pointer;


      cl[i].const_first = -1;
      cl[i].lit_expr.X_op = O_absent;
      cl[i].reg1_expr.X_op = O_absent;
      cl[i].reg2_expr.X_op = O_absent;

      if (! handle (&cl[i], &exp))
        {
          as_bad (_("invalid expression at `%s'"), operand);
          return 0;
        }

      if (cl[i].reg1_expr.X_op == O_absent
          && cl[i].reg2_expr.X_op == O_absent
          && cl[i].lit_expr.X_op == O_absent)
        {
          as_bad (_("empty operand at `%s'"), operand);
          return 0;
        }

      if (cl[i].reg1_expr.X_op != O_absent
          && cl[i].reg2_expr.X_op != O_absent
          && cl[i].lit_expr.X_op != O_absent)
        {
          /* It's safe to eliminate a superfluous zero constant. This is to
             allow our stupid programmers to have `%rX + %rY + 38 - 11 -27' for
             `SRC1, SRC2'.  */
          if (cl[i].lit_expr.X_op == O_constant
              && cl[i].lit_expr.X_add_number == 0)
            cl[i].lit_expr.X_op = O_absent;
          else
            {
              /* Make your best to output only the operand under
                 consideration.  */
              char c = s[0];
              s[0] = '\0';
              as_bad (_("excessive number of terms in an instruction's "
                        "operand at `%s'"), operand);
              s[0] = c;
              return 0;
            }
        }

      if (cl[i].lit_expr.X_op != O_absent)
        {
          /* FIXME: stupidly prevent literal from being encoded as SRC1 if a
             QUAD register is required at this position. Consider the following
             awful syntax which may provoke an invalid instruction:
             `ldapq %r2 + 0, %r4' (I came across it in PM setjmp within libmcst)
             or  even "better" `ldapq 0 + %r2, %r4'. */

          int fit_src1 = (/* Don't attempt to put a constant into position of
                             SRC1 if it has been specified AFTER a register in
                             an expression like `%rX + const'.  */
                          cl[i].const_first == 1
                          && arg_fmt[0] != QUAD
                          && cl[i].lit_expr.X_op == O_constant
                          && cl[i].lit_expr.X_add_number >= 0
                          && cl[i].lit_expr.X_add_number <= 31);

          /* Ensure that a short 5-bit literal matching SRC1 comes before a
             register from the very beginning in case they are provided via a
             single expression (i.e. as terms of a sum).  */
          if (fit_src1)
            add_arg (&cl[i].lit_expr);

          if (cl[i].reg1_expr.X_op != O_absent)
            add_arg (&cl[i].reg1_expr);

          /* Contrary to the aforesaid, ensure that a long literal requiring
             SRC2 comes after a register (if any).  */
          if (! fit_src1)
            add_arg (&cl[i].lit_expr);
        }
      else
        {
          add_arg (&cl[i].reg1_expr);

          if (cl[i].reg2_expr.X_op != O_absent)
            add_arg (&cl[i].reg2_expr);
        }

      if (need_mas && ! parse_mas (&s, 0))
        {
          as_bad (_("invalid MAS specified"));
          return 0;
        }

      if (i < 2)
        {
          if (*s == '\0' || *s == '?')
            {
              /* One may not have less than two operands for LD/ST separated by
                 commas.  */
              if (i == 0)
                {
                  as_bad (_("insufficient number of operands for an "
                            "instruction"));
                  return 0;
                }

              break;
            }

          if (! slurp_char (&s, ','))
            {
              as_bad (_("missing comma at `%s'"), s);
              return 0;
            }
        }
    }

  gas_assert (len == 2 || len == 3);

  /* Ensure that I always indexes the last element in cl[] for loads and stores
     in `.ignore ld_st_style' mode.  */
  if (i == 3)
    i = 2;

  /* For "traditional" (i.e. non-`.ignore ld_st_style') stores use 0 in the
     below check.  */
  if (for_store && !ignore_ld_st)
    i = 0;

  /* I guess that the case like 'ld %rx, [%rY + %rZ]' cannot be recognized
     within the above loop. Catch it now.  */
  if (cl[i].reg1_expr.X_op == O_absent
      || cl[i].reg2_expr.X_op != O_absent
      || cl[i].lit_expr.X_op != O_absent)
    {
      as_bad (_("Register should be specified for %s"),
              for_store ? "SRC3" : "DST");
      return 0;
    }

  /* Convert the awful traditional order of operands in store to the standard
     one.  */
  if (for_store && !ignore_ld_st)
    {
      expressionS *tmp = args[0];
      args[0] = args[1];
      if (len == 3)
        args[1] = args[2];

      args[len - 1] = tmp;
    }

  /* Insert an implicit zero argument if needed.  */
  if (len == 2)
    {
      /* Move DST to its legitimate position.  */
      args[2] = args[1];

      zero.X_op = O_constant;
      zero.X_add_number = 0;

      /* Leave a 5-bit constant in SRC1: it might very well not match a 4-bit
         short literal in SRC2 and thus require a long one.

         Avoid moving a register to SRC2 position as well: this may lead to an
         illegal encoding in case of QUAD operand. Consider the following
         idiotic syntax which may provoke this error: `ldapq %r2, %r4' if I
         don't take care of that.  */
      if (

          /* FIXME: contrary to what is said above DO move a "lonely" constant
             argument (for example `[1]' or `[5]') to SRC2 even if its placement
             at position of SRC1 could eliminate the need for allocation of a
             16-bit literal. This is to emulate the stupid behaviour of LAS:
             when running E2KT for E2K binary compiler project with `e2k-linux
             -as' operating in "self-control" mode I got numerous divergences
             because of this stupid issue . . .  */
#if 0
          (args[0]->X_op == O_constant
          && args[0]->X_add_number >= 0
           && args[0]->X_add_number <= 31)
          ||
#endif /* 0  */
          args[0]->X_op == O_register)
        args[1] = &zero;
      else
        {
          args[1] = args[0];
          args[0] = &zero;
        }
    }

  gas_assert (args[2]->X_op == O_register);
  encode_reg (4, arg_fmt[2], args[2]->X_add_number);


  if (args[0]->X_op == O_register)
    encode_reg (1, arg_fmt[0], args[0]->X_add_number);
  else if (args[0]->X_op == O_constant
           && args[0]->X_add_number >= 0
           && args[0]->X_add_number <= 31)
    encode_short_lit_in_src1 (args[0]->X_add_number);
  else
    {
      as_bad (_("Invalid argument in position of SRC1."));
      return 0;
    }

  encode_src2 (args[1], arg_fmt[1]);
  *pstr = s;

  return 1;
}

static int
parse_alf1_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf1_opcode_templ *alf = (const e2k_alf1_opcode_templ *) op;

  if (alf->alopf == ALOPF11 || alf->alopf == ALOPF11_MERGE)
    {
      const e2k_alopf11_opcode_templ *alopf11
        = (const e2k_alopf11_opcode_templ *) op;

      free_als->need_ales = 1;
      free_als->ales.alef2.opce = alopf11->ales_opce;
      free_als->opc2_arr = alopf11->ales_opc2;
      free_als->explicit_ales25_v4 = alopf11->explicit_ales25_v4;
    }

  do {
    CHECK (parse_three_args_for_ld_st (&s, alf->arg_fmt, 0, alf->need_mas,  1));

    if (alf->alopf == ALOPF11_MERGE)
      {
        e2k_pred mrg_pred;

        CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
        CHECK_MSG (parse_pred (&s, &mrg_pred, 1),
                   _("predicate expected at `%s'"), s);
        free_als->preds[1] = mrg_pred;
      }

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}

static int
parse_alopf11_lit8_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alopf11_lit8_opcode_templ *alf
    = (const e2k_alopf11_lit8_opcode_templ *) op;


  free_als->need_ales = 1;
  free_als->opc2_arr = alf->ales_opc2;
  
  do {
    u_int32_t alef2_opce;

    CHECK (parse_src1 (&s, alf->arg_fmt[0]));
    CHECK (slurp_char (&s, ','));
    CHECK (parse_src2 (&s, alf->arg_fmt[1]));

    /* FIXME: the use of parse_literal by analogy with `parse_pshufh_args ()'
       leads to SIGSEGV here.  */
    CHECK_MSG ((slurp_char (&s, ',')
                && parse_number (&s, &alef2_opce, sizeof (alef2_opce), 0)),
               _("`, literal8' expected"));

    if (alef2_opce > 0xff)
      {
        const char *msg = "value of literal8 is out of range";

        /* FIXME: can it be possible to implement 'as_bad_or_warn ()' in some
           regular way?  */
        if (! permissive_mode)
          as_bad (_(msg));
        else
          as_warn (_(msg));
      }
    else if (alf->warn && alef2_opce > alf->max_lit8)
      as_warn (_(alf->warn));


    free_als->ales.alef2.opce = (u_int8_t) (alef2_opce & 0xff);

    CHECK (parse_dst (&s, alf->arg_fmt[2]));

    *pstr = s;
    return 1;
  }
  while (0);
  return 0;
}


/* FIXME: the function is declared below.  */
static void start_ss_syllable (int set_ilabel);

#define IBRANCH 1
#define RBRANCH 2
static int parse_ctcond (char **pstr, int ibranch);

static int
parse_alf2_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf2_opcode_templ *alf = (const e2k_alf2_opcode_templ *) op;

  do {
    unsigned i;

    if (alf->alopf == ALOPF12_IBRANCHD
	|| alf->alopf == ALOPF12_ICALLD)
      {
	/* FIXME: the following code has been stupidly copied from
	   `parse_ibranch_args ()'. */

	/* Do I actually need to support an internal label here?  */
	start_ss_syllable (1);

	if (wc.ss.set.ctop)
	  {
	    as_bad (_("cannot encode `%s', SS.ctop in the current wide command"
		      " is already busy"), op->name);
	    break;
	  }
	
	SET_FIELD (ss, ctop, 0, 0 /* non-default */);
      }

    if (alf->alopf == ALOPF12_ICALLD)
      {
	u_int8_t wbs;

	/* Should I really consider it optional?  */
	slurp_str (&s, "wbs=");

	/* FIXME: use of `SGND' parameter equal to `2' here is a hack which
	   lets me handle the case of WBS being an expression, e.g.,
	   `call %ctprX, wbs = 16 - 4'.  */
	CHECK_MSG (parse_number (&s, &wbs, sizeof (wbs), 2),
		   _("wbs value expected"));

	free_als->u[0].alf2.opce = wbs;

	CHECK_MSG (slurp_char (&s, ','), _("comma expected after WBS"));
      }


    CHECK (parse_src2 (&s, alf->arg_fmt[0]));
    CHECK (parse_dst (&s, alf->arg_fmt[1]));

    /* The execution of `I{BRANCH,CALL}D' is controlled by `ctcond' rather
       than by `alj_cond' unlike ordinary AL instructions!  */
    if (alf->alopf == ALOPF12_IBRANCHD || alf->alopf == ALOPF12_ICALLD)
      CHECK (parse_ctcond (&s, alf->alopf == ALOPF12_IBRANCHD ? IBRANCH : 0));
    
    *pstr = s;

    if (alf->alopf != ALOPF12_ICALLD)
      {
	for (i = 0; i < free_als->real_als_nmb; i++)
	  free_als->u[i].alf2.opce = alf->opce;
      }

    /* As far as I understand ALES is needed for ALOPF{1,2}2
       only. */
    if (alf->alopf == ALOPF12
	|| alf->alopf == ALOPF12_IBRANCHD
	|| alf->alopf == ALOPF12_ICALLD
	|| alf->alopf == ALOPF22
        /* It seems that GETSP needs ALES even though it is ALOPF2.
           I cannot understand why. */
        || alf->opc == 0x58)
      {
	free_als->need_ales = 1;

        /* FIXME ! ! !  */
        if (alf->alopf == ALOPF12)
          {
            const e2k_alopf12_opcode_templ *alopf12 =
              (const e2k_alopf12_opcode_templ *) op;

            free_als->ales.alef2.opce = alopf12->ales_opce;
            free_als->ales.alef2.opc2 = alopf12->ales_opc2;
          }
        else
          {
            /* This is almost certainly wrong. Cast OP appropriately to either
               of `e2k_alopf{1,2}2_opcode_templ' and fetch these parameters
               from there.  */
            free_als->ales.alef2.opce = NONE_VALUE;
            free_als->ales.alef2.opc2 = EXT_VALUE;
          }
      }

    /* Take into account that according to all existing `iset-vX.single's
       `{MOVTd,GETPL} . . ., %ctprX' should be encoded in ALS0 only. According
       to instruction Table B.1.1 in use ALS0 should be already encoded in
       free_als->pos[0].  */
    if (alf->alopf == ALOPF2 && (alf->opc == 0x61 || alf->opc == 0x63)
        && (free_als->u[0].alf1.dst >= 0xd1 && free_als->u[0].alf2.dst <= 0xd3))
      {
        gas_assert (free_als->plcmnt_nmb >= 1);
        if (free_als->pos[0] != 0)
	  {
	    as_bad (_("`%s' to `%%ctpr{1,2,3}' registers may be encoded in "
		      "the 0-th channel only"),
		    alf->opc == 0x61 ? "movtd" : "getpl");
	    return 0;
	  }
        free_als->plcmnt_nmb = 1;
      }

    return 1;
  }
  while (0);

  return 0;
}

static int
parse_pshufh_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alopf12_opcode_templ *alf = (const e2k_alopf12_opcode_templ *) op;
  do {
    u_int8_t alef2_opce;

    CHECK (parse_src2 (&s, alf->arg_fmt[0]));

    CHECK_MSG ((slurp_char (&s, ',')
                && parse_number (&s, &alef2_opce, sizeof (alef2_opce), 0)),
               _("`, order' expected for PSHUFH"));

    CHECK (parse_dst (&s, alf->arg_fmt[1]));
    free_als->u[0].alf2.opce = alf->opce;
    free_als->need_ales = 1;
    free_als->ales.alef2.opce = alef2_opce;
    free_als->ales.alef2.opc2 = alf->ales_opc2;

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}

static int
parse_alf3_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf3_opcode_templ *alf = (const e2k_alf3_opcode_templ *) op;

  do {
    CHECK (parse_three_args_for_ld_st (&s, alf->arg_fmt, 1, alf->need_mas, 1));

    if (alf->alopf == ALOPF13)
      {
        const e2k_alopf13_opcode_templ *alopf13 =
          (const e2k_alopf13_opcode_templ *) op;

        free_als->need_ales = 1;
        free_als->ales.alef2.opce = alopf13->ales_opce;
        free_als->ales.alef2.opc2 = alopf13->ales_opc2;
      }

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}

struct mu_reg
{
  int min_cpu;
  const char *name;
  int addr;
  int mas;
  /* Which ALC `mmurr %mmu_reg, %rX' can be encoded in. FIXME: should I have a
     mask here provided that at most one ALC can be allowed? If not, how do I
     specify that no ALCes are allowed?  */
  int read_chn;

  int readable;

  /* Specifies whether `mmurw,2 %rX, %mmu_reg' is allowed or not. Note that the
     only valid channel for MMURW seems to be ALC2 which has already been taken
     into account in `opcode_templ'. While the zero value of this field means
     "not writable anywhere", non-zero stands for the minimal iset starting from
     which the register becomes writable (consider `%us_cl_{b,up,m*}' which have
     been present since elbrus-v1, but become writable starting from elbrus-v6
     only, see Bug #107736). Note, however, that this field may still contain 1
     being less than MIN_CPU for initially writable registers. This shouldn't
     break anything but at the same time saves me the trouble of reworking
     mu-regs.def to match the new meaning of this field. */
  int writable;
};

static struct hash_control *
init_mu_register_hash (void)
{
  size_t i;
  struct hash_control *res;

  static struct mu_reg reg_tbl [] = {

    /* According to C.11.1.3.1 MAS for `mmur{r,w}' has MASF1 format and is
       calculated as `MAS = (MAS.opc << 3) | 7'.  */
#define ENTRY(a,b,c,d,e,f) {a, b, c, (d << 3) | 7, e, 1, f},
    /* Specify whatever you want for READ_CHN provided that this
       register is not readable.  */
#define WONLY(a,b,c,d) {a, b, c, (d << 3) | 7, 2, 0, 1},
#define DIS_ENTRY(a,b,c,d,e,f)
#include "opcode/e2k/mu-regs.def"
#undef DIS_ENTRY
#undef WONLY
#undef ENTRY

  };

  res = hash_new ();
  for (i = 0; i < sizeof (reg_tbl) / sizeof (reg_tbl[0]); i++)
    {
      if (hash_insert (res, reg_tbl[i].name, (void *) &reg_tbl[i]))
	as_fatal (_("hash_insert () failed"));
    }

  return res;
}



static int
parse_mu_reg (char **pstr, struct mu_reg **preg)
{
  static struct hash_control *hash;
  struct mu_reg *reg;
  char *s = *pstr;

  if (hash == NULL)
    hash = init_mu_register_hash ();

  reg = reg_hash_entry (hash, "MU", &s);
  if (reg == NULL)
    return 0;

  /* Unlike CU registers all MU ones seem to be "forward-compatible".
     Therefore I don't specify MAX_CPU for them.  */
  if ((mcpu != 0 || reg->min_cpu != 1)
      && (mcpu < reg->min_cpu))
    {
      /* This is a temporary assert inserted simultaneously with the
	 removal of the below user error message in "generic" case.  */
      gas_assert (mcpu >= 2);
      as_bad (_("MU register `%s' is not available for elbrus-v%d"),
	      reg->name, mcpu);

      return 0;
    }

  *preg = reg;
  *pstr = s;

  return 1;
}

static int
parse_mmurr_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf1_opcode_templ *alf = (const e2k_alf1_opcode_templ *) op;

  do {
    /* FIXME: that awful parse_literal () invoked from within parse_src{1,2} ()
       expects to meet a comma after the literal value. In fact it will go on
       parsing the input string until it meets the one. Therefore append a
       comma to the end of my fake input buffer. Otherwise, you may very well
       obtain a poorly reproducible memory error when running e2k-linux-as
       . . .  */
    static char fake_buf[128], zero_fake_buf[] = "0,";
    char *fake;
    struct mu_reg *mmu_reg;

    fake = &zero_fake_buf[0];
    CHECK (parse_src1 (&fake, alf->arg_fmt[0]));

    slurp_char (&s, ' ');

    if (! parse_mu_reg (&s, &mmu_reg))
      {
        as_bad (_("unknown src2 for mmurr at `%s'"), s);
        break;
      }

    if (free_als->plcmnt_nmb == 1)
      {
        if (free_als->pos[0] != mmu_reg->read_chn)
          {
            as_bad (_("`mmurr %s' can be encoded in ALC%d only"),
                    mmu_reg->name, mmu_reg->read_chn);
            break;
          }
      }
    else
      {
        free_als->plcmnt_nmb = 1;
        free_als->pos[0] = mmu_reg->read_chn;
      }


    sprintf (fake_buf, "%d,", mmu_reg->addr);
    fake = &fake_buf[0];
    CHECK (parse_src2 (&fake, alf->arg_fmt[1]));

    CHECK (parse_dst (&s, alf->arg_fmt[2]));


    free_als->need_mas = 1;
    free_als->mas = mmu_reg->mas;

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}


static int
parse_mmurw_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf3_opcode_templ *alf = (const e2k_alf3_opcode_templ *) op;

  do {
    /* FIXME: that awful parse_literal () invoked from within parse_src{1,2} ()
       expects to meet a comma after the literal value. In fact it will go on
       parsing the intput string until it meets the one. Therefore append a
       comma to the end of my fake input buffer. Otherwise, you may very well
       obtain a poorly reproducible memory error when running e2k-linux-as
       . . .  */
    static char fake_buf[128], zero_fake_buf[] = "0,";
    char *fake;
    struct mu_reg *mmu_reg;

    slurp_char (&s, ' ');
    CHECK (parse_src3 (&s, alf->arg_fmt[2], 0, 0));

    CHECK (slurp_char (&s, ','));
    if (! parse_mu_reg (&s, &mmu_reg))
      {
        as_bad (_("unknown src2 for mmurw at `%s'"), s);
        break;
      }

    if (! mmu_reg->writable)
      {
        as_bad (_("`%s' is not writable"), mmu_reg->name);
        break;
      }
    else if (mcpu < mmu_reg->writable)
      {
	as_bad (_("`%s' is not writable on `elbrus-v%d'"),
		mmu_reg->name, mcpu);
        break;
      }

    sprintf (fake_buf, "%d,", mmu_reg->addr);
    fake = &fake_buf[0];
    CHECK (parse_src2 (&fake, alf->arg_fmt[1]));

    fake = &zero_fake_buf[0];
    CHECK (parse_src1 (&fake, alf->arg_fmt[0]));

    free_als->need_mas = 1;
    free_als->mas = mmu_reg->mas;

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}

/* See C.17.1.2. */

#define CTCOND_MASK             480

#define CTCOND_NEVER            0
#define CTCOND_ALWAYS           32
#define CTCOND_PRED             64
#define CTCOND_NEG_PRED         96
#define CTCOND_LOOP_END         128
#define CTCOND_NOT_LOOP_END     160
#define CTCOND_MLOCK            256

static void
start_ss_syllable (int set_ilabel)
{
  if (set_ilabel && last_ilabel != NULL)
    {
      ss_ilabel = last_ilabel;
      last_ilabel_used++;
    }

  if (wc.ss.started)
    return;
  /* All values which are set here may be overriden, i.e.
     are default. */

  /* We may very well have no ct command in SS. However, since
     CTCOND_NEVER == 0, we may skip this. */
  SET_FIELD (ss, ctcond, CTCOND_NEVER, 1);

  /* IPD should be probably set to its default value for all instructions
     requiring SS provided that it hasn't been explicitly specified. FIXME:
     get rid of duplicating actions when encoding particular instructions.  */
  SET_FIELD (ss, ipd, default_ipd, 1);

  /* What are other necessary (non-zero) defaults? */
  wc.ss.started = 1;
}

static void
start_cs0 (void)
{
  if (last_ilabel != NULL)
    {
      cs0_ilabel = last_ilabel;
      last_ilabel_used++;
    }
}


int
parse_mova_args (char **pstr, const e2k_opcode_templ *op)
{
  int i;
  e2k_generic_register reg;
  const e2k_mova_opcode_templ *mova = (const e2k_mova_opcode_templ *) op;
  char *s = *pstr;
  unsigned chn;

  static const struct {
    const char *name;
    unsigned int max;
    unsigned int bit_offset;
  }
  param[] = {{"area=", 31, 6},
             {"ind=", 31, 1},
             {"am=", 1, 0},
             {"be=", 1, 15}};

  /* Specify if the corresponding parameter has already been seen.  */
  int seen[4] = {0, 0, 0, 0};

  int is_movaq =  mova->opc == 5;
  /* FIXME: find out if IND may be used uninitialized below.  */
  u_int8_t ind = 0;


  if (! slurp_char (&s, ',')
      || ! parse_number (&s, &chn, sizeof (chn), 0))
    {
      as_bad (_("mova channel expected at `%s'"), *pstr);
      return 0;
    }

  if (chn > 3)
    {
      as_bad (_("invalid mova channel %u specified"), chn);
      return 0;
    }

  if (is_movaq && chn % 2 != 0)
    {
      as_bad (_("movaq should be encoded in an even channel either 0 or 2"));
      return 0;
    }

  if (wc.busy_aa2f1 & (1 << chn))
    {
      as_bad (_("mova channel %d is already busy"), chn);
      return 0;
    }

  if (is_movaq && (wc.busy_aa2f1 & (1 << (chn + 1))))
    {
        as_bad (_("channel %d required for movaq is already busy"), chn + 1);
        return 0;
    }

  if (last_ilabel != NULL)
    {
      aa2f1_ilabel[chn] = last_ilabel;
      last_ilabel_used++;
    }

  wc.busy_aa2f1 |= 1 << chn;
  if (is_movaq)
    wc.busy_aa2f1 |= 1 << (chn + 1);


  /* Set `AA2F1.opc'.  */
  for (i = 0; i < (is_movaq ? 2 : 1); i++)
    wc.aa2f1[chn + i] |= mova->opc << 12;

  /* Space may be present if the channel number has been specified in the
     normal way (i.e. `mova,chn %dst') or absent in case of `mova, chn %dst'
     where the generic GAS parser removes space between CHN and DST). */
  slurp_char (&s, ' ');

  /* `16 == 4 * 4' stupidly takes into account that 4 MOVA* parameters may be
     shuffled.  */
  for (i = 0; i < 16; i++)
    {
      u_int8_t param_val;
      int k = i % 4;

      if (! slurp_str (&s, param[k].name))
	continue;

      if (seen[k])
	{
	  as_bad (_("`%s' has already been seen"), param[k].name);
	  return 0;
	}

      seen[k] = 1;

      if (! parse_number (&s, &param_val, sizeof (param_val), 0))
        {
          as_bad (_("numeric value should be specified for `%s'"),
                  param[k].name);
          return 0;
        }

      if (param_val > param[k].max)
        {
          as_bad (_("%d exceeds maximal value for %s"), param_val,
                  param[k].name);
          return 0;
        }

      if (k != 1 || !is_movaq)
        {
	  int j;
          /* Encode all parameters except for `ind' for MOVAQ . . . */
          for (j = 0; j < (is_movaq ? 2 : 1); j++)
            wc.aa2f1[chn + j] |= param_val << param[k].bit_offset;
        }
      else
        {
          /* . . . `ind' will be encoded later when the value of `be' is
             known.  */
          ind = param_val;
        }

      if (! slurp_char (&s, ','))
        {
          as_bad (_("`,' expected at `%s'"), s);
          return 0;
        }
    }

  if (is_movaq)
    {
      int big_endian = (wc.aa2f1[chn] & (1 << 15)) != 0;

      wc.aa2f1[chn + (big_endian ? 1 : 0)] |= ind << param[1].bit_offset;
      wc.aa2f1[chn + (big_endian ? 0 : 1)] |= (ind + 8) << param[1].bit_offset;
    }


  if (parse_generic_register (&s, &reg))
    {
      if (reg.fmt != mova->arg_fmt && reg.fmt != SINGLE)
        {
          as_bad (_("register of invalid format specified for dst of mova"));
          return 0;
        }

      /* ATTENTION: note that dst0 occupies the most significant half of AA0F1,
         while dst1 the least significant one.
         FIXME: currently I make use of the little-endian nature of a host
         e2k-linux-as is run at (i.e. `1 - chn % 2').  */
      for (i = 0; i < (is_movaq ? 2 : 1); i++)
        {
          encode_reg_in_dst (&wc.aa0f1[(chn + i) / 2].dst[1 - (chn + i) % 2],
                             &reg);
          reg.idx++;
        }
    }
  else
    {
      u_int8_t special_dst;
      
      if (! parse_special_register_for_dst (&s, &special_dst))
        {
          as_bad (_("invalid destination for MOVA at `%s'"), s);
          return 0;
        }

      if (is_movaq)
        special_dst &= 0xfe;

      for (i = 0; i < (is_movaq ? 2 : 1); i++)
        wc.aa0f1[(chn + i) / 2].dst[1 - (chn + i) % 2] = special_dst | i;
    }


  /* 0 means that SS shouldn't attempt to take ilabel belonging to our starting
     AA2F1 for its own. FIXME: in all other places I currently use 1 to be
     compatible with the prior behaviour. Change it to 0 in places where ilabel
     obviously belongs to another syllable, for example to CS0 or to CS1. This
     will let you eliminate the need for `cs{0,1}_ilabel == ss_ilabel' checks
     when packing a wide command.  */
  start_ss_syllable (0);

  for (i = 0; i < (is_movaq ? 2 : 1); i++)
    wc.ss.val.fields.aa |= 1 << (chn + i);

  *pstr = s;
  return 1;
}

int
parse_fapb_args (char **pstr,
                 const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  struct field {
    const char *name;
    int set;
    u_int32_t val;
    int bit_offset;
    int bit_size;
  };

#define fapb_fields                              \
  fapb_field (ct, 31, 1)                         \
  fapb_field (dpl, 31, 1)                        \
  fapb_field (si, 30, 1)                         \
  fapb_field (dcd, 28, 2)                        \
  fapb_field (fmt, 25, 3)                        \
  fapb_field (mrng, 20, 5)                       \
  fapb_field (d, 15, 5)                          \
  fapb_field (incr, 12, 3)                       \
  fapb_field (ind, 8, 4)                         \
  fapb_field (be, 14, 1)                         \
  fapb_field (am, 13, 1)                         \
  fapb_field (area, 8, 5)                        \
  fapb_field (asz, 5, 3)                         \
  fapb_field (abs, 0, 5)                         \
  fapb_field (disp, 0, 32)
  

#define fapb_field(name, offset, size)                  \
  struct field name##_fld = {#name"=", 0, 0, offset, size};

  fapb_fields;

#undef fapb_field
  
#define fapb_field(name, offset, size)          \
  &name##_fld,

  struct field *fields[] = {
    fapb_fields
  };

#undef fapb_fields

  char *s = *pstr;
  unsigned i, chn;
  int comma_expected = 0;

  while (*s != '\0')
    {
      if (comma_expected && ! slurp_char (&s, ','))
        {
          as_bad (_("comma expected at `%s'"), s);
          return 0;
        }
      else
        comma_expected = 1;
        
      for (i = 0; i < sizeof (fields) / sizeof (fields[0]); i++)
        if (slurp_str (&s, fields[i]->name))
          {
            if (! parse_number (&s, &fields[i]->val,
                                sizeof (fields[i]->val), 0))
              {
                as_bad (_("value expected after `%s'"), fields[i]->name);
                return 0;
              }

            fields[i]->set = 1;
            break;
          }

      if (i == sizeof (fields) / sizeof (fields[0]))
        {
          as_bad (_("unrecognized fapb parameter at `%s'"), s);
          return 0;
        }
    }

  if (ct_fld.set)
    {
      if (dpl_fld.set)
        {
          as_bad (_("`ct' and `dpl' can't be set within the same fapb"));
          return 0;
        }

      chn = 0;
    }
  else if (dpl_fld.set)
    chn = 1;
  else
    {
      as_bad (_("neither `ct', nor `dpl' has been specified"));
      return 0;
    }

  if ((wc.busy_aps & (1 << chn)) != 0)
    {
      as_bad (_("fapb occupying APS%d has already been met"), chn);
      return 0;
    }

  wc.busy_aps |= 1 << chn;

  if (si_fld.val == 0)
    {
      if (be_fld.set !=0 || am_fld.set != 0 || area_fld.set != 0)
        {
          as_bad (_("neither of `be', `am' and `area' can be specified "
                    "provided that `si == 0'"));
          return 0;
        }
    }
  else if (si_fld.val == 1)
    {
      if (incr_fld.set !=0 || ind_fld.set != 0)
        {
          as_bad (_("neither of `incr', and `ind' can be specified "
                    "provided that `si == 1'"));
          return 0;
        }
    }

  /* ATTENTION: in order not to mistakenly encode `disp' into APSx it's crucial
     that it comes last in the fields[] array!  */ 
  for (i = 0; i < sizeof (fields) / sizeof (fields[0]) - 1; i++)
    if (fields[i]->set)
      wc.aps[chn] |= fields[i]->val << fields[i]->bit_offset;

  /* Encode `disp' into APLSx. */
  wc.apls[chn] = disp_fld.val;

  *pstr = s;
  return 1;
}


int
parse_flushts_args (char **pstr ATTRIBUTE_UNUSED,
                    const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);

  /* FIXME: SS is stupidly set as a whole here. If we already met other
     instructions which can be encoded in SS syllable having SF2 format (e.g.
     ipd, ctop, ctcond), there encodings are sure to be lost. In addition to
     this currently there's no way to control which instructions can be encoded
     in SS along with FLUSHTS.

     FORTUNATELY, currently there is a single use of FLUSHTS within the Kernel
     where it's the only instruction in a wide command.  */
  wc.ss.val.word = 0xd4100000;
  return 1;
}


static int
parse_alf5_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alopf15_opcode_templ *alf = (const e2k_alopf15_opcode_templ *) op;

  gas_assert ((alf->arg_fmt == SINGLE) || (alf->arg_fmt == DOUBLE));
  do {
    CHECK (parse_src2 (&s, alf->arg_fmt));
    /* It's a shame. Deal uniformly with all commas. */
    CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
    CHECK (parse_state_register (&s, 5));
    

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    free_als->ales.alef2.opc2 = EXT_VALUE;
    free_als->u[0].alf5.opce = NONE_VALUE;

    *pstr = s;
    return 1;
     
  } while (0);

  return 0;
}

static int
parse_alf6_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alopf16_opcode_templ *alf = (const e2k_alopf16_opcode_templ *) op;

  gas_assert ((alf->arg_fmt == SINGLE) || (alf->arg_fmt == DOUBLE));
  do {
    CHECK (parse_state_register (&s, 6));
    CHECK (parse_dst (&s, alf->arg_fmt));

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    free_als->ales.alef2.opc2 = EXT_VALUE;
    free_als->u[0].alf6.none = NONE_VALUE;

    *pstr = s;
    return 1;
     
  } while (0);

  return 0;
}

static int
parse_alf7_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf7_opcode_templ *alf = (const e2k_alf7_opcode_templ *) op;

  do {
    e2k_pred pred;

    CHECK (parse_src1 (&s, alf->arg_fmt[0]));
    CHECK (slurp_char (&s, ','));
    CHECK (parse_src2 (&s, alf->arg_fmt[1]));
    /* I believe parse_dst2 is needed here. */
    CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
    CHECK_MSG (parse_pred (&s, &pred, 0), _("%%pred expected at `%s'"), s);

    if (pred.negated)
      {
        as_bad ("negated predicate is irrelevant in dst2");
        break;
      }

    free_als->u[0].alf7.dst2.pdst = pred.pred_num;

    if (alf->alopf == ALOPF7)
      free_als->u[0].alf7.dst2.cmpopce = alf->cmpopce;
    else if (alf->alopf == ALOPF17)
      {
	free_als->need_ales = 1;

	/* FIXME: here I just "reuse" CMPOPCE field somehow, `ALS.dst2.cmpopce'
	   seems to play no role in encoding of ALOPF17 instructions unlike
	   ALOPF7 ones. A dedicated `e2k_alopf17_opcode_templ' with a field
	   named in a more appropriate way is required.  */
	free_als->ales.alef2.opce = alf->cmpopce;

	/* Eventually OPC2 should be provided in `e2k_alopf17_opcode_templ'
	   especially if we end up with ALOPF17 instructions both in EXT and
	   EXT1 tables of instructions with long encodings.  */
	free_als->ales.alef2.opc2 = EXT1_VALUE;

	/* Note that nothing is said about this field in relation to ALOPF17
	   instructions in `iset-v6.single'.  */
	free_als->u[0].alf7.dst2.cmpopce = 0;
      }

    *pstr = s;

    /* Take comparison operations with an explicitly specified ALC into account.
       FIXME: in fact only _integer_ comparison operations should be tracked if
       you read C.17.1.2 attentively. To make it possible to distinguish them
       from floating-point comparisons they should be marked by `e2k-opcode-
       generator' somehow . . . The results of ALOPF8 `ccto*' operations
       shouldn't be referred to by `%cmpX' conditions as well. Therfore, they
       are not tracked in `parse_alf8_args ()'.
       TODO: however, LAS currently allows to refer to both floating-point
       comparisons and `ccto*' operations in `%cmp*' conditionals. Find out
       why.  */
    if (free_als->plcmnt_nmb == 1)
      {
        /* Should `free_als->real_alses[pos]' be taken into account here? This
           depends on whether ALOPF7 instruction can occupy two ALCes which
           doesn't seem to be the case.  */
        gas_assert (free_als->real_als_nmb == 1);
        wc.explicit_int_cmp_mask |= 1 << free_als->pos[0];
      }

    return 1;
  } while (0);

  return 0;
}

static int
parse_alf8_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf8_opcode_templ *alf = (const e2k_alf8_opcode_templ *) op;

  do {
    e2k_pred pred;

    CHECK (parse_src2 (&s, alf->arg_fmt));
    /* I believe parse_dst2 is needed here. */
    CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
    CHECK_MSG (parse_pred (&s, &pred, 0), _("%%pred expected at `%s'"), s);
    if (pred.negated)
      {
        as_bad (_("negated predicate is irrelevant in ALF8.dst2"));
        break;
      }

    free_als->u[0].alf8.dst2.pdst = pred.pred_num;
    free_als->u[0].alf8.dst2.cmpopce = alf->cmpopce;
    free_als->u[0].alf8.opce = NONE_VALUE;

    *pstr = s;
    return 1;
  } while (0);

  return 0;
}

static int
parse_aasti (char **pstr)
{
  char *s = *pstr;
  expressionS exp;
  struct args_closure cl;
  int aasti_idx;
  unsigned i;
  char *save_input_line_pointer = input_line_pointer;

  input_line_pointer = s;
  hack_for_e2k = 1;
  expression (&exp);
  hack_for_e2k = 0;
  s = input_line_pointer;
  input_line_pointer = save_input_line_pointer;

  cl.const_first = -1;
  cl.lit_expr.X_op = O_absent;
  cl.reg1_expr.X_op = O_absent;
  cl.reg2_expr.X_op = O_absent;

  if (! handle (&cl, &exp))
    {
      as_bad (_("Invalid argument for AASTI"));
      return 0;
    }

  if (cl.reg1_expr.X_op == O_absent
      || cl.reg1_expr.X_add_number < 256
      || cl.reg1_expr.X_add_number > 256 + 15)
    {
      as_bad (_("%%aasti<idx> expected"));
      return 0;
    }

  if (cl.reg2_expr.X_op != O_absent)
    {
      as_bad (_("Illegal argument for AASTI"));
      return 0;
    }

  aasti_idx = cl.reg1_expr.X_add_number - 256;
  for (i = 0; i < free_als->real_als_nmb; i++)
    {
      free_als->u[i].alf10.opce1_hi |= aasti_idx >> 1;
      free_als->u[i].alf10.opce1_lo |= (aasti_idx & 0x1) << 7;
    }


  if (cl.lit_expr.X_op != O_absent)
    {
      if (min_row != max_row
          || !(min_col == max_col || dummy_table[min_row][max_col] == 0))
        {
          as_bad (_("Literal format or position in %%aasti not specified"));
          return 0;
        }

      if (min_row != LITERAL_32)
        {
          as_bad (_("Wrong literal format in %%aasti"));
          return 0;
        }

      /* Either of `LTS{0,1,2}' should be explicitly selected.  */
      if (min_col != 0 && min_col != 2 && min_col != 4)
        {
          as_bad (_("Wrong literal position in %%aasti"));
          return 0;
        }

      /* Encode `lt' in ALS.opce1 (see C.11.7.1). In case there's no literal
         addend this field will silently remain equal to zero.  */
      for (i = 0; i < free_als->real_als_nmb; i++)       
        free_als->u[i].alf10.opce1_lo |= (min_col >> 1) + 1;

      /* By analogy with `encode_src2 ()' don't worry about a placement if you
         see a literal reference at least until you allow placements associated
         with identical expressions share the same literal. Otherwise this will
         lead to a "cannot place literals" error.  */
      if (! lit_reference)
        {
          literal_placement *plcmnt = &allowed_placements[crnt_lit++];
          plcmnt->exp = cl.lit_expr;
          plcmnt->plcmnt_nmb = 1;
          /* The underlying value corresponds to LITERAL_32.  */
          plcmnt->size[0] = 2;
          plcmnt->pos[0] = min_col;

          plcmnt->als_idx = (free_als->plcmnt_nmb == 1
                             ? free_als->pos[0] : 6);
        }
    }

  *pstr = s;
  return 1;
}

/* This one parses arguments of LDAA{b,h,w,d,q{,p}} instructions.  */
static int
parse_alf19_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf9_opcode_templ *alf = (const e2k_alf9_opcode_templ *) op;

  do {
    u_int8_t aad_num;
    unsigned i;

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    /* FIXME: this should be encoded within e2k_alf9_opcode_templ, of
       course.  */
    free_als->ales.alef2.opc2
      = strcmp (op->name, "ldaaqp") == 0 ? EXT1_VALUE : EXT_VALUE;

    CHECK_MSG (slurp_str (&s, "%aad"), _(", %%aad expected "));
    CHECK_MSG (parse_number (&s, &aad_num, sizeof (aad_num), 0),
               _("%%aad index expected"));
    CHECK_MSG (aad_num <= 31, _("invalid %%aad index specified"));

    for (i = 0; i < free_als->real_als_nmb; i++)
      free_als->u[i].alf10.opce1_hi |= aad_num << 3;

    /* This deserves a dedicated parse function since it may be an
       expression.  */
    parse_aasti (&s);

    CHECK (parse_dst (&s, alf->arg_fmt));

    if (! parse_mas (&s, 1))
      {
        as_bad (_("Invalid MAS specified"));
        return 0;
      }

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}


/* This one parses arguments of STAA{b,h,w,d,q{,p}} instructions.  */
static int
parse_alf10_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf10_opcode_templ *alf = (const e2k_alf10_opcode_templ *) op;

  do {
    u_int8_t aad_num;
    unsigned i;

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    /* FIXME: this should be encoded within e2k_alf10_opcode_templ, of
       course.  */
    free_als->ales.alef2.opc2
      = strcmp (op->name, "staaqp") == 0 ? EXT1_VALUE : EXT_VALUE;
    
    slurp_char (&s, ' ');
    CHECK (parse_src3 (&s, alf->arg_fmt, 0, 0));

    CHECK_MSG (slurp_str (&s, ",%aad"), _(", %%aad expected "));
    CHECK_MSG (parse_number (&s, &aad_num, sizeof (aad_num), 0),
               _("%%aad index expected"));
    CHECK_MSG (aad_num <= 31, _("invalid %%aad index specified"));

    for (i = 0; i < free_als->real_als_nmb; i++)
      free_als->u[i].alf10.opce1_hi |= aad_num << 3;

    /* This deserves a dedicated parse function since it may be an
       expression.  */
    parse_aasti (&s);

    if (! parse_mas (&s, 1))
      {
        as_bad (_("Invalid MAS specified"));
        return 0;
      }

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}


struct aau_reg
{
  const char *name;
  unsigned int reg;
  int need_d;
  unsigned int d;
  int need_ind;
  unsigned int ind;

  /* Note that all of them are currently r/w except for currently unsupported
     `%aabf' which is documented as write-only.  */
};

static struct hash_control *
init_aau_register_hash (void)
{
  size_t i;
  struct hash_control *res;

  static struct aau_reg reg_tbl [] = {

#define ENTRY(a,b) {a, b, 0, 0, 0, 0},
#define ENTRY_ALS_D(a,b,c) {a, b, 1, c, 0, 0},
#define ENTRY_ALS_IND(a,b,c) {a, b, 0, 0, 1, c},

#include "opcode/e2k/aau-regs.def"

#undef ENTRY_ALS_IND
#undef ENTRY_ALS_D
#undef ENTRY

  };

  res = hash_new ();
  for (i = 0; i < sizeof (reg_tbl) / sizeof (reg_tbl[0]); i++)
    {
      if (hash_insert (res, reg_tbl[i].name, (void *) &reg_tbl[i]))
	as_fatal (_("hash_insert () failed"));
    }

  return res;
}


static int
parse_aau_reg (char **pstr, struct aau_reg **preg)
{
  static struct hash_control *hash;
  struct aau_reg *reg;
  char *s = *pstr;

  if (hash == NULL)
    hash = init_aau_register_hash ();

  reg = reg_hash_entry (hash, "AAU", &s);
  if (reg == NULL)
    return 0;

  /* Unlike CU and MU registers the set of AAU ones seem to be identical for
     all supported instruction sets. Therefore I don't check if the obtained
     register is supported by the current MCPU.  */

  *preg = reg;
  *pstr = s;

  return 1;
}



static int
parse_aaurw_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf10_opcode_templ *alf = (const e2k_alf10_opcode_templ *) op;

  do {
    u_int16_t opce1;
    unsigned j;
    struct aau_reg *reg;

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    free_als->ales.alef2.opc2 = EXT_VALUE;

    free_als->need_mas = 1;
    /* MAS.mod == "special MMU/AAU" == 0x7,
       MAS.opc == "AAU reg operations" == 0x7  */
    free_als->mas = (0x7 << 3) | 0x7;

    slurp_char (&s, ' ');
    CHECK (parse_src3 (&s, alf->arg_fmt, 0, 0));
    CHECK_MSG (slurp_char (&s, ','), _("`,' expected"));

    if (! parse_aau_reg (&s, &reg))
      break;

    opce1 = reg->reg << 2;

    if (reg->need_ind)
      opce1 |= reg->ind << 7;

    if (reg->need_d)
      opce1 |= reg->d << 11;

    for (j = 0; j < free_als->real_als_nmb; j++)
      {
	free_als->u[j].alf10.opce1_lo = opce1 & 0xff;
	free_als->u[j].alf10.opce1_hi = opce1 >> 8;
      }

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}

static int
parse_aaurr_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf9_opcode_templ *alf = (const e2k_alf9_opcode_templ *) op;

  do {
    u_int16_t opce1;
    unsigned j;
    struct aau_reg *reg;

    free_als->need_ales = 1;
    free_als->ales.alef2.opce = NONE_VALUE;
    free_als->ales.alef2.opc2 = EXT_VALUE;

    free_als->need_mas = 1;
    /* MAS.mod == "special MMU/AAU" == 0x7,
       MAS.opc == "AAU reg operations" == 0x7  */
    free_als->mas = (0x7 << 3) | 0x7;

    slurp_char (&s, ' ');

    if (! parse_aau_reg (&s, &reg))
      break;

    opce1 = reg->reg << 2;

    if (reg->need_ind)
      opce1 |= reg->ind << 7;

    if (reg->need_d)
      opce1 |= reg->d << 11;

    for (j = 0; j < free_als->real_als_nmb; j++)
      {
	free_als->u[j].alf9.opce1_lo = opce1 & 0xff;
	free_als->u[j].alf9.opce1_hi = opce1 >> 8;
      }

    CHECK (parse_dst (&s, alf->arg_fmt));

    *pstr = s;
    return 1;

  }
  while (0);

  return 0;
}



static int
parse_alopf21_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alopf21_opcode_templ *alf = (const e2k_alopf21_opcode_templ *) op;

  free_als->need_ales = 1;
  free_als->ales.alef1.opc2 = alf->ales_opc2;

  do {
    CHECK (parse_src1 (&s, alf->arg_fmt[0]));
    CHECK_MSG (slurp_char (&s, ','),
               _("comma followed with src2 expected at `%s'"), s);
    CHECK (parse_src2 (&s, alf->arg_fmt[1]));
    CHECK (parse_src3 (&s, alf->arg_fmt[2], 1, 1));
    CHECK (parse_dst (&s, alf->arg_fmt[3]));

    if (alf->alopf == ALOPF21_MERGE)
      {
        e2k_pred mrg_pred;

        CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
        CHECK_MSG (parse_pred (&s, &mrg_pred, 1),
                   _("predicate expected at `%s'"), s);
        free_als->preds[1] = mrg_pred;
      }


    *pstr = s;
    return 1;
  }
  while (0);
  return 0;
}

static int
parse_merge_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;
  const e2k_alf1_opcode_templ *alf = (const e2k_alf1_opcode_templ *) op;

  /* Merge is definitely ALOPF1, so we don't need to check alf->alopf */

  do {
    e2k_pred mrg_pred;

    CHECK (parse_src1 (&s, alf->arg_fmt[0]));
    CHECK (slurp_char (&s, ','));
    CHECK (parse_src2 (&s, alf->arg_fmt[1]));
    CHECK (parse_dst (&s, alf->arg_fmt[2]));
    CHECK_MSG (slurp_char (&s, ','), _("comma expected at `%s'"), s);
    CHECK_MSG (parse_pred (&s, &mrg_pred, 1),
               _("predicate expected at `%s'"), s);

    free_als->preds[1] = mrg_pred;

    *pstr = s;
    return 1;
  }
  while (0);
  return 0;
}


/* These are to be moved to a more appropriate place.  */
int instruction_met = 0;
int parse_errors_met = 0;

int
parse_alf_args (char **pstr, const e2k_opcode_templ *op)
{
  static int (*parse_alf_fn[]) (char **, const e2k_opcode_templ *) = {
    [ALOPF1] = parse_alf1_args,
    [ALOPF2] = parse_alf2_args,
    [ALOPF3] = parse_alf3_args,
    [MMURR] = parse_mmurr_args,
    [MMURW] = parse_mmurw_args,
    [ALOPF7] = parse_alf7_args,
    [ALOPF17] = parse_alf7_args,
    [ALOPF8] = parse_alf8_args,
    [ALOPF19] = parse_alf19_args,
    [AAURR] = parse_aaurr_args,
    [ALOPF10] = parse_alf10_args,
    [AAURW] = parse_aaurw_args,
    [ALOPF11] = parse_alf1_args,
    [ALOPF11_LIT8] = parse_alopf11_lit8_args,
    [ALOPF11_MERGE] = parse_alf1_args,
    [ALOPF12] = parse_alf2_args,
    [ALOPF12_PSHUFH] = parse_pshufh_args,
    [ALOPF12_IBRANCHD] = parse_alf2_args,
    [ALOPF12_ICALLD] = parse_alf2_args,
    [ALOPF13] = parse_alf3_args,
    [ALOPF15] = parse_alf5_args,
    [ALOPF16] = parse_alf6_args,
    [ALOPF21] = parse_alopf21_args,
    [ALOPF21_MERGE] = parse_alopf21_args,
    [ALOPF22] = parse_alf2_args,
    [MERGE] = parse_merge_args
  };

  e2k_alf_opcode_templ *alf;
  char *s;

  gas_assert (free_als - &free_alses[0] <= 6);
  /* Don't even attempt to parse arguments of excessive instructions.  */
  if (free_als - &free_alses[0] == 6)
    {
      as_bad (_("An excessive ALF instruction"));
      parse_errors_met = 1;
      return 0;
    }

  alf = (e2k_alf_opcode_templ *) op;
  s = *pstr;
  
  if (last_ilabel)
    {
      free_als->label = last_ilabel;
      last_ilabel_used++;
    }

  /* See if this is a quad instruction requiring a pair of ALCes and assign
     them appropriately if so. The underlying actions are partially dependent
     on the current state of things in `e2k-opc.h' . . .  */
  if ((alf->alopf == ALOPF11
       && ((e2k_alopf11_opcode_templ *) alf)->arg_fmt[2] == QUAD)
      || ((alf->alopf == ALOPF2 || alf->alopf == ALOPF22)
	  && ((e2k_alf2_opcode_templ *) alf)->arg_fmt[1] == QUAD)
      || (alf->alopf == ALOPF12
	  && ((e2k_alopf12_opcode_templ *) alf)->arg_fmt[1] == QUAD))
    {
      free_als->real_als_nmb = 2;

      free_als->real_alses[0][0] = 0;
      free_als->real_alses[3][0] = 3;

      if (alf->allowed_channels[1])
	{
	  free_als->real_alses[0][1] = 1;
	  free_als->real_alses[1][0] = 0;
	  free_als->real_alses[1][1] = 1;

	  /* FIXME: GETSAP and stale GETSOD for which we find ourselves here
	     can be encoded in ALC{0,1} only, however, setting these redundant
	     values shouldn't hurt them . . .  */
	  free_als->real_alses[3][1] = 4;
	  free_als->real_alses[4][0] = 3;
	  free_als->real_alses[4][1] = 4;
	}
      else
	{
	  free_als->real_alses[0][1] = 2;
	  free_als->real_alses[2][0] = 0;
	  free_als->real_alses[2][1] = 2;

	  free_als->real_alses[3][1] = 5;
	  free_als->real_alses[5][0] = 3;
	  free_als->real_alses[5][1] = 5;
	}

      /* A load from `%qrX' should have the same SRC1 in each of a pair of
	 ALCes. Without stale `ldo*q' taken into account this should be only
	 `ldapq'.  */
      if (alf->alopf == ALOPF11
	  && alf->need_mas
	  && ((e2k_alopf11_opcode_templ *) alf)->arg_fmt[0] == QUAD)
	free_als->same_src1_quad = 1;
    }
  else if ((alf->alopf == ALOPF13
	    && ((e2k_alopf13_opcode_templ *) alf)->arg_fmt[2] == QUAD)
	   || ((alf->alopf == ALOPF10 || alf->alopf == AAURW)
	       && ((e2k_alf10_opcode_templ *) alf)->arg_fmt == QUAD)
	   || ((alf->alopf == AAURR
		|| alf->alopf == ALOPF19)
	       && ((e2k_alf9_opcode_templ *) alf)->arg_fmt == QUAD))
    {
      /* It's one of the quad stores (including STAAQ and AAURWQ) or either of
	 LDAAQ and AAURRQ  implemented only in `ALC{2,5}'. Interestingly enough
	 the latter two instructions look quite different from other quad loads
	 in this respect.  */
      free_als->real_als_nmb = 2;

      free_als->real_alses[2][0] = 2;
      free_als->real_alses[2][1] = 5;
      free_als->real_alses[5][0] = 2;
      free_als->real_alses[5][1] = 5;

      /* If `%qrX' is used as a destination, it should be encoded in the same
	 way in each ALC within a pair.  */
      if (((e2k_alopf11_opcode_templ *) alf)->arg_fmt[0] == QUAD)
	free_als->same_src1_quad = 1;
    }
  else
    {
      int i;

      free_als->real_als_nmb = 1;
      for (i = 0; i < 6; i++)
	free_als->real_alses[i][0] = i;
    }

  do {
    CHECK (parse_chn_optional (&s, alf, 0));
    CHECK (parse_sm_optional (&s));
    /* FIXME: this stupidly allows for `,sm' and `, chn' to be swapped.  */
    CHECK (parse_chn_optional (&s, alf, 1));

    /* Now remember explicitly specified ALCes containing speculative operations
       in the current wide instruction which may be referred to by potential
       `%dt_al[0][1][3][4]' control transfer conditions. Note that while
       `%dt_al' references to  non-speculative operations are not prohibited,
       their usage in this context doesn't make sense according to a note in
       C.17.1.2. Presumably such an operation will just cause an interrupt in
       case of a diagnostical operand and the related `%dt_al' condition will
       take no effect.  */
    if (free_als->plcmnt_nmb == 1 && free_als->u[0].alf1.opc.spec)
      {
        int pos = free_als->pos[0];
        wc.explicit_alces |= 1 << free_als->real_alses[pos][0];

        /* For quad operations consider the second ALC in a pair as explicit
           too.  */
        if (free_als->real_als_nmb == 2)
          wc.explicit_alces |= 1 << free_als->real_alses[pos][1];
      }




    /* Parse arguments. This is specific to a particular encoding.  */
    CHECK (parse_alf_fn[alf->alopf] (&s, op));

    /* The execution of `I{BRANCH,CALL}D' is controlled by `ct_cond', which
       has already been processed in `parse_alf2_args ()'. `alj_cond' is not
       applicable to these instructions and is said to result in `exc_illegal
       _opcode'. Therefore, don't attempt to parse it here.  */
    if (alf->alopf != ALOPF12_IBRANCHD && alf->alopf != ALOPF12_ICALLD)
      CHECK (parse_als_pred_optional (&s));

    /* At this point we have created a new ALS. It's possible to set an operation
       code and some other attributes now. I also set a so-called `finish function'
       that "finishes" the ALS when a position of a literal syllable it probably
       uses is known. */
    almost_finish_alf (alf);

    if (brace_cntr == 0 && !no_strict_delay)
      {
	/* `nop 5' should be implicitly appended to "braceless" `RW{s,d}'.  */
	if (alf->alopf == ALOPF15)
	  wc.nop_nmb = 5;
	/* ALOPF8 "braceless" `ccto*' instructions require `nop 2'.  */
	else if (alf->alopf == ALOPF8)
	  wc.nop_nmb = 2;
	/* We may have either `nop 2' or `nop 4' for comparisons at present
	   depending on whether it's an integer comparison or a floating-point
	   one. Let e2k-opcode generator specify the right number in an
	   instruction template.  */
	else if (alf->alopf == ALOPF7 || alf->alopf == ALOPF17)
	  wc.nop_nmb = ((e2k_alf7_opcode_templ *) alf)->implicit_nops;
      }

    *pstr = s;
    return 1;

  } while (0);

  /* This is to ensure that `free_als' gets increased in case an error was met
     while parsing. An attempt to reuse it for subsequent instructions may
     result in numerous assertion failures.  */
  almost_finish_alf (alf);
  return 0;
}

int
parse_incr_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *s = *pstr;
  unsigned i;
  int chn;
  unsigned incr;
  e2k_als *related_als;
  e2k_pred incr_pred;

  if (free_als == &free_alses[0])
    {
      as_bad (_("unexpected `incr'"));
      return 0;
    }

  related_als = free_als - 1;

  if (slurp_char (&s, ',')
      && parse_number (&s, &chn, sizeof (chn), 0))
    {
      if (related_als->pos[0] != chn)
        {
          as_bad (_("incorrect channel specified for `incr'"));
          return 0;
        }
    }

  slurp_char (&s, ' ');

  if (!slurp_str (&s, "%aaincr"))
    {
      as_bad (_("`%%aaincr' expected"));
      return 0;
    }

  if (! parse_number (&s, &incr, sizeof (incr), 0))
    {
      as_bad (_("index of `%%aaincr' expected"));
      return 0;
    }

  if (slurp_char (&s, '?')
      && parse_pred (&s, &incr_pred, 1))
    related_als->preds[3] = incr_pred;


  for (i = 0; i < related_als->real_als_nmb; i++)
    related_als->u[i].alf10.opce1_lo |= ((incr << 4) | 0x4);

  *pstr = s;
  return 1;
}


int
parse_copf2_args (char **pstr, const e2k_opcode_templ *op)
{
  e2k_copf2_opcode_templ *copf2 = (e2k_copf2_opcode_templ *) op;
  char *s = *pstr;

  do
    {
      start_cs0 ();

      if (wc.cs0.set)
        {
          as_bad (_("cannot encode `%s': CS0 in the current wide instruction "
		    "is already busy"), copf2->name);
          break;
        }

      wc.cs0.val.fields.ctp_opc =  copf2->ctp_opc;

      if (copf2->allowed_ctprs[0]
	  || copf2->allowed_ctprs[1]
	  || copf2->allowed_ctprs[2])
        {
          u_int8_t ctprn;
          CHECK_MSG (slurp_str (&s, "%ctpr"), _("%%ctpr expected "));
          CHECK_MSG (parse_number (&s, &ctprn, sizeof (ctprn), 0),
		     _("cannot see %%ctpr number"));

          CHECK_MSG ((ctprn >= 1) && (ctprn <= 3),
		     _("invalid %%ctpr%d specified"), ctprn);

	  CHECK_MSG (copf2->allowed_ctprs[ctprn - 1],
		     _("%%ctpr%d is not supported by %s"), ctprn, op->name);
          wc.cs0.val.fields.ctpr = ctprn;
        }

      if (copf2->label_expected)
        {
          char *save_input_line_pointer;

          slurp_char (&s, ',');

          /* FIXME: stupidly allow for an optional `disp=' before an immediate
             displacement value, i.e. `disp %ctprX, disp=D' (see C.15.1). Note
             that unlike LAS I currently allow to specify an immediate
             displacement without preceding `disp='. Moreover, now it becomes
             possible to specify `disp=label'. These familiarities should be
             better prohibited as well as specifying a label as an argument to
             SDISP  .*/
          slurp_str (&s, "disp=");

          save_input_line_pointer = input_line_pointer;
          input_line_pointer = s;
          expression (&cs0_exp);
          s = input_line_pointer;
          input_line_pointer = save_input_line_pointer;

          if (cs0_exp.X_op == O_constant)
            {
              /* FIXME: verify CS0.disp in SDISP somehow for the sake of
		 Bug #83996.  */
              if (copf2->ctp_opc == 2 && (cs0_exp.X_add_number < 0
                                          || cs0_exp.X_add_number >= 32))
                {
                  as_bad (_("invalid value for CS0.disp in SDISP specified"));
                  return 0;
                }

              /* There is no point for not setting CS0.disp now. Is
                 it supposed that the user has already divided
                 displacement by eight? */
              wc.cs0.val.fields.disp = (u_int32_t) cs0_exp.X_add_number;
            }
          else if (cs0_exp.X_op == O_symbol || cs0_exp.X_op == O_plt)
            {
	      if (copf2->ctp_opc == 2)
		{
		  as_bad (_("CS0.disp in SDISP should encode an immediate "
			    "value"));
		  return 0;
		}

              /* We'll probably need a relocation. */
              wc.cs0.pexp = &cs0_exp;
            }
	  else
	    {
	      as_bad (_("invalid expression at `%s'"), input_line_pointer);
	      return 0;
	    }
        }
      else
        {
          /* FIXME: here CS0.param.type is set for COPF1 RETURN and GETTSD
	     operations according to Table B.4.1.1 in fact.
	     FIXME: a better way of distinguishing between RETURN and GETTSD
	     instead of checking for the first letter in the name should be
	     implemented.  */
          wc.cs0.val.fields.disp = op->name[0] == 'r' ? 0 : 1;
        }

      wc.cs0.set = 1;

      *pstr = s;
      return 1;
    }
  while (0);
  return 0;
}

int
parse_pref_args (char **pstr,
                 const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *s = *pstr;

  do
    {
      u_int8_t iprn, ipd = 0;
      u_int32_t pdisp = 0;
      char *save_input_line_pointer;

      start_cs0 ();

      if (wc.cs0.set)
        {
          as_bad (_("cannot encode `pref', CS0 in the current wide command is "
                    "already busy"));
          break;
        }

      /* See ctp_opc and ctpr for PREF in Table B.4.1.  */
      wc.cs0.val.fields.ctp_opc = 1;
      wc.cs0.val.fields.ctpr = 0;

      CHECK_MSG (slurp_str (&s, "%ipr"), _("%%ipr expected "));
      CHECK_MSG (parse_number (&s, &iprn, sizeof (iprn), 0),
                 _("cannot see index for %%ipr"));
      CHECK_MSG (iprn <= 7, _("invalid index for %%ipr"));

      slurp_char (&s, ',');

      /* FIXME: stupidly allow for an optional `disp=' before an immediate
         displacement value, i.e. `disp %ctprX, disp=D' (see C.15.1). Note
         that unlike LAS I currently allow to specify an immediate
         displacement without preceding `disp='. Moreover, now it becomes
         possible to specify `disp=label'. These familiarities should be
         better prohibited as well as specifying a label as an argument to
         SDISP  .*/
      slurp_str (&s, "disp=");

      save_input_line_pointer= input_line_pointer;
      input_line_pointer = s;
      expression (&cs0_exp);
      s = input_line_pointer;
      input_line_pointer = save_input_line_pointer;

      if (slurp_str (&s, ",ipd="))
        {
          CHECK_MSG (parse_number (&s, &ipd, sizeof (ipd), 0),
                     _("cannot see value of ipd"));
          CHECK_MSG (ipd <= 1, _("invalid value for ipd"));
        }

      if (cs0_exp.X_op == O_constant)
        {
          /* There is no point for not setting CS0.disp now. Is
             it supposed that the user has already divided
             displacement by eight? */
          pdisp = (u_int32_t) cs0_exp.X_add_number;
        }
      else if (cs0_exp.X_op == O_symbol)
        {
          /* We'll probably need a relocation. */

          /* Adjust X_op according to our needs. It'll be used later when
             deciding which relocation to emit. Note, that we've not introduced
             a special `sym@PREF' syntax. I wonder if it was a right
             decision . . .  */
          cs0_exp.X_op = O_pref;
          wc.cs0.pexp = &cs0_exp;
        }

      /* See C.15.8. Note, that for PREF this field of C0F1 is actually called
         `param', it occupies the same bits as `disp' in C0F2.  */
      wc.cs0.val.fields.disp = (pdisp << 4) + (ipd << 3) + iprn;

      wc.cs0.set = 1;

      *pstr = s;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_nop_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *s = *pstr;
  do
    {
      if (s[0] != '\0')
        {
          CHECK_MSG (parse_number (&s, &wc.nop_nmb, sizeof(wc.nop_nmb), 0), _("number expected"));
          CHECK_MSG (wc.nop_nmb <= 7, _("illegal nop number"));
        }
      else
        wc.nop_nmb = 0xff;

      CHECK_MSG (s[0] == 0, _("unexpected symbol"));

      *pstr = s;
      return 1;
    }
  while (0);

  return 0;
}



unsigned setcmd_masks[] = {

#define SETBN_IDX       0
#define RSZ_MASK        0x3f
  RSZ_MASK,
#define RBS_MASK        0x3f
  RBS_MASK,
#define RCUR_MASK       0x3f
  RCUR_MASK,

#define SETBP_IDX       3
#define PSZ_MASK        0x1f
  PSZ_MASK,

#define SETTR_IDX       4
#define TYPE_MASK       ((1 << 15) - 1)
  TYPE_MASK,

#define SETWD_IDX       5
#define WSZ_MASK        0x7f
  WSZ_MASK,
#define NFX_MASK        0x1
  NFX_MASK,
#define DBL_MASK        0x1
  DBL_MASK,


#define VFRPSZ_IDX      8
#define RPSZ_MASK       0x1f
  RPSZ_MASK,

#define SETEI_IDX       9
#define SETEI_MASK      0xff
  SETEI_MASK
};

int
parse_setcmd_args (char **pstr, const e2k_opcode_templ *op)
{
  static const char *cmd_name[] = {"setbn", "setbp", "settr", "setwd",
                                   "vfrpsz", "setei"};

  static const char *param_str[] = {
    "rsz=", "rbs=", "rcur=", "psz=", "type=", "wsz=", "nfx=", "dbl=", "rpsz=",

    /* For SETEI there's no specifier before its parameter according to
       iset.single.  */
    ""
  };
  static unsigned param_dnlim[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0};

  const char *param_err[] = {
    _("rotated register area size"),
    _("rotated register area base"),
    _("current value of rotated register area base"),
    _("rotated predicate area size"),
    _("current type"), 
    _("register window size"),
    _("nfx value"),
    _("dbl value"),
    _("register parameter size"),
    _("exception info register")
  };

  unsigned lo_idx[] = {SETBN_IDX, SETBP_IDX, SETTR_IDX, SETWD_IDX,
                       VFRPSZ_IDX, SETEI_IDX};
  unsigned hi_idx[] = {SETBN_IDX + 2, SETBP_IDX, SETTR_IDX,
                       SETWD_IDX + (mcpu >= 3 ? 2 : 1),
                       VFRPSZ_IDX, SETEI_IDX};

  char *str = *pstr;
  do
    {
      unsigned i, j;
      unsigned id = ((e2k_setcmd_opcode_templ *) op)->id;
      int param_cntr = 0;

      if ((wc.setcmd_args[lo_idx[id]] & ~setcmd_masks[lo_idx[id]]) == 0)
        {
          /* We must have already seen this command. FIXME: how are you going
             to catch this case if the first parameter of a set command hasn't
             been explicitly specified? Shouldn't I have a loop over all
             supported parameters here instead?  */
          as_bad ("a wide command cannon contain more than one instance of %s",
                  cmd_name[id]);
          return 0;
        }

      for (i = lo_idx[id]; i <= hi_idx[id]; i++)
        {
          for (j = lo_idx[id]; j <= hi_idx[id]; j++)
            {
              if (slurp_str (&str, param_str[j]))
                {
                  /* FIXME: the value 2 of SGND parameter is a hack which lets
                     me parse a numeric expression rather than just a raw
                     number.  */
                  if (! parse_number (&str, &wc.setcmd_args[j],
                                      sizeof (wc.setcmd_args[j]), 2))
                    {
                      as_bad (_("value for %s expected%s%s"), param_err[j],
                              param_str[j][0] != '\0' ? " after " : "",
                              param_str[j]);
                      break;
                    }

                  if (! ((wc.setcmd_args[j] >= param_dnlim[j])
                        && (wc.setcmd_args[j] <= (param_dnlim[j] + setcmd_masks[j]))))
                    {
                      as_bad (_("invalid value for %s"), param_err[j]);
                      break;
                    }

                  wc.setcmd_args[j] -= param_dnlim[j];
                  param_cntr++;

                  slurp_char (&str, ',');
                  break;
                }
            }
          if ((j <= hi_idx[id]) && (wc.setcmd_args[j] & ~setcmd_masks[j]))
            /* We've seen something invalid. A message has already
               been output. */
            return 0;
          else if (j > hi_idx[id])
            {
              if (str[0] != '\0')
                {
                  as_bad (_("invalid parameter `%s'\n"), str);
                  return 0;
                }
              /* Allow less parameters than specified in param_str for each
                 instruction. Hope that not specified ones either will be
                 set to their default values (like nfx for setwd) or an
                 error message will be output if a default value does not
                 exist. In any case I believe that no parameters is
                 certainly a crime. */
              else if (param_cntr == 0)
                {
                  as_bad (_("no parameters for `%s'\n"), cmd_name[id]);
                  return 0;
                }

              /* Break to successfull `return 1' below if there are less
                 parameters than the maximal supported number.  */
              break;
            }
        }
    }
  while (0);

  *pstr = str;
  return 1;
}

int
parse_setsft_args (char **pstr ATTRIBUTE_UNUSED,
		   const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  wc.setsft_seen = 1;
  return 1;
}

int
parse_wait_args (char **pstr,
                 const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  static const char *param[14] = {
    "all_c=", "all_e=", "st_c=", "ld_c=", "fl_c=", "ma_c=", "trap=",
    /* These have been added starting from elbrus-v5.  */
    "sas=", "sal=",
    /* These are available in elbrus-v6.  */
    "las=", "lal=", "mt=", "int=", "mem_mod="
  };

  /* This array is used to track if the corresponding parameter has been
     specified explicitly.  */
  int val[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

  char *str = *pstr;

  do
    {
      int i;
      int invalid_comb;
      int n_params = sizeof (param) / sizeof (param[0]);
      u_int32_t cs1_param = 0x0;

      for (i = 0; i < n_params; i++)
        {
          int j;

          for (j = 0; j < n_params; j++)
            {
              if (slurp_str (&str, param[j]))
                {
                  u_int8_t param_val;

		  /* FIXME: this a temporary assert inserted simultaneously
		     with the elimination of `mcpu < 2' case from the runtime
		     condition below.  */
		  gas_assert (mcpu >= 2);

                  if ((mcpu < 5 && j > 6)
		      || (mcpu < 6 && j > 8))
                    {
                      as_bad (_("Invalid `%s' WAIT parameter for %s"), param[j],
                              cpu_name ());
                      return 0;
                    }

                  if (! parse_number (&str, &param_val, sizeof (param_val), 0)
                      || (param_val != 0 && param_val != 1))
                    {
                      as_bad (_("%s{0,1} expected"),  param[j]);
                      return 0;
                    }

                  val[j] = param_val;
                  cs1_param |= (param_val << j);
                  slurp_char (&str, ',');
                  break;
                }
            }

          if (j == n_params)
            {
              if (str[0] != '\0')
                {
                  as_bad (_("junk in WAIT command: `%s'\n"), str);
                  return 0;
                }

              if (cs1_param == 0x0)
                {
                  as_bad (_("no parameters specified for WAIT command\n"));
                  return 0;
                }

              break;
            }
        }

      /* Take a special care of `{s,l}a{s,l} = 1' according to C.22.1 (see also
	 Bug #83566): ensure that `{st,ld}_c' is set to `1' in case it hasn't
	 been explicitly set this way by the user. Emit an error on illegal
	 combination of WAIT flags in case the user has explicitly set it to
	 zero.  */

      /* This variable makes it possible to barf on all encountered invalid
	 combinations of WAIT parameters, not just the first one.  */
      invalid_comb = 0;
      for (i = 7; i <= 10; i++)
        {
	  /* J refers to either of `st_c' or `ld_c' whichever is
	     appropriate.  */
	  int j = i < 9 ? i - 5 : i - 7;
          if (val[i] == 1)
            {
              if (val[j] == -1)
                cs1_param |= 1 << j;
              else if (val[j] == 0)
                {
                  as_bad (_("invalid combination of `%s0' and `%s1' WAIT "
                            "flags"), param[j], param[i]);
                  invalid_comb = 1;
                }
            }
        }

      if (invalid_comb)
	return 0;

      start_cs1 ();
      if (wc.cs1.set)
        {
          as_bad (_("Cannot encode WAIT because CS1 is busy"));
          return 0;
        }

      /* CALL probably occupies the same fields in CS1 as WAIT. Use them
         temporarely. I should probably invent `wc.cs1.val.fields.wait. . .'
         or rename `wc.cs1.val.fields.call. . .' to something more general.  */
      wc.cs1.set = 1;
      wc.cs1.val.fields.call.opc = 0x3;
      wc.cs1.val.fields.call.param = cs1_param;
    }
  while (0);

  *pstr = str;
  return 1;
}

int
parse_copf4_args (char **pstr ATTRIBUTE_UNUSED, const e2k_opcode_templ *op)
{
  start_cs1 ();
  if (wc.cs1.set && wc.cs1.val.fields.call.opc != 0x7)
    {
      as_bad (_("Cannot encode `%s' because CS1 is busy"), op->name);
      return 0;
    }

  /* 0x7 stands for FLUSHR here, see table B.4.2 in iset.single.  */
  wc.cs1.val.fields.call.opc = 0x7;

  if (strcmp (op->name, "flushr") == 0)
    wc.cs1.val.fields.call.param |= 1;
  else if (strcmp (op->name, "flushc") == 0)
    wc.cs1.val.fields.call.param |= 2;
  else if (strcmp (op->name, "fillr") == 0)
    wc.cs1.val.fields.call.param |= 4;
  /* This should be `fillc'.  */
  else
    wc.cs1.val.fields.call.param |= 8;

  wc.cs1.set = 1;

  return 1;
}


static int
parse_ctpr (char **pstr, u_int8_t *pctprn)
{
  char *s = *pstr;
  do
    {
      CHECK_MSG (slurp_str (&s, "%ctpr"), _("`%%ctpr{1,2,3}' expected"));
      CHECK_MSG (parse_number (&s, pctprn, sizeof (*pctprn), 0)
                 && (*pctprn >= 1) && (*pctprn <= 3),
                 _("invalid `%%ctpr' number (should be 1, 2 or 3)"));
      *pstr = s;
      return 1;
    }
  while (0);
  return 0;
}

static int
slurp_ct_subcond (char **pstr, const char *operator, const char *subcond)
{
  char *s = *pstr;

  if (operator && operator[0] != '\0')
    {
      if (! slurp_str (&s, operator))
        return 0;
    }

  if (! slurp_char (&s, '%') && ! slurp_char (&s, '#'))
    return 0;

  if (! slurp_str (&s, subcond))
    return 0;

  *pstr = s;
  return 1;
}

static int
parse_pl_ctcond (char **pstr, u_int32_t *psrc)
{
  char *s = *pstr;
  int neg = 0;

  if (slurp_char (&s, '~'))
    neg = 1;

  if (slurp_str (&s, "%cmp"))
    {
      u_int32_t cmp_jk;

      if ((slurp_str (&s, "0||") && (cmp_jk = 0, 1))
          || (slurp_str (&s, "3||") && (cmp_jk = 1, 1)))
        {
          u_int32_t negj = neg;
          u_int32_t negk = 0;

          if (slurp_char (&s, '~'))
            negk = 1;

          if (slurp_str (&s, "%cmp")
              && slurp_char (&s, cmp_jk == 0 ? '1' : '4'))
            {
              *psrc = (0x1 << 3) | (cmp_jk << 2) | (negj << 1) | negk;
              *pstr = s;
              return 1;
            }
        }
      else if (s[0] == '0' || s[0] == '1' || s[0] == '3' || s[0] == '4')
        {
          char c = s[0];
          *psrc = (0x0 << 3) | neg;

          if (c == '0' || c == '1')
            *psrc |= (c - '0') << 1;
          else if (c == '3' || c == '4')
            *psrc |= (c - '0' - 1) << 1;

          *pstr = ++s;
          return 1;
        }
    }
  else if (slurp_str (&s, "%clp") && s[0] >= '0' && s[0] <= '2')
    {
      *psrc = (0x2 << 3) | ((s[0] - '0') << 1) | neg;

      *pstr = ++s;
      return 1;
    }

  return 0;
}

static int
parse_ctcond (char **pstr, int ibranch)
{
  char *s = *pstr;
  e2k_pred pred;
  u_int32_t psrc;

  int parsed;

  do
    {
      if (! slurp_char (&s, '?'))
        {
          if (! is_end_of_line[(unsigned char) *s])
            {
              as_bad ("end of line expected");
              return 0;
            }

          /* If a user does not specify condition this means that
             he specifies `always' explicitly rather than implicitly
             and this cannot be overriden by other short commands. */
          SET_FIELD (ss, ctcond,
                     ibranch == RBRANCH ? CTCOND_MLOCK : CTCOND_ALWAYS, 0);
          return 1;
        }

      if (slurp_ct_subcond (&s, "", "always"))
        {
          SET_FIELD (ss, ctcond, CTCOND_ALWAYS, 0);
        }
      else if (slurp_ct_subcond (&s, "", "never"))
        {
          SET_FIELD (ss, ctcond, CTCOND_NEVER, 0);
        }
      else if (slurp_ct_subcond (&s, "", "LOOP_END"))
        {
          SET_FIELD (ss, ctcond, CTCOND_LOOP_END, 0);
        }
      else if (slurp_ct_subcond (&s, "", "NOT_LOOP_END"))
        {
          SET_FIELD (ss, ctcond, CTCOND_NOT_LOOP_END, 0);
        }
      else if ((parsed = slurp_ct_subcond (&s, "", "MLOCK"))
               || ibranch == RBRANCH )
        {
          /* There is no point in allowing for `%%MLOCK' after rbranch.  */
          if (parsed && ibranch != IBRANCH)
            {
              as_bad (_("%%MLOCK control transfer condition is applicable"
                        " only to ibranch"));
              break;
            }

          if (ibranch == RBRANCH || slurp_str (&s, "||"))
            {
              if (slurp_ct_subcond (&s, "", "dt_al"))
                {
                  static int conv[5] = {0, 1, -1, 2, 3};
                  unsigned mask = 0;
                  int i;

                  for (i = 0; i < 5; i++)
                    {
                      if (conv[i] == -1)
                        continue;

                      if (slurp_char (&s, '0' + i))
                        mask = mask | (1 << conv[i]);
                    }

                  if (mask == 0)
                    {
                      as_bad (_("index of form `[0][1][3][4]' expected after "
                                "`%%dt_al'"));
                      break;
                    }

                  /* See C.17.1.2 for encoding of `dt_cond'.  */
                  SET_FIELD (ss, ctcond,
                             ((ibranch == RBRANCH ? CTCOND_MLOCK : 0)
                              | ((8 << 5) + mask)),
                             0);
                }
              else if (mcpu >= 3 && parse_pl_ctcond (&s, &psrc))
                {
                  SET_FIELD (ss, ctcond,
                             ((ibranch == RBRANCH ? CTCOND_MLOCK : 0)
                              | (9 << 5) | psrc), 0);
                }
              else
                {
                  as_bad (_("invalid control transfer condition `%s' "
                            "after %s"),
                          s,
                          (ibranch == RBRANCH
                           ? "rbranch" : "ibranch %MLOCK ||"));
                  break;
                }
            }
          else
            SET_FIELD (ss, ctcond, CTCOND_MLOCK, 0);
        }
      else if (parse_pred (&s, &pred, 0))
        {
          u_int32_t ctcond;

          if (slurp_ct_subcond (&s, "||", "LOOP_END"))
            ctcond = pred.negated ? (0xe << 5) : (0x6 << 5);
          else if (slurp_ct_subcond (&s, "&&", "NOT_LOOP_END"))
            ctcond = pred.negated ? (0x7 << 5) : (0xf << 5);
          else
            ctcond = pred.negated ? CTCOND_NEG_PRED : CTCOND_PRED;

          SET_FIELD (ss, ctcond, ctcond | pred.pred_num, 0);
        }
      else
        {
          as_bad (_("invalid control transfer condition `%s'"), s);
          break;
        }

      *pstr = s;
      return 1;
    }
  while (0);
  
  return 0;
}

int
parse_ct_args (char **pstr, const e2k_opcode_templ *op)
{
  char *str = *pstr;

  start_ss_syllable (1);
  do
    {
      u_int8_t ctprn;

      CHECK (parse_ctpr (&str, &ctprn));

      wc.ss.val.fields.ctop = ctprn;

      if (strcmp (op->name, "call") == 0)
        {
          u_int8_t wbs;

          slurp_char (&str, ',');

          /* Should I really consider it optional?  */
          slurp_str (&str, "wbs=");

          /* FIXME: use of `SGND' parameter equal to `2' here is a hack which
             lets me handle the case of WBS being an expression, e.g.,
             `call %ctprX, wbs = 16 - 4'.  */
          CHECK_MSG (parse_number (&str, &wbs, sizeof (wbs), 2),
                     _("wbs value expected"));

          start_cs1 ();
          if (wc.cs1.set)
            {
              as_bad (_("Cannot encode `%s': CS1 is busy"), op->name);
              return 0;
            }

          wc.cs1.set = 1;
          wc.cs1.val.fields.call.opc = 5;
          wc.cs1.val.fields.call.param = wbs;
        }

      /* Can call be followed by ctcond at all? Certainly it can.  */
      if (! parse_ctcond (&str, 0))
        break;

      /* Set ipd to 2 by default (in case ct is not blocked by %never).
         This value can be overriden by ipd short command. */
      if ((wc.ss.val.fields.ctcond & CTCOND_MASK) != CTCOND_NEVER)
        {
          SET_FIELD (ss, ipd, default_ipd, 1);
        }

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_hicall_args (char **pstr, const e2k_opcode_templ *op)
{
  char *str = *pstr;

  start_ss_syllable (1);
  do
    {
      u_int8_t wbs;
      char *save_input_line_pointer;
      int is_hcall = (op->name[0] == 'h');
      wc.ss.val.fields.ctop = 0;

      save_input_line_pointer = input_line_pointer;
      input_line_pointer = str;
      expression (&cs0_exp);
      str = input_line_pointer;
      input_line_pointer = save_input_line_pointer;
      
      slurp_char (&str, ',');

      if (wc.cs0.set)
        {
          as_bad (_("cannot encode `pref', CS0 in the current wide command is "
                    "already busy"));
          break;
        }

      if (cs0_exp.X_op == O_constant)
	{
	  /* Check the value of hdisp parameter of HCALL. Note that it's encoded
	     in `CS0.disp[4:1]' unlike sdisp which is encoded in
	     `CS0.disp[4:0]'. This is taken into account below . . .  */
	  if (is_hcall && (cs0_exp.X_add_number < 0
			   || cs0_exp.X_add_number >= 16))
	    {
	      as_bad (_("invalid value for CS0.disp in HCALL specified"));
	      return 0;
	    }

	  wc.cs0.val.fields.disp = (u_int32_t) cs0_exp.X_add_number;
	  /* . . . by shifting the parsed hdisp value (but not the disp one
	     for ICALL!) by one bit to the left.  */
	  if (is_hcall)
	    wc.cs0.val.fields.disp <<= 1;
	    
	}
      else if (cs0_exp.X_op == O_symbol || cs0_exp.X_op == O_plt)
	{
	  if (is_hcall)
	    {
	      as_bad (_("CS0.disp in HCALL should encode an immediate "
			"value"));
	      return 0;
	    }

	  /* We'll probably need a relocation. */
	  wc.cs0.pexp = &cs0_exp;
	}
      else
	{
	  as_bad (_("invalid expression at `%s'"), input_line_pointer);
	  return 0;
	}


      /* Encode `CS0.ctp_opc = {H,I}CALL == 0' (see Table B.4.1).  */
      wc.cs0.val.fields.ctp_opc = 0;
      wc.cs0.set = 1;

      /* Should I really consider it optional?  */
      slurp_str (&str, "wbs=");

      /* FIXME: use of `SGND' parameter equal to `2' here is a hack which
	 lets me handle the case of WBS being an expression, e.g.,
	 `call %ctprX, wbs = 16 - 4'.  */
      CHECK_MSG (parse_number (&str, &wbs, sizeof (wbs), 2),
		 _("wbs value expected"));

      start_cs1 ();
      if (wc.cs1.set)
	{
	  as_bad (_("Cannot encode `%s': CS1 is busy"), op->name);
	  return 0;
	}

      wc.cs1.set = 1;
      wc.cs1.val.fields.call.opc = 5;
      /* Set CS1.param.wbs and `CS1.param.ctopc = {H,I}CALL == {2,1}'
	 (see Table B.4.2.1).  */
      wc.cs1.val.fields.call.param = ((is_hcall ? 2 : 1) << 7) | wbs;

      /* Can call be followed by ctcond at all? Certainly it can.  */
      if (! parse_ctcond (&str, 0))
        break;

      /* Set ipd to 2 by default (in case ct is not blocked by %never).
         This value can be overriden by ipd short command. */
      if ((wc.ss.val.fields.ctcond & CTCOND_MASK) != CTCOND_NEVER)
        {
          SET_FIELD (ss, ipd, default_ipd, 1);
        }

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}


int
parse_ibranch_args (char **pstr, const e2k_opcode_templ *op)
{
  char *s = *pstr;

  do
    {
      char *save_input_line_pointer;

      start_ss_syllable (1);

      if (wc.ss.set.ctop)
        {
          as_bad (_("cannot encode `%s', SS.ctop in the current wide command is already busy"), op->name);
          break;
        }
      SET_FIELD (ss, ctop, 0, 0 /* non-default */);

      start_cs0 ();

      if (wc.cs0.set)
        {
          as_bad (_("cannot encode `%s', CS0 in current wide command is already busy"), op->name);
          break;
        }

      wc.cs0.val.fields.ctp_opc = 0;
        
      slurp_char (&s, ',');
      save_input_line_pointer= input_line_pointer;
      input_line_pointer = s;
      expression (&cs0_exp);
      s = input_line_pointer;
      input_line_pointer = save_input_line_pointer;

      if (cs0_exp.X_op == O_constant)
        {
          /* There is no point for not setting CS0.disp now. Is
             it supposed that the user has already divided
             displacement by eight? */
          wc.cs0.val.fields.disp = (u_int32_t) cs0_exp.X_add_number;
        }
      else if (cs0_exp.X_op == O_symbol)
        {
          /* We'll probably need a relocation. */
          wc.cs0.pexp = &cs0_exp;
        }

      if (strcmp (op->name, "ibranch") == 0)
        {
          if (! parse_ctcond (&s, IBRANCH))
            break;
        }
      else if (strcmp (op->name, "rbranch") == 0)
        {
          if (! parse_ctcond (&s, RBRANCH))
            break;
        }
      else
        {
          as_bad (_("unexpected instruction `%s'"), op->name);
        }

      wc.cs0.set = 1;

      if ((wc.ss.val.fields.ctcond & CTCOND_MASK) != CTCOND_NEVER)
        {
          SET_FIELD (ss, ipd, default_ipd, 1);
        }


      *pstr = s;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_done_hiret_glaunch_args (char **pstr,
			       const e2k_opcode_templ *op)
{
  char *s = *pstr;

  /* REMINDER: this call is crucial even if no condition is explicitly applied
     to DONE as it currently happens to be in E2K Linux Kernel. It ensures that
     CTCOND_ALWAYS will be encoded in such a case.  */
  if (! parse_ctcond (&s, 0))
    return 0;

  start_ss_syllable (1);
  SET_FIELD (ss, ctop, 0, 0 /* non-default */);

  start_cs0 ();
  if (wc.cs0.set)
    {
      as_bad (_("cannot encode `DONE', CS0 in current wide command is already "
                "busy"));
      return 0;
    }

  /* According to Table B.4.1 in iset.single providing the values to be encoded
     in CS0.ctp_opc `DONE == IRET == HRET == GLAUNCH == 3', whereas the only
     option for CS0.ctpr is 0.  */
  wc.cs0.val.fields.ctpr = 0;
  wc.cs0.val.fields.ctp_opc = 3;

  /* If this is either of {H,I}RET or GLAUNCH take care of setting
     CS0.param.type  according to Table B.4.1.1 (FIXME: this field is to be
     introduced yet, below I make use of the fact that it occupies the same
     bits as CS0.disp). Otherwise silently leave `CS0.disp' equal to zero for
     DONE. Note that DONE has C0F2 format unlike the first two instructions.
     Hardly can I understand what role `disp' value can play for it. Moreover,
     it's not prescribed by our iset.  */
  if (op->name[0] == 'i')
    wc.cs0.val.fields.disp = 2;
  else if (op->name[0] == 'h')
    wc.cs0.val.fields.disp = 3;
  else if (op->name[0] == 'g')
    wc.cs0.val.fields.disp = 4;

  wc.cs0.set = 1;

  if ((wc.ss.val.fields.ctcond & CTCOND_MASK) != CTCOND_NEVER)
    {
      SET_FIELD (ss, ipd, default_ipd, 1);
    }

  *pstr = s;
  return 1;
}

int
parse_ipd_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;

  start_ss_syllable (1);
  do
    {
      u_int8_t ipd;
      CHECK_MSG (parse_number (&str, &ipd, sizeof (ipd), 0), _("ipd value expected after `ipd'"));
      if (ipd > 3)
        {
          as_bad (_("invalid ipd value %u; should be < 3"), (u_int32_t) ipd);
          break;
        }

      /* Allow a stupid user (or our stupid compiler to explicitly set the same
         value for IPD multiple times within the same wide command (see commits
         to ecomp related to Bug #82373). Attempt to set IPD if it hasn't been
         set at all, set to a default value or set to a different value. In the
         latter case a user is likely to obtain a error, but these are his
         problems.  */
      if (wc.ss.set.ipd == 0
          || wc.ss.dflt.ipd == 1
          || wc.ss.val.fields.ipd != ipd)
        {
          SET_FIELD (ss, ipd, ipd, 0);
        }

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

/* Allow for aliases. Currently the only valid ones are `{ld,st}L{c,d,s,f,g}s
   {b,h,w,d,q,qp}' for `elbrus-v{X>=3}' listed in Bug #52651. This idiotism is
   required for the sake of our binary compiler.  */
static const char *
real_insn_name (const char *name)
{
  static char real_name[7];

  /* Stupidly replace `apur{r,w}X' instructions with their more custom
     `aaur{r,w}X' counterparts.  */
  if (name[0] == 'a' && name[1] == 'p' && name[2] == 'u' && name[3] == 'r'
      && (name[5] == '\0' || name[6] == '\0'))
    {
      strncpy (real_name, name, 7);
      real_name[1] = 'a';
      return real_name;
    }

  if (mcpu < 3)
    return name;

  if ((name[0] != 'l' || name[1] != 'd') && (name[0] != 's' || name[1] != 't'))
    return name;

  if (name[2] != 'l')
    return name;

  if ((name[3] != 'c' && name[3] != 'd' && name[3] != 's' && name[3] != 'f'
       && name[3] != 'g')
      || name[4] !=  's')
    return name;

  /* FIXME: currently I'm too lazy to check for format . . .  */

  strncpy (&real_name[2], &name[3], 5);
  real_name[0] = name[0];
  real_name[1] = name[1];
  return real_name;
}

static inline int
slurp_fmt (const char *s, int *pref, int *prow, int *plen)
{
  int ret = 0;
  int row;
  int ref = 0;
  int len;
  
  if (s[0] != '_')
    return 0;
  
  if (s[1] == 'f')
    {
      int i = 4;
      if (s[2] == '1' && s[3] == '6')
        {
          if (s[4] == 's')
            i = 5;

          /* Don't rush to set `prow' here: we may very well fail
             later.  */
          row = LITERAL_16;
        }
      else if (s[2] == '3' && s[3] == '2')
        {
          if (s[4] == 's')
            i = 5;

          row = LITERAL_32;
        }
      else if (s[2] == '6' && s[3] == '4')
        row = LITERAL_64;
      else
        return 0;

      if (s[i] == ' ')
        {
          len = i + 1;
          ret = 1;
        }
      else if (s[i] == '(' || s[i] == '[')
        {
          len = i;
          ret = 1;
        }
      else if (s[i] == ',')
        {
          len = i + 1;
          ret = 2;
        }
      else
        return 0;

    }
  else if (s[1] == 'l' && s[2] == 'i' && s[3] == 't' && s[6] == '_'
           && s[7] == 'r'  && s[8] == 'e' && s[9] == 'f')
    {
      if (s[10] == ' ')
        {
          len = 11;
          ret = 1;
        }
      else if (s[10] == '(' || s[10] == '[')
        {
          len = 10;
          ret = 1;
        }
      else if (s[10] == ',')
        {
          len = 11;
          ret = 2;
        }
      else
        return 0;

      ref = 1;

      if (s[4] == '1' && s[5] == '6')
        row = LITERAL_16;
      else if (s[4] == '3' && s[5] == '2')
        row = LITERAL_32;
      else if (s[4] == '6' && s[5] == '4')
        row = LITERAL_64;
      else
        return 0;
    }
  else
    return 0;

  gas_assert (ret == 1 || ret == 2);

  *pref = ref;
  *prow = row;
  *plen = len;

  return ret;
}

static inline int
slurp_lts (const char *s, int *pmin_col, int *pmax_col, int *plen)
{
  int ret = 0;
  int idx;
  int min, max;
  int len;
  int i;
  
  if (s[0] != '_' || s[1] != 'l' || s[2] != 't' || s[3] != 's')
    return 0;

  idx = s[4] - '0';

  if (s[4] == '0' || s[4] == '1')
    {
      if (s[5] == 'l' && s[6] == 'o')
        {
          min = max = 2 * idx;
          i = 7;
        }
      else if (s[5] == 'h' && s[6] == 'i')
        {
          min = max = 2 * idx + 1;
          i = 7;
        }
      else
        {
          min = 2 * idx;
          max = 2 * idx + 1;
          i = 5;
        }
    }
  else if (s[4] == '2' || s[4] == '3')
    {
      min = max = 2 * idx;
      i = 5;
    }
  else
    return 0;

  if (s[i] == ' ')
    {
      len = i + 1;
      ret = 1;
    }
  else if (s[i] == '(' || s[i] == '[')
    {
      len = i;
      ret = 1;
    }
  else if (s[i] == ',')
    {
      len = i + 1;
      ret = 2;      
    }
  else
    return 0;

  gas_assert (ret == 1 || ret == 2);

  *pmin_col = min;
  *pmax_col = max;
  *plen = len;

  return ret;
}

#if 0

static void
get_literal_specs (char *s)
{
  static const literal_format_specifier f[] = {
    {"_f16s", {LITERAL_16, 1}},
    {"_f16", {LITERAL_16, 0}},
    {"_f32s",{LITERAL_32, 1}},
    {"_f32", {LITERAL_32, 0}},
    {"_f64", {LITERAL_64, 0}},

    /* Note that references should be considered in pairs with placements
       only.  */
    {"_lit16_ref", {LITERAL_16, 0}},
    {"_lit32_ref", {LITERAL_32, 0}},
    {"_lit64_ref", {LITERAL_64, 0}}
  };

  static const literal_placement_specifier p[] = {
    {"_lts0lo", {0, 0}},
    {"_lts0hi", {1, 1}},
    {"_lts0", {0, 1}},
    {"_lts1lo", {2, 2}},
    {"_lts1hi", {3, 3}},
    {"_lts1", {2, 3}},
    {"_lts2", {4, 4}},
    {"_lts3", {6, 6}}
  };

  int i;

  min_col = 0;
  max_col = 7;


  min_row = LITERAL_16;
  max_row = LITERAL_64;

  lit_reference = 0;

  /* Look for either of `_{f,lit}XX,_ltsYY ' or `_ltsYY,_{f,lit}XX ' pairs.  */
  for (i = 0; i < 8; i++)
    {
      int j;

      for (j = 0; j < 8; j++)
        {
          int k;

          for (k = 0; k < 2; k++)
            {
              /* 24 chars should be enough to hold `_litXX_ref,_ltsY{lo,hi} ',
                 other patterns are shorter.  */
              char patt[24];
              char *spec;

              sprintf (patt, "%s,%s",
                       k == 0 ? f[i].id : p[j].id, k== 0 ? p[j].id : f[i].id);
              spec = strstr (s, patt);

              if (spec != NULL)
                {
                  size_t l = strlen (patt);

                  if (spec[l] == ' ' || spec[l] == '(' || spec[l] == '[')
                    {
                      /* One should take care of removing ' ' unlike '(' and
                         '['.  */
                      if (spec[l] == ' ')
                        l++;

                      max_row = min_row = f[i].fmt.size;
                      min_col = p[j].rng.min_col;
                      max_col = p[j].rng.max_col;

                      lit_reference = i >= 5 ? 1 : 0;

                      /* Ensure that ambiguous references like `_lit16_ref,
                         _lts{0,1}' are prohibited.  */
                      if (lit_reference
                          && (min_row != max_row
                              || (min_col != max_col
                                  && dummy_table[min_row][max_col] != 0)))
                        {
                          as_bad (_("Ambiguous literal reference `%s'"), patt);
                          return;
                        }

                      memmove (spec, spec + l, strlen (spec) - l + 1);
                      return;
                    }
                }
            }
        }
    }

  /* Look for either of `_fXX ' or `_ltsYY ' partial specification.  */
  for (i = 0; i < 2; i++)
    {
      int j;
      int fmt = i == 0;

      /* Note that `_litXX_ref' format specifications aren't considered here.
         Therefore the upper index is five.  */
      for (j = 0; j < (fmt ? 5 : 8); j++)
        {
          char patt[8];
          char *spec;

          sprintf (patt, "%s", fmt ? f[j].id : p[j].id);
          spec = strstr (s, patt);

          if (spec != NULL)
            {
              size_t l = strlen (patt);

              if (spec[l] == ' ' || spec[l] == '(' || spec[l] == '[')
                {
                  /* One should take care of removing ' ' unlike '(' and
                     '['.  */
                  if (spec[l] == ' ')
                    l++;

                  if (fmt)
                    max_row = min_row = f[j].fmt.size;
                  else
                    {
                      min_col = p[j].rng.min_col;
                      max_col = p[j].rng.max_col;
                    }

                  memmove (spec, spec + l, strlen (spec) - l + 1);
                  return;
                }
            }
        }
    }
}

#endif /* 0  */

static int
replace_nested_commas (char *s, size_t *pidx, size_t *plen)
{
  size_t i;
  size_t level = 0;
  char br[256];
  int fmt_lts_slurped = 0;

  /* FIXME: this stupid GCC doesn't see that these variables are initialized
     and used afterwards only along with setting `fmt_lts_slurped' to 1.  */
  size_t slurped_idx = 0;
  size_t slurped_len = 0;

  /* FIXME: move initialization of these globals somewhere . . .  */
  min_col = 0;
  max_col = 7;

  min_row = LITERAL_16;
  max_row = LITERAL_64;

  lit_reference = 0;


  for (i = 0; s[i] != '\0';)
    {
      if (s[i] == '(' || s[i] == '[')
        {
          if (level == 256)
            {
              as_bad (_("Nesting level of brackets too deep"));
              return 0;
            }

          br[level++] = s[i] == '(' ? ')' : ']';
          ++i;
        }
      else if (s[i] == ')' || s[i] == ']')
        {
          if (level == 0 || br[--level] != s[i])
            {
              as_bad (_("Unbalanced `%c'"), s[i]);
              return 0;
            }

          ++i;
        }
      /* Replace a comma surrounded with either type of brackets with a plus
         sign to ease the subsequent parsing of expressions.  */
      else if (s[i] == ',')
        {
          if (level > 0)
            s[i] = '+';

          ++i;
        }
      else if (fmt_lts_slurped == 0)
        {
          int f = 0;
          int ref = 0;
          int flen = 0;
          /* FIXME: GCC doesn't realize that ROW is used only in case F has been
             changed to 1 which implies passing a pointer to it to `slurp_
             fmt ()'. */
          int row = 0;

          int l = 0;
          int llen = 0;
          int min = 0;
          int max = 0;
          

          f = slurp_fmt (&s[i], &ref, &row, &flen);

          if (f == 0 || f == 2)
            l = slurp_lts (&s[i + flen], &min, &max, &llen);

          if (f == 0 && l == 2)
            f = slurp_fmt (&s[i + llen], &ref, &row, &flen);

          if (! ((f == 1 && l == 0) || (f == 0 && l == 1)
                 || (f == 2 && l == 1) || (f == 1 && l == 2)))
            {
              /* FIXME: shouldn't I report an error in such suspicious cases as
                 `f == 2 && l == 0' or `f == 2 && l == 2' corresponding to
                 `_fXXs, ' or `_fXXs,_ltsYY,' respectively instead of silently
                 going on?  */
              ++i;
              continue;
            }

          /* Having `_litXX_ref ' alone without accompanying `_ltsYY' is an
             error.  */
          if (f == 1 && ref == 1 && l == 0)
            {
              as_bad (_("_ltsX not specified for a literal reference"));
              return 0;
            }

          if (f != 0)
            {
              min_row = max_row = row;
              lit_reference = ref;
            }

          if (l != 0)
            {
              min_col = min;
              max_col = max;

              /* Combinations like `_f{32,64},_lts{0,1}{lo,hi}' should be
                 prohibited.  */
              if (min_col == max_col && min_col < 4 && min_row != 0)
                {
                  as_bad (_("Invalid combination of literal format and "
                            "location"));
                  return 0;
                }

            }

          slurped_idx = i;
          slurped_len = flen + llen;
          i += slurped_len;
          fmt_lts_slurped = 1;
        }
      else
        ++i;
    }

  if (level > 0)
    {
      as_bad (_("Unbalanced brackets in expression"));
      return 0;
    }

  /* `s[i]' contains a trailing zero, `s[slurped_idx + slurped_len]' is the
     first char of substring to be moved.  */
  if (fmt_lts_slurped != 0)
    memmove (&s[slurped_idx], &s[slurped_idx + slurped_len],
             i + 1 - (slurped_idx + slurped_len));

  /* This info may be required by the caller to localize the name of a symbol
     in preprocessing mode in the _original_ string prior to the removal of
     `_fXX, _ltsYY' specifiers above.  */
  *pidx = slurped_idx;
  *plen = slurped_len;
  return 1;
}


const char *maybe_symbol_ptr;
const char *symbol_ptr;

void
md_assemble (char *str)
{
  char *s;
  const char *insn_name;
  int space = 0;
  int comma = 0;
  char junk = '\0';
  const struct e2k_opcode_templ *insn_tmpl;
  static size_t orig_size;
  static char *orig_str;
  size_t len = strlen (str);

  if (orig_size < len + 1)
    {
      orig_size = len + 1;
      orig_str = (char *) realloc (orig_str, orig_size);
    }

  strcpy (orig_str, str);

  s = str;
  if (ISLOWER (*s))
    {
      do
	++s;
      while (ISLOWER (*s) || ISDIGIT (*s) || *s == '_');
    }

  switch (*s)
    {
    case '\0':
      break;

    case ',':
      comma = 1;
      *s = '\0';
      break;

    case ' ':
      space = 1;
      *s++ = '\0';
      break;

    case '%':
    case '[':
      {
        /* Generic GAS parser will leave the first space anyway in such a bogus
           situation . . .  */
        char *s1 = strchr (s, ' ');
        while (*s1 != '\0')
          {
            *s1 = *(s1 + 1);
            s1++;
          }
      }

      junk = *s;
      *s = '\0';
      break;

    default:
      as_bad (_("Unknown opcode: `%s'"), str);
    }

  insn_name = real_insn_name (str);
  insn_tmpl = (struct e2k_opcode_templ *) hash_find (op_hash, insn_name);
  
  if (insn_tmpl)
    {
      size_t replace_idx = 0;
      size_t replace_len = 0;

      /* Take care of restoring the original STR by getting rid of '\0'
	 inserted above. It's not necessary to restore a space ' ' in fact, but
	 is handy for debugging purposes.  */
      if (comma)
        *s = ',';
      else if (space)
	s[-1] = ' ';
      else if (junk != '\0')
        *s = junk;

      /* SYMBOL_PTR will point to the symbol in STR with stripped `_fXX,_ltsYY'
	 specifiers if any is met at all. `REPLACE_{IDX,LEN}' are required to
	 restore its position in ORIG_STR.  */
      symbol_ptr = maybe_symbol_ptr = NULL;

      if (replace_nested_commas (s, &replace_idx, &replace_len) == 0
          || insn_tmpl->parse_args (&s, insn_tmpl) == 0)
        {
          /* We must have had `as_bad ()' invoked if the instruction's parser
             failed.  */
          gas_assert (had_errors () != 0);
          parse_errors_met = 1;
        }
      else if (*s != '\0')
        {
          parse_errors_met = 1;
          as_bad (_("unrecognized arguments `%s' in `%s'"), s, orig_str);
        }

      if (last_ilabel != NULL)
        {
          /* FIXME: shouldn't I print out all internal labels belonging to the
             list here? Will just the last one do?  */
          if (! last_ilabel_used)
            as_bad (_("internal label `%s' not followed by an appropriate "
                      "instruction"), last_ilabel->name);

          last_ilabel_used = 0;
          last_ilabel = NULL;
        }

      instruction_met = 1;

      if (preprocess_mode)
	{
	  size_t i;
	  size_t j;
	  static size_t space_size;
	  static char *space_str;
	  size_t symbol_offs;

	  if (symbol_ptr != NULL)
	    {
	      symbol_offs = (size_t) (symbol_ptr - str);

	      /* Adjust for stripped `_fXX,_ltsYY' specifiers to get the offset
		 of a symbol in the original string if needed.  */
	      if (symbol_offs > replace_idx)
		symbol_offs += replace_len;
	    }
	  else
	    symbol_offs = len;

	  /* Reserve 1 byte for a leading '\t' and 6 bytes for "$hide_" prefix
	     (see my comment below). Also reserve LEN bytes in assumption that
	     if STR consisted of '-'s only each of them should be preceded with
	     space.  */
	  if (space_size < len + 1 + 6 + len + 1)
	    {
	      space_size = len + 1 + 6 + len + 1;
	      space_str = (char *) realloc (space_str, space_size);
	    }


	  /* Take care of printing all necessary assembler directives and
	     comments. If we are within curly braces (a wide instruction),
	     instruction number has already been printed before the opening
	     one.  */
	  if (brace_cntr == 0 || pending_preprocess_brace)
	    {
	      if (strncmp (str, "fapb", 4) == 0 && preprocess_async == 0)
		{
		  puts (".section .fapb,\"ax\",@progbits");
		  preprocess_async = 1;
		}
	      else if (strncmp (str, "fapb", 4) != 0 && preprocess_async == 1)
		{
		  puts (".text");
		  preprocess_async = 0;
		}

	      preprocess_insn_cntr++;
	      printf ("\n! Instruction #%d\n%s", preprocess_insn_cntr,
		      pending_preprocess_brace ? "{\n" : "");

	      if (pending_preprocess_brace)
		pending_preprocess_brace = 0;
	    }

	  space_str[0] = '\t';
	  j = 1;

	  for (i = 0; i < symbol_offs; i++, j++)
	    {
	      /* Prepend each '-' with a space for the sake of the stupid LAS
		 parser.  */
	      if (orig_str[i] == '-')
		space_str[j++] = ' ';

	      space_str[j] = orig_str[i];
	    }

	  if (i < len && orig_str[i] != '$')
	    {
	      /* Ensure that the name of a symbol starts with '$' for the sake
		 of LAS. FIXME: the current implementation doesn't let me handle
		 expressions containing _several_ symbolic references among an
		 instruction's arguments. Fortunately, we are not likely to have
		 such arguments at present, are we?  */
	      space_str[j++] = '$';

	      /* In preprocessing mode eliminate references to `[0-9]+b' labels
		 by stupidly prepending `$hide_' prefix to them. Otherwise the
		 generic part of GAS will complain that it hasn't met their
		 definitions above. To be revisited  */
	      if (orig_str[i] >= '0' && orig_str[i] <= '9')
		{
		  space_str[j++] = 'h';
		  space_str[j++] = 'i';
		  space_str[j++] = 'd';
		  space_str[j++] = 'e';
		  space_str[j++] = '_';
		}
	    }

	  /* Go on copying ORIG_STR further and prepending each minus with
	     space.  */
	  for (; i < len; i++, j++)
	    {
	      if (orig_str[i] == '-')
		space_str[j++] = ' ';

	      space_str[j] = orig_str[i];
	    }

	  space_str[j] = '\0';

	  puts (space_str);
	}
    }
  else
    as_bad (_("unknown instruction `%s'"), str);

  /* FIXME: I'm reluctant to allocate and free `{ORIG,SPACE}_STR' for each
     instruction, but they should be eventually freed somehow . . .  */
}


symbolS *
md_undefined_symbol (name)
     char *name ATTRIBUTE_UNUSED;
{
  return 0;
}

const char *
md_atof (int type ATTRIBUTE_UNUSED,
         char *litP ATTRIBUTE_UNUSED,
         int *sizeP ATTRIBUTE_UNUSED)
{
  return ieee_md_atof (type, litP, sizeP, FALSE);
}

valueT
md_section_align (segT segment, valueT size)
{
  /* Stupid LAS by default sets (at least) a 16-byte alignment for non-empty
     `.{bss,{,ro}data}' sections. For empty ones it always sets a 1-byte
     alignment even if there are objects with greater alignments belonging to
     these sections (I wonder if the latter may lead to trouble)!!! TODO: undo
     this when there's no longer point in comparing disassembly of the Kernel
     compiled with GAS against the one produced by LAS.  */
  if (segment == data_section || segment == bss_section
      || segment == rodata_section)
    {
      if (size != 0)
        record_alignment (segment, 4);
      else
        bfd_set_section_alignment (segment, 0);
    }

  return size;
}


int
tc_e2k_fix_adjustable (struct fix *fixP)
{
  /* Prevent local symbols from being replaced with the containing sections
     in relocation entries so as not to lose info on the size of the former.
     Obviously this should be done for `R_E2K_*_SIZE relocations and for
     relocations intended to produce AP in PM so as not to obtain the one
     extended to the end of GD because of unavailable info on its size (see
     Bug #121736).   */
  if (fixP->fx_r_type == BFD_RELOC_SIZE32
      || fixP->fx_r_type == BFD_RELOC_SIZE64
      || (e2k_arch_size == 128
	  && fixP->fx_r_type == BFD_RELOC_E2K_AP))
    return 0;

  return 1;
}

arelent *
tc_gen_reloc (section, fixp)
     asection *section ATTRIBUTE_UNUSED;
     fixS *fixp;
{
  arelent *rel;

#if 0
  switch (fixp->fx_r_type)
    {
    case BFD_RELOC_SIZE32:
    case BFD_RELOC_SIZE64:
      if (S_IS_DEFINED (fixp->fx_addsy)
	  && !S_IS_EXTERNAL (fixp->fx_addsy))
	{
	  /* Resolve size relocation against local symbol to size of
	     the symbol plus addend.  */
	  valueT value = S_GET_SIZE (fixp->fx_addsy) + fixp->fx_offset;
#if 0
	  if (fixp->fx_r_type == BFD_RELOC_SIZE32
	      && !fits_in_unsigned_long (value))
	    as_bad_where (fixp->fx_file, fixp->fx_line,
			  _("symbol size computation overflow"));
#endif /* 0  */
	  fixp->fx_addsy = NULL;
	  fixp->fx_subsy = NULL;
	  md_apply_fix (fixp, (valueT *) &value, NULL);
	  return NULL;
	}
    default:
      break;
    }
#endif /* 0  */


  rel = (arelent *) xmalloc (sizeof (arelent));
  rel->sym_ptr_ptr = (asymbol **) xmalloc (sizeof (asymbol *));
  *rel->sym_ptr_ptr = symbol_get_bfdsym (fixp->fx_addsy);

  rel->address = fixp->fx_frag->fr_address + fixp->fx_where;

  if (fixp->fx_r_type == BFD_RELOC_32_PCREL
      || fixp->fx_r_type == BFD_RELOC_64_PCREL)
    rel->addend = section->vma + fixp->fx_addnumber + md_pcrel_from (fixp);
  else
    rel->addend = fixp->fx_offset;

  rel->howto = bfd_reloc_type_lookup (stdoutput, fixp->fx_r_type);
  return rel;
}


/* Believe that on E2K PC-relative offsets are relative to the location the
   relocation is applied to.  */
long
md_pcrel_from (fixP)
     fixS *fixP ATTRIBUTE_UNUSED;
{
  return fixP->fx_where + fixP->fx_frag->fr_address;
}


void
md_operand (expressionS *e)
{
  char *s = input_line_pointer;
  e2k_generic_register reg;
  u_int8_t special;

  if (parse_generic_register (&s, &reg))
    {
      e->X_op = O_register;
      e->X_add_number = reg.idx;
 
      /* Let O_register have X_add_number equal to the value to be encoded
         into `ALF.{src{1,2,3},dst}'.  */
      switch (reg.type)
        {
        case BASED:
          break;
        case WINDOW:
          e->X_add_number += 128;
          break;
        case GLOBAL:
          e->X_add_number += 224;
          break;
        case AASTI:
          e->X_add_number += 256;
          break;
        default:
          abort ();
        }
    }
  else if ((special = parse_special_register (&s)) != 0)
    {
      e->X_op = O_register;
      e->X_add_number = special;
    }

  input_line_pointer = s;
}

int md_long_jump_size;
int md_short_jump_size;

void
md_apply_fix (fixP, valP, seg)
     /* The fix we're to put in.  */
     fixS *fixP;
     /* Pointer to the value of the bits.  */
     valueT *valP;
     /* Segment fix is from.  */
     segT seg ATTRIBUTE_UNUSED;
{
  /* It turns out that `fixP->fx_pcrel' is set in fixup_segment ()' where we
     are called from. In that case we must correct a relocation for
     pc-relativeness. I wonder, why cannot we choose the right relocation type
     in `e2k_cons_fix_new ()' when we see e.g. an O_subtract expression?
     Moreover, it seems that we may want to migrate from pc-relative to abs
     relocation here (see tc-tilegx as an example) . . .  */

  if (fixP->fx_pcrel)
    {
      switch (fixP->fx_r_type)
        {
        case BFD_RELOC_32:
          fixP->fx_r_type = BFD_RELOC_32_PCREL;
          break;
        case BFD_RELOC_64:
          fixP->fx_r_type = BFD_RELOC_64_PCREL;
          break;
        default:
          break;
        }
    }
  
  
  if (fixP->fx_addsy == NULL)
    {
      char *p = fixP->fx_where + fixP->fx_frag->fr_literal;

      /* The following two IFs should work e.g. for constructs like
         `.long 1f - 0f' so that no bogus relocations are generated in
         the output file. But . . . find out how it happens that we have
         `BFD_RELOC_XX' rather than `BFD_RELOC_XX_PCREL' in the aforementioned
         case and why `fx_pcrel == 0'.  */
      if (fixP->fx_r_type == BFD_RELOC_32)
        {
          md_number_to_chars (p, *valP, 4);
          fixP->fx_done = 1;
        }
      else if (fixP->fx_r_type == BFD_RELOC_64)
        {
          md_number_to_chars (p, *valP, 8);
          fixP->fx_done = 1;
        }
      else if (fixP->fx_r_type == BFD_RELOC_E2K_DISP)
        {
          /* The offset of CS0 inside wide command has been
             placed in *valP somehow. */

          *((valueT *) (void *) p) |= (((*valP) / 8) & 0xfffffff);

          /* What's the point in valP as a pointer? Does anyone
             need to modify data lying there at all?*/
          /* *valP -= fixP->fx_where; */
          fixP->fx_done = 1;
        }
    }

  if (fixP->fx_addsy != NULL)
    {
      if (fixP->fx_r_type == BFD_RELOC_E2K_TLS_IE
          /* Without that I used to obtain BSF_GLOBAL instead of
             BSF_THREAD_LOCAL for extern `__thread' symbols accessed via
             GD model (e.g. when compiling with `-fPIC'). Should LE case be
             considered here as well?

             Keep in mind that if we have an extern `__thread' symbol in a
             non-fPIC object, it's accessed via IE by default, not via LE. And
             that is why we didn't have problems in this case before.  */
          || fixP->fx_r_type == BFD_RELOC_E2K_TLS_GDMOD
          || fixP->fx_r_type == BFD_RELOC_E2K_TLS_GDREL

          || fixP->fx_r_type == BFD_RELOC_E2K_32_TLS_LE
          || fixP->fx_r_type == BFD_RELOC_E2K_64_TLS_LE)
        S_SET_THREAD_LOCAL (fixP->fx_addsy);
    }


  fixP->fx_addnumber = *valP;
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


static void
start_wide_command (void)
{
  int i;
  ilabels_num = 0;
  ss_ilabel = cs0_ilabel = cs1_ilabel = NULL;

  for (i = 0; i < 4; i++)
    aa2f1_ilabel[i] = NULL;

  inside_wide_command = 1;
  memset (&wc, 0, sizeof (wc));
  /* Set up an invalid value indicating that nothing
     has been really set. */

  for (i = 0; i < 10; i++)
    wc.setcmd_args[i] = ~setcmd_masks[i];

  wc.setsft_seen = 0;

  crnt_lit = 0;
  memset (free_alses, 0, sizeof (free_alses));
  free_als = &free_alses[0];

  /* Do it after memsetting free_alses with zero. */
  for (i = 0; i < 6; i++)
    {
      int j;
      memset (&free_alses[i], 0, sizeof (free_alses[i]));
      for (j = 0; j < 4; j++)
        {
          free_alses[i].preds[j].pred_num = -1;
          free_alses[i].preds[j].negated = 0;
        }
    }
}

static int
compare_literal_placements (const void *frst, const void *scnd)
{
#if 1
  int i;
#endif /* 0  */

  const literal_placement *frst_plcmnt = *((const literal_placement **) frst);
  const literal_placement *scnd_plcmnt = *((const literal_placement **) scnd);

#if 0
  if (frst_plcmnt->als_idx < scnd_plcmnt->als_idx)
    return -1;

  return (frst_plcmnt->als_idx == scnd_plcmnt->als_idx) ? 0 : 1;
#endif /* 0  */

#if 1
  /* Прежде всего сравниваем общее количество возможных размещений. */
  if (frst_plcmnt->plcmnt_nmb < scnd_plcmnt->plcmnt_nmb)
    return -1;
  else if (frst_plcmnt->plcmnt_nmb > scnd_plcmnt->plcmnt_nmb)
    return 1;

  /* Если общее количество размещений у литералов совпадает, наверное, сначала
     все-таки выгоднее размещать те литералы, которые требуют больше места.
     У нас массив size[] как будто является возрастающим. */

  for (i = 0; i < frst_plcmnt->plcmnt_nmb; i++)
    {
      if (frst_plcmnt->size[i] > scnd_plcmnt->size[i])
        return -1;
      else if (frst_plcmnt->size[i] < scnd_plcmnt->size[i])
        return 1;
    }

  /* Не ясно, кому отдать предпочтение. */
  return ((size_t) frst_plcmnt < (size_t) scnd_plcmnt) ? -1 : 1;
#endif /* 0  */
}

static int
hsyll_same_expr (struct hsyll *phs, expressionS *exp, unsigned int idx)
{
  if (phs->owner->exp.X_op != exp->X_op)
    return 0;

  if (exp->X_op == O_constant)
    {
      /* FIXME: conversion to (VOID *) added to fight strict aliasing
         warnings.  */
      u_int16_t *dst_shrt = (u_int16_t *) (void *) &phs->owner->exp.X_add_number;
      u_int16_t *src_shrt = (u_int16_t *) (void *) &exp->X_add_number;

      if (dst_shrt[phs->sub_idx] == src_shrt[idx])
        return 1;
      return 0;
    }
  else if (is_symbol (exp))
    {
      if (phs->owner->exp.X_op != exp->X_op
          || phs->owner->exp.X_add_symbol != exp->X_add_symbol
          || phs->owner->exp.X_add_number != exp->X_add_number
          || phs->sub_idx != idx)
        return 0;

      return 1;
    }
  else
    gas_assert (0);

  return 0;
}

static void
set_hsyll_owner (struct hsyll *phs, literal_placement *owner, unsigned int idx)
{
  phs->owner = owner;
  phs->sub_idx = idx;
}


static int
place_literal (literal_placement *pplcmnt, int plcmnt_idx, int prove, int finalize ATTRIBUTE_UNUSED)
{
  unsigned int i;
  int pos;

#if 0
  /* Когда мы сдвигаем индекс у n-го размещения, литералы, соответствующие размещениям
     0, . . ., n - 1 могут спокойно оставаться на своих местах. Правда, удобнее все
     вычищать, поскольку часть занимаемых ими полуслогов могла быть использована
     размещениями >= n, а это отслеживать крайне неудобно. Но, по крайней мере,
     для них можно не повторять проверку, т.е. вызывать ф-цию с prove == 0. */
#endif /* 0 */
  if (prove)
    {
      for (i = 0, pos = pplcmnt->pos[plcmnt_idx]; i < pplcmnt->size[plcmnt_idx]; pos++, i++)
        {
          int pos_msk = 1 << (((pos >> 1) << 1) + 1 - (pos & 0x1));
          if ((wc.busy_lts & pos_msk) != 0
              && (
#if 0
		  /* This condition used to prevent us from merging wider than
		     16-bit (i.e. 32 and 64-bit) identical literals. However,
		     it hasn't been required since ugly `lit_ref's started
		     being treated separately from regular literals. It is
		     necessarily disabled now that we are going to get rid of
		     `lit_ref's in LCC by replacing them with duplicating
		     literal values (Bug #124870) and (TODO!) is to be
		     eventually removed if the new approach does not result
		     in any trouble.  */
		  pplcmnt->size[plcmnt_idx] > 1
		  ||
#endif /* 0  */
		  ! hsyll_same_expr (&wc.lts[pplcmnt->pos[plcmnt_idx] + i], &pplcmnt->exp, i)))
            /* Очередной полу-литерал занят другим значением. Возвращаемся,
               ничего не испортив. */
            return 0;
        }
    }

  /* Есть место. Можно занимать без дальнейших проверок. */
  for (i = 0, pos = pplcmnt->pos[plcmnt_idx]; i < pplcmnt->size[plcmnt_idx]; pos++, i++)
    {
      int pos_msk = 1 << (((pos >> 1) << 1) + 1 - (pos & 0x1));
      /* FIXME: try to get rid of wc.busy_lts. Use wc.lts[].owner instead. */
      if (wc.busy_lts & pos_msk)
        continue;

      wc.busy_lts |= pos_msk;
      set_hsyll_owner (&wc.lts[pos], pplcmnt, i);
    }

  return 1;
}

static int
place_literals (void)
{
  int i;
  int crnt_idx[MAX_LITERAL_NMB] = {0, 0, 0, 0, 0, 0, 0};
  literal_placement *pplcmnt[MAX_LITERAL_NMB];
  /* В начале мы не можем сказать ни об одном размещении, является ли оно
     действительным (см. использование ниже). */
  int first_incr = 0;

  unsigned int best_res = 0x100;

  for (i = 0; i < crnt_lit; i++)
    pplcmnt[i] = &allowed_placements[i];
  
  qsort (pplcmnt, crnt_lit, sizeof (pplcmnt[0]), compare_literal_placements);

  while (1)
    {
      /* В любом случае полностью обнуляем wc.lts[] и маску использования wc.busy_lts.
         Из-за того, что несколько размещаемых литералов могут использовать общие полуслоги. */
      memset (wc.lts, 0, sizeof (wc.lts));
      wc.busy_lts = 0;

      for (i = 0; i < crnt_lit; i++)
        {
          /* Третий параметр показывает необходимость проверки при размещении
             литерала. Размещения, идущие до первого с увеличившимся значением
             текущего индекса, заведомо остаются действительными. */
          if (!place_literal (pplcmnt[i], crnt_idx[i], i >= first_incr, 0))
            /* Если не удалось разместить этот, нет смысла возиться со следующими. */
            break;
        }

      if (i == crnt_lit)
        {
          /* На этом шаге все литералы успешно уместились. Будем продвигать индексы,
             начиная с последнего размещения. */
          first_incr = crnt_lit - 1;
          /* Критерий того, удалось ли нам "компактнее" разместить литералы. Правда,
             реально нас интересует только положение старшего ненулевого бита в каждом
             из сравниваемых значений. */
          if ((unsigned int) wc.busy_lts < best_res)
            {
              best_res = (unsigned int) wc.busy_lts;
              for (i = 0; i < crnt_lit; i++)
                /* Сохраним значения "оптимальных" индексов для каждого размещения. */
                pplcmnt[i]->optimal_plcmnt_idx = crnt_idx[i];
            }
        }
      else
        /* Обломались на i-ом размещении. Будем продвигать, начиная с него. */
        first_incr = i;

      /* Обнуляем индексы, для размещений, следующих за первым продвигаемым. */

      for (i = crnt_lit - 1; i > first_incr; i--)
        crnt_idx[i] = 0;

      /* Продвигаем текущие индексы размещений. */
      for (i = first_incr; i >= 0; i--)
        {
          if ((++crnt_idx[i]) < pplcmnt[i]->plcmnt_nmb)
            break;
          else
            crnt_idx[i] = 0;
        }

        if (i == -1)
          /* Все возможные размещения перебраны. Выходим. */
          break;
        else
          /* Теперь это значение показывает, в каком размещении реально увеличился
             индекс (до него - индексы размещений остались неизменными, после
             него - нули). */
          first_incr = i;
    }

  if (best_res == 0x100)
    {
      as_bad ("literals cannot be packed into a wide command");
      return 0;
    }

  /* Размещаем литералы оптимальным образом. Все размещения корректны,
     в проверке не нуждаются.*/
  memset (wc.lts, 0, sizeof (wc.lts));
  wc.busy_lts = 0;
  for (i = 0; i < crnt_lit; i++)
    place_literal (pplcmnt[i], pplcmnt[i]->optimal_plcmnt_idx, 0, 1);

  return 1;
}

static void
encode_long_lit_in_src2 (u_int8_t *src2, literal_placement *plcmnt)
{
  size_t size = plcmnt->size[plcmnt->optimal_plcmnt_idx];
  int lit_nmb = plcmnt->pos[plcmnt->optimal_plcmnt_idx] / 2;
  int hi = plcmnt->pos[plcmnt->optimal_plcmnt_idx] % 2;
  
  gas_assert (*src2 == 0);
  /* Напоминаю, что это поле содержит размер в ПОЛУСЛОГАХ! */
  switch (size)
    {
    case 1:
      gas_assert (lit_nmb < 2);
      *src2 = 0xd0 | ((lit_nmb == 1) ? 0x1 : 0x0) | (hi ? 0x4 : 0x0);
      break;
    case 2:
      /* Не может размещаться, начиная с верхнего полу-литерала. */
      gas_assert (hi == 0);
      *src2 = 0xd8 | (unsigned char) lit_nmb;
      break;
    case 4:
      gas_assert (hi == 0);
      gas_assert (lit_nmb < 3);
      *src2 |= 0xdc | (unsigned char) lit_nmb;
      break;
    default:
      gas_assert (0);
    }
}

/* Функция, завершающая формирование значения в ALS-слоге
   формата ALF1. */
static int
finish_alf123578 (e2k_als *pals)
{
  if (pals->src2)
    {
      unsigned i;
      for (i = 0; i < pals->real_als_nmb; i++)
        encode_long_lit_in_src2 (&pals->u[i].alf1.src2, pals->src2);
    }

  return 1;
}

/* Функция, завершающая формирование значений в ALS'ax. */
static void
finish_alses (void)
{
  int i;
  int crnt_als = free_als - &free_alses[0];

  for (i = 0; i < crnt_als; i++)
    {
      if (free_alses[i].finish)
        free_alses[i].finish ((e2k_als *) &free_alses[i]);
    }
}

/* Функция, выполняющая сравнения двух ALS'ов по числу возможных
   размещений. Вызывается при сортировке указателей на ALS'ы
   перед их размещением в широкой команде. */

static int
compare_alses (const void *frst, const void *scnd)
{
  const e2k_als *frst_als = ((const e2k_als **) frst)[0];
  const e2k_als *scnd_als = ((const e2k_als **) scnd)[0];

  return ((size_t) frst_als < (size_t) scnd_als) ? -1 : 1;

#if 0
  /* Прежде всего сравниваем общее количество возможных размещений. */
  if (frst_als->plcmnt_nmb < scnd_als->plcmnt_nmb)
    return -1;
  else if (frst_als->plcmnt_nmb > scnd_als->plcmnt_nmb)
    return 1;

  /* Пока я не рассматриваю ALS'ы, занимающие 2 слога (например, в командах,
     работающих с квадро-регистрами), у меня нет других оснований для предпочтения
     одного из ALS'ов. */

  return 0;
#endif /* 0  */
}

static int
place_alses (void)
{
  int i;
  int crnt_idx[ALS_CHANNELS_NUMBER] = {0, 0, 0, 0, 0, 0};
  e2k_als *pals[ALS_CHANNELS_NUMBER];
  unsigned int best_res = 1 << ALS_CHANNELS_NUMBER;
  int crnt_als = free_als - &free_alses[0];

  int first_incr = 0;
  int met_mas = 0;

  /* В светлом будущем мы будем работать не только с alf1, поэтому указатели
     на разные типы ALS'ов будут браться из общего массива. */
  for (i = 0; i < crnt_als; i++)
    pals[i] = (e2k_als *) &free_alses[i];

  qsort (pals, crnt_als, sizeof (pals[0]), compare_alses);

  while (1)
    {
      memset (wc.al, 0, sizeof (wc.al));
      wc.busy_al = 0;

      for (i = 0; i < crnt_als; i++)
        {
          unsigned j;
          if (i < first_incr)
            {
              /* Здесь не должно возникать проблем с размещением, условие должно само
                 собой выполняться (assert для контроля моих внутренних ошибок). */
              for (j = 0; j < pals[i]->real_als_nmb; j++)
                {
                  gas_assert ((wc.busy_al & (1 << pals[i]->real_alses[pals[i]->pos[crnt_idx[i]]][j])) == 0);
                  wc.busy_al |= 1 << pals[i]->real_alses[pals[i]->pos[crnt_idx[i]]][j];
                }
            }
          else
            {
              /* Здесь уже никто ничего не гарантирует. */
              for (j = 0; j < pals[i]->real_als_nmb; j++)
                {
                  if (wc.busy_al & (1 << pals[i]->real_alses[pals[i]->pos[crnt_idx[i]]][j]))
                    break;
                }

              if (j < pals[i]->real_als_nmb)
                /* Местечко занято. Если не удалось разместить этот ALS,
                   нет смысла возиться со следующими. */
                break;
              else
                {
                  for (j = 0; j < pals[i]->real_als_nmb; j++)
                    wc.busy_al |= 1 << pals[i]->real_alses[pals[i]->pos[crnt_idx[i]]][j];
                }
            }
        }

      if (i == crnt_als)
        {
          /* На этом шаге все ALS'ы успешно уместились. Будем продвигать индексы,
             начиная с последнего размещения. */
          first_incr = crnt_als - 1;
          /* Критерий того, удалось ли нам "компактнее" разместить ALS'ы. Но имеет ли
             смысл вообще этим заниматься? Ведь, кажется, ALS'ы в отличие от литералов
             могут входить (или не входить) в широкую команду совершенно независимо друг от друга. */
          if (best_res == 1 << ALS_CHANNELS_NUMBER
              && (unsigned int) wc.busy_al < best_res)
            {
              best_res = (unsigned int) wc.busy_al;
              for (i = 0; i < crnt_als; i++)
                /* Сохраним значения "оптимальных" индексов размещения для каждого ALS'а. */
                pals[i]->optimal_plcmnt_idx = crnt_idx[i];
            }
        }
      else
        /* Обломались на i-ом размещении. Будем продвигать, начиная с него. */
        first_incr = i;

      /* Обнуляем индексы, для размещений, следующих за первым продвигаемым. */
      for (i = crnt_als - 1; i > first_incr; i--)
        crnt_idx[i] = 0;

      /* Продвигаем текущие индексы размещений. */
      for (i = first_incr; i >= 0; i--)
        {
          if ((++crnt_idx[i]) < pals[i]->plcmnt_nmb)
            break;
          else
            crnt_idx[i] = 0;
        }

        if (i == -1)
          /* All possible placements have been considered. Escape.  */
          break;
        else
          /* Теперь это значение показывает, в каком размещении реально увеличился
             индекс (до него - индексы размещений остались неизменными, после
             него - нули). */
          first_incr = i;
    }

  if (best_res == (1 << ALS_CHANNELS_NUMBER))
    {
      as_bad ("ALSes cannot be packed into a wide command");
      return 0;
    }

  /* Place ALS'es in the most optimal way. All placements are guaranteed to be
     correct and don't need to be checked.  */
  memset (wc.al, 0, sizeof (wc.al));
  wc.busy_al = 0;
  for (i = 0; i < crnt_als; i++)
    {
#define RLP0    0
#define RLP1    1
#define MRGC0   2
#define MRGC1   3

      static const u_int16_t al_to_rlp_mrgc[][2]
        = {{RLP0, MRGC0}, {RLP0, MRGC0}, {RLP0, MRGC0},
           {RLP1, MRGC1}, {RLP1, MRGC1}, {RLP1, MRGC1},
	   /* These two correspond to AM{2,5} "ALC"es. TODO(?): in theory the
	      first of them could be used to encode RPC == MRGC0 acting on {S/L
	      /C}RP, but this is not currently used in the underlying algorithm
	      and doesn't probably make much sense.  */
	   {RLP0, -1}, {RLP1, -1}};

      /* The trailing two elements in {MASK,NEG}[] correspond to RLP{0,1}
	 acting on AM{2,5} respectively.  */
      static u_int16_t al_to_mask[] = {0x1, 0x2, 0x4, 0x1, 0x2, 0x4, 0x8, 0x8};
      static u_int16_t al_to_neg[] = {0x1, 0x2, 0x4, 0x1, 0x2, 0x4, 0x4, 0x4};
      unsigned j;
      int al_num = pals[i]->pos[pals[i]->optimal_plcmnt_idx];
      /* This will be used when setting al[] bits in HS when packing the wide
	 instruction. Can they be set right here?  */

      for (j = 0; j < pals[i]->real_als_nmb; j++)
        {
          int real_num = pals[i]->real_alses[al_num][j];
          wc.busy_al |= (1 << real_num);
          memcpy (&wc.al[real_num].val, &pals[i]->u[j].val,
                  sizeof (pals[i]->u[j].val));

          /* Only the first of a pair of ALSes inherits an internal label.  */
          if (j == 0)
            wc.al[real_num].label = pals[i]->label;

          if (pals[i]->exp.X_op == O_islocal)
            {
              gas_assert (pals[i]->real_als_nmb == 1);
              wc.al[real_num].exp = &pals[i]->exp;
            }
          else
            wc.al[real_num].exp = NULL;
            
        }
      if (pals[i]->need_mas)
	{
	  if (wc.cs1.set)
	    /* This must have been set by one of the functions
	       called from encode_setcmds which in its turn is
	       called prior to this one. In this case we cannot
	       encode MAS since the CS1 syllable is already busy.
	       Usage of wc.cs1.set is bogus and non-rescalable. */
	    {
	      as_bad (_("cannot encode MAS: CS1 syllable is busy "
			"with set-instructions"));
	      return 0;
	    }

	  if (! met_mas)
	    {
	      wc.cs1.val.word = 0;
#define CS1_MAS		0x6
	      wc.cs1.val.fields.mas.opc = CS1_MAS;
	      met_mas = 1;
	    }
#define SET_MAS(aln) case aln:					\
	  wc.cs1.val.fields.mas.mas##aln = pals[i]->mas;        \
          break;

          for (j = 0; j < pals[i]->real_als_nmb; j++)
            {
              switch (pals[i]->real_alses[al_num][j])
                {
                  SET_MAS (0);
                  SET_MAS (2);
                  SET_MAS (3);
                  SET_MAS (5);
                default:
                  gas_assert (_("MAS applied to illegal ALS"));
                }
            }
	}

      /* Do quad ops occupying two ALCes  ever need ales(es)? Yes,
         they do. */

      if (pals[i]->need_ales)
        {
          for (j = 0; j < pals[i]->real_als_nmb; j++)
            {
              int real_num = pals[i]->real_alses[al_num][j];
              if (pals[i]->opc2_arr)
                {
                  /* FIXME: this is a stupid way to signalize that an
                     instruction when encoded in this particular ALC doesn't
                     need ALES.  */
                  if (pals[i]->opc2_arr[real_num] == 0xff)
                    continue;

                  pals[i]->ales.alef2.opc2 = pals[i]->opc2_arr[real_num];
                }

              wc.busy_ales |= (1 << real_num);
              memcpy (&wc.ales[real_num], &pals[i]->ales, sizeof (pals[i]->ales));

              if (mcpu == 4 && pals[i]->explicit_ales25_v4
                  && (real_num == 2 || real_num == 5))
                wc.explicit_ales25 = 1;
            }
        }



      {
        unsigned l;
        for (l = 0; l < 4; l++)
          {
            unsigned k;
	    /* `l == {0,2,3}' correspond to %p{red,cnt}X encoded in RLP, while
	       `l == 1' stands for MRGC predicate.  */
            int op_idx = (l < 2) ? l : 0;

	    /* No predicate of the type under consideration (i.e. ` ? %p{red,
	       cnt}X' or MRGC) acting on this ALS.  */
            if (pals[i]->preds[l].pred_num < 0)
	      continue;

            for (k = 0; k < pals[i]->real_als_nmb; k++)
              {
                int real_al_num = pals[i]->real_alses[al_num][k];
		/* preds[3] acts on AM{2,5} matching ALC{2,5} in fact. There
		   should be no `AMj's matching other ALCes.  */
		if (l == 3)
		  {
		    if (real_al_num == 2)
		      real_al_num = 6;
		    else if (real_al_num == 5)
		      real_al_num = 7;
		    else
		      gas_assert (0);
		  }

                for (j = 0; j < 6; j++)
                  {
		    /* Does this already employed CDS<j> half syllable encode
		       the same operation as we need?  */
                    if (wc.cds[j].rlp_mrgc.opc == al_to_rlp_mrgc[real_al_num][op_idx])
                      {
			u_int16_t opc = al_to_rlp_mrgc[real_al_num][op_idx];
#if 0
                        /* With things like `? %predX, %pcntY' possible there
			   may be more than one RLP acting on the same ALC,
			   which is why this assert is commented out. should be
                           impossible at least while an explicit rlp command is not
                           introduced. In the latter case this situation may very
                           well become a user error. */
                        gas_assert ((wc.cds[j].rlp_mrgc.mask
				     & al_to_mask[real_al_num]) == 0);
#endif /* 0  */
			/* Does this already employed CDS<j> half syllable encode
			   the same predicate as we need?  */
                        if (wc.cds[j].rlp_mrgc.pred
			    == pals[i]->preds[l].pred_fld)
                          {
			    /* Should one check for a possible inconsistency
			       because of CDS.neg[2] shared between CDS.mask[2,3]?  */
			    if ((al_to_mask[real_al_num] == 0x4
				 && (wc.cds[j].rlp_mrgc.mask & 0x8) != 0)
				|| (al_to_mask[real_al_num] == 0x8
				    && (wc.cds[j].rlp_mrgc.mask & 0x4) != 0))
			      {
				/* Only RLP{0,1} and `MRGC0 together with RPC
				   == MRGC0' may act on such a combination of
				   "target syllables" as CDS.mask[3] seems to
				   be reserved for MRGC1 up to iset-v6.  */
				gas_assert (opc == RLP0 || opc == RLP1
					    || (/* RPC predicates may emerge
						   starting from elbrus-v3
						   only.  */
						mcpu > 2
						&& opc == MRGC0));

				if ((pals[i]->preds[l].negated
				     && (wc.cds[j].rlp_mrgc.neg
					 & al_to_neg[real_al_num]) == 0)
				    || (! pals[i]->preds[l].negated
					&& (wc.cds[j].rlp_mrgc.neg
					    & al_to_neg[real_al_num]) != 0))
				  continue;
			      }

			    /* This CDS half-syllable may be safely shared
			       between an already encoded operation and the
			       new one.  */
                            wc.cds[j].rlp_mrgc.mask |= al_to_mask[real_al_num];
                            if (pals[i]->preds[l].negated)
                              wc.cds[j].rlp_mrgc.neg |= al_to_neg[real_al_num];
                            break;
                          }
                      }
                  }

                if (j < 6)
                  /* We have found an appropriate CDS half-syllable
                     and modified it. */
                  continue;

                /* As I understand, a free CDS half-syllable should have
                   a zero mask. */
                for (j = 0; (j < 6) && (wc.cds[j].rlp_mrgc.mask != 0x0);)
                  j++;



                if (j == 6)
                  {
                    as_bad (_("out of free cds half-syllables"));
                    return 0;
                  }

                wc.cds[j].rlp_mrgc.opc = al_to_rlp_mrgc[real_al_num][op_idx];
                wc.cds[j].rlp_mrgc.mask = al_to_mask[real_al_num];
                wc.cds[j].rlp_mrgc.pred = pals[i]->preds[l].pred_fld;
                if (pals[i]->preds[l].negated)
                  wc.cds[j].rlp_mrgc.neg = al_to_neg[real_al_num];
              }
          }
      }
    }

  if (met_mas)
    wc.cs1.set = 1;

  return 1;  
}

typedef struct {
  u_int32_t mdl:4;
  u_int32_t lng:3;
  u_int32_t nop:3;
  u_int32_t lm:1;
  u_int32_t x:1;
  u_int32_t s:1;
  u_int32_t sw:1;
  u_int32_t c:2;
  u_int32_t cd:2;
  u_int32_t pl:2;
  u_int32_t ale:6;
  u_int32_t al:6;
} e2k_hs;



/* 3-bit lng field holds the number of double words in the wide instruction
   minus one. This means that the wide instruction may consist of 8 double
   (or 16 single 32-bit) words at maximum.  */
static u_int32_t packed_cmd[16];

static void
set_wc_reloc (int where, int size, expressionS *exp, int pcrel, enum bfd_reloc_code_real r_type)
{
  struct wc_reloc *pwcr = &wc.relocs[wc.reloc_cntr];
  pwcr->where = where;
  pwcr->size = size;
  pwcr->exp = exp;
  pwcr->pcrel = pcrel;
  pwcr->r_type = r_type;

  wc.reloc_cntr++;
}

static void
pack_plcmnt (int lts_idx, u_int16_t *hlts)
{
  literal_placement *plcmnt = wc.lts[lts_idx].owner;
  unsigned int sub_idx = wc.lts[lts_idx].sub_idx;
  size_t size;

  if (!plcmnt)
    {
      *hlts = 0;
      return;
    }

  size = plcmnt->size[plcmnt->optimal_plcmnt_idx];
  gas_assert (sub_idx < size);

  if (plcmnt->exp.X_op == O_constant)
    {
      /* FIXME: conversion to (VOID *) added to fight strict aliasing
         warnings.  */
      *hlts = ((u_int16_t *) (void *) &plcmnt->exp.X_add_number)[sub_idx];
    }
  else if (plcmnt->exp.X_op == O_symbol)
    {
      *hlts = 0;
      switch (size)
        {
        case 2:
          if (sub_idx == 0)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 4, &plcmnt->exp, 0, BFD_RELOC_32);
          break;
        case 4:
          /* Half-syllable number 2 has is placed at the lowest memory address.
             For all other "symbolic" half-syllables there is nothing to do.
             Probably add some sanity checks. */
          if (sub_idx == 2)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 8, &plcmnt->exp, 0, BFD_RELOC_E2K_64_ABS_LIT);
          break;
        default:
          gas_assert (0);
        }
    }
  else if (plcmnt->exp.X_op == O_pc)
    {
      *hlts = 0;
      switch (size)
        {
        case 2:
          if (sub_idx == 0)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 4, &plcmnt->exp,
                          /* This is a pc-relative relocation.  */
                          1,
                          BFD_RELOC_32_PCREL);
          break;
        case 4:
          /* Half-syllable number 2 has is placed at the lowest memory address.
             For all other "symbolic" half-syllables there is nothing to do.
             Probably add some sanity checks. */
          if (sub_idx == 2)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 8, &plcmnt->exp,
                          1, BFD_RELOC_64_PCREL);
          break;
        default:
          gas_assert (0);
        }
    }
  else if (plcmnt->exp.X_op == O_tls_le)
    {
      /* We may have 32 and 64-bit long TLS_LE relocs.  */
      switch (size)
        {
        case 2:
          if (sub_idx == 0)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 4, &plcmnt->exp, 0, BFD_RELOC_E2K_32_TLS_LE);
          break;
        case 4:
          if (sub_idx == 2)
            set_wc_reloc ((char *) hlts - (char *) packed_cmd, 8, &plcmnt->exp, 0, BFD_RELOC_E2K_64_TLS_LE);
          break;
        default:
          gas_assert (0);
        }
    }
  else if ((plcmnt->exp.X_op == O_gotoff && size == 2)
           || plcmnt->exp.X_op == O_got
           || plcmnt->exp.X_op == O_gotplt
           || plcmnt->exp.X_op == O_tls_ie
           || plcmnt->exp.X_op == O_tls_gdmod
           || plcmnt->exp.X_op == O_tls_gdrel

           /* FIXME: what's the point in treating this relocation as a 32-bit
              one provided that finally its type is adjusted in
              `e2k_cons_fix_new ()'?  */
           || plcmnt->exp.X_op == O_size

           /* FIXME: according to treatment of the underlying two relocations
              in parse_literal () I doubt if they are 32-bit in fact. Are they
              actually used nowadays?  */
           || plcmnt->exp.X_op == O_ap_got
           || plcmnt->exp.X_op == O_pl_got

           || plcmnt->exp.X_op == O_islocal32)
    {
      /* TLS_IE reloc is 32 bits long both in 32 and 64-bit mode.  */
      gas_assert (size == 2);

      if (sub_idx == 0)
        set_wc_reloc ((char *) hlts - (char *) packed_cmd, 4, &plcmnt->exp, 0,
                      plcmnt->exp.X_op == O_gotoff
                      ? BFD_RELOC_32_GOTOFF
                      :  (plcmnt->exp.X_op == O_got
                          ? BFD_RELOC_E2K_GOT
                          : (plcmnt->exp.X_op == O_gotplt
                             ? BFD_RELOC_E2K_GOTPLT
                             : (plcmnt->exp.X_op == O_tls_ie
                                ? BFD_RELOC_E2K_TLS_IE
                                : (plcmnt->exp.X_op == O_tls_gdmod
                                   ? BFD_RELOC_E2K_TLS_GDMOD
                                   : (plcmnt->exp.X_op == O_tls_gdrel
                                      ? BFD_RELOC_E2K_TLS_GDREL
                                      : (plcmnt->exp.X_op == O_size
                                         ? BFD_RELOC_SIZE32
                                         : (plcmnt->exp.X_op == O_ap_got
                                            ? BFD_RELOC_E2K_AP_GOT
                                            : (plcmnt->exp.X_op == O_pl_got
                                               ? BFD_RELOC_E2K_PL_GOT
                                               : BFD_RELOC_E2K_ISLOCAL32
                                               )))))))));
    }
  else if (plcmnt->exp.X_op == O_gotoff && size == 4)
    {
      gas_assert (size == 4);
      if (sub_idx == 2)
	set_wc_reloc ((char *) hlts - (char *) packed_cmd, 8, &plcmnt->exp,
		      0, BFD_RELOC_E2K_GOTOFF64_LIT);
    }
}

int total_syllables;

static void
pack_wide_command (void)
{
  int i;
  int crnt_syll = 0, lts_cntr = 0, cds_cntr = 0, pls_cntr = 0;
  e2k_hs *hs;
  /* FIXME: `bufs[]' and `sub_frags[]' arrays should obviously contain one
     element more than `ilabels[]'.  */
  char *obj_buf, *bufs[21];
  fragS *sub_frags[21];
  u_int16_t *hsyllables;
  unsigned hsyllable_cntr;

  /* If this is an instruction belonging to an asynchronous program, there is no
     point in encoding it as an ordinary one. FIXME: a check is needed to ensure
     that a user doesn't mix the two types of instructions within a single wide
     command.  */
  if (wc.busy_aps != 0)
    {
      /* REMINDER: currently it seems to me that all four FAPB syllables (i.e.
         APS0, APLS0, APS1 and APLS1) should be present no matter whether a
         single FAPB instruction or a pair of them are provided by a user. This
         follows from 6.8 in iset.single and from object files produced by
         LAS.  */
      for (i = 0; i < 2; i++)
        {
          if ((wc.busy_aps & (1 << i)) != 0)
            {
              obj_buf = frag_more (8);
              memcpy (obj_buf, &wc.aps[i], 4);
              memcpy (obj_buf + 4, &wc.apls[i], 4);
            }
          else
            {
              obj_buf = frag_more (8);
              memset (obj_buf, 0, 8);
            }
        }

      return;
    }


  /* I don't want to see any rubbish from previous wide commands
     in syllables which are included just for alignment. */
  memset (packed_cmd, 0, sizeof (packed_cmd));
  hs = (e2k_hs *) &packed_cmd[crnt_syll++]; 

  if (wc.lm)
    hs->lm = 0x1;

  if (wc.sw)
    hs->sw = 0x1;

  /* FIXME: wouldn't it be more correct to check `wc.ss.started' here to take
     into account the case of SS being equal to zero if it's possible at all,
     of course.  */
  if (wc.ss.started)
    {
      /* If the same internal lable is attached both to SS and CS0 (consider
         IBRANCH) or SS and CS1 (consider CALL) or SS and ALS0 (consider I{CALL,
	 BRANCH}D) give preference to CS0, CS1 and ALS0 respectively.

	 FIXME: ICALL is encoded in three syllables at once: SS, CS0 and CS1.
	 Despite the fact that the label eventually points to CS1, which is
	 probably OK as this is the most informative syllable, I suspect that
	 this case turns out to be workable only by chance . . .  */
      if (ss_ilabel != NULL
          && !((wc.cs0.set && cs0_ilabel == ss_ilabel)
               || (wc.cs1.set && cs1_ilabel == ss_ilabel)
	       || ((wc.busy_al & (1 << 0)) && wc.al[0].label == ss_ilabel)))
        {
          ilabels[ilabels_num].list = ss_ilabel;
          ilabels[ilabels_num++].off = 4 * crnt_syll;
        }

      hs->s = 1;
      packed_cmd[crnt_syll++] = wc.ss.val.word;
    }

  for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
    {
      if (wc.busy_al & (1 << i))
        {
          hs->al |= (u_int32_t) (1 << i);

          if (wc.al[i].label != NULL)
            {
              ilabels[ilabels_num].list = wc.al[i].label;
              ilabels[ilabels_num++].off = 4 * crnt_syll;
            }

          memcpy (&packed_cmd[crnt_syll++], &wc.al[i].val, sizeof (u_int32_t));
          if (wc.al[i].exp)
            {
              gas_assert (wc.al[i].exp->X_op == O_islocal);
              set_wc_reloc (((char *) &packed_cmd[crnt_syll - 1]
                             - (char *) packed_cmd),
                            4, wc.al[i].exp, 0, BFD_RELOC_E2K_ISLOCAL);
            }
        }
    }

  if (wc.cs0.set)
    {
      if (cs0_ilabel != NULL)
        {
          ilabels[ilabels_num].list = cs0_ilabel;
          ilabels[ilabels_num++].off = 4 * crnt_syll;
        }

      memcpy (&packed_cmd[crnt_syll++], &wc.cs0, sizeof (u_int32_t));
      hs->c |= 0x1;
      if (wc.cs0.pexp
          && (wc.cs0.pexp->X_op == O_symbol
              || wc.cs0.pexp->X_op == O_plt
              || wc.cs0.pexp->X_op == O_pref))
        {
          bfd_reloc_code_real_type rtype;

          if (wc.cs0.pexp->X_op == O_symbol)
            rtype = BFD_RELOC_E2K_DISP;
          else if (wc.cs0.pexp->X_op == O_plt)
            rtype = BFD_RELOC_E2K_PLT;
          else
            rtype = BFD_RELOC_E2K_PREF;

          /* I don't know whether this should be done here. At present
             X_add_number is corrected for ALL pc-relative relocs (not only
             for that associated with DISP) at the end of this function: a
             position of the syllable within the current wide command (WHERE)
             is taken into account. Therefore, to avoid duplication, comment
             the following line out.  */
#if 0
          wc.cs0.pexp->X_add_number += sizeof (u_int32_t) * (crnt_syll - 1);
#endif /* 0  */

          set_wc_reloc (((char *) &packed_cmd[crnt_syll - 1]
                         - (char *) packed_cmd),
                        4, wc.cs0.pexp, 1, rtype);
        }
    }

  if (mcpu >= 4)
    {
      static const e2k_ales dflt_ales = {.alef2 = {NONE_VALUE, EXT_VALUE}};
      if (((wc.busy_ales & (1 << 2)) != 0 && wc.ales[2] != dflt_ales.hword)
          || ((wc.busy_ales & (1 << 5)) != 0 && wc.ales[5] != dflt_ales.hword)
          || wc.explicit_ales25)
        {
          u_int16_t *ales25 = (u_int16_t *) &packed_cmd[crnt_syll++];

          if ((wc.busy_ales & (1 << 2)) != 0)
            memcpy (&ales25[1], &wc.ales[2], sizeof (u_int16_t));
          else
            memcpy (&ales25[1], &dflt_ales, sizeof (u_int16_t));

          if ((wc.busy_ales & (1 << 5)) != 0)
            memcpy (ales25, &wc.ales[5], sizeof (u_int16_t));
          else
            memcpy (ales25, &dflt_ales, sizeof (u_int16_t));
        }

    }


  if (wc.cs1.set)
    {
      if (cs1_ilabel != NULL)
        {
          ilabels[ilabels_num].list = cs1_ilabel;
          ilabels[ilabels_num++].off = 4 * crnt_syll;
        }

      memcpy (&packed_cmd[crnt_syll++], &wc.cs1, sizeof (u_int32_t));
      hs->c |= 0x2;
    }


  /* HS, SS, ALS*, CS0 and CS1 syllables can be placed before the middle point.*/
  hs->mdl = (crnt_syll - 1);

  /* It's time to accommodate half-syllables now. Meanwhile I have to
     deal only with ALES-half-syllables. */

  hsyllables = (u_int16_t *) &packed_cmd[crnt_syll];
  hsyllable_cntr = 0;
  for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
    {
      if (wc.busy_ales & (1 << i))
        {
          hs->ale |= (u_int32_t) (1 << i);

          if ((i == 2) || (i == 5))
            {
              if (mcpu < 4)
                {
                  static const e2k_ales dflt_ales =
                    {.alef2 = {NONE_VALUE, EXT_VALUE}};
                  gas_assert (wc.ales[i] == dflt_ales.hword);
                }
              else
                continue;
            }
          else
            {
              /* The order of half-syllables is rather strange. It seems that
                 the first half-syllable in a syllable occupies the high-order
                 half-word. I came to this conclusion after having studied the
                 code of cgk_WideInstructionPack in LAS, not after having read
                 iset.single .*/
              memcpy (hsyllables + (hsyllable_cntr & ~0x1) + 1 - (hsyllable_cntr & 0x1), &wc.ales[i], sizeof (u_int16_t));
              hsyllable_cntr++;
            }
        }
    }

  /* Take care of AASx half-syllables. Note, that the first AASx half-syllable
     may share a syllable with a trailing ALESx half-syllable.  */
  for (i = 0; i < 2; i++)
    {
      if ((wc.busy_aa2f1 & (3 << (2 * i))) != 0)
        {
          memcpy (hsyllables + (hsyllable_cntr & ~0x1) + 1
                  - (hsyllable_cntr & 0x1),
                  &wc.aa0f1[i], 2 * sizeof (u_int8_t));
          hsyllable_cntr++;
        }
    }

  for (i = 0; i < 4; i++)
    {
      if ((wc.busy_aa2f1 & (1 << i)) != 0)
        {
          memcpy (hsyllables + (hsyllable_cntr & ~0x1) + 1
                  - (hsyllable_cntr & 0x1),
                  &wc.aa2f1[i], sizeof (u_int16_t));

          if (aa2f1_ilabel[i] != NULL)
            {
              ilabels[ilabels_num].list = aa2f1_ilabel[i];
              /* Let OFF point to the start of the syllable containing this
                 AA2F1 half-syllable. Obviously, one may end up with two
                 internal labels corresponding to two different AA2F1 half-
                 syllables pointing to the same location (i.e. syllable).  */
              ilabels[ilabels_num++].off
                = 4 * crnt_syll + 2 * (hsyllable_cntr & ~0x1);
            }

          hsyllable_cntr++;
        }
    }
  
  /* Depending on the number of ALES* and AAS* half-syllables let us align on a
     syllable boundary. */
  hsyllable_cntr = (hsyllable_cntr + 1) & ~0x1;
  crnt_syll += hsyllable_cntr >> 1;

  /* It should be impossible to have more than 16 syllables occupied so far
     even on `elbrus-v{4,5}' having an additional syllable for `ALES{2,5}'.
     However, all subsequent increases of CRNT_SYLL and accesses to the related
     areas of PACKED_CMD[] should be checked for array boundary violations.  */
  gas_assert (crnt_syll <= 16);

  /* Count LTSes. */
  for (i = 7; i >= 0; i--)
    {
      int pos_msk = 1 << (((i >> 1) << 1) + 1 - (i & 0x1));
      if (wc.busy_lts & pos_msk)
        {
          lts_cntr = 1 + (i >> 1);
          break;
        }
    }

  for (i = 5; i >= 0; i--)
    {
      if (wc.cds[i].rlp_mrgc.mask)
        {
          cds_cntr = 1 + (i >> 1);
          break;
        }
    }

  if (wc.pls[2].needed != 0)
    wc.pls[1].needed = 1;

  if (wc.pls[1].needed != 0)
    wc.pls[0].needed = 1;


  pls_cntr = wc.pls[0].needed + wc.pls[1].needed + wc.pls[2].needed;
  hs->pl = pls_cntr;  
  
  /* Finally, given the total number of LTS*, PLS* and CDS*
     syllables we align on a double syllable boundary. */

  if ((crnt_syll + lts_cntr + pls_cntr + cds_cntr) & 0x1)
      crnt_syll++;
 
  /* The way I pack literals seems to be optimal only for 32-bit ones
     because of their idiotic order in a wide command. However, for
     16-bit ones which have a normal order (hi comes after lo) it
     looks bogus. The respective order (normal) of lts_lo and lts_hi
     also seems to be opposite to all other half-syllables (idiotic). */

  if (crnt_syll + lts_cntr <= 16)
    {
      u_int16_t *hlts;
      hlts = (u_int16_t *) &packed_cmd[crnt_syll];
      for (i = 2 * lts_cntr - 1; i >= 0; i--, hlts++)
	pack_plcmnt (i, hlts + ((i % 2) ? 1 : -1));
    }

  crnt_syll += lts_cntr;

  /* Here I pack PLS syllables. */
  
  for (i = 2; i >= 0; i--)
    {
      if (wc.pls[i].needed)
	{
	  if (crnt_syll < 16)
	    packed_cmd[crnt_syll] = wc.pls[i].val.word;

	  crnt_syll++;
	}
    }

  
  /* Here I pack CDS half-syllables. */ 

  if (crnt_syll + cds_cntr <= 16)
    {
      u_int16_t *hcds;

      hcds = (u_int16_t *) &packed_cmd[crnt_syll];
      for (i = 0; i < (cds_cntr << 1); i++)
	{
	  size_t hcds_idx = (i & ~0x1);

	  /* This is to make GAS place CDS syllables like LAS. Get rid of this
	     line to fall back to the original behaviour.  */
	  hcds_idx = 2 * cds_cntr - 2 - hcds_idx;

	  hcds_idx += 1 - (i & 0x1);
	  memcpy (hcds + hcds_idx, &wc.cds[i].val, sizeof (wc.cds[i].val));
	}
    }

  hs->cd = cds_cntr;
  crnt_syll += cds_cntr;

  /* One should end up with an even number of 32-bit syllables in the end
     taking into account that the length of a wide instruction in bytes is
     a multiple of 8.  */
  gas_assert (crnt_syll % 2 == 0);

  /* Now that we've determined the number of syllables in the current wide
     instruction check for overflow.  */
  if (crnt_syll > 16)
    {
      as_bad (_("wide instruction requires %d syllables which exceeds the "
		"maximal supported size of 16 ones"), crnt_syll);

      /* If you wish to provide verbose info on the oversized wide instruction
	 one day, consider implementing a special function which will count its
	 syllables once again and print them out instead of packing.  */

      /* It makes little sense to care about setting up internal labels and
	 relocations now . . .  */
      return;
    }

  {

    if (total_syllables == 634)
      total_syllables += 0;

    total_syllables += crnt_syll;
  }

  gas_assert ((crnt_syll & 0x1) == 0);
  hs->lng = (crnt_syll >> 1) - 1;

  if (wc.nop_nmb != 0xff)
    hs->nop = wc.nop_nmb;
  /* `nop' has been specified without a parameter. In such a case either treat
     it as a standalone `nop' if no other instructions are present within this
     wide command (i.e. leave `hs->nop' equal to zero) or encode it as `nop 1'
     otherwise. To determine if there are any other instructions within the
     wide command under consideration compare the word containing HS against
     zero.  */
  else if (packed_cmd[0] != 0)
    hs->nop = 1;

  for (i = 0; i < ilabels_num + 1; i++)
    {
      size_t start_off = i == 0 ? 0 : ilabels[i - 1].off;
      size_t end_off = (i < ilabels_num
                        ? ilabels[i].off : (size_t) 4 * crnt_syll);

      /* All this splitting of a frag into several subfrags is required in order
         to ensure that colon () outputs a label at the right position within a
         wide instruction. FIXME: can't I achieve that in another way?  */
      if (i > 0)
        {
          struct ilabel_list *list, *prev;
          for (list = ilabels[i - 1].list; list != NULL; list = prev)
            {
              colon (list->name);
              prev = list->prev;
              free (list);
            }
        }

      bufs[i] = frag_more (end_off - start_off);
      sub_frags[i] = frag_now;

      memcpy (bufs[i], (char *) packed_cmd + start_off, end_off - start_off);
    }

  for (i = 0; i < wc.reloc_cntr; i++)
    {
      int j;
      size_t start_off;
      expressionS subexp;
      memset (&subexp, 0, sizeof subexp);
      subexp.X_op = O_symbol;
      subexp.X_add_symbol = wc.relocs[i].exp->X_add_symbol;
      /* I've entirely forgotten about addend. I wonder, how all that (I mean a
         considerable part of BINUTILS testsuite along with dynamically linked
         programs using GLIBC) worked without this.  */
      subexp.X_add_number = wc.relocs[i].exp->X_add_number;

      if (wc.relocs[i].pcrel)
        subexp.X_add_number += wc.relocs[i].where;

      for (j = 0; j < ilabels_num + 1; j++)
        {
          size_t end_off = (j < ilabels_num
                            ? ilabels[j].off : (size_t) 4 * crnt_syll);

          if (end_off > (size_t) wc.relocs[i].where)
            break;
        }

      gas_assert (j < ilabels_num + 1);
      start_off = j == 0 ? 0 : ilabels[j - 1].off;


      fix_new_exp (sub_frags[j],
                   (wc.relocs[i].where - start_off + bufs[j]
                    - sub_frags[j]->fr_literal),
                   wc.relocs[i].size, &subexp, wc.relocs[i].pcrel,
                   wc.relocs[i].r_type);
    }
}


#define SETCMD_PARAM(name)      wc.cs1.val.fields.setcmd.name

#define SETR0_OPC       0
#define SETR1_OPC       1
#define SETEI_OPC       2
#define SETBR_OPC       4

static void
encode_setbr (int setup_opcode)
{
  if (wc.cs1.set)
    {
      as_bad ("cannot encode SETBR, CS1 syllable is already busy");
      return;
    }

  if ((wc.setcmd_args[SETBN_IDX] & ~setcmd_masks[SETBN_IDX]) == 0)
    {
      SETCMD_PARAM (setbn) = 1;
      SETCMD_PARAM (rsz) = wc.setcmd_args[SETBN_IDX] & setcmd_masks[SETBN_IDX];
      SETCMD_PARAM (rbs) = wc.setcmd_args[SETBN_IDX + 1] & setcmd_masks[SETBN_IDX + 1];
      SETCMD_PARAM (rcur) = wc.setcmd_args[SETBN_IDX + 2] & setcmd_masks[SETBN_IDX + 2];
    }

  if ((wc.setcmd_args[SETBP_IDX] & ~setcmd_masks[SETBP_IDX]) == 0)
    {
      SETCMD_PARAM (setbp) = 1;
      SETCMD_PARAM (psz) = wc.setcmd_args[SETBP_IDX] & setcmd_masks[SETBP_IDX];
    }

  if (setup_opcode)
    {
      SETCMD_PARAM (opc) = SETBR_OPC;
      start_cs1 ();
      wc.cs1.set = 1;
    }
}

typedef union {
  struct {
    unsigned x : 3;
    unsigned dbl : 1;
    unsigned nfx : 1;
    unsigned wsz : 7;
    unsigned rpsz : 5;
    unsigned type : 15;
  } fields;
  unsigned word;
} setr01_lts;

static literal_placement *
encode_setr0 (int setup_opcode)
{
  literal_placement *plcmnt;
  setr01_lts lts;
  lts.word  = 0x0;

  encode_setbr (0);

  plcmnt = &allowed_placements[crnt_lit++];
  plcmnt->size[0] = 2;
  plcmnt->pos[0] = 0;
  plcmnt->optimal_plcmnt_idx = -1;
  plcmnt->plcmnt_nmb = 1;

  /* There's no ALS we can back ref to.  */
  plcmnt->als_idx = 6;
  
  if ((wc.setcmd_args[SETTR_IDX] & ~setcmd_masks[SETTR_IDX]) == 0)
    {
      SETCMD_PARAM (settr) = 1;
      lts.fields.type = wc.setcmd_args[SETTR_IDX] & setcmd_masks[SETTR_IDX];
    }

  if ((wc.setcmd_args[SETWD_IDX] & ~setcmd_masks[SETWD_IDX]) == 0)
    {
      /* There is no field in CS1 indicating that SETWD is present, is there? */
      lts.fields.wsz = wc.setcmd_args[SETWD_IDX] & setcmd_masks[SETWD_IDX];
      
      /* Is nfx specified explicitly? */
      if ((wc.setcmd_args[SETWD_IDX + 1] & ~setcmd_masks[SETWD_IDX + 1]) == 0)
        lts.fields.nfx = (wc.setcmd_args[SETWD_IDX + 1]
                          & setcmd_masks[SETWD_IDX + 1]);
      else
        /* Set implicit 0 as LAS does. */
        lts.fields.nfx = 0;

      /* Is dbl specified explicitly? */
      if ((wc.setcmd_args[SETWD_IDX + 2] & ~setcmd_masks[SETWD_IDX + 2]) == 0)
        lts.fields.dbl = (wc.setcmd_args[SETWD_IDX + 2]
                          & setcmd_masks[SETWD_IDX + 2]);
      else
        /* See if dbl field should be implicitly set to 0.  */
        lts.fields.dbl = 0;
    }
  
  /* This is a temporary hack. */
  plcmnt->exp.X_op = O_constant;
  plcmnt->exp.X_add_number = lts.word;

  if (setup_opcode)
    {
      SETCMD_PARAM (opc) = SETR0_OPC;
      start_cs1 ();
      wc.cs1.set = 1;
    }

  return plcmnt;
}

static void
encode_setr1 (void)
{
  literal_placement *plcmnt = encode_setr0 (0);
  setr01_lts lts;

  lts.word = (unsigned) plcmnt->exp.X_add_number;
  lts.fields.rpsz = wc.setcmd_args[VFRPSZ_IDX] & setcmd_masks[VFRPSZ_IDX];

  /* This is a temporary hack. */
  plcmnt->exp.X_op = O_constant;
  plcmnt->exp.X_add_number = lts.word;

  SETCMD_PARAM (opc) = SETR1_OPC;
  start_cs1 ();
  wc.cs1.set = 1;
}

static void
encode_setei (void)
{
  if (wc.cs1.set)
    {
      as_bad ("cannot encode SETEI, CS1 syllable is already busy");
      return;
    }

  /* One shouldn't find himself here if the only parameter to this instruction
     hasn't been specified.  */
  gas_assert ((wc.setcmd_args[SETEI_IDX] & ~setcmd_masks[SETEI_IDX]) == 0);
  /* FIXME: `& setcmd_masks[]' seems to be excessive because I've already
     verified that parameters fit the corresponding bitfields. Note that the
     27-th bit is implicitly set to zero this way.  */
  wc.cs1.val.word = wc.setcmd_args[SETEI_IDX] & setcmd_masks[SETEI_IDX];
  SETCMD_PARAM (opc) = SETEI_OPC;
  start_cs1 ();
  wc.cs1.set = 1;
}

static void
encode_setsft (void)
{
  if (wc.cs1.set)
    {
      as_bad ("cannot encode SETSFT, CS1 syllable is already busy");
      return;
    }

  gas_assert (wc.setsft_seen);
  /* It's the 27-th bit containing 1 that makes the difference between SETEI
     and SETSFT.  */
  wc.cs1.val.word = 1 << 27;
  SETCMD_PARAM (opc) = SETEI_OPC;
  start_cs1 ();
  wc.cs1.set = 1;
}



static void
encode_setcmds (void)
{
  if ((wc.setcmd_args[VFRPSZ_IDX] & ~setcmd_masks[VFRPSZ_IDX]) == 0)
    encode_setr1 ();
  else if (((wc.setcmd_args[SETWD_IDX] & ~setcmd_masks[SETWD_IDX]) == 0)
           || ((wc.setcmd_args[SETTR_IDX] & ~setcmd_masks[SETTR_IDX]) == 0))
    encode_setr0 (1);
  else if (((wc.setcmd_args[SETBP_IDX] & ~setcmd_masks[SETBP_IDX]) == 0)
           || ((wc.setcmd_args[SETBN_IDX] & ~setcmd_masks[SETBN_IDX]) == 0))
    encode_setbr (1);

  /* SETEI and SETSFT are not packed into `SETBR' or `SETR{0,1}' along with the
     above set instructions. Therefore no `else' here . . .  */
  if ((wc.setcmd_args[SETEI_IDX] & ~setcmd_masks[SETEI_IDX]) == 0)
    encode_setei ();

  if (wc.setsft_seen)
    encode_setsft ();
}

static void
check_for_cmp (u_int32_t cmp_num)
{
  if (! (wc.explicit_int_cmp_mask & (1 << cmp_num)))
    as_bad (_("no integer comparison with an explicitly"
              " specified ALC matches %%cmp%d in ctcond"),
            cmp_num);
}

/* Verify the correctness and self-consistency of instructions encoded in
   PLSx syllables. TODO(?): it could be used also either to barf on useless PLS
   instructions having no effect on the output or silently discard them. Note
   that OBJDUMP doesn't print mnemonics for them.   */
static void
verify_pls_insns (void)
{
  int i;
  int clp_cascading[3] = {0, 0, 0};

  for (i = 0; i < 3; i++)
    {
      int j;

      if ((wc.explicit_lp_mask & (1 << (4 + i))) == 0)
        {
          /* There is no such CLP. Verify that its PASS part hasn't been
             encoded by the user before continuing.  */
          if ((wc.explicit_lp_mask & (1 << (7 + i))) != 0)
            as_bad (_("undefined @p%d passed to a global predicate via"
                      " {C/M}LP%d"), 4 + i, i);

          continue;
        }

      for (j = 0; j < 2; j++)
        {
          int cascading;
          int incoming = wc.clp_incoming_lp[i][j];

          if ((wc.explicit_lp_mask & (1 << incoming)) == 0)
            {
              as_bad (_("undefined @p%d used as an incoming parameter"
                        " for CLP%d"), incoming, i);

              /* If this is either of `@p{4,5,6}' the calculation of cascading
                 below makes no sense. Just return.  */
              if (incoming >= 4)
                return;
            }

          cascading = incoming < 4 ? 1 : (clp_cascading[incoming - 4] + 1);
          if (cascading > clp_cascading[i])
            {
              clp_cascading[i] = cascading;
              /* FIXME: it's not quite clear from `iset-vX.single' if this
                 limitation applies to MLP. However, LAS believes that it
                 does.  */
              if (cascading > 2)
                as_bad (_("maximal supported cascading of 2 exceeded for "
                          "{C/M}LP%d"), i);
            }
        }
    }
}

static void
end_wide_command (void)
{
  do {
    /* If instruction has not been met then it's not a wide
       command at all. Well, `instruction_met' and `inside_wide_command'
       essenses have already become a bit misleading. e2k_start_line_hook
       looks really bogus now.

       I guess that it makes little sense to finalize the current wide command
       if parse errors have been met.  */

    CHECK (instruction_met && !parse_errors_met);

    verify_pls_insns ();

    if (wc.ss.started && wc.ss.set.ctcond)
      {
        u_int32_t ctcond = wc.ss.val.fields.ctcond;
        u_int32_t ct = (ctcond & 0x1e0) >> 5;
        
        if (ct == 8)
          {
            int i;
            /* This is `%dt_al' control transfer condition.  */
            u_int32_t mask = (ctcond & 0xf);

            for (i  = 0; i < 4; i++)
              {
                if (mask & (1 << i))
                  {
                    /* Get the related ALC number.  */
                    int j = i < 2 ? i : i + 1;
                    if (! (wc.explicit_alces & (1 << j)))
                      as_bad (_("no speculative operation with an explicit"
                                " ALC matches %%dt_al[%d] in control transfer"
                                " condition"), j);
                  }
              }
          }
        if (ct == 9)
          {
            /* This is either of `%c{m,l}pX' conditions.  */
            u_int32_t type = (ctcond & 0x18) >> 3;

            /* Either of `%cmp{0,1,3,4}' conditions.  */
            if (type == 0)
              {
                u_int32_t cmp_num = (ctcond & 0x6) >> 1;
                if (cmp_num >= 2)
                  cmp_num++;

                check_for_cmp (cmp_num);
              }
            else if (type == 1)
              {
                u_int32_t cmp_jk = (ctcond & 0x4) >> 2;
                check_for_cmp (cmp_jk ? 3 : 0);
                check_for_cmp (cmp_jk ? 4 : 1);
              }
            else if (type == 2)
              {
                u_int32_t clp_num = (ctcond & 0x6) >> 1;

                if (! (wc.explicit_lp_mask & (1 << (clp_num + 4))))
                  as_bad (_("no explicitl {C/M}LP operation producing @p%d"
                            " matches %%clp%d in control transfer condition"),
                          clp_num + 4, clp_num);
              }
          }
      }

    encode_setcmds ();
    CHECK_MSG (place_literals (), _("cannot place literals"));
    finish_alses ();
    place_alses ();
    pack_wide_command ();
  }
  while (0);

  /* Recall why this is done here . . .  */
  inside_wide_command = 0;
  instruction_met = 0;
  parse_errors_met = 0;
}


void
e2k_start_line_hook (char c)
{
  /* A wide command consisting of just one instruction
     may very well do without curly brackets. */

  if (inside_wide_command && brace_cntr == 0)
    end_wide_command ();

  if (c == '{')
    {
      if (brace_cntr > 0)
        as_bad ("unexpected `{'");


      if (preprocess_mode)
        pending_preprocess_brace = 1;


      start_wide_command ();
      brace_cntr++;
      /* This has been added so as to ensure that an empty wide command `{}'
         will be interpreted as a standalone `nop' rather than "nothing at all".
         They say there's a bug in ecomp.rel-20-0 which makes it emit such
         commands instead of regular `nop's. The failure of `e2k-linux-as' to
         interpret them appropriately led to an unworkable kernel compiled with
         `ecomp.rel-20-0/lcc_i --cheat-as': in particular it was impossible to
         `rlogin -l malakhov monocub-pc-2' because of (?) problems with NFS.  */
      instruction_met = 1;
    }
  else if (c == '}')
    {
      if (preprocess_mode)
        {
          /* Keep in mind that empty wide instructions `{ }' are considered to
             be NOPs, i.e. belong to synchronous code.  */
          if (pending_preprocess_brace)
            {
              if (preprocess_async == 1)
                {
                  puts (".text");
                  preprocess_async = 0;
                }

              preprocess_insn_cntr++;
              printf ("\n! Instruction #%d\n%s", preprocess_insn_cntr,
                      pending_preprocess_brace ? "{\n" : "");

              pending_preprocess_brace = 0;
            }

          puts ("}");
        }

      if (!inside_wide_command)
        as_bad ("unexpected `}'");

      end_wide_command ();
      brace_cntr--;
      /* Do this here to be on the safe side . . .  */
      start_wide_command ();
    }
  else if (brace_cntr == 0 && c != '\0')
    {
      /* The previous command must have been finished
         already. */
      gas_assert (!inside_wide_command);
      start_wide_command ();
    }
}

void
e2k_cleanup_hook ()
{
  /* I hope this hook will let me end the last wide command that
     is not surrounded with braces. '\0' means don't start the
     next one. */
  e2k_start_line_hook ('\0');
}

/* Trying to emulate las behavior. In case a symbol is defined in
   a standard executable section or in a user-defined section and
   its type is not specified (STT_NOTYPE), default to STT_FUNC. */

/* FIXME: Am  I going to have a function symbol for each "labxx:"
   inside a real function? LAS does not output such (non-global)
   labels to an object file. */

void
e2k_adjust_symtab (void)
{
  symbolS *sym;

  for (sym = symbol_rootP; sym != NULL; sym = symbol_next (sym))
    {
      const struct bfd_elf_special_section *spec;
      asymbol *bfd_sym = symbol_get_bfdsym (sym);
      Elf_Internal_Sym *elf_sym = &elf_symbol (bfd_sym)->internal_elf_sym;
      
      if ((spec = _bfd_elf_get_sec_type_attr (bfd_sym->the_bfd,
                                              bfd_sym->section))
          && !(spec->attr & SHF_EXECINSTR))
	continue;

      /* Unexpectedly enough ELF_ST_TYPE (elf_sym->st_info) does not mean
         anything when swapping out a symbol to an object file. At least
         if elf_backend_get_symbol_type method is not defined. STT_NOTYPE
         is swapped out to an object file if neither of the flags below is
         set (see elf.c). */

      /* I don't want to set STT_FUNC for symbols of zero size (labels).  */
      if (((bfd_sym->flags & (BSF_THREAD_LOCAL | BSF_GNU_INDIRECT_FUNCTION
                              | BSF_FUNCTION | BSF_OBJECT | BSF_RELC
                              | BSF_SRELC)) == 0)
          && elf_sym->st_size)
        bfd_sym->flags |= BSF_FUNCTION;


      if (ELF_ST_TYPE (elf_sym->st_info) == STT_NOTYPE)
	elf_sym->st_info = ELF_ST_INFO (ELF_ST_BIND (elf_sym->st_info),
                                        STT_FUNC);
    }
}


/* Let us try to remove leading `$' from symbol names
   to be LAS-compatible. I'm reluctant to fix symbol
   name printing inside a compiler. */

char *
e2k_canonicalize_symbol_name (char *name)
{
  if (*name == '$')
    {
      char *s;
      for (s = name; *s != '\0'; s++)
        *s = *(s + 1);
    }
  return name;
}

#if 0

void
e2k_cons (expressionS *exp, int size)
{
  expression (exp);
}

#endif /* 0 */

int
parse_loop_mode_args (char **pstr ATTRIBUTE_UNUSED,
                      const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  wc.lm = 1;
  return 1;
}

int
parse_set_mark_args (char **pstr ATTRIBUTE_UNUSED,
                     const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  wc.sw = 1;
  return 1;
}


int
parse_alc_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;

  /* FIXME: I guess such an approach isn't endian-safe . . .  */
  union {
    struct {
      u_int8_t alct : 1;
      u_int8_t alcf : 1;
    } s;
    u_int8_t v;
  } alc;

  start_ss_syllable (1);

  if (parse_number (&str, &alc.v, sizeof (alc.v), 0))
    {
      SET_FIELD (ss, alct, alc.s.alct, 0);
      SET_FIELD (ss, alcf, alc.s.alcf, 0);
      *pstr = str;
      return 1;
    }

  do
    {
      u_int8_t alcft;

      CHECK_MSG (slurp_str (&str, "alcf="), _("`alcf=' expected"));
      CHECK_MSG (parse_number (&str, &alcft, sizeof (alcft), 0), _("alcf value expected"));
      if (alcft > 1)
        as_bad (_("invalid alcf value; should be either 0 or 1"));
      SET_FIELD (ss, alcf, alcft, 0);

      CHECK_MSG (slurp_char (&str, ','), _("`,' expected"));
      CHECK_MSG (slurp_str (&str, "alct="), _("`alct=' expected"));
      CHECK_MSG (parse_number (&str, &alcft, sizeof (alcft), 0), _("alct value expected"));
      if (alcft > 1)
        as_bad (_("invalid alct value; should be either 0 or 1"));
      SET_FIELD (ss, alct, alcft, 0);

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_abn_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;

  start_ss_syllable (1);

  /* FIXME: I guess such an approach isn't endian-safe . . .  */
  union {
    struct {
      u_int8_t abnt : 1;
      u_int8_t abnf : 1;
    } s;
    u_int8_t v;
  } abn;

  start_ss_syllable (1);

  if (parse_number (&str, &abn.v, sizeof (abn.v), 0))
    {
      SET_FIELD (ss, abnt, abn.s.abnt, 0);
      SET_FIELD (ss, abnf, abn.s.abnf, 0);
      *pstr = str;
      return 1;
    }

  do
    {
      u_int8_t abnft;

      CHECK_MSG (slurp_str (&str, "abnf="), _("`abnf=' expected"));
      CHECK_MSG (parse_number (&str, &abnft, sizeof (abnft), 0), _("abnf value expected"));
      if (abnft > 1)
        as_bad (_("invalid abnf value; should be either 0 or 1"));
      SET_FIELD (ss, abnf, abnft, 0);

      CHECK_MSG (slurp_char (&str, ','), _("`,' expected"));
      CHECK_MSG (slurp_str (&str, "abnt="), _("`abnt=' expected"));
      CHECK_MSG (parse_number (&str, &abnft, sizeof (abnft), 0), _("abnt value expected"));
      if (abnft > 1)
        as_bad (_("invalid abnt value; should be either 0 or 1"));
      SET_FIELD (ss, abnt, abnft, 0);

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_abp_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;

  start_ss_syllable (1);

  /* FIXME: I guess such an approach isn't endian-safe . . .  */
  union {
    struct {
      u_int8_t abpt : 1;
      u_int8_t abpf : 1;
    } s;
    u_int8_t v;
  } abp;

  start_ss_syllable (1);

  if (parse_number (&str, &abp.v, sizeof (abp.v), 0))
    {
      SET_FIELD (ss, abpt, abp.s.abpt, 0);
      SET_FIELD (ss, abpf, abp.s.abpf, 0);
      *pstr = str;
      return 1;
    }

  do
    {
      u_int8_t abpft;

      CHECK_MSG (slurp_str (&str, "abpf="), _("`abpf=' expected"));
      CHECK_MSG (parse_number (&str, &abpft, sizeof (abpft), 0), _("abpf value expected"));
      if (abpft > 1)
        as_bad (_("invalid abpf value; should be either 0 or 1"));
      SET_FIELD (ss, abpf, abpft, 0);

      CHECK_MSG (slurp_char (&str, ','), _("`,' expected"));
      CHECK_MSG (slurp_str (&str, "abpt="), _("`abpt=' expected"));
      CHECK_MSG (parse_number (&str, &abpft, sizeof (abpft), 0), _("abpt value expected"));
      if (abpft > 1)
        as_bad (_("invalid abpt value; should be either 0 or 1"));
      SET_FIELD (ss, abpt, abpft, 0);

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_abg_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;

  start_ss_syllable (1);
  do
    {
      u_int8_t abg;
      /* Interestingly enough, for ABG they prefer not to explicitly split
         arguments into `abgi=' and `abgd=', but to use a dumb number
         instead.  */
      CHECK_MSG (parse_number (&str, &abg, sizeof (abg), 0),
                 _("abg value expected"));
      if (abg > 3)
        as_bad (_("invalid abg value: should lie in the interval from 0 to 3"));
      SET_FIELD (ss, abg, abg, 0);

      *pstr = str;
      return 1;
    }
  while (0);

  return 0;
}

int
parse_vfdi_args (char **pstr ATTRIBUTE_UNUSED,
                 const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);
  SET_FIELD (ss, vfdi, 1, 0);
  return 1;
}

static int
parse_and_encode_rpc_optional (char **pstr)
{
  e2k_pred pred;

  /* Missing RPC is quite OK.  */
  if (slurp_char (pstr, '?') == 0)
    return 1;

  /* Let `%pcntX' be used in place of RPC as iset-v{X>=3}.single doesn't
     seem to prohibit this.  */
  if (! parse_pred (pstr, &pred, 1))
    return 0;

  if (mcpu == 2)
    {
      /* The predicate has been successfully parsed, but it is not supported
	 for this CPU.  */
      as_bad (_("Recovery Point Conditions are not supported for elbrus-v2"));
      return 0;
    }

  /* We are called before RLP and MRGC predicates are assigned to CDS half-
     syllables, therefore, the hi part of CDS0 from which allocation typically
     starts should be free.  */
  gas_assert (wc.cds[0].rlp_mrgc.mask == 0);

  /* Note that RPC has the same encoding as MRGC0 (see C.10.2; this lets later
     encoded MRGC0 predicates share the hi part of CDS0 with us) and ...  */
#define RPC MRGC0
  wc.cds[0].rlp_mrgc.opc = RPC;

  /* ... this is the mask value irrelevant to MRGC0 (1, 2 and 4 are used to
     encode ALC{0,1,2} MRGC0 acts on respectively) that distinguishes them.  */
  wc.cds[0].rlp_mrgc.mask = 0x8;
  wc.cds[0].rlp_mrgc.pred = pred.pred_fld;

  if (pred.negated)
    wc.cds[0].rlp_mrgc.neg = 0x4;

  return 1;
}

/* Starting from elbrus-v3 SRP can't be encoded together with CRP as this
   combination of bits is used for SLRP, whereas on elbrus-v2 this is
   formally possible. However, do these instructions together make any
   sense even on elbrus-v2? This is rather doubtful which is why this
   combination is prohibited for all isets by virtue of `SET_FIELD (..,
   dfl = 0)'. FIXME: more intuitive error messages should be emitted on
   an attempt to combine these instructions.  */
int
parse_srp_args (char **pstr,
                const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);

  /* Starting from iset-v3.single SRP implies `SS.(crp aka rp_opc_lo) == 0'
     whereas `SS.crp == 1' corresponds to SLRP.  */
  SET_FIELD (ss, crp, 0, 0 /* ensure that it can't be overridden!  */);
  SET_FIELD (ss, srp, 1, 0);

  return parse_and_encode_rpc_optional (pstr);
}

int
parse_crp_args (char **pstr,
                const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);

  SET_FIELD (ss, crp, 1, 0);
  /* Starting from iset-v3.single CRP implies SS.(srp aka rp_opc_hi) == 0.  */
  SET_FIELD (ss, srp, 0, 0 /* ensure that it can't be overridden!  */);

  return parse_and_encode_rpc_optional (pstr);
}

int
parse_slrp_args (char **pstr,
		 const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);

  /* SLRP appeared in iset-v3 and requires `SS.(crp aka rp_opc_lo) == SS.(srp
     aka rp_opc_hi) == 1'.  */
  SET_FIELD (ss, crp, 1, 0 /* ensure that it can't be overridden!  */);
  SET_FIELD (ss, srp, 1, 0);

  return parse_and_encode_rpc_optional (pstr);
}

int
parse_bap_args (char **pstr ATTRIBUTE_UNUSED,
                const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  start_ss_syllable (1);
  SET_FIELD (ss, bap, 1, 0);

  /* Set SS.ipd to 2 BY DEFAULT (i.e. it can be overridden by a user
     explicitly). Is it the right thing to do here? It seems that LAS does so
     when it sees BAP as well as EAP (see below) . . .  To be revisited.  */
  SET_FIELD (ss, ipd, default_ipd, 1);

  /* FIXME: produce an error if there are any arguments.  */
  return 1;
}

int
parse_eap_args (char **pstr ATTRIBUTE_UNUSED,
                const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{ 
  start_ss_syllable (1);
  /* If `ss.eap' has been explicitly set to 1 by the preceding EAP, just bail
     out to prevent SET_FIELD from generating an error message. It turns out to
     be that LCC can generate two EAPs within the same wide instruction.  */
  if (wc.ss.set.eap
      && wc.ss.dflt.eap == 0
      && wc.ss.val.fields.eap == 1)
    return 1;

  SET_FIELD (ss, eap, 1, 0);
  SET_FIELD (ss, ipd, default_ipd, 1);
  return 1;
}


static int
encode_elp (e2k_pred *pgp, u_int8_t spred, e2k_pred *plp)
{
  int idx;
  int is_even;
  u_int8_t elp;

  if (plp->pred_num > 3)
    {
      as_bad (_("only @p0, @p1, @p2 and @p3 can be used to store the result"
                " of ELP"));
      return 0;
    }

  idx = plp->pred_num / 2;
  is_even = plp->pred_num % 2 == 0;

  elp = pgp->pred_num == -1 ? spred : (0x60 | pgp->pred_num);

  /* Can I further reduce the duplication here?  */
  if (is_even)
    {
      SET_FIELD (pls[idx], elp0, elp, 0);
    }
  else
    {
      SET_FIELD (pls[idx], elp1, elp, 0);
    }

  wc.pls[idx].needed = 1;
  wc.explicit_lp_mask |= 1 << plp->pred_num;

  return 1;
}

static int
encode_clp_mlp_pass (e2k_pred *plp, e2k_pred *pgp)
{
  int idx;

  if (plp->pred_num < 4)
    {
      as_bad (_("only @p4, @p5 and @p6 can be used to pass the result"
                " of {C/M}LP to %%pred"));
      return 0;
    }

  idx = plp->pred_num - 4;

  SET_FIELD (pls[idx], clp_vdst, 0x1, 0);
  SET_FIELD (pls[idx], clp_pdst, pgp->pred_num, 0);

  /* This way MLP `pass'es are kept track of. This is required to prevent
     the usage of undefined local predicates in them.  */
  wc.explicit_lp_mask |= 1 << (7 + idx);
  return 1;
}

int
parse_pass_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *str = *pstr;
  e2k_pred pred, lpred;
  u_int8_t spred = 0;

  do {
    if (parse_pred (&str, &pred, 0) || parse_spred (&str, &spred))
      {
        if (pred.pred_num != -1 && pred.negated)
          {
            as_bad (_("a negated predicate can't be used as the source"
                      " for pass in ELP"));
            break;
          }

        CHECK_MSG (slurp_char (&str, ','), _("comma expected"));
        CHECK_MSG (parse_local_pred (&str, &lpred),
                   _("local predicate expected as the destination for pass"
                     " in ELP"));
        CHECK_MSG (! lpred.negated, _("a negated local predicate can't be used"
                                      " as the destination for pass in ELP"));
        if (!encode_elp (&pred, spred, &lpred))
          break;
      }
    else if (parse_local_pred (&str, &lpred))
      {
        if (lpred.negated)
          {
            as_bad (_("a negated local predicate can't be used as the source"
                      " for pass in {C/M}LP"));
            break;
          }

        CHECK_MSG (slurp_char (&str, ','), _("comma expected"));
        CHECK_MSG (parse_pred (&str, &pred, 0),
                   _("global predicate expected as the destination for pass"
                     " in {C/M}LP"));

        CHECK_MSG (! pred.negated, _("a negated predicate can't be used as the"
                                     " destination for pass in {C/M}LP"));

        if (! encode_clp_mlp_pass (&lpred, &pred))
          break;
      }
    else
      {
        as_bad (_("either of %%lcntex, %%spred, %%pred%s or @p expected as "
		  "the first parameter for `pass'"),
		mcpu >= 3 ? ", %rndpred" : "");
        return 0;
      }

    *pstr = str;
    return 1;
  }
  while (0);

  return 0;
}

static int
encode_clp_mlp (e2k_pred *plp0, e2k_pred *plp1, e2k_pred *plp2, int opc)
{
  const char *err = NULL;
  int idx;

  if (plp2->pred_num < 4)
    {
      as_bad (_("only @p4, @p5 and @p6 can be used to store the result"
                " of {C/M}LP"));
      return 0;
    }

  idx = plp2->pred_num - 4;

  /* Check for acceptable source local predicates for {C/M}LP according to
     C.10.1.2 and C.10.1.3 respectively.  */
  if (idx == 0 && (plp0->pred_num > 1 || plp1->pred_num > 1))
    err = "@p0 and @p1";
  else if (idx == 1 && (plp0->pred_num > 4 || plp1->pred_num > 4))
    err = "@p0, @p1, @p2, @p3 and @p4";
  else if (plp0->pred_num > 5 || plp1->pred_num > 5)
    err = "@p0, @p1, @p2, @p3, @p4 and @p5";

  if (err)
    {
      as_bad (_("only `%s' can be used as incoming parameters for {C/M}LP%d"),
              err, idx);
      return 0;
    }
    

  /* opc for andp. */
  SET_FIELD (pls[idx], clp_opc, opc, 0);
  SET_FIELD (pls[idx], clp_neg0, ((plp0->negated) ? 0x1 : 0x0), 0);
  SET_FIELD (pls[idx], clp_p0, plp0->pred_num, 0);
  SET_FIELD (pls[idx], clp_neg1, ((plp1->negated) ? 0x1 : 0x0), 0);
  SET_FIELD (pls[idx], clp_p1, plp1->pred_num, 0);

  wc.pls[idx].needed = 1;

  /* This is required to implement a check for meaningful `%clpX' conditions.
     It's inacceptable to rely on PLS.needed since the one with zero contents
     may be added implicitly for consistency of the wide instruction. Consider
     a rather synthetic situation in which the user relies on PLS0 and PLS2 to
     do the job.  */
  wc.explicit_lp_mask |= 1 << (idx + 4);

  wc.clp_incoming_lp[idx][0] = plp0->pred_num;
  wc.clp_incoming_lp[idx][1] = plp1->pred_num;

  return 1;
}

static int
parse_clp_mlp_args (char **pstr, const e2k_opcode_templ *op ATTRIBUTE_UNUSED,
                    int opc)
{
  char *str = *pstr;
  e2k_pred lpred1, lpred2, lpred3;

  do {
     CHECK_MSG (parse_local_pred (&str, &lpred1),
                _("local predicate expected as the first source parameter"
                  " for {C/M}LP"));

     CHECK_MSG (slurp_char (&str, ','), _("comma expected at `%s'"), str);

     CHECK_MSG (parse_local_pred (&str, &lpred2),
                _("local predicate expected as the second source parameter"
                  " for {C/M}LP"));

     CHECK_MSG (slurp_char (&str, ','), _("comma expected at `%s'"), str);

     CHECK_MSG (parse_local_pred (&str, &lpred3),
                _("local predicate expected as the destination"
                  " for {C/M}LP"));

     CHECK_MSG (! lpred3.negated,
                _("a negated local predicate can't be used as the destination"
                  " for {C/M}LP"));

     if (! encode_clp_mlp (&lpred1, &lpred2, &lpred3, opc))
       break;

     *pstr = str;
     return 1;
  } while (0);

  return 0;
}

int
parse_andp_args (char **pstr, const e2k_opcode_templ *op)
{
  return parse_clp_mlp_args (pstr, op, 0);
}

int
parse_landp_args (char **pstr, const e2k_opcode_templ *op)
{
  return parse_clp_mlp_args (pstr, op, 1);
}

int
parse_movep_args (char **pstr, const e2k_opcode_templ *op)
{
  return parse_clp_mlp_args (pstr, op, 3);
}



int
parse_cpl_args (char **pstr,
                const e2k_opcode_templ *op ATTRIBUTE_UNUSED)
{
  char *s = *pstr;

  if (brace_cntr != 0)
    {
      as_bad (_("combined predicate logic command shouldn't be used within "
                "a wide command"));
      return 0;
    }

  do {
    int clp_opc;
    e2k_pred src1, src2, dst;
    e2k_pred lp0, lp1, lp4;

    CHECK_MSG (parse_pred (&s, &src1, 0), _("src1 predicate missing"));
    CHECK_MSG (slurp_char (&s, ','), _("comma after src1 expected"));
    CHECK_MSG (parse_pred (&s, &src2, 0), _("src2 predicate missing"));
    CHECK_MSG (slurp_char (&s, ','), _("comma after src2 expected"));
    CHECK_MSG (parse_pred (&s, &dst, 0), _("src2 predicate missing"));
    CHECK_MSG (!dst.negated, _("dst predicate can't be negated"));

    clp_opc = strcmp (op->name, "clpandp") == 0 ? 0 : 1;

    lp0.negated = src1.negated;
    lp0.pred_fld = lp0.pred_num = 0;

    lp1.negated = src2.negated;
    lp1.pred_fld = lp1.pred_num = 1;

    lp4.negated = 0;
    lp4.pred_fld = lp4.pred_num = 4;

    /* Hopefully, all local predicates created above are OK and the following
       calls have no chance of failing . . .  */
    encode_elp (&src1, 0, &lp0);
    encode_elp (&src2, 0, &lp1);
    encode_clp_mlp (&lp0, &lp1, &lp4, clp_opc);
    encode_clp_mlp_pass (&lp4, &dst);

    *pstr = s;
    return 1;
  }
  while (0);

  return 0;
}


void
e2k_init ()
{
  init_opcode_templs ();
}


static char *
e2k_end_of_match (char *cont, const char *what)
{
  int len = strlen (what);

  if (strncasecmp (cont, what, strlen (what)) == 0
      && ! is_part_of_name (cont[len]))
    return cont + len;

  return NULL;
}


int
e2k_parse_name (char *name, expressionS *e, char *nextcharP)
{
  if (*nextcharP ==  '@')
    {
      int type = 0;
      char *next_end;

      if (((next_end = e2k_end_of_match (&input_line_pointer[1], "GOTOFF"))
           && (type = O_gotoff))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "GOT"))
              && (type = O_got))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "GOTPLT"))
              && (type = O_gotplt))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "TLS_LE"))
              && (type = O_tls_le))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "TLS_IE"))
              && (type = O_tls_ie))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "TLS_GDMOD"))
              && (type = O_tls_gdmod))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "TLS_GDREL"))
              && (type = O_tls_gdrel))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "TLS_DTPREL"))
              && (type = O_tls_dtprel))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "PLT"))
              && (type = O_plt))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "ISLOCAL"))
              && (type = O_islocal))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "SIZE"))
              && (type = O_size))
          || (e2k_arch_size == 128
              && ((next_end = e2k_end_of_match (&input_line_pointer[1],
						"AP_GOT"))
		  || (next_end = e2k_end_of_match (&input_line_pointer[1],
						   "P_GOT")))
              && (type = O_ap_got))
          || (e2k_arch_size == 128
              && ((next_end = e2k_end_of_match (&input_line_pointer[1],
						"PL_GOT"))
		  || (next_end = e2k_end_of_match (&input_line_pointer[1],
						   "P_PLT")))
              && (type = O_pl_got))
          || ((next_end
               = e2k_end_of_match (&input_line_pointer[1], "ISLOCAL32"))
              && (type = O_islocal32))
          || ((next_end = e2k_end_of_match (&input_line_pointer[1], "ABS"))
              && (type = O_symbol))
	  || (e2k_arch_size == 128
              && (next_end = e2k_end_of_match (&input_line_pointer[1], "AP"))
              && (type = O_ap))
          || (e2k_arch_size == 128
              && (next_end = e2k_end_of_match (&input_line_pointer[1], "PL"))
              && (type = O_pl))
	  || ((next_end = e2k_end_of_match (&input_line_pointer[1], "DYNOPT"))
              && (type = O_dynopt))
	  )
        {
	  /* It's the place where the start of a symbol reference with an
	     explicitly specified `@RELOCATION' should be remembered for the
	     sake of preprocessing mode. As for symbols without an explicitly
	     specified relocation or local labels they are treated in `gas/
	     expr.c'.  */
	  symbol_ptr = name;

          memset (e, 0, sizeof *e);
          e->X_op = type;
          e->X_add_symbol = symbol_find_or_make (name);

          /* This sequence is borrowed from `tc-sh.c'. Find out what these
             actions are really needed for.  */

          *input_line_pointer = *nextcharP;
          input_line_pointer = next_end;
          *nextcharP = *input_line_pointer;
          *input_line_pointer = '\0';

          /* By returning one we actually restore the character at
             INPUT_LINE_POINTER to its previous value (see expr.c). What was
             the point in setting it to zero a line above then?  */
          return 1;
        }
      else if ((next_end = e2k_end_of_match (&input_line_pointer[1], "PCREL")))
        {
          memset (e, 0, sizeof *e);
          e->X_op = O_pc;
          e->X_add_symbol = symbol_find_or_make (name);

          /* Return 1 or else all my efforts will have no effect.  */
          return 1;
        }
      else
        as_bad (_("unknown relocation `@%s'"), &input_line_pointer[1]);
    }
  else if (e2k_arch_size != 128)
    {
      /* Note that `e2k_canonicalize_symbol_name ()' is called from within
         `symbol_find_or_make ()' below, therefore, here I should take a
         possible `$' prefix before a symbol name into account. Another case
         when the dollar is missing should be considered as well now that we are
         going to get rid of this awful prefix in LCC. The failure to do so
         turned out to be the reason for Bug #85757.  */
      char *filtered = name;

      if (filtered[0] == '$')
        filtered++;

      /* _GLOBAL_OFFSET_TABLE_ should be treated specially if a relocation is
         not explicitly specified. In this case either R_E2K_32_PC or
         R_E2K_64_PC_LIT should be generated rather than R_E2K_{32,64}_ABS.
         It's the most typical use of this symbol in fact. The only exception
         I know is `_GLOBAL_OFFSET_TABLE_@GOTOFF' which is required by ld.so
         to find its base address. See Bug #38938, Bug #47636, Comment #7.  */
      if  (strcmp (filtered, "_GLOBAL_OFFSET_TABLE_") == 0)
        {
          memset (e, 0, sizeof *e);
          e->X_op = O_pc;
          e->X_add_symbol = symbol_find_or_make (name);

          /* Return 1 or else all my efforts will have no effect.  */
          return 1;
        }
    }

  return 0;
}

void
e2k_cons_fix_new (fragS *frag,
                  int where,
                  int nbytes,
                  expressionS *exp)
{
  expressionS subexp;
  bfd_reloc_code_real_type reloc = BFD_RELOC_NONE;

  switch (exp->X_op)
    {
    case O_tls_dtprel:
      if (nbytes == 4)
        reloc = BFD_RELOC_E2K_32_DTPREL;
      else if (nbytes == 8)
        reloc = BFD_RELOC_E2K_64_DTPREL;
      else
	{
	  /* Formally assign a relocation even for a value of an unsuitable
	     size to prevent as_fatal () later.  */
	  reloc = BFD_RELOC_E2K_32_DTPREL;
	  as_bad (_("invalid @TLS_DTPREL value size %d, should be 4 or 8"),
		  nbytes);
	}

      break;

    case O_got:
      /* Assign a meaningful relocation no matter whether NBYTES is suitable or
	 not so as to prevent a repetetive as_bad () below in this function and
	 as_fatal () in resolve_symbol_value () later if NBYTES doesn't match
	 the relocation.  */
      reloc = BFD_RELOC_E2K_GOT;
      if (nbytes != 4)
	as_bad (_("invalid @GOT value size %d, should be 4"), nbytes);
      break;

    case O_gotoff:
      if (nbytes == 4)
	reloc = BFD_RELOC_32_GOTOFF;
      else if (nbytes == 8)
	reloc = BFD_RELOC_E2K_GOTOFF64;
      else
	{
	  /* Formally assign a relocation even for a value of an unsuitable
	     size to prevent as_fatal () later.  */
	  reloc = BFD_RELOC_32_GOTOFF;
	  as_bad (_("invalid @GOTOFF value size %d, should be 4 or 8"),
		  nbytes);
	}
      break;

    case O_size:
      if (nbytes == 4)
        reloc = BFD_RELOC_SIZE32;
      else if (nbytes == 8)
        reloc = BFD_RELOC_SIZE64;
      else
	{
	  /* Formally assign a relocation even for a value of an unsuitable
	     size to prevent as_fatal () later.  */
	  reloc = BFD_RELOC_SIZE32;
	  as_bad (_("invalid @SIZE value size %d, should be 4 or 8"), nbytes);
	}

      break;

    case O_ap:
      gas_assert (e2k_arch_size == 128);
      /* Formally assign a relocation even for a value of an unsuitable
	 size to prevent as_fatal () later.  */
      reloc = BFD_RELOC_E2K_AP;
      if (nbytes != 16)
	as_bad (_("invalid @AP value size %d, should be 16"), nbytes);
      break;

    case O_pl:
      gas_assert (e2k_arch_size == 128);
      /* Formally assign a relocation even for a value of an unsuitable
	 size to prevent as_fatal () later.  */
      reloc = BFD_RELOC_E2K_PL;
      /* FIXME: there's probably no point in allowing for 8-byte @PL values
	 here nowadays. Indeed, the only way to obtain such a value is via
	 a meaningless `.dword sym@PL'.  */
      if (nbytes != 8 && nbytes != 16)
	as_bad (_("invalid @PL value size %d, should be 8 or 16"), nbytes);

      break;

    case O_dynopt:
      if (nbytes == 4)
	reloc = BFD_RELOC_E2K_DYNOPT32;
      else if (nbytes == 8 )
	reloc = BFD_RELOC_E2K_DYNOPT64;
      else
	{
	  /* Formally assign a relocation even for a value of an unsuitable
	     size to prevent as_fatal () later.  */
	  reloc = BFD_RELOC_E2K_DYNOPT32;
	  as_bad (_("invalid @DYNOPT value size %d, should be 4 or 8"), nbytes);
	}
      break;

    case O_gotplt:
    case O_tls_gdmod:
    case O_tls_gdrel:
    case O_tls_le:
    case O_tls_ie:
    case O_plt:
    case O_islocal:
      /* Formally assign a "valid" relocation even for unsupported types of
	 values to prevent as_fatal () in `resolve_symbol_value ()' later.  */
      reloc = BFD_RELOC_E2K_GOT;
      as_bad (_("unsupported value type"));
      break;

    default:
      /* TODO: recall if something different from a symbolic relocation
	 may come here.  */
      break;
    }



  /* All this is obviously redundant when `exp->X_op == O_symbol' and we
     are creating BFD_RELOC_{32,64} . . .   */
  memset (&subexp, 0, sizeof subexp);

  if (reloc != BFD_RELOC_NONE)
    /* Set X_op to O_symbol in case we have a e2k-specific value for original
       X_op only (I mean TLS and so on). Otherwise, this may be wrong, e.g.
       if we have O_subtract.  */
    subexp.X_op = O_symbol;
  else
    subexp.X_op = exp->X_op;

  subexp.X_add_symbol = exp->X_add_symbol;

  /* X_op_symbol is important when dealing with expressions like `.LC1-.LT0'.
     All this stupid copying of fields becomes annoying . . . Rewrite this
     code when you understand its role better.  */
  subexp.X_op_symbol = exp->X_op_symbol;
  
  /* . . . but for now don't forget about ADDEND!!!  */
  subexp.X_add_number = exp->X_add_number;
  exp = &subexp;

  if (reloc == BFD_RELOC_NONE)
    {
      /* FIXME(?): something different from a known relocation against a symbol
	 must have been obtained for the value under consideration. What can it
	 be  and why should it be limited to sizes of 4 and 8?  */
      switch (nbytes)
        {
        case 4:
          reloc = BFD_RELOC_32;
          break;
        case 8:
          reloc = BFD_RELOC_64;
          break;
        default:
          as_bad (_("unsupported relocation size %d"), nbytes);
          /* Find out whether we are still alive here after AS_BAD.  */
          reloc = BFD_RELOC_64;
          break;
        }
    }

  fix_new_exp (frag, where, nbytes, exp, 0, reloc);
}

static void
e2k_add_magic_info (void)
{
  asection *magic_sec;
  char *magic, *p;
  size_t name_size, name_size_aligned;
  size_t magic_size, magic_size_aligned;
  static const char name[] = "MCST";

  if (! (magic = getenv ("MAGIC")))
    return;

  name_size = sizeof (name);
  name_size_aligned = (name_size + 3) & 0xfffffffc;
  magic_size = strlen (magic) + 1;
  magic_size_aligned = (magic_size + 3) & 0xfffffffc;

  magic_sec = subseg_new (".magic", 0);
  bfd_set_section_flags (magic_sec, SEC_HAS_CONTENTS | SEC_READONLY);

  /* Follow the standard note section layout:
     First write the length of the name string.  */
  p = frag_more (4);
  md_number_to_chars (p, (valueT) name_size, 4);

  /* Next comes the length of the "MAGIC" itself, i.e., the actual data.  */
  p = frag_more (4);
  md_number_to_chars (p, (valueT) magic_size, 4);

  /* Write the note NT_MAGIC type.  */
  p = frag_more (4);
  md_number_to_chars (p, (valueT) NT_MAGIC, 4);

  /* Write the name field.  */
  p = frag_more (name_size_aligned);
  /* FIXME: I don't remember for sure if `frag_more ()' zeroes out allocated
     memory.  */
  memset (p, 0, name_size_aligned);
  memcpy (p, name, name_size);

  /* Finally, write the descriptor.  */
  p = frag_more (magic_size_aligned);
  memset (p, 0, magic_size_aligned);
  memcpy (p, magic, magic_size);
}

#if defined TE_E2K_UCLIBC
static void
e2k_add_uclibc_poison (void)
{
  bfd_elf_add_obj_attr_int (stdoutput, OBJ_ATTR_GNU, Tag_GNU_E2K_UCLIBC, 1);

}
#endif /* defined TE_E2K_UCLIBC  */


void
e2k_end (void)
{
  e2k_add_magic_info ();

#if defined TE_E2K_UCLIBC
  e2k_add_uclibc_poison ();
#endif /* defined TE_E2K_UCLIBC  */
}

/* `.eh_frame' section in PM should be relocated at runtime and therefore
   should be writable.  */
int
e2k_dwarf2_eh_frame_read_only (void)
{
  return e2k_arch_size == 128 ? SEC_NO_FLAGS : SEC_READONLY;
}

int
e2k_eh_frame_alignment (void)
{
  return e2k_arch_size == 128 ? 4 : 2;
}


bfd_reloc_code_real_type
e2k_cfi_reloc_for_encoding (int encoding)
{
  if (e2k_arch_size == 128)
    {
      if (encoding == DW_EH_PE_aligned)
	return BFD_RELOC_E2K_AP;
      else if (encoding == DW_EH_PE_funcrel)
	return BFD_RELOC_E2K_PL;
    }

  return BFD_RELOC_NONE;
}

/* Given a symbolic attribute NAME, return the proper integer value.
   Returns -1 if the attribute is not known.  */

int
e2k_convert_symbolic_attribute (const char *name)
{
  static const struct
  {
    const char * name;
    const int    tag;
  }
  attribute_table[] =
    {
#define T(tag) {#tag, tag}
      T (Tag_GNU_E2K_UCLIBC),
#undef T
    };
  unsigned int i;

  if (name == NULL)
    return -1;

  for (i = 0; i < ARRAY_SIZE (attribute_table); i++)
    if (strcmp (name, attribute_table[i].name) == 0)
      return attribute_table[i].tag;

  return -1;
}
