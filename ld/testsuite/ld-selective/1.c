/* _start should be the only thing left after GC.  */

void _start() __asm__("_start");

#ifdef __LCC__
void _start()  __attribute__ ((section (".text._start")));
void dropme1()  __attribute__ ((section (".text.dropme1")));
extern int dropme2[] __attribute__ ((section (".data.dropme2")));
#endif /* __LCC__  */

void _start()
{
}

void dropme1()
{
}

int dropme2[102] = { 0 };
