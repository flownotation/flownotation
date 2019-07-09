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
  int x;
} asn1buf;
void abort()
{
  return;
}

void assert()
{
  return;
}

typedef int asn1_octet;
typedef int asn1_error_code;
typedef enum 
{
  PRIMITIVE = 0x00,
  CONSTRUCTED = 0x20
} asn1_construction;
typedef enum 
{
  UNIVERSAL = 0x00,
  APPLICATION = 0x40,
  CONTEXT_SPECIFIC = 0x80,
  PRIVATE = 0xC0
} asn1_class;
typedef int asn1_tagnum;
typedef struct 
{
  asn1_class asn1class;
  asn1_construction construction;
  asn1_tagnum tagnum;
  size_t tag_len;
  size_t tag_end_len;
} taginfo;
asn1_error_code k5_asn1_encode_bool(asn1buf *buf, intmax_t val, size_t *len_out);
asn1_error_code k5_asn1_encode_int(asn1buf *buf, intmax_t val, size_t *len_out);
asn1_error_code k5_asn1_encode_uint(asn1buf *buf, uintmax_t val, size_t *len_out);
asn1_error_code k5_asn1_encode_bytestring(asn1buf *buf, unsigned char * const *val, size_t len, size_t *len_out);
asn1_error_code k5_asn1_encode_bitstring(asn1buf *buf, unsigned char * const *val, size_t len, size_t *len_out);
asn1_error_code k5_asn1_encode_generaltime(asn1buf *buf, time_t val, size_t *len_out);
asn1_error_code k5_asn1_decode_bool(const unsigned char *asn1, size_t len, intmax_t *val);
asn1_error_code k5_asn1_decode_int(const unsigned char *asn1, size_t len, intmax_t *val);
asn1_error_code k5_asn1_decode_uint(const unsigned char *asn1, size_t len, uintmax_t *val);
asn1_error_code k5_asn1_decode_generaltime(const unsigned char *asn1, size_t len, time_t *time_out);
asn1_error_code k5_asn1_decode_bytestring(const unsigned char *asn1, size_t len, unsigned char **str_out, size_t *len_out);
asn1_error_code k5_asn1_decode_bitstring(const unsigned char *asn1, size_t len, unsigned char **bits_out, size_t *len_out);
enum atype_type
{
  atype_min = 1,
  atype_fn = 2,
  atype_ptr = 3,
  atype_offset = 4,
  atype_optional = 5,
  atype_counted = 6,
  atype_sequence = 7,
  atype_nullterm_sequence_of = 8,
  atype_nonempty_nullterm_sequence_of = 9,
  atype_tagged_thing = 10,
  atype_bool = 11,
  atype_int = 12,
  atype_uint = 13,
  atype_int_immediate = 14,
  atype_max = 15
};
struct atype_info
{
  enum atype_type type;
  size_t size;
  const void *tinfo;
};
struct fn_info
{
  asn1_error_code (*enc)(asn1buf *, const void *, taginfo *, size_t *);
  asn1_error_code (*dec)(const taginfo *, const unsigned char *, size_t, void *);
  int (*check_tag)(const taginfo *);
  void (*free_func)(void *);
};
struct ptr_info
{
  void *(*loadptr)(const void *);
  void (*storeptr)(void *, void *);
  const struct atype_info *basetype;
};
struct offset_info
{
  unsigned int dataoff : 9;
  const struct atype_info *basetype;
};
struct optional_info
{
  int (*is_present)(const void *);
  void (*init)(void *);
  const struct atype_info *basetype;
};
struct counted_info
{
  unsigned int dataoff : 9;
  unsigned int lenoff : 9;
  unsigned int lensigned : 1;
  unsigned int lensize : 5;
  const struct cntype_info *basetype;
};
struct tagged_info
{
  unsigned int tagval : 16;
  unsigned int tagtype : 8;
  unsigned int construction : 6;
  unsigned int implicit : 1;
  const struct atype_info *basetype;
};
struct immediate_info
{
  intmax_t val;
  asn1_error_code err;
};
enum cntype_type
{
  cntype_min = 1,
  cntype_string = 2,
  cntype_der = 3,
  cntype_seqof = 4,
  cntype_choice = 5,
  cntype_max = 6
};
struct cntype_info
{
  enum cntype_type type;
  const void *tinfo;
};
struct string_info
{
  asn1_error_code (*enc)(asn1buf *, unsigned char * const *, size_t, size_t *);
  asn1_error_code (*dec)(const unsigned char *, size_t, unsigned char **, size_t *);
  unsigned int tagval : 5;
};
struct choice_info
{
  const struct atype_info **options;
  size_t n_options;
};
struct seq_info
{
  const struct atype_info **fields;
  size_t n_fields;
};
static void free_atype_ptr(const struct atype_info *a, void *val);
static void free_sequence(const struct seq_info *seq, void *val);
static void free_sequence_of(const struct atype_info *eltinfo, void *val, size_t count);
static void free_cntype(const struct cntype_info *a, void *val, size_t count);
typedef struct 
{
  const struct atype_info d;
} __fln__freeptrS_const_struct_atype_info;
typedef struct 
{
  const struct atype_info d;
} __fln__freebaseS_const_struct_atype_info;
typedef struct 
{
  const struct atype_info d;
} __fln__freebaseS_freeptrS_const_struct_atype_info;
typedef struct 
{
  const struct cntype_info d;
} __fln__freecnS_const_struct_cntype_info;
typedef struct 
{
  const struct seq_info d;
} __fln__freeseqS_const_struct_seq_info;
__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_tail_w(__fln__freeptrS_const_struct_atype_info x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_tail_w_ptr(__fln__freeptrS_const_struct_atype_info *x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freebaseS_freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_tail_r(__fln__freebaseS_freeptrS_const_struct_atype_info x)
{
  __fln__freeptrS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_tail_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info *x)
{
  __fln__freeptrS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_fst_w(__fln__freebaseS_const_struct_atype_info x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_fst_w_ptr(__fln__freebaseS_const_struct_atype_info *x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freebaseS_freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freebaseS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_fst_r(__fln__freebaseS_freeptrS_const_struct_atype_info x)
{
  __fln__freebaseS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freebaseS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_fst_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info *x)
{
  __fln__freebaseS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freebaseS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_snd_w(__fln__freeptrS_const_struct_atype_info x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_snd_w_ptr(__fln__freeptrS_const_struct_atype_info *x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freebaseS_freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_snd_r(__fln__freebaseS_freeptrS_const_struct_atype_info x)
{
  __fln__freeptrS_const_struct_atype_info y = {.d = x.d};
  return y;
}

__fln__freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_snd_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info *x)
{
  __fln__freeptrS_const_struct_atype_info tmp = {.d = x->d};
  __fln__freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

__fln__freeptrS_const_struct_atype_info __fln__freeptrS_const_struct_atype_info_intg(const struct atype_info x)
{
  __fln__freeptrS_const_struct_atype_info y = {.d = x};
  return y;
}

__fln__freeptrS_const_struct_atype_info *__fln__freeptrS_const_struct_atype_info_intg_ptr(const struct atype_info *x)
{
  __fln__freeptrS_const_struct_atype_info tmp = {.d = *x};
  __fln__freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct atype_info __fln__freeptrS_const_struct_atype_info_sec(__fln__freeptrS_const_struct_atype_info x)
{
  return x.d;
}

const struct atype_info *__fln__freeptrS_const_struct_atype_info_sec_ptr(__fln__freeptrS_const_struct_atype_info *x)
{
  return &x->d;
}

__fln__freebaseS_const_struct_atype_info __fln__freebaseS_const_struct_atype_info_intg(const struct atype_info x)
{
  __fln__freebaseS_const_struct_atype_info y = {.d = x};
  return y;
}

__fln__freebaseS_const_struct_atype_info *__fln__freebaseS_const_struct_atype_info_intg_ptr(const struct atype_info *x)
{
  __fln__freebaseS_const_struct_atype_info tmp = {.d = *x};
  __fln__freebaseS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct atype_info __fln__freebaseS_const_struct_atype_info_sec(__fln__freebaseS_const_struct_atype_info x)
{
  return x.d;
}

const struct atype_info *__fln__freebaseS_const_struct_atype_info_sec_ptr(__fln__freebaseS_const_struct_atype_info *x)
{
  return &x->d;
}

__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_intg(const struct atype_info x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info y = {.d = x};
  return y;
}

__fln__freebaseS_freeptrS_const_struct_atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(const struct atype_info *x)
{
  __fln__freebaseS_freeptrS_const_struct_atype_info tmp = {.d = *x};
  __fln__freebaseS_freeptrS_const_struct_atype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_sec(__fln__freebaseS_freeptrS_const_struct_atype_info x)
{
  return x.d;
}

const struct atype_info *__fln__freebaseS_freeptrS_const_struct_atype_info_sec_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info *x)
{
  return &x->d;
}

__fln__freecnS_const_struct_cntype_info __fln__freecnS_const_struct_cntype_info_intg(const struct cntype_info x)
{
  __fln__freecnS_const_struct_cntype_info y = {.d = x};
  return y;
}

__fln__freecnS_const_struct_cntype_info *__fln__freecnS_const_struct_cntype_info_intg_ptr(const struct cntype_info *x)
{
  __fln__freecnS_const_struct_cntype_info tmp = {.d = *x};
  __fln__freecnS_const_struct_cntype_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct cntype_info __fln__freecnS_const_struct_cntype_info_sec(__fln__freecnS_const_struct_cntype_info x)
{
  return x.d;
}

const struct cntype_info *__fln__freecnS_const_struct_cntype_info_sec_ptr(__fln__freecnS_const_struct_cntype_info *x)
{
  return &x->d;
}

__fln__freeseqS_const_struct_seq_info __fln__freeseqS_const_struct_seq_info_intg(const struct seq_info x)
{
  __fln__freeseqS_const_struct_seq_info y = {.d = x};
  return y;
}

__fln__freeseqS_const_struct_seq_info *__fln__freeseqS_const_struct_seq_info_intg_ptr(const struct seq_info *x)
{
  __fln__freeseqS_const_struct_seq_info tmp = {.d = *x};
  __fln__freeseqS_const_struct_seq_info *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

const struct seq_info __fln__freeseqS_const_struct_seq_info_sec(__fln__freeseqS_const_struct_seq_info x)
{
  return x.d;
}

const struct seq_info *__fln__freeseqS_const_struct_seq_info_sec_ptr(__fln__freeseqS_const_struct_seq_info *x)
{
  return &x->d;
}

const struct atype_info *free_atype(__fln__freebaseS_const_struct_atype_info *a, void *val)
{
  const struct atype_info* a__fln_p = __fln__freebaseS_const_struct_atype_info_sec_ptr(a);
  __fln__freebaseS_freeptrS_const_struct_atype_info *x;
  __fln__freebaseS_const_struct_atype_info *y;
  __fln__freecnS_const_struct_cntype_info *c;
  __fln__freeseqS_const_struct_seq_info *s;
  switch (a__fln_p->type)
  {
    case atype_fn:
    {
      const struct fn_info *fn = a__fln_p->tinfo;
      if (fn->free_func != 0)
        fn->free_func(val);

      break;
    }

    case atype_sequence:
      s = __fln__freeseqS_const_struct_seq_info_intg_ptr(a__fln_p->tinfo);
      free_sequence(s, val);
      break;

    case atype_ptr:
    {
      const struct ptr_info *ptrinfo = a__fln_p->tinfo;
      void *ptr = LOADPTR(val, ptrinfo);
      if (ptr != 0)
      {
        x = __fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(ptrinfo->basetype);
        free_atype(x, ptr);
        free_atype_ptr(x, ptr);
      }

      break;
    }

    case atype_offset:
    {
      const struct offset_info *off = a__fln_p->tinfo;
      assert(off->basetype != 0);
      y = __fln__freebaseS_const_struct_atype_info_intg_ptr(off->basetype);
      free_atype(y, ((char *) val) + off->dataoff);
      break;
    }

    case atype_optional:
    {
      const struct optional_info *opt = a__fln_p->tinfo;
      y = __fln__freebaseS_const_struct_atype_info_intg_ptr(opt->basetype);
      free_atype(y, val);
      break;
    }

    case atype_counted:
    {
      const struct counted_info *counted = a__fln_p->tinfo;
      void *dataptr = ((char *) val) + counted->dataoff;
      size_t count;
      if (load_count(val, counted, &count) == 0)
      {
        c = __fln__freecnS_const_struct_cntype_info_intg_ptr(counted->basetype);
        free_cntype(c, dataptr, count);
      }

      break;
    }

    case atype_nullterm_sequence_of:

    case atype_nonempty_nullterm_sequence_of:
    {
      size_t count = get_nullterm_sequence_len(val, a__fln_p->tinfo);
      free_sequence_of(a__fln_p->tinfo, val, count);
      break;
    }

    case atype_tagged_thing:
    {
      const struct tagged_info *tag = a__fln_p->tinfo;
      y = __fln__freebaseS_const_struct_atype_info_intg_ptr(tag->basetype);
      free_atype(y, val);
      break;
    }

    case atype_bool:

    case atype_int:

    case atype_uint:

    case atype_int_immediate:
      break;

    default:
      abort();

  }

  return __fln__freeptrS_atype_info_intg_ptr(x);
}

static void free_atype_ptr(__fln__freeptrS_const_struct_atype_info *a, void *val)
{
  const struct atype_info* a__fln_p = __fln__freeptrS_const_struct_atype_info_sec_ptr(a);
  __fln__freeptrS_const_struct_atype_info *x;
  switch (a__fln_p->type)
  {
    case atype_fn:

    case atype_sequence:

    case atype_counted:

    case atype_nullterm_sequence_of:

    case atype_nonempty_nullterm_sequence_of:

    case atype_bool:

    case atype_int:

    case atype_uint:

    case atype_int_immediate:
      break;

    case atype_ptr:
    {
      const struct ptr_info *ptrinfo = a__fln_p->tinfo;
      void *ptr = LOADPTR(val, ptrinfo);
      free(ptr);
      STOREPTR(0, ptrinfo, val);
      break;
    }

    case atype_offset:
    {
      const struct offset_info *off = a__fln_p->tinfo;
      assert(off->basetype != 0);
      x = __fln__freeptrS_const_struct_atype_info_intg_ptr(off->basetype);
      free_atype_ptr(x, ((char *) val) + off->dataoff);
      break;
    }

    case atype_optional:
    {
      const struct optional_info *opt = a__fln_p->tinfo;
      x = __fln__freeptrS_const_struct_atype_info_intg_ptr(opt->basetype);
      free_atype_ptr(x, val);
      break;
    }

    case atype_tagged_thing:
    {
      const struct tagged_info *tag = a__fln_p->tinfo;
      x = __fln__freeptrS_const_struct_atype_info_intg_ptr(tag->basetype);
      free_atype_ptr(x, val);
      break;
    }

    default:
      abort();

  }

}

static void free_cntype(__fln__freecnS_const_struct_cntype_info *c, void *val, size_t count)
{
  const struct cntype_info* c__fln_p = __fln__freecnS_const_struct_cntype_info_sec_ptr(c);
  __fln__freebaseS_freeptrS_const_struct_atype_info *x;
  switch (c__fln_p->type)
  {
    case cntype_string:

    case cntype_der:
      free(*((char **) val));
      *((char **) val) = 0;
      break;

    case cntype_seqof:
    {
      const struct atype_info *a = c__fln_p->tinfo;
      const struct ptr_info *ptrinfo = a->tinfo;
      void *seqptr = LOADPTR(val, ptrinfo);
      free_sequence_of(ptrinfo->basetype, seqptr, count);
      free(seqptr);
      STOREPTR(0, ptrinfo, val);
      break;
    }

    case cntype_choice:
    {
      const struct choice_info *choice = c__fln_p->tinfo;
      if (count < choice->n_options)
      {
        x = __fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(choice->options[count]);
        free_atype(x, val);
        free_atype_ptr(x, val);
      }

      break;
    }

    default:
      abort();

  }

}

static void free_sequence(__fln__freeseqS_const_struct_seq_info *seq, void *val)
{
  const struct seq_info* seq__fln_p = __fln__freeseqS_const_struct_seq_info_sec_ptr(seq);
  size_t i;
  __fln__freebaseS_freeptrS_const_struct_atype_info *x;
  x = __fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(seq__fln_p->fields);
  for (i = 0; i < seq__fln_p->n_fields; i++)
    free_atype(x[i], val);

  for (i = 0; i < seq__fln_p->n_fields; i++)
    free_atype_ptr(x[i], val);

}

static void free_sequence_of(__fln__freebaseS_const_struct_atype_info *eltinfo, void *val, size_t count)
{
  const struct atype_info* eltinfo__fln_p = __fln__freebaseS_const_struct_atype_info_sec_ptr(eltinfo);
  void *eltptr;
  assert(eltinfo__fln_p->size != 0);
  __fln__freebaseS_freeptrS_const_struct_atype_info *x;
  x = __fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(eltinfo__fln_p);
  while ((count--) > 0)
  {
    eltptr = ((char *) val) + (count * x->d.size);
    __fln__freebaseS_const_struct_atype_info* x__fln_h = __fln__freebaseS_freeptrS_const_struct_atype_info_fst_r_ptr(x);
    __fln__freeptrS_const_struct_atype_info* x__fln_s = free_atype(x__fln_h, eltptr);
    free_atype_ptr(x__fln_s, eltptr);
  }

}

static int check_atype_tag(const struct atype_info *a, const taginfo *t)
{
  switch (a->type)
  {
    case atype_fn:
    {
      const struct fn_info *fn = a->tinfo;
      assert(fn->check_tag != 0);
      return fn->check_tag(t);
    }

    case atype_sequence:

    case atype_nullterm_sequence_of:

    case atype_nonempty_nullterm_sequence_of:
      return ((t->asn1class == UNIVERSAL) && (t->construction == CONSTRUCTED)) && (t->tagnum == 16);

    case atype_ptr:
    {
      const struct ptr_info *ptrinfo = a->tinfo;
      return check_atype_tag(ptrinfo->basetype, t);
    }

    case atype_offset:
    {
      const struct offset_info *off = a->tinfo;
      return check_atype_tag(off->basetype, t);
    }

    case atype_optional:
    {
      const struct optional_info *opt = a->tinfo;
      return check_atype_tag(opt->basetype, t);
    }

    case atype_counted:
    {
      const struct counted_info *counted = a->tinfo;
      switch (counted->basetype->type)
      {
        case cntype_string:
        {
          const struct string_info *string = counted->basetype->tinfo;
          return ((t->asn1class == UNIVERSAL) && (t->construction == PRIMITIVE)) && (t->tagnum == string->tagval);
        }

        case cntype_seqof:
          return ((t->asn1class == UNIVERSAL) && (t->construction == CONSTRUCTED)) && (t->tagnum == 16);

        case cntype_der:
          return 1;

        case cntype_choice:
          return 1;

        default:
          abort();

      }

    }

    case atype_tagged_thing:
    {
      const struct tagged_info *tag = a->tinfo;
      if ((!tag->implicit) && (t->construction != tag->construction))
        return 0;

      return (t->asn1class == tag->tagtype) && (t->tagnum == tag->tagval);
    }

    case atype_bool:
      return ((t->asn1class == UNIVERSAL) && (t->construction == PRIMITIVE)) && (t->tagnum == 1);

    case atype_int:

    case atype_uint:

    case atype_int_immediate:
      return ((t->asn1class == UNIVERSAL) && (t->construction == PRIMITIVE)) && (t->tagnum == 2);

    default:
      abort();

  }

}

static asn1_error_code null_terminate(const struct atype_info *eltinfo, void *ptr, size_t count, void **ptr_out)
{
  const struct ptr_info *ptrinfo = eltinfo->tinfo;
  void *endptr;
  assert(eltinfo->type == atype_ptr);
  ptr = realloc(ptr, (count + 1) * eltinfo->size);
  if (ptr == 0)
    return 0;

  endptr = ((char *) ptr) + (count * eltinfo->size);
  STOREPTR(0, ptrinfo, endptr);
  *ptr_out = ptr;
  return 0;
}

