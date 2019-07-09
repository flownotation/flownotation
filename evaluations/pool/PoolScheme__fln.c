typedef int va_list;
typedef int size_t;
typedef int __builtin_va_list;
typedef int __gnuc_va_list;
typedef int __int8_t;
typedef int __uint8_t;
typedef int __int16_t;
typedef int __uint16_t;
typedef int __int_least16_t;
typedef int __uint_least16_t;
typedef int __int32_t;
typedef int __uint32_t;
typedef int __int64_t;
typedef int __uint64_t;
typedef int __int_least32_t;
typedef int __uint_least32_t;
typedef int __s8;
typedef int __u8;
typedef int __s16;
typedef int __u16;
typedef int __s32;
typedef int __u32;
typedef int __s64;
typedef int __u64;
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
typedef int _off_t;
typedef int __dev_t;
typedef int __uid_t;
typedef int __gid_t;
typedef int _off64_t;
typedef int _fpos_t;
typedef int _ssize_t;
typedef int wint_t;
typedef int _mbstate_t;
typedef int _flock_t;
typedef int _iconv_t;
typedef int __ULong;
typedef int __FILE;
typedef int ptrdiff_t;
typedef int wchar_t;
typedef int __off_t;
typedef int __pid_t;
typedef int __loff_t;
typedef int u_char;
typedef int u_short;
typedef int u_int;
typedef int u_long;
typedef int ushort;
typedef int uint;
typedef int clock_t;
typedef int time_t;
typedef int daddr_t;
typedef int caddr_t;
typedef int ino_t;
typedef int off_t;
typedef int dev_t;
typedef int uid_t;
typedef int gid_t;
typedef int pid_t;
typedef int key_t;
typedef int ssize_t;
typedef int mode_t;
typedef int nlink_t;
typedef int fd_mask;
typedef int _types_fd_set;
typedef int clockid_t;
typedef int timer_t;
typedef int useconds_t;
typedef int suseconds_t;
typedef int FILE;
typedef int fpos_t;
typedef int cookie_read_function_t;
typedef int cookie_write_function_t;
typedef int cookie_seek_function_t;
typedef int cookie_close_function_t;
typedef int cookie_io_functions_t;
typedef int div_t;
typedef int ldiv_t;
typedef int lldiv_t;
typedef int sigset_t;
typedef int __sigset_t;
typedef int _sig_func_ptr;
typedef int sig_atomic_t;
typedef int __tzrule_type;
typedef int __tzinfo_type;
typedef int mbstate_t;
typedef int sem_t;
typedef int pthread_t;
typedef int pthread_attr_t;
typedef int pthread_mutex_t;
typedef int pthread_mutexattr_t;
typedef int pthread_cond_t;
typedef int pthread_condattr_t;
typedef int pthread_key_t;
typedef int pthread_once_t;
typedef int pthread_rwlock_t;
typedef int pthread_rwlockattr_t;
typedef int pthread_spinlock_t;
typedef int pthread_barrier_t;
typedef int pthread_barrierattr_t;
typedef int jmp_buf;
typedef int rlim_t;
typedef int sa_family_t;
typedef int sigjmp_buf;
typedef int stack_t;
typedef int siginfo_t;
typedef int z_stream;
typedef int int8_t;
typedef int uint8_t;
typedef int int16_t;
typedef int uint16_t;
typedef int int32_t;
typedef int uint32_t;
typedef int int64_t;
typedef int uint64_t;
typedef int int_least8_t;
typedef int uint_least8_t;
typedef int int_least16_t;
typedef int uint_least16_t;
typedef int int_least32_t;
typedef int uint_least32_t;
typedef int int_least64_t;
typedef int uint_least64_t;
typedef int int_fast8_t;
typedef int uint_fast8_t;
typedef int int_fast16_t;
typedef int uint_fast16_t;
typedef int int_fast32_t;
typedef int uint_fast32_t;
typedef int int_fast64_t;
typedef int uint_fast64_t;
typedef int intptr_t;
typedef int uintptr_t;
typedef int intmax_t;
typedef int uintmax_t;
typedef _Bool bool;
typedef int va_list;
typedef void *MirEGLNativeWindowType;
typedef void *MirEGLNativeDisplayType;
typedef struct MirConnection MirConnection;
typedef struct MirSurface MirSurface;
typedef struct MirSurfaceSpec MirSurfaceSpec;
typedef struct MirScreencast MirScreencast;
typedef struct MirPromptSession MirPromptSession;
typedef struct MirBufferStream MirBufferStream;
typedef struct MirPersistentId MirPersistentId;
typedef struct MirBlob MirBlob;
typedef struct MirDisplayConfig MirDisplayConfig;
typedef struct xcb_connection_t xcb_connection_t;
typedef uint32_t xcb_window_t;
typedef uint32_t xcb_visualid_t;
typedef int block;
typedef struct 
{
  block rd_key[11];
  unsigned int rounds;
} AES_KEY;
inline static void AES_set_encrypt_key(const block userkey, AES_KEY *key)
{
  block x0;
  block x1;
  block x2;
  block *kp = key->rd_key;
  kp[0] = (x0 = userkey);
  x2 = _mm_setzero_si128();
  x1 = _mm_aeskeygenassist_si128(x0, 1);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[1] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[2] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 4);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[3] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 8);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[4] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 16);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[5] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 32);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[6] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 64);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[7] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 128);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[8] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 27);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[9] = x0;
  x1 = _mm_aeskeygenassist_si128(x0, 54);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 16));
  x0 = _mm_xor_si128(x0, x2);
  x2 = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(x2), _mm_castsi128_ps(x0), 140));
  x0 = _mm_xor_si128(x0, x2);
  x1 = _mm_shuffle_epi32(x1, 255);
  x0 = _mm_xor_si128(x0, x1);
  kp[10] = x0;
  key->rounds = 10;
}

