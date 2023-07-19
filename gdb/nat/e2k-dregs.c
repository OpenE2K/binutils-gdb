#include "gdbsupport/common-defs.h"
#include "e2k-dregs.h"

/* Return the value of the inferior's %ddbsr register.  */
#define e2k_dr_low_get_ddbsr() (e2k_dr_low.get_ddbsr ())
#define e2k_dr_low_get_ddbar(i) (e2k_dr_low.get_ddbar (i))


#define DIBCR_GROUP_SIZE 2
#define DIBSR_B_SIZE 1

#define E2K_DIBAR_VACANT(state, i) \
  (((state)->dibcr_mirror & (0x3 << (DIBCR_GROUP_SIZE * i))) == 0)


#define E2K_DIBAR_ENABLE(state, i) \
  do { \
    (state)->dibcr_mirror |= \
      (0x3 << (DIBCR_GROUP_SIZE * i)); \
  } \
  while (0)


#define E2K_DIBAR_DISABLE(state, i) \
  do { \
    (state)->dibcr_mirror &= \
      ~(0x3 << (DIBCR_GROUP_SIZE * i));	\
  } \
  while (0)

#define E2K_DIBSR_CLEAR_B(state, i) \
  do { \
    (state)->dibsr_mirror &= \
      ~(0x1 << (DIBSR_B_SIZE * i)); \
  } \
  while (0)
  

#define DDBCR_WRITE	1
#define DDBCR_READ	2
#define DDBCR_ACCESS	3

#define DDBCR_LEN_1	(0x1 << 2)
#define DDBCR_LEN_2	(0x2 << 2)
#define DDBCR_LEN_4	(0x3 << 2)
#define DDBCR_LEN_8	(0x4 << 2)
#define DDBCR_LEN_16	(0x5 << 2)


#define DDBCR_RW_LEN_SHIFT 2
#define DDBCR_GROUP_SIZE 14

#define DDBSR_B_SIZE 12


#define E2K_DDBAR_VACANT(state, i) \
  (((state)->ddbcr_mirror & (0x1001ull << (DDBCR_GROUP_SIZE * i))) == 0)

/* Set and clear `Vi' and `Ti' simultaneously.  */
#define E2K_DDBAR_ENABLE(state, i)              \
  do {                                          \
    (state)->ddbcr_mirror |=                    \
      (0x1001ull << (DDBCR_GROUP_SIZE * i));    \
  } while (0)


#define E2K_DDBAR_DISABLE(state, i)             \
  do {                                          \
    (state)->ddbcr_mirror &=                    \
      ~(0x1001ull << (DDBCR_GROUP_SIZE * i));   \
  } while (0)

#define E2K_DDBSR_CLEAR_B(state, i) \
  do { \
    (state)->ddbsr_mirror &= \
      ~(0xffull << (DDBSR_B_SIZE * i)); \
  } \
  while (0)



#define E2K_DDBAR_GET_RW_LEN(state, i) \
  (((state)->ddbcr_mirror \
    >> (DDBCR_RW_LEN_SHIFT + DDBCR_GROUP_SIZE * i)) & 0x1f)


/* Explicitily set all these fields in %DDBCR along with RW and LEN except for
   `Vj' and `Tj' which are set in E2K_DDBCR_{ENABLE,DISABLE} and `SFj', `HWj'
   which I've never touched before (i.e. in my previous implementation of
   watchpoints).  */
#define E2K_DDBAR_SET_RW_LEN(state, i, rwlen)                   \
  do {                                                          \
    (state)->ddbcr_mirror &=                                    \
      ~(0x3feull << (DDBCR_GROUP_SIZE * i));                       \
    (state)->ddbcr_mirror |=                                    \
      ((uint64_t) (0x380 | (rwlen << DDBCR_RW_LEN_SHIFT))       \
       << (DDBCR_GROUP_SIZE * i));                              \
  } while (0)

#define E2K_DDBAR_HIT(ddbsr, i) \
  ((ddbsr & (0xffull << (DDBSR_B_SIZE * i))) != 0)





static void
e2k_update_inferior_debug_regs (struct e2k_debug_reg_state *state,
                                struct e2k_debug_reg_state *new_state)
{
  int i;

  ALL_DIBARS (i)
  {
    /* On x86 they call `lwp_set_debug_registers_changed (1)' in case the new
       register's value is different from the old one. Later in `prepare_to_
       resume ()' this is used as a criterion that debug registers should be
       updated via `ptrace ()'. However, I always have to update them via
       `ptrace ()' because of our stupid %ddbsr and %dibsr behaviour. Therefore
       I don't have analogs for `x86_linux_dr_set_{addr,control} ()'.  */
    if (E2K_DIBAR_VACANT (new_state, i) == E2K_DIBAR_VACANT (state, i))
      gdb_assert (new_state->dibar_mirror[i] == state->dibar_mirror[i]);
  }


