#include <stdio.h>

#define name(a) __name (a)
#define __name(a) #a

extern void call_back ();

int
foo (int arg)
{
  printf ("Within " name (foo)" (%d) before call_back ()\n", arg);
  call_back ();
  printf ("Within " name (foo)" (%d) after call_back ()\n", arg);
  return arg * 7;
}
