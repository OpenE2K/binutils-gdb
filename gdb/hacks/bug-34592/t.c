#include <stdio.h>
#include <sys/mman.h>

int
main ()
{
  char *code;
  code = mmap (NULL, 4096, PROT_EXEC | PROT_READ | PROT_WRITE,
	       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  code[0] = 0x1;

  munmap (code, 4096);
  return 0;
}
