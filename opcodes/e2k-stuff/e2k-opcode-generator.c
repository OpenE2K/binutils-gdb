#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int mcpu;
static int forward_incompat;

void
print_common_part_minimal (const char *type, const char *name,
                           const char *parse_args)
{
  /* Note that elbrus-v1 "forward-compatible" instructions are generic ones and
     shouldn't be placed under a special condition, while "forward-incompatible"
     really should.  */
  if (mcpu >= 2 || forward_incompat)
    printf ("if (mcpu %s %d)\n", forward_incompat ? "==" : ">=", mcpu);

  printf ("{\n\tstatic %s dummy =", type);
  printf ("\n\t\t{\"%s\", %s", name, parse_args);

  /* FIXME: zero it out so as to avoid FALSE "forward incompatible" instructions
     in case `fetch_cop_channels ()' isn't invoked prior to this function. See
     also my comment when setting `forward_incompat' to 1.  */
  forward_incompat = 0;
}

void
print_common_part (const char *type, const char *name, const char *parse_args)
{
  print_common_part_minimal (type, name, parse_args);
  printf (", NULL");
}

void
print_common_part_with_merge (const char *type, const char *name,
                              const char *parse_args, const char *merge)
{
  print_common_part_minimal (type, name, parse_args);
  printf (", %s", merge);
}


/* Number of operands (and thus elements in FORMAT array) are different
   between different ALFs, but it's possible to print it here because we
   receive it as a string.  */
void
print_alf_part (const char *alopf, const char *mas, int cop, const int *chns,
                const char *format)
{
  int i;
  printf (", %s, %s, 0x%x, {", alopf, mas, cop);

  for (i = 0; i < 6; i++)
    printf ("%d%s", chns[i], i < 5 ? ", " : "");

  printf ("}, %s", format);
}

void
print_alopf11_tail (const char *opce, const int *chns, const char *opc2,
                    int explicit_ales25_v4)
{
  int i;
  printf (", %s, ", opce);
  printf ("{");
  for (i = 0; i < 6; i++)
    printf ("%s%s", chns[i] == 0 ? "0" : opc2, i < 5 ? ", " : "");
  printf ("}");

  printf (", %d", explicit_ales25_v4);
}

void
print_final_part ()
{
  printf ("};\n");
  printf ("\tadd_to_insn_table ((e2k_opcode_templ *) &dummy);\n");
  printf ("}\n");
}


typedef struct
{
  int cop;
  struct
  {
    const char *name;
    int usage;
  } opers[3];
  int incompat;
  int usage;
} e2k_oper;

typedef struct
{
  int size;
  e2k_oper *entries;
} e2k_oper_table;


#include "e2k-tables/tables.h"

/* These are opcodes used for operations producing flags (see Table B.1.4).
   Note that in spite of the fact that most of them (except for INC{s,d} and
   DEC{s,d}) have their counterparts in Tables B.1.{1,3.*} with exactly the
   same values, those tables can't be used to encode these instructions because
   of a wider set of allowed ALCes, whereas flag instructions can be encoded
   only in ALC{0,3}. The failure to realize this from the very beginning was
   the reason for Bug #101335.  */

/* These flag instruction opcodes appeared starting from `elbrus-v1'.  */
e2k_oper elbrus_v1_flag_opers[] =
  {
    {0x00,      {{"ANDs", 0},        {"", 0},        {"", 0}}, 0},
    {0x02,      {{"ANDNs", 0},       {"", 0},        {"", 0}}, 0},
    {0x04,      {{"ORs", 0},         {"", 0},        {"", 0}}, 0},
    {0x06,      {{"ORNs", 0},        {"", 0},        {"", 0}}, 0},
    {0x08,      {{"XORs", 0},        {"", 0},        {"", 0}}, 0},
    {0x0a,      {{"XORNs", 0},       {"", 0},        {"", 0}}, 0},
    {0x10,      {{"ADDs", 0},        {"", 0},        {"", 0}}, 0},
    {0x12,      {{"SUBs", 0},        {"", 0},        {"", 0}}, 0},
    {0x14,      {{"SCLs", 0},        {"", 0},        {"", 0}}, 0},
    {0x16,      {{"SCRs", 0},        {"", 0},        {"", 0}}, 0},
    {0x18,      {{"SHLs", 0},        {"", 0},        {"", 0}}, 0},
    {0x1a,      {{"SHRs", 0},        {"", 0},        {"", 0}}, 0},
    {0x1c,      {{"SARs", 0},        {"", 0},        {"", 0}}, 0},
    {0x22,      {{"UMULX", 0},       {"", 0},        {"", 0}}, 0},
    {0x23,      {{"SMULX", 0},       {"", 0},        {"", 0}}, 0},
    {0x30,      {{"INCs", 0},        {"", 0},        {"", 0}}, 0},
    {0x32,      {{"DECs", 0},        {"", 0},        {"", 0}}, 0},
  };

/* These ones were introduced into `elbrus-v3', after which the set of
   instructions producing flags has remained intact up to `elbrus-v6'
   inclusively.  */
e2k_oper elbrus_v3_flag_opers[] =
  {
    {0x01,      {{"ANDd", 0},        {"", 0},        {"", 0}}, 0},
    {0x03,      {{"ANDNd", 0},       {"", 0},        {"", 0}}, 0},
    {0x05,      {{"ORd", 0},         {"", 0},        {"", 0}}, 0},
    {0x07,      {{"ORNd", 0},        {"", 0},        {"", 0}}, 0},
    {0x09,      {{"XORd", 0},        {"", 0},        {"", 0}}, 0},
    {0x0b,      {{"XORNd", 0},       {"", 0},        {"", 0}}, 0},
    {0x11,      {{"ADDd", 0},        {"", 0},        {"", 0}}, 0},
    {0x13,      {{"SUBd", 0},        {"", 0},        {"", 0}}, 0},
    {0x15,      {{"SCLd", 0},        {"", 0},        {"", 0}}, 0},
    {0x17,      {{"SCRd", 0},        {"", 0},        {"", 0}}, 0},
    {0x19,      {{"SHLd", 0},        {"", 0},        {"", 0}}, 0},
    {0x1b,      {{"SHRd", 0},        {"", 0},        {"", 0}}, 0},
    {0x1d,      {{"SARd", 0},        {"", 0},        {"", 0}}, 0},
    {0x31,      {{"INCd", 0},        {"", 0},        {"", 0}}, 0},
    {0x33,      {{"DECd", 0},        {"", 0},        {"", 0}}, 0},
  };


e2k_oper_table oper_tables[][5] =
  {
    {
      {
        sizeof (elbrus_v1_short_opers) / sizeof (e2k_oper),
        elbrus_v1_short_opers
      },

      {
        sizeof (elbrus_v1_long_opers) / sizeof (e2k_oper),
        elbrus_v1_long_opers
      },

      {
        0,
        NULL
      },

      {
        0,
        NULL
      },

      {
        sizeof (elbrus_v1_flag_opers) / sizeof (e2k_oper),
        elbrus_v1_flag_opers
      }
    },

    {
      {
        sizeof (elbrus_v2_short_opers) / sizeof (e2k_oper),
        elbrus_v2_short_opers
      },

      {
        sizeof (elbrus_v2_long_opers) / sizeof (e2k_oper),
        elbrus_v2_long_opers
      },

      {
        0,
        NULL
      },

      {
        0,
        NULL
      },

      {
        0,
        NULL
      }
    },

    {
      {
        sizeof (elbrus_v3_short_opers) / sizeof (e2k_oper),
        elbrus_v3_short_opers
      },

      {
        sizeof (elbrus_v3_long_opers) / sizeof (e2k_oper),
        elbrus_v3_long_opers
      },

      {
        sizeof (elbrus_v3_long_ext1_opers) / sizeof (e2k_oper),
        elbrus_v3_long_ext1_opers
      },

      {
        0,
        NULL
      },

      {
        sizeof (elbrus_v3_flag_opers) / sizeof (e2k_oper),
	elbrus_v3_flag_opers,
      }
    },

    {
      {
        sizeof (elbrus_v4_short_opers) / sizeof (e2k_oper),
        elbrus_v4_short_opers
      },

      {
        sizeof (elbrus_v4_long_opers) / sizeof (e2k_oper),
        elbrus_v4_long_opers
      },

      {
        sizeof (elbrus_v4_long_ext1_opers) / sizeof (e2k_oper),
        elbrus_v4_long_ext1_opers
      },

      {
        0,
        NULL
      },

      {
        0,
        NULL
      }
    },

    {
      {
        sizeof (elbrus_v5_short_opers) / sizeof (e2k_oper),
        elbrus_v5_short_opers
      },

      {
        sizeof (elbrus_v5_long_opers) / sizeof (e2k_oper),
        elbrus_v5_long_opers
      },

      {
        sizeof (elbrus_v5_long_ext1_opers) / sizeof (e2k_oper),
        elbrus_v5_long_ext1_opers
      },

      {
        0,
        NULL
      },

      {
        0,
        NULL
      }
    },

    {
      {
        sizeof (elbrus_v6_short_opers) / sizeof (e2k_oper),
        elbrus_v6_short_opers
      },

      {
        sizeof (elbrus_v6_long_opers) / sizeof (e2k_oper),
        elbrus_v6_long_opers
      },

      {
        sizeof (elbrus_v6_long_ext1_opers) / sizeof (e2k_oper),
        elbrus_v6_long_ext1_opers
      },

      {
        sizeof (elbrus_v6_long_ext2_opers) / sizeof (e2k_oper),
        elbrus_v6_long_ext2_opers
      },

      {
        0,
        NULL
      }
    }
  };

const e2k_oper_table *short_opers;
const e2k_oper_table *long_opers;
const e2k_oper_table *long_ext1_opers;
const e2k_oper_table *long_ext2_opers;
const e2k_oper_table *flag_opers;

const e2k_oper_table *elbrus_v1_short_opers_table = &oper_tables[0][0];
const e2k_oper_table *elbrus_v1_long_opers_table = &oper_tables[0][1];
const e2k_oper_table *elbrus_v1_flag_opers_table = &oper_tables[0][4];



typedef struct
{
  const char *name;
  const char *format;
} instr_format;

typedef struct
{
  int cop;
  int channels[6];
} instr_cop_chn;


int
fetch_cop_channels (const e2k_oper_table *table, const char *name,
                    instr_cop_chn *res)
{
  int i, sz;

  res->cop = -1;
  for (i = 0; i < 6; i++)
    res->channels[i] = 0;


  for (i = 0; i < table->size; i++)
    {
      int j;
      for (j = 0; j < 3; j++)
        {
          if (strcasecmp (table->entries[i].opers[j].name, name) == 0)
            {
              res->cop = table->entries[i].cop;
              res->channels[j + 3] = res->channels[j] = 1;
              table->entries[i].opers[j].usage += 1;
            }
        }


      if (res->cop != -1)
        {
          /* As far as I understand, all sorts of SQRT are implemented in the
             5-th channel only.  */
          if (strcasestr (name, "sqrt"))
            {
              int j;
              /* Verify that we've obtained expected channels 2 and 5 from our
                 tables.  */
              for (j = 0; j < 6; j++)
                {
                  if ((j != 2 && j != 5 && res->channels[j] == 1)
                      || ((j == 2 || j == 5) && res->channels[j] == 0))
                    abort ();
                }

              res->channels[2] = 0;
            }

          /* FIXME: this is a rather rude solution. For this to work each
             invocation of `print_common_part_minimal ()' should be preceded
             with `fetch_cop_channels ()' which isn't always the case (consider
             invocations of `output_alopf21_insn ()').  */
          forward_incompat = table->entries[i].incompat;
          return 1;
        }
    }

  return 0;
}


