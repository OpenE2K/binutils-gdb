#include "gdbsupport/common-defs.h"
#include "gdb_proc_service.h"

#include <sys/ptrace.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>

#include <fcntl.h>

/* This is a rather stupid hacks to bring all needed registers into play.
   NEW_E2K_CALLS should be eliminated at all nowadays.  */
#define NEW_E2K_CALLS 1
#include "nat/e2k-linux.h"
#include "nat/e2k-linux-dregs.h"


static greg_t
get_stack_base (int pid, const char *stack_name)
{
  char mapsfilename[PATH_MAX];
  FILE *mapsfile;

  long long addr, endaddr, offset, inode;
  char permissions[8], device[8];
  /* This can be either a filename or some other information like "[chain
     stack]" provided by the Kernel.  */
  char misc[PATH_MAX];

  sprintf (mapsfilename, "/proc/%d/maps", pid);
  mapsfile = fopen (mapsfilename, "r");

  /* FIXME: in the currently non existent version of this function for native
     GDB I used to call `error ()' under the same circumstances rather than just
     silently return undefined (i.e. zero) value.  */
  if (mapsfile == NULL)
    return 0;

  while (1)
    {
      int ret;
      ret = fscanf (mapsfile, "%llx-%llx %s %llx %s %llx",
		    &addr, &endaddr, permissions, &offset, device, &inode);

      if (ret < 6 || ret == EOF)
	break;

      misc[0] = '\0';
      /* Eat everything up to EOL for MISC.  */
      ret = fscanf (mapsfile, "%[^\n]\n", misc);
      if (ret == 1 && strstr (misc, stack_name))
        {
          fclose (mapsfile);
          return addr;
        }
    }

  fclose (mapsfile);
  return 0;
}

static greg_t
get_pcsp_base (int pid)
{
  return get_stack_base (pid, "[chain stack]");
}

static greg_t
get_psp_base (int pid)
{
  return get_stack_base (pid, "[procedure stack]");
}

static greg_t
get_idr (void)
{
  greg_t idr;

  /* Funnily enough `%idr' is not supported on elbrus-v1, whereas the related
     value of `%idr.mdl' equals to `1' according to 5.14 in `iset.single'.
     However, I just return 0, which should make it clear that this register is
     missing from CPU.  */
  if (__builtin_cpu_is ("elbrus-v1"))
    return 0;

  /* Replace "rrd %%idr, %0"  with its byte code so as to let
     this GDB module be compiled for elbrus-v{X<2}. Taking into
     account that elbrus-v1 is no longer supported by e2k-linux-as
     this could be avoided.  */
  __asm__ ("\n\t.word 0x04100011"	/* HS  */
	   "\n\t.reg %0"		/* ALS0.dst  */
	   "\n\t.byte 0xc0"		/* And the rest of ALS0  */
	   "\n\t.byte 0x8a"		/* with %idr in ALF6.reg#  */
	   "\n\t.byte 0x3f"
	   "\n\t.word 0x01c00000"	/* ALES  */
	   "\n\t.word 0x00000000"	/* LTS0  */
	   : "=r" (idr));
  return idr;
}

static greg_t
get_core_mode (void)
{
  greg_t core_mode;

  /* The value returned for `elbrus-v{1,2}' doesn't play any role since GDB
     shouldn't even add `%core_mode' to the list of supported registers then.
     In corefile debugging mode it should rely on `%idr' to recognize this
     case.  */
  if (__builtin_cpu_is ("elbrus-v1") || __builtin_cpu_is ("elbrus-v2"))
    return 0;

  /* Replace "rrd %%core_mode, %0"  with its byte code so as to let
     this GDB module be compiled for elbrus-v{X<3}.  */
  __asm__ ("\n\t.word 0x04100011"	/* HS  */
	   "\n\t.reg %0"		/* ALS0.dst  */
	   "\n\t.byte 0xc0"		/* And the rest of ALS0  */
	   "\n\t.byte 0x04"		/* with %core_mode in ALF6.reg#  */
	   "\n\t.byte 0x3f"
	   "\n\t.word 0x01c00000"	/* ALES  */
	   "\n\t.word 0x00000000"	/* LTS0  */
	   : "=r" (core_mode));
  return core_mode;
}


