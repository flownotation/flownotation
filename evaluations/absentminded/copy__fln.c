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
typedef long long widest_t;
typedef struct ProtocolDesc ProtocolDesc;
typedef struct OblivInputs OblivInputs;
typedef struct OblivBit OblivBit;
typedef char yao_key_t[(80 + 7) / 8];
typedef char nnob_key_t[10];
typedef struct NnobKey
{
  nnob_key_t key;
} NnobKey;
typedef struct NnobShareAndMac
{
  bool share;
  nnob_key_t mac;
} NnobShareAndMac;
struct ProtocolDesc
{
  int partyCount;
  int thisParty;
  int error;
  struct ProtocolTransport *trans;
  union 
  {
    struct 
    {
      unsigned mulCount;
      unsigned xorCount;
    } debug;
  };
  int (*currentParty)(ProtocolDesc *);
  void (*feedOblivInputs)(ProtocolDesc *, OblivInputs *, size_t, int);
  bool (*revealOblivBits)(ProtocolDesc *, widest_t *, const OblivBit *, size_t, int);
  void (*setBitAnd)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitOr)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitXor)(ProtocolDesc *, OblivBit *, const OblivBit *, const OblivBit *);
  void (*setBitNot)(ProtocolDesc *, OblivBit *, const OblivBit *);
  void (*flipBit)(ProtocolDesc *, OblivBit *);
  void *extra;
  void (*splitextra)(ProtocolDesc *, ProtocolDesc *);
  void (*cleanextra)(ProtocolDesc *);
};
typedef struct 
{
  void *sender;
  void (*send)(void *, const char *, const char *, int n, int len);
  void (*release)(void *);
} OTsender;
typedef struct 
{
  void *recver;
  void (*recv)(void *, char *, const bool *, int n, int len);
  void (*release)(void *);
} OTrecver;
typedef void (*OcOtCorrelator)(char *, const char *, int, void *);
typedef struct 
{
  void *sender;
  void (*send)(void *, char *, char *, int n, int len, OcOtCorrelator, void *);
  void (*release)(void *);
} COTsender;
typedef OTrecver COTrecver;
typedef struct YaoProtocolDesc
{
  char protoType;
  yao_key_t R;
  yao_key_t I;
  uint64_t gcount;
  uint64_t gcount_offset;
  uint64_t icount;
  uint64_t ocount;
  bool ownOT;
  void (*nonFreeGate)(struct ProtocolDesc *, OblivBit *, char, const OblivBit *, const OblivBit *);
  union 
  {
    OTsender sender;
    OTrecver recver;
  };
  void *extra;
} YaoProtocolDesc;
inline static YaoProtocolDesc *protoYaoProtocolDesc(ProtocolDesc *s1)
{
  if ((*((char *) s1->extra)) == 1)
    return (YaoProtocolDesc *) s1->extra;
  else
    return 0;

}

typedef struct ProtocolTransport ProtocolTransport;
struct ProtocolTransport
{
  int maxParties;
  ProtocolTransport *(*split)(ProtocolTransport *);
  int (*send)(ProtocolTransport *, int, const void *, size_t);
  int (*recv)(ProtocolTransport *, int, void *, size_t);
  int (*flush)(ProtocolTransport *);
  void (*cleanup)(ProtocolTransport *);
};
struct OblivInputs
{
  union 
  {
    unsigned long long src;
    float src_f;
  };
  struct OblivBit *dest;
  size_t size;
};
typedef void (*protocol_run)(void *);
ProtocolDesc *ocCurrentProto(void);
void ocSetCurrentProto(ProtocolDesc *pd);
bool ocCanSplitProto(ProtocolDesc *);
bool ocSplitProto(ProtocolDesc *, ProtocolDesc *);
void ocCleanupProto(ProtocolDesc *);
int ocCurrentParty();
int ocCurrentPartyDefault(ProtocolDesc *pd);
inline static int protoCurrentParty(ProtocolDesc *pd)
{
  return pd->currentParty(pd);
}

inline static char ocCurrentProtoType()
{
  return *((char *) ocCurrentProto()->extra);
}

void gcryDefaultLibInit(void);
inline static int transSend(ProtocolTransport *t, int d, const void *p, size_t n)
{
  return t->send(t, d, p, n);
}

inline static int transRecv(ProtocolTransport *t, int s, void *p, size_t n)
{
  return t->recv(t, s, p, n);
}

