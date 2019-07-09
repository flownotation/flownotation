#ifndef OBLIV_H
#define OBLIV_H
#define bool int
#define true 1
#define false 0
#define unsigned unsigned int
#define size_t int

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

struct ProtocolDesc {
  int partyCount, thisParty, error;
  struct ProtocolTransport* trans;
  union // a struct for each protocol-specific info
  { 
    struct { unsigned mulCount,xorCount; } debug;
  };
  int (*currentParty)(ProtocolDesc*);
  void (*feedOblivInputs)(ProtocolDesc*,OblivInputs*,size_t,int);
  // Return value is true if the write was actually done
  bool (*revealOblivBits)(ProtocolDesc*,widest_t*,const OblivBit*,size_t,int);

  void (*setBitAnd)(ProtocolDesc*,OblivBit*,const OblivBit*,const OblivBit*);
  void (*setBitOr )(ProtocolDesc*,OblivBit*,const OblivBit*,const OblivBit*);
  void (*setBitXor)(ProtocolDesc*,OblivBit*,const OblivBit*,const OblivBit*);
  void (*setBitNot)(ProtocolDesc*,OblivBit*,const OblivBit*);
  void (*flipBit  )(ProtocolDesc*,OblivBit*); // Sometimes avoids a struct copy

  void* extra;  // protocol-specific information
                // First field should be char protoType
};

#endif

#ifndef CURRENT_PROTO
#define CURRENT_PROTO
// Right now, we do not support multiple protocols at the same time
static ProtocolDesc *currentProto;
static inline bool known(const OblivBit* o) { return !o->unknown; }
#endif