/* Eventually both of them should be set to the same value which is 0 if the
   latest "elbrus-v6 specific" regset should be used, 1 if the Kernel provides
   "elbrus-v5 specific" regset (see Bug #81304, Comment #4) and 2 if only the
   ancient "elbrus v1" one is available.  */
static int min_regset = 0;
static int max_regset = 2;

static long
e2k_linux_access_regs (int set, int tid, e2k_linux_gregset_t regs)
{
  int i;
  long res = -1;
  typeof (regs[0]) sizes[3] = {SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT,
			       SIZE_OF_ELBRUS_V5_USER_REGS_STRUCT,
			       SIZE_OF_ELBRUS_V1_USER_REGS_STRUCT};

  /* FIXME: this stupid assert is to be removed.  */
  gdb_assert (sizeof (e2k_linux_gregset_t)
	      == SIZE_OF_ELBRUS_V6_USER_REGS_STRUCT + 8);

  /* We should determine which regset to use during the very first invocation
     of this function which should be PTRACE_GETREGS. The bogus behaviour of
     old E2K kernels (see below) doesn't let us determine this for
     PTRACE_SETREGS.  */
  gdb_assert (min_regset == max_regset || set == 0);

  /* linux-2.6.33 doesn't seem to replicate the bogus behaviour of linux-3.14
     in relation to `ptrace (PTRACE_GETREGS)' with the `user_regs_struct' of
     unsupported size (see Bug #86806, Comment #3 and Bug #81304, Comment #5).
     I don't have any desire to study its behaviour in this case in detail,
     therefore I just make use of the hope that support for the new format of
     `user_regs_struct' will be never backported to linux-2.6.33.  */
  if (min_regset != max_regset)
    {
      struct utsname u;

      /* If the version of the kernel can't be determined, assume that it
	 doesn't support the new format of `user_regs_struct' to be on the safe
	 side.  */
      if (uname (&u)
	  || strncmp (u.release, "2.6.", 4) == 0)
	min_regset = max_regset;
    }

  for (i = min_regset; i <= max_regset; i++)
    {
      regs[0] = sizes[i];

      /* An error due to the lack of support for new regset in the kernel should
	 be treated specially.  */
      res = ptrace (set ? PTRACE_SETREGS : PTRACE_GETREGS, tid, 0,
		    (void *) regs);
      
      /* The new kernel should NEVER modify `user_regs.sizeof_struct' (see Bug
         #81304, Comment #5). However, it DOES so on seeing an unsupported
	 sizeof_struct along with producing the right RES thanks to <sanekf@
	 mcst.ru> who inattentively read that comment. However, unlike the old
	 one it'll never zero out this field because of unavailable pt_regs.  */
      if (regs[0] == 0)
        {
          /* This may happen if we use an old kernel not supporting the new
             `user_regs_struct' either due to its erroneous reaction to
             unfamiliar value of `user_regs.sizeof_struct' (see Bug #81304,
             Comment #5) or unavailable `pt_regs'. Fall back to usage of the
             old `user_regs_struct' then if this hasn't been done already. If
             this has been done and we find ourselves still here, this means
             that the second case takes place.  */

          if (i == 0 || i == 1)
            {
              if (min_regset != max_regset)
                {
                  /* The Kernel does not support this regset, try an older
		     one.  */
                  min_regset = i + 1;

                  /* Reobtain registers using the old `user_regs_struct'. This
                     should be the only case in which this loop performs more
                     than one iteration.  */
                  continue;
                }
              else
                {
                  static int warned;

                  /* This should be a bug in the new kernel, otherwise we
                     wouldn't find ourselves here.  */
                  if (! warned)
                    {
                      warning (_("The kernel has spoiled `user_regs."
                                 "sizeof_struct' field. Please, report "
                                 "this bug"));
                      warned = 1;
                    }
                }
            }
          else
            {
              gdb_assert (min_regset == 2 && min_regset == max_regset);

              /* An old kernel zeroed out `sizeof_struct' field because of
                 unavailable `pt_regs'. Take care of restoring it since it's
                 used by `e2k_supply_gregset ()' later.  */
              regs[0] = SIZE_OF_ELBRUS_V1_USER_REGS_STRUCT;
            }
        }
      else if (max_regset != min_regset)
        {
          /* Make it clear that we use the new kernel.  */
          gdb_assert (i == 0 || i == 1);

          /* Currently on e2s-pc-2 I have a "new" Kernel with the previous (i.e.
             not the latest proposed in Bug #81304, Comments #8 - #11) revision
             of the "new" `user_regs_struct'. Therefore for the latest GDB to
             work with it somehow, it should rely on the legacy `user_regs_
             struct'. This is what the underlying check allows for: it case it
             fails the loop will continue as if an old kernel was used. Should
             it be left here forever to make it possible to fallback to the
             legacy `user_regs_struct' in case of some unexpected changes in
             the Kernel?  */
          if (res == 0)
            /* OK, the latest `user_regs_struct' is workable.  */
            max_regset = min_regset;
          else
            /* No, this `user_regs_struct' is not workable, proceed with an
	       older one..  */
            min_regset = i + 1;
        }
    }

  if (set == 0 && res == 0)
    {
      /* The base of chain stack should be fetched from `/proc/TID/maps' if the
	 kernel doesn't support even elbrus-v5 specific regset.  */
      if (min_regset == 2)
	{
	  regs[gregset_idx (E2K_PCSP_BASE)] = get_pcsp_base (tid);
	  regs[gregset_idx (E2K_PSP_BASE)] = get_psp_base (tid);
	  regs[gregset_idx (E2K_IDR_REGNUM)] = get_idr ();
	  regs[gregset_idx (E2K_CORE_MODE_REGNUM)] = get_core_mode ();
	}

      /* Calculate `%_pcsp_offset'.  */
      regs[gregset_idx (E2K_PCSP_OFFSET)]
	= ((regs[gregset_idx (E2K_PCSP_LO_REGNUM)] & 0xffffffffffffULL)
	   + (regs[gregset_idx (E2K_PCSP_HI_REGNUM)] & 0xffffffff)
	   - regs[gregset_idx (E2K_PCSP_BASE)]);
    }

  return res;
}

