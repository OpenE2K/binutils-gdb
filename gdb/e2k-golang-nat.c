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

#include "defs.h"
#include "regcache.h"
#include "gregset.h"
#include "target-descriptions.h"
#include "linux-nat.h"

/* Share E2K_GOLANG register numbers with `gdb/e2k-golang-tdep.c'.  */
#include "e2k-golang-tdep.h"

/* For PTRACE_{G,S}ETREGS helper stuff: e2k_linux_gregset_t is actually the
   user_regs_struct used to transfer the registers' contents between the
   tracer and the Kernel. Particular registers' offsets in this array can be
   evaluated with the help of `byte_offset()' and `gregset_idx()' macros.  */
#include "gdbsupport/e2k-linux-regs.h"

#include <sys/ptrace.h>

class e2k_golang_nat_target : public linux_nat_target
{
    /* Add the description reader.  */
  const struct target_desc *read_description () override;

  /* Add our register access methods.  */
  void fetch_registers (struct regcache *regcache, int regnum) override;
  void store_registers (struct regcache *regcache, int regnum) override;
};

static bool elbrus_v5_layout = false;

const struct target_desc *
e2k_golang_nat_target::read_description ()
{
  if (__builtin_cpu_is ("elbrus-v5") || __builtin_cpu_is ("elbrus-v6"))
    elbrus_v5_layout = true;

  return tdesc_e2k_golang;
}

static void
supply_gregset_regnum (struct regcache *regcache,
		       const gdb_gregset_t *gregsetp, int regnum)
{
  int i;
  const elf_greg_t *regp = *gregsetp;

  if (regnum == -1)
    {
      /* Only integer registers and PC are supported here.  */
      for (i = 0; i < NUM_E2K_GOLANG_RAW_REGS; i++)
	regcache->raw_supply (i, regp + i);
    }
  else
    regcache->raw_supply (regnum, regp + regnum);
}


void
supply_gregset (struct regcache *regcache, const gdb_gregset_t *gregsetp)
{
  supply_gregset_regnum (regcache, gregsetp, -1);
}

void
supply_fpregset (struct regcache *regcache, const gdb_fpregset_t *fpregsetp)
{
}

void
fill_gregset (const struct regcache *regcache, gdb_gregset_t *gregsetp,
	      int regnum)
{
}

void
fill_fpregset (const struct regcache *regcache, gdb_fpregset_t *fpregsetp,
	       int regnum)
{
}


void
e2k_golang_nat_target::fetch_registers (struct regcache *regcache, int regnum)
{
  int tid = get_ptrace_pid (regcache->ptid());
  e2k_linux_gregset_t exch = {0};
  exch[0] = sizeof (exch);
  e2k_golang_gregset_t regs = {0};

  if (ptrace (PTRACE_GETREGS, tid, 0, (void *) &exch) == -1)
    {
     perror_with_name (_("PTRACE_GETREGS failed"));
     return;
    }

  unsigned long long psp_base = (exch[gregset_idx (E2K_PSP_LO_REGNUM)]
				 & 0xffffffffffffULL);
  unsigned long long psp_ind = (exch[gregset_idx (E2K_PSP_HI_REGNUM)]
				& 0xffffffffULL);
  unsigned long long psp = psp_base + psp_ind;
  unsigned int wdsz = ((exch[gregset_idx (E2K_WD_REGNUM)] >> 16) & 0x7ff) >> 4;
  unsigned int wbs = ((exch[gregset_idx (E2K_CR1_LO_REGNUM)] >> 33) & 0x7f);
  unsigned int br = (exch[gregset_idx (E2K_CR1_HI_REGNUM)] & 0xfffffff);
  unsigned int rbs = br & 0x3f;
  unsigned int rsz_full = ((br >> 6) & 0x3f) + 1;
  unsigned int rcur = (br >> 12) & 0x3f;
  unsigned int i;

  /* Evaluate PSP on the user's side.  */
  psp -= 32 * wbs;

  /* The kernel provides us only with 6 syscall arguments via PTRACE_GETREGS.  */
  if (wdsz > 3)
    wdsz = 3;

  for (i = 0; i < wbs + wdsz && (i < 6 || (i >= rbs && i < rbs + rsz_full));
       i++)
    {
      unsigned long long even, odd;

      if (i < wbs)
	{
	  even = ptrace (PTRACE_PEEKDATA, tid, psp + 32 * i, NULL);
	  odd = ptrace (PTRACE_PEEKDATA, tid,
			psp + 32 * i + (elbrus_v5_layout ? 16 : 8), NULL);
	}
      else
	{
	  /* The kernel provides us only with 6 syscall arguments, which are
	     usually on %b[1], ..., %b[6]. But where should %b[0] be fetched
	     from? Presumably, from E2K_SYS_NUM_REGNUM on entrance and from
	     E2K_RVAL_REGNUM on return from the syscall, respectively. However,
	     it would be extremely awkward if possible at all to distinguish
	     between these two cases here. Therefore, why wouldn't
	     E2K_RVAL_REGNUM contain the "present" %b[0] value (i.e. either
	     syscall number or the result) throughout all syscall stages? Note
	     that currently it's not likely to be the case and has probably
	     never been on the Kernel side and, therefore, needs to be
	     revisited. E2K_SYS_NUM_REGNUM could still be used to keep the
	     syscall number from entrance to return from the syscall (recall
	     that gdb prints it out on return).

	     What about the user's %b[7]? Can its value be determined at all
	     within the syscall? Or is it principally unpredictable on return?
	     And why doesn't the kernel provide it via user_regs_struct?
	     Stupidly zero out it for now.  */
	  even = (2 * (i - wbs) <= 6
		  ? exch[gregset_idx (E2K_RVAL_REGNUM) + 2 * (i - wbs)]
		  : 0);
	  odd = (2 * (i - wbs) + 1 <= 6
		 ? exch[gregset_idx (E2K_RVAL_REGNUM) + 2 * (i - wbs) + 1]
		 : 0);
	}

      if (i < 6)
	{
	  regs[E2K_GOLANG_R0_REGNUM + 2 * i] = even;
	  regs[E2K_GOLANG_R0_REGNUM + 2 * i + 1] = odd;
	}

      if (i >= rbs && i < rbs + rsz_full)
	{
	 unsigned int qbidx = ((rsz_full - rcur) + (i - rbs)) % rsz_full;

	 if (qbidx < 4)
	    {
	      regs[E2K_GOLANG_B0_REGNUM + 2 * qbidx] = even;
	      regs[E2K_GOLANG_B0_REGNUM + 2 * qbidx + 1] = odd;
	    }
	}
    }

  regs[E2K_GOLANG_PC_REGNUM] = exch[gregset_idx (E2K_CR0_HI_REGNUM)];

  supply_gregset_regnum (regcache, &regs, regnum);
}

/* Store REGNUM (or all registers if REGNUM == -1) to the target
   from REGCACHE using PTRACE_SETREGSET.  */

void
e2k_golang_nat_target::store_registers (struct regcache *regcache, int regnum)
{
}

static e2k_golang_nat_target the_e2k_golang_nat_target;

void _initialize_e2k_golang_nat ();
void
_initialize_e2k_golang_nat ()
{
  /* Register the target.  */
  linux_target = &the_e2k_golang_nat_target;
  add_inf_child_target (&the_e2k_golang_nat_target);
}
