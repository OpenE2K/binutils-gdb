/* Native-dependent code for GNU/Linux E2K.
   Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

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

#include "defs.h"
#include "inferior.h"
#include "gdb_proc_service.h"
#include "objfiles.h"
#include "regcache.h"
#include "target-descriptions.h"

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "e2k-nat.h"
#include "linux-nat.h"
#include "e2k-tdep.h"
#include "e2k-linux-tdep.h"
#include "nat/e2k-linux.h"
#include "nat/e2k-linux-dregs.h"
#include "nat/linux-btrace.h"


#include "gdbsupport/e2k-linux-regs.h"

void
supply_gregset (struct regcache *regcache, const prgregset_t *prgregs)
{
  e2k_linux_gregset_t gregs;
  /* Prevent GREGS buffer overflow when building GDB with glibc providing a
     more profound "gregset" than GDB's e2k_linux_gregset_t. Such a situation
     takes place with  glibc containing arg{7,...,12} in its  user_regs_struct
     (Bug #143282) until these registers are supported in GDB, but this sort of
     a test should be kept forever to allow for future non-synchronous
     extensions on glibc side. The reason for why it was not added from the
     very beginning was that glibc's "gregset" could prove to be less, but not
     more  profound during the build of GDB.  */
  memcpy (&gregs, prgregs,
	  (sizeof (*prgregs) <= SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT
	   ? sizeof (*prgregs) : SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT));
  memset (&gregs[gregset_idx (E2K_IDR_REGNUM)], 0,
	  byte_offset (E2K_PCSP_OFFSET) - byte_offset (E2K_IDR_REGNUM));

  /* Zero out `%_pcsp_offset'. It's unlikely to play any role here at all.  */
  gregs[gregset_idx (E2K_PCSP_OFFSET)] = 0;

  /* Presumably, the aforesaid also applies to the setting of LEN parameter as
     its value should be familiar to GDB.  */
  e2k_supply_gregset
    (regcache, -1, gregs,
     (sizeof (*prgregs) <= SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT
      ? sizeof (*prgregs) : SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT));
}

void
supply_fpregset (struct regcache *regcache, const gdb_fpregset_t *fpregs)
{
  e2k_supply_fpregset (e2k_linux_ptrace_offsets, regcache, -1, fpregs);
}


void
fill_gregset (const struct regcache *regcache, prgregset_t *gregs, int regnum)
{
  /* This function is used not only when providing `%g13' value via
     gregset for libthread_db, but also when generating a core file
     with `gcore' command (see linux_nat_corefile_thread_callback). */

  e2k_collect_gregset (e2k_linux_ptrace_offsets, regcache, regnum, gregs, 0);
}

void
fill_fpregset (const struct regcache *regcache,
	       gdb_fpregset_t *fpregs, int regnum)
{
}


static void
e2k_linux_fetch_inferior_registers (struct target_ops *ops,
                                    struct regcache *regcache,
				    int regno)
{
  int tid;
  e2k_linux_gregset_t gregs;

  /* GNU/Linux LWP ID's are process ID's.  */
  tid = regcache->ptid ().lwp ();
  if (tid == 0)
     /* Not a multi-threaded program.  */
    tid = regcache->ptid ().pid ();

  e2k_linux_getregs (tid, gregs);
  e2k_supply_gregset (regcache, -1, gregs, SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT);
}

#if defined NEW_E2K_CALLS





#endif /* defined NEW_E2K_CALLS  */