long
e2k_linux_getregs (int tid, e2k_linux_gregset_t regs)
{
  return e2k_linux_access_regs (0, tid, regs);
}

long
e2k_linux_setregs (int tid, e2k_linux_gregset_t regs)
{
  return e2k_linux_access_regs (1, tid, regs);
}


int
e2k_linux_read_tags (int pid, gdb_byte *readbuf, ULONGEST offset,
                     ULONGEST len, ULONGEST *xfered_len)
{
  /* Maybe, this should be FIXED later somehow. Use LEN (expressed in
     32-bit words, while OFFSET is expressed in bytes!!!) to determine
     whom these tags are requested by and how they should be accessed.
     Choose the output format accordingly.

     If `LEN == {1,2}' then GDB needs to fill in tag fields either in
     a register or a memory location. There is no point in using
     `/proc/pid/mem_tags' (see Bug #62176, Comment #4) for that. No
     other values of LEN are used when GDB does this job. Tags should
     be provided in a NON-PACKED format in this case.

     If GDB is generating a corefile, then LEN is a multiple of four.
     Tags should be provided in a PACKED format. The only way to do
     this job efficiently is to use `/proc/pid/mem_tags'. In case the
     latter is not available, there is no point in making a user wait
     for a few minutes or more while `ptrace (PTRACE_PEEKTAG)' is
     reading tags for every word of the memory region. Just set them
     to zero instead.  */

  int ret = 0;

  if (len == 1 || len == 2)
    {
      ULONGEST i;
      for (i = 0; i < len; i++)
        {
          /* ptrace () may very well return -1 if an address (offset)
             isn't properly aligned. The value at such address should be
             considered tagless.  */
          int res = ptrace (PTRACE_PEEKTAG, pid, offset + 4 * i, 0);
          readbuf[i] = (res != -1) ? (unsigned char) res : 0;
        }

      *xfered_len = len;
    }
  else
    {
      int fd;
      char filename[64];

      /* When filling in corefiles, we always obtain tags for portions
         of data consisting of properly aligned quadro words (even
         pages, in fact). Each quadro word corresponds to one byte of
         tags if a PACKED output format is used.  */
      gdb_assert (len % 4 == 0);

      sprintf (filename, "/proc/%d/mem_tags", pid);
      fd = open (filename, O_RDONLY | O_LARGEFILE);
      if (fd == -1)
        {
          /* There is no point in making the user wait.  */
          memset (readbuf, 0, len >> 2);
          *xfered_len = len;
        }
      else
        {

          /* If pread64 is available, use it.  It's faster if the kernel
             supports it (only one syscall), and it's 64-bit safe even on
             32-bit platforms (for instance, SPARC debugging a SPARC64
             application).  */
#ifdef HAVE_PREAD64
          if (pread64 (fd, readbuf, len >> 2, offset >> 4) != (len >> 2))
#else
          if (lseek (fd, offset >> 4, SEEK_SET) == -1
              || read (fd, readbuf, len >> 2) != (len >> 2))
#endif
            ret = 1;
          else
            *xfered_len = len;
        }

      close (fd);
    }

  return ret;
}


