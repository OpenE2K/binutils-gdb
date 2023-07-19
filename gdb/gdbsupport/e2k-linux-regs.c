#include "gdbsupport/e2k-linux-regs.h"

const int e2k_linux_ptrace_offsets[NUM_E2K_RAW_REGS] =
{
#define E2K_RAW_REG(a, b, c) b,
#define E2K_PSEUDO_REG(a, b)

  /* Define it for symmetry with inclusions of "e2k-regs.inc" into other files
     (wouldn't it be better to include "config.h" instead?). Otherwise the
     values in `e2k_linux_ptrace_offsets[]' won't match the actual target
     register numbers.  */
#define NEW_E2K_CALLS 1
#include "e2k-regs.inc"

#undef E2K_PSEUDO_REG
#undef E2K_RAW_REG
};
