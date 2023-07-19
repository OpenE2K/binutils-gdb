/* GNU/Linux/E2K specific low level interface, for the remote server for GDB.
   Copyright (C) 1995, 1996, 1998, 1999, 2000, 2001, 2002, 2007, 2008, 2009,
   2010 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "server.h"
#include "linux-low.h"
#include "regdef.h"
#include "tdesc.h"
#include "nat/e2k-dregs.h"

/* FIXME: for now this should be defined before `e2k-regs.inc' which is
   included implicitly here. Get rid of it.  */
#define NEW_E2K_CALLS
#include "nat/e2k-linux.h"
#include "nat/e2k-linux-dregs.h"

#include <sys/ptrace.h>

/* Per-process arch-specific data we want to keep.  */

struct arch_process_info
{
  struct e2k_debug_reg_state debug_reg_state;
};


/* Defined in auto-generated file reg-e2k.c.  */
void init_registers_e2k (void);

void init_registers_elbrus_v2 (void);
void init_registers_elbrus_v3 (void);

/* Defined in auto-generated file reg-elbrus-v5.c.  */
void init_registers_elbrus_v5 (void);

extern const struct target_desc *tdesc_e2k;
extern const struct target_desc *tdesc_elbrus_v2;
extern const struct target_desc *tdesc_elbrus_v3;
extern const struct target_desc *tdesc_elbrus_v5;

static void
e2k_arch_setup (void)
{
  const struct target_desc *tdesc;

  if (tdesc_elbrus_v5)
    tdesc = tdesc_elbrus_v5;
  else  if (tdesc_elbrus_v3)
    tdesc = tdesc_elbrus_v3;
  else  if (tdesc_elbrus_v2)
    tdesc = tdesc_elbrus_v2;
  else
    tdesc = tdesc_e2k;

  if (e2k_linux_check_ptrace_singlestep ())
    tdesc_create_feature ((struct target_desc *) tdesc,
			  "org.mcst.gdb.e2k.singlestep");

  current_process ()->tdesc = tdesc;
}

static CORE_ADDR
e2k_get_pc (struct regcache *regcache)
{
  CORE_ADDR pc;

  collect_register_by_name (regcache, "cr0_hi", &pc);
  return pc;
}



/* This function is called when overlaying the contents of cached
   registers (probably containing modifications made by user in
   GDB) on the contents obtained by ptrace (PTRACE_GETREGS, . . .)
   prior to calling ptrace (PTRACE_SETREGS, . . .)
   (see `regsets_store_inferior_registers' in linux-low.c). */
static void
e2k_fill_gregset (struct regcache *regcache, void *buf)
{
  int i;
  int j;
  int have_elbrus_v2_regs;
  int have_elbrus_v3_regs;
  int have_elbrus_v5_regs;

  have_elbrus_v5_regs = tdesc_elbrus_v5 != NULL;
  have_elbrus_v3_regs = tdesc_elbrus_v3 != NULL || have_elbrus_v5_regs;
  have_elbrus_v2_regs = tdesc_elbrus_v2 != NULL || have_elbrus_v3_regs;

  

  /* `%_sizeof' has the same zero offset in REGSET (i.e. `user_regs_struct') as
     in REGCACHE.  */
  collect_register (regcache, 0,  (char *) buf + byte_offset (SIZEOF_REGNUM));

  collect_register (regcache, 1,
		    (char *) buf + byte_offset (E2K_SYS_NUM_REGNUM));

  /* `%_pcsp_offset' is located at the end of REGSET, but right after `%_sizeof'
     and `%sys_num' registers in REGCACHE. Note that the offset in REGCACHE is
     the same as in {g,G}-packet.  */
  collect_register (regcache, 2,
		    (char *) buf + byte_offset (E2K_PCSP_OFFSET));

  /* There's no point in transferring the nine trailing CALL-specific registers
     from REGCACHE to REGSET: the changes to these registers from GDB side are
     processed in a very specific way by `e2k_linux_regcache_changed ()'.  */
  for (i = E2K_G0_REGNUM, j = 3; i <= E2K_PSP_BASE; i++)
    {
      /* These ones have already been collected above. They've already given
	 their contribution to J.  */
      if (i == E2K_SYS_NUM_REGNUM || i == E2K_PCSP_OFFSET)
	continue;

      /* Skip registers unsupported by the CPU in use. Since they are missing
	 from GDBSERVER regcache and thus G-packet, they shouldn't contribute
	 to J.  */
      if ((i == E2K_IDR_REGNUM && ! have_elbrus_v2_regs)
	  || (i == E2K_CORE_MODE_REGNUM && ! have_elbrus_v3_regs)
	  || (i >= E2K_LSR1_REGNUM && i <= E2K_GTAG_V5_31_REGNUM
	      && ! have_elbrus_v5_regs))
	continue;


      if (
          /* Stupidly prevent debug registers from being collected from
             regcache and thus undo the settings done in prepare_to_resume.  */
          (i < E2K_DIBCR || i > E2K_DDBSR_REGNUM)

          /* FIXME: this prevents `%cr1.lo' from being collected. That probably
             spoiled `%cr1.lo.wbs' when resuming in a function being CALLed from
             within `e2k-linux-gdb'. `WD.size_q' was set not to its initial
             value of 4 in a function being CALLed, but to the value it had
             within the function from which the CALL was performed. As a result
             the callee obtained invalid parameters and spoiled registers
             belonging to the preceding windows. What's the point in letting the
             user modify `%cr1.lo.wbs' within the Kernel?  */
          && i != E2K_CR1_LO_REGNUM)
	collect_register (regcache, j, (char *) buf + byte_offset (i));

      /* This register should contribute to J even if it hasn't been collected
	 to REGSET because it's present in GDBSERVER REGCACHE and G-packet.  */
      j++;
    }

  /* This is a self-consistency check that no registers have been missed.  */
  gdb_assert (j == regcache->tdesc->reg_defs.size () - 9);
}

