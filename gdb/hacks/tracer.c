#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
set_breakpoint (pid_t pid, unsigned long long bp, unsigned long long pc)
{
  unsigned long long regs[551];

  regs[0] = sizeof (regs);
  if (ptrace (PTRACE_GETREGS, pid, NULL, &regs) != 0)
    perror ("PTRACE_GETREGS");

  /* DIBCR.t0 = DIBCR.v0 = 1  */
  regs[311] = 3;
  /* Set DIBAR0 to point at the start of `trapper'.  */
  regs[313] = bp;

  /* Zero out DIBSR due to an awful peculiarity of our processor.  */
  regs[327] = 0;

  /* Play with start PC (to be more precise `%cr0.hi'.  */
  if (pc != 0)
    regs[51] = pc;

  if (ptrace (PTRACE_SETREGS, pid, NULL, &regs) != 0)
    perror ("PTRACE_SETREGS");
}

unsigned long long
get_pc (pid_t pid)
{
  unsigned long long regs[551];

  regs[0] = sizeof (regs);
  if (ptrace (PTRACE_GETREGS, pid, NULL, &regs) != 0)
    perror ("PTRACE_GETREGS");

  /* Get `%cr0.hi'.  */
  return regs[51];
}

void
my_wait (pid_t pid)
{
  int status;

  waitpid (pid, &status, 0);

  if (WIFSTOPPED (status))
    printf ("Child stopped with signal #%d at 0x%llx\n", WSTOPSIG (status),
            get_pc (pid));
}


void
cont (pid_t pid)
{
  if (ptrace (PTRACE_CONT, pid, NULL, 0) != 0)
    perror ("PTRACE_CONT");

  my_wait (pid);
}


int
main ()
{
  pid_t pid;
  int status;

  pid = fork ();

  if (pid == 0)
    {
      char *const argv[] = {"./trapper", NULL};
      char *const envp[] = {NULL};

      ptrace (PTRACE_TRACEME, 0, NULL, NULL);
      execve (argv[0], argv, envp);
    }
  else if (pid < 0)
    abort ();

  my_wait (pid);

  set_breakpoint (pid, 0x10088, 0x10080);
  cont (pid);

  set_breakpoint (pid, 0x10078, 0x10078);
  cont (pid);

  set_breakpoint (pid, 0x10078, 0x0);
  cont (pid);

  return 0;
}