void
e2k_linux_prepare_to_resume (struct lwp_info *lwp)
{
  e2k_linux_update_debug_registers (lwp);
}


struct e2k_insn_seq
{
  int len;
  const ULONGEST seq[32];
  void (* adjust) (ULONGEST, ULONGEST *);
};



static void
execute_insn_seq (int tid, CORE_ADDR pc,
		  const struct e2k_insn_seq *seq,
                  ULONGEST param,
                  int syscall)
{
  static const ULONGEST bkpt = 0x0dc0c08004000001ULL;
  int i;
  int len = seq->len;
  ULONGEST saved_insns[len + 1];
  e2k_linux_gregset_t regs;
  ULONGEST syllables[len];
  int status;
  // ULONGEST sys_rnum;

  for (i = 0; i < len; i++)
    syllables[i] = seq->seq[i];

  if (seq->adjust != NULL)
    seq->adjust (param, syllables);

  for (i = 0; i < (syscall ? len : len + 1); i++)
    {
      saved_insns[i] = ptrace (PTRACE_PEEKTEXT, tid, pc + 8 * i,  NULL);
      ptrace (PTRACE_POKETEXT, tid, pc + 8 * i, i < len ? syllables[i] : bkpt);
    }

  e2k_linux_getregs (tid, regs);

  /* Adjust `%cr0.hi' so as to resume at ADDR.  */
  regs[gregset_idx (E2K_CR0_HI_REGNUM)] = pc;

  if (! syscall)
    {
      // sys_rnum = regs[gregset_idx (E2K_SYS_NUM_REGNUM)];
      regs[gregset_idx (E2K_SYS_NUM_REGNUM)] = -1ULL;
    }

  e2k_linux_setregs (tid, regs);

  if (ptrace (syscall ? PTRACE_SYSCALL : PTRACE_CONT, tid,
              (PTRACE_TYPE_ARG3) 0, (PTRACE_TYPE_ARG4) 0)
      != 0)
    {
      int my_err = errno;
      my_err++;
    }

  waitpid (tid, &status, 0);

  if (syscall)
    e2k_linux_getregs (tid, regs);

  for (i = 0; i < (syscall ? len : len + 1); i++)
    ptrace (PTRACE_POKETEXT, tid, pc + 8 * i, saved_insns[i]);
}


static void
adjust_call (ULONGEST wbs, ULONGEST *prog)
{
  prog[2] &= ~(0x7fULL);
  prog[2] |= wbs;
}

static const struct e2k_insn_seq call_prog =
  {
    3,

    {
      0x4000000300004201ULL,
      0x8000042000009012ULL,
      0x0000000050000008ULL,
    },

    &adjust_call
  };


void
e2k_linux_call_dummy (int tid, int arch_idx, ULONGEST pc)
{
  ULONGEST wbs;
  e2k_linux_gregset_t regs;

  e2k_linux_getregs (tid, regs);

  /* Obtain WD.size of the CALLer as `(current_wd.psize >> 4) + cr1_lo.wbs'
     and set WBS to it when calling a dummy frame.  */
  wbs = ((((regs[gregset_idx (E2K_WD_REGNUM)] >> 32) & 0x7ff) >> 4)
	 + ((regs[gregset_idx (E2K_CR1_LO_REGNUM)] >> 33) & 0x7f));

  execute_insn_seq (tid, pc, &call_prog, wbs, 0);
}

