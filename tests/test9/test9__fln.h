#ifndef TEST9__FLN__FLN_H__
#define TEST9__FLN__FLN_H__
#include "test9.h"
typedef struct {const int d; } __fln__test1I_const_int;
typedef struct {const struct foo1 d; } __fln__test1S_const_struct_foo1;
typedef struct {struct foo1 d; } __fln__test1I_struct_foo1;
typedef struct {const struct foo1 d; } __fln__test2S_const_struct_foo1;
typedef struct {const struct foo1 d; } __fln__test1S_test2S_const_struct_foo1;
typedef struct {int d; } __fln__test1I_int;
typedef struct {const struct foo d; } __fln__test1I_const_struct_foo;
typedef struct {int d; } __fln__test3S_int;
typedef struct {int d; } __fln__test2S_int;
typedef struct {int d; } __fln__test2S_test3S_int;
typedef struct {int d; } __fln__test1S_int;
typedef struct {int d; } __fln__test1S_test2S_test3S_int;
typedef struct {int d; } __fln__test4I_int;
typedef struct {int d; } __fln__test3I_int;
typedef struct {int d; } __fln__test3I_test4I_int;
typedef struct {int d; } __fln__test2I_int;
typedef struct {int d; } __fln__test2I_test3I_test4I_int;
typedef struct {int d; } __fln__test1I_test2I_test3I_test4I_int;
typedef struct {int d; } __fln__test1I_test2I_int;
typedef struct {int d; } __fln__test4S_int;
typedef struct {int d; } __fln__test3S_test4S_int;
typedef struct {int d; } __fln__test2S_test3S_test4S_int;
typedef struct {int d; } __fln__test1S_test2S_test3S_test4S_int;
typedef struct {int d; } __fln__test2I_test3I_int;
typedef struct {int d; } __fln__test1I_test2I_test3I_int;
typedef struct {struct foo1 d; } __fln__test2I_struct_foo1;
typedef struct {struct foo1 d; } __fln__test1I_test2I_struct_foo1;
typedef struct {const int d; } __fln__test2S_const_int;
typedef struct {const int d; } __fln__test1S_const_int;
typedef struct {const int d; } __fln__test1S_test2S_const_int;
typedef struct {struct foo d; } __fln__test1I_struct_foo;
__fln__test1I_const_int __fln__test1I_const_int_intg(const int x) {__fln__test1I_const_int y = { .d = x }; return y; }
__fln__test1I_const_int* __fln__test1I_const_int_intg_ptr(const int* x) {__fln__test1I_const_int tmp = { .d = *x }; __fln__test1I_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const int __fln__test1I_const_int_sec(__fln__test1I_const_int x) { return x.d; }
const int* __fln__test1I_const_int_sec_ptr(__fln__test1I_const_int* x) { return &x->d; }
__fln__test1S_const_struct_foo1 __fln__test1S_const_struct_foo1_intg(const struct foo1 x) {__fln__test1S_const_struct_foo1 y = { .d = x }; return y; }
__fln__test1S_const_struct_foo1* __fln__test1S_const_struct_foo1_intg_ptr(const struct foo1* x) {__fln__test1S_const_struct_foo1 tmp = { .d = *x }; __fln__test1S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct foo1 __fln__test1S_const_struct_foo1_sec(__fln__test1S_const_struct_foo1 x) { return x.d; }
const struct foo1* __fln__test1S_const_struct_foo1_sec_ptr(__fln__test1S_const_struct_foo1* x) { return &x->d; }
__fln__test1I_struct_foo1 __fln__test1I_struct_foo1_intg(struct foo1 x) {__fln__test1I_struct_foo1 y = { .d = x }; return y; }
__fln__test1I_struct_foo1* __fln__test1I_struct_foo1_intg_ptr(struct foo1* x) {__fln__test1I_struct_foo1 tmp = { .d = *x }; __fln__test1I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
struct foo1 __fln__test1I_struct_foo1_sec(__fln__test1I_struct_foo1 x) { return x.d; }
struct foo1* __fln__test1I_struct_foo1_sec_ptr(__fln__test1I_struct_foo1* x) { return &x->d; }
__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_tail_w(__fln__test2S_const_struct_foo1 x) {__fln__test1S_test2S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_tail_w_ptr(__fln__test2S_const_struct_foo1* x) {__fln__test1S_test2S_const_struct_foo1 tmp = { .d = x->d }; __fln__test1S_test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_tail_r(__fln__test1S_test2S_const_struct_foo1 x) { __fln__test2S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_tail_r_ptr(__fln__test1S_test2S_const_struct_foo1* x) { __fln__test2S_const_struct_foo1 tmp = { .d = x->d }; __fln__test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_fst_w(__fln__test1S_const_struct_foo1 x) {__fln__test1S_test2S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_fst_w_ptr(__fln__test1S_const_struct_foo1* x) {__fln__test1S_test2S_const_struct_foo1 tmp = { .d = x->d }; __fln__test1S_test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_fst_r(__fln__test1S_test2S_const_struct_foo1 x) { __fln__test1S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_fst_r_ptr(__fln__test1S_test2S_const_struct_foo1* x) { __fln__test1S_const_struct_foo1 tmp = { .d = x->d }; __fln__test1S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_snd_w(__fln__test2S_const_struct_foo1 x) {__fln__test1S_test2S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_snd_w_ptr(__fln__test2S_const_struct_foo1* x) {__fln__test1S_test2S_const_struct_foo1 tmp = { .d = x->d }; __fln__test1S_test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_snd_r(__fln__test1S_test2S_const_struct_foo1 x) { __fln__test2S_const_struct_foo1 y = { .d = x.d }; return y; }
__fln__test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_snd_r_ptr(__fln__test1S_test2S_const_struct_foo1* x) { __fln__test2S_const_struct_foo1 tmp = { .d = x->d }; __fln__test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_struct_foo1 __fln__test2S_const_struct_foo1_intg(const struct foo1 x) {__fln__test2S_const_struct_foo1 y = { .d = x }; return y; }
__fln__test2S_const_struct_foo1* __fln__test2S_const_struct_foo1_intg_ptr(const struct foo1* x) {__fln__test2S_const_struct_foo1 tmp = { .d = *x }; __fln__test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct foo1 __fln__test2S_const_struct_foo1_sec(__fln__test2S_const_struct_foo1 x) { return x.d; }
const struct foo1* __fln__test2S_const_struct_foo1_sec_ptr(__fln__test2S_const_struct_foo1* x) { return &x->d; }
__fln__test1S_test2S_const_struct_foo1 __fln__test1S_test2S_const_struct_foo1_intg(const struct foo1 x) {__fln__test1S_test2S_const_struct_foo1 y = { .d = x }; return y; }
__fln__test1S_test2S_const_struct_foo1* __fln__test1S_test2S_const_struct_foo1_intg_ptr(const struct foo1* x) {__fln__test1S_test2S_const_struct_foo1 tmp = { .d = *x }; __fln__test1S_test2S_const_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct foo1 __fln__test1S_test2S_const_struct_foo1_sec(__fln__test1S_test2S_const_struct_foo1 x) { return x.d; }
const struct foo1* __fln__test1S_test2S_const_struct_foo1_sec_ptr(__fln__test1S_test2S_const_struct_foo1* x) { return &x->d; }
__fln__test1I_int __fln__test1I_int_intg(int x) {__fln__test1I_int y = { .d = x }; return y; }
__fln__test1I_int* __fln__test1I_int_intg_ptr(int* x) {__fln__test1I_int tmp = { .d = *x }; __fln__test1I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1I_int_sec(__fln__test1I_int x) { return x.d; }
int* __fln__test1I_int_sec_ptr(__fln__test1I_int* x) { return &x->d; }
__fln__test1I_const_struct_foo __fln__test1I_const_struct_foo_intg(const struct foo x) {__fln__test1I_const_struct_foo y = { .d = x }; return y; }
__fln__test1I_const_struct_foo* __fln__test1I_const_struct_foo_intg_ptr(const struct foo* x) {__fln__test1I_const_struct_foo tmp = { .d = *x }; __fln__test1I_const_struct_foo* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct foo __fln__test1I_const_struct_foo_sec(__fln__test1I_const_struct_foo x) { return x.d; }
const struct foo* __fln__test1I_const_struct_foo_sec_ptr(__fln__test1I_const_struct_foo* x) { return &x->d; }
__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_tail_w(__fln__test2S_test3S_int x) {__fln__test1S_test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_int* __fln__test1S_test2S_test3S_int_tail_w_ptr(__fln__test2S_test3S_int* x) {__fln__test1S_test2S_test3S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_int __fln__test1S_test2S_test3S_int_tail_r(__fln__test1S_test2S_test3S_int x) { __fln__test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_int* __fln__test1S_test2S_test3S_int_tail_r_ptr(__fln__test1S_test2S_test3S_int* x) { __fln__test2S_test3S_int tmp = { .d = x->d }; __fln__test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_fst_w(__fln__test1S_int x) {__fln__test1S_test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_int* __fln__test1S_test2S_test3S_int_fst_w_ptr(__fln__test1S_int* x) {__fln__test1S_test2S_test3S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_int __fln__test1S_test2S_test3S_int_fst_r(__fln__test1S_test2S_test3S_int x) { __fln__test1S_int y = { .d = x.d }; return y; }
__fln__test1S_int* __fln__test1S_test2S_test3S_int_fst_r_ptr(__fln__test1S_test2S_test3S_int* x) { __fln__test1S_int tmp = { .d = x->d }; __fln__test1S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_snd_w(__fln__test2S_int x) {__fln__test1S_test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_int* __fln__test1S_test2S_test3S_int_snd_w_ptr(__fln__test2S_int* x) {__fln__test1S_test2S_test3S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_int __fln__test1S_test2S_test3S_int_snd_r(__fln__test1S_test2S_test3S_int x) { __fln__test2S_int y = { .d = x.d }; return y; }
__fln__test2S_int* __fln__test1S_test2S_test3S_int_snd_r_ptr(__fln__test1S_test2S_test3S_int* x) { __fln__test2S_int tmp = { .d = x->d }; __fln__test2S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_int __fln__test3S_int_intg(int x) {__fln__test3S_int y = { .d = x }; return y; }
__fln__test3S_int* __fln__test3S_int_intg_ptr(int* x) {__fln__test3S_int tmp = { .d = *x }; __fln__test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test3S_int_sec(__fln__test3S_int x) { return x.d; }
int* __fln__test3S_int_sec_ptr(__fln__test3S_int* x) { return &x->d; }
__fln__test2S_int __fln__test2S_int_intg(int x) {__fln__test2S_int y = { .d = x }; return y; }
__fln__test2S_int* __fln__test2S_int_intg_ptr(int* x) {__fln__test2S_int tmp = { .d = *x }; __fln__test2S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2S_int_sec(__fln__test2S_int x) { return x.d; }
int* __fln__test2S_int_sec_ptr(__fln__test2S_int* x) { return &x->d; }
__fln__test2S_test3S_int __fln__test2S_test3S_int_intg(int x) {__fln__test2S_test3S_int y = { .d = x }; return y; }
__fln__test2S_test3S_int* __fln__test2S_test3S_int_intg_ptr(int* x) {__fln__test2S_test3S_int tmp = { .d = *x }; __fln__test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2S_test3S_int_sec(__fln__test2S_test3S_int x) { return x.d; }
int* __fln__test2S_test3S_int_sec_ptr(__fln__test2S_test3S_int* x) { return &x->d; }
__fln__test1S_int __fln__test1S_int_intg(int x) {__fln__test1S_int y = { .d = x }; return y; }
__fln__test1S_int* __fln__test1S_int_intg_ptr(int* x) {__fln__test1S_int tmp = { .d = *x }; __fln__test1S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1S_int_sec(__fln__test1S_int x) { return x.d; }
int* __fln__test1S_int_sec_ptr(__fln__test1S_int* x) { return &x->d; }
__fln__test1S_test2S_test3S_int __fln__test1S_test2S_test3S_int_intg(int x) {__fln__test1S_test2S_test3S_int y = { .d = x }; return y; }
__fln__test1S_test2S_test3S_int* __fln__test1S_test2S_test3S_int_intg_ptr(int* x) {__fln__test1S_test2S_test3S_int tmp = { .d = *x }; __fln__test1S_test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1S_test2S_test3S_int_sec(__fln__test1S_test2S_test3S_int x) { return x.d; }
int* __fln__test1S_test2S_test3S_int_sec_ptr(__fln__test1S_test2S_test3S_int* x) { return &x->d; }
__fln__test2S_test3S_int __fln__test2S_test3S_int_tail_w(__fln__test3S_int x) {__fln__test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_int* __fln__test2S_test3S_int_tail_w_ptr(__fln__test3S_int* x) {__fln__test2S_test3S_int tmp = { .d = x->d }; __fln__test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_int __fln__test2S_test3S_int_tail_r(__fln__test2S_test3S_int x) { __fln__test3S_int y = { .d = x.d }; return y; }
__fln__test3S_int* __fln__test2S_test3S_int_tail_r_ptr(__fln__test2S_test3S_int* x) { __fln__test3S_int tmp = { .d = x->d }; __fln__test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_int __fln__test2S_test3S_int_fst_w(__fln__test2S_int x) {__fln__test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_int* __fln__test2S_test3S_int_fst_w_ptr(__fln__test2S_int* x) {__fln__test2S_test3S_int tmp = { .d = x->d }; __fln__test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_int __fln__test2S_test3S_int_fst_r(__fln__test2S_test3S_int x) { __fln__test2S_int y = { .d = x.d }; return y; }
__fln__test2S_int* __fln__test2S_test3S_int_fst_r_ptr(__fln__test2S_test3S_int* x) { __fln__test2S_int tmp = { .d = x->d }; __fln__test2S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_int __fln__test2S_test3S_int_snd_w(__fln__test3S_int x) {__fln__test2S_test3S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_int* __fln__test2S_test3S_int_snd_w_ptr(__fln__test3S_int* x) {__fln__test2S_test3S_int tmp = { .d = x->d }; __fln__test2S_test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_int __fln__test2S_test3S_int_snd_r(__fln__test2S_test3S_int x) { __fln__test3S_int y = { .d = x.d }; return y; }
__fln__test3S_int* __fln__test2S_test3S_int_snd_r_ptr(__fln__test2S_test3S_int* x) { __fln__test3S_int tmp = { .d = x->d }; __fln__test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_tail_w(__fln__test2I_test3I_test4I_int x) {__fln__test1I_test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_test4I_int* __fln__test1I_test2I_test3I_test4I_int_tail_w_ptr(__fln__test2I_test3I_test4I_int* x) {__fln__test1I_test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_tail_r(__fln__test1I_test2I_test3I_test4I_int x) { __fln__test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_test4I_int* __fln__test1I_test2I_test3I_test4I_int_tail_r_ptr(__fln__test1I_test2I_test3I_test4I_int* x) { __fln__test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_fst_w(__fln__test1I_int x) {__fln__test1I_test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_test4I_int* __fln__test1I_test2I_test3I_test4I_int_fst_w_ptr(__fln__test1I_int* x) {__fln__test1I_test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_int __fln__test1I_test2I_test3I_test4I_int_fst_r(__fln__test1I_test2I_test3I_test4I_int x) { __fln__test1I_int y = { .d = x.d }; return y; }
__fln__test1I_int* __fln__test1I_test2I_test3I_test4I_int_fst_r_ptr(__fln__test1I_test2I_test3I_test4I_int* x) { __fln__test1I_int tmp = { .d = x->d }; __fln__test1I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_snd_w(__fln__test2I_int x) {__fln__test1I_test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_test4I_int* __fln__test1I_test2I_test3I_test4I_int_snd_w_ptr(__fln__test2I_int* x) {__fln__test1I_test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test1I_test2I_test3I_test4I_int_snd_r(__fln__test1I_test2I_test3I_test4I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test1I_test2I_test3I_test4I_int_snd_r_ptr(__fln__test1I_test2I_test3I_test4I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4I_int __fln__test4I_int_intg(int x) {__fln__test4I_int y = { .d = x }; return y; }
__fln__test4I_int* __fln__test4I_int_intg_ptr(int* x) {__fln__test4I_int tmp = { .d = *x }; __fln__test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test4I_int_sec(__fln__test4I_int x) { return x.d; }
int* __fln__test4I_int_sec_ptr(__fln__test4I_int* x) { return &x->d; }
__fln__test3I_int __fln__test3I_int_intg(int x) {__fln__test3I_int y = { .d = x }; return y; }
__fln__test3I_int* __fln__test3I_int_intg_ptr(int* x) {__fln__test3I_int tmp = { .d = *x }; __fln__test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test3I_int_sec(__fln__test3I_int x) { return x.d; }
int* __fln__test3I_int_sec_ptr(__fln__test3I_int* x) { return &x->d; }
__fln__test3I_test4I_int __fln__test3I_test4I_int_intg(int x) {__fln__test3I_test4I_int y = { .d = x }; return y; }
__fln__test3I_test4I_int* __fln__test3I_test4I_int_intg_ptr(int* x) {__fln__test3I_test4I_int tmp = { .d = *x }; __fln__test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test3I_test4I_int_sec(__fln__test3I_test4I_int x) { return x.d; }
int* __fln__test3I_test4I_int_sec_ptr(__fln__test3I_test4I_int* x) { return &x->d; }
__fln__test2I_int __fln__test2I_int_intg(int x) {__fln__test2I_int y = { .d = x }; return y; }
__fln__test2I_int* __fln__test2I_int_intg_ptr(int* x) {__fln__test2I_int tmp = { .d = *x }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2I_int_sec(__fln__test2I_int x) { return x.d; }
int* __fln__test2I_int_sec_ptr(__fln__test2I_int* x) { return &x->d; }
__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_intg(int x) {__fln__test2I_test3I_test4I_int y = { .d = x }; return y; }
__fln__test2I_test3I_test4I_int* __fln__test2I_test3I_test4I_int_intg_ptr(int* x) {__fln__test2I_test3I_test4I_int tmp = { .d = *x }; __fln__test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2I_test3I_test4I_int_sec(__fln__test2I_test3I_test4I_int x) { return x.d; }
int* __fln__test2I_test3I_test4I_int_sec_ptr(__fln__test2I_test3I_test4I_int* x) { return &x->d; }
__fln__test1I_test2I_test3I_test4I_int __fln__test1I_test2I_test3I_test4I_int_intg(int x) {__fln__test1I_test2I_test3I_test4I_int y = { .d = x }; return y; }
__fln__test1I_test2I_test3I_test4I_int* __fln__test1I_test2I_test3I_test4I_int_intg_ptr(int* x) {__fln__test1I_test2I_test3I_test4I_int tmp = { .d = *x }; __fln__test1I_test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1I_test2I_test3I_test4I_int_sec(__fln__test1I_test2I_test3I_test4I_int x) { return x.d; }
int* __fln__test1I_test2I_test3I_test4I_int_sec_ptr(__fln__test1I_test2I_test3I_test4I_int* x) { return &x->d; }
__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_tail_w(__fln__test3I_test4I_int x) {__fln__test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_test4I_int* __fln__test2I_test3I_test4I_int_tail_w_ptr(__fln__test3I_test4I_int* x) {__fln__test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_test4I_int __fln__test2I_test3I_test4I_int_tail_r(__fln__test2I_test3I_test4I_int x) { __fln__test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test3I_test4I_int* __fln__test2I_test3I_test4I_int_tail_r_ptr(__fln__test2I_test3I_test4I_int* x) { __fln__test3I_test4I_int tmp = { .d = x->d }; __fln__test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_fst_w(__fln__test2I_int x) {__fln__test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_test4I_int* __fln__test2I_test3I_test4I_int_fst_w_ptr(__fln__test2I_int* x) {__fln__test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test2I_test3I_test4I_int_fst_r(__fln__test2I_test3I_test4I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test2I_test3I_test4I_int_fst_r_ptr(__fln__test2I_test3I_test4I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_test4I_int __fln__test2I_test3I_test4I_int_snd_w(__fln__test3I_int x) {__fln__test2I_test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_test4I_int* __fln__test2I_test3I_test4I_int_snd_w_ptr(__fln__test3I_int* x) {__fln__test2I_test3I_test4I_int tmp = { .d = x->d }; __fln__test2I_test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_int __fln__test2I_test3I_test4I_int_snd_r(__fln__test2I_test3I_test4I_int x) { __fln__test3I_int y = { .d = x.d }; return y; }
__fln__test3I_int* __fln__test2I_test3I_test4I_int_snd_r_ptr(__fln__test2I_test3I_test4I_int* x) { __fln__test3I_int tmp = { .d = x->d }; __fln__test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_test4I_int __fln__test3I_test4I_int_tail_w(__fln__test4I_int x) {__fln__test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test3I_test4I_int* __fln__test3I_test4I_int_tail_w_ptr(__fln__test4I_int* x) {__fln__test3I_test4I_int tmp = { .d = x->d }; __fln__test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4I_int __fln__test3I_test4I_int_tail_r(__fln__test3I_test4I_int x) { __fln__test4I_int y = { .d = x.d }; return y; }
__fln__test4I_int* __fln__test3I_test4I_int_tail_r_ptr(__fln__test3I_test4I_int* x) { __fln__test4I_int tmp = { .d = x->d }; __fln__test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_test4I_int __fln__test3I_test4I_int_fst_w(__fln__test3I_int x) {__fln__test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test3I_test4I_int* __fln__test3I_test4I_int_fst_w_ptr(__fln__test3I_int* x) {__fln__test3I_test4I_int tmp = { .d = x->d }; __fln__test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_int __fln__test3I_test4I_int_fst_r(__fln__test3I_test4I_int x) { __fln__test3I_int y = { .d = x.d }; return y; }
__fln__test3I_int* __fln__test3I_test4I_int_fst_r_ptr(__fln__test3I_test4I_int* x) { __fln__test3I_int tmp = { .d = x->d }; __fln__test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_test4I_int __fln__test3I_test4I_int_snd_w(__fln__test4I_int x) {__fln__test3I_test4I_int y = { .d = x.d }; return y; }
__fln__test3I_test4I_int* __fln__test3I_test4I_int_snd_w_ptr(__fln__test4I_int* x) {__fln__test3I_test4I_int tmp = { .d = x->d }; __fln__test3I_test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4I_int __fln__test3I_test4I_int_snd_r(__fln__test3I_test4I_int x) { __fln__test4I_int y = { .d = x.d }; return y; }
__fln__test4I_int* __fln__test3I_test4I_int_snd_r_ptr(__fln__test3I_test4I_int* x) { __fln__test4I_int tmp = { .d = x->d }; __fln__test4I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_int __fln__test1I_test2I_int_tail_w(__fln__test2I_int x) {__fln__test1I_test2I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_int* __fln__test1I_test2I_int_tail_w_ptr(__fln__test2I_int* x) {__fln__test1I_test2I_int tmp = { .d = x->d }; __fln__test1I_test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test1I_test2I_int_tail_r(__fln__test1I_test2I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test1I_test2I_int_tail_r_ptr(__fln__test1I_test2I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_int __fln__test1I_test2I_int_fst_w(__fln__test1I_int x) {__fln__test1I_test2I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_int* __fln__test1I_test2I_int_fst_w_ptr(__fln__test1I_int* x) {__fln__test1I_test2I_int tmp = { .d = x->d }; __fln__test1I_test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_int __fln__test1I_test2I_int_fst_r(__fln__test1I_test2I_int x) { __fln__test1I_int y = { .d = x.d }; return y; }
__fln__test1I_int* __fln__test1I_test2I_int_fst_r_ptr(__fln__test1I_test2I_int* x) { __fln__test1I_int tmp = { .d = x->d }; __fln__test1I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_int __fln__test1I_test2I_int_snd_w(__fln__test2I_int x) {__fln__test1I_test2I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_int* __fln__test1I_test2I_int_snd_w_ptr(__fln__test2I_int* x) {__fln__test1I_test2I_int tmp = { .d = x->d }; __fln__test1I_test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test1I_test2I_int_snd_r(__fln__test1I_test2I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test1I_test2I_int_snd_r_ptr(__fln__test1I_test2I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_int __fln__test1I_test2I_int_intg(int x) {__fln__test1I_test2I_int y = { .d = x }; return y; }
__fln__test1I_test2I_int* __fln__test1I_test2I_int_intg_ptr(int* x) {__fln__test1I_test2I_int tmp = { .d = *x }; __fln__test1I_test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1I_test2I_int_sec(__fln__test1I_test2I_int x) { return x.d; }
int* __fln__test1I_test2I_int_sec_ptr(__fln__test1I_test2I_int* x) { return &x->d; }
__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_tail_w(__fln__test2S_test3S_test4S_int x) {__fln__test1S_test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_test4S_int* __fln__test1S_test2S_test3S_test4S_int_tail_w_ptr(__fln__test2S_test3S_test4S_int* x) {__fln__test1S_test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_tail_r(__fln__test1S_test2S_test3S_test4S_int x) { __fln__test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_test4S_int* __fln__test1S_test2S_test3S_test4S_int_tail_r_ptr(__fln__test1S_test2S_test3S_test4S_int* x) { __fln__test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_fst_w(__fln__test1S_int x) {__fln__test1S_test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_test4S_int* __fln__test1S_test2S_test3S_test4S_int_fst_w_ptr(__fln__test1S_int* x) {__fln__test1S_test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_int __fln__test1S_test2S_test3S_test4S_int_fst_r(__fln__test1S_test2S_test3S_test4S_int x) { __fln__test1S_int y = { .d = x.d }; return y; }
__fln__test1S_int* __fln__test1S_test2S_test3S_test4S_int_fst_r_ptr(__fln__test1S_test2S_test3S_test4S_int* x) { __fln__test1S_int tmp = { .d = x->d }; __fln__test1S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_snd_w(__fln__test2S_int x) {__fln__test1S_test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_test3S_test4S_int* __fln__test1S_test2S_test3S_test4S_int_snd_w_ptr(__fln__test2S_int* x) {__fln__test1S_test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test1S_test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_int __fln__test1S_test2S_test3S_test4S_int_snd_r(__fln__test1S_test2S_test3S_test4S_int x) { __fln__test2S_int y = { .d = x.d }; return y; }
__fln__test2S_int* __fln__test1S_test2S_test3S_test4S_int_snd_r_ptr(__fln__test1S_test2S_test3S_test4S_int* x) { __fln__test2S_int tmp = { .d = x->d }; __fln__test2S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4S_int __fln__test4S_int_intg(int x) {__fln__test4S_int y = { .d = x }; return y; }
__fln__test4S_int* __fln__test4S_int_intg_ptr(int* x) {__fln__test4S_int tmp = { .d = *x }; __fln__test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test4S_int_sec(__fln__test4S_int x) { return x.d; }
int* __fln__test4S_int_sec_ptr(__fln__test4S_int* x) { return &x->d; }
__fln__test3S_test4S_int __fln__test3S_test4S_int_intg(int x) {__fln__test3S_test4S_int y = { .d = x }; return y; }
__fln__test3S_test4S_int* __fln__test3S_test4S_int_intg_ptr(int* x) {__fln__test3S_test4S_int tmp = { .d = *x }; __fln__test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test3S_test4S_int_sec(__fln__test3S_test4S_int x) { return x.d; }
int* __fln__test3S_test4S_int_sec_ptr(__fln__test3S_test4S_int* x) { return &x->d; }
__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_intg(int x) {__fln__test2S_test3S_test4S_int y = { .d = x }; return y; }
__fln__test2S_test3S_test4S_int* __fln__test2S_test3S_test4S_int_intg_ptr(int* x) {__fln__test2S_test3S_test4S_int tmp = { .d = *x }; __fln__test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2S_test3S_test4S_int_sec(__fln__test2S_test3S_test4S_int x) { return x.d; }
int* __fln__test2S_test3S_test4S_int_sec_ptr(__fln__test2S_test3S_test4S_int* x) { return &x->d; }
__fln__test1S_test2S_test3S_test4S_int __fln__test1S_test2S_test3S_test4S_int_intg(int x) {__fln__test1S_test2S_test3S_test4S_int y = { .d = x }; return y; }
__fln__test1S_test2S_test3S_test4S_int* __fln__test1S_test2S_test3S_test4S_int_intg_ptr(int* x) {__fln__test1S_test2S_test3S_test4S_int tmp = { .d = *x }; __fln__test1S_test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1S_test2S_test3S_test4S_int_sec(__fln__test1S_test2S_test3S_test4S_int x) { return x.d; }
int* __fln__test1S_test2S_test3S_test4S_int_sec_ptr(__fln__test1S_test2S_test3S_test4S_int* x) { return &x->d; }
__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_tail_w(__fln__test3S_test4S_int x) {__fln__test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_test4S_int* __fln__test2S_test3S_test4S_int_tail_w_ptr(__fln__test3S_test4S_int* x) {__fln__test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_test4S_int __fln__test2S_test3S_test4S_int_tail_r(__fln__test2S_test3S_test4S_int x) { __fln__test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test3S_test4S_int* __fln__test2S_test3S_test4S_int_tail_r_ptr(__fln__test2S_test3S_test4S_int* x) { __fln__test3S_test4S_int tmp = { .d = x->d }; __fln__test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_fst_w(__fln__test2S_int x) {__fln__test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_test4S_int* __fln__test2S_test3S_test4S_int_fst_w_ptr(__fln__test2S_int* x) {__fln__test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_int __fln__test2S_test3S_test4S_int_fst_r(__fln__test2S_test3S_test4S_int x) { __fln__test2S_int y = { .d = x.d }; return y; }
__fln__test2S_int* __fln__test2S_test3S_test4S_int_fst_r_ptr(__fln__test2S_test3S_test4S_int* x) { __fln__test2S_int tmp = { .d = x->d }; __fln__test2S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_test3S_test4S_int __fln__test2S_test3S_test4S_int_snd_w(__fln__test3S_int x) {__fln__test2S_test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test2S_test3S_test4S_int* __fln__test2S_test3S_test4S_int_snd_w_ptr(__fln__test3S_int* x) {__fln__test2S_test3S_test4S_int tmp = { .d = x->d }; __fln__test2S_test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_int __fln__test2S_test3S_test4S_int_snd_r(__fln__test2S_test3S_test4S_int x) { __fln__test3S_int y = { .d = x.d }; return y; }
__fln__test3S_int* __fln__test2S_test3S_test4S_int_snd_r_ptr(__fln__test2S_test3S_test4S_int* x) { __fln__test3S_int tmp = { .d = x->d }; __fln__test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_test4S_int __fln__test3S_test4S_int_tail_w(__fln__test4S_int x) {__fln__test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test3S_test4S_int* __fln__test3S_test4S_int_tail_w_ptr(__fln__test4S_int* x) {__fln__test3S_test4S_int tmp = { .d = x->d }; __fln__test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4S_int __fln__test3S_test4S_int_tail_r(__fln__test3S_test4S_int x) { __fln__test4S_int y = { .d = x.d }; return y; }
__fln__test4S_int* __fln__test3S_test4S_int_tail_r_ptr(__fln__test3S_test4S_int* x) { __fln__test4S_int tmp = { .d = x->d }; __fln__test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_test4S_int __fln__test3S_test4S_int_fst_w(__fln__test3S_int x) {__fln__test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test3S_test4S_int* __fln__test3S_test4S_int_fst_w_ptr(__fln__test3S_int* x) {__fln__test3S_test4S_int tmp = { .d = x->d }; __fln__test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_int __fln__test3S_test4S_int_fst_r(__fln__test3S_test4S_int x) { __fln__test3S_int y = { .d = x.d }; return y; }
__fln__test3S_int* __fln__test3S_test4S_int_fst_r_ptr(__fln__test3S_test4S_int* x) { __fln__test3S_int tmp = { .d = x->d }; __fln__test3S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3S_test4S_int __fln__test3S_test4S_int_snd_w(__fln__test4S_int x) {__fln__test3S_test4S_int y = { .d = x.d }; return y; }
__fln__test3S_test4S_int* __fln__test3S_test4S_int_snd_w_ptr(__fln__test4S_int* x) {__fln__test3S_test4S_int tmp = { .d = x->d }; __fln__test3S_test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test4S_int __fln__test3S_test4S_int_snd_r(__fln__test3S_test4S_int x) { __fln__test4S_int y = { .d = x.d }; return y; }
__fln__test4S_int* __fln__test3S_test4S_int_snd_r_ptr(__fln__test3S_test4S_int* x) { __fln__test4S_int tmp = { .d = x->d }; __fln__test4S_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_tail_w(__fln__test2I_test3I_int x) {__fln__test1I_test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_int* __fln__test1I_test2I_test3I_int_tail_w_ptr(__fln__test2I_test3I_int* x) {__fln__test1I_test2I_test3I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_int __fln__test1I_test2I_test3I_int_tail_r(__fln__test1I_test2I_test3I_int x) { __fln__test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_int* __fln__test1I_test2I_test3I_int_tail_r_ptr(__fln__test1I_test2I_test3I_int* x) { __fln__test2I_test3I_int tmp = { .d = x->d }; __fln__test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_fst_w(__fln__test1I_int x) {__fln__test1I_test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_int* __fln__test1I_test2I_test3I_int_fst_w_ptr(__fln__test1I_int* x) {__fln__test1I_test2I_test3I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_int __fln__test1I_test2I_test3I_int_fst_r(__fln__test1I_test2I_test3I_int x) { __fln__test1I_int y = { .d = x.d }; return y; }
__fln__test1I_int* __fln__test1I_test2I_test3I_int_fst_r_ptr(__fln__test1I_test2I_test3I_int* x) { __fln__test1I_int tmp = { .d = x->d }; __fln__test1I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_snd_w(__fln__test2I_int x) {__fln__test1I_test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test1I_test2I_test3I_int* __fln__test1I_test2I_test3I_int_snd_w_ptr(__fln__test2I_int* x) {__fln__test1I_test2I_test3I_int tmp = { .d = x->d }; __fln__test1I_test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test1I_test2I_test3I_int_snd_r(__fln__test1I_test2I_test3I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test1I_test2I_test3I_int_snd_r_ptr(__fln__test1I_test2I_test3I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_int __fln__test2I_test3I_int_intg(int x) {__fln__test2I_test3I_int y = { .d = x }; return y; }
__fln__test2I_test3I_int* __fln__test2I_test3I_int_intg_ptr(int* x) {__fln__test2I_test3I_int tmp = { .d = *x }; __fln__test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test2I_test3I_int_sec(__fln__test2I_test3I_int x) { return x.d; }
int* __fln__test2I_test3I_int_sec_ptr(__fln__test2I_test3I_int* x) { return &x->d; }
__fln__test1I_test2I_test3I_int __fln__test1I_test2I_test3I_int_intg(int x) {__fln__test1I_test2I_test3I_int y = { .d = x }; return y; }
__fln__test1I_test2I_test3I_int* __fln__test1I_test2I_test3I_int_intg_ptr(int* x) {__fln__test1I_test2I_test3I_int tmp = { .d = *x }; __fln__test1I_test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__test1I_test2I_test3I_int_sec(__fln__test1I_test2I_test3I_int x) { return x.d; }
int* __fln__test1I_test2I_test3I_int_sec_ptr(__fln__test1I_test2I_test3I_int* x) { return &x->d; }
__fln__test2I_test3I_int __fln__test2I_test3I_int_tail_w(__fln__test3I_int x) {__fln__test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_int* __fln__test2I_test3I_int_tail_w_ptr(__fln__test3I_int* x) {__fln__test2I_test3I_int tmp = { .d = x->d }; __fln__test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_int __fln__test2I_test3I_int_tail_r(__fln__test2I_test3I_int x) { __fln__test3I_int y = { .d = x.d }; return y; }
__fln__test3I_int* __fln__test2I_test3I_int_tail_r_ptr(__fln__test2I_test3I_int* x) { __fln__test3I_int tmp = { .d = x->d }; __fln__test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_int __fln__test2I_test3I_int_fst_w(__fln__test2I_int x) {__fln__test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_int* __fln__test2I_test3I_int_fst_w_ptr(__fln__test2I_int* x) {__fln__test2I_test3I_int tmp = { .d = x->d }; __fln__test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_int __fln__test2I_test3I_int_fst_r(__fln__test2I_test3I_int x) { __fln__test2I_int y = { .d = x.d }; return y; }
__fln__test2I_int* __fln__test2I_test3I_int_fst_r_ptr(__fln__test2I_test3I_int* x) { __fln__test2I_int tmp = { .d = x->d }; __fln__test2I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_test3I_int __fln__test2I_test3I_int_snd_w(__fln__test3I_int x) {__fln__test2I_test3I_int y = { .d = x.d }; return y; }
__fln__test2I_test3I_int* __fln__test2I_test3I_int_snd_w_ptr(__fln__test3I_int* x) {__fln__test2I_test3I_int tmp = { .d = x->d }; __fln__test2I_test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test3I_int __fln__test2I_test3I_int_snd_r(__fln__test2I_test3I_int x) { __fln__test3I_int y = { .d = x.d }; return y; }
__fln__test3I_int* __fln__test2I_test3I_int_snd_r_ptr(__fln__test2I_test3I_int* x) { __fln__test3I_int tmp = { .d = x->d }; __fln__test3I_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_tail_w(__fln__test2I_struct_foo1 x) {__fln__test1I_test2I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1I_test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_tail_w_ptr(__fln__test2I_struct_foo1* x) {__fln__test1I_test2I_struct_foo1 tmp = { .d = x->d }; __fln__test1I_test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_tail_r(__fln__test1I_test2I_struct_foo1 x) { __fln__test2I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_tail_r_ptr(__fln__test1I_test2I_struct_foo1* x) { __fln__test2I_struct_foo1 tmp = { .d = x->d }; __fln__test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_fst_w(__fln__test1I_struct_foo1 x) {__fln__test1I_test2I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1I_test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_fst_w_ptr(__fln__test1I_struct_foo1* x) {__fln__test1I_test2I_struct_foo1 tmp = { .d = x->d }; __fln__test1I_test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_struct_foo1 __fln__test1I_test2I_struct_foo1_fst_r(__fln__test1I_test2I_struct_foo1 x) { __fln__test1I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1I_struct_foo1* __fln__test1I_test2I_struct_foo1_fst_r_ptr(__fln__test1I_test2I_struct_foo1* x) { __fln__test1I_struct_foo1 tmp = { .d = x->d }; __fln__test1I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_snd_w(__fln__test2I_struct_foo1 x) {__fln__test1I_test2I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test1I_test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_snd_w_ptr(__fln__test2I_struct_foo1* x) {__fln__test1I_test2I_struct_foo1 tmp = { .d = x->d }; __fln__test1I_test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_snd_r(__fln__test1I_test2I_struct_foo1 x) { __fln__test2I_struct_foo1 y = { .d = x.d }; return y; }
__fln__test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_snd_r_ptr(__fln__test1I_test2I_struct_foo1* x) { __fln__test2I_struct_foo1 tmp = { .d = x->d }; __fln__test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2I_struct_foo1 __fln__test2I_struct_foo1_intg(struct foo1 x) {__fln__test2I_struct_foo1 y = { .d = x }; return y; }
__fln__test2I_struct_foo1* __fln__test2I_struct_foo1_intg_ptr(struct foo1* x) {__fln__test2I_struct_foo1 tmp = { .d = *x }; __fln__test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
struct foo1 __fln__test2I_struct_foo1_sec(__fln__test2I_struct_foo1 x) { return x.d; }
struct foo1* __fln__test2I_struct_foo1_sec_ptr(__fln__test2I_struct_foo1* x) { return &x->d; }
__fln__test1I_test2I_struct_foo1 __fln__test1I_test2I_struct_foo1_intg(struct foo1 x) {__fln__test1I_test2I_struct_foo1 y = { .d = x }; return y; }
__fln__test1I_test2I_struct_foo1* __fln__test1I_test2I_struct_foo1_intg_ptr(struct foo1* x) {__fln__test1I_test2I_struct_foo1 tmp = { .d = *x }; __fln__test1I_test2I_struct_foo1* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
struct foo1 __fln__test1I_test2I_struct_foo1_sec(__fln__test1I_test2I_struct_foo1 x) { return x.d; }
struct foo1* __fln__test1I_test2I_struct_foo1_sec_ptr(__fln__test1I_test2I_struct_foo1* x) { return &x->d; }
__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_tail_w(__fln__test2S_const_int x) {__fln__test1S_test2S_const_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_int* __fln__test1S_test2S_const_int_tail_w_ptr(__fln__test2S_const_int* x) {__fln__test1S_test2S_const_int tmp = { .d = x->d }; __fln__test1S_test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_int __fln__test1S_test2S_const_int_tail_r(__fln__test1S_test2S_const_int x) { __fln__test2S_const_int y = { .d = x.d }; return y; }
__fln__test2S_const_int* __fln__test1S_test2S_const_int_tail_r_ptr(__fln__test1S_test2S_const_int* x) { __fln__test2S_const_int tmp = { .d = x->d }; __fln__test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_fst_w(__fln__test1S_const_int x) {__fln__test1S_test2S_const_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_int* __fln__test1S_test2S_const_int_fst_w_ptr(__fln__test1S_const_int* x) {__fln__test1S_test2S_const_int tmp = { .d = x->d }; __fln__test1S_test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_const_int __fln__test1S_test2S_const_int_fst_r(__fln__test1S_test2S_const_int x) { __fln__test1S_const_int y = { .d = x.d }; return y; }
__fln__test1S_const_int* __fln__test1S_test2S_const_int_fst_r_ptr(__fln__test1S_test2S_const_int* x) { __fln__test1S_const_int tmp = { .d = x->d }; __fln__test1S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_snd_w(__fln__test2S_const_int x) {__fln__test1S_test2S_const_int y = { .d = x.d }; return y; }
__fln__test1S_test2S_const_int* __fln__test1S_test2S_const_int_snd_w_ptr(__fln__test2S_const_int* x) {__fln__test1S_test2S_const_int tmp = { .d = x->d }; __fln__test1S_test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_int __fln__test1S_test2S_const_int_snd_r(__fln__test1S_test2S_const_int x) { __fln__test2S_const_int y = { .d = x.d }; return y; }
__fln__test2S_const_int* __fln__test1S_test2S_const_int_snd_r_ptr(__fln__test1S_test2S_const_int* x) { __fln__test2S_const_int tmp = { .d = x->d }; __fln__test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__test2S_const_int __fln__test2S_const_int_intg(const int x) {__fln__test2S_const_int y = { .d = x }; return y; }
__fln__test2S_const_int* __fln__test2S_const_int_intg_ptr(const int* x) {__fln__test2S_const_int tmp = { .d = *x }; __fln__test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const int __fln__test2S_const_int_sec(__fln__test2S_const_int x) { return x.d; }
const int* __fln__test2S_const_int_sec_ptr(__fln__test2S_const_int* x) { return &x->d; }
__fln__test1S_const_int __fln__test1S_const_int_intg(const int x) {__fln__test1S_const_int y = { .d = x }; return y; }
__fln__test1S_const_int* __fln__test1S_const_int_intg_ptr(const int* x) {__fln__test1S_const_int tmp = { .d = *x }; __fln__test1S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const int __fln__test1S_const_int_sec(__fln__test1S_const_int x) { return x.d; }
const int* __fln__test1S_const_int_sec_ptr(__fln__test1S_const_int* x) { return &x->d; }
__fln__test1S_test2S_const_int __fln__test1S_test2S_const_int_intg(const int x) {__fln__test1S_test2S_const_int y = { .d = x }; return y; }
__fln__test1S_test2S_const_int* __fln__test1S_test2S_const_int_intg_ptr(const int* x) {__fln__test1S_test2S_const_int tmp = { .d = *x }; __fln__test1S_test2S_const_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const int __fln__test1S_test2S_const_int_sec(__fln__test1S_test2S_const_int x) { return x.d; }
const int* __fln__test1S_test2S_const_int_sec_ptr(__fln__test1S_test2S_const_int* x) { return &x->d; }
__fln__test1I_struct_foo __fln__test1I_struct_foo_intg(struct foo x) {__fln__test1I_struct_foo y = { .d = x }; return y; }
__fln__test1I_struct_foo* __fln__test1I_struct_foo_intg_ptr(struct foo* x) {__fln__test1I_struct_foo tmp = { .d = *x }; __fln__test1I_struct_foo* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
struct foo __fln__test1I_struct_foo_sec(__fln__test1I_struct_foo x) { return x.d; }
struct foo* __fln__test1I_struct_foo_sec_ptr(__fln__test1I_struct_foo* x) { return &x->d; }
#endif