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

int trusted_read(__fln__trusted_int x)
{
  int x__fln_p = __fln__trusted_int_read(x);
  return x__fln_p;
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
  trusted_read(x);
  random_func(__fln__trusted_int_read(y));
}

