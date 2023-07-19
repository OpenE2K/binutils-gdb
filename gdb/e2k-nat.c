#include "defs.h"
#include "e2k-nat.h"
#include "inferior.h"

struct e2k_dr_low_type e2k_dr_low;

struct e2k_process_info
{
  struct e2k_process_info *next;
  pid_t pid;
  struct e2k_debug_reg_state state;
};

static struct e2k_process_info *e2k_process_list;

/* Find process data for process PID.  */
static struct e2k_process_info *
e2k_find_process_pid (pid_t pid)
{
  struct e2k_process_info *proc;

  for (proc = e2k_process_list; proc; proc = proc->next)
    if (proc->pid == pid)
      return proc;

  return NULL;
}

/* Add process data for process PID.  Returns newly allocated info
   object.  */
static struct e2k_process_info *
e2k_add_process (pid_t pid)
{
  struct e2k_process_info *proc;

  proc = (struct e2k_process_info *) xcalloc (1, sizeof (*proc));
  proc->pid = pid;

  proc->next = e2k_process_list;
  e2k_process_list = proc;

  return proc;
}

/* Get data specific info for process PID, creating it if necessary.
   Never returns NULL.  */
static struct e2k_process_info *
e2k_process_info_get (pid_t pid)
{
  struct e2k_process_info *proc;

  proc = e2k_find_process_pid (pid);
  if (proc == NULL)
    proc = e2k_add_process (pid);

  return proc;
}



/* Get debug registers state for process PID.  */

struct e2k_debug_reg_state *
e2k_debug_reg_state (pid_t pid)
{
  return &e2k_process_info_get (pid)->state;
}


int
e2k_can_use_hw_breakpoint (enum bptype type, int cnt, int othertype)
{
  return 1;
}

int
e2k_region_ok_for_hw_watchpoint (CORE_ADDR addr, int len)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_region_ok_for_watchpoint (state, addr, len);
}

int
e2k_stopped_by_watchpoint ()
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_stopped_by_watchpoint (state);
}

int
e2k_stopped_data_address (CORE_ADDR *addr_p)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_stopped_data_address (state, addr_p);
}

int
e2k_insert_watchpoint (CORE_ADDR addr, int len,
		       enum target_hw_bp_type type, struct expression *cond)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_insert_watchpoint (state, type, addr, len);
}

int
e2k_remove_watchpoint (CORE_ADDR addr, int len,
		       enum target_hw_bp_type type, struct expression *cond)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_remove_watchpoint (state, type, addr, len);
}

int
e2k_insert_hw_breakpoint (struct gdbarch *gdbarch,
                          struct bp_target_info *bp_tgt)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  bp_tgt->placed_address = bp_tgt->reqstd_address;
  return (e2k_dr_insert_hw_breakpoint (state, bp_tgt->placed_address)
          ? EBUSY : 0);
}




int
e2k_remove_hw_breakpoint (struct gdbarch *gdbarch,
			  struct bp_target_info *bp_tgt)
{
  struct e2k_debug_reg_state *state
    = e2k_debug_reg_state (inferior_ptid.pid ());

  return e2k_dr_remove_hw_breakpoint (state, bp_tgt->placed_address);
}
