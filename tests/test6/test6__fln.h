typedef struct {int d; } __fln__tag_int;
__fln__tag_int __fln__tag_int_write(int x) {__fln__tag_int y; y.d = x; return y; }
int __fln__tag_int_read(__fln__tag_int x) { return x.d; }
int* __fln__tag_int_read_ptr(__fln__tag_int* x) { return &x->d; }
__fln__tag_int __fln__tag_int_if(__fln__tag_int x) { return x; }
