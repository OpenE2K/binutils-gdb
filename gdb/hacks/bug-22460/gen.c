#include <stdio.h>

int
main ()
{
  int i;

  for (i = 0; i < 128; i++)
    printf ("adds 0x0, 0x%x, %%b[%d]\n", i + 1, i);

  printf ("\n\nadds 0x0, 0x0, %%r0\n\n\n");

  for (i = 0; i < 128; i++)
    printf ("adds %%r0, %%b[%d], %%r0\n", i);

  return 0;
}
