typedef struct 
{
  int d;
} __fln__AliceS_int;
typedef struct 
{
  int d;
} __fln__BobS_int;
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

__fln__BobS_int __fln__BobS_int_intg(int x)
{
  __fln__BobS_int y = {.d = x};
  return y;
}

__fln__BobS_int *__fln__BobS_int_intg_ptr(int *x)
{
  __fln__BobS_int tmp = {.d = *x};
  __fln__BobS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__BobS_int_sec(__fln__BobS_int x)
{
  return x.d;
}

int *__fln__BobS_int_sec_ptr(__fln__BobS_int *x)
{
  return &x->d;
}

int f(int *a)
{
  return 0;
}

int g(int a)
{
  return 0;
}

int h(void *a)
{
  return 0;
}

int i(__fln__AliceS_int *a)
{
  int* a__fln_p = __fln__AliceS_int_sec_ptr(a);
  return 0;
}

int main()
{
  __fln__AliceS_int x0;
  int *y0 = &x0;
  __fln__AliceS_int *y1;
  y1 = &x0;
  int *y2 = (int *) (&x0);
  f(&x0);
  f(y1);
  f(y2);
  __fln__BobS_int *x1;
  int y3 = *x1;
  __fln__BobS_int y4;
  y4 = *x1;
  int y5 = *((int *) x1);
  g(*x1);
  g(y4);
  g(y5);
  h(x0);
  void *y6;
  i(y6);
  return 0;
}