static void
e2k_linux_store_inferior_registers (struct target_ops *ops,
                                    struct regcache *regcache,
				    int regno)
{
  struct gdbarch *gdbarch = regcache->arch ();
  int tid;
  e2k_linux_gregset_t regs;
  ULONGEST pcsp_base;
  ULONGEST req_pcsp_offset;

  tid = regcache->ptid ().lwp ();
  if (tid == 0)
    tid = regcache->ptid ().pid ();

  if (e2k_linux_getregs (tid, regs) == -1)
    perror_with_name (_("Couldn't get registers"));

#if defined NEW_E2K_CALLS
    /* These "registers" are required only to trigger execution of certain
     instruction sequences. Ensure that they are not set when restoring a
     register cache.  */
  if (regno == E2K_CALL_DUMMY
      || regno == E2K_PROLOGUE
      || regno == E2K_CALL_TARGET
      || regno == E2K_DBL_REG || regno == E2K_DBL_STACK
      || regno == E2K_QUAD_REG || regno == E2K_QUAD_STACK)
    {
      ULONGEST entry_point = (ULONGEST) entry_point_address ();
      int ptr_bit = gdbarch_ptr_bit (gdbarch);
      ULONGEST arch_idx = ptr_bit == 128 ? 2 : (ptr_bit == 64 ? 0 : 1);

      switch (regno)
	{
	case E2K_CALL_DUMMY:
	  e2k_linux_call_dummy (tid, arch_idx, entry_point);
	  break;

	case E2K_PROLOGUE:
	  {
	    ULONGEST getsp;

	    regcache_raw_read_unsigned (regcache, E2K_PROLOGUE, &getsp);
	    /* Note that for the sake of GDBSERVER the non-zero least
	       significant bit here indicates that this register "is
	       active".  */
	    getsp &= -2ULL;
	    e2k_linux_execute_dummy_prologue (tid, arch_idx, entry_point,
					      getsp);
	  }
          break;

	case E2K_CALL_TARGET:
	  e2k_linux_call_target (tid, arch_idx, entry_point);
	  break;

	case E2K_DBL_REG:
	case E2K_DBL_STACK:
	  {
	    /* Note that for the sake of GDBSERVER the least significant 8-byte
	       dword in `dbl_param' type is reserved for the "set" field.  */
	    gdb_byte buf[25];
	    regcache->raw_read (regno, buf);
	    e2k_linux_move_dbl_param (tid, arch_idx, entry_point, &buf[8],
				      regno == E2K_DBL_REG);
	  }
	  break;

	case E2K_QUAD_REG:
	case E2K_QUAD_STACK:
	  {
	    /* The least significant 8 bytes have been reserved for the "set"
	       param in `quad_param' type as well.  */
	    gdb_byte buf[33];
	    regcache->raw_read (regno, buf);
	    e2k_linux_move_quad_param (tid, arch_idx, entry_point, &buf[8],
				       regno == E2K_QUAD_REG);
	  }
	  break;
	}

      e2k_linux_fetch_inferior_registers (ops, regcache, -1);
      return;
    }


  regcache_raw_read_unsigned (regcache, E2K_PCSP_BASE, &pcsp_base);
  regcache_raw_read_unsigned (regcache, E2K_PCSP_OFFSET, &req_pcsp_offset);

  if ((regs[gregset_idx (E2K_PCSP_LO_REGNUM)] & 0xffffffffffffULL)
      + (regs[gregset_idx (E2K_PCSP_HI_REGNUM)] & 0xffffffff)
      - pcsp_base - req_pcsp_offset == 32)
    {
      ULONGEST entry_point = (ULONGEST) entry_point_address ();
      int ptr_bit = gdbarch_ptr_bit (gdbarch);
      ULONGEST arch_idx = ptr_bit == 128 ? 2 : (ptr_bit == 64 ? 0 : 1);
      ULONGEST sys_rnum;

      e2k_linux_return_from_dummy (tid, arch_idx, entry_point);

      regcache_raw_read_unsigned (regcache, E2K_SYS_NUM_REGNUM, &sys_rnum);
      if (sys_rnum != -1ULL)
        e2k_linux_enter_syscall (tid, entry_point);

      if (e2k_linux_getregs (tid, regs) == -1)
        perror_with_name (_("Couldn't get registers"));

      /* Fall through.  */
    }

#endif /* defined NEW_E2K_CALLS  */

  /* Why shouldn't we synchronize with all registers changed within regcache
     rather than with the specified one only? I mean the usage of `-1' instead
     of `regno' below.  */
  e2k_collect_gregset (e2k_linux_ptrace_offsets, regcache, -1, regs, 0);

  if (e2k_linux_setregs (tid, regs) == -1)
    perror_with_name (_("Couldn't write registers"));
}

static const struct target_desc *
e2k_linux_read_description (struct target_ops *ops)
{
  struct target_desc *result;

  if (__builtin_cpu_is ("elbrus-v6"))
    result = tdesc_elbrus_v6_linux;
  else if (__builtin_cpu_is ("elbrus-v5"))
    result = tdesc_elbrus_v5_linux;
  else if (__builtin_cpu_is ("elbrus-v4") || __builtin_cpu_is ("elbrus-v3"))
    result = tdesc_elbrus_v3_linux;
  else if (__builtin_cpu_is ("elbrus-v2"))
    result = tdesc_elbrus_v2_linux;
  else
    result = tdesc_e2k_linux;

  if (e2k_linux_check_ptrace_singlestep ())
    tdesc_create_feature (result, "org.mcst.gdb.e2k.singlestep");

  return result;
}

struct e2k_linux_nat_target : public e2k_nat_target<linux_nat_target>
{
  virtual ~e2k_linux_nat_target () override {}

  /* Override the GNU/Linux inferior startup hook.  */
  void post_startup_inferior (ptid_t ptid) override
  { linux_nat_target::post_startup_inferior (ptid); }