static void
adjust_dummy_prologue_np (ULONGEST getsp, ULONGEST *prog)
{
  prog[2] &= 0xffffffff00000000ULL;
  prog[2] |= getsp & 0xffffffffULL;
}


static const struct e2k_insn_seq dummy_prologue_np =
  {
    3,

    /* 0000<000000000000> HS       0x04108022,    g:  */
    /*                    ALS0     0x58ecd980,     getsp,0 _f32s,_lts1 0xdeadbeef, %dr0  */
    /*                    CS1      0x040000c1,     setwd wsz = 0x5, nfx = 0x1  */
    /*                                             setbn rsz = 0x3, rbs = 0x1, rcur = 0x0  */
    /*                    ALES     0x01c00000,  */
    /*                    LTS1     0xdeadbeef,  */
    /*                    LTS0     0x000000b0,  */

    {
      0x58ecd98004108022ULL,
      0x01c00000040000c1ULL,
      0x000000b000000000ULL
    },

    &adjust_dummy_prologue_np
  };


static void
adjust_dummy_prologue_pm (ULONGEST getsp, ULONGEST *prog)
{
  prog[2] &= 0xffffffff00000000ULL;
  prog[2] |= getsp & 0xffffffffULL;
}


static const struct e2k_insn_seq dummy_prologue_pm =
  {
    5,

    /* 0000<000000000000> HS       0x0c008023,    g:  */
    /*                    ALS0     0x62ecd980,     getsap,0 _f32s,_lts1 0xdeadbeef, %qr0  */
    /*                    ALS1     0x62ecd981,  */
    /*                    CS1      0x040000c1,     setwd wsz = 0x5, nfx = 0x1  */
    /*                                             setbn rsz = 0x3, rbs = 0x1, rcur = 0x0  */
    /*                    LTS1     0xdeadbeef,  */
    /*                    LTS0     0x000000b0,  */
    /*
    0000<000000000000> HS    0c300012 :
    ALS0  57c08000  movtq,0 %qr0, %qb[0]
                   ALS1  57c08101
                   ALES  01c001c0
    */

    {
      0x62ecd9800c008023ULL,
      0x040000c162ecd981ULL,
      0x000000b0deadbeefULL,
      0x57c080000c300012ULL,
      0x01c001c057c08101ULL
    },

    &adjust_dummy_prologue_pm
  };


void
e2k_linux_execute_dummy_prologue (int tid, int arch_idx, ULONGEST pc,
				  ULONGEST getsp)
{
  static const struct e2k_insn_seq *prologues[] = {
    &dummy_prologue_np,
    &dummy_prologue_np,
    &dummy_prologue_pm
  };

  execute_insn_seq (tid, pc, prologues[arch_idx], getsp, 0);
}


void
e2k_linux_call_target (int tid, int arch_idx, ULONGEST pc)
{
  ULONGEST pcsp;
  e2k_linux_gregset_t regs;

  e2k_linux_getregs (tid, regs);

  pcsp = ((regs[gregset_idx (E2K_PCSP_LO_REGNUM)] & 0xffffffffffffULL)
	  + (regs[gregset_idx (E2K_PCSP_HI_REGNUM)] & 0xffffffff));


  /* Dummy frame has `WD.size_q == 5', thus CALL the target function with
     `wbs = 0x1'.  */
  execute_insn_seq (tid, pc, &call_prog, 0x1, 0);

  /* Ensure that the target function returns to the inferior's entry point
     so as an AT_ENTRY_POINT DUMMY breakpoint could be hit without additional
     hacks.  */
  ptrace (PTRACE_POKETEXT, tid, pcsp + 32 - 32 + 8, pc);
}


static void
adjust_dbl_on_reg (ULONGEST regno, ULONGEST *prog)
{
  prog[0] &= 0xffffff00ffffffffULL;
  prog[0] |= (regno & 0x7f) << 32;
}

