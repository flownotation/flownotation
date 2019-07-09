#ifndef OT_PROTO__FLN__FLN_H__
#define OT_PROTO__FLN__FLN_H__
#include "ot_proto.h"
typedef struct {int d; } __fln__randomI_int;
typedef struct {pair d; } __fln__RSAkeyI_pair;
typedef struct {pair d; } __fln__RSAkeyS_pair;
typedef struct {int d; } __fln__secretS_int;
typedef struct {int d; } __fln__randomS_int;
__fln__randomI_int __fln__randomI_int_intg(int x) {__fln__randomI_int y = { .d = x }; return y; }
__fln__randomI_int* __fln__randomI_int_intg_ptr(int* x) {__fln__randomI_int tmp = { .d = *x }; __fln__randomI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__randomI_int_sec(__fln__randomI_int x) { return x.d; }
int* __fln__randomI_int_sec_ptr(__fln__randomI_int* x) { return &x->d; }
__fln__RSAkeyI_pair __fln__RSAkeyI_pair_intg(pair x) {__fln__RSAkeyI_pair y = { .d = x }; return y; }
__fln__RSAkeyI_pair* __fln__RSAkeyI_pair_intg_ptr(pair* x) {__fln__RSAkeyI_pair tmp = { .d = *x }; __fln__RSAkeyI_pair* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
pair __fln__RSAkeyI_pair_sec(__fln__RSAkeyI_pair x) { return x.d; }
pair* __fln__RSAkeyI_pair_sec_ptr(__fln__RSAkeyI_pair* x) { return &x->d; }
__fln__RSAkeyS_pair __fln__RSAkeyS_pair_intg(pair x) {__fln__RSAkeyS_pair y = { .d = x }; return y; }
__fln__RSAkeyS_pair* __fln__RSAkeyS_pair_intg_ptr(pair* x) {__fln__RSAkeyS_pair tmp = { .d = *x }; __fln__RSAkeyS_pair* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
pair __fln__RSAkeyS_pair_sec(__fln__RSAkeyS_pair x) { return x.d; }
pair* __fln__RSAkeyS_pair_sec_ptr(__fln__RSAkeyS_pair* x) { return &x->d; }
__fln__secretS_int __fln__secretS_int_intg(int x) {__fln__secretS_int y = { .d = x }; return y; }
__fln__secretS_int* __fln__secretS_int_intg_ptr(int* x) {__fln__secretS_int tmp = { .d = *x }; __fln__secretS_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__secretS_int_sec(__fln__secretS_int x) { return x.d; }
int* __fln__secretS_int_sec_ptr(__fln__secretS_int* x) { return &x->d; }
__fln__randomS_int __fln__randomS_int_intg(int x) {__fln__randomS_int y = { .d = x }; return y; }
__fln__randomS_int* __fln__randomS_int_intg_ptr(int* x) {__fln__randomS_int tmp = { .d = *x }; __fln__randomS_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__randomS_int_sec(__fln__randomS_int x) { return x.d; }
int* __fln__randomS_int_sec_ptr(__fln__randomS_int* x) { return &x->d; }
#endif