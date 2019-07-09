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

void func(__fln__BobS_int x)
{
  int x__fln_p = __fln__BobS_int_sec(x);
  return 0;
}

int main()
{
  __fln__AliceS_int bal;
  func(bal);
  return 0;
}