  ALL_DDBARS (i)
  {
    /* See the above comment on what could be done in the opposite case and why
       it's not done for E2K.  */
    if (E2K_DDBAR_VACANT (new_state, i) == E2K_DDBAR_VACANT (state, i))
      gdb_assert (new_state->ddbar_mirror[i] == state->ddbar_mirror[i]);
  }


  *state = *new_state;
}



/* Insert a hardware-assisted breakpoint at BP_TGT->placed_address.
   Return 0 on success, EBUSY on failure.  */
int
e2k_dr_insert_hw_breakpoint (struct e2k_debug_reg_state *state,
                             CORE_ADDR addr)
{
  struct e2k_debug_reg_state local_state = *state;
  int i, vacant = 4;

  ALL_DIBARS (i)
    {
      if (! E2K_DIBAR_VACANT (state, i))
        {
          if (local_state.dibar_mirror[i] == addr)
            {
              local_state.dibar_ref_count[i]++;
              break;
            }
        }
      else if (vacant == 4)
        vacant = i;
    }

  if (i == 4 && vacant == 4)
      return -1;

  if (i == 4)
    {
      /* Presumably, `bi' in `%dibsr' should be zeroed out no matter
         whether we've fetched a new `%dibari' or reuse an existing one
         (see a call to `clear_dibsr_b ()' after this lexical block).
         So it's convenient to migrate from `vacant' to `i' right
         now.  */
      i = vacant;


      E2K_DIBAR_ENABLE (&local_state, i);
      local_state.dibar_mirror[i] = addr;
      local_state.dibar_ref_count[i] = 1;
    }

  /* Clear `dibsr.bi', otherwise no reaction to hit may follow.  */
  E2K_DIBSR_CLEAR_B (&local_state, i);

  e2k_update_inferior_debug_regs (state, &local_state);
  return 0;
}

/* Remove a hardware-assisted breakpoint at BP_TGT->placed_address.
   Return 0 on success, -1 on failure.  */
int
e2k_dr_remove_hw_breakpoint (struct e2k_debug_reg_state *state,
                             CORE_ADDR addr)
{
  int i, retval = -1;

  struct e2k_debug_reg_state local_state = *state;

#if 0

  /* It seems that breakpoints are removed after a `call_function_by_hand'
     is finished. At this very moment we may very well have
     `crnt_dsp_idx == -1' (it's temprarely set to `-1' to make e2k function
     call possible). . . Therefore verify whether this breakpoint's gdbarch
     is DSP or not instead.  */
  if (target_gdbarch () != gdbarch)
    return dsp_remove_hw_breakpoint (ops, gdbarch, bp_tgt);

#endif /* 0  */

  ALL_DIBARS (i)
    {

      if (! E2K_DIBAR_VACANT (&local_state, i)
#if 0
          /* Is this condition required at all?  */
           && ivar_field (dibcr, ti)
#endif /* 0  */
	  )
        {

          if (local_state.dibar_mirror[i] == addr)
            {
	       /* No longer in use?  */
              if (--local_state.dibar_ref_count[i] == 0)
                {
		  /* This means set `Vi' and `Ti' fields to 0.  */
		  E2K_DIBAR_DISABLE (&local_state, i);
		  local_state.dibar_mirror[i] = 0;
                }

              retval = 0;
            }
        }
    }

  if (retval == 0)
    e2k_update_inferior_debug_regs (state, &local_state);

  return retval;
}

static unsigned
e2k_length_and_rw_bits (int len, enum target_hw_bp_type type)
{
  unsigned rw;

  switch (type)
    {
    case hw_write:
      rw = DDBCR_WRITE;
      break;
    case hw_read:
      rw = DDBCR_READ;
      break;
    case hw_access:
      rw = DDBCR_ACCESS;
	break;
      default:
	internal_error (__FILE__, __LINE__, _("\
Invalid hardware breakpoint type %d in e2k_watchpoint_rw_encoding.\n"),
			(int) type);
    }

  switch (len)
    {
    case 1:
      return (DDBCR_LEN_1 | rw);
    case 2:
      return (DDBCR_LEN_2 | rw);
    case 4:
      return (DDBCR_LEN_4 | rw);
    case 8:
      return (DDBCR_LEN_8 | rw);
    case 16:
      return (DDBCR_LEN_16 | rw);
    default:
      internal_error (__FILE__, __LINE__, _("\
Invalid hardware breakpoint length %d in e2k_watchpoint_len_encoding.\n"), len);
    }

  return 0;
}