  /* Add the description reader.  */
  const struct target_desc *read_description () override
  { return e2k_linux_read_description (this); }

  struct btrace_target_info *enable_btrace (ptid_t ptid,
					    const struct btrace_config *conf) override
  { return nullptr; }
  void disable_btrace (struct btrace_target_info *tinfo) override {}
  void teardown_btrace (struct btrace_target_info *tinfo) override {}
  enum btrace_error read_btrace (struct btrace_data *data,
				 struct btrace_target_info *btinfo,
				 enum btrace_read_type type) override
  { return linux_read_btrace (data, btinfo, type); }
  const struct btrace_config *btrace_conf (const struct btrace_target_info *btinfo) override
  { return linux_btrace_conf (btinfo); }

  /* These two are rewired to low_ versions.  linux-nat.c queries
     stopped-by-watchpoint info as soon as an lwp stops (via the low_
     methods) and caches the result, to be returned via the normal
     non-low methods.  */
  bool stopped_by_watchpoint () override
  { return linux_nat_target::stopped_by_watchpoint (); }

  bool stopped_data_address (CORE_ADDR *addr_p) override
  { return linux_nat_target::stopped_data_address (addr_p); }

  bool low_stopped_by_watchpoint () override
  { return e2k_nat_target::stopped_by_watchpoint (); }

  bool low_stopped_data_address (CORE_ADDR *addr_p) override
  { return e2k_nat_target::stopped_data_address (addr_p); }

  void low_new_fork (struct lwp_info *parent, pid_t child_pid) override
  {}

  //  void low_forget_process (pid_t pid) override
  // { e2k_forget_process (pid); }

  void low_prepare_to_resume (struct lwp_info *lwp) override
  { e2k_linux_prepare_to_resume (lwp); }

  // void low_new_thread (struct lwp_info *lwp) override
  // { e2k_linux_new_thread (lwp); }

  // void low_delete_thread (struct arch_lwp_info *lwp) override
  // { e2k_linux_delete_thread (lwp); }

  // void resume (ptid_t ptid, int step, enum gdb_signal signo) override
  // { inf_ptrace_target::resume (ptid, step, signo); }

  void store_registers (struct regcache *regcache, int regnum) override
  { e2k_linux_store_inferior_registers (this, regcache, regnum); }


  enum target_xfer_status xfer_partial (enum target_object object,
					const char *annex,
					gdb_byte *readbuf,
					const gdb_byte *writebuf,
					ULONGEST offset, ULONGEST len,
					ULONGEST *xfered_len) override;

  void fetch_registers (struct regcache *regcache, int regno) override
  { e2k_linux_fetch_inferior_registers (this, regcache, regno); }
};

enum target_xfer_status
e2k_linux_nat_target::xfer_partial (enum target_object object,
				    const char *annex,
				    gdb_byte *readbuf,
				    const gdb_byte *writebuf,
				    ULONGEST offset, ULONGEST len,
				    ULONGEST *xfered_len)
{
  int pid;

  pid = inferior_ptid.lwp ();
  /* What is this needed for? This code is met everywhere . . . */
  if (pid == 0)
    pid = inferior_ptid.pid ();

  if (object == TARGET_OBJECT_TAG)
    {
      if (writebuf == NULL)
        {
          if (e2k_linux_read_tags (pid, readbuf, offset, len, xfered_len) == 0)
            return TARGET_XFER_OK;

          return TARGET_XFER_E_IO;
        }
      else
        {
          ULONGEST i;
          for (i = 0; i < len; i++)
            ptrace (PTRACE_POKETAG, pid, offset + 4 * i, 0 /* ??? */);
        }
    }

  return linux_nat_target::xfer_partial (object, annex, readbuf, writebuf,
					 offset, len, xfered_len);
}

static e2k_linux_nat_target the_e2k_linux_nat_target;

void _initialize_e2k_linux_nat (void);

void
_initialize_e2k_linux_nat (void)
{
  e2k_dr_low.get_ddbsr = e2k_linux_dr_get_ddbsr;
  e2k_dr_low.get_ddbar = e2k_linux_dr_get_ddbar;

  linux_target = &the_e2k_linux_nat_target;
  /* Add the target.  */
  add_inf_child_target (linux_target);


  // super_xfer_partial = t->to_xfer_partial;
  // t->to_xfer_partial = e2k_linux_xfer_partial;

  // t->to_read_description = e2k_linux_read_description;

  /* Register the target.  */
  // linux_nat_add_target (t);

  /* To ensure that debug registers are updated before resuming.  */
  // linux_nat_set_prepare_to_resume (t, e2k_linux_prepare_to_resume);
}
