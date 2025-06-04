#include <stdio.h>

extern int foo ();

int
main ()
{
  int res = foo ();

  if (res == 128 * 129 / 2)
    {
      printf ("Obtained correct `res == %d'\n", res);
      return 0;
    }
  
  printf ("Obtained incorrect `res == %d'\n", res);
  return 1;
}
