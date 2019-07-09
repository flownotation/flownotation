typedef struct {int d; } __fln__trusted_int;
__fln__trusted_int __fln__trusted_int_write(int x) {__fln__trusted_int y; y.d = x; return y; }
int __fln__trusted_int_read(__fln__trusted_int x) { return x.d; }

int trusted_read(__fln__trusted_int x)
{
  return __fln__trusted_int_read(x);
}

__fln__trusted_int trusted_write(int x)
{
  return __fln__trusted_int_write(x);
}

int random_func(int x)
{
  return x;
}

int main()
{
  __fln__trusted_int x;
  __fln__trusted_int y;
  int z;
  x = trusted_write(1);
  z = trusted_read(x);
  z = trusted_read(y);
  y = trusted_write(1);
  x = trusted_write(trusted_read(y));
  y = trusted_write(trusted_read(x));
  random_func(trusted_read(x));
}

