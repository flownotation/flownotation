//
//  PoolScheme.h
//
//
//  Created by Sourgroup on 8/31/17.
//
//
/*
This framework works for all types of LEGO-style protocols, as long as they allows on-demand bucket generation*/

#ifndef PooLScheme_h
#define PooLScheme_h

#include "../../src/pycparser/utils/fake_libc_include/stdio.h"
#include "../../src/pycparser/utils/fake_libc_include/stdbool.h"
#include "../../src/pycparser/utils/fake_libc_include/stdlib.h"
// #include "../../src/pycparser/utils/fake_libc_include/emmintrin.h"
// #include "../../src/pycparser/utils/fake_libc_include/immintrin.h"
#include "../../src/pycparser/utils/fake_libc_include/stdint.h"
//#include <sys/random.h>
#include "PRG.h"
// #include "PoolWarpper.h"
/*! \file PoolScheme.h*/

typedef struct OblivBit
{
int unknown;
union {
int knownValue;
};
} OblivBit;

/**
* @brief Pool structure, a collection of all the pool configuration
*
*/
typedef struct
{
block Pool_PRG_SeedBlock; /**< PRG Seed */
AES_KEY Pool_PRG_Seed;    /**< expanded PRG Seed */
uint64_t Pool_PRG_Count;  /**< PRG index */
uint64_t Pool_Size;       /**< Pool Size for this pool */
uint64_t Buffer_Size;     /**< Buffersize for this pool */
double Check_Rate;        /**< Check rate for this pool */
uint64_t Bucket_Size;     /**< Bucket size for this pool */

void *ext[2];
/**< Extra information needed by underlying protocol. */
size_t Gate_Pointer_Size;             /**<This is the size of the pointer to the batch of and-gates, mux-gates or something else. */
void *Batch_Gates_in_Pool;            /**<This is the pointer to the Pool batch, whose size is Gate_Pointer_Size. */
void *Batch_Gates_in_Buffer;          /**<This is the pointer to the Buffer batch, whose size is Gate_Pointer_Size. */
uint64_t *Gate_in_Buffer_Index_Array; /**<This array denotes the index of the gates that are about to go to Pool from buffer.*/
uint64_t *Gate_in_Bucket_Index_Array; /**<This array denotes the index of the gates that are about to go to buckets.*/
uint64_t Buffer_Index;                /**<This is the index of the next about-to-go gate in buffer.*/
uint64_t Bucket_Index;                /**< This is the index of the next about-to-go in Pool.*/
uint64_t Bucket_Buffer_Size;          /**< This is how many indexes of gates are stored.*/
size_t Bucket_Pointer_Size;           /**< This is the size of the pointer to the about-to-evaluate bucket.*/
void *Bucket_Pointer;                 /**< This points to the about-to-evaluate bucket.*/

void (*Batch_Gates_Generation)(void *Batch_Gates_dst, uint64_t n, void *ext[]); /**< This function generates n gates and puts them into Batch_Gates_dst. */
void (*Gate_Check)(void *Batch_Gates, uint64_t index, void *ext[]);             /**< This function checks the index^th gate in Batch_Gates, with the randomness in ext. */
void (*Gate_Copy)(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void *ext[]);
/**< This function copies a gate from src to dst, the indexs/indexd is the gate index in the batches. */
void (*Evaluation)(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void *ext[]);                                     /**< This function evaluates Bucket with InputL and InputR and puts the result in Outputs */
void (*Malloc_Gate_Pointer)(void *dst, uint64_t size, void *ext[]);                                                                                /**< This function allocats memory for the gate batch pointer*/
void (*Malloc_Bucket_Pointer)(void *dst, uint64_t size, void *ext[]);                                                                              /**< This function allocates memory for the bucket pointer*/
void (*Bucket_Build)(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void *ext[]); /**<This function regenerates n buckets of size BucketSize and puts them at Bucket_Pointer_dst, Gates are from Batch_Gates_in_Pool, whose indexes are in *Gate_in_Bucket_Index_Array;*/
void (*Refresh_Seed)(void **ext, block SeedBlock);                                                                                                 /**< This function simply refreshes the random seed in **ext*/
} Pool;

