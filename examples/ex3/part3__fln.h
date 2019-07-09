typedef struct {int d; } __fln__trusted_int;
typedef struct {int d; } __fln__test_int;
__fln__trusted_int __fln__trusted_int_write(int x) {__fln__trusted_int y; y.d = x; return y; }
int __fln__trusted_int_read(__fln__trusted_int x) { return x.d; }
int* __fln__trusted_int_read_ptr(__fln__trusted_int* x) { return &x->d; }
__fln__test_int __fln__test_int_write(int x) {__fln__test_int y; y.d = x; return y; }
int __fln__test_int_read(__fln__test_int x) { return x.d; }
int* __fln__test_int_read_ptr(__fln__test_int* x) { return &x->d; }
