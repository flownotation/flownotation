typedef struct {int d; } __fln__authentic_int;
typedef struct {foo d; __fln__authentic_int data; } __fln__authentic_foo;
__fln__authentic_int __fln__authentic_int_intg(int x) {__fln__authentic_int y; y.d = x; return y; }
int __fln__authentic_int_sec(__fln__authentic_int x) { return x.d; }
int* __fln__authentic_int_sec_ptr(__fln__authentic_int* x) { return &x->d; }
__fln__authentic_foo __fln__authentic_foo_intg(foo x) {__fln__authentic_foo y; y.d = x; return y; }
foo __fln__authentic_foo_sec(__fln__authentic_foo x) { return x.d; }
foo* __fln__authentic_foo_sec_ptr(__fln__authentic_foo* x) { return &x->d; }