/**
* @brief Service structure, a collection of all the configuration of this framework, may influence the underlying pools.
*/

typedef struct
{
Pool And_Pool;                                                                /**< This is the AndGate Pool*/
Pool Mux_Pool;                                                                /**< This is the MuxGate Pool*/
size_t extsize;                                                               /**< This is the size of the extra information needed by the underlying protocol*/
void *ext;                                                                    /**< This is the pointer to the extra information */
void (*extsetup)(void *ext, uint64_t BufferSize, block key);                  /**< This is the function to setup the extra information data structure*/
void (*Xor)(void *dst, void *L, void *R, void *ext);                          /**< This is the function to evaluate Xor gats*/
void (*Not)(void *dst, void *L, void *ext);                                   /**< This is the function to evaluate Not gates*/
void (*Alice_Input)(void *dst, unsigned char *choice, uint64_t n, void *ext); /**< Input data from Alice into this framework*/
void (*Bob_Input)(void *dst, unsigned char *choice, uint64_t n, void *ext);   /**< Input data from Bob into this framework*/
unsigned char (*Alice_Output)(void *bit, void *ext);                          /**< Reveal data to Alice from this framework*/
unsigned char (*Bob_Output)(void *bit, void *ex);                             /**< Reveal data to Bob from this framework*/
} ServiceConfig;

/*! \fn void SetupService(ServiceConfig *Service,size_t extsize,
void (*extsetup)(void *,uint64_t,block),
void (*Alice_Input)(void *,unsigned char *,uint64_t,void **),
void (*Bob_Input)(void *,unsigned char *,uint64_t,void **),
unsigned char (*Alice_Output)(void *,void **),
unsigned char (*Bob_Output)(void *,void **)
)
\brief Setup the whole service and put the configuration in Service.
\param Service Where to store the configuration.
\param extsize The size of the underlying protocol configuration.
\param extsetup Function to setup the underlying protocol configuration.
\param Alice_Input Function to input bits from Alice in the underlying protocol.
\param Bob_Input Function to input bits from Bob in the underlying protocol.
\param Alice_Output Function to reveal a bit to Alice in the underlying protocol.
\param Bob_Output Function to reveal a bit to Alice in the underlying protocol.
*/

void SetupService(ServiceConfig *Service, size_t extsize,
void (*extsetup)(void *, uint64_t, block),
void (*Alice_Input)(void *, unsigned char *, uint64_t, void *),
void (*Bob_Input)(void *, unsigned char *, uint64_t, void *),
unsigned char (*Alice_Output)(void *, void *),
unsigned char (*Bob_Output)(void *, void *),
void Xor(void *, void *, void *, void *),
void Not(void *, void *, void *));

/*! \fn void SetupPool(Pool *dst,
uint64_t PoolSize,
uint64_t BufferSize,
double CheckRate,
uint64_t BucketSize,
size_t Gate_Pointer_Size,
size_t Bucket_Pointer_Size,
uint64_t BucketBufferSize,
block PoolPRGSeed,
void (*Batch_Gates_Generation)(void *,uint64_t ,void **),
void (*Gate_Check)(void *,uint64_t ,void **),
void (*Gate_Copy)(void *,uint64_t ,void *,uint64_t ,void **),
void (*Bucket_Build)(void *, uint64_t , void *, uint64_t *, void **),
void (*Evaluation)(void *, void *, void *, void *,uint64_t, void **),
void (*MallocGatePointer)(void *, uint64_t ,void **),
void (*MallocBucketPointer)(void *, uint64_t ,void **),
void (*Refresh_Seed)(void **,block)
);

\brief Setup a pool for our service and put the configuration in dst.
\param dst Where to store the configuration.
\param PoolSize The size of the Pool, i.e. how many garbled gates are to be in the pool.
\param BufferSize The size of the Buffer, i.e. how many garbled gates are to be in the buffer.
\param CheckRate THe probability that a freshly garbled gate is checked.
\param BucketSize The size of the Bucket for this pool, i.e. how many garbled gates are to be in a bucket.
\param Gate_Pointer_Size is the space needed to config the underlying protocol.
\param Bucket_Pointer_Size is the space needed to store a bucket.
\param PoolPRGSeed is the random seed used in the protocol.
\param (*Batch_Gates_Generation)(void *,uint64_t ,void **) is the underlying protocol function, generates a batch of gates.
\param (*Gate_Check)(void *,uint64_t ,void **) is the underlying protocol function, checks a gate in a batch.
\param (*Gate_Copy)(void *,uint64_t ,void *,uint64_t ,void **) is the underlying protocol function, copies a gate in a batch to another gate in another batch.
\param (*Bucket_Build)(void *, uint64_t , void *, uint64_t *, void **) is the underlying protocol function, builds up a bucket given the indexes of the gates in it.
\param (*Evaluation)(void *, void *, void *, void *,uint64_t, void **) is the underlying protocol function, evaluates the bucket with given inputs.
\param (*MallocGatePointer)(void *, uint64_t ,void **) is the underlying protocol function, allocates the memory for a gate batch.
\param (*MallocBucketPointer)(void *, uint64_t ,void **) is the underlying protocol function, allocates the memory of a bucket.
\param (*Refresh_Seed)(void **,block) is the underlying protocol function, refreshes the random seed.
*/

