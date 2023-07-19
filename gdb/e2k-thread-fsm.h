#ifndef E2K_THREAD_FSM_H
#define E2K_THREAD_FSM_H

#include "infcall.h"
#include "thread-fsm.h"

typedef struct
{
  int in_regs;
  int nregs;
  union
  {
    int regno;
    int offset;
  } u;

  struct value *val[2];
} param_slot;

struct e2k_call_thread_fsm;
typedef struct
{
  size_t len;
  void (* adjust) (struct e2k_call_thread_fsm *);
  /* 32 `int's should be enough for all currently used instruction sequences.
     Specify `[32]' instead of `[]' so as to prevent G++ and LXX from barfing
     on an initializer of this field.  */
  int code[32];
} e2k_instr;


/* Data for the FSM that manages an infcall.  It's main job is to
   record the called function's return value.  */

struct e2k_call_thread_fsm
{
  /* The base class.  */
  struct thread_fsm thread_fsm;

  struct thread_fsm **in_thread_info;
  struct thread_fsm *prev;
  

  /* This one contains address of an intermediate breakpoint used to execute
     programs of `e2k_instr's.  */
  CORE_ADDR bp;

  /* This is `bp_addr' of a DUMMY breakpoint from `gdb/infcall.c'. I should
     simulate hitting it somehow when a CALL is done.  */
  CORE_ADDR bp_addr;

  CORE_ADDR funaddr;
  struct type *value_type;

  int stack_frame_size;
  int param_len;
  param_slot *params;

  e2k_instr *call_prog[5];
  int instr_idx;

  /* All the info necessary to be able to extract the return
     value.  */
  struct call_return_meta_info return_meta_info;

  /* The called function's return value.  This is extracted from the
     target before the dummy frame is popped.  */
  struct value *return_value;

  /* Set it when you see that the CALL has been interrupted. Later in `should_
     notify_stop' method say "yes" when the interrupted CALL is finished to
     ensure that `normal_stop ()' is called and thus DUMMY frame is popped.  */
  int was_interrupted;
};

extern struct e2k_call_thread_fsm *
new_e2k_call_thread_fsm (struct thread_fsm **in_thread_info,
                         struct gdbarch *gdbarch, struct value *function,
                         struct type *value_type,
                         int struct_return_p, CORE_ADDR struct_addr,
                         CORE_ADDR *real_pc, CORE_ADDR bp_addr,
                         CORE_ADDR funaddr, int nargs, struct value **args);



extern void adjust_inner_prologue (struct e2k_call_thread_fsm *sm);
extern e2k_instr inner_prologue;

extern void adjust_prepare_dbl_slot (struct e2k_call_thread_fsm *sm);


#endif /* E2K_THREAD_FSM_H  */
