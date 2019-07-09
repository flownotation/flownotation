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

int main()
{
  __fln__AliceS_int h;
  int l;
  if (h == 2)
  {
    l = 1;
  }
  else
  {
    l = 0;
  }

  __fln__AliceS_int h2;
  if (h == h2)
  {
    l = 1;
  }
  else
  {
    l = 0;
  }

  if (h)
  {
    l = 1;
  }
  else
  {
    l = 0;
  }

  if (!h)
  {
    l = 1;
  }
  else
  {
    l = 0;
  }

  return 0;
}