inline static void AES_ecb_encrypt_blks(block *blks, unsigned int nblks, const AES_KEY *key)
{
  unsigned int i;
  unsigned int j;
  for (i = 0; i < nblks; ++i)
    blks[i] = _mm_xor_si128(blks[i], key->rd_key[0]);

  for (j = 1; j < key->rounds; ++j)
    for (i = 0; i < nblks; ++i)
    blks[i] = _mm_aesenc_si128(blks[i], key->rd_key[j]);


  for (i = 0; i < nblks; ++i)
    blks[i] = _mm_aesenclast_si128(blks[i], key->rd_key[key->rounds]);

}

inline static void AES_set_decrypt_key_fast(AES_KEY *dkey, const AES_KEY *ekey)
{
  int j = 0;
  int i = ekey->rounds;
  dkey->rounds = i;
  dkey->rd_key[i--] = ekey->rd_key[j++];
  while (i)
    dkey->rd_key[i--] = _mm_aesimc_si128(ekey->rd_key[j++]);

  dkey->rd_key[i] = ekey->rd_key[j];
}

inline static void AES_set_decrypt_key(block userkey, AES_KEY *key)
{
  AES_KEY temp_key;
  AES_set_encrypt_key(userkey, &temp_key);
  AES_set_decrypt_key_fast(key, &temp_key);
}

inline static void AES_ecb_decrypt_blks(block *blks, unsigned nblks, const AES_KEY *key)
{
  unsigned i;
  unsigned j;
  unsigned rnds = key->rounds;
  for (i = 0; i < nblks; ++i)
    blks[i] = _mm_xor_si128(blks[i], key->rd_key[0]);

  for (j = 1; j < rnds; ++j)
    for (i = 0; i < nblks; ++i)
    blks[i] = _mm_aesdec_si128(blks[i], key->rd_key[j]);


  for (i = 0; i < nblks; ++i)
    blks[i] = _mm_aesdeclast_si128(blks[i], key->rd_key[j]);

}

