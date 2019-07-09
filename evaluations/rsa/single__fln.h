#ifndef SINGLE__FLN__FLN_H__
#define SINGLE__FLN__FLN_H__
typedef struct {int d; } __fln__public_keyS_int;
typedef struct {int d; } __fln__encodeI_int;
typedef struct {int d; } __fln__primeI_int;
typedef struct {int d; } __fln__private_keyS_int;
typedef struct {int d; } __fln__decodeI_int;
__fln__public_keyS_int __fln__public_keyS_int_intg(int x) {__fln__public_keyS_int y = { .d = x }; return y; }
__fln__public_keyS_int* __fln__public_keyS_int_intg_ptr(int* x) {__fln__public_keyS_int tmp = { .d = *x }; __fln__public_keyS_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__public_keyS_int_sec(__fln__public_keyS_int x) { return x.d; }
int* __fln__public_keyS_int_sec_ptr(__fln__public_keyS_int* x) { return &x->d; }
__fln__encodeI_int __fln__encodeI_int_intg(int x) {__fln__encodeI_int y = { .d = x }; return y; }
__fln__encodeI_int* __fln__encodeI_int_intg_ptr(int* x) {__fln__encodeI_int tmp = { .d = *x }; __fln__encodeI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__encodeI_int_sec(__fln__encodeI_int x) { return x.d; }
int* __fln__encodeI_int_sec_ptr(__fln__encodeI_int* x) { return &x->d; }
__fln__primeI_int __fln__primeI_int_intg(int x) {__fln__primeI_int y = { .d = x }; return y; }
__fln__primeI_int* __fln__primeI_int_intg_ptr(int* x) {__fln__primeI_int tmp = { .d = *x }; __fln__primeI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__primeI_int_sec(__fln__primeI_int x) { return x.d; }
int* __fln__primeI_int_sec_ptr(__fln__primeI_int* x) { return &x->d; }
__fln__private_keyS_int __fln__private_keyS_int_intg(int x) {__fln__private_keyS_int y = { .d = x }; return y; }
__fln__private_keyS_int* __fln__private_keyS_int_intg_ptr(int* x) {__fln__private_keyS_int tmp = { .d = *x }; __fln__private_keyS_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__private_keyS_int_sec(__fln__private_keyS_int x) { return x.d; }
int* __fln__private_keyS_int_sec_ptr(__fln__private_keyS_int* x) { return &x->d; }
__fln__decodeI_int __fln__decodeI_int_intg(int x) {__fln__decodeI_int y = { .d = x }; return y; }
__fln__decodeI_int* __fln__decodeI_int_intg_ptr(int* x) {__fln__decodeI_int tmp = { .d = *x }; __fln__decodeI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__decodeI_int_sec(__fln__decodeI_int x) { return x.d; }
int* __fln__decodeI_int_sec_ptr(__fln__decodeI_int* x) { return &x->d; }
#endif