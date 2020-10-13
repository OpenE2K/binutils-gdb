void foo(void);

#ifdef __LCC__
int main (void)  __attribute__ ((section (".text.main")));
void foo1 (void) __attribute__ ((section (".text.foo1")));
void foo2 (void) __attribute__ ((section (".text.foo2")));
void foo3 (void) __attribute__ ((section (".text.foo3")));
#endif /* __LCC__  */

int main(void)
{
   foo ();

   for (;;)
	;
}

int a;

void foo1(void)
{
	a = 1;
}

void foo2(void)
{
	a = 2;
}

void foo3(void)
{
	a = 3;
}


