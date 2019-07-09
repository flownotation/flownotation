typedef struct {int d; } __fln__secret_int;
__fln__secret_int __fln__secret_int_write(int x) {__fln__secret_int y; y.d = x; return y; }
int __fln__secret_int_read(__fln__secret_int x) { return x.d; }
int* __fln__secret_int_read_ptr(__fln__secret_int* x) { return &x->d; }