void
gen_alopf1 ()
{
  static const instr_format instrs_wo_mas[] =
    {
      {"adds", "ARGS_SSS"},
      {"addd", "ARGS_DDD"},
      {"subs", "ARGS_SSS"},
      {"subd", "ARGS_DDD"},
      {"udivx", "ARGS_DSS"},
      {"umodx",	"ARGS_DSS"},
      {"sdivx", "ARGS_DSS"},
      {"smodx", "ARGS_DSS"},
      {"udivs", "ARGS_SSS"},
      {"udivd", "ARGS_DDD"},
      {"sdivs", "ARGS_SSS"},
      {"sdivd", "ARGS_DDD"},
      {"ands", "ARGS_SSS"},
      {"andd", "ARGS_DDD"},
      {"andns", "ARGS_SSS"},
      {"andnd", "ARGS_DDD"},
      {"ors", "ARGS_SSS"},
      {"ord", "ARGS_DDD"},
      {"orns", "ARGS_SSS"},
      {"ornd", "ARGS_DDD"},
      {"xors", "ARGS_SSS"},
      {"xord", "ARGS_DDD"},
      {"xorns", "ARGS_SSS"},
      {"xornd", "ARGS_DDD"},
      {"shls", "ARGS_SSS"},
      {"shld", "ARGS_DDD"},
      {"shrs", "ARGS_SSS"},
      {"shrd", "ARGS_DDD"},
      {"scls", "ARGS_SSS"},
      {"scld", "ARGS_DDD"},
      {"scrs", "ARGS_SSS"},
      {"scrd", "ARGS_DDD"},
      {"sars", "ARGS_SSS"},
      {"sard", "ARGS_DDD"},
      {"getfs", "ARGS_SSS"},
      {"getfd", "ARGS_DDD"},
      {"sxt", "ARGS_SSD"},
      {"merges", "ARGS_SSS"},
      {"merged", "ARGS_DDD"},
      {"fadds", "ARGS_SSS"},
      {"faddd", "ARGS_DDD"},
      {"fsubs", "ARGS_SSS"},
      {"fsubd", "ARGS_DDD"},
      {"fmins", "ARGS_SSS"},
      {"fmind", "ARGS_DDD"},
      {"fmaxs", "ARGS_SSS"},
      {"fmaxd", "ARGS_DDD"},
      {"fmuls", "ARGS_SSS"},
      {"fmuld", "ARGS_DDD"},
      {"fxaddss", "ARGS_DSS"},
      {"fxadddd", "ARGS_DDD"},
      {"fxaddsx", "ARGS_DSD"},
      {"fxadddx", "ARGS_DDD"},
      {"fxaddxx", "ARGS_DDD"},
      {"fxaddxd", "ARGS_DDD"},
      {"fxaddxs", "ARGS_DDS"},
      {"fxsubss", "ARGS_DSS"},
      {"fxsubdd", "ARGS_DDD"},
      {"fxsubsx", "ARGS_DSD"},
      {"fxsubdx", "ARGS_DDD"},
      {"fxsubxx", "ARGS_DDD"},
      {"fxsubxd", "ARGS_DDD"},
      {"fxsubxs", "ARGS_DDS"},
      {"fxrsubss", "ARGS_DSS"},
      {"fxrsubdd", "ARGS_DDD"},
      {"fxrsubsx", "ARGS_DSD"},
      {"fxrsubdx", "ARGS_DDD"},
      {"fxmulss", "ARGS_DSS"},
      {"fxmuldd", "ARGS_DDD"},
      {"fxmulsx", "ARGS_DSD"},
      {"fxmuldx", "ARGS_DDD"},
      {"fxmulxx", "ARGS_DDD"},
      {"fxmulxd", "ARGS_DDD"},
      {"fxmulxs", "ARGS_DDS"},
      {"fxdivss", "ARGS_DSS"},
      {"fxdivdd", "ARGS_DDD"},
      {"fxdivsx", "ARGS_DSD"},
      {"fxdivdx", "ARGS_DDD"},
      {"fxdivxx", "ARGS_DDD"},
      {"fxdivxd", "ARGS_DDD"},
      {"fxdivxs", "ARGS_DDS"},
      {"fxdivtss", "ARGS_DSS"},
      {"fxdivtdd", "ARGS_DDD"},
      {"fxdivtsx", "ARGS_DSD"},
      {"fxdivtdx", "ARGS_DDD"},
      {"fxsqrtusx", "ARGS_DSD"},
      {"fxsqrtudx", "ARGS_DDD"},
      {"fxsqrtuxx", "ARGS_DDD"},
      {"fxsqrttsx", "ARGS_DSD"},
      {"fxsqrttdx", "ARGS_DDD"},
      {"fxsqrttxx", "ARGS_DDD"},

      {"movif", "ARGS_DSD"},
      {"vfsi", "ARGS_SDD"},

      {"vfbgv", "ARGS_SSS"},
      {"mkfsw", "ARGS_SSD"},
    };


  static const instr_format instrs_with_mas[] =
    {
      {"ldcsb", "ARGS_SSD"},
      {"lddsb", "ARGS_SSD"},
      {"ldesb", "ARGS_SSD"},
      {"ldfsb", "ARGS_SSD"},
      {"ldgsb", "ARGS_SSD"},
      {"ldssb", "ARGS_SSD"},
      {"ldcsh", "ARGS_SSD"},
      {"lddsh", "ARGS_SSD"},
      {"ldesh", "ARGS_SSD"},
      {"ldfsh", "ARGS_SSD"},
      {"ldgsh", "ARGS_SSD"},
      {"ldssh", "ARGS_SSD"},
      {"ldcsw", "ARGS_SSD"},
      {"lddsw", "ARGS_SSD"},
      {"ldesw", "ARGS_SSD"},
      {"ldfsw", "ARGS_SSD"},
      {"ldgsw", "ARGS_SSD"},
      {"ldssw", "ARGS_SSD"},
      {"ldcsd", "ARGS_SSD"},
      {"lddsd", "ARGS_SSD"},
      {"ldesd", "ARGS_SSD"},
      {"ldfsd", "ARGS_SSD"},
      {"ldgsd", "ARGS_SSD"},
      {"ldssd", "ARGS_SSD"},

      {"ldb", "ARGS_DDD"},
      {"ldh", "ARGS_DDD"},
      {"ldw", "ARGS_DDD"},
      {"ldd", "ARGS_DDD"}
    };

  static const struct {
    const char *mas;
    int size;
    const instr_format *arr;
  } alopf1_groups [] =
      {
        {
          "NO_MAS",
          sizeof (instrs_wo_mas) / sizeof (instrs_wo_mas[0]),
          instrs_wo_mas
        },
        {
          "MAS",
          sizeof (instrs_with_mas) / sizeof (instrs_with_mas[0]),
          instrs_with_mas
        }
      };

  int i;    

  for (i = 0; i < 2; i++)
    {
      int j;
      const char *mas = alopf1_groups[i].mas;

      for (j = 0; j < alopf1_groups[i].size; j++)
        {
          const instr_format *crnt = &alopf1_groups[i].arr[j];
          instr_cop_chn cop_chn;
          const char *alopf = "ALOPF1";

          /* Arguments of `MERGE{s,d}' instructions should be parsed
             specially.  */
          if (strcmp (crnt->name, "merges") == 0
              || strcmp (crnt->name, "merged") == 0)
            alopf = "MERGE";

          /* Fetch info on ALS.cop and allowed channels from the short opers
             table.  */
          if (! fetch_cop_channels (short_opers, crnt->name, &cop_chn))
            continue;

          if (strstr (crnt->name, "div") || strstr (crnt->name, "mod"))
            {
              /* According to Table B.1.1 ALS2 should be pretty valid . . .   */
              if (cop_chn.channels[2] == 0)
                abort ();

              cop_chn.channels[2] = 0;
            }

          print_common_part_with_merge ("e2k_alf1_opcode_templ", crnt->name,
                                        "parse_alf_args", "merge_alopf_simple");
          print_alf_part (alopf, mas, cop_chn.cop, cop_chn.channels,
                          crnt->format);

          /* We don't have any additional info to print for ALOPF1, just
             output
             the closing brace.  */
          print_final_part ();
        }
    }
}

#define _generic(mnemo) (mcpu == 1 ? mnemo : "")
#define _e3s(mnemo) (mcpu == 2 ? mnemo : "")

