#ifndef E2K_NAT_H
#define E2K_NAT_H 1

#include "breakpoint.h"
#include "nat/e2k-dregs.h"

/* Hardware-assisted breakpoints and watchpoints.  */

/* Add hardware breakpoint and watchpoint methods to the provided
   TARGET_OPS. Targets using e2k family debug registers should call
   this.  */
struct target_ops;
extern void e2k_use_watchpoints (struct target_ops *);

/* Helper functions used by x86_nat_target below.  See their
   definitions.  */

extern int e2k_can_use_hw_breakpoint (enum bptype type, int cnt, int othertype);
extern int e2k_region_ok_for_hw_watchpoint (CORE_ADDR addr, int len);
extern int e2k_stopped_by_watchpoint ();
extern int e2k_stopped_data_address (CORE_ADDR *addr_p);
extern int e2k_insert_watchpoint (CORE_ADDR addr, int len,
				  enum target_hw_bp_type type,
				  struct expression *cond);
extern int e2k_remove_watchpoint (CORE_ADDR addr, int len,
				  enum target_hw_bp_type type,
				  struct expression *cond);
extern int e2k_insert_hw_breakpoint (struct gdbarch *,
				     struct bp_target_info *bp_tgt);
extern int e2k_remove_hw_breakpoint (struct gdbarch *,
				     struct bp_target_info *bp_tgt);

/* Convenience template mixin used to add x86 watchpoints support to a
   target.  */

template <typename BaseTarget>
struct e2k_nat_target : public BaseTarget
{
  /* Hook in the x86 hardware watchpoints/breakpoints support.  */

  int can_use_hw_breakpoint (enum bptype type, int cnt, int othertype) override
  { return e2k_can_use_hw_breakpoint (type, cnt, othertype); }

  int region_ok_for_hw_watchpoint (CORE_ADDR addr, int len) override
  { return e2k_region_ok_for_hw_watchpoint (addr, len); }

  int insert_watchpoint (struct gdbarch *, CORE_ADDR addr, int len,
			 enum target_hw_bp_type type,
			 struct expression *cond) override
  { return e2k_insert_watchpoint (addr, len, type, cond); }

  int remove_watchpoint (struct gdbarch *, CORE_ADDR addr, int len,
			 enum target_hw_bp_type type,
			 struct expression *cond) override
  { return e2k_remove_watchpoint (addr, len, type, cond); }

  int insert_hw_breakpoint (struct gdbarch *gdbarch,
			    struct bp_target_info *bp_tgt) override
  { return e2k_insert_hw_breakpoint (gdbarch, bp_tgt); }

  int remove_hw_breakpoint (struct gdbarch *gdbarch,
			    struct bp_target_info *bp_tgt) override
  { return e2k_remove_hw_breakpoint (gdbarch, bp_tgt); }

  bool stopped_by_watchpoint () override
  { return e2k_stopped_by_watchpoint (); }

  bool stopped_data_address (CORE_ADDR *addr_p) override
  { return e2k_stopped_data_address (addr_p); }
};

#endif /* E2K_NAT_H  */