static int
e2k_insert_aligned_watchpoint (struct e2k_debug_reg_state *state,
			       CORE_ADDR addr,
                               unsigned len_rw_bits)
{
  int i, vacant = 4;

  ALL_DDBARS (i)
    {
      if (! E2K_DDBAR_VACANT (state, i))
	{
	  if (state->ddbar_mirror[i] == addr
	      && E2K_DDBAR_GET_RW_LEN (state, i) == len_rw_bits)
	    {
	      state->ddbar_ref_count[i]++;
	      break;
	    }
	}
      else if (vacant == 4)
        vacant = i;
    }

  /* No more debug registers!  */
  if (i == 4 && vacant == 4)
    return -1;


  if (i == 4)
    {
      /* Presumably, bits in `%ddbsr' should be zeroed out no matter
         whether we've fetched a new `%ddbari' or reuse an existing one
         (see a piece of code just after the current block). So it's
         convenient to migrate from `vacant' to `i' right now.  */
      i = vacant;

      E2K_DDBAR_SET_RW_LEN (state, i, len_rw_bits);
      E2K_DDBAR_ENABLE (state, i);
      state->ddbar_mirror[i] = addr;
      state->ddbar_ref_count[i] = 1;
    }

  /* Thank our processor engineers for an additional need to clear the related
     group of fields in %DDBSR.  */
  E2K_DDBSR_CLEAR_B (state, i);
  return 0;
}


/* Remove a watchpoint at address ADDR, which is assumed to be aligned
   according to the length of the region to watch.  LEN_RW_BITS is the
   value of the bits from DR7 which describes the length and access
   type of the region watched by this watchpoint.  Return 0 on
   success, -1 on failure.  */

static int
e2k_remove_aligned_watchpoint (struct e2k_debug_reg_state *state,
                               CORE_ADDR addr,
                               unsigned len_rw_bits)
{
  int i, retval = -1;

  ALL_DDBARS (i)
    {
      if (! E2K_DDBAR_VACANT (state, i)
	  && state->ddbar_mirror[i] == addr
	  && E2K_DDBAR_GET_RW_LEN (state, i) == len_rw_bits)
        {
	   /* No longer in use?  */
	  if (--state->ddbar_ref_count[i] == 0)
	    {
	      /* Is there actually any point in resetting %DDBARi?  */
	      state->ddbar_mirror[i] = 0;
	      E2K_DDBAR_DISABLE (state, i);
            }
	  retval = 0;
        }
    }

  return retval;
}


/* Types of operations supported by `e2k_handle_nonaligned_watchpoint ()'.  */
typedef enum { WP_INSERT, WP_REMOVE, WP_COUNT } e2k_wp_op_t;

/* Insert or remove a (possibly non-aligned) watchpoint, or count the
   number of debug registers required to watch a region at address
   ADDR whose length is LEN for accesses of type TYPE.  Return 0 on
   successful insertion or removal, a positive number when queried
   about the number of registers, or -1 on failure.  If WHAT is not a
   valid value, bombs through internal_error.  */

static int
e2k_handle_nonaligned_watchpoint (struct e2k_debug_reg_state *state,
                                  e2k_wp_op_t what,
                                  CORE_ADDR addr, int len,
                                  enum target_hw_bp_type type)
{
  int retval = 0, status = 0;

