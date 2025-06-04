#include <stdio.h>
#include <complex.h>

__float128 alpha = 1.234567;
long double beta = 1.234567;

__float128
foo (__float128 arg)
{
  return arg * arg;
}

__CFLOAT128 z;

int
main ()
{
  _Float128 r1;
  __float128 r2 = 0.53;

  __real__ z = 5.0;
  __imag__ z = 3.5;
  
  r1 = 1.1234;

  r1 *= r2;

  r1 = foo (r1);
  return 0;
}
