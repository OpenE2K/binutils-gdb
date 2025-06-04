#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>

static int
my_wait (pid_t pid, const char *msg)
{
  int status;
  waitpid (pid, &status, 0);
  printf ("%s: status == 0x%x\n", msg, status);

  /* Believe that we may go on tracing if the inferior is currently stopped
     by SIGTRAP. This is a rather primitive criterium.  */
  if ((status >> 8) == 5)
    return 1;

  return 0;
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
  int go_on = 0;
  char cmdline[128];
  pid_t pid = fork ();

  if (pid == 0)
    {
      char *args[2] = {argv[1], NULL};

      ptrace (PTRACE_TRACEME, 0, 0, 0);
      execv (args[0], args);
      return 37;
    }

  /* A child should be stopped in the middle of `execv ()'.  */
  my_wait (pid, "child is in the middle of execv ()");

  sprintf (cmdline, "cat /proc/%d/maps", pid);

  do
    {
      ptrace (PTRACE_SYSCALL, pid, NULL, NULL);
      go_on = my_wait (pid, "child should be stopped");

#if defined __e2k__
	print_ip (pid);
#endif /* __e2k__  */

      system (cmdline);
    }
  while (go_on);

  return 0;
}
