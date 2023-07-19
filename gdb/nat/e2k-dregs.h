#ifndef E2K_DREGS_H
#define E2K_DREGS_H 1

#include "gdbsupport/break-common.h" /* target_hw_bp_type */

/* Low-level function vector.  */

struct e2k_dr_low_type
{
  unsigned long (*get_ddbsr) (void);
  CORE_ADDR (*get_ddbar) (int);
};

extern struct e2k_dr_low_type e2k_dr_low;

#define N_DIBAR	4
#define N_DDBAR	4

struct e2k_debug_reg_state
{
  CORE_ADDR ddbar_mirror[N_DDBAR];
  uint64_t ddbsr_mirror, ddbcr_mirror;
  int ddbar_ref_count[N_DDBAR];

  CORE_ADDR dibar_mirror[N_DIBAR];
  uint64_t dibsr_mirror, dibcr_mirror;
  int dibar_ref_count[N_DIBAR];
};

#define ALL_DIBARS(i)	for (i = 0; i < N_DIBAR; i++)
#define ALL_DDBARS(i)	for (i = 0; i < N_DDBAR; i++)


/* Note that while this extern declaration resides in the common header for GDB
   and GDBSERVER, each of them should provide its own implementation.  */
extern struct e2k_debug_reg_state *e2k_debug_reg_state (pid_t pid);

extern int e2k_dr_insert_hw_breakpoint (struct e2k_debug_reg_state *state,
                                        CORE_ADDR addr);

extern int e2k_dr_remove_hw_breakpoint (struct e2k_debug_reg_state *state,
                                        CORE_ADDR addr);

extern int e2k_dr_region_ok_for_watchpoint (struct e2k_debug_reg_state *state,
                                            CORE_ADDR addr, int len);

extern int e2k_dr_insert_watchpoint (struct e2k_debug_reg_state *state,
                                     enum target_hw_bp_type type,
                                     CORE_ADDR addr, int len);

extern int e2k_dr_remove_watchpoint (struct e2k_debug_reg_state *state,
                                     enum target_hw_bp_type type,
                                     CORE_ADDR addr, int len);

extern int e2k_dr_stopped_data_address (struct e2k_debug_reg_state *state,
                                        CORE_ADDR *addr_p);

extern int e2k_dr_stopped_by_watchpoint (struct e2k_debug_reg_state *state);


#endif /* E2K_DREGS_H  */