static const struct e2k_insn_seq dbl_on_reg = {
  1,

  {
    0x61c0e00304000001ULL
  },

  &adjust_dbl_on_reg
};

static void
adjust_dbl_on_stack_64 (ULONGEST offset, ULONGEST *prog)
{
  prog[1] &= 0x00000000ffffffffULL;
  prog[1] |= (offset & 0xffffffffULL) << 32;
}


static e2k_insn_seq dbl_on_stack_64 = {
  2,

  /* 0000<000000000000> HS       0x10000011,    :  */
  /*                    ALS2     0x2780d8e0,     std,2 %dg0, [ %dr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    LTS1     0x00000000,  */
  /*                    LTS0     0x12345678,  */

  {
    0x2780d8e010000011ULL,
    0x1234567800000000ULL
  },

  &adjust_dbl_on_stack_64
};


static void
adjust_dbl_on_stack_32 (ULONGEST offset, ULONGEST *prog)
{

  prog[1] &= 0x00000000ffffffffULL;
  prog[1] |= (offset & 0xffffffffULL) << 32;
}


static e2k_insn_seq dbl_on_stack_32 = {
  2,

  {
    /* 0000<000000000000> HS       0x10400011,    :  */
    /*                    ALS2     0x2780d8e0,     stgdd,2 %dg0, [ %r0 + _f32s,_lts0 0x12345678 ]  */
    /*                    LTS1     0x00000000,  */
    /*                    LTS0     0x12345678,  */
    0x2780d8e010400011ULL,
    0x1234567800000000ULL
  },

  &adjust_dbl_on_stack_32
};

static void
adjust_dbl_on_stack_pm (ULONGEST offset, ULONGEST *prog)
{

  prog[1] &= 0x00000000ffffffffULL;
  prog[1] |= (offset & 0xffffffffULL) << 32;
}


static const struct e2k_insn_seq dbl_on_stack_pm = {
  2,

  /* 0000<000000000000> HS       0x10400011,    :  */
  /*                    ALS2     0x2b80d8e0,     stapd,2 %dg0, [ %qr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    LTS1     0x00000000,  */
  /*                    LTS0     0x12345678,  */

  {
    0x2b80d8e010400011ULL,
    0x1234567800000000ULL
  },

  &adjust_dbl_on_stack_pm
};





void
e2k_linux_move_dbl_param (int tid, int arch_idx, ULONGEST pc,
			  const gdb_byte *buf, int on_reg)
{
  static const struct e2k_insn_seq *dbl_on_stack[] = {
    &dbl_on_stack_64,
    &dbl_on_stack_32,
    &dbl_on_stack_pm
  };

  ULONGEST saved_g0;
  gdb_byte saved_gtag0;
  ULONGEST offset;
  e2k_linux_gregset_t regs;

  e2k_linux_getregs (tid, regs);

  saved_g0 = regs[gregset_idx (E2K_G0_REGNUM)];
  saved_gtag0 = ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)];

  memcpy (&offset, buf, 8);
  memcpy (&regs[gregset_idx (E2K_G0_REGNUM)], buf + 8, 8);
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)] = buf[16] & 0xf;

  if (e2k_linux_setregs (tid, regs) == -1)
    perror_with_name (_("Couldn't write registers"));
  execute_insn_seq (tid, pc, on_reg ? &dbl_on_reg : dbl_on_stack[arch_idx],
		    offset, 0);

  if (e2k_linux_getregs (tid, regs)  == -1)
    perror_with_name (_("Couldn't get registers"));

  regs[gregset_idx (E2K_G0_REGNUM)] = saved_g0;
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)] = saved_gtag0;

  if (e2k_linux_setregs (tid, regs) == -1)
    perror_with_name (_("Couldn't write registers"));
}


static void
adjust_quad_on_reg (ULONGEST regno, ULONGEST *prog)
{
  prog[0] &= 0xffffff00ffffffffULL;
  prog[0] |= (regno & 0x7f) << 32;

  prog[1] &= 0xffffffffffffff00ULL;
  prog[1] |= (regno + 1) & 0x7f;
}


