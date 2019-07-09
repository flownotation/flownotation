typedef struct foo
{
  int data;
  float num;
} foo;
typedef struct 
{
  int d;
} __fln__test1S_int;
typedef struct 
{
  foo d;
} __fln__test1S_foo;
__fln__test1S_int __fln__test1S_int_intg(int x)
{
  __fln__test1S_int y;
  y.d = x;
  return y;
}

__fln__test1S_int *__fln__test1S_int_intg_ptr(int *x)
{
  __fln__test1S_int *y;
  y->d = *x;
  return y;
}

int __fln__test1S_int_sec(__fln__test1S_int x)
{
  return x.d;
}

int *__fln__test1S_int_sec_ptr(__fln__test1S_int *x)
{
  return &x->d;
}

__fln__test1S_foo __fln__test1S_foo_intg(foo x)
{
  __fln__test1S_foo y;
  y.d = x;
  return y;
}

__fln__test1S_foo *__fln__test1S_foo_intg_ptr(foo *x)
{
  __fln__test1S_foo *y;
  y->d = *x;
  return y;
}

foo __fln__test1S_foo_sec(__fln__test1S_foo x)
{
  return x.d;
}

foo *__fln__test1S_foo_sec_ptr(__fln__test1S_foo *x)
{
  return &x->d;
}

int testf_1s(__fln__test1S_int a, __fln__test1S_foo b)
{
  foo b__fln_p = __fln__test1S_foo_sec(b);
  int a__fln_p = __fln__test1S_int_sec(a);
  return 0;
}

int main()
{
  return 0;
}