/* Other architectures do not use `find_register_by_number'
   here because register offsets withing ptrace
   (PTRACE_GETREGS, ...,  data) `data' buffer are not the
   same as the ones used by gdbserver when transmitting
   registers to the remote host. Instead they have bogus
   arrays for the former group of offsets. There are two
   many sets of registers and kinds of offsets within GDB
   indeed! */

static void
e2k_store_gregset (struct regcache *regcache, const void *buf)
{
  int i;
  int j;
  ULONGEST regcache_size;

  int have_elbrus_v2_regs;
  int have_elbrus_v3_regs;
  int have_elbrus_v5_regs;

  have_elbrus_v5_regs = tdesc_elbrus_v5 != NULL;
  have_elbrus_v3_regs = tdesc_elbrus_v3 != NULL || have_elbrus_v5_regs;
  have_elbrus_v2_regs = tdesc_elbrus_v2 != NULL || have_elbrus_v3_regs;


  memcpy (&regcache_size, buf, sizeof (regcache_size));

  /* `%_sizeof' has the same zero offset in REGSET (i.e. `user_regs_struct') as
     in REGCACHE.  */
  supply_register (regcache, 0,
		   (const char *) buf + byte_offset (SIZEOF_REGNUM));

  supply_register (regcache, 1,
		   (const char *) buf + byte_offset (E2K_SYS_NUM_REGNUM));
    

  /* `%_pcsp_offset' is located at the end of REGSET, but right after `%_sizeof'
     in REGCACHE. Note that the offset in REGCACHE is the same as in
     {g,G}-packet.  */
  supply_register (regcache, 2,
		   (const char *) buf + byte_offset (E2K_PCSP_OFFSET));


  /* There's no point in transferring the last 9 CALL-specific registers
     from REGSET to REGCACHE. Due to their specific nature these registers are
     only changed by GDB, they can't be fetched from the inferior.  */
  for (i = E2K_G0_REGNUM, j = 3; i <= E2K_PSP_BASE; i++)
    {
      int avail = 0;

      /* These ones have already been supplied above. They've already given
	 their contribution to J.  */
      if (i == E2K_SYS_NUM_REGNUM || i == E2K_PCSP_OFFSET)
	continue;

      /* Skip registers unsupported by the CPU in use. Since they are missing
	 from GDBSERVER regcache and thus G-packet, they shouldn't contribute
	 to J.  */
      if ((i == E2K_IDR_REGNUM && ! have_elbrus_v2_regs)
	  || (i == E2K_CORE_MODE_REGNUM && ! have_elbrus_v3_regs)
	  || (i >= E2K_LSR1_REGNUM && i <= E2K_GTAG_V5_31_REGNUM
	      && ! have_elbrus_v5_regs))
	continue;


      /* %lsr1, %ilcr1, %qpgX and %p{c,}sp_base registers require the new
	 user_regs_struct to be supplied, otherwise they should be considered
	 as unavailable. However, I make an exception for `%pcsp_base' which
	 is supplied as zero in this case, which is required for GDB to work
	 properly at present.  */
      if (regcache_size == SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT
	  || (regcache_size == SIZE_OF_ELBRUS_V5_USER_REGS_STRUCT
	      && i < E2K_DIMTP_LO_REGNUM)
          || i < E2K_LSR1_REGNUM
	  || i == E2K_PCSP_BASE)
	avail = 1;
      else if (i == E2K_PSP_BASE)
	{
	  ULONGEST psp_base;
	  memcpy (&psp_base, (const char *) buf + byte_offset (E2K_PSP_BASE),
		  sizeof (psp_base));

	  /* Make `%psp_base' available if it has been successfully fetched
	     from `/proc/PID/maps' inspite of the Kernel lacking support for
	     the latest user_regs_struct.  */
	  if (psp_base != 0)
	    avail = 1;
	}

      supply_register (regcache, j,
		       avail ? (const char *) buf + byte_offset (i) : NULL);

      /* This register should contribute to J even if it has been supplied to
	 REGCACHE as unavailable.  */
      j++;
    }

  /* This is a self-consistency check that no registers have been missed.  */
  gdb_assert (j == regcache->tdesc->reg_defs.size () - 9);
}

