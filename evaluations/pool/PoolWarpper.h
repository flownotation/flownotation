//
//  PoolWarpper.h
//
//
//  Created by Sourgroup on 9/11/17.
//
//

#ifndef PoolWarpper_h
#define PoolWarpper_h
#include "block.h"
#include "aes.h"
#include "PRG.h"
// #include "InputProcess.h"
// #include "BatchMuxBucketProcess.h"

#ifdef ALICE
/**
 * @brief Type warp up for Alice
 *
 */
typedef Wire OblivBit;
#endif
#ifdef BOB
/**
 * @brief Type warp up for Bob
 *
 */
typedef WireE OblivBit;
#endif

/**
 * @brief Extra information needed by the underlying protocol.
 *
 */

typedef struct
{
    InputSet Input_Set;        /**< Input Setup*/
    block Seed;                /**< Random Seed */
    AES_KEY PoolKey;           /**< Extended Random Sed*/
    unsigned char *CheckArray; /**< Here stores the randomness used for check gates*/
    uint64_t index, CheckArraySize, Count;
} PoolExt;
#ifdef ALICE
enum
{
    And_Gate_Pointer_Size = sizeof(BatchGate),
    And_Bucket_Pointer_Size = sizeof(BatchBucket),
    Mux_Gate_Pointer_Size = sizeof(BatchMuxCore),
    Mux_Bucket_Pointer_Size = sizeof(BMCBucket),
    Extsize = sizeof(PoolExt),
    BufferSize = 1024
};
#endif

#ifdef BOB
enum
{
    And_Gate_Pointer_Size = sizeof(BatchGate),
    And_Bucket_Pointer_Size = sizeof(BatchBucket),
    Mux_Gate_Pointer_Size = sizeof(BatchMuxCore),
    Mux_Bucket_Pointer_Size = sizeof(BMCBucket),
    Extsize = sizeof(PoolExt),
    BufferSize = 1024
};
#endif

static inline void Batch_Gates_Generation_For_And_Pool(void *Batch_Gates_dst, uint64_t n, void **Ext);
static inline void Batch_Gates_Generation_For_Mux_Pool(void *Batch_Gates_dst, uint64_t n, void **Ext);
static inline void Gate_Check_For_And_Pool(void *Batch_Gate, uint64_t index, void **Ext);
static inline void Gate_Check_For_Mux_Pool(void *Batch_Gate, uint64_t index, void **Ext);
static inline void Gate_Copy_For_And_Pool(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void **Ext);
static inline void Gate_Copy_For_Mux_Pool(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void **Ext);
static inline void Bucket_Build_For_And_Pool(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void **Ext);
static inline void Bucket_Build_For_Mux_Pool(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void **Ext);
static inline void Evaluation_For_And_Pool(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void **Ext);
static inline void Evaluation_For_Mux_Pool(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void **Ext);
static inline void Malloc_Gate_Pointer_For_And_Pool(void *dst, uint64_t size, void **Ext);
static inline void Malloc_Gate_Pointer_For_Mux_Pool(void *dst, uint64_t size, void **Ext);
static inline void Malloc_Bucket_Pointer_For_And_Pool(void *dst, uint64_t size, void **Ext);
static inline void Malloc_Bucket_Pointer_For_Mux_Pool(void *dst, uint64_t size, void **Ext);
static inline void Extsetup(void *Ext, uint64_t BufferSize1, block SeedBlock);
static inline void Refresh_Seed(void **Ext, block SeedBlock);
static inline void Xor_For_Pool(void *dst, void *L, void *R, void *Ext);
static inline void Not_For_Pool(void *dst, void *L, void *Ext);

static inline void Refresh_Random_Tape(PoolExt *Ext)
{
    PRG((block *)(Ext->CheckArray), (Ext->CheckArraySize) / 16, (Ext->PoolKey), &(Ext->Count));
    Ext->index = 0;
}