inline static void PRG(block *dst, unsigned int n, AES_KEY seed, uint64_t *count)
{
  uint64_t i;
  block *tmp;
  tmp = _mm_malloc((sizeof(block)) * n, 32);
  for (i = *count; i < (n + (*count)); i++)
  {
    dst[i - (*count)] = _mm_set_epi64x(i, i);
  }

  *count += n;
  memcpy(tmp, dst, n * 16);
  AES_ecb_encrypt_blks(dst, n, &seed);
  for (i = 0; i < n; i++)
    dst[i] = _mm_xor_si128(dst[i], tmp[i]);

  _mm_free(tmp);
}

typedef struct OblivBit
{
  int unknown;
  union 
  {
    int knownValue;
  };
} OblivBit;
typedef struct 
{
  block Pool_PRG_SeedBlock;
  AES_KEY Pool_PRG_Seed;
  uint64_t Pool_PRG_Count;
  uint64_t Pool_Size;
  uint64_t Buffer_Size;
  double Check_Rate;
  uint64_t Bucket_Size;
  void *ext[2];
  size_t Gate_Pointer_Size;
  void *Batch_Gates_in_Pool;
  void *Batch_Gates_in_Buffer;
  uint64_t *Gate_in_Buffer_Index_Array;
  uint64_t *Gate_in_Bucket_Index_Array;
  uint64_t Buffer_Index;
  uint64_t Bucket_Index;
  uint64_t Bucket_Buffer_Size;
  size_t Bucket_Pointer_Size;
  void *Bucket_Pointer;
  void (*Batch_Gates_Generation)(void *Batch_Gates_dst, uint64_t n, void *ext[]);
  void (*Gate_Check)(void *Batch_Gates, uint64_t index, void *ext[]);
  void (*Gate_Copy)(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void *ext[]);
  void (*Evaluation)(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void *ext[]);
  void (*Malloc_Gate_Pointer)(void *dst, uint64_t size, void *ext[]);
  void (*Malloc_Bucket_Pointer)(void *dst, uint64_t size, void *ext[]);
  void (*Bucket_Build)(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void *ext[]);
  void (*Refresh_Seed)(void **ext, block SeedBlock);
} Pool;
typedef struct 
{
  Pool And_Pool;
  Pool Mux_Pool;
  size_t extsize;
  void *ext;
  void (*extsetup)(void *ext, uint64_t BufferSize, block key);
  void (*Xor)(void *dst, void *L, void *R, void *ext);
  void (*Not)(void *dst, void *L, void *ext);
  void (*Alice_Input)(void *dst, unsigned char *choice, uint64_t n, void *ext);
  void (*Bob_Input)(void *dst, unsigned char *choice, uint64_t n, void *ext);
  unsigned char (*Alice_Output)(void *bit, void *ext);
  unsigned char (*Bob_Output)(void *bit, void *ex);
} ServiceConfig;
void SetupService(ServiceConfig *Service, size_t extsize, void (*extsetup)(void *, uint64_t, block), void (*Alice_Input)(void *, unsigned char *, uint64_t, void *), void (*Bob_Input)(void *, unsigned char *, uint64_t, void *), unsigned char (*Alice_Output)(void *, void *), unsigned char (*Bob_Output)(void *, void *), void Xor(void *, void *, void *, void *), void Not(void *, void *, void *));
void SetupPool(Pool *dst, uint64_t PoolSize, uint64_t BufferSize, double CheckRate, uint64_t BucketSize, size_t Gate_Pointer_Size, size_t Bucket_Pointer_Size, uint64_t BucketBufferSize, block PoolPRGSeed, void (*Batch_Gates_Generation)(void *, uint64_t, void **), void (*Gate_Check)(void *, uint64_t, void **), void (*Gate_Copy)(void *, uint64_t, void *, uint64_t, void **), void (*Bucket_Build)(void *, uint64_t, void *, uint64_t *, void **), void (*Evaluation)(void *, void *, void *, void *, uint64_t, void **), void (*MallocGatePointer)(void *, uint64_t, void **), void (*MallocBucketPointer)(void *, uint64_t, void **), void (*Refresh_Seed)(void **, block));
void Pool_Gate_Buffer_Refresh(Pool *dst);
uint64_t Next_Gate_in_Buffer(Pool *dst);
void Pool_Evaluation(void *dst, void *InputL, void *InputR, Pool *P);
inline static void Pool_Alice_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service);
inline static void Pool_Bob_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service);
inline static unsigned char Pool_Alice_Output(OblivBit *src, ServiceConfig *Service);
inline static unsigned char Pool_Bob_Output(OblivBit *src, ServiceConfig *Service);
inline static void Pool_Alice_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service)
{
  (*Service->Alice_Input)(dst, choice, n, Service->ext);
}

