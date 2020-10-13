int unused_var
#ifdef __LCC__
__attribute__ ((section (".data.unused_var")))
#endif /* __LCC__  */
  = 7;

int used_var
#ifdef __LCC__
__attribute__ ((section (".data.used_var")))
#endif /* __LCC__  */
  = 7;

#ifdef __LCC__
int unused_func (int v) __attribute__ ((section (".text.unused_func")));

int __attribute__((noinline)) used_func (int v)
  __attribute__ ((section (".text.used_func")));

int main (void) __attribute__ ((section (".text.main")));
#endif /* __LCC__  */

int
unused_func (int v)
{
  return 3 * unused_var;
}

int
__attribute__((noinline))
used_func (int v)
{
  return 2 * used_var;
}

int
main (void)
{
  return used_func (5);
}

#ifndef __LCC__
/* These tricks are not required for LCC because it doesn't prepend an
   underscore to the start of function names. Moreover, it's not likely to
   process such a construct in an adequate way. For example, I am unable
   to find `.ifndef' directives in the resulting .s-file. As a result one
   obtains multiple definitions of `used_func" and `main'. Even if `.ifndef'
   directives were passed to the output .s-file, this could be not enough,
   because our compiler prepends symbol names with a dollar (`$') and I'm
   not sure whether they would have worked appropriately.  */
void
dummy_func (void)
{
  /* These are here in case the target prepends an underscore to
     the start of function names.  They are inside a dummy function
     so that they will appear at the end of gcc's assembler output,
     after the definitions of main() and used_func(), rather than
     at the beginning of the file.  */

  __asm__(".ifndef main\n\
.global main\n\
.set main, _main\n\
.endif");

  __asm__(".ifndef used_func\n\
.global used_func\n\
.set used_func, _used_func\n\
.endif");
}
#endif /* __LCC__  */