void SetupPool(Pool *dst,
uint64_t PoolSize,
uint64_t BufferSize,
double CheckRate,
uint64_t BucketSize,
size_t Gate_Pointer_Size,
size_t Bucket_Pointer_Size,
uint64_t BucketBufferSize,
block PoolPRGSeed,
void (*Batch_Gates_Generation)(void *, uint64_t, void **),
void (*Gate_Check)(void *, uint64_t, void **),
void (*Gate_Copy)(void *, uint64_t, void *, uint64_t, void **),
void (*Bucket_Build)(void *, uint64_t, void *, uint64_t *, void **),
void (*Evaluation)(void *, void *, void *, void *, uint64_t, void **),
void (*MallocGatePointer)(void *, uint64_t, void **),
void (*MallocBucketPointer)(void *, uint64_t, void **),
void (*Refresh_Seed)(void **, block));
void Pool_Gate_Buffer_Refresh(Pool *dst);
uint64_t Next_Gate_in_Buffer(Pool *dst);
void Pool_Evaluation(void *dst, void *InputL, void *InputR, Pool *P);
static inline void Pool_Alice_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service);
static inline void Pool_Bob_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service);
static inline unsigned char Pool_Alice_Output(OblivBit *src, ServiceConfig *Service);
static inline unsigned char Pool_Bob_Output(OblivBit *src, ServiceConfig *Service);

/*! \fn void Pool_Alice_Input(OblivBit *dst,unsigned char *choice,uint64_t n,ServiceConfig *Service)
\brief generate n OblivBits, put them at *dst, and associate them with secret values from Alice, under the Framework of Service. Bob could pass a void pointer to choice.
*/
// #provides :secrecy(4) @initialized_service
static inline void Pool_Alice_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service)
{
(*(Service->Alice_Input))(dst, choice, n, Service->ext);
}

/*! \fn void Pool_Bob_Input(OblivBit *dst,unsigned char *choice,uint64_t n,ServiceConfig *Service)
\brief generate n OblivBits, put them at *dst, and associate them with secret values from Bob, under the Framework of Service. Alice could pass a void pointer to choice.
*/
static inline void Pool_Bob_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service)
{
(*(Service->Bob_Input))(dst, choice, n, Service->ext);
}

/*! \fn unsigned char Pool_Alice_Output(OblivBit *src,ServiceConfig *Service)
\brief  Interpret OblivBit *src and reveal it to Alice under the Framework of Service. Bob would always receive 0.
*/
static inline unsigned char Pool_Alice_Output(OblivBit *src, ServiceConfig *Service)
{
return (*(Service->Alice_Output))(src, Service->ext);
}

/*! \fn unsigned char Pool_Bob_Output(OblivBit *src,ServiceConfig *Service)
\brief  Interpret OblivBit *src and reveal it to Bob under the Framework of Service. Alice would always receive 0.
*/
static inline unsigned char Pool_Bob_Output(OblivBit *src, ServiceConfig *Service)
{
return (*(Service->Bob_Output))(src, Service->ext);
}

