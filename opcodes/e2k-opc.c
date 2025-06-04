/* Copyright (c) 2009-2025 AO MCST.
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

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "libiberty.h"
#include "opcode/e2k.h"

/* Imply `-mcpu=elbrus-v2' by default now that support for `-mcpu={generic,
   elbrus-v1}' is to be removed from `e2k-linux-as' (see MCSTBug #96498,
   Comment #11).  */
int mcpu = 2;

/* This has been moved to libopcodes because of the need to recognize
   elbrus-maket32c in `add_to_insn_table ()' (MCSTBug #162899).  */
unsigned long output_mach;

#define ISET_ALL_COMPAT_MASK	0x7f
#define ISET_V2_COMPAT_MASK	0x7e
#define ISET_V3_COMPAT_MASK	0x7c
#define ISET_PRE_V6_COMPAT_MASK	0x1f
#define ISET_V6_COMPAT_MASK	0x60
#define ISET_V7_COMPAT_MASK	0x40


#define MAX_E2K_NUM_OPCODES 16384
struct e2k_opcode_templ *e2k_opcode_templs[MAX_E2K_NUM_OPCODES];
size_t e2k_num_opcodes;

static void
add_to_insn_table (e2k_opcode_templ *new)
{
  if (e2k_num_opcodes == MAX_E2K_NUM_OPCODES)
    abort ();

  /* The following instructions are not supported in ALC{i>=3} on
     elbrus-maket32c in spite of what instruction tables in iset-v7.single
     state (MCSTBug #162899).  */
  if (output_mach == bfd_mach_e2k_maket32c
      && (strcmp (new->name, "qpkuzltr") == 0
	  || strcmp (new->name, "qpaesebgn") == 0
	  || strcmp (new->name, "qpaesltr") == 0
	  || strcmp (new->name, "qpaesdbgn") == 0
	  || strcmp (new->name, "qpaesiltr") == 0
	  || strcmp (new->name, "qpkuzebgn") == 0))
    {
      int i;
      e2k_alf_opcode_templ *alf = (e2k_alf_opcode_templ *) new;
      for (i = 3; i <= 5; i++)
	{
	  if (alf->allowed_channels[i] != 0)
	    alf->allowed_channels[i] = 0;
	}
    }

  e2k_opcode_templs[e2k_num_opcodes++] = new;
}

void *
link_alf_opcodes (e2k_alf_opcode_templ *first, e2k_alf_opcode_templ *next)
{
  int i;

  /* No more than TWO `e2k_alf_opcode_templ's may currently be linked
     together. */
  if (first->next != NULL)
    return NULL;

  if (first->alopf != next->alopf
      && ! (first->alopf == ALOPF1 && next->alopf == ALOPF11))
    return NULL;

  /* The names should obviously coincide.  */
  if (strcmp (first->name, next->name) != 0)
    return NULL;

  if (first->iset_mask == 0x1 && next->iset_mask == 0x2)
    {
      /* elbrus-v{X<=2}-specific "object-oriented" instructions are a special
	 case as e2k-opcode-generator produces two independent entries for them
	 which was quite OK when the hash table was filled in based on the
	 initial MCPU and they were never inserted into it together. TODO(?):
	 consider reworking e2k-opcode-generator to merge them into a single
	 entry at its level. For now do so here.  */

      /* Ideally one should ensure that all of the fields except for ISET_MASK
	 of the merged `e2k_al*f*_opcode_templ's coincide, but such tests
	 involving particular formats would extremely complicate this function.
	 Hardly are they worth being implemented taking into account that this
	 is known to be the case. Therefore, limit ourselves to
	 ALLOWED_CHANNELS[].  */
      for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
	{
	  if (first->allowed_channels[i] != next->allowed_channels[i])
	    return NULL;
	}

      /* Ensure that FIRST->ISET_MASK includes all ISET's the insn is supported
	 in as `insn_supported ()' relies on this (see below). Such a "merge"
	 makes linking these instructions unnecessary.  */
      first->iset_mask |= next->iset_mask;
    }
  else
    {
      /* FIRST has been expected to be workable on all isets supported by NEXT
	 (except for elbrus-v{X<=2} "object-oriented" instructions processed
	 above, of course) until elbrus-v7 providing an incompatible PM
	 implementation. FIXME(?): the underlying code treats such PM insns
	 by analogy with elbrus-v{1,2} "object-oriented" ones and is to be
	 revisited.  */
      if ((first->iset_mask & next->iset_mask) != next->iset_mask)
	{
	  for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
	    {
	      if (first->allowed_channels[i] != next->allowed_channels[i])
		return NULL;
	    }

	  first->iset_mask |= next->iset_mask;
	  return first;
	}


      for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
	{
	  /* The encodings for more advanced E2K isets are expected to only extend
	     the set of supported ALCes.  */
	  if (first->allowed_channels[i] != 0 && next->allowed_channels[i] != 0)
	    return NULL;
	}

      /* Link FIRST and NEXT.  */
      first->next = next;
    }

  /* Non-NULL return value signalizes the success.  */
  return first;
}

