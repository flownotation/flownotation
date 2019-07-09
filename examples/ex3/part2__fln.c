int test1(int a)
{
  return a;
}

int test2(__fln__trusted_int a)
{
  int a__fln_p = __fln__trusted_int_read(a);
  return a__fln_p;
}

