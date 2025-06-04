#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>

static void
my_wait (pid_t pid, const char *msg)
{
  int status;
  waitpid (pid, &status, 0);
  printf ("%s: status == 0x%x\n", msg, status);
}

#if defined __e2k__
static void
print_ip (pid_t pid)
{
  /* Use the old-style `user_regs_struct' here to be on the safe side.  */
  unsigned long regs[551];
  regs[0] = sizeof (regs);

  ptrace (PTRACE_GETREGS, pid, 0, regs);
  /* Print out the contents of `%cr0.hi'.  */
  printf ("IP == 0x%lx\n", regs[0x198 / 8]);
}
#endif /* __e2k__  */

int
main (int argc, char **argv)
{
  unsigned long addr;
  pid_t pid = fork ();

  if (pid == 0)
    {
      int i;
      char *args[3] = {argv[1], argv[2], NULL};

      for (i = 0; i < 3; i++)
	{
	  printf ("Before PTRACE_TRACEME\n");
	  sleep (1);
	}
      

      ptrace (PTRACE_TRACEME, 0, 0, 0);

      for (i = 0; i < 3; i++)
	{
	  printf ("After PTRACE_TRACEME\n");
	  sleep (1);
	}

      execv (args[0], args);
      return 37;
    }

  /* A child should have been stopped in the middle of `execv ()'.  */
  my_wait (pid, "child is in the middle of execv ()");

  /* Insert software breakpoint at the address specified as the third
     argument.  */
  addr = strtoul (argv[3], NULL, 0);

  if (addr != 0)
    {
      unsigned long orig;

      orig = ptrace (PTRACE_PEEKTEXT, pid, addr, 0);
      ptrace (PTRACE_POKETEXT, pid, addr, 0x0dc0c08004000001);

      ptrace (PTRACE_CONT, pid, NULL, NULL);
      my_wait (pid, "child should be stopped at breakpoint");

#if defined __e2k__
      print_ip (pid);
#endif /* __e2k__  */

      /* Remove the breakpoint by restoring the original instruction.  */
      ptrace (PTRACE_POKETEXT, pid, addr, orig);
    }

  ptrace (PTRACE_CONT, pid, NULL, NULL);
  my_wait (pid, "child should be done");

#if defined __e2k__
      print_ip (pid);
#endif /* __e2k__  */


  return 0;
}