static inline void Service_Xor(void *dst, void *InputL, void *InputR, ServiceConfig *Service)
{
(*(Service->Xor))(dst, InputL, InputR, Service->ext);
}
static inline void Service_Not(void *dst, void *Input, ServiceConfig *Service)
{
(*(Service->Not))(dst, Input, Service->ext);
}
#endif /* PoolScheme_h */
#include "PoolScheme__fln.h"

#include "PoolScheme__fln.h"

#include "PoolScheme__fln.h"

//
//  PoolScheme.c
//
//
//  Created by Sourgroup on 8/31/17.
//
//

#include "PoolScheme.h"
//#include <sys/random.h>
/**
* @brief Pool structure, a collection of all the pool configuration
*
*/
typedef int block;

bool Checker(long long PoolSize,double r,long long BucketSize,long long s);

typedef struct
{
block Pool_PRG_SeedBlock; /**< PRG Seed */
AES_KEY Pool_PRG_Seed;    /**< expanded PRG Seed */
uint64_t Pool_PRG_Count;  /**< PRG index */
uint64_t Pool_Size;       /**< Pool Size for this pool */
uint64_t Buffer_Size;     /**< Buffersize for this pool */
double Check_Rate;        /**< Check rate for this pool */
uint64_t Bucket_Size;     /**< Bucket size for this pool */

void *ext[2];
/**< Extra information needed by underlying protocol. */
size_t Gate_Pointer_Size;             /**<This is the size of the pointer to the batch of and-gates, mux-gates or something else. */
void *Batch_Gates_in_Pool;            /**<This is the pointer to the Pool batch, whose size is Gate_Pointer_Size. */
void *Batch_Gates_in_Buffer;          /**<This is the pointer to the Buffer batch, whose size is Gate_Pointer_Size. */
uint64_t *Gate_in_Buffer_Index_Array; /**<This array denotes the index of the gates that are about to go to Pool from buffer.*/
uint64_t *Gate_in_Bucket_Index_Array; /**<This array denotes the index of the gates that are about to go to buckets.*/
uint64_t Buffer_Index;                /**<This is the index of the next about-to-go gate in buffer.*/
uint64_t Bucket_Index;                /**< This is the index of the next about-to-go in Pool.*/
uint64_t Bucket_Buffer_Size;          /**< This is how many indexes of gates are stored.*/
size_t Bucket_Pointer_Size;           /**< This is the size of the pointer to the about-to-evaluate bucket.*/
void *Bucket_Pointer;                 /**< This points to the about-to-evaluate bucket.*/

void (*Batch_Gates_Generation)(void *Batch_Gates_dst, uint64_t n, void *ext[]); /**< This function generates n gates and puts them into Batch_Gates_dst. */
void (*Gate_Check)(void *Batch_Gates, uint64_t index, void *ext[]);             /**< This function checks the index^th gate in Batch_Gates, with the randomness in ext. */
void (*Gate_Copy)(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void *ext[]);
/**< This function copies a gate from src to dst, the indexs/indexd is the gate index in the batches. */
void (*Evaluation)(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void *ext[]);                                     /**< This function evaluates Bucket with InputL and InputR and puts the result in Outputs */
void (*Malloc_Gate_Pointer)(void *dst, uint64_t size, void *ext[]);                                                                                /**< This function allocats memory for the gate batch pointer*/
void (*Malloc_Bucket_Pointer)(void *dst, uint64_t size, void *ext[]);                                                                              /**< This function allocates memory for the bucket pointer*/
void (*Bucket_Build)(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void *ext[]); /**<This function regenerates n buckets of size BucketSize and puts them at Bucket_Pointer_dst, Gates are from Batch_Gates_in_Pool, whose indexes are in *Gate_in_Bucket_Index_Array;*/
void (*Refresh_Seed)(void **ext, block SeedBlock);                                                                                                 /**< This function simply refreshes the random seed in **ext*/
} Pool;

