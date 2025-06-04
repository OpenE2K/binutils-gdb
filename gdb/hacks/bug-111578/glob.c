__float128 var = 1.1234Q;

int
main ()
{
  __float128 loc;
  loc = var;
  loc *= loc;

  return var >= 2 ? 1 : 0;
}
