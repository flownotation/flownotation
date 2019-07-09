typedef struct {int d; } __fln__trusted_int;
typedef struct {int d; } __fln__encrypted_int;
__fln__trusted_int __fln__trusted_int_write(int x) {__fln__trusted_int y; y.d = x; return y; }
int __fln__trusted_int_read(__fln__trusted_int x) { return x.d; }
int* __fln__trusted_int_read_ptr(__fln__trusted_int* x) { return &x->d; }
__fln__encrypted_int __fln__encrypted_int_write(int x) {__fln__encrypted_int y; y.d = x; return y; }
int __fln__encrypted_int_read(__fln__encrypted_int x) { return x.d; }
int* __fln__encrypted_int_read_ptr(__fln__encrypted_int* x) { return &x->d; }
__fln__trusted_pair __fln__trusted_pair_write(pair x) {__fln__trusted_pair y; y.d = x; return y; }
pair __fln__trusted_pair_read(__fln__trusted_pair x) { return x.d; }
pair* __fln__trusted_pair_read_ptr(__fln__trusted_pair* x) { return &x->d; }
