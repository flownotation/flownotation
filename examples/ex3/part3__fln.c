int test1()
{
  return 0;
}

int test2(int a)
{
  return a;
}

int main()
{
  int x;
  test1();
  __fln__trusted_int y;
  test2(y);
}