int
insn_supported (const e2k_opcode_templ *tpl)
{
  /* For ALF* insns linked into a list the FIRST one is sure to be supported
     by the widest set of ISETs, therefore there's no point (and opportunity
     as we have no idea if we are dealing with ALF* here) in quering the
     NEXT one.  */
  return ((tpl->iset_mask & (1 << (mcpu - 1))) != 0) ? 1 : 0;
}

int
supported_in_alc (const e2k_alf_opcode_templ *tpl, unsigned alc)
{
  if (alc >= ALS_CHANNELS_NUMBER
      || ! insn_supported ((const e2k_opcode_templ *) tpl))
    abort ();

  while (tpl)
    {
      if (((tpl->iset_mask & (1 << (mcpu - 1))) != 0)
	  && tpl->allowed_channels[alc])
	return 1;

      tpl = tpl->next;
    }

  return 0;
}

/* Can the instruction be encoded in the given ALC on any of the existing
   ISETs at all no matter what the current one is?  */
int
supported_in_alc_at_all (const e2k_alf_opcode_templ *tpl, unsigned alc)
{
  if (alc >= ALS_CHANNELS_NUMBER
      || ! insn_supported ((const e2k_opcode_templ *) tpl))
    abort ();

  while (tpl)
    {
      if (tpl->allowed_channels[alc])
	return 1;

      tpl = tpl->next;
    }

  return 0;
}

u_int8_t
get_max_alopf (const e2k_alf_opcode_templ *alf)
{
  if (alf->alopf != ALOPF1
      || alf->next == NULL
      || ! insn_supported ((const e2k_opcode_templ *) alf->next))
    return alf->alopf;

  return alf->next->alopf;
}

u_int8_t
get_ales_opce (const e2k_alf_opcode_templ *alf)
{
  if (alf->alopf == ALOPF11 || alf->alopf == ALOPF11_MERGE)
    return ((e2k_alopf11_opcode_templ *) alf)->ales_opce;

  if (alf->next == NULL
      || alf->next->alopf != ALOPF11
      || ! insn_supported ((const e2k_opcode_templ *) alf->next))
    abort ();

  return ((e2k_alopf11_opcode_templ *) alf->next)->ales_opce;
}


u_int8_t
get_explicit_ales25_v4 (const e2k_alf_opcode_templ *alf)
{
  if (alf->alopf == ALOPF11 || alf->alopf == ALOPF11_MERGE)
    return ((e2k_alopf11_opcode_templ *) alf)->explicit_ales25_v4;

  if (alf->next == NULL
      || alf->next->alopf != ALOPF11
      || ! insn_supported ((const e2k_opcode_templ *) alf->next))
    abort ();

  return ((e2k_alopf11_opcode_templ *) alf->next)->explicit_ales25_v4;
}

