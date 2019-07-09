typedef struct 
{
  int e;
  int d;
  int N;
} pair;
typedef struct 
{
  int d;
} __fln__randomI_int;
typedef struct 
{
  pair d;
} __fln__RSAkeyI_pair;
typedef struct 
{
  pair d;
} __fln__RSAkeyS_pair;
typedef struct 
{
  int d;
} __fln__secretS_int;
typedef struct 
{
  int d;
} __fln__randomS_int;
__fln__randomI_int __fln__randomI_int_intg(int x)
{
  __fln__randomI_int y = {.d = x};
  return y;
}

__fln__randomI_int *__fln__randomI_int_intg_ptr(int *x)
{
  __fln__randomI_int tmp = {.d = *x};
  __fln__randomI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__randomI_int_sec(__fln__randomI_int x)
{
  return x.d;
}

int *__fln__randomI_int_sec_ptr(__fln__randomI_int *x)
{
  return &x->d;
}

__fln__RSAkeyI_pair __fln__RSAkeyI_pair_intg(pair x)
{
  __fln__RSAkeyI_pair y = {.d = x};
  return y;
}

__fln__RSAkeyI_pair *__fln__RSAkeyI_pair_intg_ptr(pair *x)
{
  __fln__RSAkeyI_pair tmp = {.d = *x};
  __fln__RSAkeyI_pair *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

pair __fln__RSAkeyI_pair_sec(__fln__RSAkeyI_pair x)
{
  return x.d;
}

pair *__fln__RSAkeyI_pair_sec_ptr(__fln__RSAkeyI_pair *x)
{
  return &x->d;
}

__fln__RSAkeyS_pair __fln__RSAkeyS_pair_intg(pair x)
{
  __fln__RSAkeyS_pair y = {.d = x};
  return y;
}

__fln__RSAkeyS_pair *__fln__RSAkeyS_pair_intg_ptr(pair *x)
{
  __fln__RSAkeyS_pair tmp = {.d = *x};
  __fln__RSAkeyS_pair *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

pair __fln__RSAkeyS_pair_sec(__fln__RSAkeyS_pair x)
{
  return x.d;
}

pair *__fln__RSAkeyS_pair_sec_ptr(__fln__RSAkeyS_pair *x)
{
  return &x->d;
}

__fln__secretS_int __fln__secretS_int_intg(int x)
{
  __fln__secretS_int y = {.d = x};
  return y;
}

__fln__secretS_int *__fln__secretS_int_intg_ptr(int *x)
{
  __fln__secretS_int tmp = {.d = *x};
  __fln__secretS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__secretS_int_sec(__fln__secretS_int x)
{
  return x.d;
}

int *__fln__secretS_int_sec_ptr(__fln__secretS_int *x)
{
  return &x->d;
}

__fln__randomS_int __fln__randomS_int_intg(int x)
{
  __fln__randomS_int y = {.d = x};
  return y;
}

__fln__randomS_int *__fln__randomS_int_intg_ptr(int *x)
{
  __fln__randomS_int tmp = {.d = *x};
  __fln__randomS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__randomS_int_sec(__fln__randomS_int x)
{
  return x.d;
}

int *__fln__randomS_int_sec_ptr(__fln__randomS_int *x)
{
  return &x->d;
}

void send(int addr, int data)
{
}

int recv(int addr)
{
  int v = 0;
  return v;
}

__fln__RSAkeyI_pair gen_RSA_pair()
{
  int e = 0;
  int d = 0;
  int N = 0;
  pair p = {e, d, N};
  return __fln__RSAkeyI_pair_intg(p);
}

int get_public(__fln__RSAkeyS_pair p)
{
  pair p__fln_p = __fln__RSAkeyS_pair_sec(p);
  return p__fln_p.e;
}

int get_private(__fln__RSAkeyS_pair p)
{
  pair p__fln_p = __fln__RSAkeyS_pair_sec(p);
  return p__fln_p.d;
}

int get_modulus(__fln__RSAkeyS_pair p)
{
  pair p__fln_p = __fln__RSAkeyS_pair_sec(p);
  return p__fln_p.N;
}

int rand_int()
{
  int s = sample();
  return s;
}

int enc(int m, int k)
{
  return m + k;
}

int safe_rand_sub(__fln__randomS_int a, __fln__randomS_int b)
{
  int b__fln_p = __fln__randomS_int_sec(b);
  int a__fln_p = __fln__randomS_int_sec(a);
  int t = a__fln_p - b__fln_p;
  return t;
}

void ot_alice(__fln__secretS_int m0, __fln__secretS_int m1)
{
  int m0__fln_p = __fln__secretS_int_sec(m0);
  int m1__fln_p = __fln__secretS_int_sec(m1);
  __fln__RSAkeyI_pair p;
  p = gen_RSA_pair();
  get_public(__fln__RSAkeyI_pair_sec(p));
  send(1, get_public(__fln__RSAkeyI_pair_sec(p)));
  send(1, get_modulus(__fln__RSAkeyI_pair_sec(p)));
  __fln__randomI_int x0;
  __fln__randomI_int x1;
  x0 = rand_int();
  x1 = rand_int();
  send(1, __fln__randomI_int_sec(x0));
  send(1, __fln__randomI_int_sec(x1));
  __fln__randomS_int v;
  v = __fln__randomS_int_intg(recv(1));
  int k0 = pow(safe_rand_sub(v, __fln__randomI_int_sec(x0)), get_private(__fln__RSAkeyI_pair_sec(p)));
  int k1 = pow(safe_rand_sub(v, __fln__randomI_int_sec(x1)), get_private(__fln__RSAkeyI_pair_sec(p)));
  send(1, enc(m0__fln_p, k0));
  send(1, enc(m1__fln_p, k1));
}

int ot_bob(int c)
{
  int e = recv(0);
  int N = recv(0);
  int x0 = recv(0);
  int x1 = recv(0);
  __fln__randomI_int k;
  k = rand_int();
  int v;
  if (c == 0)
  {
    v = x0 + pow(__fln__randomI_int_sec(k), e);
  }
  else
  {
    v = x1 + pow(__fln__randomI_int_sec(k), e);
  }

  send(0, v);
  int m0p = recv(0);
  int m1p = recv(0);
  if (c == 0)
  {
    return m0p - __fln__randomI_int_sec(k);
  }
  else
  {
    return m1p - __fln__randomI_int_sec(k);
  }

}

