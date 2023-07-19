#ifndef E2K_LINUX_H
#define E2K_LINUX_H

#include "nat/linux-nat.h"
#include "gdbsupport/e2k-linux-regs.h"

#include "gdbsupport/common-defs.h"
#include "gdb_proc_service.h"

extern long e2k_linux_getregs (int tid, e2k_linux_gregset_t regs);
extern long e2k_linux_setregs (int tid, e2k_linux_gregset_t regs);

extern int e2k_linux_read_tags (int pid, gdb_byte *readbuf, ULONGEST offset,
                                ULONGEST len, ULONGEST *xfered_len);

/* Function to call prior to resuming a thread.  */
extern void e2k_linux_prepare_to_resume (struct lwp_info *lwp);


/* Functions used to implement CALLs at the native level in a way suitable
   both for GDB and GDBSERVER.  */
extern void e2k_linux_call_dummy (int tid, int arch_idx, ULONGEST pc);

extern void e2k_linux_execute_dummy_prologue (int tid, int arch_idx,
					      ULONGEST pc, ULONGEST getsp);

extern void e2k_linux_call_target (int tid, int arch_idx, ULONGEST pc);

extern void e2k_linux_move_dbl_param (int tid, int arch_idx, ULONGEST pc,
				      const gdb_byte *buf, int on_reg);

extern void e2k_linux_move_quad_param (int tid, int arch_idx, ULONGEST pc,
				       const gdb_byte *buf, int on_reg);

extern void e2k_linux_return_from_dummy (int tid, int arch_idx, ULONGEST pc);
extern void e2k_linux_enter_syscall (int tid, ULONGEST pc);

extern int e2k_linux_check_ptrace_singlestep (void);

#endif /* E2K_LINUX_H  */
