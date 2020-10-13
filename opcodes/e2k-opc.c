#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "libiberty.h"
#include "opcode/e2k.h"

int mcpu;

#define MAX_E2K_NUM_OPCODES 16384
struct e2k_opcode_templ *e2k_opcode_templs[MAX_E2K_NUM_OPCODES];
size_t e2k_num_opcodes;

static void
add_to_insn_table (e2k_opcode_templ *new)
{
  if (e2k_num_opcodes == MAX_E2K_NUM_OPCODES)
    abort ();

  e2k_opcode_templs[e2k_num_opcodes++] = new;
}


static const char *
merge_alopf1_with_alopf11 (e2k_alf1_opcode_templ *l,
                           e2k_alopf11_opcode_templ *r)
{
  int i;
  for (i = 0; i < 6; i++)
    {
      if (l->allowed_channels[i] != 0)
        {
          if (r->allowed_channels[i] != 0)
            abort ();

          r->allowed_channels[i] = l->allowed_channels[i];
          /* This value seems to be not currently reserved in iset.  Use it to
             specify that an instruction in the related ALC should be actually
             encoded as ALOPF1, not ALOPF11.  */
          r->ales_opc2[i] = 0xff;
        }
    }

  /* Signalize to the caller that the hash entry should be replaced with more
     "universal" merged ALOPF11.  */
  return "jam";
}

static const char *
merge_alopf11 (struct e2k_opcode_templ *lhs,
               const struct e2k_opcode_templ *rhs)
{
  int i;
  e2k_alopf11_opcode_templ *l = (e2k_alopf11_opcode_templ *) lhs;
  const e2k_alopf11_opcode_templ *r = (const e2k_alopf11_opcode_templ *) rhs;

  /* FIXME: accessing `alopf' field in LHS which may very well turn out to be
     ALOPF1 via `e2k_alopf11_opcode_templ *' is controversial. It'd be be better
     to use `e2k_alf_opcode_templ *'.  */
  if (l->alopf == ALOPF1 && r->alopf == ALOPF11)
    {
      e2k_alf1_opcode_templ *alopf1 = (e2k_alf1_opcode_templ *) lhs;
      e2k_alopf11_opcode_templ *alopf11 = (e2k_alopf11_opcode_templ *) rhs;
      return merge_alopf1_with_alopf11 (alopf1, alopf11);
    }

  if (l->alopf != r->alopf
      || (l->alopf != ALOPF11 && l->alopf != ALOPF11_LIT8))
    abort ();

  if (l->opc != r->opc)
    abort ();

  for (i = 0; i < 6; i++)
    {
      if (r->allowed_channels[i] != 0)
        {
          if (l->allowed_channels[i] != 0)
            {
              if (l->ales_opc2[i] != r->ales_opc2[i])
                abort ();
            }
          else
            {
              l->allowed_channels[i] = r->allowed_channels[i];
              l->ales_opc2[i] = r->ales_opc2[i];
            }
        }
    }

  /* Return NULL by analogy with succesfull hash_jam to make it clear to the
     caller that there's no point in replacing the hash entry.  */
  return NULL;
}

static const char *
merge_alopf_simple (struct e2k_opcode_templ *lhs,
                    const struct e2k_opcode_templ *rhs)
{
  int i;
  e2k_alf_opcode_templ *l = (e2k_alf_opcode_templ *) lhs;
  const e2k_alf_opcode_templ *r = (const e2k_alf_opcode_templ *) rhs;

  if ((l->alopf != ALOPF1 && l->alopf != ALOPF2 && l->alopf != ALOPF21)
      || l->alopf != r->alopf)
    abort ();

  for (i = 0; i < 6; i++)
    {
      if (r->allowed_channels[i] != 0)
        {
          /* There should be no duplication of ALC'es now. I can probably rely
             on this above in `merge_alopf11 ()' as well . . .  */
          if (l->allowed_channels[i] != 0)
            abort ();
          else
            l->allowed_channels[i] = r->allowed_channels[i];
        }
    }

  return NULL;
}

