#include "obliv_bits.h"
typedef struct OblivBit 
{
  int unknown;
  union 
  {
    int knownValue;
  };
} 
OblivBit;

#param(1) @obliv:secrecy
void __obliv_c__assignBitKnown(OblivBit* dest, int value)
  { dest->knownValue = value; dest->unknown=false; }

#param @obliv:secrecy
void __obliv_c__copyBit(OblivBit* dest,const OblivBit* src)
  { if(dest!=src) *dest=*src; }

#param(2) @obliv:secrecy
int __obliv_c__bitIsKnown(int* v,const OblivBit* bit)
{ if(known(bit)) *v=bit->knownValue;
  return known(bit);
}

#param @obliv:secrecy 
void __obliv_c__flipBit(OblivBit* dest) 
{ if(known(dest)) dest->knownValue = !dest->knownValue;
  else currentProto->flipBit(currentProto,dest); 
}

#param @obliv:secrecy
void __obliv_c__setBitAnd(OblivBit* dest,const OblivBit* a,const OblivBit* b)
{
  if(known(a) || known(b))
  { if(!known(a)) { const OblivBit* t=a; a=b; b=t; }
    if(a->knownValue) __obliv_c__copyBit(dest,b);
    else __obliv_c__assignBitKnown(dest,false);
  }else currentProto->setBitAnd(currentProto,dest,a,b);
}

#param @obliv:secrecy
void __obliv_c__setBitOr(OblivBit* dest,const OblivBit* a,const OblivBit* b)
{
  if(known(a) || known(b))
  { if(!known(a)) { const OblivBit* t=a; a=b; b=t; }
    if(!a->knownValue) __obliv_c__copyBit(dest,b);
    else __obliv_c__assignBitKnown(dest,true);
  }else currentProto->setBitOr(currentProto,dest,a,b);
}

#param @obliv:secrecy
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

#param @obliv:secrecy
void __obliv_c__setBitNot(OblivBit* dest,const OblivBit* a)
{ if(known(a)){ *dest=*a; dest->knownValue=!dest->knownValue; }
  else currentProto->setBitNot(currentProto,dest,a); 
}

#param @obliv:secrecy
void test() {
  return;
}

int main() {
    #requires @obliv:secrecy
    OblivBit* data = malloc(sizeof(OblivBit)*32);
    
    int input[32];
    for (int i = 0; i < 32; i++) {
      input[i] = i;
    }

    for (int i = 0; i < 32; i++) {
      __obliv_c__assignBitKnown(&data[i], input[i]);
    }
  
}
