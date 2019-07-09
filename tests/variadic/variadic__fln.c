typedef struct 
{
  int d;
} __fln__AliceS_int;
__fln__AliceS_int __fln__AliceS_int_intg(int x)
{
  __fln__AliceS_int y = {.d = x};
  return y;
}

__fln__AliceS_int *__fln__AliceS_int_intg_ptr(int *x)
{
  __fln__AliceS_int tmp = {.d = *x};
  __fln__AliceS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__AliceS_int_sec(__fln__AliceS_int x)
{
  return x.d;
}

int *__fln__AliceS_int_sec_ptr(__fln__AliceS_int *x)
{
  return &x->d;
}

int f(__fln__AliceS_int a, int b, ...)
{
  int a__fln_p = __fln__AliceS_int_sec(a);
  return 0;
}

int main()
{
  __fln__AliceS_int x;
  int y;
  f(x, y);
  return 0;
}