static inline void Batch_Gates_Generation_For_And_Pool(void *Batch_Gates_dst, uint64_t n, void **Ext)
{
    BatchGateGeneration((BatchGate *)Batch_Gates_dst, n, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Batch_Gates_Generation_For_Mux_Pool(void *Batch_Gates_dst, uint64_t n, void **Ext)
{
    BatchMuxGeneration((BatchMuxCore *)Batch_Gates_dst, n, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Gate_Check_For_And_Pool(void *Batch_Gate, uint64_t index, void **Ext)
{
    BGRef Ref;
    Ref.BG = (BatchGate *)Batch_Gate;
    Ref.ID = index;
    unsigned char x[2];
    uint64_t i;
    i = ((PoolExt *)(Ext[0]))->index;
    if (i < ((PoolExt *)(Ext[0]))->CheckArraySize)
    {
        Refresh_Random_Tape((PoolExt *)(Ext[0]));
        i = ((PoolExt *)(Ext[0]))->index;
    }
    x[0] = (((PoolExt *)(Ext[0]))->CheckArray[i]) % 2;
    x[1] = ((((PoolExt *)(Ext[0]))->CheckArray[i]) / 2) % 2;
    BatchGateCheck(&Ref, x[0], x[1], &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
    ((PoolExt *)(Ext[0]))->index++;
}
static inline void Gate_Check_For_Mux_Pool(void *Batch_Gate, uint64_t index, void **Ext)
{
    BMCRef Ref;
    Ref.BMC = (BatchMuxCore *)Batch_Gate;
    Ref.ID = index;
    unsigned char x[2];
    uint64_t i;
    i = ((PoolExt *)(Ext[0]))->index;
    if (i < ((PoolExt *)(Ext[0]))->CheckArraySize)
    {
        Refresh_Random_Tape((PoolExt *)(Ext[0]));
        i = ((PoolExt *)(Ext[0]))->index;
    }
    x[0] = (((PoolExt *)(Ext[0]))->CheckArray[i]) % 2;
    x[1] = ((((PoolExt *)(Ext[0]))->CheckArray[i]) / 2) % 2;
    BatchMuxCheck(&Ref, x[0], x[1], &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
    ((PoolExt *)(Ext[0]))->index++;
}

static inline void Gate_Copy_For_And_Pool(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void **Ext)
{
    BGRef dstref, srcref;
    dstref.BG = (BatchGate *)dstBatch;
    srcref.BG = (BatchGate *)srcBatch;
    dstref.ID = indexd;
    srcref.ID = indexs;
    CopyBatchGate(&dstref, &srcref);
}

static inline void Gate_Copy_For_Mux_Pool(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void **Ext)
{
    BMCRef dstref, srcref;
    dstref.BMC = (BatchMuxCore *)dstBatch;
    srcref.BMC = (BatchMuxCore *)srcBatch;
    dstref.ID = indexd;
    srcref.ID = indexs;
    BMCCopy(&dstref, &srcref);
}

static inline void Bucket_Build_For_And_Pool(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void **Ext)
{
    int i;
    for (i = 0; i < BucketSize; i++)
    {
        ((BatchBucket *)Bucket_Pointer_dst)->G[i].BG = (BatchGate *)Batch_Gates_in_Pool;
        ((BatchBucket *)Bucket_Pointer_dst)->G[i].ID = Gate_in_Bucket_Index_Array[i];
    }
    BatchBucketInnerSoldering((BatchBucket *)Bucket_Pointer_dst, BucketSize, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Bucket_Build_For_Mux_Pool(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void **Ext)
{
    int i;
    for (i = 0; i < BucketSize; i++)
    {
        ((BMCBucket *)Bucket_Pointer_dst)->BMC[i].BMC = (BatchMuxCore *)Batch_Gates_in_Pool;
        ((BMCBucket *)Bucket_Pointer_dst)->BMC[i].ID = Gate_in_Bucket_Index_Array[i];
    }
    BMCIBSoldering((BMCBucket *)Bucket_Pointer_dst, BucketSize, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Evaluation_For_And_Pool(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void **Ext)
{
#ifdef ALICE
    BatchBucketOuterSoldering(*((Wire *)InputL), *((Wire *)InputR), (BatchBucket *)Bucket, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
#endif
#ifdef BOB
    BatchBucketOuterSoldering(((WireE *)InputL)->W, ((WireE *)InputR)->W, (BatchBucket *)Bucket, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
#endif
    BatchBucketEval((OblivBit *)Outputs, (BatchBucket *)Bucket, *((OblivBit *)InputL), *((OblivBit *)InputR), BucketSize, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Evaluation_For_Mux_Pool(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void **Ext)
{
    BMCBucketEval((BMCBucket *)Bucket, BucketSize, ((OblivBit *)InputL), *((OblivBit *)InputR), (OblivBit *)Outputs, &(((PoolExt *)(Ext[0]))->Input_Set.Gate_Set));
}

static inline void Malloc_Gate_Pointer_For_And_Pool(void *dst, uint64_t size, void **Ext)
{
    MallocBatchGate((BatchGate *)dst, size);
}

static inline void Malloc_Gate_Pointer_For_Mux_Pool(void *dst, uint64_t size, void **Ext)
{
    MallocBatchMuxCore((BatchMuxCore *)dst, *((uint64_t *)(Ext[1])), size);
}

static inline void Malloc_Bucket_Pointer_For_And_Pool(void *dst, uint64_t size, void **Ext)
{
    MallocBatchBucket((BatchBucket *)dst, size, 1);
}

static inline void Malloc_Bucket_Pointer_For_Mux_Pool(void *dst, uint64_t size, void **Ext)
{
    MallocBMCB((BMCBucket *)dst, *((uint64_t *)(Ext[1])), size, 1);
}

static inline void Extsetup(void *Ext, uint64_t BufferSize1, block SeedBlock)
{
    ((PoolExt *)(Ext))->CheckArray = malloc(sizeof(unsigned char) * BufferSize);
    ((PoolExt *)(Ext))->index = 0;
    ((PoolExt *)(Ext))->Count = 0;
    ((PoolExt *)(Ext))->CheckArraySize = BufferSize;
    InputSetup(&(((PoolExt *)(Ext))->Input_Set), SeedBlock);
}

static inline void Refresh_Seed(void **Ext, block SeedBlock)
{
    ((PoolExt *)(Ext[0]))->Seed = SeedBlock;
    AES_set_encrypt_key(SeedBlock, &(((PoolExt *)(Ext[0]))->PoolKey));
}

static inline void Alice_Input_For_Service(void *dst, unsigned char *choice, uint64_t n, void *Ext)
{
#ifdef ALICE
    AliceInput((Wire *)dst, choice, n, &(((PoolExt *)(Ext))->Input_Set));
#endif
#ifdef BOB
    AliceInput((WireE *)dst, n, &(((PoolExt *)(Ext))->Input_Set));
#endif
}

static inline void Bob_Input_For_Service(void *dst, unsigned char *choice, uint64_t n, void *Ext)
{
#ifdef ALICE
    BobInput((Wire *)dst, n, &(((PoolExt *)(Ext))->Input_Set));
#endif
#ifdef BOB
    BobInput((WireE *)dst, choice, n, &(((PoolExt *)(Ext))->Input_Set));
#endif
}

static inline unsigned char Alice_Output_For_Service(void *bit, void *Ext)
{
#ifdef ALICE
    return AliceOutput(*((Wire *)bit), &(((PoolExt *)(Ext))->Input_Set));
#endif
#ifdef BOB
    return AliceOutput(*((WireE *)bit), &(((PoolExt *)(Ext))->Input_Set));
#endif
}

static inline unsigned char Bob_Output_For_Service(void *bit, void *Ext)
{
#ifdef ALICE
    return BobOutput(*((Wire *)bit), &(((PoolExt *)(Ext))->Input_Set));
#endif
#ifdef BOB
    return BobOutput(*((WireE *)bit), &(((PoolExt *)(Ext))->Input_Set));
#endif
}
static inline void Xor_For_Pool(void *dst, void *L, void *R, void *Ext)
{
    *((OblivBit *)dst) = XorGate(*((OblivBit *)L), *((OblivBit *)R));
}
static inline void Not_For_Pool(void *dst, void *L, void *Ext)
{
    *((OblivBit *)dst) = NotGate(*((OblivBit *)L), &(((PoolExt *)Ext)->Input_Set.Gate_Set));
}
#endif /* PoolWarpper_h */