Pool* SetupPool(Pool *dst,
uint64_t PoolSize,
uint64_t BufferSize,
double CheckRate,
uint64_t BucketSize,
size_t Gate_Pointer_Size,
size_t Bucket_Pointer_Size,
uint64_t BucketBufferSize,
block PoolPRGSeed,
void (*Batch_Gates_Generation)(void *, uint64_t, void **),
void (*Gate_Check)(void *, uint64_t, void **),
void (*Gate_Copy)(void *, uint64_t, void *, uint64_t, void **),
void (*Bucket_Build)(void *, uint64_t, void *, uint64_t *, void **),
void (*Evaluation)(void *, void *, void *, void *, uint64_t, void **),
void (*MallocGatePointer)(void *, uint64_t, void **),
void (*MallocBucketPointer)(void *, uint64_t, void **),
void (*Refresh_Seed)(void **, block))
{
// #requires { Pool_PRG_SeedBlock.block @random_block:integrity }
// #requires { Bucket_Index.uint64_t @valid_index:secrecy }
Pool dst2;
dst->Pool_PRG_Count = 0;
dst->Pool_Size = PoolSize;
dst->Buffer_Size = BufferSize;
dst->Check_Rate = CheckRate;
dst->Bucket_Size = BucketSize;
dst->Bucket_Buffer_Size = BucketBufferSize;
dst->Batch_Gates_in_Pool = _mm_malloc(Gate_Pointer_Size, 32);
dst->Batch_Gates_in_Buffer = _mm_malloc(Gate_Pointer_Size, 32);
dst->Gate_in_Bucket_Index_Array = (uint64_t *)malloc(sizeof(uint64_t) * BucketBufferSize * BucketSize);
dst->Gate_in_Buffer_Index_Array = (uint64_t *)malloc(sizeof(uint64_t) * BufferSize);
dst->Bucket_Pointer = _mm_malloc(Bucket_Pointer_Size, 32);

dst->Batch_Gates_Generation = (Batch_Gates_Generation);
dst->Gate_Check = (Gate_Check);
dst->Gate_Copy = (Gate_Copy);
dst->Bucket_Build = (Bucket_Build);
dst->Evaluation = (Evaluation);
dst->Malloc_Gate_Pointer = (MallocGatePointer);
dst->Malloc_Bucket_Pointer = (MallocBucketPointer);
dst->Refresh_Seed = (Refresh_Seed);

AES_set_encrypt_key(PoolPRGSeed, &(dst->Pool_PRG_Seed));

MallocGatePointer((dst->Batch_Gates_in_Pool), PoolSize, dst->ext);
MallocGatePointer((dst->Batch_Gates_in_Buffer), BufferSize, dst->ext);
MallocBucketPointer((dst->Bucket_Pointer), BucketBufferSize, dst->ext);
(*(dst->Refresh_Seed))(dst->ext, PoolPRGSeed);

dst->Bucket_Index = dst->Bucket_Size * dst->Bucket_Buffer_Size;
dst->Buffer_Index = 0;
dst->Gate_in_Buffer_Index_Array[dst->Buffer_Index] = dst->Buffer_Size + 1;
uint64_t i;
i = 0;
do
{
(*(dst->Gate_Copy))((dst->Batch_Gates_in_Pool), i, (dst->Batch_Gates_in_Buffer), Next_Gate_in_Buffer(dst), dst->ext);
i++;
} while (i < dst->Pool_Size);
return dst;
}

