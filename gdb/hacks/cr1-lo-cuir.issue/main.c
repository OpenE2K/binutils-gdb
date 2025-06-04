#include <stdio.h>

extern int foo ();
extern int bar ();

void
call_back ()
{
  printf ("In call_back ()\n");
}

int
main (int argc, char **argv)
{
  printf ("&foo == 0x%lx, &bar == 0x%lx\n", (long) &foo, (long) &bar);
  return foo (argc) - 7;
}
