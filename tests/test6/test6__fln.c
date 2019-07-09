int test_has_param_1(int x)
{
  return 0;
}

int test_has_param_2(int x, int y)
{
  return 0;
}

int test_has_param_all(int x, int y)
{
  return 0;
}

int test_has_return()
{
  return 0;
}

int test_assign_read(int x)
{
  x = 1;
  return 0;
}

int test_assign_write(int x)
{
  int y;
  y = x;
  return 0;
}

int test_assign_read_write(int x)
{
  int y;
  y = x;
  return 0;
}

void func(int x)
{
  return 0;
}

int test_id_read(int x)
{
  func(x);
  return 0;
}

void func1(int x)
{
  return 0;
}

int test_id_write(int x)
{
  x = func1(x);
  return 0;
}

void func2(int x)
{
  return 0;
}

int test_provides_read(__fln__tag_int x)
{
  int x__fln_p = __fln__tag_int_read(x);
  func2(x__fln_p);
  return 0;
}

void func3(int x)
{
  return 0;
}

__fln__tag_int test_provides_write(int x)
{
  func3(x);
  return __fln__tag_int_write(0);
}

void test_requires_read()
{
  int x;
  x = 17;
}

void test_requires_write_call(int x)
{
  x;
}

void test_requires_write()
{
  __fln__tag_int x;
  test_requires_write_call(__fln__tag_int_read(x));
}

int main()
{
  return 0;
}