const struct e2k_insn_seq quad_on_reg = {
  2,

  /* 0000<000000000000> HS       0x0c300012,     */
  /*                    ALS0     0x57c0e006,     movtq,0 %qg0, %qb[6]  */
  /*                    ALS1     0x57c0e107,  */
  /*                    ALES     0x01c001c0,  */

  {
    0x57c0e0060c300012ULL,
    0x01c001c057c0e107ULL
  },

  &adjust_quad_on_reg
};


static void
adjust_quad_on_stack_64 (ULONGEST offset, ULONGEST *prog)
{
  prog[2] = (((offset + 8) & 0xffffffffULL)
             + ((offset & 0xffffffffULL) << 32));
}


static e2k_insn_seq quad_on_stack_64 = {
  3,

  /* There is probably no quadro-store in 64-bit mode, is there? Just use two
     STDs in its place.  */
  /* 0002<0000000000a8> HS       0x90000022,    :  */
  /*                    ALS2     0x2780d8e0,     std,2 %dg0, [ %dr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    ALS5     0x2780d9e1,     std,5 %dg1, [ %dr0 + _f32s,_lts1 0x12345680 ]  */
  /*                    LTS2     0x00000000,  */
  /*                    LTS1     0x12345680,  */
  /*                    LTS0     0x12345678,  */

  {
    0x2780d8e090000022ULL,
    0x000000002780d9e1ULL,
    0x1234567812345680ULL
  },

  &adjust_quad_on_stack_64
};

static e2k_insn_seq quad_on_stack_32 = {
  2,

  /* 0002<0000000000a8> HS       0x92400012,    :  */
  /*                    ALS2     0x3980d8e0,     stgdq,2 %qg0, [ %r0 + _f32s,_lts0 0x12345678 ]  */
  /*                    ALS5     0x3980d8e1,  */
  /*                    LTS0     0x12345678,  */

  {
    0x3980d8e092400012ULL,
    0x123456783980d8e1ULL
  },

  &adjust_dbl_on_stack_32
};

static const struct e2k_insn_seq quad_on_stack_pm = {
  2,

  /* 0000<000000000000> HS       0x92400012,    :  */
  /*                    ALS2     0x3a80d8e0,     stapq,2 %qg0, [ %qr0 + _f32s,_lts0 0x12345678 ]  */
  /*                    ALS5     0x3a80d8e1,  */
  /*                    LTS0     0x12345678,  */

  {
    0x3a80d8e092400012ULL,
    0x123456783a80d8e1ULL
  },

  &adjust_dbl_on_stack_pm
};



void
e2k_linux_move_quad_param (int tid, int arch_idx, ULONGEST pc,
			   const gdb_byte *buf, int on_reg)
{
  static const struct e2k_insn_seq *quad_on_stack[] = {
    &quad_on_stack_64,
    &quad_on_stack_32,
    &quad_on_stack_pm
  };

  ULONGEST saved_g0;
  ULONGEST saved_g1;
  gdb_byte saved_gtag0;
  gdb_byte saved_gtag1;
  ULONGEST offset;
  e2k_linux_gregset_t regs;

  e2k_linux_getregs (tid, regs);

  saved_g0 = regs[gregset_idx (E2K_G0_REGNUM)];
  saved_g1 = regs[gregset_idx (E2K_G1_REGNUM)];
  saved_gtag0 = ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)];
  saved_gtag1 = ((gdb_byte *) regs)[byte_offset (E2K_GTAG1_REGNUM)];

  memcpy (&offset, buf, 8);
  memcpy (&regs[gregset_idx (E2K_G0_REGNUM)], buf + 8, 8);
  memcpy (&regs[gregset_idx (E2K_G1_REGNUM)], buf + 16, 8);
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)] = buf[24] & 0xf;
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG1_REGNUM)] = (buf[24] & 0xf0) >> 4;

  if (e2k_linux_setregs (tid, regs) == -1)
    perror_with_name (_("Couldn't write registers"));
  execute_insn_seq (tid, pc, on_reg ? &quad_on_reg : quad_on_stack[arch_idx],
		    offset, 0);

  if (e2k_linux_getregs (tid, regs) == -1)
    perror_with_name (_("Couldn't get registers"));

  regs[gregset_idx (E2K_G0_REGNUM)] = saved_g0;
  regs[gregset_idx (E2K_G1_REGNUM)] = saved_g1;
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG0_REGNUM)] = saved_gtag0;
  ((gdb_byte *) regs)[byte_offset (E2K_GTAG1_REGNUM)] = saved_gtag1;

  if (e2k_linux_setregs (tid, regs) == -1)
    perror_with_name (_("Couldn't write registers"));
}

