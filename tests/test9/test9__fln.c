struct foo
{
  int x;
};
struct foo1
{
  int x;
};
struct foo2
{
  struct foo1;
};
typedef struct 
{
  const int d;
} __fln__test1I_const_int;
typedef struct 
{
  const struct foo1 d;
} __fln__test1S_const_struct_foo1;
typedef struct 
{
  struct foo1 d;
} __fln__test1I_struct_foo1;
typedef struct 
{
  const struct foo1 d;
} __fln__test2S_const_struct_foo1;
typedef struct 
{
  const struct foo1 d;
} __fln__test1S_test2S_const_struct_foo1;
typedef struct 
{
  int d;
} __fln__test1I_int;
typedef struct 
{
  const struct foo d;
} __fln__test1I_const_struct_foo;
typedef struct 
{
  int d;
} __fln__test3S_int;
typedef struct 
{
  int d;
} __fln__test2S_int;
typedef struct 
{
  int d;
} __fln__test2S_test3S_int;
typedef struct 
{
  int d;
} __fln__test1S_int;
typedef struct 
{
  int d;
} __fln__test1S_test2S_test3S_int;
typedef struct 
{
  int d;
} __fln__test4I_int;
typedef struct 
{
  int d;
} __fln__test3I_int;
typedef struct 
{
  int d;
} __fln__test3I_test4I_int;
typedef struct 
{
  int d;
} __fln__test2I_int;
typedef struct 
{
  int d;
} __fln__test2I_test3I_test4I_int;
typedef struct 
{
  int d;
} __fln__test1I_test2I_test3I_test4I_int;
typedef struct 
{
  int d;
} __fln__test1I_test2I_int;
typedef struct 
{
  int d;
} __fln__test4S_int;
typedef struct 
{
  int d;
} __fln__test3S_test4S_int;
typedef struct 
{
  int d;
} __fln__test2S_test3S_test4S_int;
typedef struct 
{
  int d;
} __fln__test1S_test2S_test3S_test4S_int;
typedef struct 
{
  int d;
} __fln__test2I_test3I_int;
typedef struct 
{
  int d;
} __fln__test1I_test2I_test3I_int;
typedef struct 
{
  struct foo1 d;
} __fln__test2I_struct_foo1;
typedef struct 
{
  struct foo1 d;
} __fln__test1I_test2I_struct_foo1;
typedef struct 
{
  const int d;
} __fln__test2S_const_int;
typedef struct 
{
  const int d;
} __fln__test1S_const_int;
typedef struct 
{
  const int d;
} __fln__test1S_test2S_const_int;
typedef struct 
{
  struct foo d;
} __fln__test1I_struct_foo;
__fln__test1I_const_int __fln__test1I_const_int_intg(const int x)
{
  __fln__test1I_const_int y = {.d = x};
  return y;
}

