typedef long long widest_t;
typedef struct ProtocolDesc ProtocolDesc;
typedef struct OblivInputs OblivInputs;
typedef struct OblivBit
{
  int unknown;
  union 
  {
    int knownValue;
  };
} OblivBit;
struct ProtocolDesc
{
  int partyCount;
  int thisParty;
  int error;
  struct ProtocolTransport *trans;
  union 
  {
    struct 
    {
      unsigned int mulCount;
      unsigned int xorCount;
    } debug;
  };
  int (*currentParty)(ProtocolDesc *);
  void (*feedOblivInputs)(ProtocolDesc *, OblivInputs *, int, int);
  int (*revealOblivBits)(ProtocolDesc *, widest_t *, const OblivBit *, int, int);
  void (*setBitAnd)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitOr)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitXor)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitNot)(ProtocolDesc *, OblivBit *, const OblivBit *);
  void (*flipBit)(ProtocolDesc *, OblivBit *);
  void *extra;
};
static ProtocolDesc *currentProto;
inline static int known(const OblivBit *o)
{
  return !o->unknown;
}

typedef struct 
{
  OblivBit d;
} __fln__oblivS_OblivBit;
typedef struct 
{
  const OblivBit d;
} __fln__oblivS_const_OblivBit;
__fln__oblivS_OblivBit __fln__oblivS_OblivBit_intg(OblivBit x)
{
  __fln__oblivS_OblivBit y = {.d = x};
  return y;
}

__fln__oblivS_OblivBit *__fln__oblivS_OblivBit_intg_ptr(OblivBit *x)
{
  __fln__oblivS_OblivBit tmp = {.d = *x};
  __fln__oblivS_OblivBit *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

OblivBit __fln__oblivS_OblivBit_sec(__fln__oblivS_OblivBit x)
{
  return x.d;
}

OblivBit *__fln__oblivS_OblivBit_sec_ptr(__fln__oblivS_OblivBit *x)
{
  return &x->d;
}

__fln__oblivS_const_OblivBit __fln__oblivS_const_OblivBit_intg(const OblivBit x)
{
  __fln__oblivS_const_OblivBit y = {.d = x};
  return y;
}

__fln__oblivS_const_OblivBit *__fln__oblivS_const_OblivBit_intg_ptr(const OblivBit *x)
{
  __fln__oblivS_const_OblivBit tmp = {.d = *x};
  __fln__oblivS_const_OblivBit *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const OblivBit __fln__oblivS_const_OblivBit_sec(__fln__oblivS_const_OblivBit x)
{
  return x.d;
}

const OblivBit *__fln__oblivS_const_OblivBit_sec_ptr(__fln__oblivS_const_OblivBit *x)
{
  return &x->d;
}

typedef struct OblivBit
{
  int unknown;
  union 
  {
    int knownValue;
  };
} OblivBit;
void __obliv_c__assignBitKnown(__fln__oblivS_OblivBit *dest, int value)
{
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  dest__fln_p->knownValue = value;
  dest__fln_p->unknown = 0;
}

void __obliv_c__copyBit(__fln__oblivS_OblivBit *dest, __fln__oblivS_const_OblivBit *src)
{
  const OblivBit* src__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(src);
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  if (dest__fln_p != src__fln_p)
    *dest__fln_p = *src__fln_p;

}

int __obliv_c__bitIsKnown(int *v, __fln__oblivS_const_OblivBit *bit)
{
  const OblivBit* bit__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(bit);
  if (known(bit__fln_p))
    *v = bit__fln_p->knownValue;

  return known(bit__fln_p);
}

void __obliv_c__flipBit(__fln__oblivS_OblivBit *dest)
{
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  if (known(dest__fln_p))
    dest__fln_p->knownValue = !dest__fln_p->knownValue;
  else
    currentProto->flipBit(currentProto, dest__fln_p);

}

void __obliv_c__setBitAnd(__fln__oblivS_OblivBit *dest, __fln__oblivS_const_OblivBit *a, __fln__oblivS_const_OblivBit *b)
{
  const OblivBit* b__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(b);
  const OblivBit* a__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(a);
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  if (known(a__fln_p) || known(b__fln_p))
  {
    if (!known(a__fln_p))
    {
      const OblivBit *t = a__fln_p;
      a__fln_p = b__fln_p;
      b__fln_p = t;
    }

    if (a__fln_p->knownValue)
      __obliv_c__copyBit(dest__fln_p, b__fln_p);
    else
      __obliv_c__assignBitKnown(dest__fln_p, 0);

  }
  else
    currentProto->setBitAnd(currentProto, dest__fln_p, a__fln_p, b__fln_p);

}

void __obliv_c__setBitOr(__fln__oblivS_OblivBit *dest, __fln__oblivS_const_OblivBit *a, __fln__oblivS_const_OblivBit *b)
{
  const OblivBit* b__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(b);
  const OblivBit* a__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(a);
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  if (known(a__fln_p) || known(b__fln_p))
  {
    if (!known(a__fln_p))
    {
      const OblivBit *t = a__fln_p;
      a__fln_p = b__fln_p;
      b__fln_p = t;
    }

    if (!a__fln_p->knownValue)
      __obliv_c__copyBit(dest__fln_p, b__fln_p);
    else
      __obliv_c__assignBitKnown(dest__fln_p, 1);

  }
  else
    currentProto->setBitOr(currentProto, dest__fln_p, a__fln_p, b__fln_p);

}

void __obliv_c__setBitXor(__fln__oblivS_OblivBit *dest, __fln__oblivS_const_OblivBit *a, __fln__oblivS_const_OblivBit *b)
{
  const OblivBit* b__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(b);
  const OblivBit* a__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(a);
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  int v;
  if (known(a__fln_p) || known(b__fln_p))
  {
    if (!known(a__fln_p))
    {
      const OblivBit *t = a__fln_p;
      a__fln_p = b__fln_p;
      b__fln_p = t;
    }

    v = a__fln_p->knownValue;
    __obliv_c__copyBit(dest__fln_p, b__fln_p);
    if (v)
      __obliv_c__flipBit(dest__fln_p);

  }
  else
    currentProto->setBitXor(currentProto, dest__fln_p, a__fln_p, b__fln_p);

}

void __obliv_c__setBitNot(__fln__oblivS_OblivBit *dest, __fln__oblivS_const_OblivBit *a)
{
  const OblivBit* a__fln_p = __fln__oblivS_const_OblivBit_sec_ptr(a);
  OblivBit* dest__fln_p = __fln__oblivS_OblivBit_sec_ptr(dest);
  if (known(a__fln_p))
  {
    *dest__fln_p = *a__fln_p;
    dest__fln_p->knownValue = !dest__fln_p->knownValue;
  }
  else
    currentProto->setBitNot(currentProto, dest__fln_p, a__fln_p);

}

void test()
{
  return;
}

int main()
{
  __fln__oblivS_OblivBit *data = malloc((sizeof(OblivBit)) * 32);
  int input[32];
  for (int i = 0; i < 32; i++)
  {
    input[i] = i;
  }

  for (int i = 0; i < 32; i++)
  {
    __obliv_c__assignBitKnown(&data[i], input[i]);
  }

}

