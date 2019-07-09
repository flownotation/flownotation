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
  int d;
} __fln__no_prvkey_sigI_int;
typedef struct 
{
  int d;
} __fln__check_lenI_int;
typedef struct 
{
  int d;
} __fln__no_prvkey_autI_int;
typedef struct 
{
  const uint8_t d;
} __fln__check_valid_ptrI_const_uint8_t;
typedef struct 
{
  int d;
} __fln__no_prvkey_decI_int;
typedef struct 
{
  int d;
} __fln__no_prvkey_decI_no_prvkey_autI_int;
typedef struct 
{
  int d;
} __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int;
__fln__no_prvkey_sigI_int __fln__no_prvkey_sigI_int_intg(int x)
{
  __fln__no_prvkey_sigI_int y = {.d = x};
  return y;
}

__fln__no_prvkey_sigI_int *__fln__no_prvkey_sigI_int_intg_ptr(int *x)
{
  __fln__no_prvkey_sigI_int tmp = {.d = *x};
  __fln__no_prvkey_sigI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__no_prvkey_sigI_int_sec(__fln__no_prvkey_sigI_int x)
{
  return x.d;
}

int *__fln__no_prvkey_sigI_int_sec_ptr(__fln__no_prvkey_sigI_int *x)
{
  return &x->d;
}

__fln__check_lenI_int __fln__check_lenI_int_intg(int x)
{
  __fln__check_lenI_int y = {.d = x};
  return y;
}

__fln__check_lenI_int *__fln__check_lenI_int_intg_ptr(int *x)
{
  __fln__check_lenI_int tmp = {.d = *x};
  __fln__check_lenI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__check_lenI_int_sec(__fln__check_lenI_int x)
{
  return x.d;
}

int *__fln__check_lenI_int_sec_ptr(__fln__check_lenI_int *x)
{
  return &x->d;
}

__fln__no_prvkey_autI_int __fln__no_prvkey_autI_int_intg(int x)
{
  __fln__no_prvkey_autI_int y = {.d = x};
  return y;
}

__fln__no_prvkey_autI_int *__fln__no_prvkey_autI_int_intg_ptr(int *x)
{
  __fln__no_prvkey_autI_int tmp = {.d = *x};
  __fln__no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__no_prvkey_autI_int_sec(__fln__no_prvkey_autI_int x)
{
  return x.d;
}

int *__fln__no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_autI_int *x)
{
  return &x->d;
}

__fln__check_valid_ptrI_const_uint8_t __fln__check_valid_ptrI_const_uint8_t_intg(const uint8_t x)
{
  __fln__check_valid_ptrI_const_uint8_t y = {.d = x};
  return y;
}

__fln__check_valid_ptrI_const_uint8_t *__fln__check_valid_ptrI_const_uint8_t_intg_ptr(const uint8_t *x)
{
  __fln__check_valid_ptrI_const_uint8_t tmp = {.d = *x};
  __fln__check_valid_ptrI_const_uint8_t *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const uint8_t __fln__check_valid_ptrI_const_uint8_t_sec(__fln__check_valid_ptrI_const_uint8_t x)
{
  return x.d;
}

const uint8_t *__fln__check_valid_ptrI_const_uint8_t_sec_ptr(__fln__check_valid_ptrI_const_uint8_t *x)
{
  return &x->d;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_w(__fln__no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_w_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_w(__fln__no_prvkey_sigI_int x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_w_ptr(__fln__no_prvkey_sigI_int *x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_sigI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_sigI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_sigI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_sigI_int tmp = {.d = x->d};
  __fln__no_prvkey_sigI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_w(__fln__no_prvkey_decI_int x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_w_ptr(__fln__no_prvkey_decI_int *x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_decI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_decI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_int __fln__no_prvkey_decI_int_intg(int x)
{
  __fln__no_prvkey_decI_int y = {.d = x};
  return y;
}

__fln__no_prvkey_decI_int *__fln__no_prvkey_decI_int_intg_ptr(int *x)
{
  __fln__no_prvkey_decI_int tmp = {.d = *x};
  __fln__no_prvkey_decI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__no_prvkey_decI_int_sec(__fln__no_prvkey_decI_int x)
{
  return x.d;
}

int *__fln__no_prvkey_decI_int_sec_ptr(__fln__no_prvkey_decI_int *x)
{
  return &x->d;
}

__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_intg(int x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int y = {.d = x};
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_intg_ptr(int *x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int tmp = {.d = *x};
  __fln__no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__no_prvkey_decI_no_prvkey_autI_int_sec(__fln__no_prvkey_decI_no_prvkey_autI_int x)
{
  return x.d;
}

int *__fln__no_prvkey_decI_no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int *x)
{
  return &x->d;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_intg(int x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = {.d = x};
  return y;
}

__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_intg_ptr(int *x)
{
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = {.d = *x};
  __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_sec(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x)
{
  return x.d;
}

int *__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int *x)
{
  return &x->d;
}

__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_tail_w(__fln__no_prvkey_autI_int x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_tail_w_ptr(__fln__no_prvkey_autI_int *x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_tail_r(__fln__no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_tail_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_fst_w(__fln__no_prvkey_decI_int x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_fst_w_ptr(__fln__no_prvkey_decI_int *x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_int __fln__no_prvkey_decI_no_prvkey_autI_int_fst_r(__fln__no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_decI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_fst_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_decI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_snd_w(__fln__no_prvkey_autI_int x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_decI_no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_snd_w_ptr(__fln__no_prvkey_autI_int *x)
{
  __fln__no_prvkey_decI_no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_decI_no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_snd_r(__fln__no_prvkey_decI_no_prvkey_autI_int x)
{
  __fln__no_prvkey_autI_int y = {.d = x.d};
  return y;
}

__fln__no_prvkey_autI_int *__fln__no_prvkey_decI_no_prvkey_autI_int_snd_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int *x)
{
  __fln__no_prvkey_autI_int tmp = {.d = x->d};
  __fln__no_prvkey_autI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

static uint8_t *res_p;
static const uint8_t *do_ptr[1];
static void copy_tag(uint16_t tag)
{
  return;
}

void flash_do_release(const uint8_t *do_data)
{
  return;
}

void gpg_do_write_simple(uint8_t nr, const uint8_t *data, int size)
{
  return;
}

void ac_reset_admin(void)
{
  return;
}

void ac_reset_pso_cds(void)
{
  return;
}

void ac_reset_other(void)
{
  return;
}

const uint8_t *flash_do_write(uint8_t nr, const uint8_t *data, int len)
{
  return data;
}

__fln__check_lenI_int assign_len(int old, int new)
{
  if (new >= 0)
  {
    old = new;
  }
  else
  {
    return __fln__check_lenI_int_intg(0);
  }

}

static void copy_do_1(uint16_t tag, __fln__check_valid_ptrI_const_uint8_t *do_data, int with_tag)
{
  const uint8_t* do_data__fln_p = __fln__check_valid_ptrI_const_uint8_t_sec_ptr(do_data);
  __fln__check_lenI_int len;
  if (with_tag)
  {
    copy_tag(tag);
    if (do_data__fln_p[0] >= 128)
      *(res_p++) = 0x81;

    int tmp = do_data__fln_p[0] + 1;
    len = assign_len(__fln__check_lenI_int_sec(len), tmp);
  }
  else
  {
    int tmp = do_data__fln_p[0];
    len = assign_len(__fln__check_lenI_int_sec(len), tmp);
    do_data__fln_p++;
  }

  memcpy(res_p, do_data__fln_p, __fln__check_lenI_int_sec(len));
  res_p += len;
}

const uint8_t *check_do_ptr(const uint8_t *do_ptr)
{
  if (do_ptr)
  {
    return do_ptr;
  }
  else
  {
    return 0;
  }

}

__fln__no_prvkey_sigI_int check_prvkey_sig(int no_key_invar, uint8_t prvkey_sig)
{
  if (prvkey_sig)
  {
    return __fln__no_prvkey_sigI_int_intg(0);
  }
  else
  {
    return __fln__no_prvkey_sigI_int_intg(no_key_invar);
  }

}

__fln__no_prvkey_decI_int check_prvkey_dec(__fln__no_prvkey_sigI_int no_key_invar, uint8_t prvkey_dec)
{
  int no_key_invar__fln_p = __fln__no_prvkey_sigI_int_sec(no_key_invar);
  if (prvkey_dec)
  {
    return __fln__no_prvkey_decI_int_intg(0);
  }
  else
  {
    return __fln__no_prvkey_decI_int_intg(no_key_invar__fln_p);
  }

}

__fln__no_prvkey_autI_int check_prvkey_aut(__fln__no_prvkey_decI_int no_key_invar, uint8_t prvkey_aut)
{
  int no_key_invar__fln_p = __fln__no_prvkey_decI_int_sec(no_key_invar);
  if (prvkey_aut)
  {
    return __fln__no_prvkey_autI_int_intg(0);
  }
  else
  {
    return __fln__no_prvkey_autI_int_intg(no_key_invar__fln_p);
  }

}

int prvkey_aut_to_bool(__fln__no_prvkey_autI_int no_key_invar)
{
  int no_key_invar__fln_p = __fln__no_prvkey_autI_int_sec(no_key_invar);
  if (no_key_invar__fln_p)
  {
    return 0;
  }
  else
  {
    return 1;
  }

}

static int rw_kdf(uint16_t tag, int with_tag, const uint8_t *data, int len, int is_write)
{
  if (tag != 1)
    return 0;

  if (is_write)
  {
    const uint8_t **do_data_p = (const uint8_t **) (&do_ptr[1]);
    __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int no_key_invar;
    if (prvkey_aut_to_bool(check_prvkey_aut(check_prvkey_dec(check_prvkey_sig(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_sec(no_key_invar), do_ptr[1]), do_ptr[1]), do_ptr[1])))
    {
    }
    else
    {
      return 0;
    }

    if (!(((len == 0) || ((len == 90) && ((((((data[0] == 0x81) && (data[3] == 0x82)) && (data[6] == 0x83)) && (data[12] == 0x84)) && (data[22] == 0x87)) && (data[56] == 0x88)))) || ((len == 110) && ((((((((data[0] == 0x81) && (data[3] == 0x82)) && (data[6] == 0x83)) && (data[12] == 0x84)) && (data[22] == 0x85)) && (data[32] == 0x86)) && (data[42] == 0x87)) && (data[76] == 0x88)))))
      return 0;

    if (*do_data_p)
      flash_do_release(*do_data_p);

    gpg_do_write_simple(1, 0, 0);
    gpg_do_write_simple(1, 0, 0);
    gpg_do_write_simple(1, 0, 0);
    ac_reset_admin();
    ac_reset_pso_cds();
    ac_reset_other();
    if (len == 0)
    {
      *do_data_p = 0;
      return 1;
    }
    else
    {
      *do_data_p = flash_do_write(1, data, len);
      if (*do_data_p)
        return 1;
      else
        return 0;

    }

  }
  else
  {
    copy_do_1(tag, check_do_ptr(do_ptr[1]), with_tag);
    return 1;
  }

}

int main()
{
  return 0;
}