void
gen_alopf2 ()
{
  size_t i;
  {
    static const instr_format custom[] = 
      {
        {"fxsqrtisx", "ARGS_SD"},
        {"fxsqrtidx", "ARGS_DD"},
        {"fxsqrtixx", "ARGS_DD"},
        {"movfi", "ARGS_DS"},
        {"bitrevs", "ARGS_SS"},
        {"bitrevd", "ARGS_DD"},
        {"lzcnts", "ARGS_SS"},
        {"lzcntd", "ARGS_DD"},
        {"popcnts", "ARGS_SS"},
        {"popcntd", "ARGS_DD"},
	{"modbgv", "ARGS_SS"},
      };

    for (i = 0; i < sizeof (custom) / sizeof (custom[0]); i++)
      {
        instr_cop_chn cop_chn;

        if (! fetch_cop_channels (short_opers, custom[i].name, &cop_chn))
          continue;

        print_common_part_with_merge ("e2k_alf2_opcode_templ", custom[i].name,
                                      "parse_alf_args", "merge_alopf_simple");
        print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                        custom[i].format);

            /* These ones have ALF2.opce == NONE == 0xc0, don't they?  */
        printf (", 0xc0");
        print_final_part ();
      }
  }

    /* All flavours of MOVT. See table B.8.1. */
    static const instr_format gen_movts[] =
      {
        {"movts", "ARGS_SS"},
        {"movtd", "ARGS_DD"},
      };

    /* It makes sense to transpose this matrix, doesn't it? See
       `custom_movts[j][i]' in the loop below.  */
    static const struct {
      const char *name;
      int opce;
    } custom_movts[][3] =
        {
          /* opce = mv */
          {
            {"movts", 0xc0},
            {"movtd", 0xc0}
          },

          /* opce = mvc */
          {
            {"movtcs", 0xc1},
            {"movtcd", 0xc1}
          },

          /* opce = mvr */
          {
            {"movtrs", 0xc2},
            {"movtrd", 0xc2}
          },

          /* opce = mvrc */
          {
            {"movtrcs", 0xc3},
            {"movtrcd", 0xc3}
          }
        };


    for (i = 0; i < 2; i++)
      {
        const instr_format *crnt = &gen_movts[i];
        instr_cop_chn cop_chn;
        int j;

        if (!fetch_cop_channels (short_opers, crnt->name, &cop_chn))
          continue;

        for (j = 0; j < 4; j++)
          {
            print_common_part_with_merge ("e2k_alf2_opcode_templ",
                                          custom_movts[j][i].name,
                                          "parse_alf_args",
                                          "merge_alopf_simple");
            print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                            crnt->format);

            /* It's time to initialize ALF2.opce now.  */
            printf (", 0x%x", custom_movts[j][i].opce);
            print_final_part ();
          }
      }

    /* See Table B.3.1  */
    {
      static u_int8_t opce[] = {0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
                                0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf};

      static const char *gen_name [] = {"fstos", "fstod", "fdtos", "fdtod"};

      instr_format custom[][4] = {
        {
          {_generic("fstois"), "ARGS_SS"},
          {_generic("fstoid"), "ARGS_SD"},
          {_generic("fdtois"), "ARGS_DS"},
          {_generic("fdtoid"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {_generic("fxtois"), "ARGS_DS"}, /* ARGS_XS in fact */
          {_generic("fxtoid"), "ARGS_DD"}  /* ARGS_XD in fact */
        },

        {
          {_generic("fstoistr"), "ARGS_SS"},
          {_e3s("fstoidtr"), "ARGS_SD"},
          {_generic("fdtoistr"), "ARGS_DS"},
          {_e3s("fdtoidtr"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {_e3s("fxtoistr"), "ARGS_DS"},
          {_e3s("fxtoidtr"), "ARGS_DD"}
        },

        {
          {_generic("istofs"), "ARGS_SS"},
          {_generic("istofd"), "ARGS_SD"},
          {_generic("idtofs"), "ARGS_DS"},
          {_generic("idtofd"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {_generic("istofx"), "ARGS_SD"},
          {"", "ARGS_DS"},
          {_generic("idtofx"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {_generic("fstofd"), "ARGS_SD"},
          {_generic("fdtofs"), "ARGS_DS"},
          {_generic("fxtofd"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {_generic("fstofx"), "ARGS_SD"},
          {_generic("fxtofs"), "ARGS_DS"},
          {_generic("fdtofx"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {_generic("pfdtois"), "ARGS_DS"},
          {_generic("pfstois"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {"", "ARGS_DS"},
          {"", "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {_generic("pfdtoistr"), "ARGS_DS"},
          {_generic("pfstoistr"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {"", "ARGS_DS"},
          {"", "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {"", "ARGS_DS"},
          {_generic("pistofs"), "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {"", "ARGS_DS"},
          {"", "ARGS_DD"}
        },


        {
          {"", "ARGS_SS"},
          {_generic("pfstofd"), "ARGS_SD"},
          {_generic("pfdtofs"), "ARGS_DS"},
          {"", "ARGS_DD"}
        },

        {
          {"", "ARGS_SS"},
          {"", "ARGS_SD"},
          {"", "ARGS_DS"},
          {"", "ARGS_DD"}
        }
      };

      for (i = 0; i < 16; i++)
        {
          int j;

          for (j = 0; j < 4; j++)
            {
              instr_cop_chn cop_chn;
              /* If there is no instruction, continue.  */
              if (custom[i][j].name[0] == '\0')
                continue;

              if (! fetch_cop_channels (elbrus_v1_short_opers_table,
                                        gen_name[j], &cop_chn))
                continue;

              print_common_part_with_merge ("e2k_alf2_opcode_templ",
                                            custom[i][j].name, "parse_alf_args",
                                            "merge_alopf_simple");
              print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                              custom[i][j].format);

              /* It's time to initialize ALF2.opce now.  */
              printf (", 0x%x", opce[i]);
              print_final_part ();
            }
        }
    }

    {
      /* Encode GETPL.  */
      instr_cop_chn cop_chn;
      if (fetch_cop_channels (short_opers, "getpl", &cop_chn))
        {
          print_common_part_with_merge ("e2k_alf2_opcode_templ", "getpl",
                                        "parse_alf_args", "merge_alopf_simple");
          print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          "ARGS_SD");
          /* ALF2.opce == CUD == 0xf0 (see Table B.5.1)  */
          printf (", 0xf0");
          print_final_part ();
        }
    }

    {
      /* Encode GETSAP.  */
      instr_cop_chn cop_chn;
      if (fetch_cop_channels (short_opers, "drtoap", &cop_chn))
        {

          /* Note that GETSAP (unlike other instructions having
             `cop == DRTOAP'?) can be encoded in channels 0 and 1 only (in a
             pair of these channels to be precise).  */
          cop_chn.channels[3] = cop_chn.channels[4] = 0;

          print_common_part_with_merge ("e2k_alf2_opcode_templ", "getsap",
                                        "parse_alf_args", "merge_alopf_simple");
          print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          "ARGS_SQ");
          /* ALF2.opce == USD == 0xec (see Table B.5.1)  */
          printf (", 0xec");
          print_final_part ();
        }
    }

    {
      /* Encode CUDTOAP and GDTOAP.  */
      instr_cop_chn cop_chn;
      if (fetch_cop_channels (short_opers, "drtoap", &cop_chn))
        {
          unsigned int alf2_opce[] = {0xf0, 0xf2};
          const char *names[] = {"cudtoap", "gdtoap"};

          for (i = 0; i < 2; i++)
            {
              print_common_part_with_merge
                ("e2k_alf2_opcode_templ", names[i],
                 "parse_alf_args", "merge_alopf_simple");
              print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop,
                              cop_chn.channels, "ARGS_SQ");
              /* ALF2.opce == GD == 0xf2 (see Table B.5.1)  */
              printf (", 0x%x", alf2_opce[i]);
              print_final_part ();
            }
        }
    }

    {
      /* Encode e3s-specific MOVX{,a,c}.  */
      instr_cop_chn cop_chn;
      if (fetch_cop_channels (short_opers, "movx", &cop_chn))
        {
          int opce[3] = {0xc0, 0xc1, 0xc2};
          const char *ins_name[3] = {"movx", "movxa", "movxc"};
          for (i = 0; i < 3; i++)
            {
              print_common_part_with_merge ("e2k_alf2_opcode_templ",
                                            ins_name[i], "parse_alf_args",
                                            "merge_alopf_simple");
              print_alf_part ("ALOPF2", "NO_MAS", cop_chn.cop, cop_chn.channels,
                              "ARGS_DD");
              printf (", 0x%x", opce[i]);
              print_final_part ();
            }
        }
    }
}

void
gen_alopf3 ()
{
  static const instr_format store_instrs[] = 
    {
      {"stcsb", "ARGS_SSS"},
      {"stdsb", "ARGS_SSS"},
      {"stesb", "ARGS_SSS"},
      {"stfsb", "ARGS_SSS"},
      {"stgsb", "ARGS_SSS"},
      {"stssb", "ARGS_SSS"},

      {"stcsh", "ARGS_SSS"},
      {"stdsh", "ARGS_SSS"},
      {"stesh", "ARGS_SSS"},
      {"stfsh", "ARGS_SSS"},
      {"stgsh", "ARGS_SSS"},
      {"stssh", "ARGS_SSS"},

      {"stcsw", "ARGS_SSS"},
      {"stdsw", "ARGS_SSS"},
      {"stesw", "ARGS_SSS"},
      {"stfsw", "ARGS_SSS"},
      {"stgsw", "ARGS_SSS"},
      {"stssw", "ARGS_SSS"},

      {"stcsd", "ARGS_SSD"},
      {"stdsd", "ARGS_SSD"},
      {"stesd", "ARGS_SSD"},
      {"stfsd", "ARGS_SSD"},
      {"stgsd", "ARGS_SSD"},
      {"stssd", "ARGS_SSD"},

      {"stb", "ARGS_DDS"},
      {"sth", "ARGS_DDS"},
      {"stw", "ARGS_DDS"},
      {"std", "ARGS_DDD"}
    };

  int i;

  for (i = 0; i < sizeof (store_instrs) / sizeof (store_instrs[0]); i++)
    {
      const instr_format *crnt = &store_instrs[i];
      instr_cop_chn cop_chn;

      /* Fetching ALS.cop and legal channels from SHORT operations table.  */
      if (! fetch_cop_channels (short_opers, crnt->name, &cop_chn))
        continue;

      print_common_part ("e2k_alf3_opcode_templ", crnt->name,
                         "parse_alf_args");
      print_alf_part ("ALOPF3", "MAS", cop_chn.cop, cop_chn.channels,
                      crnt->format);

      /* No additional info to print.  */
      print_final_part ();
    }
}

static void
gen_alopf7 ()
{
  static const instr_format gen_ins[] =
    {
      {"cmpsb", "ARGS_SS"},
      {"cmpdb", "ARGS_DD"},
      {"cmpandsb", "ARGS_SS"},
      {"cmpanddb", "ARGS_DD"},
      {"fcmpsb", "ARGS_SS"},
      {"fcmpdb", "ARGS_DD"},
      {"fxcmpsb", "ARGS_SS"},
      {"fxcmpdb", "ARGS_DD"},
      {"fxcmpxb", "ARGS_DD"}
    };

  static const char *ins_name[][8] =
  {
    {"cmposb", "cmpbsb", "cmpesb", "cmpbesb", "cmpssb", "cmppsb", "cmplsb", "cmplesb"},
    {"cmpodb", "cmpbdb", "cmpedb", "cmpbedb", "cmpsdb", "cmppdb", "cmpldb", "cmpledb"},
    {"", "", "cmpandesb", "", "cmpandssb", "cmpandpsb", "", "cmpandlesb"},
    {"", "", "cmpandedb", "", "cmpandsdb", "cmpandpdb", "", "cmpandledb"},
    {"fcmpeqsb", "fcmpltsb", "fcmplesb", "fcmpuodsb", "fcmpneqsb", "fcmpnltsb", "fcmpnlesb", "fcmpodsb"},
    {"fcmpeqdb", "fcmpltdb", "fcmpledb", "fcmpuoddb", "fcmpneqdb", "fcmpnltdb", "fcmpnledb", "fcmpoddb"},
    {"fxcmpeqsb", "fxcmpltsb", "fxcmplesb", "fxcmpuodsb", "fxcmpneqsb", "fxcmpnltsb", "fxcmpnlesb", "fxcmpodsb"},
    {"fxcmpeqdb", "fxcmpltdb", "fxcmpledb", "fxcmpuoddb", "fxcmpneqdb", "fxcmpnltdb", "fxcmpnledb", "fxcmpoddb"},
    {"fxcmpeqxb", "fxcmpltxb", "fxcmplexb", "fxcmpuodxb", "fxcmpneqxb", "fxcmpnltxb", "fxcmpnlexb", "fxcmpodxb"}   
  };

  int i;

  for (i = 0; i < sizeof (gen_ins) / sizeof (gen_ins[0]); i++)
    {
      int j;
      instr_cop_chn cop_chn;
      const instr_format *crnt = &gen_ins[i];

      /* Fetching ALS.cop and legal channels from SHORT operations table.  */
      if (! fetch_cop_channels (short_opers, crnt->name, &cop_chn))
        continue;

      for (j = 0; j < 8; j++)
        {
          /* Empty names correspond to non-existent instructions.  */
          if (ins_name[i][j][0] == '\0')
            continue;

          /* A specialized name should be output here rather than a "generic"
             one.  */
          print_common_part ("e2k_alf7_opcode_templ", ins_name[i][j],
                             "parse_alf_args");
          print_alf_part ("ALOPF7", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          crnt->format);

          /* It's time to initialize ALF7.dst2.cmpopce here which is equal to J
             according to `Table B.2.1' in iset.single.  */
          printf (", 0x%x", j);


	  /* Output an implicit number of NOPs implied by the comparison under
	     consideration. As far as I know, floating-point ones require 4,
	     while integer just 2.  */
	  printf (", %d", ins_name[i][j][0] == 'f' ? 4 : 2);

          print_final_part ();
        }
    }
}

static void
gen_alopf17 ()
{
    static const instr_format gen_ins[] =
    {
      {"pcmpp", "ARGS_DD"},
      {"qpcmpp", "ARGS_PP"}
    };

    static const char *ins_name[16]
      = {"pcmpeqbop", "pcmpeqhop", "pcmpeqwop", "pcmpeqdop",
	 "pcmpgtbop", "pcmpgthop", "pcmpgtwop", "pcmpgtdop",
	 "pcmpeqbap", "pcmpeqhap", "pcmpeqwap", "pcmpeqdap",
	 "pcmpgtbap", "pcmpgthap", "pcmpgtwap", "pcmpgtdap"};

    int i;

    for (i = 0; i < 2; i++)
    {
      int j;
      instr_cop_chn cop_chn;
      const instr_format *crnt = &gen_ins[i];

      /* Fetching ALS.cop and legal channels from SHORT operations table.  */
      if (! fetch_cop_channels (long_ext1_opers, crnt->name, &cop_chn))
        continue;

      for (j = 0; j < 16; j++)
        {
          /* A specialized name should be output here rather than a "generic"
             one.  */
	  char name[32];
	  sprintf (name, "%s%s", i == 0 ? "" : "q", ins_name[j]);

	  /* FIXME: eventually a dedicated e2k_alopf17_opcode_templ should
	     be used here.  */
          print_common_part ("e2k_alf7_opcode_templ", name, "parse_alf_args");
          print_alf_part ("ALOPF17", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          crnt->format);

          /* It's time to initialize ALES.opce here which is equal to `0xc0 + J'
             according to `Table B.2.5' in iset-v6.single.  */
          printf (", 0x%x", 0xc0 + j);

	  /* Output an implicit number of NOPs implied by the comparison.
	     According to the behaviour of LAS, these ones are likely to be
	     treated as integer ones.  */
	  printf (", 2");

          print_final_part ();
        }
    }

      
}

static void
gen_alopf8 ()
{
  static const char *names[] = {"cctopo", "cctopb", "cctope", "cctopbe",
                                "cctops", "cctopp", "cctopl", "cctople"};
  instr_cop_chn cop_chn;
  /* This is going to succeed for generic.  */
  if ( fetch_cop_channels (short_opers, "cctob", &cop_chn))
    {
      size_t i;

      for (i = 0; i < sizeof (names) / sizeof (names[0]); i++)
        {
          print_common_part ("e2k_alf8_opcode_templ", names[i],
                             "parse_alf_args");
          print_alf_part ("ALOPF8", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          "ARGS_S");
          /* Encode ALF8.dst2.cmpopce which determines the tested relation.  */
          printf (", 0x%x", i);

          print_final_part ();
        }
    }
}


static void
gen_alopf10 ()
{
  int i;
  static const char *ins_name[] = {"staab", "staah", "staaw",
                                   "staad", "staaq", "staaqp",
                                   "aaurw", "aaurws", "aaurwd", "aaurwq"};
  static const char *real_name[] = {NULL, NULL, NULL,
                                    NULL, NULL, NULL,
                                    "staaw", "staaw", "staad", "staaq"};
  static const char *fmt[] = {"ARGS_S", "ARGS_S", "ARGS_S",
                              "ARGS_D", "ARGS_Q", "ARGS_P",
                              "ARGS_S", "ARGS_S", "ARGS_D", "ARGS_Q"};

  for (i = 0; i < sizeof (ins_name) / sizeof (ins_name[0]); i++)
    {
      const char *instr_fmt = i < 6 ? "ALOPF10" : "AAURW";
      instr_cop_chn cop_chn;

      if (! fetch_cop_channels (i != 5 ? long_opers : long_ext1_opers,
                                (real_name[i] != NULL
                                 ? real_name[i]
                                 : ins_name[i]),
                                &cop_chn))
        continue;
      
      print_common_part ("e2k_alf10_opcode_templ", ins_name[i],
                         "parse_alf_args");
      print_alf_part (instr_fmt, i < 6 ? "MAS" : "NO_MAS", cop_chn.cop,
                      cop_chn.channels, fmt[i]);

      print_final_part ();

    }
}

/* Note, that I've not seen `LDAA{B,H,W,D,Q}', being ALOPF19 as well, anywhere
   within our sources including E2K Linux Kernel yet. Therefore they remain
   unsupported meanwhile . . .  */
static void
gen_alopf19 ()
{
  int i;
  static const char *ins_name[] = {"aaurr", "aaurrd", "aaurrq"};
  static const char *real_name[] = {"ldaaw", "ldaad", "ldaaq"};
  static const char *fmt[] = {"ARGS_S", "ARGS_D", "ARGS_Q"};

  for (i = 0; i < 3; i++)
    {
      instr_cop_chn cop_chn;

      if (! fetch_cop_channels (long_opers,
                                (real_name[i] != NULL
                                 ? real_name[i]
                                 : ins_name[i]),
                                &cop_chn))
        continue;
      
      print_common_part ("e2k_alf9_opcode_templ", ins_name[i],
                         "parse_alf_args");
      print_alf_part ("AAURR", "NO_MAS", cop_chn.cop, cop_chn.channels,
                      fmt[i]);

      print_final_part ();

    }
}


/* FIXME: can't these loads be unified with instructions in MAS[] in
   gen_alopf11 () ???  */
static void
gen_alopf11_loads ()
{
  static const instr_format ext_loads[] =
    {
      {"ldgdb", "ARGS_SSD"},
      {"ldgdh", "ARGS_SSD"},
      {"ldgdw", "ARGS_SSD"},
      {"ldgdd", "ARGS_SSD"},
      {"ldgdq", "ARGS_SSQ"},

      {"ldcudb", "ARGS_SSD"},
      {"ldcudh", "ARGS_SSD"},
      {"ldcudw", "ARGS_SSD"},
      {"ldcudd", "ARGS_SSD"},
      {"ldcudq", "ARGS_SSQ"},


      {"ldapb", "ARGS_QSD"},
      {"ldaph", "ARGS_QSD"},
      {"ldapw", "ARGS_QSD"},
      {"ldapd", "ARGS_QSD"},
      {"ldapq", "ARGS_QSQ"},

      {"ldodwb", "ARGS_QSD"},
      {"ldodwd", "ARGS_QSD"},
      {"ldodwh", "ARGS_QSD"},
      {"ldodwq", "ARGS_QSQ"},
      {"ldodww", "ARGS_QSD"},

      {"ldodpb", "ARGS_QSD"},
      {"ldodpd", "ARGS_QSD"},
      {"ldodph", "ARGS_QSD"},
      {"ldodpq", "ARGS_QSQ"},
      {"ldodpw", "ARGS_QSD"},
      {"ldodrb", "ARGS_QSD"},
      {"ldodrd", "ARGS_QSD"},
      {"ldodrh", "ARGS_QSD"},
      {"ldodrq", "ARGS_QSQ"},
      {"ldodrw", "ARGS_QSD"},

      {"ldcsq", "ARGS_DDQ"},
      {"lddsq", "ARGS_DDQ"},
      {"ldesq", "ARGS_SSQ"},

      /* Beware of `r,ddq' format of arguments for the next two
         instructions unlike `ddq' for the others.  */
      {"ldfsq", "ARGS_DDQ"},
      {"ldgsq", "ARGS_DDQ"},
 
      {"ldssq", "ARGS_DDQ"},
      {"ldq", "ARGS_DDQ"},
    };


  static const instr_format ext1_loads[] =
    {
      {"ldqp", "ARGS_DDP"},
      {"ldgdqp", "ARGS_SSP"},
      {"ldcudqp", "ARGS_SSP"},

      {"ldcsqp", "ARGS_DDP"},
      {"lddsqp", "ARGS_DDP"},
      {"ldesqp", "ARGS_SSP"},

      /* Beware of `r,ddq' format of arguments for the next two
         instructions unlike `ddq' for the others.  */
      {"ldfsqp", "ARGS_DDP"},
      {"ldgsqp", "ARGS_DDP"},
 
      {"ldssqp", "ARGS_DDP"},
      {"ldapqp", "ARGS_QSP"},

      {"ldrqp", "ARGS_DDP"},
    };


  static struct {
    const instr_format *loads;
    const int size;
  } groups[] = 
      {
        {ext_loads, sizeof (ext_loads) / sizeof (instr_format)},
        {ext1_loads, sizeof (ext1_loads) / sizeof (instr_format)},
      };



  int i, j;

  for (j = 0; j < 2; j++)
    {
      for (i = 0; i < groups[j].size; i++)
        {
          instr_cop_chn cop_chn;

          /* Fetch info on ALS.cop and allowed channels from the LONG opers
             table.  */
          if (! fetch_cop_channels (j == 0 ? long_opers : long_ext1_opers,
                                    groups[j].loads[i].name, &cop_chn))
            continue;

          print_common_part_with_merge ("e2k_alopf11_opcode_templ",
                                        groups[j].loads[i].name,
                                        "parse_alf_args", "merge_alopf11");
          print_alf_part ("ALOPF11", "MAS", cop_chn.cop, cop_chn.channels,
                          groups[j].loads[i].format);

          print_alopf11_tail ("NONE", cop_chn.channels,
                              j == 0 ? "EXT" : "EXT1", 0);
          print_final_part ();
        }
    }
}


struct extra_alopf11_lit8
{
  u_int8_t max;
  const char *warn;
};
  
static int
is_alopf11_lit8 (const char *name, struct extra_alopf11_lit8 *extra)
{
  extra->max = 0;
  extra->warn = NULL;

  if (strcmp (name, "pextrh") == 0)
    {
      extra->max = 7;
      extra->warn = ("use of 'pextrh' with count > 7 leads to an "
                     "undefined result");
    }
  else if (strcmp (name, "pinsh") == 0)
    {
      extra->max = 4;
      extra->warn = ("use of 'pinsh' with count > 4 leads to an "
                     "undefined result");
    }
  else if (strcmp (name, "psllqh") == 0)
    {
      extra->max = 15;
      extra->warn = ("use of 'psllqh' with count > 15 leads to a "
                     "zero result");
    }
  else if (strcmp (name, "psllql") == 0)
    {
      extra->max = 7;
      extra->warn = ("use of 'psllql' with count > 7 leads to a "
                     "zero result");
    }
  else if (strcmp (name, "psrlqh") == 0)
    {
      extra->max = 7;
      extra->warn = ("use of 'psrlqh' with count > 7 leads to a "
                     "zero result");
    }
  else if (strcmp (name, "psrlql") == 0)
    {
      extra->max = 15;
      extra->warn = ("use of 'psrlql' with count > 15 leads to a "
                     "zero result");
    }
  else if (strcmp (name, "pshufw") == 0)
    {
      extra->max = 15;
      extra->warn = "'pshufw' uses only four low-order bits of literal8";
    }

  if (extra->warn)
    return 1;

  return 0;
}

static void
print_alopf11_lit8 (const struct extra_alopf11_lit8 *extra)
{
  printf (", %d, ", extra->max);
  if (extra->warn)
    printf ("\"%s\"", extra->warn);
  else
    printf ("NULL");
}

static void
gen_alopf11 ()
{
  static const instr_format masless[] =
    {
      {"muls", "ARGS_SSS"},
      {"muld", "ARGS_DDD"},
      {"umulx", "ARGS_SSD"},
      {"smulx", "ARGS_SSD"},
      {"fdivs", "ARGS_SSS"},
      {"fdivd", "ARGS_DDD"},
      {"fsqrttd", "ARGS_DDD"},
      {"pfmuls", "ARGS_DDD"},
      {"pfmuld", "ARGS_DDD"},
      {"paddb", "ARGS_SSS"},
      {"paddh", "ARGS_SSS"},
      {"paddw", "ARGS_SSS"},
      {"paddd", "ARGS_SSS"},
      {"paddsb", "ARGS_SSS"},
      {"paddsh", "ARGS_SSS"},
      {"paddusb", "ARGS_SSS"},
      {"paddush", "ARGS_SSS"},
      {"psubb", "ARGS_SSS"},
      {"psubh", "ARGS_SSS"},
      {"psubw", "ARGS_SSS"},
      {"psubd", "ARGS_SSS"},
      {"psubsb", "ARGS_SSS"},
      {"psubsh", "ARGS_SSS"},
      {"psubusb", "ARGS_SSS"},
      {"psubush", "ARGS_SSS"},
      {"pmaxsh", "ARGS_SSS"},
      {"pmaxub", "ARGS_SSS"},
      {"pminsh", "ARGS_SSS"},
      {"pminub", "ARGS_SSS"},
      {"psadbw", "ARGS_SSS"},
      {"pmulhuh", "ARGS_SSS"},
      {"pmulhh", "ARGS_SSS"},
      {"pmullh", "ARGS_SSS"},
      {"pmaddh", "ARGS_SSS"},

      {"pslld", "ARGS_SSS"},
      {"psllw", "ARGS_SSS"},
      {"psllh", "ARGS_SSS"},
      {"psrld", "ARGS_SSS"},
      {"psrlw", "ARGS_SSS"},
      {"psrlh", "ARGS_SSS"},
      {"psraw", "ARGS_SSS"},
      {"psrah", "ARGS_SSS"},

      {"pfadds", "ARGS_SSS"},
      {"pfaddd", "ARGS_DDD"},
      {"pfsubs", "ARGS_SSS"},
      {"pfsubd", "ARGS_DDD"},

      {"aptoap", "ARGS_QSQ"},
      {"aptoapb", "ARGS_QSQ"},

      /* I suppose that GETVA like CAST and TDTOMP isn't actually ALOPF1 as
         it is said in iset.single. It seems to be ALOPF11 in fact.  */
      {"getva", "ARGS_QSD"},

      {"pandd", "ARGS_DDD"},
      {"pandnd", "ARGS_DDD"},
      {"pord", "ARGS_DDD"},
      {"pxord", "ARGS_DDD"},

      /* I wonder if LDRD is MASless . . .  */
      {"ldrd", "ARGS_DDD"},

      {"fstoifs", "ARGS_SSS"},
      {"fdtoifd", "ARGS_DDD"},

      {"umulhd", "ARGS_DDD"},
      {"smulhd", "ARGS_DDD"},

      /* FIXME: the way arguments of PUTTC are currently parsed is too generic
         for this instruction: I can encode any general-purpose register as a
         DST. However, iset.single says that only `%tc{,d}' should be used.
         Interestingly enough, LAS lets one specify any register for DST as
         well.  */
      {"puttc", "ARGS_DDD"},

      {"pminuw", "ARGS_DDD"},
      {"pminsw", "ARGS_DDD"},
      {"pmaxuw", "ARGS_DDD"},
      {"pmaxsw", "ARGS_DDD"},


      {"fscales", "ARGS_SSS"},
      {"fscaled", "ARGS_DSD"},
      {"fxscalesx", "ARGS_DSD"},

      {"mpsadbh", "ARGS_DDD"},
      {"packuswh", "ARGS_DDD"},

      {"pavgusb", "ARGS_DDD"},
      {"pavgush", "ARGS_DDD"},

      {"qpand", "ARGS_PPP"},
      {"qpandn", "ARGS_PPP"},

      {"qpor", "ARGS_PPP"},
      {"qpxor", "ARGS_PPP"},


      {"qpaddb", "ARGS_PPP"},
      {"qpaddh", "ARGS_PPP"},
      {"qpaddsb", "ARGS_PPP"},
      {"qpaddsh", "ARGS_PPP"},
      {"qpaddusb", "ARGS_PPP"},
      {"qpaddush", "ARGS_PPP"},
      {"qpaddw", "ARGS_PPP"},
      {"qpaddd", "ARGS_PPP"},

      {"qpsubb", "ARGS_PPP"},
      {"qpsubh", "ARGS_PPP"},
      {"qpsubsb", "ARGS_PPP"},
      {"qpsubsh", "ARGS_PPP"},
      {"qpsubusb", "ARGS_PPP"},
      {"qpsubush", "ARGS_PPP"},
      {"qpsubw", "ARGS_PPP"},
      {"qpsubd", "ARGS_PPP"},

      {"qpfadds", "ARGS_PPP"},
      {"qpfaddd", "ARGS_PPP"},

      {"qpfhadds", "ARGS_PPP"},
      {"qpfhsubs", "ARGS_PPP"},


      {"qpfaddsubs", "ARGS_PPP"},
      {"qpfaddsubd", "ARGS_PPP"},

      {"qpfstoifs", "ARGS_DPP"},
      {"qpfdtoifd", "ARGS_DPP"},

      {"qpfmins", "ARGS_PPP"},
      {"qpfmind", "ARGS_PPP"},
      {"qpfmaxs", "ARGS_PPP"},
      {"qpfmaxd", "ARGS_PPP"},

      {"qpfmuls", "ARGS_PPP"},
      {"qpfmuld", "ARGS_PPP"},

      {"qpfsubs", "ARGS_PPP"},
      {"qpfsubd", "ARGS_PPP"},

      {"qpmsk2sgnb", "ARGS_PSP"},

      {"qppackdl", "ARGS_DDP"},

      {"qpsllh", "ARGS_PDP"},
      {"qpsllw", "ARGS_PDP"},
      {"qpslld", "ARGS_PDP"},
      {"qpsrlh", "ARGS_PDP"},
      {"qpsrlw", "ARGS_PDP"},
      {"qpsrld", "ARGS_PDP"},
      {"qpsrah", "ARGS_PDP"},
      {"qpsraw", "ARGS_PDP"},

      {"pfdivs", "ARGS_SSS"},
      {"pfdivd", "ARGS_DDD"},

      {"pcmpeqd", "ARGS_DDD"},
      {"pcmpgtd", "ARGS_DDD"},

      {"pfhadds", "ARGS_DDD"},
      {"pfhsubs", "ARGS_DDD"},
      {"pfaddsubs", "ARGS_DDD"},

      {"pfmins", "ARGS_DDD"},
      {"pfmind", "ARGS_DDD"},
      {"pfmaxs", "ARGS_DDD"},
      {"pfmaxd", "ARGS_DDD"},

      {"pfsqrttd", "ARGS_DDD"},

      {"pminsb", "ARGS_DDD"},
      {"pminuh", "ARGS_DDD"},
      {"pmaxsb", "ARGS_DDD"},
      {"pmaxuh", "ARGS_DDD"},

      {"pfstoifs", "ARGS_DDD"},
      {"pfdtoifd", "ARGS_DDD"},

      {"phaddh", "ARGS_DDD"},
      {"phaddw", "ARGS_DDD"},
      {"phaddsh", "ARGS_DDD"},

      {"phsubh", "ARGS_DDD"},
      {"phsubw", "ARGS_DDD"},
      {"phsubsh", "ARGS_DDD"},

      {"psignb", "ARGS_DDD"},
      {"psignh", "ARGS_DDD"},
      {"psignw", "ARGS_DDD"},

      {"pmaddubsh", "ARGS_DDD"},
      {"pmulhrsh", "ARGS_DDD"},
      {"phminposuh", "ARGS_DDD"},

      {"pmulubhh", "ARGS_DDD"},

      {"pextrh", "ARGS_DDS"},
      {"pinsh", "ARGS_DDD"},

      {"psllqh", "ARGS_DDD"},
      {"psllql", "ARGS_DDD"},
      {"psrlqh", "ARGS_DDD"},
      {"psrlql", "ARGS_DDD"},

      /* Starting from elbrus-v4 these operations are encoded in some ALCes as
         ALOPF11.  */
      {"fadds", "ARGS_SSS"},
      {"faddd", "ARGS_DDD"},
      {"fsubs", "ARGS_SSS"},
      {"fsubd", "ARGS_DDD"},
      {"fmuls", "ARGS_SSS"},
      {"fmuld", "ARGS_DDD"},

      {"qpacksshb", "ARGS_PPP"},
      {"qpacksswh", "ARGS_PPP"},
      {"qpackushb", "ARGS_PPP"},
      {"qpackuswh", "ARGS_PPP"},

      {"qpavgusb", "ARGS_PPP"},
      {"qpavgush", "ARGS_PPP"},

      {"qpcmpeqb", "ARGS_PPP"},
      {"qpcmpeqd", "ARGS_PPP"},
      {"qpcmpeqh", "ARGS_PPP"},
      {"qpcmpeqw", "ARGS_PPP"},
      {"qpcmpgtb", "ARGS_PPP"},
      {"qpcmpgtd", "ARGS_PPP"},
      {"qpcmpgth", "ARGS_PPP"},
      {"qpcmpgtw", "ARGS_PPP"},
      {"qphaddh", "ARGS_PPP"},
      {"qphaddsh", "ARGS_PPP"},
      {"qphaddw", "ARGS_PPP"},
      {"qphsubh", "ARGS_PPP"},
      {"qphsubsh", "ARGS_PPP"},
      {"qphsubw", "ARGS_PPP"},

      {"qpmaxsb", "ARGS_PPP"},
      {"qpmaxsh", "ARGS_PPP"},
      {"qpmaxsw", "ARGS_PPP"},
      {"qpmaxub", "ARGS_PPP"},
      {"qpmaxuh", "ARGS_PPP"},
      {"qpmaxuw", "ARGS_PPP"},

      {"qpminsb", "ARGS_PPP"},
      {"qpminsh", "ARGS_PPP"},
      {"qpminsw", "ARGS_PPP"},
      {"qpminub", "ARGS_PPP"},
      {"qpminuh", "ARGS_PPP"},
      {"qpminuw", "ARGS_PPP"},

      {"qpmulhh", "ARGS_PPP"},
      {"qpmulhrsh", "ARGS_PPP"},
      {"qpmulhuh", "ARGS_PPP"},
      {"qpmullh", "ARGS_PPP"},
      {"qpmulubhh", "ARGS_DPP"},

      {"qpsignb", "ARGS_PPP"},
      {"qpsignh", "ARGS_PPP"},
      {"qpsignw", "ARGS_PPP"},

      {"qphminposuh", "ARGS_PPD"},
      {"qpmaddh", "ARGS_PPP"},
      {"qpmaddubsh", "ARGS_PPP"},
      {"qpmpsadbh", "ARGS_PSP"},
      {"qpsadbw", "ARGS_PPP"},
      {"qpsrcd", "ARGS_PDP"},
      {"qpsrcw", "ARGS_PDP"},

      /* FIXME: according to `iset-v1.single' the next two instructions are
         ALOPF1, however their opcodes can't be found among instructions having
         a short encoding. Shouldn't you file a bug to these idiots at last?  */
      {"cast", "ARGS_QQQ"},
      {"tdtomp", "ARGS_DDD"},

      {"odtoap", "ARGS_QDQ"},

      {"psrcd", "ARGS_DDD"},
      {"psrcw", "ARGS_DDD"},

      {"getfzs", "ARGS_SSS"},
      {"getfzd", "ARGS_DDD"},

      {"puttagqp", "ARGS_PSP"},

      {"pmullw", "ARGS_DDD"},
      {"qpmullw", "ARGS_PPP"},

      {"pmrgp", "ARGS_DDD"},
      {"qpmrgp", "ARGS_PPP"},

      {"clmulh", "ARGS_DDD"},
      {"clmull", "ARGS_DDD"},
    };


  /* FIXME: is MAS applicable to PUTTAGx instructions at all? LAS lets one
     encode it with these instructions, but I doubt that this is correct. What
     has made me believe that it's relevant to them? I can't find any evidence
     of that within iset-vX.single . . .  */
  static const instr_format mas[] =
    {
      {"puttags", "ARGS_SSS"},
      {"puttagd", "ARGS_DSD"}
    };

  static const struct {
    const char *mas;
    int size;
    const instr_format *arr;
  } groups [] =
      {
        {
          "NO_MAS",
          sizeof (masless) / sizeof (masless[0]),
          masless
        },
        {
          "MAS",
          sizeof (mas) / sizeof (mas[0]),
          mas
        }
      };

  int i;

  /* I guess that there is probably no point in generating templates for MAS
     and MASless instructions inside one loop. To be revisited . . .  */

  for (i = 0; i < 2; i++)
    {
      int j;
      const char *mas = groups[i].mas;

      for (j = 0; j < groups[i].size; j++)
        {
          int k;
          instr_cop_chn cop_chn;
          const instr_format *crnt = &groups[i].arr[j];
          struct extra_alopf11_lit8 extra;
	  int need_merge = strstr (crnt->name, "mrgp") ? 1 : 0;
          int need_extra_ind = is_alopf11_lit8 (crnt->name, &extra);
          /* See Bug #78923, Comment #2 for the original list of instructions
             requiring explicitly specified default ALES{2,5} syllables on
             elbrus-v4.  */
          int explicit_ales25_v4 = (strcmp (crnt->name, "pfadds") == 0
                                    || strcmp (crnt->name, "pfaddd") == 0
                                    || strcmp (crnt->name, "pfsubs") == 0
                                    || strcmp (crnt->name, "pfsubd") == 0
                                    || strcmp (crnt->name, "pfmuls") == 0
                                    || strcmp (crnt->name, "pfhadds") == 0
                                    || strcmp (crnt->name, "pfhsubs") == 0
                                    || strcmp (crnt->name, "pfaddsubs") == 0
                                    );

          for (k = 0; k < 3; k++)
            {
              const char *ext = (k == 0 ? "EXT" : (k == 1 ? "EXT1" : "EXT2"));
              const e2k_oper_table *lopers
		= (k == 0
		   ? long_opers
		   : (k == 1 ? long_ext1_opers : long_ext2_opers));

              if (lopers == NULL)
                continue;

              if (! fetch_cop_channels (lopers, crnt->name, &cop_chn))
                continue;

              if (strstr (crnt->name, "div"))
                {
                  /* According to Table B.1.3 ALS2 should be pretty valid . . .   */
                  if (cop_chn.channels[2] == 0)
                    abort ();

                  cop_chn.channels[2] = 0;
                }
              else if (strcmp (crnt->name, "puttc") == 0)
                {
                  if (cop_chn.channels[3] == 0)
                    abort ();

                  cop_chn.channels[3] = 0;
                }


              print_common_part_with_merge
                ((need_extra_ind
                  ? "e2k_alopf11_lit8_opcode_templ"
                  : "e2k_alopf11_opcode_templ"),
                 crnt->name, "parse_alf_args", "merge_alopf11");

              print_alf_part (need_merge
			      ?
			      "ALOPF11_MERGE"
			      : (need_extra_ind ? "ALOPF11_LIT8" : "ALOPF11"),
                              mas, cop_chn.cop, cop_chn.channels, crnt->format);

              print_alopf11_tail ("NONE", cop_chn.channels, ext,
                                  explicit_ales25_v4);

              if (need_extra_ind)
                print_alopf11_lit8 (&extra);

              print_final_part ();
            }
        }
    }

  /* Floating-point comparisons producing bit masks (see Table B.2.3)  */
  {
    static const instr_format generic[] = {
      {"fcmps", "ARGS_SSS"},
      {"fcmpd", "ARGS_DDD"},
      {"pfcmps", "ARGS_DDD"},
      {"pfcmpd", "ARGS_DDD"},
      {"qpfcmps", "ARGS_PPP"},
      {"qpfcmpd", "ARGS_PPP"},
    };

    static const char *suffixes[] = {"eq", "lt", "le", "uod", "neq",
                                     "nlt", "nle", "od"};
    static const char *opces[] = {"0xc0", "0xc1", "0xc2", "0xc3", "0xc4",
                                  "0xc5", "0xc6", "0xc7"};


    for (i = 0; i < 6; i++)
      {
        int j;
        instr_cop_chn cop_chn;
        char name[32];
        size_t gen_len;
        const e2k_oper_table *lopers = i < 4 ? long_opers : long_ext1_opers;
        const char *ext = i < 4 ? "EXT" : "EXT1";

        gen_len = strlen (generic[i].name);
        strncpy (name, generic[i].name, gen_len - 1);

        if (! fetch_cop_channels (lopers, generic[i].name, &cop_chn))
          continue;

        for (j = 0; j < 8; j++)
          {
            size_t sfx_len = strlen (suffixes[j]);
            strncpy (&name[gen_len - 1], suffixes[j], sfx_len);
            /* This should copy the trailing zero as well.  */
            strncpy (&name[gen_len + sfx_len - 1],
                     &generic[i].name[gen_len - 1], 2);

            print_common_part_with_merge ("e2k_alopf11_opcode_templ", name,
                                          "parse_alf_args", "merge_alopf11");
            print_alf_part ("ALOPF11", "NO_MAS", cop_chn.cop, cop_chn.channels,
                            generic[i].format);

            print_alopf11_tail (opces[j], cop_chn.channels, ext, 0);
            print_final_part ();
          }
      }

  }

  /* Floating-point comparisons producing flags (see B.2.4 in iset.single)  */
  {
    static const instr_format general[] = {
      {"fcmpsf", "ARGS_SSS"},
      {"fcmpdf", "ARGS_DDS"},
      {"fxcmpsf", "ARGS_DSS"},
      {"fxcmpdf", "ARGS_DDS"},
      {"fxcmpxf", "ARGS_DDS"}
    };
      
    static const char *custom_opce[2] = {"0xc7", "0xc3"};
    static const char *custom_name[][2] = {
       {"fcmpodsf", "fcmpudsf"},
       {"fcmpoddf", "fcmpuddf"},
       {"fxcmpodsf", "fxcmpudsf"},
       {"fxcmpoddf", "fxcmpuddf"},
       {"fxcmpodxf", "fxcmpudxf"}
     };

    static const char *others[] = {
      /* These are PCMPs  */
      "pcmpeqb", "pcmpeqh", "pcmpeqw", "pcmpgtb", "pcmpgth", "pcmpgtw",

      "pmovmskb", "pmovmskps", "pmovmskpd", "packsshb", "packushb",
      "pshufw",
      "packsswh", "punpckhbh", "punpckhhw", "punpckhwd", "punpcklbh",
      "punpcklhw", "punpcklwd"};

     for (i = 0; i < 5; i++)
       {
         int j;
         instr_cop_chn cop_chn;

         if (! fetch_cop_channels (long_opers, general[i].name, &cop_chn))
           continue;

         for (j = 0; j < 2; j++)
           {
             print_common_part_with_merge ("e2k_alopf11_opcode_templ",
                                           custom_name[i][j], "parse_alf_args",
                                           "merge_alopf11");
             print_alf_part ("ALOPF11", "NO_MAS", cop_chn.cop, cop_chn.channels,
                             general[i].format);

             print_alopf11_tail (custom_opce[j], cop_chn.channels, "EXT", 0);
             print_final_part ();
           }
       }

     for (i = 0; i < 19; i++)
       {
         instr_cop_chn cop_chn;
         struct extra_alopf11_lit8 extra;
         int need_extra_ind = is_alopf11_lit8 (others[i], &extra);

         if (! fetch_cop_channels (long_opers, others[i], &cop_chn))
           continue;

         print_common_part_with_merge
           ((need_extra_ind
             ? "e2k_alopf11_lit8_opcode_templ"
             : "e2k_alopf11_opcode_templ"),
            others[i], "parse_alf_args", "merge_alopf11");

         print_alf_part (need_extra_ind ? "ALOPF11_LIT8" : "ALOPF11", "NO_MAS",
                         cop_chn.cop, cop_chn.channels, "ARGS_DDD");

         print_alopf11_tail ("NONE", cop_chn.channels, "EXT", 0);

         if (need_extra_ind)
           print_alopf11_lit8 (&extra);

         print_final_part ();
       }
  }

  gen_alopf11_loads ();
}

static void
gen_alopf11_with_flags ()
{
  /* REMINDER: opcodes are normally taken from Tables B.1.1 and B.1.3. What
     they are duplicated for in Table B.1.4 (see for example, ANDs_f{b,h,w})
     is a non-trivial question . . .
     At the same time for currently unsupported {INC,DEC}s_f{b,h,w} there are
     no appropriate opcodes in B.1.1 and B.1.3, they should be fetched from
     B.1.4 instead.

     Note that the aforementioned `{INC,DEC}s_f{b,h,w}' as well as
     `S,{{C,H}{L,R},AR}s_f{b,h,w}' are ALOPF21 in fact . . .  */

  static const char *opc_gen[] = {"adds", "subs", "umulx", "smulx", "ands",
                                  "andns", "ors", "orns", "xors", "xorns"};
  static const char *opc_v3[] = {"addd", "subd", "andd", "andnd", "ord",
                                 "ornd", "xord", "xornd"};
  
  static const char *opc2[4] = {"FLB", "FLH", "FLW", "FLD"};
  static const char sfx[4] = {'b', 'h', 'w', 'd'};

  static struct
  {
    const char **opc;
    size_t num_opc;
    const char *args_fmt;
    size_t sfx_lo;
    size_t sfx_hi;
  }
  groups[] =
    {
      {opc_gen, sizeof (opc_gen) / sizeof (opc_gen[0]), "ARGS_SSS", 0, 2},
      {opc_v3, sizeof (opc_v3) / sizeof (opc_v3[0]), "ARGS_DDS", 3, 3},
    };

  size_t i;
  size_t gidx;

  /* FIXME: for a better symmetry one may consider `gidx = {0,1}' for each
     `mcpu'. This shouldn't change anything.  */
  if (mcpu != 1 && mcpu != 3)
    return;
  gidx = mcpu == 1 ? 0 : 1;

  for (i = 0; i < groups[gidx].num_opc; i++)
    {
      instr_cop_chn cop_chn;
      size_t j;

      /* Search flag opcodes and channels for the currently processed `mcpu'. */
      if (! fetch_cop_channels (flag_opers, groups[gidx].opc[i], &cop_chn))
        continue;

      for (j = groups[gidx].sfx_lo; j <= groups[gidx].sfx_hi; j++)
        {
          char name[32];
          sprintf (name, "%s_f%c", groups[gidx].opc[i], sfx[j]);
          print_common_part_with_merge ("e2k_alopf11_opcode_templ", name,
                                        "parse_alf_args", "merge_alopf11");
          print_alf_part ("ALOPF11", "NO_MAS", cop_chn.cop, cop_chn.channels,
                          groups[gidx].args_fmt);

          print_alopf11_tail ("NONE", cop_chn.channels, opc2[j], 0);
          print_final_part ();
        }
    }
}

/* I don't know what name would be appropriate for this function but
   among others it generates FSQRT{s,id} . . .   */
static void
gen_alopf12_fsqrts ()
{
  static const instr_format fsqrts[] =
    {
      {"frcps", "ARGS_SS"},
      {"fsqrts", "ARGS_SS"},
      {"fsqrtid", "ARGS_DD"},
      {"frsqrts", "ARGS_SS"},
      {"pfsqrts", "ARGS_SS"},
      {"gettd", "ARGS_DD"},
      {"gettags", "ARGS_SS"},
      {"gettagd", "ARGS_DS"},
      {"gettc", "ARGS_SD"},
      {"invtc", "ARGS_SD"},
      /* FIXME: I guess that this one along with several preceding instructions
         isn't "fsqrt". Keep it here for now since within this function
         appropriate values for `ALS.opce == ALES.opce == NONE' and `ALES.opc2
         == EXT' are set. Anyway, this function is to be revisited along with
         many others . . .

      FIXME: implement extra verification taking into account that the use of
      DST other than `%tst' with "puttst" is prohibited.  */
      {"puttst", "ARGS_DD"},
    };

  int i;

  for (i = 0; i < sizeof (fsqrts) / sizeof (fsqrts[0]); i++)
    {
      instr_cop_chn cop_chn;

      /* Fetch info on ALS.cop and allowed channels from the LONG opers
         table.  */
      if (! fetch_cop_channels (long_opers, fsqrts[i].name, &cop_chn))
        continue;

      if (strcmp (fsqrts[i].name, "frcps") == 0)
        {
          /* According to Table B.1.1 ALS2 should be pretty valid . . .   */
          if (cop_chn.channels[2] == 0)
            abort ();

          cop_chn.channels[2] = 0;
        }
      else if (strcmp (fsqrts[i].name, "gettc") == 0
               || strcmp (fsqrts[i].name, "invtc") == 0)
        {
          if (cop_chn.channels[3] == 0)
            abort ();

          cop_chn.channels[3] = 0;
        }
      else if (strcmp (fsqrts[i].name, "puttst") == 0)
        {
          if (cop_chn.channels[0] == 0)
            abort ();

          cop_chn.channels[0] = 0;
        }


      print_common_part ("e2k_alopf12_opcode_templ", fsqrts[i].name,
                         "parse_alf_args");
      print_alf_part ("ALOPF12", "NO_MAS", cop_chn.cop, cop_chn.channels,
                      fsqrts[i].format);

      /* It's time to initialize `ALS.opce = 0xc0 (NONE)',
         `ALES.opce = 0xc0 (NONE)' and `ALES.opc2 = 0x1 (EXT)'.  */
      printf (", 0xc0, 0xc0, 0x1");
      print_final_part ();
    }
}

/* PSHUFH is an ALOPF12 instruction which is to be parsed and encoded
   in a special way.  */
static void
gen_pshufh ()
{
  instr_cop_chn cop_chn;

  if (! fetch_cop_channels (long_opers, "pshufh", &cop_chn))
    return;

  print_common_part ("e2k_alopf12_opcode_templ", "pshufh", "parse_alf_args");
  print_alf_part ("ALOPF12_PSHUFH", "NO_MAS", cop_chn.cop, cop_chn.channels,
                  /* I cannot understand according to iset.single which format
                     arguments of PSHUFH have, but according to sample .s-files
                     `pshufh,1 %dr3,  0x1b, %dr3' they look like double. Anyway
                     arguments are treated specially . . .  */
                  "ARGS_DD");
  /* I believe that `ALS.opce = 0xc0 (NONE)' because nothing else is said about
     it, `ALES.opce should be determined from a literal8 argument' and
     `ALES.opc2 = 0x1 (EXT)'.  */
  printf (", 0xc0, 0x0, 0x1");
  print_final_part ();
}


static void
gen_alopf12 ()
{
  /* These instructions have ALS.opce == USD == 0xec (see B.5 in
     iset.single).  */
  static const instr_format *crnt, usd_instrs [] =
    {
      {"getsod", "ARGS_QQ"},
      {"getsp", "ARGS_SD"},
    };

  size_t i;

  gen_alopf12_fsqrts ();

  for (i = 0; i < sizeof (usd_instrs) / sizeof (usd_instrs[0]); i++)
    {
      instr_cop_chn cop_chn;
      crnt = &usd_instrs[i];

      /* Fetch info on ALS.cop and allowed channels from the LONG opers
         table.  */
      if (! fetch_cop_channels (long_opers, crnt->name, &cop_chn))
        continue;

      print_common_part ("e2k_alopf12_opcode_templ", crnt->name,
                         "parse_alf_args");
      print_alf_part ("ALOPF12", "NO_MAS", cop_chn.cop, cop_chn.channels,
                      crnt->format);

      /* It's time to initialize `ALS.opce = 0xec', `ALES.opce = 0xc0 (NONE)'
         and `ALES.opc2 = 0x1 (EXT)'.  */
      printf (", 0xec, 0xc0, 0x1");
      print_final_part ();
    }

  {
    static const instr_format insns[] =
      {
	{"qpsgn2mskb", "ARGS_PS"},
	{"qpswitchw", "ARGS_PP"},
	{"qpswitchd", "ARGS_PP"},
      };

    for (i = 0; i < sizeof (insns) / sizeof (insns[0]); i++)
      {
	instr_cop_chn cop_chn;
	crnt = &insns[i];

	/* Fetch info on ALS.cop and allowed channels from the EXT1 LONG
	   opers table.  */
	if (! fetch_cop_channels (long_ext1_opers, crnt->name, &cop_chn))
	  continue;

	print_common_part ("e2k_alopf12_opcode_templ", crnt->name,
			   "parse_alf_args");
	print_alf_part ("ALOPF12", "NO_MAS", cop_chn.cop, cop_chn.channels,
			crnt->format);

	/* Here I print ALS.opce (I guess that it's NONE, because I've been
	   unable to find another value in iset-v5.single), ALES.opce and
	   ALES.opc2.  */
	printf (", NONE, NONE, EXT1");
	print_final_part ();
      }
  }


  {
    /* Note that these ones may also accept the first operand of quad
       format.  */
    static const instr_format insns[] =
      {
	{"ibranchd", "ARGS_DD"},
	{"icalld", "ARGS_DD"},
      };

    const char *alopf[] = {"ALOPF12_IBRANCHD", "ALOPF12_ICALLD"};

    for (i = 0; i < sizeof (insns) / sizeof (insns[0]); i++)
      {
	instr_cop_chn cop_chn;
	crnt = &insns[i];

	/* Fetch info on ALS.cop and allowed channels from the EXT LONG
	   opers table.  */
	if (! fetch_cop_channels (long_opers, crnt->name, &cop_chn))
	  continue;

	/* IBRANCHD and ICALLD are said to be implemented in ALC0 only.
	   Fortunately, they don't require a pair of `ALC{0,3}' channels if
	   the first operand is of quad format.  */
	cop_chn.channels[3] = 0;

	print_common_part ("e2k_alopf12_opcode_templ", crnt->name,
			   "parse_alf_args");
	print_alf_part (alopf[i], "NO_MAS", cop_chn.cop, cop_chn.channels,
			crnt->format);

	/* ALS.opce == NONE for IBRANCHD, but will be replaced with WBS for
	   ICALLD. ALES.opce is likely to be NONE for both of them, while
	   ALES.opc2 is explicitly said to be EXT for both instructions.  */
	printf (", NONE, NONE, EXT");
	print_final_part ();
      }
  }

  {
    static struct
    {
      const char *sfx;
      int ales_opce;
    }
    qpcext_info[] = 
    {
      {"0x00", 0xc0}, {"0x7f", 0xc2}, {"0x80", 0xc4}, {"0xff", 0xc6}
    };

    instr_cop_chn cop_chn;

    /* QPCEXT comes from EXT1 table, but should I make use of this fact
       here? The same question applies to many other places where I
       explicitly search a particular `EXTj' table.  */
    if (fetch_cop_channels (long_ext1_opers, "qpcext", &cop_chn))
      {
	for (i = 0; i < sizeof (qpcext_info) / sizeof (qpcext_info[0]); i++)
	  {
	    char name[16];
	    sprintf (name, "qpcext_%s", qpcext_info[i].sfx);
	    print_common_part ("e2k_alopf12_opcode_templ", name,
			       "parse_alf_args");
	    print_alf_part ("ALOPF12", "NO_MAS", cop_chn.cop, cop_chn.channels,
			    "ARGS_DP");

	    /* Here I print ALS.opce (I guess that it's NONE, because I've been
	       unable to find another value in iset-v5.single), ALES.opce and
	       ALES.opc2.  */
	    printf (", NONE, 0x%x, EXT1", qpcext_info[i].ales_opce);
	    print_final_part ();
	  }
      }
  }

  {
    /* See Table B.3.2  */
    static const struct {
      u_int8_t opce;
      const char *name;
      const char *arg_fmt;
    } qptoqp_transforms[] =
        {{0xc8, "qpfstois", "ARGS_PP"},
         {0xca, "qpfstoistr", "ARGS_PP"},
         {0xcc, "qpistofs", "ARGS_PP"},
         {0xd8, "qpfstoid", "ARGS_DP"},
         {0xda, "qpfstoidtr", "ARGS_DP"},
         {0xdc, "qpistofd", "ARGS_DP"},
         {0xde, "qpfstofd", "ARGS_DP"},
         {0xe8, "qpfdtois", "ARGS_PD"},
         {0xea, "qpfdtoistr", "ARGS_PD"},
	 {0xec, "qpidtofs", "ARGS_PD"},
         {0xee, "qpfdtofs", "ARGS_PD"},
         {0xf8, "qpfdtoid", "ARGS_PP"},
         {0xfa, "qpfdtoidtr", "ARGS_PP"},
         {0xfc, "qpidtofd", "ARGS_PP"}
        };

    instr_cop_chn cop_chn;

    /* This will succeed only for elbrus-v5.  */
    if (fetch_cop_channels (long_ext1_opers, "qptoqp", &cop_chn))
      {
        for (i = 0;
             i < sizeof (qptoqp_transforms) / sizeof (qptoqp_transforms[0]);
             i++)
          {
            print_common_part ("e2k_alopf12_opcode_templ",
                               qptoqp_transforms[i].name, "parse_alf_args");
            print_alf_part ("ALOPF12", "NO_MAS", cop_chn.cop, cop_chn.channels,
                            qptoqp_transforms[i].arg_fmt);

            /* ALS.opce, ALES.opce and ALES.opc2  */
            printf (", 0x%x, NONE, EXT1", qptoqp_transforms[i].opce);
            print_final_part ();
          }
      }
  }

  gen_pshufh ();
}

static void
gen_alopf13 ()
{
    static const instr_format  stores[] =
      {
        {"stcsq", "ARGS_SSQ"},
        {"stdsq", "ARGS_SSQ"},
        {"stesq", "ARGS_SSQ"},
        {"stfsq", "ARGS_SSQ"},
        {"stgsq", "ARGS_SSQ"},
        {"stssq", "ARGS_SSQ"},

        {"strd", "ARGS_DDD"},

        {"stgdb", "ARGS_SSS"},
        {"stgdh", "ARGS_SSS"},
        {"stgdw", "ARGS_SSS"},
        {"stgdd", "ARGS_SSD"},
        {"stgdq", "ARGS_SSQ"},
        {"stgdmqp", "ARGS_SSP"},
        {"stgdqp", "ARGS_SSP"},

        {"stapb", "ARGS_QSS"},
        {"staph", "ARGS_QSS"},
        {"stapw", "ARGS_QSS"},
        {"stapd", "ARGS_QSD"},
        {"stapq", "ARGS_QSQ"},
        {"stapqp", "ARGS_QSP"},
        {"stapmqp", "ARGS_QSP"},

        {"stq", "ARGS_DDQ"},
        {"stmqp", "ARGS_DDP"},
        {"stqp", "ARGS_DDP"},

        {"stodpb", "ARGS_QSS"},
        {"stodpd", "ARGS_QSD"},
        {"stodph", "ARGS_QSS"},
        {"stodpq", "ARGS_QSQ"},
        {"stodpw", "ARGS_QSS"},

        {"stodrb", "ARGS_QSS"},
        {"stodrd", "ARGS_QSD"},
        {"stodrh", "ARGS_QSS"},
        {"stodrq", "ARGS_QSQ"},
        {"stodrw", "ARGS_QSS"},

        {"stodwb", "ARGS_QSS"},
        {"stodwd", "ARGS_QSD"},
        {"stodwh", "ARGS_QSS"},
        {"stodwq", "ARGS_QSQ"},
        {"stodww", "ARGS_QSS"},

        {"stcsmqp", "ARGS_DDP"},
        {"stcsqp", "ARGS_DDP"},
        {"stdsmqp", "ARGS_DDP"},
        {"stdsqp", "ARGS_DDP"},
        {"stesmqp", "ARGS_SSP"},
        {"stesqp", "ARGS_SSP"},

        /* What do they mean by specifying `r, ddq' (i.e. not just `ddq') as
           format of arguments for FS and GS operations in `iset-v5.single'?  */
        {"stfsmqp", "ARGS_DDP"},
        {"stfsqp", "ARGS_DDP"},
        {"stgsmqp", "ARGS_DDP"},
        {"stgsqp", "ARGS_DDP"},

        {"stssmqp", "ARGS_DDP"},
        {"stssqp", "ARGS_DDP"},

        {"strqp", "ARGS_DDP"},
      };

    int j;
    for (j = 0; j < 2; j++)
      {
        int i;
        const e2k_oper_table *lopers = j == 0 ?  long_opers : long_ext1_opers;
        const char *ext = j == 0 ? "EXT" : "EXT1";

        for (i = 0; i < sizeof (stores) / sizeof (stores[0]); i++)
          {
            instr_cop_chn cop_chn;

            /* Fetch info on ALS.cop and allowed channels from the LONG opers
               table.  */
            if (! fetch_cop_channels (lopers, stores[i].name, &cop_chn))
              continue;

            print_common_part ("e2k_alopf13_opcode_templ", stores[i].name,
                               "parse_alf_args");
            print_alf_part ("ALOPF13", "MAS", cop_chn.cop, cop_chn.channels,
                            stores[i].format);

            /* `ALEF2.opce = 0xc0 (NONE)' and `ALES.opc2 = 0x1 (EXT)'.  */
            printf (", NONE, %s", ext);
            print_final_part ();
          }
      }
}


static void
gen_alopf15 ()
{
  instr_format rr [] =
    {
      {"rws", "ARGS_S"},
      {"rwd", "ARGS_D"}
    };

  int i;

  for (i = 0; i < 2; i++)
    {
      /* Despite the contents of the long operations table these instructions
         are implemented in the zeroth channel only.  */
      static const int available_channels[6] = {1, 0, 0, 0, 0, 0};

      instr_cop_chn cop_chn;
      instr_format *crnt = &rr[i];

      if (! fetch_cop_channels (long_opers, crnt->name, &cop_chn))
        continue;

      print_common_part ("e2k_alopf15_opcode_templ", crnt->name,
                         "parse_alf_args");
      print_alf_part ("ALOPF15", "NO_MAS", cop_chn.cop, available_channels,
                      crnt->format);

      /* Currently we don't encode anything else. Code in `tc-e2k.c' sets
         ALEF2.{opc2,opce} to their "default" values itself.  */
      print_final_part ();
    }
}


static void
gen_alopf16 ()
{
  instr_format rr [] =
    {
      {"rrs", "ARGS_S"},
      {"rrd", "ARGS_D"}
    };

  int i;

  for (i = 0; i < 2; i++)
    {
      /* Despite the contents of the long operations table these instructions
         are implemented in the zeroth channel only.  */
      static const int available_channels[6] = {1, 0, 0, 0, 0, 0};

      instr_cop_chn cop_chn;
      instr_format *crnt = &rr[i];

      if (! fetch_cop_channels (long_opers, crnt->name, &cop_chn))
        continue;

      print_common_part ("e2k_alopf16_opcode_templ", crnt->name,
                         "parse_alf_args");
      print_alf_part ("ALOPF16", "NO_MAS", cop_chn.cop, available_channels,
                      crnt->format);

      /* Currently we don't encode anything else. Code in `tc-e2k.c' sets
         ALEF2.{opc2,opce} to their "default" values itself.  */
      print_final_part ();
    }
}


static void
output_alopf21_insn (const char *name, int cop, const int *channels,
                     const char *arg_fmts, const char *opc2)
{
  print_common_part ("e2k_alopf21_opcode_templ", name, "parse_alf_args");
  print_alf_part ("ALOPF21", "NO_MAS", cop, channels, arg_fmts);

  /* Now print ALEF1.opc2.  */
  printf (", %s", opc2);

  print_final_part ();
}


typedef struct
{
  char name[64];
  int channels[6];
  const char *arg_fmts;
} combined_table_entry;

typedef struct
{
  combined_table_entry entry[128];
} combined_table;

static void
add_combined_table_entry_by_idx (combined_table *dst, int idx,
                                 const char *name, const int channels[],
                                 const char *args_fmt)
{
  combined_table_entry *entry = &dst->entry[idx];

  strcpy (entry->name, name);
  memcpy (entry->channels, channels, sizeof (entry->channels));
  entry->arg_fmts = args_fmt;

}

static void
add_combined_table_entry (combined_table *dst, int scnd, int frst, int fmt,
                          const char *name, const int channels[],
                          const char *args_fmt)
{
  int idx = 32 * scnd + 2 * frst + fmt;
  add_combined_table_entry_by_idx (dst, idx, name, channels, args_fmt);
}


static void
add_empty_combined_table_entry_by_idx (combined_table *dst, int idx)
{
  static int no_channels[6] = {0, 0, 0, 0, 0, 0};
  /* Let an empty `name' be a sign of an empty entry.  */
  add_combined_table_entry_by_idx (dst, idx, "", no_channels, "");
}

static void
add_empty_combined_table_entry (combined_table *dst, int scnd, int frst,
                                int fmt)
{
  int idx = 32 * scnd + 2 * frst + fmt;
  add_empty_combined_table_entry_by_idx (dst, idx);
}


static void
fill_combined_table (int cpu, combined_table *dst, const char *prefix,
                     const char *frst_stage[], const char *scnd_stage[],
                     const int channels[], const char *sfmt, const char *dfmt,
                     int (* callback) (int, const char *, const char *, int))
{
  int i;
  for (i = 0; i < 4; i++)
    {
      int j;

      for (j = 0; j < 16; j++)
        {
          int k;

          for (k = 0; k < 2; k++)
            {
              if (scnd_stage[i][0] == '\0' || frst_stage[j][0] == '\0'
                  || (callback != NULL
                      && callback (cpu, scnd_stage[i], frst_stage[j], k) == 0))
                add_empty_combined_table_entry (dst, i, j, k);
              else
                {
                  char name[64];
                  sprintf (name, "%s%s_%s%s", prefix, frst_stage[j],
                           scnd_stage[i], k == 0 ? "s" : "d");
                  add_combined_table_entry (dst, i, j, k, name, channels,
                                            k == 0 ? sfmt : dfmt);
                }
            }
        }
    }
}


static void
fill_icmb (int cpu, combined_table *dst, const char *frst_stage[],
           const char *scnd_stage[])
{
  /* A subset of channels appropriate for ICMB{0,1,2,3} seems to be
     identical across `elbrus-v{1,2,3,4,5}'.  */
  static const int channels[6] = {0, 1, 0, 0, 1, 0};
  fill_combined_table (cpu, dst, "", frst_stage, scnd_stage, channels,
                       "ARGS_SSSS", "ARGS_DDDD", NULL);
}


static void
fill_icmb012 (int cpu, combined_table *dst, const char *scnd_stage[])
{
  /* The corresponding Table B.1.5.2 seems to be identical across `iset-v{1,2,
     3,4,5}.single'. If that changes, replace this array with a function filling
     in one depending on `mcpu' value.  */
  static const char *frst_stage[] = {
    "and", "andn", "or", "orn", "xor", "xorn", "", "merge", "add", "sub", "scl",
    "scr", "shl", "shr", "sar", "getf"};

  fill_icmb (cpu, dst, frst_stage, scnd_stage);
}

#define __elbrus_v1(s) cpu == 1 ? s : ""
#define __elbrus_v3(s) cpu >= 3 ? s : ""
#define __elbrus_v5(s) cpu >= 5 ? s : ""

static void
fill_icmb0 (int cpu, combined_table *dst)
{
  static const char *scnd_stage[] = {"and", "andn", "or", "orn"};
  fill_icmb012 (cpu, dst, scnd_stage);
}

static void
fill_icmb1 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] = {"xor", "xorn", "rsub",
                              __elbrus_v1 ("merge")};
  fill_icmb012 (cpu, dst, scnd_stage);
}


static void
fill_icmb2 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] = {"add", "sub", cpu == 1 ? "scl" : "",
                              __elbrus_v1 ("scr")};

  fill_icmb012 (cpu, dst, scnd_stage);
}

static void
fill_icmb3 (int cpu, combined_table *dst)
{
  static const int insf_channels[] = {1, 1, 0, 1, 1, 0};
  const char *frst_stage[] =
    {
      __elbrus_v1 ("and"),
      __elbrus_v1 ("andn"),
      __elbrus_v1 ("or"),
      __elbrus_v1 ("orn"),
      __elbrus_v1 ("xor"),
      __elbrus_v1 ("xorn"),
      "",
      __elbrus_v1 ("merge"),
      __elbrus_v1 ("add"),
      __elbrus_v1 ("sub"),
      __elbrus_v1 ("scl"),
      __elbrus_v1 ("scr"),
      __elbrus_v1 ("shl"),
      __elbrus_v1 ("shr"),
      __elbrus_v1 ("sar"),
      __elbrus_v1 ("getf")
    };

  const char *scnd_stage[] =
    {
      __elbrus_v1 ("shl"),
      __elbrus_v1 ("shr"),
      __elbrus_v1 ("sar"),
      __elbrus_v1 ("getf")
    };

  fill_icmb (cpu, dst, frst_stage, scnd_stage);

  /* Interestingly enough, according to `iset-v1.single' I can use any
     2nd_stage value I like to encode INSF, while `iset-v{X >= 2}.single'
     enforce the usage of `2nd_stage == 3'. Use `3' to be compatible with all
     istruction sets.  */
  add_combined_table_entry (dst, 3, 6, 0, "insfs", insf_channels, "ARGS_SSSS");
  add_combined_table_entry (dst, 3, 6, 1, "insfd", insf_channels, "ARGS_DDDD");
}

static int
fcmb_callback (int cpu, const char *scnd, const char *frst, int fmt)
{
  int i;

  if (cpu != 1)
    return 1;

  /* For elbrus-v1 take into account that annoying constraint next to the
     Tables B.1.7.4 and B.1.8.4 in `iset-v1.single'.  */

  for (i = 0; i < 2; i++)
    {
      const char *swp;

      /* Note that the actual `frst' can never be `rsub'. However, I take into
         account that `frst' and `scnd' are swapped below.  */
      if ((strcmp (frst, "add") == 0 || strcmp (frst, "sub") == 0 ||
           strcmp (frst, "rsub") == 0)
          && strcmp (scnd, "mul") == 0)
        return 1;

      /* Swap `frst' and `scnd': this lets me avoid duplication of `strcmp's. */
      swp = scnd;
      scnd = frst;
      frst = swp;
    }

  return 0;
}

static void
fill_fcmb (int cpu, combined_table *dst, const char *scnd_stage[])
{
  static const char *frst_stage[] = {"add", "sub", "", "", "mul", "", "", "",
                                     "", "", "", "", "", "", "", ""};

  static const int channels_0134[6] = {1, 1, 0, 1, 1, 0};
  static const int channels_all[6] = {1, 1, 1, 1, 1, 1};

  fill_combined_table (cpu, dst, "f", frst_stage, scnd_stage,
                       cpu < 4 ? channels_0134 : channels_all,
                       "ARGS_SSSS", "ARGS_DDDD", &fcmb_callback);
}

static void
fill_fcmb0 (int cpu, combined_table *dst)
{
  static const char *scnd_stage[] = {"add", "sub", "", ""};
  fill_fcmb (cpu, dst, scnd_stage);
}

static void
fill_fcmb1 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] =
    {
      __elbrus_v1 ("mul"),
      "rsub",
      "",
      ""
    };

  fill_fcmb (cpu, dst, scnd_stage);
}


/* Constraints imposed on `PFCMBx' and `QPFCMBx' seem to be identical except
   for the fact that no constraint is imposed on ADDSUB in the latter case. See
   notes next to Tables B.1.8.5 and B.1.9.5.  */
static int
common_pfcmb_qpfcmb (int cpu, const char *scnd, const char *frst, int fmt,
                     int is_qpfcmb)
{
  if (cpu >= 3 && fmt == 1)
    {
      int i;
      const char *subop[] = {scnd, frst};

      for (i = 0; i < 2; i++)
        {
          static const char *dbl_prohibit[] = {"hadd", "hsub", "addsub"};
          int j;
          for (j = 0; j < (is_qpfcmb ? 2 : 3); j++)
            {
              if (strcmp (subop[i], dbl_prohibit[j]) == 0)
                return 0;
            }
              
        }
    }

    return 1;  
}
  
static int
pfcmb_callback (int cpu, const char *scnd, const char *frst, int fmt)
{
  /* Note that I reuse `fcmb_callback' here because additional constraints
     imposed on `PFCMBx' operations on elbrus-v1 seem to be identical to those
     imposed on `FCMBx'.  */
  if (cpu == 1)
    return fcmb_callback (cpu, scnd, frst, fmt);


  return common_pfcmb_qpfcmb (cpu, scnd, frst, fmt, 0);
}

static void
fill_pfcmb (int cpu, combined_table *dst, const char *scnd_stage[])
{
  const char *frst_stage[] =
    {
      "add",
      "sub",
      __elbrus_v3 ("hadd"),
      __elbrus_v3 ("hsub"),
      "mul",
      "",
      "",
      __elbrus_v3 ("addsub"),
      "", "", "", "", "", "", "", ""
      
    };

  static const int channels_0134[6] = {1, 1, 0, 1, 1, 0};
  static const int channels_all[6] = {1, 1, 1, 1, 1, 1};

  fill_combined_table (cpu, dst, "pf", frst_stage, scnd_stage,
                       cpu < 4 ? channels_0134 : channels_all,
                       "ARGS_DDDD", "ARGS_DDDD", &pfcmb_callback);
}

static void
fill_pfcmb0 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] =
    {
      "add",
      "sub",
      __elbrus_v3 ("hadd"),
      __elbrus_v3 ("hsub")
    };

  fill_pfcmb (cpu, dst, scnd_stage);
}

static void
fill_pfcmb1 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] =
    {
      __elbrus_v1 ("mul"),
      "rsub",
      "",
      __elbrus_v3 ("addsub")
    };

  fill_pfcmb (cpu, dst, scnd_stage);

  /* These ones have been implemented since `elbrus-v2'.  */
  if (cpu >= 2)
    {
      static const int channels_0134[] = {1, 1, 0, 1, 1, 0};
      add_combined_table_entry (dst, 2, 6, 1, "pshufb", channels_0134,
                                "ARGS_DDDD");
      add_combined_table_entry (dst, 3, 6, 1, "pmerge", channels_0134,
                                "ARGS_DDDD");
    }
}

static int
qpfcmb_callback (int cpu, const char *scnd, const char *frst, int fmt)
{
  return common_pfcmb_qpfcmb (cpu, scnd, frst, fmt, 1);
}


static void
fill_qpfcmb (int cpu, combined_table *dst, const char *scnd_stage[])
{
  const char *frst_stage[] =
    {
      __elbrus_v5 ("add"),
      __elbrus_v5 ("sub"),
      __elbrus_v5 ("hadd"),
      __elbrus_v5 ("hsub"),
      __elbrus_v5 ("mul"),
      "",
      "",
      __elbrus_v5 ("addsub"),
      "", "", "", "", "", "", "", ""
      
    };

  static const int channels_all[6] = {1, 1, 1, 1, 1, 1};

  /* Note that I reuse `fcmb_callback' here because additional constraints
     imposed on `PFCMBx' operations on elbrus-v1 seem to be identical to those
     imposed on `FCMBx'.  */
  fill_combined_table (cpu, dst, "qpf", frst_stage, scnd_stage,
                       channels_all, "ARGS_PPPP", "ARGS_PPPP",
                       &qpfcmb_callback);
}


static void
fill_qpfcmb0 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] =
    {
      __elbrus_v5 ("add"),
      __elbrus_v5 ("sub"),
      __elbrus_v5 ("hadd"),
      __elbrus_v5 ("hsub")
    };

  fill_qpfcmb (cpu, dst, scnd_stage);
}

static void
fill_qpfcmb1 (int cpu, combined_table *dst)
{
  const char *scnd_stage[] =
    {
      "",
      __elbrus_v5 ("rsub"),
      "",
      __elbrus_v5 ("addsub")
    };

  fill_qpfcmb (cpu, dst, scnd_stage);

  /* Note that for CPU's prior to `elbrus-v5' the above code fills in an empty
     table in fact. Non-standard instructions should be added only for
     `elbrus-v5', of course.  */
  if (cpu >= 5)
    {
      static const int channels_0134[] = {1, 1, 0, 1, 1, 0};
      add_combined_table_entry (dst, 0, 6, 1, "qppermb", channels_0134,
                                "ARGS_PPPP");
      add_combined_table_entry (dst, 2, 6, 1, "qpshufb", channels_0134,
                                "ARGS_PPPP");
      add_combined_table_entry (dst, 3, 6, 1, "qpmerge", channels_0134,
                                "ARGS_PPPP");
    }
}

static void
fill_logical_combined_table (int cpu, combined_table *dst, const char *prefix,
                             int addend, int ident, const char *fmt)
{
  int i;
  static const int channels[] = {1, 1, 0, 1, 1, 0};
  for (i = 0; i < 128; i++)
    {
      int idx = i + addend;
      char sfx[16];

      if (cpu < 5)
        sfx[0] = '\0';
      else if (ident == 0)
        sprintf (sfx, "%d", idx);
      else if (ident == 1)
        sprintf (sfx, "0x%02x", idx);
      else
        {
          const char *human_sfx;
          switch (idx)
            {
            case 0x80:
              human_sfx = "and";
              break;
            case 0x96:
              human_sfx = "xor";
              break;
            case 0xd8:
              human_sfx = "sel3";
              break;
            case 0xe8:
              human_sfx = "mjr";
              break;
            case 0xfe:
              human_sfx = "or";
              break;
            default:
              human_sfx = "";
            }

          strcpy (sfx, human_sfx);
        }
      
      if (sfx[0] == '\0')
        add_empty_combined_table_entry_by_idx (dst, i);
      else
        {
          char name[64];
          sprintf (name, "%slog_%s", prefix, sfx);
          add_combined_table_entry_by_idx (dst, i, name, channels, fmt);
        }
    }
}

static void
fill_plog_lcmbd0_dec (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 0, 0, "ARGS_DDDD");
}

static void
fill_plog_lcmbd0_hex (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 0, 1, "ARGS_DDDD");
}

