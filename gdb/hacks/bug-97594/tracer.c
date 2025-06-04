#include <sys/ptrace.h>
#include <sys/types.h>
#if defined __i386__
#include <sys/user.h>
#endif /* __i386__  */
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void
my_wait (pid_t pid, const char *msg)
{
  int status;
  waitpid (pid, &status, 0);
  printf ("%s: status == 0x%x\n", msg, status);
}

static void
print_ip (pid_t pid)
{
#if defined __e2k__
  /* Use the old-style `user_regs_struct' here to be on the safe side.  */
  unsigned long regs[551];
  regs[0] = sizeof (regs);

  ptrace (PTRACE_GETREGS, pid, 0, regs);
  /* Print out the contents of `%cr0.hi'.  */
  printf ("IP == 0x%lx\n", regs[0x198 / 8]);
#elif defined __i386__ /* __e2k__  */
  struct user_regs_struct regs;
  ptrace (PTRACE_GETREGS, pid, 0, &regs);
  printf ("eip == 0x%lx\n", regs.eip);
#endif /* __i386__  */
}

int val;

int
main (int argc, char **argv)
{
  pid_t pid = fork ();

  if (pid == 0)
    {
      ptrace (PTRACE_TRACEME, 0, 0, 0);
      if (argc >= 3)
	{
	  char *const args[] = {"./tracee.64", NULL};
	  execv (args[0], args);
	}
      else
	{
	  /* Either of these events should make `waitpid ()' in the parent
	     return.  */
	  if (argc == 1)
	    raise (SIGCONT);
#if defined __e2k__
	  else /* if (argc == 2)  */
	    __asm__ (
		     /* After this load the very first waitpid () in the parent
			should return with `WSTOPSIG (status) == SIGSEGV'.  */
		     "{\n\tldd 0x0, 0x0, %empty\n}"
		     /* The next waitpid () after the first PTRACE_SINGLESTEP
			should return `WSTOPSIG (status) == SIGTRAP' after
			executing this nop.  */
		     "\n\tnop"
		     /* waitpid () after the second PTRACE_SINGLESTEP should
			once again return `WSTOPSIG (status) == SIGSEGV'.  */
		     "{\n\tldd 0x0, 0x0, %empty\n}"
		     "\n\tnop");
#endif /* __e2k__  */

	  while (1)
	    val++;
	}
    }

  my_wait (pid, "child should just have raised a signal after PTRACE_TRACEME");
  print_ip (pid);

  while (1)
    {
      long res;
      res = ptrace (PTRACE_SINGLESTEP, pid, NULL, NULL);
      printf ("ptrace () returned %d\n", res);
      my_wait (pid, "child should have performed a single step");
      print_ip (pid);
    }
}