static struct regset_info e2k_regsets[] = {
  /* Once again, what's the difference between all these gregset's:
     gregset_t, elf_gregset_t and so on? */

  { PTRACE_GETREGS, PTRACE_SETREGS, 0, SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT + 8,
    GENERAL_REGS,
    e2k_fill_gregset, e2k_store_gregset },
  NULL_REGSET
};

static struct regsets_info e2k_regsets_info =
  {
    /* regsets  */
    e2k_regsets,
    /* num_regsets: this will be set in `initialize_regsets_info ()' within
       linux-low.c  */
    0,
    /* disabled_regsets.  */
    NULL
  };

static struct regs_info regs_info =
  {
    NULL,
    NULL,
    &e2k_regsets_info 
  };

static const struct regs_info *
e2k_regs_info (void)
{
  return &regs_info;
}

/* Low-level function vector.  */
struct e2k_dr_low_type e2k_dr_low =
  {
    e2k_linux_dr_get_ddbsr,
    e2k_linux_dr_get_ddbar
  };

/* Breakpoint/Watchpoint support.  */

static const gdb_byte *
e2k_sw_breakpoint_from_kind (int kind, int *size)
{
  /* I have no idea why `bp_size ()' in mem-break.c calls this method for
     non-SW breakpoints . . .  */
  *size = 0;
  return NULL;
}


static const gdb_byte e2k_breakpoint[8] = {
  0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28
};


static const gdb_byte e2k_legacy_breakpoint[8] = {
  0x01, 0x00, 0x00, 0x04, 0x80, 0xc0, 0xc0, 0x0d
};

static int
e2k_breakpoint_at (CORE_ADDR where)
{
  unsigned char insn[8];

  (*the_target->read_memory) (where, (unsigned char *) insn, sizeof (insn));

  if (memcmp (e2k_breakpoint, insn, sizeof (insn)) == 0
      /* FIXME: should the legacy breakpoint be supported at all nowadays?  */
      || memcmp (e2k_legacy_breakpoint, insn, sizeof (insn)) == 0)
    return 1;

  return 0;
}


static int
e2k_supports_z_point_type (char z_type)
{
  switch (z_type)
    {
#if 0
    case Z_PACKET_SW_BP:
#endif /* 0  */
    case Z_PACKET_HW_BP:
    case Z_PACKET_WRITE_WP:
    case Z_PACKET_ACCESS_WP:
      return 1;
    default:
      return 0;
    }
}

static int
e2k_insert_point (enum raw_bkpt_type type, CORE_ADDR addr,
		  int size, struct raw_breakpoint *bp)
{
  struct process_info *proc = current_process ();

  switch (type)
    {
    case raw_bkpt_type_hw:
    case raw_bkpt_type_write_wp:
    case raw_bkpt_type_access_wp:
      {
	enum target_hw_bp_type hw_type
	  = raw_bkpt_type_to_target_hw_bp_type (type);
	struct e2k_debug_reg_state *state
	  = &proc->priv->arch_private->debug_reg_state;

	return e2k_dr_insert_watchpoint (state, hw_type, addr, size);
      }

    default:
      /* Unsupported.  */
      return 1;
    }
}