static void
fill_plog_lcmbd0_named (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 0, 2, "ARGS_DDDD");
}

static void
fill_plog_lcmbd1_dec (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 128, 0, "ARGS_DDDD");
}

static void
fill_plog_lcmbd1_hex (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 128, 1, "ARGS_DDDD");
}

static void
fill_plog_lcmbd1_named (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "p", 128, 2, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq0_dec (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 0, 0, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq0_hex (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 0, 1, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq0_named (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 0, 2, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq1_dec (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 128, 0, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq1_hex (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 128, 1, "ARGS_DDDD");
}

static void
fill_qplog_lcmbq1_named (int cpu, combined_table *dst)
{
  fill_logical_combined_table (cpu, dst, "qp", 128, 2, "ARGS_DDDD");
}





/* FIXME: this currently duplicates the functionality of `print_common_part_
   minimal ()'. When the latter is fixed in respect of `mcpu' conditionals
   it should be used from here.  */
static void
print_combined_table (const char *opc2, const combined_table *table,
                      int first, int last)
{
  int i;
  char cond[64];
  if (first == 1 && last == 6)
    cond[0] = '\0';
  else if (first == last)
    sprintf (cond, "if (mcpu == %d)\n", first);
  else if (last == 6)
    sprintf (cond, "if (mcpu >= %d)\n", first);
  else
    sprintf (cond, "if (mcpu >= %d && mcpu <= %d)\n", first, last);

  for (i = 0; i < 128; i++)
    {
      const char *mrg;
      const char *name = table->entry[i].name;
      int merge = 0;

      
      if (name[0] == '\0')
        continue;

      /* Be very careful so as not to mark `{q,}pmerge' and other similar
         "combined" instructions not really making use of MRGC as
         ALOPF21_MERGE.  */
      mrg = strstr (name, "merge");
      if (mrg
          && ((mrg > name && mrg[-1] == '_'
               && (mrg[5] == 's' || mrg[5] == 'd'))
              || (mrg == name && mrg[5] == '_')))
        merge = 1;

      printf ("%s", cond);
      printf ("{\n\tstatic e2k_alopf21_opcode_templ dummy =");
      printf ("\n\t\t{\"%s\", parse_alf_args, merge_alopf_simple",
              table->entry[i].name);

      print_alf_part (merge ? "ALOPF21_MERGE" : "ALOPF21", "NO_MAS", i,
                      table->entry[i].channels, table->entry[i].arg_fmts);

      /* Now print ALEF1.opc2.  */
      printf (", %s", opc2);

      print_final_part ();
    }
}

static void
intersect (combined_table *a, const combined_table *b)
{
  int i;

  for (i = 0; i < 128; i++)
    {
      int j;
      int demolish = 1;

      if (a->entry[i].name[0] == '\0'
          || b->entry[i].name[0] == '\0'
          || strcmp (a->entry[i].name, b->entry[i].name))
        {
          a->entry[i].name[0] = '\0';
          continue;
        }

      if (a->entry[i].arg_fmts != b->entry[i].arg_fmts)
        abort ();

      for (j = 0; j < 6; j++)
        {
          a->entry[i].channels[j] *= b->entry[i].channels[j];
          if (a->entry[i].channels[j] != 0)
            demolish = 0;
        }

      if (demolish)
        a->entry[i].name[0] = '\0';
    }
}

static void
subtract (combined_table *a, const combined_table *b)
{
  int i;

  for (i = 0; i < 128; i++)
    {
      int j;
      int demolish = 1;

      if (b->entry[i].name[0] == '\0')
        continue;

      if (a->entry[i].name[0] == '\0'
          || strcmp (a->entry[i].name, b->entry[i].name)
          || a->entry[i].arg_fmts != b->entry[i].arg_fmts)
        abort ();

      for (j = 0; j < 6; j++)
        {
          if (a->entry[i].channels[j] == 0 && b->entry[i].channels[j] == 1)
            abort ();

          a->entry[i].channels[j] -= b->entry[i].channels[j];
          if (a->entry[i].channels[j] != 0)
            demolish = 0;
        }

      if (demolish)
        a->entry[i].name[0] = '\0';
    }
}


static void
gen_alopf21_combined ()
{
  static void (*fill[]) (int, combined_table *) = {
    &fill_icmb0, &fill_icmb1, &fill_icmb2, &fill_icmb3, &fill_fcmb0,
    &fill_fcmb1, &fill_pfcmb0, &fill_pfcmb1, &fill_qpfcmb0, &fill_qpfcmb1,
    &fill_plog_lcmbd0_dec, &fill_plog_lcmbd0_hex,
    &fill_plog_lcmbd1_dec, &fill_plog_lcmbd1_hex, &fill_plog_lcmbd1_named,
    &fill_qplog_lcmbq0_dec, &fill_qplog_lcmbq0_hex,
    &fill_qplog_lcmbq1_dec, &fill_qplog_lcmbq1_hex, &fill_qplog_lcmbq1_named
  };

  static const char *opc2[] = {"ICMB0", "ICMB1", "ICMB2", "ICMB3", "FCMB0",
                               "FCMB1", "PFCMB0", "PFCMB1", "QPFCMB0",
                               "QPFCMB1",
                               "LCMBD0", "LCMBD0", "LCMBD1", "LCMBD1", "LCMBD1",
                               "LCMBQ0", "LCMBQ0", "LCMBQ1", "LCMBQ1", "LCMBQ1"
  };

  int i;

  for (i = 0; i < sizeof (fill) / sizeof (fill[0]); i++)
    {
      combined_table tables[6];
      int j;

      for (j = 0; j < 6; j++)
        (*fill[i]) (j + 1, &tables[j]);

      for (j = 0; j < 6; j++)
        {
          int k;
          combined_table tmp = tables[j];
          for (k = j + 1; k < 6; k++)
            {
              intersect (&tmp, &tables[k]);
              subtract (&tables[j], &tmp);
              /* `tables[j]' contains a subset of instructions supported by
                 `mcpu = j + 1' missing in `tables[k]', i.e. those ones
                 unsupported by `mcpu = k + 1'. Therefore, the last `mcpu'
                 which supports them is `k'.  */
              print_combined_table (opc2[i], &tables[j], j + 1, k);
              subtract (&tables[k], &tmp);
              tables[j] = tmp;
            }

          print_combined_table (opc2[i], &tables[j], j + 1, 6);
        }
    }
}

static void
gen_alopf21_with_flags ()
{
  static const char *opc_gen[] = {"incs", "decs", "shls", "shrs", "scls",
                                  "scrs", "sars"};
  static const char *opc_v3[] = {"incd", "decd", "shld", "shrd", "scld",
                                 "scrd", "sard"};
  
  static const char *opc2[4] = {"FLB", "FLH", "FLW", "FLD"};
  static const char sfx[4] = {'b', 'h', 'w', 'd'};

  static struct
  {
    const char **opc;
    size_t num_opc;
    const char *args_fmt;
    size_t sfx_lo;
    size_t sfx_hi;
  }
  groups[] =
    {
      {opc_gen, sizeof (opc_gen) / sizeof (opc_gen[0]), "ARGS_SSS", 0, 2},
      {opc_v3, sizeof (opc_v3) / sizeof (opc_v3[0]), "ARGS_DDS", 3, 3},
    };

  size_t i;
  size_t gidx;

  /* FIXME: for a better symmetry one may consider `gidx = {0,1}' for each
     `mcpu'. This shouldn't change anything.  */
  if (mcpu != 1 && mcpu != 3)
    return;
  gidx = mcpu == 1 ? 0 : 1;

  for (i = 0; i < groups[gidx].num_opc; i++)
    {
      instr_cop_chn cop_chn;
      size_t j;

      /* Search flag opcodes and channels for the currently processed `mcpu'. */
      if (! fetch_cop_channels (flag_opers, groups[gidx].opc[i], &cop_chn))
        continue;

      for (j = groups[gidx].sfx_lo; j <= groups[gidx].sfx_hi; j++)
        {
          char name[32];
          sprintf (name, "%s_f%c", groups[gidx].opc[i], sfx[j]);

          output_alopf21_insn (name, cop_chn.cop, cop_chn.channels,
                               groups[gidx].args_fmt, opc2[j]);
        }
    }
}

static void
gen_alopf21_custom ()
{
  size_t i;
  static const instr_format instrs[] =
    {
      {"addcd", "ARGS_DDSD"},
      {"addcd_c", "ARGS_DDSD"},
      {"subcd", "ARGS_DDSD"},
      {"subcd_c", "ARGS_DDSD"},

      {"fmas", "ARGS_SSSS"},
      {"fmss", "ARGS_SSSS"},
      {"fnmas", "ARGS_SSSS"},
      {"fnmss", "ARGS_SSSS"},
      {"fmad", "ARGS_DDDD"},
      {"fmsd", "ARGS_DDDD"},
      {"fnmad", "ARGS_DDDD"},
      {"fnmsd", "ARGS_DDDD"},

      {"qpfmas", "ARGS_PPPP"},
      {"qpfmss", "ARGS_PPPP"},
      {"qpfnmas", "ARGS_PPPP"},
      {"qpfnmss", "ARGS_PPPP"},
      {"qpfmad", "ARGS_PPPP"},
      {"qpfmsd", "ARGS_PPPP"},
      {"qpfnmad", "ARGS_PPPP"},
      {"qpfnmsd", "ARGS_PPPP"},

      {"qpfmass", "ARGS_PPPP"},
      {"qpfmsas", "ARGS_PPPP"},
      {"qpfmasd", "ARGS_PPPP"},
      {"qpfmsad", "ARGS_PPPP"},
    };


  for (i = 0; i < 2; i++)
    {
      int j;
      const e2k_oper_table *tables[] = {long_opers, long_ext2_opers};
      const char *exts[] = {"EXT", "EXT2"};
      for (j = 0; j < sizeof (instrs) / sizeof (instrs[0]); j++)
	{
	  instr_cop_chn cop_chn;

	  if (! fetch_cop_channels (tables[i], instrs[j].name, &cop_chn))
	    continue;

	  output_alopf21_insn (instrs[j].name, cop_chn.cop, cop_chn.channels,
			       instrs[j].format, exts[i]);
	}
    }
}


static void
gen_alopf22 ()
{

  /* Encoding all flavours of MOVTq.  */

    static const struct {
      const char *name;
      int opce;
    } custom_movtq[] =
        {
          /* opce = mv */
          {"movtq", 0xc0},

          /* opce = mvc */
          {"movtcq", 0xc1},

          /* opce = mvr */
          {"movtrq", 0xc2},

          /* opce = mvrc */
          {"movtrcq", 0xc3}
        };

    int i;
    instr_cop_chn cop_chn;

    if (! fetch_cop_channels (long_opers, "movtq", &cop_chn))
      return;

    for (i = 0; i < 4; i++)
      {
        /* No `e2k_alopf22_opcode_templ' has been introduced yet because
           for the supported ALOPF22 instructions (these are all flavours of
           MOVTq) ALEF2.{opce,opc2} have their "default" values which are set
           in `parse_alf2_args ()'.  */
        print_common_part ("e2k_alf2_opcode_templ", custom_movtq[i].name,
                           "parse_alf_args");
        print_alf_part ("ALOPF22", "NO_MAS", cop_chn.cop, cop_chn.channels,
                        "ARGS_QQ");

        /* It's time to initialize ALF2.opce now.  */
        printf (", 0x%x", custom_movtq[i].opce);
        print_final_part ();
      }
}


void
print_usage (int used)
{
  int i;
  fprintf (stderr, "%s operations:\n", used ? "Used" : "Unused");

  for (i = 0; i < 6; i++)
    {
      int j;
      /* Don't care about `flag_opers' for now: their impact is
         insignificant. This is why I use `j < 4', not `j < 5' here.  */
      for (j = 0; j < 4; j++)
        {
          int k;
          const e2k_oper_table *table = &oper_tables[i][j];
          for (k = 0; k < oper_tables[i][j].size; k++)
            {
              int l;
              e2k_oper *entry = &table->entries[k];
              for (l = 0; l < 3; l++)
                {
                  const char *name = entry->opers[l].name;
                  int usage = entry->opers[l].usage;

                  if (name[0] != '\0')
                    {
                      if ((used && usage > 0) || (!used && usage == 0))
                        fprintf (stderr, "%s\n", name);
                    }
                  else if (usage > 0)
                    abort ();
                }
            }
        }
    }

  fprintf (stderr, "\n\n\n\n\n");
}

int
main ()
{
  int i;
  
  for (i = 0; i < 6; i++)
    {
      short_opers = &oper_tables[i][0];
      long_opers = &oper_tables[i][1];
      long_ext1_opers = &oper_tables[i][2];
      long_ext2_opers = &oper_tables[i][3];
      flag_opers = &oper_tables[i][4];

      mcpu = i + 1;

      gen_alopf1 ();
      gen_alopf2 ();
      gen_alopf3 ();
      gen_alopf7 ();
      gen_alopf17 ();
      gen_alopf8 ();
      gen_alopf10 ();
      gen_alopf19 ();
      gen_alopf11 ();
      gen_alopf11_with_flags ();
      gen_alopf12 ();
      gen_alopf13 ();
      gen_alopf15 ();
      gen_alopf16 ();
      gen_alopf21_with_flags ();
      gen_alopf22 ();
      gen_alopf21_custom ();
    }

  gen_alopf21_combined ();

  print_usage (1);
  print_usage (0);

  return 0;
}
