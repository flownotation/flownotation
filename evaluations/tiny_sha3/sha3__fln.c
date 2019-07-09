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
typedef struct 
{
  union 
  {
    uint8_t b[200];
    uint64_t q[25];
  } st;
  int pt;
  int rsiz;
  int mdlen;
} sha3_ctx_t;
void sha3_keccakf(uint64_t st[25]);
int sha3_init(sha3_ctx_t *c, int mdlen);
int sha3_update(sha3_ctx_t *c, const void *data, size_t len);
int sha3_final(void *md, sha3_ctx_t *c);
void *sha3(const void *in, size_t inlen, void *md, int mdlen);
void shake_xof(sha3_ctx_t *c);
void shake_out(sha3_ctx_t *c, void *out, size_t len);
typedef struct 
{
  sha3_ctx_t d;
} __fln__sha3_initS_sha3_ctx_t;
typedef struct 
{
  sha3_ctx_t d;
} __fln__sha3_updatedS_sha3_ctx_t;
typedef struct 
{
  sha3_ctx_t d;
} __fln__sha3_uninitS_sha3_ctx_t;
typedef struct 
{
  sha3_ctx_t d;
} __fln__sha3_initS_sha3_updatedS_sha3_ctx_t;
typedef struct 
{
  sha3_ctx_t d;
} __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t;
__fln__sha3_initS_sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_intg(sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_ctx_t y = {.d = x};
  return y;
}

__fln__sha3_initS_sha3_ctx_t *__fln__sha3_initS_sha3_ctx_t_intg_ptr(sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_ctx_t tmp = {.d = *x};
  __fln__sha3_initS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_sec(__fln__sha3_initS_sha3_ctx_t x)
{
  return x.d;
}

sha3_ctx_t *__fln__sha3_initS_sha3_ctx_t_sec_ptr(__fln__sha3_initS_sha3_ctx_t *x)
{
  return &x->d;
}

__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x)
{
  __fln__sha3_updatedS_sha3_ctx_t y = {.d = x};
  return y;
}

__fln__sha3_updatedS_sha3_ctx_t *__fln__sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t *x)
{
  __fln__sha3_updatedS_sha3_ctx_t tmp = {.d = *x};
  __fln__sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_updatedS_sha3_ctx_t x)
{
  return x.d;
}

sha3_ctx_t *__fln__sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_updatedS_sha3_ctx_t *x)
{
  return &x->d;
}

__fln__sha3_uninitS_sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_intg(sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_ctx_t y = {.d = x};
  return y;
}

__fln__sha3_uninitS_sha3_ctx_t *__fln__sha3_uninitS_sha3_ctx_t_intg_ptr(sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_ctx_t tmp = {.d = *x};
  __fln__sha3_uninitS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_sec(__fln__sha3_uninitS_sha3_ctx_t x)
{
  return x.d;
}

sha3_ctx_t *__fln__sha3_uninitS_sha3_ctx_t_sec_ptr(__fln__sha3_uninitS_sha3_ctx_t *x)
{
  return &x->d;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w(__fln__sha3_uninitS_sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w_ptr(__fln__sha3_uninitS_sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_uninitS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_uninitS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_uninitS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w(__fln__sha3_initS_sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w_ptr(__fln__sha3_initS_sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x};
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = *x};
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  return x.d;
}

sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  return &x->d;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x};
  return y;
}

__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t *x)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = *x};
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  return x.d;
}