inline static void Pool_Bob_Input(OblivBit *dst, unsigned char *choice, uint64_t n, ServiceConfig *Service)
{
  (*Service->Bob_Input)(dst, choice, n, Service->ext);
}

inline static unsigned char Pool_Alice_Output(OblivBit *src, ServiceConfig *Service)
{
  return (*Service->Alice_Output)(src, Service->ext);
}

inline static unsigned char Pool_Bob_Output(OblivBit *src, ServiceConfig *Service)
{
  return (*Service->Bob_Output)(src, Service->ext);
}

inline static void Service_Xor(void *dst, void *InputL, void *InputR, ServiceConfig *Service)
{
  (*Service->Xor)(dst, InputL, InputR, Service->ext);
}

inline static void Service_Not(void *dst, void *Input, ServiceConfig *Service)
{
  (*Service->Not)(dst, Input, Service->ext);
}

typedef struct 
{
  ServiceConfig d;
} __fln__initalized_serviceI_ServiceConfig;
typedef struct 
{
  Pool d;
} __fln__initalized_poolI_Pool;
typedef struct 
{
  Pool d;
} __fln__initialized_poolS_Pool;
typedef struct 
{
  uint64_t d;
} __fln__valid_gateI_uint64_t;
__fln__initalized_serviceI_ServiceConfig __fln__initalized_serviceI_ServiceConfig_intg(ServiceConfig x)
{
  __fln__initalized_serviceI_ServiceConfig y = {.d = x};
  return y;
}

