#include "gdbsupport/common-defs.h"
#include "nat/gdb_ptrace.h"
#include "nat/e2k-linux.h"
#include "nat/e2k-dregs.h"
#include "nat/e2k-linux-dregs.h"
#include "gdbsupport/e2k-linux-regs.h"

#include "gdb_proc_service.h"

static unsigned long
e2k_dr_get (int offs)
{
  int tid;
  e2k_linux_gregset_t regs;

  tid = current_lwp_ptid ().lwp ();
  if (tid == 0)
    /* Not a multi-threaded program.  */
    tid = current_lwp_ptid ().pid ();

  /* FIXME: these asserts are to be revisited.  */
  gdb_assert ((offs & 0x7) == 0);
  gdb_assert (offs >= 0 && offs + 8 <= SIZE_OF_ELBRUS_V1_USER_REGS_STRUCT);

  if (e2k_linux_getregs (tid, regs) == -1)
    perror_with_name (_("Couldn't get registers"));

  return regs[offs >> 3];
}

CORE_ADDR
e2k_linux_dr_get_ddbar (int regnum)
{
  gdb_assert (regnum >= 0 && regnum < N_DDBAR);
  return (CORE_ADDR) e2k_dr_get (byte_offset (E2K_DDBAR_0) + 8 * regnum);
}

#if 0
/* This one is not required right now.  */
static unsigned long
e2k_get_ddbcr ()
{
  return e2k_dr_get (byte_offset (E2K_DDBCR));
}

#endif /* 0  */

unsigned long
e2k_linux_dr_get_ddbsr (void)
{
  return e2k_dr_get (byte_offset (E2K_DDBSR_REGNUM));
}

void
e2k_linux_update_debug_registers (struct lwp_info *lwp)
{
  int i;
  int tid;
  e2k_linux_gregset_t regs;
  ptid_t ptid = ptid_of_lwp (lwp);
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (current_lwp_ptid ().pid ());

  /* GNU/Linux LWP ID's are process ID's.  */
  tid = ptid.lwp ();
  if (tid == 0)
     /* Not a multi-threaded program.  */
    tid = ptid.pid ();

  if (e2k_linux_getregs (tid, regs) == -1)
    return; //perror_with_name (_("Couldn't get registers"));

  /* FIXME: indexes into REGS[] should be specified in some regular way.  */
  ALL_DIBARS (i)
    regs[gregset_idx (E2K_DIBAR_0) + i] = state->dibar_mirror[i];

  regs[gregset_idx (E2K_DIBCR)] = state->dibcr_mirror;

  /* FIXME: remove this line: the memory location being set is overwritten
     a few lines below.  */
  regs[gregset_idx (E2K_DIBSR_REGNUM)] = state->dibsr_mirror;

  ALL_DDBARS (i)
    regs[gregset_idx (E2K_DDBAR_0) + i] = state->ddbar_mirror[i];

  regs[gregset_idx (E2K_DDBCR)] = state->ddbcr_mirror;


  /* FIXME: this line is to be removed either.  */
  regs[gregset_idx (E2K_DDBSR_REGNUM)] = state->ddbsr_mirror;


    /* FIXME: should this be done here?

       FIXME: I don't know if ptrace_offsets are going to be available
       here . . .  */

  /* e2k_linux_ptrace_offsets[E2K_DIBSR_REGNUM] */
  regs[gregset_idx (E2K_DIBSR_REGNUM)] = 0;

  /* A stupid attempt to ensure that no watchpoint hits are ever missed, as it
     periodically happens in Bug #84052, by analogy with how it was done in
     respect to hardware breakpoints one line above. The actual reason for such
     misses is to be investigated yet: who is to blame the Kernel which may
     presumably write junk into `%ddbsr' or GDB itself?  */

  /* e2k_linux_ptrace_offsets[E2K_DDBSR_REGNUM]  */
  regs[gregset_idx (E2K_DDBSR_REGNUM)] = 0;

  if (e2k_linux_setregs (tid, regs) == -1)
    return; //perror_with_name (_("Couldn't write registers"));
}
