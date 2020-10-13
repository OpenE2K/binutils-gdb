extern void foo_in_so(void);
extern void unresolved_detected_at_runtime_not_at_linktime (void);

#ifdef __LCC__
void call_unresolved(void) __attribute__ ((section (".text.call_unresolved")));
int main(int argc, char *argv[]) __attribute__ ((section (".text.main")));
#endif /* __ LCC__  */

void call_unresolved(void)
{
   unresolved_detected_at_runtime_not_at_linktime();
}

int main(int argc, char *argv[])
{
   foo_in_so();

   return 0;
}