static int
e2k_remove_point (enum raw_bkpt_type type, CORE_ADDR addr,
		  int size, struct raw_breakpoint *bp)
{
  struct process_info *proc = current_process ();

  switch (type)
    {
    case raw_bkpt_type_hw:
    case raw_bkpt_type_write_wp:
    case raw_bkpt_type_access_wp:
      {
	enum target_hw_bp_type hw_type
	  = raw_bkpt_type_to_target_hw_bp_type (type);
	struct e2k_debug_reg_state *state
	  = &proc->priv->arch_private->debug_reg_state;

	return e2k_dr_remove_watchpoint (state, hw_type, addr, size);
      }
    default:
      /* Unsupported.  */
      return 1;
    }
}

static int
e2k_stopped_by_watchpoint (void)
{
  struct process_info *proc = current_process ();
  return e2k_dr_stopped_by_watchpoint (&proc->priv->arch_private->debug_reg_state);
}

static CORE_ADDR
e2k_stopped_data_address (void)
{
  struct process_info *proc = current_process ();
  CORE_ADDR addr;
  if (e2k_dr_stopped_data_address (&proc->priv->arch_private->debug_reg_state,
				   &addr))
    return addr;
  return 0;
}

/* Called when a new process is created.  */

static struct arch_process_info *
e2k_linux_new_process (void)
{
  struct arch_process_info *info = XCNEW (struct arch_process_info);

  /* FIXME: the underlying code should be replaced with
     `e2k_low_init_dregs (&info->debug_reg_state)' which is to be implemented
     in `gdbserver/e2k-low.c'.  */
  memset (&info->debug_reg_state, 0, sizeof (info->debug_reg_state));

  return info;
}

/* Called when a process is being deleted.  */

static void
e2k_linux_delete_process (struct arch_process_info *info)
{
  xfree (info);
}

/* Implementation of linux_target_ops method "supports_hardware_single_step".
 */
static int
e2k_supports_hardware_single_step (void)
{
  return 1;
}



/* See nat/e2k-dregs.h.  */

struct e2k_debug_reg_state *
e2k_debug_reg_state (pid_t pid)
{
  struct process_info *proc = find_process_pid (pid);

  return &proc->priv->arch_private->debug_reg_state;
}


struct linux_target_ops the_low_target = {
  e2k_arch_setup,
  e2k_regs_info,
  NULL,                 /* cannot_fetch_register  */
  NULL,                 /* cannot_store_register  */
  NULL,			/* fetch_register  */
  e2k_get_pc,
  NULL,                 /* set_pc  */
  NULL,			/* breakpoint_kind_from_pc  */
  e2k_sw_breakpoint_from_kind,
  NULL,			/* get_next_pcs  */
  0,			/* decr_pc_after_break: should it be zero on E2K?  */
  e2k_breakpoint_at,	/* breakpoint_at  */
  e2k_supports_z_point_type,
  e2k_insert_point,	/* insert_point  */
  e2k_remove_point,	/* remove_point  */
  e2k_stopped_by_watchpoint,
  e2k_stopped_data_address,
  NULL,			/* collect_ptrace_register  */
  NULL,			/* supply_ptrace_register  */
  NULL,			/* siginfo_fixup  */
  e2k_linux_new_process,
  e2k_linux_delete_process, /* delete_process  */
  NULL,			/* new_thread  */
  NULL,			/* delete_thread  */
  NULL,			/* new_fork  */
  e2k_linux_prepare_to_resume,
  NULL,			/* process_qsupported  */
  NULL,			/* supports_tracepoints  */
  NULL,			/* get_thread_area  */
  NULL,			/* install_fast_tracepoint_jump_pad  */
  NULL,			/* emit_ops  */
  NULL,			/* get_min_fast_tracepoint_insn_len  */
  NULL,			/* supports_range_stepping  */
  NULL,			/* breakpoint_kind_from_current_state */
  e2k_supports_hardware_single_step,
  NULL,			/* get_syscall_trapinfo  */
  NULL,			/* x86_get_ipa_tdesc_idx  */

};

static int e2k_arch_idx = -1;
static ULONGEST e2k_entry_point;

