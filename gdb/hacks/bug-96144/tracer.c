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
  ptrace (PTRACE_CONT, pid, NULL, NULL);
  my_wait (pid, "child should be done");

#if defined __e2k__
  print_ip (pid);
#endif /* __e2k__  */

  sprintf (cmdline, "cat /proc/%d/maps", pid);
  system (cmdline);
  return 0;
}
