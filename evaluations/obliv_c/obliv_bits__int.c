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
#include "obliv_bits.h"
#include "obliv_bits__fln.h"

typedef struct OblivBit
{
int unknown;
union
{
int knownValue;
};
}
OblivBit;

void __obliv_c__assignBitKnown(OblivBit* dest, int value)
{ dest->knownValue = value; dest->unknown=false; }

void __obliv_c__copyBit(OblivBit* dest,const OblivBit* src)
{ if(dest!=src) *dest=*src; }

int __obliv_c__bitIsKnown(int* v,const OblivBit* bit)
{ if(known(bit)) *v=bit->knownValue;
return known(bit);
}

void __obliv_c__flipBit(OblivBit* dest)
{ if(known(dest)) dest->knownValue = !dest->knownValue;
else currentProto->flipBit(currentProto,dest);
}

void __obliv_c__setBitAnd(OblivBit* dest,const OblivBit* a,const OblivBit* b)
{
if(known(a) || known(b))
{ if(!known(a)) { const OblivBit* t=a; a=b; b=t; }
if(a->knownValue) __obliv_c__copyBit(dest,b);
else __obliv_c__assignBitKnown(dest,false);
}else currentProto->setBitAnd(currentProto,dest,a,b);
}

void __obliv_c__setBitOr(OblivBit* dest,const OblivBit* a,const OblivBit* b)
{
if(known(a) || known(b))
{ if(!known(a)) { const OblivBit* t=a; a=b; b=t; }
if(!a->knownValue) __obliv_c__copyBit(dest,b);
else __obliv_c__assignBitKnown(dest,true);
}else currentProto->setBitOr(currentProto,dest,a,b);
}

void __obliv_c__setBitXor(OblivBit* dest,const OblivBit* a,const OblivBit* b)
{
int v;
if(known(a) || known(b))
{ if(!known(a)) { const OblivBit* t=a; a=b; b=t; }
v = a->knownValue;
__obliv_c__copyBit(dest,b);
if(v) __obliv_c__flipBit(dest);
}else currentProto->setBitXor(currentProto,dest,a,b);
}

void __obliv_c__setBitNot(OblivBit* dest,const OblivBit* a)
{ if(known(a)){ *dest=*a; dest->knownValue=!dest->knownValue; }
else currentProto->setBitNot(currentProto,dest,a);
}

void test() {
return;
}

int main() {
OblivBit* data__fln_0 = malloc(sizeof(OblivBit)*32);

int input[32];
for (int i = 0; i < 32; i++) {
input[i] = i;
}

for (int i = 0; i < 32; i++) {
__obliv_c__assignBitKnown(&data[i], input[i]);
}

}