  static int size_try_array[16][16] =
  {
    /* Trying size one.  */
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    /* Trying size two.  */
    {2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
    /* Trying size three.  */
    {2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
    /* Trying size four.  */
    {4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size five.  */
    {4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size six.  */
    {4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size seven.  */
    {4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size eight.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size nine.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size ten.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size eleven.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size twelve.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size thirteen.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size fourteen.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size fifteen.  */
    {8, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},
    /* Trying size sixteen.  */
    {16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1},

  };

  while (len > 0)
    {
      int align = addr % 16;
      /* Sixteen is the maximum length a debug register can watch at E2K.  */
      int attempt = (len > 16 ? (16 - 1) : len - 1);
      int size = size_try_array[attempt][align];

      if (what == WP_COUNT)
	{
	  /* size_try_array[] is defined such that each iteration
	     through the loop is guaranteed to produce an address and a
	     size that can be watched with a single debug register.
	     Thus, for counting the registers required to watch a
	     region, we simply need to increment the count on each
	     iteration.  */
	  retval++;
	}
      else
	{
          unsigned len_rw = e2k_length_and_rw_bits (size, type);

	  if (what == WP_INSERT)
	    status = e2k_insert_aligned_watchpoint (state, addr, len_rw);
	  else if (what == WP_REMOVE)
	    status = e2k_remove_aligned_watchpoint (state, addr, len_rw);
	  else
	    internal_error (__FILE__, __LINE__, _("\
Invalid value %d of operation in e2k_handle_nonaligned_watchpoint.\n"),
			    (int)what);
	  /* We keep the loop going even after a failure, because some
	     of the other aligned watchpoints might still succeed
	     (e.g. if they watch addresses that are already watched,
	     in which case we just increment the reference counts of
	     occupied debug registers).  If we break out of the loop
	     too early, we could cause those addresses watched by
	     other watchpoints to be disabled when breakpoint.c reacts
	     to our failure to insert this watchpoint and tries to
	     remove it.  */
	  if (status)
	    retval = status;
	}

      addr += size;
      len -= size;
    }

  return retval;
}

/* Return non-zero if we can watch a memory region that starts at
   address ADDR and whose length is LEN bytes.  */

int
e2k_dr_region_ok_for_watchpoint (struct e2k_debug_reg_state *state,
                                 CORE_ADDR addr,
                                 int len)
{
  int nregs;

  /* Compute how many aligned watchpoints we would need to cover this
     region.  */

  nregs = e2k_handle_nonaligned_watchpoint (state, WP_COUNT, addr,
                                            len, hw_write);
  return nregs <= 4 ? 1 : 0;
}




int
e2k_dr_insert_watchpoint (struct e2k_debug_reg_state *state,
                          enum target_hw_bp_type type,
                          CORE_ADDR addr,
                          int len)
{
  int retval;
  /* Work on a local copy of the debug registers, and on success,
     commit the change back to the inferior.  */
  struct e2k_debug_reg_state local_state = *state;

  if ((len != 1 && len != 2 && len != 4 && len != 8 && len != 16)
      || addr % len != 0)
    retval = e2k_handle_nonaligned_watchpoint (&local_state, WP_INSERT, addr,
                                               len, type);
  else
    {
      unsigned len_rw = e2k_length_and_rw_bits (len, type);
      retval = e2k_insert_aligned_watchpoint (&local_state, addr, len_rw);
    }

  if (retval == 0)
    e2k_update_inferior_debug_regs (state, &local_state);

  return retval;
}

int
e2k_dr_remove_watchpoint (struct e2k_debug_reg_state *state,
                          enum target_hw_bp_type type,
                          CORE_ADDR addr,
                          int len)
{
  int retval;
  /* Work on a local copy of the debug registers, and on success,
     commit the change back to the inferior.  */
  struct e2k_debug_reg_state local_state = *state;


  if ((len != 1 && len != 2 && len != 4 && len != 8 && len != 16)
      || addr % len != 0)
    retval = e2k_handle_nonaligned_watchpoint (&local_state, WP_REMOVE,
                                               addr, len, type);
  else
    {
      unsigned len_rw = e2k_length_and_rw_bits (len, type);
      retval = e2k_remove_aligned_watchpoint (&local_state, addr, len_rw);
    }

  if (retval == 0)
    e2k_update_inferior_debug_regs (state, &local_state);

  return retval;
}


int
e2k_dr_stopped_data_address (struct e2k_debug_reg_state *state,
                             CORE_ADDR *addr_p)
{
  int i;
  int res;
  CORE_ADDR addr;
  /* The current thread's DDBSR.  */
  uint64_t ddbsr = e2k_dr_low_get_ddbsr ();

  /* Make sure that we see the difference between the current state and the new
     one with DDBSR zeroed out in `e2k_update_inferior_debug_regs ()' and
     propagate the zero value to an inferior.  */
  state->ddbsr_mirror = ddbsr;

  res = 0;
  addr = 0;

  ALL_DDBARS (i)
    {
      if (E2K_DDBAR_HIT (ddbsr, i))
        {
          /* I don't know whether this check is actually needed. It
             is borrowed from `i386-nat.c'.  */
          if (! E2K_DDBAR_VACANT (state, i))
            {
              addr = e2k_dr_low_get_ddbar (i);
              res = 1;
            }
        }
    }

  if (res)
    *addr_p = addr;

  return res;
}

int
e2k_dr_stopped_by_watchpoint (struct e2k_debug_reg_state *state)
{
  CORE_ADDR addr = 0;

  return e2k_dr_stopped_data_address (state, &addr);
}