void
init_opcode_templs ()
{
#if 0
  init_opcode_templs_from_table (0, e2k_short_opers, sizeof (e2k_short_opers) / sizeof (e2k_short_opers[0]));
  init_opcode_templs_from_table (1, e2k_long_opers, sizeof (e2k_long_opers) / sizeof (e2k_long_opers[0]));
#endif /* 0  */

  /* Opcodes are mostly added from an automatically generated e2k-opc.h  */
#include "e2k-opc.h"

  /* Add some opcodes manually. */

#define E2K_OPCODE_VEC_ENTRY(name, parse_fn)                            \
  {                                                                     \
    static const e2k_opcode_templ dummy = {#name, parse_fn, NULL};      \
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }

#define COPF2_VEC_ENTRY(name, ctp_opc, allowed_ctprs, label_expected)   \
  {                                                                     \
    static const e2k_copf2_opcode_templ dummy =                         \
      {#name, parse_copf2_args, NULL, ctp_opc, allowed_ctprs,           \
       label_expected};                                                 \
                                                                        \
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }

#define COPF4_VEC_ENTRY(name)                                           \
  {                                                                     \
    static const e2k_opcode_templ dummy =                               \
      {#name, parse_copf4_args, NULL};                                  \
                                                                        \
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }


#define AAOPF1_VEC_ENTRY(name, opc, format)             \
  {                                                     \
    static e2k_mova_opcode_templ dummy =                \
      {#name, parse_mova_args, NULL, opc, format};      \
                                                        \
    add_to_insn_table ((e2k_opcode_templ *) &dummy);    \
  }

/* FIXME: stupidly adding an extra cast to `(void *)' to avoid strict
   aliasing warnings when compiling with `-O2'.  */
#define SETCMD_VEC_ENTRY(name, id)                                      \
  {                                                                     \
    static const e2k_setcmd_opcode_templ dummy =                        \
      {#name,parse_setcmd_args, NULL, id};                              \
                                                                        \
    add_to_insn_table ((e2k_opcode_templ *) (void *) &dummy);           \
  }

  COPF2_VEC_ENTRY (disp, 0x0, ALL_CTPRS, EXPECT_LABEL);
  COPF2_VEC_ENTRY (ldisp, 0x1, CTPR2, EXPECT_LABEL);
  /* FIXME: unlike DISP only a numeric value should be
     allowed for SDISP, a symbol makes no sense. */
  COPF2_VEC_ENTRY (sdisp, 0x2, ALL_CTPRS, EXPECT_LABEL);


  /* FIXME: the underlying two entries are COPF1 in fact.  */
  COPF2_VEC_ENTRY (return, 0x3, CTPR3, NO_LABEL);
  if (mcpu >= 3)
    COPF2_VEC_ENTRY (gettsd, 0x3, ALL_CTPRS, NO_LABEL);

  E2K_OPCODE_VEC_ENTRY (pref, parse_pref_args);

  COPF4_VEC_ENTRY (flushr);
  COPF4_VEC_ENTRY (flushc);

  SETCMD_VEC_ENTRY (setbn, 0);
  SETCMD_VEC_ENTRY (setbp, 1);
  SETCMD_VEC_ENTRY (settr, 2);
  SETCMD_VEC_ENTRY (setwd, 3);
  SETCMD_VEC_ENTRY (vfrpsz, 4);
  SETCMD_VEC_ENTRY (setei, 5);

  if (mcpu >= 2)
    E2K_OPCODE_VEC_ENTRY (setsft, parse_setsft_args);

  E2K_OPCODE_VEC_ENTRY (nop, parse_nop_args);
  E2K_OPCODE_VEC_ENTRY (ct, parse_ct_args);
  E2K_OPCODE_VEC_ENTRY (call, parse_ct_args);

  if (mcpu >= 6)
    E2K_OPCODE_VEC_ENTRY (hcall, parse_hcall_args);

  E2K_OPCODE_VEC_ENTRY (ipd, parse_ipd_args);

  E2K_OPCODE_VEC_ENTRY (loop_mode, parse_loop_mode_args);
  E2K_OPCODE_VEC_ENTRY (alc, parse_alc_args);
  E2K_OPCODE_VEC_ENTRY (abn, parse_abn_args);
  E2K_OPCODE_VEC_ENTRY (abp, parse_abp_args);
  E2K_OPCODE_VEC_ENTRY (abg, parse_abg_args);
  E2K_OPCODE_VEC_ENTRY (bap, parse_bap_args);
  E2K_OPCODE_VEC_ENTRY (eap, parse_eap_args);

  E2K_OPCODE_VEC_ENTRY (pass, parse_pass_args);
  E2K_OPCODE_VEC_ENTRY (andp, parse_andp_args);
  E2K_OPCODE_VEC_ENTRY (landp, parse_landp_args);

  E2K_OPCODE_VEC_ENTRY (ibranch, parse_ibranch_args);
  E2K_OPCODE_VEC_ENTRY (rbranch, parse_ibranch_args);
  E2K_OPCODE_VEC_ENTRY (done, parse_done_hret_glaunch_args);

  if (mcpu >= 6)
    {
      E2K_OPCODE_VEC_ENTRY (hret, parse_done_hret_glaunch_args);
      E2K_OPCODE_VEC_ENTRY (glaunch, parse_done_hret_glaunch_args);
    }

  E2K_OPCODE_VEC_ENTRY (wait, parse_wait_args);

  {
    static const e2k_alf3_opcode_templ mmurr =
      {"mmurr", parse_alf_args, NULL, MMURR, NO_MAS, 0x67, {0, 0, 1, 0, 0, 1},
       ARGS_DDD};

    /* FIXME: I've intentionally specified NO_MAS here so that `parse_alf_args
       ()' doesn't attempt to parse it. I set it manually in parse_mmurw_args
       instead.  */
    static const e2k_alf3_opcode_templ mmurw =
      {"mmurw", parse_alf_args, NULL, MMURW, NO_MAS, 0x27, {0, 0, 1, 0, 0, 0},
       ARGS_DDD};

    add_to_insn_table ((e2k_opcode_templ *) &mmurr);
    add_to_insn_table ((e2k_opcode_templ *) &mmurw);
  }

  E2K_OPCODE_VEC_ENTRY (incr, parse_incr_args);

  AAOPF1_VEC_ENTRY (movab, 0x1, ARGS_S);
  AAOPF1_VEC_ENTRY (movah, 0x2, ARGS_S);
  AAOPF1_VEC_ENTRY (movaw, 0x3, ARGS_S);
  AAOPF1_VEC_ENTRY (movad, 0x4, ARGS_D);
  AAOPF1_VEC_ENTRY (movaq, 0x5, ARGS_Q);
  AAOPF1_VEC_ENTRY (movaqp, 0x7, ARGS_D);

  E2K_OPCODE_VEC_ENTRY (fapb, parse_fapb_args);
  E2K_OPCODE_VEC_ENTRY (movep, parse_movep_args);

  if (mcpu >= 3)
    E2K_OPCODE_VEC_ENTRY (flushts, parse_flushts_args);

  E2K_OPCODE_VEC_ENTRY (clpandp, parse_cpl_args);
  E2K_OPCODE_VEC_ENTRY (clplandp, parse_cpl_args);

  E2K_OPCODE_VEC_ENTRY (set_mark, parse_set_mark_args);
  E2K_OPCODE_VEC_ENTRY (vfdi, parse_vfdi_args);
}