inline static int transFlush(ProtocolTransport *t)
{
  if (t->flush)
    return t->flush(t);
  else
    return 0;

}

inline static int osend(ProtocolDesc *pd, int d, const void *p, size_t n)
{
  return transSend(pd->trans, d, p, n);
}

inline static int orecv(ProtocolDesc *pd, int s, void *p, size_t n)
{
  return transRecv(pd->trans, s, p, n);
}

inline static int oflush(ProtocolDesc *pd)
{
  return transFlush(pd->trans);
}

void dhRandomInit(void);
void dhRandomFinalize(void);
inline static void otSenderRelease(OTsender *sender)
{
  sender->release(sender->sender);
}

inline static void otRecverRelease(OTrecver *recver)
{
  recver->release(recver->recver);
}

struct NpotSender *npotSenderNew(int nmax, ProtocolDesc *pd, int destParty);
void npotSenderRelease(struct NpotSender *s);
OTsender npotSenderAbstract(struct NpotSender *s);
struct NpotRecver *npotRecverNew(int nmax, ProtocolDesc *pd, int srcParty);
void npotRecverRelease(struct NpotRecver *r);
OTrecver npotRecverAbstract(struct NpotRecver *r);
void npotSend1Of2Once(struct NpotSender *s, const char *opt0, const char *opt1, int n, int len);
void npotRecv1Of2Once(struct NpotRecver *r, char *dest, unsigned mask, int n, int len);
void npotSend1Of2(struct NpotSender *s, const char *opt0, const char *opt1, int n, int len, int batchsize);
void npotRecv1Of2(struct NpotRecver *r, char *dest, const bool *sel, int n, int len, int batchsize);
struct HonestOTExtRecver *honestOTExtRecverNew(ProtocolDesc *pd, int srcparty);
void honestOTExtRecverRelease(struct HonestOTExtRecver *recver);
void honestOTExtRecv1Of2(struct HonestOTExtRecver *r, char *dest, const bool *sel, int n, int len);
void honestCorrelatedOTExtRecv1Of2(struct HonestOTExtRecver *r, char *dest, const bool *sel, int n, int len);
OTrecver honestOTExtRecverAbstract(struct HonestOTExtRecver *r);
void *honestOTExtRecv1Of2Start(struct HonestOTExtRecver *r, const bool *sel, int n);
void honestOTExtRecv1Of2Chunk(void *vargs, char *dest, int nchunk, int len, bool isCorr);
struct HonestOTExtSender *honestOTExtSenderNew(ProtocolDesc *pd, int destparty);
void honestOTExtSenderRelease(struct HonestOTExtSender *sender);
void honestOTExtSend1Of2(struct HonestOTExtSender *s, const char *opt0, const char *opt1, int n, int len);
void honestCorrelatedOTExtSend1Of2(struct HonestOTExtSender *s, char *opt0, char *opt1, int n, int len, OcOtCorrelator f, void *corrArg);
OTsender honestOTExtSenderAbstract(struct HonestOTExtSender *s);
void *honestOTExtSend1Of2Start(struct HonestOTExtSender *s, int n);
void honestOTExtSend1Of2Chunk(void *vargs, char *opt0, char *opt1, int nchunk, int len, OcOtCorrelator f, void *corrArg);
void honestOTExtSend1Of2Skip(void *vargs);
void honestOTExtSend1Of2Skip(void *vargs);
struct OTExtSender;
struct OTExtRecver;
struct OTExtRecver *otExtRecverNew(ProtocolDesc *pd, int srcparty);
struct OTExtRecver *otExtRecverNew_byPair(ProtocolDesc *pd, int srcparty);
struct OTExtRecver *otExtRecverNew_byPhair(ProtocolDesc *pd, int srcparty);
void otExtRecverRelease(struct OTExtRecver *recver);
void otExtRecv1Of2(struct OTExtRecver *r, char *dest, const bool *sel, int n, int len);
OTrecver maliciousOTExtRecverAbstract(struct OTExtRecver *r);
struct OTExtSender *otExtSenderNew(ProtocolDesc *pd, int destparty);
struct OTExtSender *otExtSenderNew_byPair(ProtocolDesc *pd, int destparty);
struct OTExtSender *otExtSenderNew_byPhair(ProtocolDesc *pd, int destparty);
void otExtSenderRelease(struct OTExtSender *sender);
void otExtSend1Of2(struct OTExtSender *s, const char *opt0, const char *opt1, int n, int len);
OTsender maliciousOTExtSenderAbstract(struct OTExtSender *s);
void yaoUseFullOTExt(ProtocolDesc *pd, int me);
void yaoUseNpot(ProtocolDesc *pd, int me);
void yaoReleaseOt(ProtocolDesc *pd, int me);
inline static void setBit(char *dest, int ind, bool v)
{
  char mask = 1 << (ind % 8);
  dest[ind / 8] = (dest[ind / 8] & (~mask)) + ((v) ? (mask) : (0));
}