__fln__test1I_const_int *__fln__test1I_const_int_intg_ptr(const int *x)
{
  __fln__test1I_const_int tmp = {.d = *x};
  __fln__test1I_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const int __fln__test1I_const_int_sec(__fln__test1I_const_int x)
{
  return x.d;
}

const int *__fln__test1I_const_int_sec_ptr(__fln__test1I_const_int *x)
{
  return &x->d;
}

__fln__test1S_const_struct_foo1 __fln__test1S_const_struct_foo1_intg(const struct foo1 x)
{
  __fln__test1S_const_struct_foo1 y = {.d = x};
  return y;
}

__fln__test1S_const_struct_foo1 *__fln__test1S_const_struct_foo1_intg_ptr(const struct foo1 *x)
{
  __fln__test1S_const_struct_foo1 tmp = {.d = *x};
  __fln__test1S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct foo1 __fln__test1S_const_struct_foo1_sec(__fln__test1S_const_struct_foo1 x)
{
  return x.d;
}

const struct foo1 *__fln__test1S_const_struct_foo1_sec_ptr(__fln__test1S_const_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1I_struct_foo1 __fln__test1I_struct_foo1_intg(struct foo1 x)
{
  __fln__test1I_struct_foo1 y = {.d = x};
  return y;
}

__fln__test1I_struct_foo1 *__fln__test1I_struct_foo1_intg_ptr(struct foo1 *x)
{
  __fln__test1I_struct_foo1 tmp = {.d = *x};
  __fln__test1I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

struct foo1 __fln__test1I_struct_foo1_sec(__fln__test1I_struct_foo1 x)
{
  return x.d;
}

struct foo1 *__fln__test1I_struct_foo1_sec_ptr(__fln__test1I_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_tail_w(__fln__test2S_const_struct_foo1 x)
{
  __fln__test1S_test2S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_tail_w_ptr(__fln__test2S_const_struct_foo1 *x)
{
  __fln__test1S_test2S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test1S_test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_tail_r(__fln__test1S_test2S_const_struct_foo1 x)
{
  __fln__test2S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_tail_r_ptr(__fln__test1S_test2S_const_struct_foo1 *x)
{
  __fln__test2S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_fst_w(__fln__test1S_const_struct_foo1 x)
{
  __fln__test1S_test2S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_fst_w_ptr(__fln__test1S_const_struct_foo1 *x)
{
  __fln__test1S_test2S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test1S_test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_fst_r(__fln__test1S_test2S_const_struct_foo1 x)
{
  __fln__test1S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_fst_r_ptr(__fln__test1S_test2S_const_struct_foo1 *x)
{
  __fln__test1S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test1S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_snd_w(__fln__test2S_const_struct_foo1 x)
{
  __fln__test1S_test2S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_snd_w_ptr(__fln__test2S_const_struct_foo1 *x)
{
  __fln__test1S_test2S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test1S_test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_snd_r(__fln__test1S_test2S_const_struct_foo1 x)
{
  __fln__test2S_const_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_snd_r_ptr(__fln__test1S_test2S_const_struct_foo1 *x)
{
  __fln__test2S_const_struct_foo1 tmp = {.d = x->d};
  __fln__test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_struct_foo1 __fln__test2S_const_struct_foo1_intg(const struct foo1 x)
{
  __fln__test2S_const_struct_foo1 y = {.d = x};
  return y;
}

__fln__test2S_const_struct_foo1 *__fln__test2S_const_struct_foo1_intg_ptr(const struct foo1 *x)
{
  __fln__test2S_const_struct_foo1 tmp = {.d = *x};
  __fln__test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct foo1 __fln__test2S_const_struct_foo1_sec(__fln__test2S_const_struct_foo1 x)
{
  return x.d;
}

const struct foo1 *__fln__test2S_const_struct_foo1_sec_ptr(__fln__test2S_const_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_intg(const struct foo1 x)
{
  __fln__test1S_test2S_const_struct_foo1 y = {.d = x};
  return y;
}

__fln__test1S_test2S_const_struct_foo1 *__fln__test1S_test2S_const_struct_foo1_intg_ptr(const struct foo1 *x)
{
  __fln__test1S_test2S_const_struct_foo1 tmp = {.d = *x};
  __fln__test1S_test2S_const_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct foo1 __fln__test1S_test2S_const_struct_foo1_sec(__fln__test1S_test2S_const_struct_foo1 x)
{
  return x.d;
}

const struct foo1 *__fln__test1S_test2S_const_struct_foo1_sec_ptr(__fln__test1S_test2S_const_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1I_int __fln__test1I_int_intg(int x)
{
  __fln__test1I_int y = {.d = x};
  return y;
}

__fln__test1I_int *__fln__test1I_int_intg_ptr(int *x)
{
  __fln__test1I_int tmp = {.d = *x};
  __fln__test1I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1I_int_sec(__fln__test1I_int x)
{
  return x.d;
}

int *__fln__test1I_int_sec_ptr(__fln__test1I_int *x)
{
  return &x->d;
}

__fln__test1I_const_struct_foo __fln__test1I_const_struct_foo_intg(const struct foo x)
{
  __fln__test1I_const_struct_foo y = {.d = x};
  return y;
}

__fln__test1I_const_struct_foo *__fln__test1I_const_struct_foo_intg_ptr(const struct foo *x)
{
  __fln__test1I_const_struct_foo tmp = {.d = *x};
  __fln__test1I_const_struct_foo *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct foo __fln__test1I_const_struct_foo_sec(__fln__test1I_const_struct_foo x)
{
  return x.d;
}

const struct foo *__fln__test1I_const_struct_foo_sec_ptr(__fln__test1I_const_struct_foo *x)
{
  return &x->d;
}

__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_tail_w(__fln__test2S_test3S_int x)
{
  __fln__test1S_test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_int *__fln__test1S_test2S_test3S_int_tail_w_ptr(__fln__test2S_test3S_int *x)
{
  __fln__test1S_test2S_test3S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_int __fln__test1S_test2S_test3S_int_tail_r(__fln__test1S_test2S_test3S_int x)
{
  __fln__test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_int *__fln__test1S_test2S_test3S_int_tail_r_ptr(__fln__test1S_test2S_test3S_int *x)
{
  __fln__test2S_test3S_int tmp = {.d = x->d};
  __fln__test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_fst_w(__fln__test1S_int x)
{
  __fln__test1S_test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_int *__fln__test1S_test2S_test3S_int_fst_w_ptr(__fln__test1S_int *x)
{
  __fln__test1S_test2S_test3S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_int __fln__test1S_test2S_test3S_int_fst_r(__fln__test1S_test2S_test3S_int x)
{
  __fln__test1S_int y = {.d = x.d};
  return y;
}

__fln__test1S_int *__fln__test1S_test2S_test3S_int_fst_r_ptr(__fln__test1S_test2S_test3S_int *x)
{
  __fln__test1S_int tmp = {.d = x->d};
  __fln__test1S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_snd_w(__fln__test2S_int x)
{
  __fln__test1S_test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_int *__fln__test1S_test2S_test3S_int_snd_w_ptr(__fln__test2S_int *x)
{
  __fln__test1S_test2S_test3S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_int __fln__test1S_test2S_test3S_int_snd_r(__fln__test1S_test2S_test3S_int x)
{
  __fln__test2S_int y = {.d = x.d};
  return y;
}

__fln__test2S_int *__fln__test1S_test2S_test3S_int_snd_r_ptr(__fln__test1S_test2S_test3S_int *x)
{
  __fln__test2S_int tmp = {.d = x->d};
  __fln__test2S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_int __fln__test3S_int_intg(int x)
{
  __fln__test3S_int y = {.d = x};
  return y;
}

__fln__test3S_int *__fln__test3S_int_intg_ptr(int *x)
{
  __fln__test3S_int tmp = {.d = *x};
  __fln__test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test3S_int_sec(__fln__test3S_int x)
{
  return x.d;
}

int *__fln__test3S_int_sec_ptr(__fln__test3S_int *x)
{
  return &x->d;
}

__fln__test2S_int __fln__test2S_int_intg(int x)
{
  __fln__test2S_int y = {.d = x};
  return y;
}

__fln__test2S_int *__fln__test2S_int_intg_ptr(int *x)
{
  __fln__test2S_int tmp = {.d = *x};
  __fln__test2S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2S_int_sec(__fln__test2S_int x)
{
  return x.d;
}

int *__fln__test2S_int_sec_ptr(__fln__test2S_int *x)
{
  return &x->d;
}

__fln__test2S_test3S_int __fln__test2S_test3S_int_intg(int x)
{
  __fln__test2S_test3S_int y = {.d = x};
  return y;
}

__fln__test2S_test3S_int *__fln__test2S_test3S_int_intg_ptr(int *x)
{
  __fln__test2S_test3S_int tmp = {.d = *x};
  __fln__test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2S_test3S_int_sec(__fln__test2S_test3S_int x)
{
  return x.d;
}

int *__fln__test2S_test3S_int_sec_ptr(__fln__test2S_test3S_int *x)
{
  return &x->d;
}

__fln__test1S_int __fln__test1S_int_intg(int x)
{
  __fln__test1S_int y = {.d = x};
  return y;
}

__fln__test1S_int *__fln__test1S_int_intg_ptr(int *x)
{
  __fln__test1S_int tmp = {.d = *x};
  __fln__test1S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
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

__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_intg(int x)
{
  __fln__test1S_test2S_test3S_int y = {.d = x};
  return y;
}

__fln__test1S_test2S_test3S_int *__fln__test1S_test2S_test3S_int_intg_ptr(int *x)
{
  __fln__test1S_test2S_test3S_int tmp = {.d = *x};
  __fln__test1S_test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1S_test2S_test3S_int_sec(__fln__test1S_test2S_test3S_int x)
{
  return x.d;
}

int *__fln__test1S_test2S_test3S_int_sec_ptr(__fln__test1S_test2S_test3S_int *x)
{
  return &x->d;
}

__fln__test2S_test3S_int __fln__test2S_test3S_int_tail_w(__fln__test3S_int x)
{
  __fln__test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_int *__fln__test2S_test3S_int_tail_w_ptr(__fln__test3S_int *x)
{
  __fln__test2S_test3S_int tmp = {.d = x->d};
  __fln__test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_int __fln__test2S_test3S_int_tail_r(__fln__test2S_test3S_int x)
{
  __fln__test3S_int y = {.d = x.d};
  return y;
}

__fln__test3S_int *__fln__test2S_test3S_int_tail_r_ptr(__fln__test2S_test3S_int *x)
{
  __fln__test3S_int tmp = {.d = x->d};
  __fln__test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_int __fln__test2S_test3S_int_fst_w(__fln__test2S_int x)
{
  __fln__test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_int *__fln__test2S_test3S_int_fst_w_ptr(__fln__test2S_int *x)
{
  __fln__test2S_test3S_int tmp = {.d = x->d};
  __fln__test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_int __fln__test2S_test3S_int_fst_r(__fln__test2S_test3S_int x)
{
  __fln__test2S_int y = {.d = x.d};
  return y;
}

__fln__test2S_int *__fln__test2S_test3S_int_fst_r_ptr(__fln__test2S_test3S_int *x)
{
  __fln__test2S_int tmp = {.d = x->d};
  __fln__test2S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_int __fln__test2S_test3S_int_snd_w(__fln__test3S_int x)
{
  __fln__test2S_test3S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_int *__fln__test2S_test3S_int_snd_w_ptr(__fln__test3S_int *x)
{
  __fln__test2S_test3S_int tmp = {.d = x->d};
  __fln__test2S_test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_int __fln__test2S_test3S_int_snd_r(__fln__test2S_test3S_int x)
{
  __fln__test3S_int y = {.d = x.d};
  return y;
}

__fln__test3S_int *__fln__test2S_test3S_int_snd_r_ptr(__fln__test2S_test3S_int *x)
{
  __fln__test3S_int tmp = {.d = x->d};
  __fln__test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_tail_w(__fln__test2I_test3I_test4I_int x)
{
  __fln__test1I_test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_test4I_int *__fln__test1I_test2I_test3I_test4I_int_tail_w_ptr(__fln__test2I_test3I_test4I_int *x)
{
  __fln__test1I_test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_tail_r(__fln__test1I_test2I_test3I_test4I_int x)
{
  __fln__test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_test4I_int *__fln__test1I_test2I_test3I_test4I_int_tail_r_ptr(__fln__test1I_test2I_test3I_test4I_int *x)
{
  __fln__test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_fst_w(__fln__test1I_int x)
{
  __fln__test1I_test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_test4I_int *__fln__test1I_test2I_test3I_test4I_int_fst_w_ptr(__fln__test1I_int *x)
{
  __fln__test1I_test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_int __fln__test1I_test2I_test3I_test4I_int_fst_r(__fln__test1I_test2I_test3I_test4I_int x)
{
  __fln__test1I_int y = {.d = x.d};
  return y;
}

__fln__test1I_int *__fln__test1I_test2I_test3I_test4I_int_fst_r_ptr(__fln__test1I_test2I_test3I_test4I_int *x)
{
  __fln__test1I_int tmp = {.d = x->d};
  __fln__test1I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_snd_w(__fln__test2I_int x)
{
  __fln__test1I_test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_test4I_int *__fln__test1I_test2I_test3I_test4I_int_snd_w_ptr(__fln__test2I_int *x)
{
  __fln__test1I_test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test1I_test2I_test3I_test4I_int_snd_r(__fln__test1I_test2I_test3I_test4I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test1I_test2I_test3I_test4I_int_snd_r_ptr(__fln__test1I_test2I_test3I_test4I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4I_int __fln__test4I_int_intg(int x)
{
  __fln__test4I_int y = {.d = x};
  return y;
}

__fln__test4I_int *__fln__test4I_int_intg_ptr(int *x)
{
  __fln__test4I_int tmp = {.d = *x};
  __fln__test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test4I_int_sec(__fln__test4I_int x)
{
  return x.d;
}

int *__fln__test4I_int_sec_ptr(__fln__test4I_int *x)
{
  return &x->d;
}

__fln__test3I_int __fln__test3I_int_intg(int x)
{
  __fln__test3I_int y = {.d = x};
  return y;
}

__fln__test3I_int *__fln__test3I_int_intg_ptr(int *x)
{
  __fln__test3I_int tmp = {.d = *x};
  __fln__test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test3I_int_sec(__fln__test3I_int x)
{
  return x.d;
}

int *__fln__test3I_int_sec_ptr(__fln__test3I_int *x)
{
  return &x->d;
}

__fln__test3I_test4I_int __fln__test3I_test4I_int_intg(int x)
{
  __fln__test3I_test4I_int y = {.d = x};
  return y;
}

__fln__test3I_test4I_int *__fln__test3I_test4I_int_intg_ptr(int *x)
{
  __fln__test3I_test4I_int tmp = {.d = *x};
  __fln__test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test3I_test4I_int_sec(__fln__test3I_test4I_int x)
{
  return x.d;
}

int *__fln__test3I_test4I_int_sec_ptr(__fln__test3I_test4I_int *x)
{
  return &x->d;
}

__fln__test2I_int __fln__test2I_int_intg(int x)
{
  __fln__test2I_int y = {.d = x};
  return y;
}

__fln__test2I_int *__fln__test2I_int_intg_ptr(int *x)
{
  __fln__test2I_int tmp = {.d = *x};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2I_int_sec(__fln__test2I_int x)
{
  return x.d;
}

int *__fln__test2I_int_sec_ptr(__fln__test2I_int *x)
{
  return &x->d;
}

__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_intg(int x)
{
  __fln__test2I_test3I_test4I_int y = {.d = x};
  return y;
}

__fln__test2I_test3I_test4I_int *__fln__test2I_test3I_test4I_int_intg_ptr(int *x)
{
  __fln__test2I_test3I_test4I_int tmp = {.d = *x};
  __fln__test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2I_test3I_test4I_int_sec(__fln__test2I_test3I_test4I_int x)
{
  return x.d;
}

int *__fln__test2I_test3I_test4I_int_sec_ptr(__fln__test2I_test3I_test4I_int *x)
{
  return &x->d;
}

__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_intg(int x)
{
  __fln__test1I_test2I_test3I_test4I_int y = {.d = x};
  return y;
}

__fln__test1I_test2I_test3I_test4I_int *__fln__test1I_test2I_test3I_test4I_int_intg_ptr(int *x)
{
  __fln__test1I_test2I_test3I_test4I_int tmp = {.d = *x};
  __fln__test1I_test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1I_test2I_test3I_test4I_int_sec(__fln__test1I_test2I_test3I_test4I_int x)
{
  return x.d;
}

int *__fln__test1I_test2I_test3I_test4I_int_sec_ptr(__fln__test1I_test2I_test3I_test4I_int *x)
{
  return &x->d;
}

__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_tail_w(__fln__test3I_test4I_int x)
{
  __fln__test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_test4I_int *__fln__test2I_test3I_test4I_int_tail_w_ptr(__fln__test3I_test4I_int *x)
{
  __fln__test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_test4I_int __fln__test2I_test3I_test4I_int_tail_r(__fln__test2I_test3I_test4I_int x)
{
  __fln__test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test3I_test4I_int *__fln__test2I_test3I_test4I_int_tail_r_ptr(__fln__test2I_test3I_test4I_int *x)
{
  __fln__test3I_test4I_int tmp = {.d = x->d};
  __fln__test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_fst_w(__fln__test2I_int x)
{
  __fln__test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_test4I_int *__fln__test2I_test3I_test4I_int_fst_w_ptr(__fln__test2I_int *x)
{
  __fln__test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test2I_test3I_test4I_int_fst_r(__fln__test2I_test3I_test4I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test2I_test3I_test4I_int_fst_r_ptr(__fln__test2I_test3I_test4I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_snd_w(__fln__test3I_int x)
{
  __fln__test2I_test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_test4I_int *__fln__test2I_test3I_test4I_int_snd_w_ptr(__fln__test3I_int *x)
{
  __fln__test2I_test3I_test4I_int tmp = {.d = x->d};
  __fln__test2I_test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_int __fln__test2I_test3I_test4I_int_snd_r(__fln__test2I_test3I_test4I_int x)
{
  __fln__test3I_int y = {.d = x.d};
  return y;
}

__fln__test3I_int *__fln__test2I_test3I_test4I_int_snd_r_ptr(__fln__test2I_test3I_test4I_int *x)
{
  __fln__test3I_int tmp = {.d = x->d};
  __fln__test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_test4I_int __fln__test3I_test4I_int_tail_w(__fln__test4I_int x)
{
  __fln__test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test3I_test4I_int *__fln__test3I_test4I_int_tail_w_ptr(__fln__test4I_int *x)
{
  __fln__test3I_test4I_int tmp = {.d = x->d};
  __fln__test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4I_int __fln__test3I_test4I_int_tail_r(__fln__test3I_test4I_int x)
{
  __fln__test4I_int y = {.d = x.d};
  return y;
}

__fln__test4I_int *__fln__test3I_test4I_int_tail_r_ptr(__fln__test3I_test4I_int *x)
{
  __fln__test4I_int tmp = {.d = x->d};
  __fln__test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_test4I_int __fln__test3I_test4I_int_fst_w(__fln__test3I_int x)
{
  __fln__test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test3I_test4I_int *__fln__test3I_test4I_int_fst_w_ptr(__fln__test3I_int *x)
{
  __fln__test3I_test4I_int tmp = {.d = x->d};
  __fln__test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_int __fln__test3I_test4I_int_fst_r(__fln__test3I_test4I_int x)
{
  __fln__test3I_int y = {.d = x.d};
  return y;
}

__fln__test3I_int *__fln__test3I_test4I_int_fst_r_ptr(__fln__test3I_test4I_int *x)
{
  __fln__test3I_int tmp = {.d = x->d};
  __fln__test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_test4I_int __fln__test3I_test4I_int_snd_w(__fln__test4I_int x)
{
  __fln__test3I_test4I_int y = {.d = x.d};
  return y;
}

__fln__test3I_test4I_int *__fln__test3I_test4I_int_snd_w_ptr(__fln__test4I_int *x)
{
  __fln__test3I_test4I_int tmp = {.d = x->d};
  __fln__test3I_test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4I_int __fln__test3I_test4I_int_snd_r(__fln__test3I_test4I_int x)
{
  __fln__test4I_int y = {.d = x.d};
  return y;
}

__fln__test4I_int *__fln__test3I_test4I_int_snd_r_ptr(__fln__test3I_test4I_int *x)
{
  __fln__test4I_int tmp = {.d = x->d};
  __fln__test4I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_int __fln__test1I_test2I_int_tail_w(__fln__test2I_int x)
{
  __fln__test1I_test2I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_int *__fln__test1I_test2I_int_tail_w_ptr(__fln__test2I_int *x)
{
  __fln__test1I_test2I_int tmp = {.d = x->d};
  __fln__test1I_test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test1I_test2I_int_tail_r(__fln__test1I_test2I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test1I_test2I_int_tail_r_ptr(__fln__test1I_test2I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_int __fln__test1I_test2I_int_fst_w(__fln__test1I_int x)
{
  __fln__test1I_test2I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_int *__fln__test1I_test2I_int_fst_w_ptr(__fln__test1I_int *x)
{
  __fln__test1I_test2I_int tmp = {.d = x->d};
  __fln__test1I_test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_int __fln__test1I_test2I_int_fst_r(__fln__test1I_test2I_int x)
{
  __fln__test1I_int y = {.d = x.d};
  return y;
}

__fln__test1I_int *__fln__test1I_test2I_int_fst_r_ptr(__fln__test1I_test2I_int *x)
{
  __fln__test1I_int tmp = {.d = x->d};
  __fln__test1I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_int __fln__test1I_test2I_int_snd_w(__fln__test2I_int x)
{
  __fln__test1I_test2I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_int *__fln__test1I_test2I_int_snd_w_ptr(__fln__test2I_int *x)
{
  __fln__test1I_test2I_int tmp = {.d = x->d};
  __fln__test1I_test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test1I_test2I_int_snd_r(__fln__test1I_test2I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test1I_test2I_int_snd_r_ptr(__fln__test1I_test2I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_int __fln__test1I_test2I_int_intg(int x)
{
  __fln__test1I_test2I_int y = {.d = x};
  return y;
}

__fln__test1I_test2I_int *__fln__test1I_test2I_int_intg_ptr(int *x)
{
  __fln__test1I_test2I_int tmp = {.d = *x};
  __fln__test1I_test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1I_test2I_int_sec(__fln__test1I_test2I_int x)
{
  return x.d;
}

int *__fln__test1I_test2I_int_sec_ptr(__fln__test1I_test2I_int *x)
{
  return &x->d;
}

__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_tail_w(__fln__test2S_test3S_test4S_int x)
{
  __fln__test1S_test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_test4S_int *__fln__test1S_test2S_test3S_test4S_int_tail_w_ptr(__fln__test2S_test3S_test4S_int *x)
{
  __fln__test1S_test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_tail_r(__fln__test1S_test2S_test3S_test4S_int x)
{
  __fln__test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_test4S_int *__fln__test1S_test2S_test3S_test4S_int_tail_r_ptr(__fln__test1S_test2S_test3S_test4S_int *x)
{
  __fln__test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_fst_w(__fln__test1S_int x)
{
  __fln__test1S_test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_test4S_int *__fln__test1S_test2S_test3S_test4S_int_fst_w_ptr(__fln__test1S_int *x)
{
  __fln__test1S_test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_int __fln__test1S_test2S_test3S_test4S_int_fst_r(__fln__test1S_test2S_test3S_test4S_int x)
{
  __fln__test1S_int y = {.d = x.d};
  return y;
}

__fln__test1S_int *__fln__test1S_test2S_test3S_test4S_int_fst_r_ptr(__fln__test1S_test2S_test3S_test4S_int *x)
{
  __fln__test1S_int tmp = {.d = x->d};
  __fln__test1S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_snd_w(__fln__test2S_int x)
{
  __fln__test1S_test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_test3S_test4S_int *__fln__test1S_test2S_test3S_test4S_int_snd_w_ptr(__fln__test2S_int *x)
{
  __fln__test1S_test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test1S_test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_int __fln__test1S_test2S_test3S_test4S_int_snd_r(__fln__test1S_test2S_test3S_test4S_int x)
{
  __fln__test2S_int y = {.d = x.d};
  return y;
}

__fln__test2S_int *__fln__test1S_test2S_test3S_test4S_int_snd_r_ptr(__fln__test1S_test2S_test3S_test4S_int *x)
{
  __fln__test2S_int tmp = {.d = x->d};
  __fln__test2S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4S_int __fln__test4S_int_intg(int x)
{
  __fln__test4S_int y = {.d = x};
  return y;
}

__fln__test4S_int *__fln__test4S_int_intg_ptr(int *x)
{
  __fln__test4S_int tmp = {.d = *x};
  __fln__test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test4S_int_sec(__fln__test4S_int x)
{
  return x.d;
}

int *__fln__test4S_int_sec_ptr(__fln__test4S_int *x)
{
  return &x->d;
}

__fln__test3S_test4S_int __fln__test3S_test4S_int_intg(int x)
{
  __fln__test3S_test4S_int y = {.d = x};
  return y;
}

__fln__test3S_test4S_int *__fln__test3S_test4S_int_intg_ptr(int *x)
{
  __fln__test3S_test4S_int tmp = {.d = *x};
  __fln__test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test3S_test4S_int_sec(__fln__test3S_test4S_int x)
{
  return x.d;
}

int *__fln__test3S_test4S_int_sec_ptr(__fln__test3S_test4S_int *x)
{
  return &x->d;
}

__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_intg(int x)
{
  __fln__test2S_test3S_test4S_int y = {.d = x};
  return y;
}

__fln__test2S_test3S_test4S_int *__fln__test2S_test3S_test4S_int_intg_ptr(int *x)
{
  __fln__test2S_test3S_test4S_int tmp = {.d = *x};
  __fln__test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2S_test3S_test4S_int_sec(__fln__test2S_test3S_test4S_int x)
{
  return x.d;
}

int *__fln__test2S_test3S_test4S_int_sec_ptr(__fln__test2S_test3S_test4S_int *x)
{
  return &x->d;
}

__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_intg(int x)
{
  __fln__test1S_test2S_test3S_test4S_int y = {.d = x};
  return y;
}

__fln__test1S_test2S_test3S_test4S_int *__fln__test1S_test2S_test3S_test4S_int_intg_ptr(int *x)
{
  __fln__test1S_test2S_test3S_test4S_int tmp = {.d = *x};
  __fln__test1S_test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1S_test2S_test3S_test4S_int_sec(__fln__test1S_test2S_test3S_test4S_int x)
{
  return x.d;
}

int *__fln__test1S_test2S_test3S_test4S_int_sec_ptr(__fln__test1S_test2S_test3S_test4S_int *x)
{
  return &x->d;
}

__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_tail_w(__fln__test3S_test4S_int x)
{
  __fln__test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_test4S_int *__fln__test2S_test3S_test4S_int_tail_w_ptr(__fln__test3S_test4S_int *x)
{
  __fln__test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_test4S_int __fln__test2S_test3S_test4S_int_tail_r(__fln__test2S_test3S_test4S_int x)
{
  __fln__test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test3S_test4S_int *__fln__test2S_test3S_test4S_int_tail_r_ptr(__fln__test2S_test3S_test4S_int *x)
{
  __fln__test3S_test4S_int tmp = {.d = x->d};
  __fln__test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_fst_w(__fln__test2S_int x)
{
  __fln__test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_test4S_int *__fln__test2S_test3S_test4S_int_fst_w_ptr(__fln__test2S_int *x)
{
  __fln__test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_int __fln__test2S_test3S_test4S_int_fst_r(__fln__test2S_test3S_test4S_int x)
{
  __fln__test2S_int y = {.d = x.d};
  return y;
}

__fln__test2S_int *__fln__test2S_test3S_test4S_int_fst_r_ptr(__fln__test2S_test3S_test4S_int *x)
{
  __fln__test2S_int tmp = {.d = x->d};
  __fln__test2S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_snd_w(__fln__test3S_int x)
{
  __fln__test2S_test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test2S_test3S_test4S_int *__fln__test2S_test3S_test4S_int_snd_w_ptr(__fln__test3S_int *x)
{
  __fln__test2S_test3S_test4S_int tmp = {.d = x->d};
  __fln__test2S_test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_int __fln__test2S_test3S_test4S_int_snd_r(__fln__test2S_test3S_test4S_int x)
{
  __fln__test3S_int y = {.d = x.d};
  return y;
}

__fln__test3S_int *__fln__test2S_test3S_test4S_int_snd_r_ptr(__fln__test2S_test3S_test4S_int *x)
{
  __fln__test3S_int tmp = {.d = x->d};
  __fln__test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_test4S_int __fln__test3S_test4S_int_tail_w(__fln__test4S_int x)
{
  __fln__test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test3S_test4S_int *__fln__test3S_test4S_int_tail_w_ptr(__fln__test4S_int *x)
{
  __fln__test3S_test4S_int tmp = {.d = x->d};
  __fln__test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4S_int __fln__test3S_test4S_int_tail_r(__fln__test3S_test4S_int x)
{
  __fln__test4S_int y = {.d = x.d};
  return y;
}

__fln__test4S_int *__fln__test3S_test4S_int_tail_r_ptr(__fln__test3S_test4S_int *x)
{
  __fln__test4S_int tmp = {.d = x->d};
  __fln__test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_test4S_int __fln__test3S_test4S_int_fst_w(__fln__test3S_int x)
{
  __fln__test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test3S_test4S_int *__fln__test3S_test4S_int_fst_w_ptr(__fln__test3S_int *x)
{
  __fln__test3S_test4S_int tmp = {.d = x->d};
  __fln__test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_int __fln__test3S_test4S_int_fst_r(__fln__test3S_test4S_int x)
{
  __fln__test3S_int y = {.d = x.d};
  return y;
}

__fln__test3S_int *__fln__test3S_test4S_int_fst_r_ptr(__fln__test3S_test4S_int *x)
{
  __fln__test3S_int tmp = {.d = x->d};
  __fln__test3S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3S_test4S_int __fln__test3S_test4S_int_snd_w(__fln__test4S_int x)
{
  __fln__test3S_test4S_int y = {.d = x.d};
  return y;
}

__fln__test3S_test4S_int *__fln__test3S_test4S_int_snd_w_ptr(__fln__test4S_int *x)
{
  __fln__test3S_test4S_int tmp = {.d = x->d};
  __fln__test3S_test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test4S_int __fln__test3S_test4S_int_snd_r(__fln__test3S_test4S_int x)
{
  __fln__test4S_int y = {.d = x.d};
  return y;
}

__fln__test4S_int *__fln__test3S_test4S_int_snd_r_ptr(__fln__test3S_test4S_int *x)
{
  __fln__test4S_int tmp = {.d = x->d};
  __fln__test4S_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_tail_w(__fln__test2I_test3I_int x)
{
  __fln__test1I_test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_int *__fln__test1I_test2I_test3I_int_tail_w_ptr(__fln__test2I_test3I_int *x)
{
  __fln__test1I_test2I_test3I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_int __fln__test1I_test2I_test3I_int_tail_r(__fln__test1I_test2I_test3I_int x)
{
  __fln__test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_int *__fln__test1I_test2I_test3I_int_tail_r_ptr(__fln__test1I_test2I_test3I_int *x)
{
  __fln__test2I_test3I_int tmp = {.d = x->d};
  __fln__test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_fst_w(__fln__test1I_int x)
{
  __fln__test1I_test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_int *__fln__test1I_test2I_test3I_int_fst_w_ptr(__fln__test1I_int *x)
{
  __fln__test1I_test2I_test3I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_int __fln__test1I_test2I_test3I_int_fst_r(__fln__test1I_test2I_test3I_int x)
{
  __fln__test1I_int y = {.d = x.d};
  return y;
}

__fln__test1I_int *__fln__test1I_test2I_test3I_int_fst_r_ptr(__fln__test1I_test2I_test3I_int *x)
{
  __fln__test1I_int tmp = {.d = x->d};
  __fln__test1I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_snd_w(__fln__test2I_int x)
{
  __fln__test1I_test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_test3I_int *__fln__test1I_test2I_test3I_int_snd_w_ptr(__fln__test2I_int *x)
{
  __fln__test1I_test2I_test3I_int tmp = {.d = x->d};
  __fln__test1I_test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test1I_test2I_test3I_int_snd_r(__fln__test1I_test2I_test3I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test1I_test2I_test3I_int_snd_r_ptr(__fln__test1I_test2I_test3I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_int __fln__test2I_test3I_int_intg(int x)
{
  __fln__test2I_test3I_int y = {.d = x};
  return y;
}

__fln__test2I_test3I_int *__fln__test2I_test3I_int_intg_ptr(int *x)
{
  __fln__test2I_test3I_int tmp = {.d = *x};
  __fln__test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test2I_test3I_int_sec(__fln__test2I_test3I_int x)
{
  return x.d;
}

int *__fln__test2I_test3I_int_sec_ptr(__fln__test2I_test3I_int *x)
{
  return &x->d;
}

__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_intg(int x)
{
  __fln__test1I_test2I_test3I_int y = {.d = x};
  return y;
}

__fln__test1I_test2I_test3I_int *__fln__test1I_test2I_test3I_int_intg_ptr(int *x)
{
  __fln__test1I_test2I_test3I_int tmp = {.d = *x};
  __fln__test1I_test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__test1I_test2I_test3I_int_sec(__fln__test1I_test2I_test3I_int x)
{
  return x.d;
}

int *__fln__test1I_test2I_test3I_int_sec_ptr(__fln__test1I_test2I_test3I_int *x)
{
  return &x->d;
}

__fln__test2I_test3I_int __fln__test2I_test3I_int_tail_w(__fln__test3I_int x)
{
  __fln__test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_int *__fln__test2I_test3I_int_tail_w_ptr(__fln__test3I_int *x)
{
  __fln__test2I_test3I_int tmp = {.d = x->d};
  __fln__test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_int __fln__test2I_test3I_int_tail_r(__fln__test2I_test3I_int x)
{
  __fln__test3I_int y = {.d = x.d};
  return y;
}

__fln__test3I_int *__fln__test2I_test3I_int_tail_r_ptr(__fln__test2I_test3I_int *x)
{
  __fln__test3I_int tmp = {.d = x->d};
  __fln__test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_int __fln__test2I_test3I_int_fst_w(__fln__test2I_int x)
{
  __fln__test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_int *__fln__test2I_test3I_int_fst_w_ptr(__fln__test2I_int *x)
{
  __fln__test2I_test3I_int tmp = {.d = x->d};
  __fln__test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_int __fln__test2I_test3I_int_fst_r(__fln__test2I_test3I_int x)
{
  __fln__test2I_int y = {.d = x.d};
  return y;
}

__fln__test2I_int *__fln__test2I_test3I_int_fst_r_ptr(__fln__test2I_test3I_int *x)
{
  __fln__test2I_int tmp = {.d = x->d};
  __fln__test2I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_test3I_int __fln__test2I_test3I_int_snd_w(__fln__test3I_int x)
{
  __fln__test2I_test3I_int y = {.d = x.d};
  return y;
}

__fln__test2I_test3I_int *__fln__test2I_test3I_int_snd_w_ptr(__fln__test3I_int *x)
{
  __fln__test2I_test3I_int tmp = {.d = x->d};
  __fln__test2I_test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test3I_int __fln__test2I_test3I_int_snd_r(__fln__test2I_test3I_int x)
{
  __fln__test3I_int y = {.d = x.d};
  return y;
}

__fln__test3I_int *__fln__test2I_test3I_int_snd_r_ptr(__fln__test2I_test3I_int *x)
{
  __fln__test3I_int tmp = {.d = x->d};
  __fln__test3I_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_tail_w(__fln__test2I_struct_foo1 x)
{
  __fln__test1I_test2I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_tail_w_ptr(__fln__test2I_struct_foo1 *x)
{
  __fln__test1I_test2I_struct_foo1 tmp = {.d = x->d};
  __fln__test1I_test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_tail_r(__fln__test1I_test2I_struct_foo1 x)
{
  __fln__test2I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_tail_r_ptr(__fln__test1I_test2I_struct_foo1 *x)
{
  __fln__test2I_struct_foo1 tmp = {.d = x->d};
  __fln__test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_fst_w(__fln__test1I_struct_foo1 x)
{
  __fln__test1I_test2I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_fst_w_ptr(__fln__test1I_struct_foo1 *x)
{
  __fln__test1I_test2I_struct_foo1 tmp = {.d = x->d};
  __fln__test1I_test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_struct_foo1 __fln__test1I_test2I_struct_foo1_fst_r(__fln__test1I_test2I_struct_foo1 x)
{
  __fln__test1I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1I_struct_foo1 *__fln__test1I_test2I_struct_foo1_fst_r_ptr(__fln__test1I_test2I_struct_foo1 *x)
{
  __fln__test1I_struct_foo1 tmp = {.d = x->d};
  __fln__test1I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_snd_w(__fln__test2I_struct_foo1 x)
{
  __fln__test1I_test2I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test1I_test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_snd_w_ptr(__fln__test2I_struct_foo1 *x)
{
  __fln__test1I_test2I_struct_foo1 tmp = {.d = x->d};
  __fln__test1I_test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_snd_r(__fln__test1I_test2I_struct_foo1 x)
{
  __fln__test2I_struct_foo1 y = {.d = x.d};
  return y;
}

__fln__test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_snd_r_ptr(__fln__test1I_test2I_struct_foo1 *x)
{
  __fln__test2I_struct_foo1 tmp = {.d = x->d};
  __fln__test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2I_struct_foo1 __fln__test2I_struct_foo1_intg(struct foo1 x)
{
  __fln__test2I_struct_foo1 y = {.d = x};
  return y;
}

__fln__test2I_struct_foo1 *__fln__test2I_struct_foo1_intg_ptr(struct foo1 *x)
{
  __fln__test2I_struct_foo1 tmp = {.d = *x};
  __fln__test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

struct foo1 __fln__test2I_struct_foo1_sec(__fln__test2I_struct_foo1 x)
{
  return x.d;
}

struct foo1 *__fln__test2I_struct_foo1_sec_ptr(__fln__test2I_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_intg(struct foo1 x)
{
  __fln__test1I_test2I_struct_foo1 y = {.d = x};
  return y;
}

__fln__test1I_test2I_struct_foo1 *__fln__test1I_test2I_struct_foo1_intg_ptr(struct foo1 *x)
{
  __fln__test1I_test2I_struct_foo1 tmp = {.d = *x};
  __fln__test1I_test2I_struct_foo1 *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

struct foo1 __fln__test1I_test2I_struct_foo1_sec(__fln__test1I_test2I_struct_foo1 x)
{
  return x.d;
}

struct foo1 *__fln__test1I_test2I_struct_foo1_sec_ptr(__fln__test1I_test2I_struct_foo1 *x)
{
  return &x->d;
}

__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_tail_w(__fln__test2S_const_int x)
{
  __fln__test1S_test2S_const_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_int *__fln__test1S_test2S_const_int_tail_w_ptr(__fln__test2S_const_int *x)
{
  __fln__test1S_test2S_const_int tmp = {.d = x->d};
  __fln__test1S_test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_int __fln__test1S_test2S_const_int_tail_r(__fln__test1S_test2S_const_int x)
{
  __fln__test2S_const_int y = {.d = x.d};
  return y;
}

__fln__test2S_const_int *__fln__test1S_test2S_const_int_tail_r_ptr(__fln__test1S_test2S_const_int *x)
{
  __fln__test2S_const_int tmp = {.d = x->d};
  __fln__test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_fst_w(__fln__test1S_const_int x)
{
  __fln__test1S_test2S_const_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_int *__fln__test1S_test2S_const_int_fst_w_ptr(__fln__test1S_const_int *x)
{
  __fln__test1S_test2S_const_int tmp = {.d = x->d};
  __fln__test1S_test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_const_int __fln__test1S_test2S_const_int_fst_r(__fln__test1S_test2S_const_int x)
{
  __fln__test1S_const_int y = {.d = x.d};
  return y;
}

__fln__test1S_const_int *__fln__test1S_test2S_const_int_fst_r_ptr(__fln__test1S_test2S_const_int *x)
{
  __fln__test1S_const_int tmp = {.d = x->d};
  __fln__test1S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_snd_w(__fln__test2S_const_int x)
{
  __fln__test1S_test2S_const_int y = {.d = x.d};
  return y;
}

__fln__test1S_test2S_const_int *__fln__test1S_test2S_const_int_snd_w_ptr(__fln__test2S_const_int *x)
{
  __fln__test1S_test2S_const_int tmp = {.d = x->d};
  __fln__test1S_test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_int __fln__test1S_test2S_const_int_snd_r(__fln__test1S_test2S_const_int x)
{
  __fln__test2S_const_int y = {.d = x.d};
  return y;
}

__fln__test2S_const_int *__fln__test1S_test2S_const_int_snd_r_ptr(__fln__test1S_test2S_const_int *x)
{
  __fln__test2S_const_int tmp = {.d = x->d};
  __fln__test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__test2S_const_int __fln__test2S_const_int_intg(const int x)
{
  __fln__test2S_const_int y = {.d = x};
  return y;
}

__fln__test2S_const_int *__fln__test2S_const_int_intg_ptr(const int *x)
{
  __fln__test2S_const_int tmp = {.d = *x};
  __fln__test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const int __fln__test2S_const_int_sec(__fln__test2S_const_int x)
{
  return x.d;
}

const int *__fln__test2S_const_int_sec_ptr(__fln__test2S_const_int *x)
{
  return &x->d;
}

__fln__test1S_const_int __fln__test1S_const_int_intg(const int x)
{
  __fln__test1S_const_int y = {.d = x};
  return y;
}

__fln__test1S_const_int *__fln__test1S_const_int_intg_ptr(const int *x)
{
  __fln__test1S_const_int tmp = {.d = *x};
  __fln__test1S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const int __fln__test1S_const_int_sec(__fln__test1S_const_int x)
{
  return x.d;
}

const int *__fln__test1S_const_int_sec_ptr(__fln__test1S_const_int *x)
{
  return &x->d;
}

__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_intg(const int x)
{
  __fln__test1S_test2S_const_int y = {.d = x};
  return y;
}

__fln__test1S_test2S_const_int *__fln__test1S_test2S_const_int_intg_ptr(const int *x)
{
  __fln__test1S_test2S_const_int tmp = {.d = *x};
  __fln__test1S_test2S_const_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const int __fln__test1S_test2S_const_int_sec(__fln__test1S_test2S_const_int x)
{
  return x.d;
}

const int *__fln__test1S_test2S_const_int_sec_ptr(__fln__test1S_test2S_const_int *x)
{
  return &x->d;
}

__fln__test1I_struct_foo __fln__test1I_struct_foo_intg(struct foo x)
{
  __fln__test1I_struct_foo y = {.d = x};
  return y;
}

__fln__test1I_struct_foo *__fln__test1I_struct_foo_intg_ptr(struct foo *x)
{
  __fln__test1I_struct_foo tmp = {.d = *x};
  __fln__test1I_struct_foo *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

struct foo __fln__test1I_struct_foo_sec(__fln__test1I_struct_foo x)
{
  return x.d;
}

struct foo *__fln__test1I_struct_foo_sec_ptr(__fln__test1I_struct_foo *x)
{
  return &x->d;
}

char f(int a)
{
  return (char) a;
}

int test()
{
  __fln__test1S_int a;
  {
    {
      f(a);
      a = __fln__test1S_int_intg(f(1));
    }
  }
}

int test_p()
{
  __fln__test1S_int *a;
  {
    {
      f(a);
      a = __fln__test1S_int_intg_ptr(f(1));
    }
  }
}

int test1()
{
  __fln__test1I_int a;
  {
    {
      f(__fln__test1I_int_sec(a));
      a = f(1);
    }
  }
}

int test1_p()
{
  __fln__test1I_int *a;
  {
    {
      f(__fln__test1I_int_sec_ptr(a));
      a = f(1);
    }
  }
}

int testf_1s(__fln__test1S_int a, __fln__test1S_int b)
{
  int b__fln_p = __fln__test1S_int_sec(b);
  int a__fln_p = __fln__test1S_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_2s(__fln__test1S_int a, int b)
{
  int a__fln_p = __fln__test1S_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_3s(int a, __fln__test1S_int b)
{
  int b__fln_p = __fln__test1S_int_sec(b);
  f(a);
  a = 1;
  return a;
}

int testf_3sp(__fln__test1S_int a, __fln__test2S_int b)
{
  int b__fln_p = __fln__test2S_int_sec(b);
  int a__fln_p = __fln__test1S_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_1i(__fln__test1I_int a, __fln__test1I_int b)
{
  int b__fln_p = __fln__test1I_int_sec(b);
  int a__fln_p = __fln__test1I_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_2i(__fln__test1I_int a, int b)
{
  int a__fln_p = __fln__test1I_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_3i(int a, __fln__test1I_int b)
{
  int b__fln_p = __fln__test1I_int_sec(b);
  f(a);
  a = 1;
  return a;
}

int testf_3ip(__fln__test1I_int a, __fln__test2I_int b)
{
  int b__fln_p = __fln__test2I_int_sec(b);
  int a__fln_p = __fln__test1I_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

int testf_3sip(__fln__test1S_int a, __fln__test2I_int b)
{
  int b__fln_p = __fln__test2I_int_sec(b);
  int a__fln_p = __fln__test1S_int_sec(a);
  f(a__fln_p);
  a__fln_p = 1;
  return a__fln_p;
}

__fln__test1S_int testf_4s(int a, int b)
{
  f(a);
  a = 1;
  return __fln__test1S_int_intg(a);
}

__fln__test1I_int testf_4i(int a, int b)
{
  f(a);
  a = 1;
  return __fln__test1I_int_intg(a);
}

int test2()
{
  __fln__test1S_test2S_test3S_int a;
  {
    __fln__test1S_int a__fln_h = __fln__test1S_test2S_test3S_int_fst_r(a);
    __fln__test2S_int a__fln_s = f(a__fln_h);
    __fln__test2S_test3S_int a__fln_t = __fln__test2S_test3S_int_fst_w(a__fln_s);
    {
      a__fln_t = __fln__test1S_test2S_test3S_int_intg(b);
    }
  }
}

int test2_p()
{
  __fln__test1S_test2S_test3S_int *a;
  {
    __fln__test1S_int* a__fln_h = __fln__test1S_test2S_test3S_int_fst_r_ptr(a);
    __fln__test2S_int* a__fln_s = f(a__fln_h);
    __fln__test2S_test3S_int* a__fln_t = __fln__test2S_test3S_int_fst_w_ptr(a__fln_s);
    {
      a__fln_t = __fln__test1S_test2S_test3S_int_intg_ptr(b);
    }
  }
}

int test3()
{
  __fln__test1S_test2S_test3S_int a;
  {
    __fln__test1S_int a__fln_h = __fln__test1S_test2S_test3S_int_fst_r(a);
    y = f(a__fln_h);
    __fln__test2S_test3S_int y__fln_t = __fln__test2S_test3S_int_fst_w(y);
    {
      y__fln_t = b;
    }
  }
}

int test3_p()
{
  __fln__test1S_test2S_test3S_int *a;
  {
    __fln__test1S_int* a__fln_h = __fln__test1S_test2S_test3S_int_fst_r_ptr(a);
    y = f(a__fln_h);
    __fln__test2S_test3S_int* y__fln_t = __fln__test2S_test3S_int_fst_w_ptr(y);
    {
      y__fln_t = b;
    }
  }
}

int test4()
{
  __fln__test1I_test2I_int a;
  {
    {
      __fln__test2I_int a__fln_t = __fln__test1I_test2I_int_tail_r(a);
      __fln__test2I_int a__fln_r = __fln__test2I_int_intg(b);
      a__fln_t = a__fln_r;
    }
  }
}

int test4_p()
{
  __fln__test1I_test2I_int *a;
  {
    {
      __fln__test2I_int* a__fln_t = __fln__test1I_test2I_int_tail_r_ptr(a);
      __fln__test2I_int* a__fln_r = __fln__test2I_int_intg_ptr(b);
      a__fln_t = a__fln_r;
    }
  }
}

int test5()
{
  __fln__test1I_test2I_int a;
  {
    {
      __fln__test2I_int a__fln_t = __fln__test1I_test2I_int_tail_r(a);
      a__fln_t = b();
    }
  }
}

int test5_p()
{
  __fln__test1I_test2I_int a;
  {
    {
      __fln__test2I_int a__fln_t = __fln__test1I_test2I_int_tail_r(a);
      a__fln_t = b();
    }
  }
}

int test6()
{
  __fln__test1S_test2S_test3S_int a;
  __fln__test1S_int a__fln_h = __fln__test1S_test2S_test3S_int_fst_r(a);
  __fln__test2S_int a__fln_s = f(a__fln_h);
  __fln__test2S_test3S_int a__fln_t = __fln__test2S_test3S_int_fst_w(a__fln_s);
  {
    __fln__test2S_int a__fln_t__fln_h = __fln__test2S_test3S_int_fst_r(a__fln_t);
    __fln__test3S_int a__fln_t__fln_s = g(a__fln_t__fln_h);
    {
      h(a__fln_t__fln_s);
    }
  }
}

int test6_p()
{
  __fln__test1S_test2S_test3S_int *a;
  __fln__test1S_int* a__fln_h = __fln__test1S_test2S_test3S_int_fst_r_ptr(a);
  __fln__test2S_int* a__fln_s = f(a__fln_h);
  __fln__test2S_test3S_int* a__fln_t = __fln__test2S_test3S_int_fst_w_ptr(a__fln_s);
  {
    __fln__test2S_int* a__fln_t__fln_h = __fln__test2S_test3S_int_fst_r_ptr(a__fln_t);
    __fln__test3S_int* a__fln_t__fln_s = g(a__fln_t__fln_h);
    {
      h(a__fln_t__fln_s);
    }
  }
}

int test7()
{
  __fln__test1I_test2I_test3I_int a;
  f(__fln__test1I_test2I_test3I_int_sec(a));
  {
    g(__fln__test1I_test2I_test3I_int_sec(a));
    {
      h(__fln__test1I_test2I_test3I_int_sec(a));
    }
  }
}

int test7_p()
{
  __fln__test1I_test2I_test3I_int *a;
  f(__fln__test1I_test2I_test3I_int_sec_ptr(a));
  {
    g(__fln__test1I_test2I_test3I_int_sec_ptr(a));
    {
      h(__fln__test1I_test2I_test3I_int_sec_ptr(a));
    }
  }
}

int test8()
{
  __fln__test1S_test2S_test3S_test4S_int a;
  __fln__test1S_int a__fln_h = __fln__test1S_test2S_test3S_test4S_int_fst_r(a);
  b = f(a__fln_h);
  __fln__test2S_test3S_test4S_int b__fln_t = __fln__test2S_test3S_test4S_int_fst_w(b);
  {
    __fln__test2S_int b__fln_t__fln_h = __fln__test2S_test3S_test4S_int_fst_r(b__fln_t);
    c = g(b__fln_t__fln_h);
    __fln__test3S_test4S_int c__fln_t = __fln__test3S_test4S_int_fst_w(c);
    {
      __fln__test3S_int c__fln_t__fln_h = __fln__test3S_test4S_int_fst_r(c__fln_t);
      d = h(c__fln_t__fln_h);
    }
  }
}

int test8_p()
{
  __fln__test1I_test2I_test3I_test4I_int *a;
  b = f(__fln__test1I_test2I_test3I_test4I_int_sec_ptr(a));
  {
    c = g(b);
    {
      d = h(c);
    }
  }
}

int test9()
{
  __fln__test1I_test2I_test3I_int a;
  __fln__test2I_test3I_int a__fln_t = __fln__test1I_test2I_test3I_int_tail_r(a);
  __fln__test2I_test3I_int a__fln_r = __fln__test2I_test3I_int_fst_w(b);
  a__fln_t = a__fln_r;
  __fln__test3I_int a__fln_t__fln_t = __fln__test2I_test3I_int_tail_r(a__fln_t);
  __fln__test3I_int a__fln_t__fln_r = __fln__test3I_int_intg(c);
  a__fln_t__fln_t = a__fln_t__fln_r;
  a__fln_t__fln_t = d;
}

int test9_p()
{
  __fln__test1I_test2I_test3I_int *a;
  __fln__test2I_test3I_int* a__fln_t = __fln__test1I_test2I_test3I_int_tail_r_ptr(a);
  __fln__test2I_test3I_int* a__fln_r = __fln__test2I_test3I_int_fst_w_ptr(b);
  a__fln_t = a__fln_r;
  __fln__test3I_int* a__fln_t__fln_t = __fln__test2I_test3I_int_tail_r_ptr(a__fln_t);
  __fln__test3I_int* a__fln_t__fln_r = __fln__test3I_int_intg_ptr(c);
  a__fln_t__fln_t = a__fln_t__fln_r;
  a__fln_t__fln_t = d;
}

int test10()
{
  __fln__test1I_struct_foo1 x;
}

int test10a()
{
  __fln__test1S_const_struct_foo1 x;
}

int test11()
{
  __fln__test1I_test2I_struct_foo1 x;
}

int test11a()
{
  __fln__test1S_test2S_const_struct_foo1 x;
}

int test12()
{
  __fln__test1I_struct_foo1 *x;
}

int test12a()
{
  __fln__test1S_const_struct_foo1 *x;
}

int test13()
{
  __fln__test1I_test2I_struct_foo1 *x;
}

int test13a()
{
  __fln__test1S_test2S_const_int *x;
}

int test14()
{
  __fln__test1I_int x;
}

int test14a()
{
  __fln__test1I_const_int x;
}

int test15()
{
  __fln__test1I_int x;
}

int test15a()
{
  __fln__test1I_const_int *x;
}

int test16(__fln__test1I_struct_foo x)
{
  struct foo x__fln_p = __fln__test1I_struct_foo_sec(x);
  return 0;
}

int test16a(__fln__test1I_const_struct_foo x)
{
  const struct foo x__fln_p = __fln__test1I_const_struct_foo_sec(x);
  return 0;
}

int test17(__fln__test1I_struct_foo *x)
{
  struct foo* x__fln_p = __fln__test1I_struct_foo_sec_ptr(x);
  return 0;
}

int test17a(__fln__test1I_const_struct_foo *x)
{
  const struct foo* x__fln_p = __fln__test1I_const_struct_foo_sec_ptr(x);
  return 0;
}

int main()
{
  return 0;
}

int test17a(__fln__test1I_volatile_const_int *x)
{
  volatile const int* x__fln_p = __fln__test1I_volatile_const_int_sec_ptr(x);
  return 0;
}