__fln__initalized_serviceI_ServiceConfig *__fln__initalized_serviceI_ServiceConfig_intg_ptr(ServiceConfig *x)
{
  __fln__initalized_serviceI_ServiceConfig tmp = {.d = *x};
  __fln__initalized_serviceI_ServiceConfig *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

ServiceConfig __fln__initalized_serviceI_ServiceConfig_sec(__fln__initalized_serviceI_ServiceConfig x)
{
  return x.d;
}

ServiceConfig *__fln__initalized_serviceI_ServiceConfig_sec_ptr(__fln__initalized_serviceI_ServiceConfig *x)
{
  return &x->d;
}

__fln__initalized_poolI_Pool __fln__initalized_poolI_Pool_intg(Pool x)
{
  __fln__initalized_poolI_Pool y = {.d = x};
  return y;
}

__fln__initalized_poolI_Pool *__fln__initalized_poolI_Pool_intg_ptr(Pool *x)
{
  __fln__initalized_poolI_Pool tmp = {.d = *x};
  __fln__initalized_poolI_Pool *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

Pool __fln__initalized_poolI_Pool_sec(__fln__initalized_poolI_Pool x)
{
  return x.d;
}

Pool *__fln__initalized_poolI_Pool_sec_ptr(__fln__initalized_poolI_Pool *x)
{
  return &x->d;
}

__fln__initialized_poolS_Pool __fln__initialized_poolS_Pool_intg(Pool x)
{
  __fln__initialized_poolS_Pool y = {.d = x};
  return y;
}

__fln__initialized_poolS_Pool *__fln__initialized_poolS_Pool_intg_ptr(Pool *x)
{
  __fln__initialized_poolS_Pool tmp = {.d = *x};
  __fln__initialized_poolS_Pool *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

Pool __fln__initialized_poolS_Pool_sec(__fln__initialized_poolS_Pool x)
{
  return x.d;
}

Pool *__fln__initialized_poolS_Pool_sec_ptr(__fln__initialized_poolS_Pool *x)
{
  return &x->d;
}

__fln__valid_gateI_uint64_t __fln__valid_gateI_uint64_t_intg(uint64_t x)
{
  __fln__valid_gateI_uint64_t y = {.d = x};
  return y;
}

__fln__valid_gateI_uint64_t *__fln__valid_gateI_uint64_t_intg_ptr(uint64_t *x)
{
  __fln__valid_gateI_uint64_t tmp = {.d = *x};
  __fln__valid_gateI_uint64_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

uint64_t __fln__valid_gateI_uint64_t_sec(__fln__valid_gateI_uint64_t x)
{
  return x.d;
}

uint64_t *__fln__valid_gateI_uint64_t_sec_ptr(__fln__valid_gateI_uint64_t *x)
{
  return &x->d;
}

typedef int block;
bool Checker(long long PoolSize, double r, long long BucketSize, long long s);
typedef struct 
{
  block Pool_PRG_SeedBlock;
  AES_KEY Pool_PRG_Seed;
  uint64_t Pool_PRG_Count;
  uint64_t Pool_Size;
  uint64_t Buffer_Size;
  double Check_Rate;
  uint64_t Bucket_Size;
  void *ext[2];
  size_t Gate_Pointer_Size;
  void *Batch_Gates_in_Pool;
  void *Batch_Gates_in_Buffer;
  uint64_t *Gate_in_Buffer_Index_Array;
  uint64_t *Gate_in_Bucket_Index_Array;
  uint64_t Buffer_Index;
  uint64_t Bucket_Index;
  uint64_t Bucket_Buffer_Size;
  size_t Bucket_Pointer_Size;
  void *Bucket_Pointer;
  void (*Batch_Gates_Generation)(void *Batch_Gates_dst, uint64_t n, void *ext[]);
  void (*Gate_Check)(void *Batch_Gates, uint64_t index, void *ext[]);
  void (*Gate_Copy)(void *dstBatch, uint64_t indexd, void *srcBatch, uint64_t indexs, void *ext[]);
  void (*Evaluation)(void *Outputs, void *InputL, void *InputR, void *Bucket, uint64_t BucketSize, void *ext[]);
  void (*Malloc_Gate_Pointer)(void *dst, uint64_t size, void *ext[]);
  void (*Malloc_Bucket_Pointer)(void *dst, uint64_t size, void *ext[]);
  void (*Bucket_Build)(void *Bucket_Pointer_dst, uint64_t BucketSize, void *Batch_Gates_in_Pool, uint64_t *Gate_in_Bucket_Index_Array, void *ext[]);
  void (*Refresh_Seed)(void **ext, block SeedBlock);
} Pool;
__fln__initalized_poolI_Pool *SetupPool(Pool *dst, uint64_t PoolSize, uint64_t BufferSize, double CheckRate, uint64_t BucketSize, size_t Gate_Pointer_Size, size_t Bucket_Pointer_Size, uint64_t BucketBufferSize, block PoolPRGSeed, void (*Batch_Gates_Generation)(void *, uint64_t, void **), void (*Gate_Check)(void *, uint64_t, void **), void (*Gate_Copy)(void *, uint64_t, void *, uint64_t, void **), void (*Bucket_Build)(void *, uint64_t, void *, uint64_t *, void **), void (*Evaluation)(void *, void *, void *, void *, uint64_t, void **), void (*MallocGatePointer)(void *, uint64_t, void **), void (*MallocBucketPointer)(void *, uint64_t, void **), void (*Refresh_Seed)(void **, block))
{
  Pool dst2;
  dst->Pool_PRG_Count = 0;
  dst->Pool_Size = PoolSize;
  dst->Buffer_Size = BufferSize;
  dst->Check_Rate = CheckRate;
  dst->Bucket_Size = BucketSize;
  dst->Bucket_Buffer_Size = BucketBufferSize;
  dst->Batch_Gates_in_Pool = _mm_malloc(Gate_Pointer_Size, 32);
  dst->Batch_Gates_in_Buffer = _mm_malloc(Gate_Pointer_Size, 32);
  dst->Gate_in_Bucket_Index_Array = (uint64_t *) malloc(((sizeof(uint64_t)) * BucketBufferSize) * BucketSize);
  dst->Gate_in_Buffer_Index_Array = (uint64_t *) malloc((sizeof(uint64_t)) * BufferSize);
  dst->Bucket_Pointer = _mm_malloc(Bucket_Pointer_Size, 32);
  dst->Batch_Gates_Generation = Batch_Gates_Generation;
  dst->Gate_Check = Gate_Check;
  dst->Gate_Copy = Gate_Copy;
  dst->Bucket_Build = Bucket_Build;
  dst->Evaluation = Evaluation;
  dst->Malloc_Gate_Pointer = MallocGatePointer;
  dst->Malloc_Bucket_Pointer = MallocBucketPointer;
  dst->Refresh_Seed = Refresh_Seed;
  AES_set_encrypt_key(PoolPRGSeed, &dst->Pool_PRG_Seed);
  MallocGatePointer(dst->Batch_Gates_in_Pool, PoolSize, dst->ext);
  MallocGatePointer(dst->Batch_Gates_in_Buffer, BufferSize, dst->ext);
  MallocBucketPointer(dst->Bucket_Pointer, BucketBufferSize, dst->ext);
  (*dst->Refresh_Seed)(dst->ext, PoolPRGSeed);
  dst->Bucket_Index = dst->Bucket_Size * dst->Bucket_Buffer_Size;
  dst->Buffer_Index = 0;
  dst->Gate_in_Buffer_Index_Array[dst->Buffer_Index] = dst->Buffer_Size + 1;
  uint64_t i;
  i = 0;
  do
  {
    (*dst->Gate_Copy)(dst->Batch_Gates_in_Pool, i, dst->Batch_Gates_in_Buffer, Next_Gate_in_Buffer(dst), dst->ext);
    i++;
  }
  while (i < dst->Pool_Size);
  return __fln__initalized_poolI_Pool_intg_ptr(dst);
}

void Pool_Gate_Buffer_Refresh(__fln__initialized_poolS_Pool *dst)
{
  Pool* dst__fln_p = __fln__initialized_poolS_Pool_sec_ptr(dst);
  (*dst__fln_p->Batch_Gates_Generation)(dst__fln_p->Batch_Gates_in_Buffer, dst__fln_p->Buffer_Size, dst__fln_p->ext);
  AES_set_encrypt_key(dst__fln_p->Pool_PRG_SeedBlock, &dst__fln_p->Pool_PRG_Seed);
  (*dst__fln_p->Refresh_Seed)(dst__fln_p->ext, dst__fln_p->Pool_PRG_SeedBlock);
  PRG((block *) dst__fln_p->Gate_in_Buffer_Index_Array, dst__fln_p->Buffer_Size / 2, dst__fln_p->Pool_PRG_Seed, &dst__fln_p->Pool_PRG_Count);
  uint64_t i;
  uint64_t j;
  j = 0;
  for (i = 0; i < dst__fln_p->Buffer_Size; i++)
  {
    if (dst__fln_p->Gate_in_Buffer_Index_Array[i] > (dst__fln_p->Check_Rate * UINT64_MAX))
    {
      dst__fln_p->Gate_in_Buffer_Index_Array[j] = i;
      j++;
    }
    else
    {
      (*dst__fln_p->Gate_Check)(dst__fln_p->Batch_Gates_in_Buffer, i, dst__fln_p->ext);
    }

  }

  for (; j < dst__fln_p->Buffer_Size; j++)
    dst__fln_p->Gate_in_Buffer_Index_Array[j] = dst__fln_p->Buffer_Size + 1;

  dst__fln_p->Buffer_Index = 0;
}

__fln__valid_gateI_uint64_t Next_Gate_in_Buffer(__fln__initialized_poolS_Pool *dst)
{
  Pool* dst__fln_p = __fln__initialized_poolS_Pool_sec_ptr(dst);
  if (dst__fln_p->Gate_in_Buffer_Index_Array[dst__fln_p->Buffer_Index] >= dst__fln_p->Buffer_Size)
    Pool_Gate_Buffer_Refresh(dst__fln_p);

  dst__fln_p->Buffer_Index++;
  return __fln__valid_gateI_uint64_t_intg(dst__fln_p->Gate_in_Buffer_Index_Array[dst__fln_p->Buffer_Index - 1]);
}

uint64_t Next_Bucket_Gates(__fln__initialized_poolS_Pool *dst)
{
  Pool* dst__fln_p = __fln__initialized_poolS_Pool_sec_ptr(dst);
  if (dst__fln_p->Bucket_Index >= (dst__fln_p->Bucket_Size * dst__fln_p->Bucket_Buffer_Size))
  {
    PRG((block *) dst__fln_p->Gate_in_Bucket_Index_Array, (dst__fln_p->Bucket_Buffer_Size * dst__fln_p->Bucket_Size) / ((sizeof(block)) / (sizeof(uint64_t))), dst__fln_p->Pool_PRG_Seed, &dst__fln_p->Pool_PRG_Count);
    dst__fln_p->Bucket_Index = 0;
    uint64_t i;
    for (i = 0; i < (dst__fln_p->Bucket_Buffer_Size * dst__fln_p->Bucket_Size); i++)
      dst__fln_p->Gate_in_Bucket_Index_Array[i] = dst__fln_p->Gate_in_Bucket_Index_Array[i] % dst__fln_p->Pool_Size;

  }

  dst__fln_p->Bucket_Index += dst__fln_p->Bucket_Size;
  return dst__fln_p->Bucket_Index - dst__fln_p->Bucket_Size;
}

void Pool_Evaluation(void *dst, void *InputL, void *InputR, Pool *P)
{
  uint64_t index0;
  index0 = Next_Bucket_Gates(P);
  (*P->Bucket_Build)(P->Bucket_Pointer, P->Bucket_Size, P->Batch_Gates_in_Pool, &P->Gate_in_Bucket_Index_Array[index0], P->ext);
  (*P->Evaluation)(dst, InputL, InputR, P->Bucket_Pointer, P->Bucket_Size, P->ext);
  uint64_t i;
  for (i = 0; i < P->Bucket_Size; i++)
  {
    (*P->Gate_Copy)(P->Batch_Gates_in_Pool, P->Gate_in_Bucket_Index_Array[index0 + i], P->Batch_Gates_in_Buffer, Next_Gate_in_Buffer(P), P->ext);
  }

}

__fln__initalized_serviceI_ServiceConfig *SetupService(ServiceConfig *Service, size_t extsize, void (*extsetup)(void *, uint64_t, block), void (*Alice_Input)(void *, unsigned char *, uint64_t, void *), void (*Bob_Input)(void *, unsigned char *, uint64_t, void *), unsigned char (*Alice_Output)(void *, void *), unsigned char (*Bob_Output)(void *, void *), void Xor(void *, void *, void *, void *), void Not(void *, void *, void *))
{
  block Key = _mm_set_epi32(1, 2, 3, 4);
  Service->ext = _mm_malloc(extsize, 32);
  Service->extsetup = extsetup;
  Service->Alice_Input = Alice_Input;
  Service->Bob_Input = Bob_Input;
  Service->Alice_Output = Alice_Output;
  Service->Bob_Output = Bob_Output;
  Service->Xor = Xor;
  Service->Not = Not;
  extsetup(Service->ext, 1024, Key);
  Service->And_Pool.ext[0] = Service->ext;
  Service->Mux_Pool.ext[0] = Service->ext;
  return __fln__initalized_serviceI_ServiceConfig_intg_ptr(Service);
}