inline static bool getBit(const char *src, int ind)
{
  return src[ind / 8] & (1 << (ind % 8));
}

inline static void xorBit(char *dest, int ind, bool v)
{
  dest[ind / 8] ^= v << (ind % 8);
}

inline static void memxor(void *dest, const void *src, size_t n)
{
  size_t i;
  for (i = 0; (i + (sizeof(uint64_t))) <= n; i += sizeof(uint64_t))
    *((uint64_t *) (((char *) dest) + i)) ^= *((uint64_t *) (((char *) src) + i));

  if ((i + (sizeof(uint32_t))) <= n)
  {
    *((uint32_t *) (((char *) dest) + i)) ^= *((uint32_t *) (((char *) src) + i));
    i += sizeof(uint32_t);
  }

  if ((i + (sizeof(uint16_t))) <= n)
  {
    *((uint16_t *) (((char *) dest) + i)) ^= *((uint16_t *) (((char *) src) + i));
    i += sizeof(uint16_t);
  }

  if (i < n)
    *(((char *) dest) + i) ^= *(((char *) src) + i);

}

void ocShareMuxes(ProtocolDesc *pd, char *z, const char *x0, const char *x1, size_t n, size_t eltsize, const bool *c, const bool *wc, char *t);
void ocFromShared_impl(ProtocolDesc *pd, void *dest, const void *src, size_t n, size_t bits, size_t bytes);
typedef struct OcCopy OcCopy;
typedef void (*ocopy_cb)(const OcCopy *, void *, const void *, size_t);
typedef void (*ocopy_cond_cb)(const OcCopy *, void *, const void *, const bool *, size_t);
struct OcCopy
{
  ocopy_cb go;
  ocopy_cond_cb goN;
  void (*release)(OcCopy *);
  size_t eltsize;
  void (*zeroFill)(const OcCopy *, void *, size_t);
  void (*addN)(const OcCopy *, void *, const void *, size_t);
  void (*subN)(const OcCopy *, void *, const void *, size_t);
};
inline static void ocShareDuplicate(void *dest, const void *src, size_t n)
{
  memcpy(dest, src, n);
}

inline static void ocShareXor(void *dest, const void *src, size_t n)
{
  memxor(dest, src, n);
}

inline static void ocCopyN(const OcCopy *c, void *dest, const void *src, size_t n)
{
  c->go(c, dest, src, n);
}

inline static void ocCopy(const OcCopy *c, void *dest, const void *src)
{
  ocCopyN(c, dest, src, 1);
}

inline static void ocCopyCondN(const OcCopy *c, void *dest, const void *src, const bool *cond, size_t n)
{
  c->goN(c, dest, src, cond, n);
}

void ocSwap(OcCopy *cpy, void *opt0, void *opt1, void *scratch);
void ocSwapCondN(OcCopy *cpy, void *opt0, void *opt1, void *scratch, const bool c[], size_t n);
inline static void ocCopyRelease(OcCopy *c)
{
  c->release(c);
}

inline static void ocCopyZeroFill(OcCopy *c, void *dest, size_t n)
{
  c->zeroFill(c, dest, n);
}

inline static void ocCopyAddN(OcCopy *c, void *dest, const void *src, size_t n)
{
  c->addN(c, dest, src, n);
}

inline static void ocCopySubN(OcCopy *c, void *dest, const void *src, size_t n)
{
  c->subN(c, dest, src, n);
}

inline static void *ocCopyElt(OcCopy *cpy, void *arr, int x)
{
  return (x * cpy->eltsize) + ((char *) arr);
}

extern const OcCopy ocCopyBool;
extern const OcCopy ocCopyChar;
extern const OcCopy ocCopyShort;
extern const OcCopy ocCopyInt;
extern const OcCopy ocCopyLong;
extern const OcCopy ocCopyLLong;
extern const OcCopy ocCopySizeT;
