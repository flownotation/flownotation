#pragma once

#include "../../src/pycparser/utils/fake_libc_include/stddef.h"
#include "../../src/pycparser/utils/fake_libc_include/string.h"
#include "obliv_common.h"

void ocShareMuxes(ProtocolDesc *pd, char *z,
const char *x0, const char *x1, size_t n, size_t eltsize,
const bool *c, const bool *wc, char *t);

void ocFromShared_impl(ProtocolDesc *pd, void *dest, const void *src,
size_t n, size_t bits, size_t bytes);

// These are effectively  assignment operators
typedef struct OcCopy OcCopy;

typedef void (*ocopy_cb)(const OcCopy *,
void *, const void *, size_t);
typedef void (*ocopy_cond_cb)(const OcCopy *,
void *, const void *, const bool *, size_t);

struct OcCopy
{
ocopy_cb go; // Guaranteed to work in non- scopes even on
// uninitialized destinations.
ocopy_cond_cb goN;
void (*release)(OcCopy *);
size_t eltsize;

// "Free" utilities
void (*zeroFill)(const OcCopy *, void *, size_t);
void (*addN)(const OcCopy *, void *, const void *, size_t);
void (*subN)(const OcCopy *, void *, const void *, size_t);
};

static inline void ocShareDuplicate(void *dest, const void *src, size_t n)
{
memcpy(dest, src, n);
}

static inline void ocShareXor(void *dest, const void *src, size_t n)
{
memxor(dest, src, n);
}

static inline void ocCopyN(const OcCopy *c, void *dest, const void *src, size_t n)
{
c->go(c, dest, src, n);
}

static inline void ocCopy(const OcCopy *c, void *dest, const void *src)
{
ocCopyN(c, dest, src, 1);
}

static inline void ocCopyCondN(const OcCopy *c, void *dest, const void *src,
const bool *cond, size_t n)
{
c->goN(c, dest, src, cond, n);
}

void ocSwap(OcCopy *cpy, void *opt0, void *opt1, void *scratch);
void ocSwapCondN(OcCopy *cpy, void *opt0, void *opt1, void *scratch,
const bool c[], size_t n);

static inline void ocCopyRelease(OcCopy *c)
{
c->release(c);
}

static inline void ocCopyZeroFill(OcCopy *c, void *dest, size_t n)
{
c->zeroFill(c, dest, n);
}

static inline void ocCopyAddN(OcCopy *c, void *dest, const void *src, size_t n)
{
c->addN(c, dest, src, n);
}
static inline void ocCopySubN(OcCopy *c, void *dest, const void *src, size_t n)
{
c->subN(c, dest, src, n);
}

static inline void *ocCopyElt(OcCopy *cpy, void *arr, int x)
{
return x * cpy->eltsize + (char *)arr;
}

extern const OcCopy ocCopyBool, ocCopyChar, ocCopyShort, ocCopyInt, ocCopyLong,
ocCopyLLong, ocCopySizeT;

// /* ------------------- Shared, packed representations ------------------------
//    Used only with honest-but-curious Yao's protocol.
//    ---------------------------------------------------------------------------
//    Produces a "packed and shared" representation of values, which can
//    be copied around and multiplexed very efficiently in bandwidth. However,
//    they introduce round-trip latencies, so you are encouraged to use the
//    ocCopyN and ocCopyCondN functions on these which copy many values in
//    one go. At least currently, they cannot be used for any arithmetic,
//    so you have to switch back-and-forth between this and ordinary  types
//    if you want to do that.

//    And yes, there is no OcSharedBool type. Use ordinary  bool instead.
//    Also, current implementation doesn't do anything fast for known values,
//    so you should really only use it for unknowns.
//    ---------------------------------------------------------------------------
// */

// typedef char OcSharedChar [ocBitSize( char     )/8];
// typedef char OcSharedShort[ocBitSize( short    )/8];
// typedef char OcSharedInt  [ocBitSize( int      )/8];
// typedef char OcSharedLong [ocBitSize( long     )/8];
// typedef char OcSharedLLong[ocBitSize( long long)/8];

// void ocFromShared_impl(ProtocolDesc* pd,
//                        void* dest,const void* src,size_t n,
//                        size_t bits,size_t bytes);
// // These functions should probably check if ocCurrentProtocol is Yao's
// #define OC_SHARED_CONVERT(t,T) \
//   void \
//   ocToShared##T##N \
//   ( ProtocolDesc* pd, \
//     OcShared##T dest[], t src[],\
//     size_t n); \
//   static inline void \
//   ocFromShared##T##N \
//   ( ProtocolDesc* pd, \
//      t dest[],OcShared##T src[],size_t n\
//   )\
//   { ocFromShared_impl(pd,dest,src,n,ocBitSize( t),sizeof( t)); }\
//   static inline void \
//   ocToShared##T \
//   ( ProtocolDesc* pd, \
//     OcShared##T* dest, t src) \
//     { ocToShared##T##N(pd,dest,&src,1); } \
//   static inline  t \
//   ocFromShared##T (ProtocolDesc* pd,OcShared##T* src)  \
//   {  t r; \
//     ~() ocFromShared##T##N(pd,&r,src,1); \
//     return r; \
//   }\
//   void\
//   ocFeedShared##T##N (OcShared##T dest[],const t src[], \
//                       size_t n,int party); \
//   void\
//   ocRevealShared##T##N (t dest[], const OcShared##T src[], \
//                         size_t n,int party);

// OC_SHARED_CONVERT(char, Char )
// OC_SHARED_CONVERT(short,Short)
// OC_SHARED_CONVERT(int,  Int  )
// OC_SHARED_CONVERT(long, Long )
// OC_SHARED_CONVERT(long long, LLong)
// #undef OC_SHARED_CONVERT

// extern OcCopy ocCopySharedChar, ocCopySharedShort, ocCopySharedInt,
//               ocCopySharedLong, ocCopySharedLLong;
// OcCopy ocCopyBoolN (size_t lim);
// OcCopy ocCopyCharN (size_t lim);
// OcCopy ocCopyShortN(size_t lim);
// OcCopy ocCopyIntN  (size_t lim);
// OcCopy ocCopyLLongN(size_t lim);

// OcCopy* ocShareCopyNew(ProtocolDesc* pd,size_t n,size_t eltsize);
// void ocShareCopyRelease(OcCopy* c);
// void ocShareInit(ProtocolDesc* pd);
// void ocShareCleanup(ProtocolDesc* pd);