void
fill_in_ales_opc2 (const e2k_alf_opcode_templ *alf, u_int8_t *opc2_arr)
{
  unsigned i;
  
  if (alf->alopf == ALOPF1)
    {
      for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
	{
	  if (alf->allowed_channels[i] != 0)
	    opc2_arr[i] = 0xff;
	}

      /* This function shouldn't be called for ALOPF1 unless it's followed by
	 ALOPF11.  */
      if ((alf = alf->next) == NULL
	  || alf->alopf != ALOPF11
	  || ! insn_supported ((const e2k_opcode_templ *) alf))
	abort ();
    }

  while (alf != NULL)
    {
      const e2k_alopf11_opcode_templ *alopf11;

      if (alf->alopf != ALOPF11
	  && alf->alopf != ALOPF11_MERGE
	  && alf->alopf != ALOPF11_LIT8)
	abort ();

      /* No point in looking at this one and further.  */
      if (! insn_supported ((const e2k_opcode_templ *) alf))
	break;

      alopf11 = (const e2k_alopf11_opcode_templ *) alf;

      for (i = 0; i < ALS_CHANNELS_NUMBER; i++)
	{
	  if (alopf11->allowed_channels[i] != 0)
	    opc2_arr[i] = alopf11->ales_opc2[i];
	}

      alf = alf->next;
    }
}

#if 0

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
          /* There should be no duplication of ALC'es now. We can probably rely
             on this above in `merge_alopf11 ()' as well . . .  */
          if (l->allowed_channels[i] != 0)
            abort ();
          else
            l->allowed_channels[i] = r->allowed_channels[i];
        }
    }

  return NULL;
}

#endif /* 0  */

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

