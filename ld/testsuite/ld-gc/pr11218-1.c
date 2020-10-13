extern void unresolved_detected_at_runtime_not_at_linktime(void);

#ifdef __LCC__
void foo_in_so(void) __attribute__ ((section (".text.foo_in_so")));
#endif /* __ LCC__  */

void foo_in_so(void)
{
   unresolved_detected_at_runtime_not_at_linktime();
}