void Pool_Gate_Buffer_Refresh(Pool *dst)
{
(*(dst->Batch_Gates_Generation))(dst->Batch_Gates_in_Buffer, dst->Buffer_Size, dst->ext);

#ifdef ALICE
preceive((unsigned char *)&(dst->Pool_PRG_Seed), 16);
#endif

#ifdef BOB
/*
#ifndef __MACH__
//getrandom(&(dst->Pool_PRG_SeedBlock),16);
#else
//mac system needs a walkaround
#endif
*/
//user needs to setup their own randomness if necessary
psend((unsigned char *)&(dst->Pool_PRG_SeedBlock), 16);
#endif

AES_set_encrypt_key(dst->Pool_PRG_SeedBlock, &(dst->Pool_PRG_Seed));
(*(dst->Refresh_Seed))(dst->ext, dst->Pool_PRG_SeedBlock);

PRG((block *)(dst->Gate_in_Buffer_Index_Array), dst->Buffer_Size / 2, dst->Pool_PRG_Seed, &(dst->Pool_PRG_Count));
uint64_t i, j;
j = 0;
for (i = 0; i < dst->Buffer_Size; i++)
{
if (dst->Gate_in_Buffer_Index_Array[i] > dst->Check_Rate * UINT64_MAX)
{
dst->Gate_in_Buffer_Index_Array[j] = i;
j++;
}
else
{
(*(dst->Gate_Check))(dst->Batch_Gates_in_Buffer, i, dst->ext);
}
}
for (; j < dst->Buffer_Size; j++)
dst->Gate_in_Buffer_Index_Array[j] = dst->Buffer_Size + 1;
dst->Buffer_Index = 0;
}

uint64_t Next_Gate_in_Buffer(Pool *dst)
{
if (dst->Gate_in_Buffer_Index_Array[dst->Buffer_Index] >= dst->Buffer_Size)
Pool_Gate_Buffer_Refresh(dst);
dst->Buffer_Index++;
return dst->Gate_in_Buffer_Index_Array[dst->Buffer_Index - 1];
}

uint64_t Next_Bucket_Gates(Pool *dst)
{
if (dst->Bucket_Index >= dst->Bucket_Size * dst->Bucket_Buffer_Size)
{
PRG((block *)(dst->Gate_in_Bucket_Index_Array), dst->Bucket_Buffer_Size * dst->Bucket_Size / ((sizeof(block)) / sizeof(uint64_t)), dst->Pool_PRG_Seed, &(dst->Pool_PRG_Count));
dst->Bucket_Index = 0;
uint64_t i;
for (i = 0; i < dst->Bucket_Buffer_Size * dst->Bucket_Size; i++)
dst->Gate_in_Bucket_Index_Array[i] = dst->Gate_in_Bucket_Index_Array[i] % dst->Pool_Size;
}
dst->Bucket_Index += dst->Bucket_Size;
return dst->Bucket_Index - dst->Bucket_Size;
}

void Pool_Evaluation(void *dst, void *InputL, void *InputR, Pool *P)
{
uint64_t index0;
index0 = Next_Bucket_Gates(P);
(*(P->Bucket_Build))(P->Bucket_Pointer, P->Bucket_Size, P->Batch_Gates_in_Pool, &(P->Gate_in_Bucket_Index_Array[index0]), P->ext);
(*(P->Evaluation))(dst, InputL, InputR, P->Bucket_Pointer, P->Bucket_Size, P->ext);
uint64_t i;
for (i = 0; i < P->Bucket_Size; i++)
{
(*(P->Gate_Copy))((P->Batch_Gates_in_Pool), P->Gate_in_Bucket_Index_Array[index0 + i], (P->Batch_Gates_in_Buffer), Next_Gate_in_Buffer(P), P->ext);
}
}

ServiceConfig* SetupService(ServiceConfig *Service, size_t extsize,
void (*extsetup)(void *, uint64_t, block),
void (*Alice_Input)(void *, unsigned char *, uint64_t, void *),
void (*Bob_Input)(void *, unsigned char *, uint64_t, void *),
unsigned char (*Alice_Output)(void *, void *),
unsigned char (*Bob_Output)(void *, void *),
void Xor(void *, void *, void *, void *),
void Not(void *, void *, void *))
{
block Key = _mm_set_epi32(1, 2, 3, 4);
Service->ext = _mm_malloc(extsize, 32);
Service->extsetup = (extsetup);
Service->Alice_Input = (Alice_Input);
Service->Bob_Input = (Bob_Input);
Service->Alice_Output = (Alice_Output);
Service->Bob_Output = (Bob_Output);
Service->Xor = (Xor);
Service->Not = (Not);

extsetup((Service->ext), 1024, Key);
Service->And_Pool.ext[0] = Service->ext;
Service->Mux_Pool.ext[0] = Service->ext;
return Service;
}