#define E2K_OPCODE_VEC_ENTRY(name, imsk, parse_fn)			\
  {                                                                     \
    static const e2k_opcode_templ dummy = {#name, imsk, parse_fn};	\
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }

#define COPF2_VEC_ENTRY(name, imsk, ctp_opc, allowed_ctprs, label_expected) \
  {                                                                     \
    static const e2k_copf2_opcode_templ dummy =                         \
      {#name, imsk, parse_copf2_args, ctp_opc, allowed_ctprs,	\
       label_expected};                                                 \
									\
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }

#define COPF4_VEC_ENTRY(name, imsk)					\
  {                                                                     \
    static const e2k_opcode_templ dummy =                               \
      {#name, imsk, parse_copf4_args};					\
                                                                        \
    add_to_insn_table ((e2k_opcode_templ *) &dummy);                    \
  }


#define AAOPF1_VEC_ENTRY(name, imsk, opc, format)		\
  {								\
    static e2k_mova_opcode_templ dummy =			\
      {#name, imsk, parse_mova_args, opc, format};		\
    								\
    add_to_insn_table ((e2k_opcode_templ *) &dummy);		\
  }

/* FIXME: stupidly adding an extra cast to `(void *)' to avoid strict
   aliasing warnings when compiling with `-O2'.  */
#define SETCMD_VEC_ENTRY(name, imsk, id)				\
  {                                                                     \
    static const e2k_setcmd_opcode_templ dummy =                        \
      {#name, imsk, parse_setcmd_args, id};				\
                                                                        \
    add_to_insn_table ((e2k_opcode_templ *) (void *) &dummy);           \
  }

  COPF2_VEC_ENTRY (disp, ISET_ALL_COMPAT_MASK, 0x0, ALL_CTPRS, EXPECT_LABEL);
  COPF2_VEC_ENTRY (ldisp, ISET_ALL_COMPAT_MASK, 0x1, CTPR2, EXPECT_LABEL);
  /* FIXME: unlike DISP only a numeric value should be
     allowed for SDISP, a symbol makes no sense. */
  COPF2_VEC_ENTRY (sdisp, ISET_ALL_COMPAT_MASK, 0x2, ALL_CTPRS, EXPECT_LABEL);


  /* FIXME: the underlying two entries are COPF1 in fact.  */
  COPF2_VEC_ENTRY (return, ISET_ALL_COMPAT_MASK, 0x3, CTPR3, NO_LABEL);

  COPF2_VEC_ENTRY (gettsd, ISET_V3_COMPAT_MASK, 0x3, ALL_CTPRS, NO_LABEL);

  E2K_OPCODE_VEC_ENTRY (pref, ISET_ALL_COMPAT_MASK, parse_pref_args);

  COPF4_VEC_ENTRY (flushr, ISET_ALL_COMPAT_MASK);
  COPF4_VEC_ENTRY (flushc, ISET_ALL_COMPAT_MASK);

  COPF4_VEC_ENTRY (fillr, ISET_V6_COMPAT_MASK);
  COPF4_VEC_ENTRY (fillc, ISET_V6_COMPAT_MASK);


  SETCMD_VEC_ENTRY (setbn, ISET_ALL_COMPAT_MASK, 0);
  SETCMD_VEC_ENTRY (setbp, ISET_ALL_COMPAT_MASK, 1);
  SETCMD_VEC_ENTRY (settr, ISET_ALL_COMPAT_MASK, 2);
  SETCMD_VEC_ENTRY (setwd, ISET_ALL_COMPAT_MASK, 3);
  SETCMD_VEC_ENTRY (vfrpsz, ISET_ALL_COMPAT_MASK, 4);
  SETCMD_VEC_ENTRY (setei, ISET_ALL_COMPAT_MASK, 5);

  E2K_OPCODE_VEC_ENTRY (setsft, ISET_V2_COMPAT_MASK, parse_setsft_args);

  E2K_OPCODE_VEC_ENTRY (nop, ISET_ALL_COMPAT_MASK, parse_nop_args);
  E2K_OPCODE_VEC_ENTRY (ct, ISET_ALL_COMPAT_MASK, parse_ct_args);
  E2K_OPCODE_VEC_ENTRY (call, ISET_ALL_COMPAT_MASK, parse_ct_args);

  E2K_OPCODE_VEC_ENTRY (hcall, ISET_V6_COMPAT_MASK, parse_hicall_args);
  E2K_OPCODE_VEC_ENTRY (icall, ISET_V6_COMPAT_MASK, parse_hicall_args);

  E2K_OPCODE_VEC_ENTRY (ipd, ISET_ALL_COMPAT_MASK, parse_ipd_args);

  E2K_OPCODE_VEC_ENTRY (loop_mode, ISET_ALL_COMPAT_MASK, parse_loop_mode_args);
  E2K_OPCODE_VEC_ENTRY (alc, ISET_ALL_COMPAT_MASK, parse_alc_args);
  E2K_OPCODE_VEC_ENTRY (abn, ISET_ALL_COMPAT_MASK, parse_abn_args);
  E2K_OPCODE_VEC_ENTRY (abp, ISET_ALL_COMPAT_MASK, parse_abp_args);

  /* See parse_abgc_args () on why ABG cannot be supported on elbrus-v{X>=6}
     for the sake of backward-compatibility.  */
  E2K_OPCODE_VEC_ENTRY (abg, ISET_PRE_V6_COMPAT_MASK, parse_abg_args);
  E2K_OPCODE_VEC_ENTRY (abgc, ISET_V6_COMPAT_MASK, parse_abgc_args);
  E2K_OPCODE_VEC_ENTRY (rbgc, ISET_V6_COMPAT_MASK, parse_rbgc_args);

  E2K_OPCODE_VEC_ENTRY (srp, ISET_ALL_COMPAT_MASK, parse_srp_args);

  E2K_OPCODE_VEC_ENTRY (crp, ISET_V2_COMPAT_MASK, parse_crp_args);

  E2K_OPCODE_VEC_ENTRY (slrp, ISET_V3_COMPAT_MASK, parse_slrp_args);

  E2K_OPCODE_VEC_ENTRY (bap, ISET_ALL_COMPAT_MASK, parse_bap_args);
  E2K_OPCODE_VEC_ENTRY (eap, ISET_ALL_COMPAT_MASK, parse_eap_args);

  E2K_OPCODE_VEC_ENTRY (ctp_call, ISET_V7_COMPAT_MASK, parse_ctp_call_args);
  E2K_OPCODE_VEC_ENTRY (dtbp, ISET_V7_COMPAT_MASK, parse_dtbp_args);

  E2K_OPCODE_VEC_ENTRY (pass, ISET_ALL_COMPAT_MASK, parse_pass_args);
  E2K_OPCODE_VEC_ENTRY (andp, ISET_ALL_COMPAT_MASK, parse_andp_args);
  E2K_OPCODE_VEC_ENTRY (landp, ISET_ALL_COMPAT_MASK, parse_landp_args);

  E2K_OPCODE_VEC_ENTRY (ibranch, ISET_ALL_COMPAT_MASK, parse_ibranch_args);
  E2K_OPCODE_VEC_ENTRY (rbranch, ISET_ALL_COMPAT_MASK, parse_ibranch_args);
  E2K_OPCODE_VEC_ENTRY (done, ISET_ALL_COMPAT_MASK,
			parse_done_hiret_glaunch_args);

  E2K_OPCODE_VEC_ENTRY (iret, ISET_V6_COMPAT_MASK, parse_done_hiret_glaunch_args);
  E2K_OPCODE_VEC_ENTRY (hret, ISET_V6_COMPAT_MASK, parse_done_hiret_glaunch_args);
  E2K_OPCODE_VEC_ENTRY (glaunch, ISET_V6_COMPAT_MASK, parse_done_hiret_glaunch_args);

  E2K_OPCODE_VEC_ENTRY (wait, ISET_ALL_COMPAT_MASK, parse_wait_args);

  {
    static const e2k_alf3_opcode_templ mmurr =
      {"mmurr", ISET_ALL_COMPAT_MASK, parse_alf_args, NULL, MMURR,
       LOAD | NO_MAS, 0x67, {0, 0, 1, 0, 0, 1}, ARGS_DDD};

    /* FIXME: I've intentionally specified NO_MAS here so that `parse_alf_args
       ()' doesn't attempt to parse it. We set it manually in parse_mmurw_args
       instead.  */
    static const e2k_alf3_opcode_templ mmurw =
      {"mmurw", ISET_ALL_COMPAT_MASK, parse_alf_args, NULL, MMURW,
       STORE | NO_MAS, 0x27, {0, 0, 1, 0, 0, 0}, ARGS_DDD};

    add_to_insn_table ((e2k_opcode_templ *) &mmurr);
    add_to_insn_table ((e2k_opcode_templ *) &mmurw);
  }

  E2K_OPCODE_VEC_ENTRY (incr, ISET_ALL_COMPAT_MASK, parse_incr_args);

  AAOPF1_VEC_ENTRY (movab, ISET_ALL_COMPAT_MASK, 0x1, ARGS_S);
  AAOPF1_VEC_ENTRY (movah, ISET_ALL_COMPAT_MASK, 0x2, ARGS_S);
  AAOPF1_VEC_ENTRY (movaw, ISET_ALL_COMPAT_MASK, 0x3, ARGS_S);
  AAOPF1_VEC_ENTRY (movad, ISET_ALL_COMPAT_MASK, 0x4, ARGS_D);
  AAOPF1_VEC_ENTRY (movaq, ISET_ALL_COMPAT_MASK, 0x5, ARGS_Q);
  AAOPF1_VEC_ENTRY (movaqp, ISET_ALL_COMPAT_MASK, 0x7, ARGS_D);

  E2K_OPCODE_VEC_ENTRY (fapb, ISET_ALL_COMPAT_MASK, parse_fapb_args);
  E2K_OPCODE_VEC_ENTRY (movep, ISET_ALL_COMPAT_MASK, parse_movep_args);

  E2K_OPCODE_VEC_ENTRY (flushts, ISET_V3_COMPAT_MASK, parse_flushts_args);

  E2K_OPCODE_VEC_ENTRY (clpandp, ISET_ALL_COMPAT_MASK, parse_cpl_args);
  E2K_OPCODE_VEC_ENTRY (clplandp, ISET_ALL_COMPAT_MASK, parse_cpl_args);

  E2K_OPCODE_VEC_ENTRY (set_mark, ISET_ALL_COMPAT_MASK, parse_set_mark_args);
  E2K_OPCODE_VEC_ENTRY (vfdi, ISET_ALL_COMPAT_MASK, parse_vfdi_args);
}
