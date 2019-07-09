typedef struct foo
{
  int data;
  float num;
} foo;
__fln__authentic_int f(int x)
{
  return __fln__authentic_int_intg(0);
}

float h()
{
  return 0.0;
}

void g(int x)
{
  return 0;
}

int main()
{
  __fln__authentic_foo x = {.data = 1, .d = {.num = 2.7}};
  x.data = f(1);
  x.d.data = __fln__authentic_int_sec(x.data);
  x.d.num = h();
  g(__fln__authentic_foo_sec(x).num);
  return 0;
}