static const struct e2k_insn_seq return_prog =
  {
    2,

    {
      0xf000000000004281,
      0x80000c2000001001
    },

    NULL
  };

void
e2k_linux_return_from_dummy (int tid, int arch_idx, ULONGEST pc)
{
  ULONGEST pcsp;
  e2k_linux_gregset_t regs;

  e2k_linux_getregs (tid, regs);

  pcsp = ((regs[gregset_idx (E2K_PCSP_LO_REGNUM)] & 0xffffffffffffULL)
	  + (regs[gregset_idx (E2K_PCSP_HI_REGNUM)] & 0xffffffff));

  /* Ensure that an inferior returns to a "breakpoint" set up by
     `execute_insn_seq ()'.  */
  ptrace (PTRACE_POKETEXT, tid, pcsp - 32 + 8, pc + 0x10);
  execute_insn_seq (tid, pc, &return_prog, 0, 0);
}


static const struct e2k_insn_seq syscall_prog =
  {
    4,

    {
      0x6000000300004001,
      0x11d4c00004000001,
      0x8000042000009012,
      0x0000000050000005
    },

    NULL
  };


void
e2k_linux_enter_syscall (int tid, ULONGEST pc)
{
  execute_insn_seq (tid, pc, &syscall_prog, 0, 1);
}


/* Check for the availability of PTRACE_SINGLESTEP.  */
int
e2k_linux_check_ptrace_singlestep (void)
{
  int has_ptrace_singlestep = 0;
  pid_t pid  = fork ();

  if (pid == 0)
    {
      ptrace (PTRACE_TRACEME, 0, 0, 0);
      __asm__ ("{\n\tldd 0x0, 0x0, %empty\n}"
	       "\n\tnop"
	       "{\n\tldd 0x0, 0x0, %empty\n}"
	       "\n\tnop");
    }
  else
    {
      int status;
      pid_t res;
      res = waitpid (pid, &status, 0);
      /* The tracee must be stopped by SIGSEGV at the next instruction
	 after `ldd 0x0, 0x0, %empty'  by now.  */
      if (res != pid
	  || ! WIFSTOPPED (status)
	  || WSTOPSIG (status) != SIGSEGV)
	abort ();

      /* Our kernel seems to have always "succeeded" with an unworkable
	 PTRACE_SINGLESTEP. What's the point in checking its return code
	 then?  */
      ptrace (PTRACE_SINGLESTEP, pid, NULL, NULL);

      /* One second should be enough for the tracee to singlestep if
	 PTRACE_SINGLESTEP is workable.  */
      sleep (1);
      res = waitpid (pid, &status, WNOHANG);

      /* This time the tracee should be stopped by SIGTRAP.  */
      if (res == pid
	  && WIFSTOPPED (status)
	  && WSTOPSIG (status) == SIGTRAP)
	has_ptrace_singlestep = 1;

      /* There should be another stop due to SIGSEGV now.  */
      ptrace (PTRACE_CONT, pid, 0, 0);
      res = waitpid (pid, &status, 0);
      if (res != pid
	  || ! WIFSTOPPED (status)
	  || WSTOPSIG (status) != SIGSEGV)
	abort ();

      /* Finally the child should be killed by SIGKILL. Original SIGSEGV used
	 to be delivered to it instead until `handle_sigsegv ()' eventually
	 terminating gdb with abort () was implemented.  */
      ptrace (PTRACE_CONT, pid, 0, SIGKILL);
      res = waitpid (pid, &status, 0);
      if (res != pid
	  || ! WIFSIGNALED (status)
	  || WTERMSIG (status) != SIGKILL)
	abort ();
    }

  return has_ptrace_singlestep;
}