sha3_ctx_t *__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  return &x->d;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w(__fln__sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w_ptr(__fln__sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w(__fln__sha3_initS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w_ptr(__fln__sha3_initS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w(__fln__sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w_ptr(__fln__sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x)
{
  __fln__sha3_updatedS_sha3_ctx_t y = {.d = x.d};
  return y;
}

__fln__sha3_updatedS_sha3_ctx_t *__fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t *x)
{
  __fln__sha3_updatedS_sha3_ctx_t tmp = {.d = x->d};
  __fln__sha3_updatedS_sha3_ctx_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

typedef struct sha3_ctx_t;
void sha3_keccakf(uint64_t st[25])
{
  const uint64_t keccakf_rndc[24] = {0x0000000000000001, 0x0000000000008082, 0x800000000000808a, 0x8000000080008000, 0x000000000000808b, 0x0000000080000001, 0x8000000080008081, 0x8000000000008009, 0x000000000000008a, 0x0000000000000088, 0x0000000080008009, 0x000000008000000a, 0x000000008000808b, 0x800000000000008b, 0x8000000000008089, 0x8000000000008003, 0x8000000000008002, 0x8000000000000080, 0x000000000000800a, 0x800000008000000a, 0x8000000080008081, 0x8000000000008080, 0x0000000080000001, 0x8000000080008008};
  const int keccakf_rotc[24] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44};
  const int keccakf_piln[24] = {10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1};
  int i;
  int j;
  int r;
  uint64_t t;
  uint64_t bc[5];
  for (r = 0; r < 24; r++)
  {
    for (i = 0; i < 5; i++)
      bc[i] = (((st[i] ^ st[i + 5]) ^ st[i + 10]) ^ st[i + 15]) ^ st[i + 20];

    for (i = 0; i < 5; i++)
    {
      t = bc[(i + 4) % 5] ^ ((bc[(i + 1) % 5] << 1) | (bc[(i + 1) % 5] >> (64 - 1)));
      for (j = 0; j < 25; j += 5)
        st[j + i] ^= t;

    }

    t = st[1];
    for (i = 0; i < 24; i++)
    {
      j = keccakf_piln[i];
      bc[0] = st[j];
      st[j] = (t << keccakf_rotc[i]) | (t >> (64 - keccakf_rotc[i]));
      t = bc[0];
    }

    for (j = 0; j < 25; j += 5)
    {
      for (i = 0; i < 5; i++)
        bc[i] = st[j + i];

      for (i = 0; i < 5; i++)
        st[j + i] ^= (~bc[(i + 1) % 5]) & bc[(i + 2) % 5];

    }

    st[0] ^= keccakf_rndc[r];
  }

}

__fln__sha3_initS_sha3_ctx_t *sha3_init(__fln__sha3_uninitS_sha3_ctx_t *c, int mdlen)
{
  sha3_ctx_t* c__fln_p = __fln__sha3_uninitS_sha3_ctx_t_sec_ptr(c);
  int i;
  for (i = 0; i < 25; i++)
    c__fln_p->st.q[i] = 0;

  c__fln_p->mdlen = mdlen;
  c__fln_p->rsiz = 200 - (2 * mdlen);
  c__fln_p->pt = 0;
  return __fln__sha3_initS_sha3_ctx_t_intg_ptr(c__fln_p);
}

__fln__sha3_updatedS_sha3_ctx_t *sha3_update(__fln__sha3_initS_sha3_ctx_t *c, const void *data, size_t len)
{
  sha3_ctx_t* c__fln_p = __fln__sha3_initS_sha3_ctx_t_sec_ptr(c);
  size_t i;
  int j;
  j = c__fln_p->pt;
  for (i = 0; i < len; i++)
  {
    c__fln_p->st.b[j++] ^= ((const uint8_t *) data)[i];
    if (j >= c__fln_p->rsiz)
    {
      sha3_keccakf(c__fln_p->st.q);
      j = 0;
    }

  }

  c__fln_p->pt = j;
  return __fln__sha3_updatedS_sha3_ctx_t_intg_ptr(c__fln_p);
}

int sha3_final(void *md, __fln__sha3_updatedS_sha3_ctx_t *c)
{
  sha3_ctx_t* c__fln_p = __fln__sha3_updatedS_sha3_ctx_t_sec_ptr(c);
  int i;
  c__fln_p->st.b[c__fln_p->pt] ^= 0x06;
  c__fln_p->st.b[c__fln_p->rsiz - 1] ^= 0x80;
  sha3_keccakf(c__fln_p->st.q);
  for (i = 0; i < c__fln_p->mdlen; i++)
  {
    ((uint8_t *) md)[i] = c__fln_p->st.b[i];
  }

  return 1;
}

void *sha3(const void *in, size_t inlen, void *md, int mdlen)
{
  __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t *sha3;
  __fln__sha3_uninitS_sha3_ctx_t* sha3__fln_h = __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(sha3);
  __fln__sha3_initS_sha3_ctx_t* sha3__fln_s = sha3_init(sha3__fln_h, mdlen);
  __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* sha3__fln_t = __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w_ptr(sha3__fln_s);
  __fln__sha3_initS_sha3_ctx_t* sha3__fln_t__fln_h = __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(sha3__fln_t);
  __fln__sha3_updatedS_sha3_ctx_t* sha3__fln_t__fln_s = sha3_update(sha3__fln_t__fln_h, in, inlen);
  sha3_final(md, sha3__fln_t__fln_s);
  return md;
}

void shake_xof(sha3_ctx_t *c)
{
  c->st.b[c->pt] ^= 0x1F;
  c->st.b[c->rsiz - 1] ^= 0x80;
  sha3_keccakf(c->st.q);
  c->pt = 0;
}

void shake_out(sha3_ctx_t *c, void *out, size_t len)
{
  size_t i;
  int j;
  j = c->pt;
  for (i = 0; i < len; i++)
  {
    if (j >= c->rsiz)
    {
      sha3_keccakf(c->st.q);
      j = 0;
    }

    ((uint8_t *) out)[i] = c->st.b[j++];
  }

  c->pt = j;
}

int main()
{
  return 0;
}

