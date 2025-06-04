#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>

#if defined __i386__

__asm__ ("\n\tdummy:"
	 "\n\tjmp dummy");

#elif defined __e2k__
__asm__ ("\n\tdummy:"
         "\n\t disp %ctpr1, dummy"
         "\n\t ct %ctpr1");

#else
# error "Unsupported architecture"
#endif

extern void dummy ();

int
main (int argc, char **argv)
{
  int status;
#if defined __i386__
  struct user_regs_struct regs;
#else
  greg_t regs[591];
#endif
  pid_t pid = fork ();

  if (pid == 0)
    {
      if (argc == 1)
	{
	  for (; ;)
	    ;
	}
      else
	sleep (600);

      return 37;
    }

  printf ("PID == %d\n", pid);

  sleep (5);
  ptrace (PTRACE_ATTACH, pid, NULL, NULL);
  waitpid (pid, NULL, 0);

#if defined __e2k__
  regs[0] = sizeof (regs);
#endif

  ptrace (PTRACE_GETREGS, pid, NULL, &regs);

#if defined __i386__
  printf ("eip == 0x%lx\n", regs.eip);
  regs.eip = (long ) &dummy;
#else
  printf ("%%cr0_hi == 0x%lx, %%_sys_rval == 0x%lx, %%_sys_rnum == 0x%lx\n",
          regs[0x198 / 8], regs[0xad8 / 8], regs[0xae0 / 8]);
  /* Set `%cr0.hi'.  */
  regs[0x198 / 8] = (long) &dummy;
  /* Reset `%_sys_rval'.  */
  regs[0xad8 / 8] = 0;
  /* Reset `%_sys_rnum'.  */
  regs[0xae0 / 8] = -1ULL;
#endif
  
  ptrace (PTRACE_SETREGS, pid, NULL, &regs);
#if defined __e2k__
  /* See if resetting `%_sys_rval' has succeeded. I doubt that this has really
     happened . . .  */
  ptrace (PTRACE_GETREGS, pid, NULL, &regs);
  printf ("%%cr0_hi == 0x%lx, %%_sys_rval == 0x%lx, %%_sys_rnum == 0x%lx\n",
          regs[0x198 / 8], regs[0xad8 / 8], regs[0xae0 / 8]);
#endif
  ptrace (PTRACE_CONT, pid, NULL, NULL);

  waitpid (pid, &status, 0);
  printf ("status == 0x%x\n", status);

  return 0;
}
