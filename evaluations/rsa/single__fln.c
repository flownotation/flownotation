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
} __fln__public_keyS_int;
typedef struct 
{
  int d;
} __fln__encodeI_int;
typedef struct 
{
  int d;
} __fln__primeI_int;
typedef struct 
{
  int d;
} __fln__private_keyS_int;
typedef struct 
{
  int d;
} __fln__decodeI_int;
__fln__public_keyS_int __fln__public_keyS_int_intg(int x)
{
  __fln__public_keyS_int y = {.d = x};
  return y;
}

__fln__public_keyS_int *__fln__public_keyS_int_intg_ptr(int *x)
{
  __fln__public_keyS_int tmp = {.d = *x};
  __fln__public_keyS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__public_keyS_int_sec(__fln__public_keyS_int x)
{
  return x.d;
}

int *__fln__public_keyS_int_sec_ptr(__fln__public_keyS_int *x)
{
  return &x->d;
}

__fln__encodeI_int __fln__encodeI_int_intg(int x)
{
  __fln__encodeI_int y = {.d = x};
  return y;
}

__fln__encodeI_int *__fln__encodeI_int_intg_ptr(int *x)
{
  __fln__encodeI_int tmp = {.d = *x};
  __fln__encodeI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__encodeI_int_sec(__fln__encodeI_int x)
{
  return x.d;
}

int *__fln__encodeI_int_sec_ptr(__fln__encodeI_int *x)
{
  return &x->d;
}

__fln__primeI_int __fln__primeI_int_intg(int x)
{
  __fln__primeI_int y = {.d = x};
  return y;
}

__fln__primeI_int *__fln__primeI_int_intg_ptr(int *x)
{
  __fln__primeI_int tmp = {.d = *x};
  __fln__primeI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__primeI_int_sec(__fln__primeI_int x)
{
  return x.d;
}

int *__fln__primeI_int_sec_ptr(__fln__primeI_int *x)
{
  return &x->d;
}

__fln__private_keyS_int __fln__private_keyS_int_intg(int x)
{
  __fln__private_keyS_int y = {.d = x};
  return y;
}

__fln__private_keyS_int *__fln__private_keyS_int_intg_ptr(int *x)
{
  __fln__private_keyS_int tmp = {.d = *x};
  __fln__private_keyS_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__private_keyS_int_sec(__fln__private_keyS_int x)
{
  return x.d;
}

int *__fln__private_keyS_int_sec_ptr(__fln__private_keyS_int *x)
{
  return &x->d;
}

__fln__decodeI_int __fln__decodeI_int_intg(int x)
{
  __fln__decodeI_int y = {.d = x};
  return y;
}

__fln__decodeI_int *__fln__decodeI_int_intg_ptr(int *x)
{
  __fln__decodeI_int tmp = {.d = *x};
  __fln__decodeI_int *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

int __fln__decodeI_int_sec(__fln__decodeI_int x)
{
  return x.d;
}

int *__fln__decodeI_int_sec_ptr(__fln__decodeI_int *x)
{
  return &x->d;
}

int modpow(long long a, long long b, int c)
{
  int res = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      res = (res * a) % c;
    }

    b = b >> 1;
    a = (a * a) % c;
  }

  return res;
}

int jacobi(int a, int n)
{
  int twos;
  int temp;
  int mult = 1;
  while ((a > 1) && (a != n))
  {
    a = a % n;
    if ((a <= 1) || (a == n))
      break;

    twos = 0;
    while (((a % 2) == 0) && (++twos))
      a /= 2;

    if ((twos > 0) && ((twos % 2) == 1))
      mult *= ((((n % 8) == 1) || ((n % 8) == 7)) * 2) - 1;

    if ((a <= 1) || (a == n))
      break;

    if (((n % 4) != 1) && ((a % 4) != 1))
      mult *= -1;

    temp = a;
    a = n;
    n = temp;
  }

  if (a == 0)
    return 0;
  else
    if (a == 1)
    return mult;
  else
    return 0;


}

int solovayPrime(int a, int n)
{
  int x = jacobi(a, n);
  if (x == (-1))
    x = n - 1;

  return (x != 0) && (modpow(a, (n - 1) / 2, n) == x);
}

int probablePrime(int n, int k)
{
  if (n == 2)
    return 1;
  else
    if (((n % 2) == 0) || (n == 1))
    return 0;


  while ((k--) > 0)
  {
    if (!solovayPrime((rand() % (n - 2)) + 2, n))
      return 0;

  }

  return 1;
}

__fln__primeI_int randPrime(int n)
{
  int prime = rand() % n;
  n += n % 2;
  prime += 1 - (prime % 2);
  while (1)
  {
    if (probablePrime(prime, 5))
      return __fln__primeI_int_intg(prime);

    prime = (prime + 2) % n;
  }

}

int gcd(int a, int b)
{
  int temp;
  while (b != 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int randExponent(int phi, int n)
{
  int e = rand() % n;
  while (1)
  {
    if (gcd(e, phi) == 1)
      return e;

    e = (e + 1) % n;
    if (e <= 2)
      e = 3;

  }

}

int inverse(__fln__public_keyS_int n, int modulus)
{
  int n__fln_p = __fln__public_keyS_int_sec(n);
  int a = n__fln_p;
  int b = modulus;
  int x = 0;
  int y = 1;
  int x0 = 1;
  int y0 = 0;
  int q;
  int temp;
  while (b != 0)
  {
    q = a / b;
    temp = a % b;
    a = b;
    b = temp;
    temp = x;
    x = x0 - (q * x);
    x0 = temp;
    temp = y;
    y = y0 - (q * y);
    y0 = temp;
  }

  if (x0 < 0)
    x0 += modulus;

  return x0;
}

int readFile(FILE *fd, char **buffer, int bytes)
{
  int len = 0;
  int cap = 1024;
  int r;
  char buf[1024];
  *buffer = malloc(1024 * (sizeof(char)));
  while ((r = fread(buf, sizeof(char), 1024, fd)) > 0)
  {
    if ((len + r) >= cap)
    {
      cap *= 2;
      *buffer = realloc(*buffer, cap);
    }

    memcpy(&(*buffer)[len], buf, r);
    len += r;
  }

  if (((len + bytes) - (len % bytes)) > cap)
    *buffer = realloc(*buffer, (len + bytes) - (len % bytes));

  do
  {
    (*buffer)[len] = '\0';
    len++;
  }
  while ((len % bytes) != 0);
  return len;
}

int encode(int m, int e, int n)
{
  return modpow(m, e, n);
}

int decode(int c, int d, int n)
{
  return modpow(c, d, n);
}

__fln__encodeI_int *encodeMessage(int len, int bytes, char *message, __fln__public_keyS_int exponent, int modulus)
{
  int exponent__fln_p = __fln__public_keyS_int_sec(exponent);
  int *encoded = malloc((len / bytes) * (sizeof(int)));
  int x;
  int i;
  int j;
  for (i = 0; i < len; i += bytes)
  {
    x = 0;
    for (j = 0; j < bytes; j++)
      x += message[i + j] * (1 << (7 * j));

    encoded[i / bytes] = encode(x, exponent__fln_p, modulus);
    printf("%d ", encoded[i / bytes]);
  }

  return __fln__encodeI_int_intg_ptr(encoded);
}

__fln__decodeI_int *decodeMessage(int len, int bytes, int *cryptogram, __fln__private_keyS_int exponent, int modulus)
{
  int exponent__fln_p = __fln__private_keyS_int_sec(exponent);
  int *decoded = malloc((len * bytes) * (sizeof(int)));
  int x;
  int i;
  int j;
  for (i = 0; i < len; i++)
  {
    x = decode(cryptogram[i], exponent__fln_p, modulus);
    for (j = 0; j < bytes; j++)
    {
      decoded[(i * bytes) + j] = (x >> (7 * j)) % 128;
      if (decoded[(i * bytes) + j] != '\0')
        printf("%c", decoded[(i * bytes) + j]);

    }

  }

  return __fln__decodeI_int_intg_ptr(decoded);
}

int main(void)
{
  __fln__primeI_int p;
  __fln__primeI_int q;
  int n;
  int phi;
  __fln__public_keyS_int e;
  __fln__private_keyS_int d;
  int bytes;
  int len;
  __fln__encodeI_int *encoded;
  __fln__decodeI_int *decoded;
  char *buffer;
  FILE *f;
  while (1)
  {
    p = randPrime(10000);
    printf("Got first prime factor, p = %d ... ", __fln__primeI_int_sec(p));
    getchar();
    q = randPrime(10000);
    printf("Got second prime factor, q = %d ... ", __fln__primeI_int_sec(q));
    getchar();
    n = __fln__primeI_int_sec(p) * __fln__primeI_int_sec(q);
    printf("Got modulus, n = pq = %d ... ", n);
    if (n < 128)
    {
      printf("Modulus is less than 128, cannot encode single bytes. Trying again ... ");
      getchar();
    }
    else
      break;

  }

  if (n >> 21)
    bytes = 3;
  else
    if (n >> 14)
    bytes = 2;
  else
    bytes = 1;


  getchar();
  phi = (__fln__primeI_int_sec(p) - 1) * (__fln__primeI_int_sec(q) - 1);
  printf("Got totient, phi = %d ... ", phi);
  getchar();
  e = __fln__public_keyS_int_intg(randExponent(phi, 1000));
  printf("Chose public exponent, e = %d\nPublic key is (%d, %d) ... ", e, e, n);
  getchar();
  d = __fln__private_keyS_int_intg(inverse(e, phi));
  printf("Calculated private exponent, d = %d\nPrivate key is (%d, %d) ... ", d, d, n);
  getchar();
  printf("Opening file \"text.txt\" for reading\n");
  f = fopen("text.txt", "r");
  if (f == 0)
  {
    printf("Failed to open file \"text.txt\". Does it exist?\n");
    return 1;
  }

  len = readFile(f, &buffer, bytes);
  fclose(f);
  printf("File \"text.txt\" read successfully, %d bytes read. Encoding byte stream in chunks of %d bytes ... ", len, bytes);
  getchar();
  encoded = encodeMessage(len, bytes, buffer, e, n);
  printf("\nEncoding finished successfully ... ");
  getchar();
  printf("Decoding encoded message ... ");
  getchar();
  decoded = decodeMessage(len / bytes, bytes, __fln__encodeI_int_sec_ptr(encoded), d, n);
  printf("\nFinished RSA demonstration!\n");
  free(__fln__encodeI_int_sec_ptr(encoded));
  free(__fln__decodeI_int_sec_ptr(decoded));
  free(buffer);
  return 0;
}