void
e2k_linux_regcache_changed (struct regcache *regcache)
{
  typedef enum
  {
    arch_idx,
    entry_point,
    call_dummy,
    prologue,
    call_target,
    dbl_reg,
    dbl_stack,
    quad_reg,
    quad_stack,
    max_regnum
  } special_regnum;

  static const char *names[] =
    {
      "_e2k_arch_idx",
      "_e2k_entry_point",
      "_e2k_call_dummy",
      "_e2k_prologue",
      "_e2k_call_target",
      "_e2k_dbl_reg",
      "_e2k_dbl_stack",
      "_e2k_quad_reg",
      "_e2k_quad_stack",
      NULL
    };

  int i;
  int set[max_regnum];
  int sum = 0;
  gdb_byte buf[40];

  for (i = 0; i < max_regnum; i++)
    {
      gdb_byte tmp[40];
      collect_register_by_name (regcache, names[i], tmp);
      set[i] = tmp[0] != 0 ? 1 : 0;
      sum += set[i];

      gdb_assert (sum <= 1);

      if (set[i] != 0)
	{
	  int regcache_regno = find_regno (regcache->tdesc, names[i]);
	  memcpy (buf, tmp, register_size (regcache->tdesc,
					   regcache_regno));
	}
    }

  if (set[arch_idx] != 0)
    e2k_arch_idx = (int) (buf[0] - 1);
  else if (set[entry_point] != 0)
    {
      memcpy (&e2k_entry_point, buf, sizeof (e2k_entry_point));
      e2k_entry_point &= -2ULL;
    }
  else if (sum != 0)
    {
      int tid;

      /* A rather clumsy way to ensure that these registers have already
	 been set . . .  */
      gdb_assert (e2k_arch_idx != -1 && e2k_entry_point != 0);

      tid = current_lwp_ptid ().lwp ();

      if (set[call_dummy] != 0)
	e2k_linux_call_dummy (tid, e2k_arch_idx, e2k_entry_point);
      else if (set[prologue] != 0)
	{
	  ULONGEST getsp;
	  memcpy (&getsp, buf, sizeof (getsp));
	  getsp &= -2ULL;
	  e2k_linux_execute_dummy_prologue (tid, e2k_arch_idx, e2k_entry_point,
					    getsp);
	}
      else if (set[call_target] != 0)
	e2k_linux_call_target (tid, e2k_arch_idx, e2k_entry_point);
      else if (set[dbl_reg] != 0 || set[dbl_stack] != 0)
	e2k_linux_move_dbl_param (tid, e2k_arch_idx, e2k_entry_point, &buf[8],
				  set[dbl_reg] != 0);
      else if (set[quad_reg] != 0 || set[quad_stack] != 0)
	e2k_linux_move_quad_param (tid, e2k_arch_idx, e2k_entry_point, &buf[8],
				   set[quad_reg] != 0);
    }
  else
    {
      /* FIXME: get rid of this duplication with `gdb/e2k-linux-nat.c'.  */
      ULONGEST pcsp_base;
      ULONGEST req_pcsp_offset;
      e2k_linux_gregset_t regs;
      int tid = current_lwp_ptid ().lwp ();

      /* FIXME: direct `ptrace ()'s below with potentially unsupported
       SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT on the Kernel side are UNsafe.
       Consider replacing them with `e2k_linux_{g,s}etregs ()'.  */
      regs[0] = SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT;
      ptrace (PTRACE_GETREGS, tid, 0, (void *) regs);

      collect_register_by_name (regcache, "pcsp_base", &pcsp_base);
      collect_register_by_name (regcache, "_pcsp_offset", &req_pcsp_offset);

      if (((regs[gregset_idx (E2K_PCSP_LO_REGNUM)] & 0xffffffffffffULL)
	   + (regs[gregset_idx (E2K_PCSP_HI_REGNUM)] & 0xffffffff)
	   - pcsp_base - req_pcsp_offset) == 32)
	{

	  e2k_linux_return_from_dummy (tid, e2k_arch_idx, e2k_entry_point);

	  if (ptrace (PTRACE_GETREGS, tid, 0, (void *) regs) == -1)
	    perror_with_name (_("Couldn't get registers"));
	}

    }
}

void
initialize_low_arch (void)
{
  /* Initialize the Linux target descriptions.  */
  if (__builtin_cpu_is ("elbrus-v2"))
    init_registers_elbrus_v2 ();
  else if (__builtin_cpu_is ("elbrus-v3")
	   || __builtin_cpu_is ("elbrus-v4"))
    init_registers_elbrus_v3 ();
  else if (__builtin_cpu_is ("elbrus-v5")
	   || __builtin_cpu_is ("elbrus-v6"))
    init_registers_elbrus_v5 ();
  else
    init_registers_e2k ();

  initialize_regsets_info (&e2k_regsets_info);
}
