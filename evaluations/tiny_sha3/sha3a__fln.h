#ifndef SHA3A__FLN__FLN_H__
#define SHA3A__FLN__FLN_H__
#include "sha3.h"
typedef struct {sha3_ctx_t d; } __fln__sha3_updatedI_sha3_ctx_t;
typedef struct {size_t d; } __fln__len_uncheckedI_size_t;
typedef struct {int d; } __fln__len_checkI_int;
typedef struct {sha3_ctx_t d; } __fln__sha3_initI_sha3_ctx_t;
typedef struct {size_t d; } __fln__len_checkedI_size_t;
typedef struct {int d; } __fln__sha3_init_checkI_int;
typedef struct {sha3_ctx_t d; } __fln__sha3_initS_sha3_ctx_t;
typedef struct {sha3_ctx_t d; } __fln__sha3_updatedS_sha3_ctx_t;
typedef struct {int d; } __fln__sha3_update_checkI_int;
typedef struct {int d; } __fln__len_checkedI_int;
typedef struct {sha3_ctx_t d; } __fln__sha3_uninitS_sha3_ctx_t;
__fln__sha3_updatedI_sha3_ctx_t __fln__sha3_updatedI_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_updatedI_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_updatedI_sha3_ctx_t* __fln__sha3_updatedI_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_updatedI_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_updatedI_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_updatedI_sha3_ctx_t_sec(__fln__sha3_updatedI_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_updatedI_sha3_ctx_t_sec_ptr(__fln__sha3_updatedI_sha3_ctx_t* x) { return &x->d; }
__fln__len_uncheckedI_size_t __fln__len_uncheckedI_size_t_intg(size_t x) {__fln__len_uncheckedI_size_t y = { .d = x }; return y; }
__fln__len_uncheckedI_size_t* __fln__len_uncheckedI_size_t_intg_ptr(size_t* x) {__fln__len_uncheckedI_size_t tmp = { .d = *x }; __fln__len_uncheckedI_size_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
size_t __fln__len_uncheckedI_size_t_sec(__fln__len_uncheckedI_size_t x) { return x.d; }
size_t* __fln__len_uncheckedI_size_t_sec_ptr(__fln__len_uncheckedI_size_t* x) { return &x->d; }
__fln__len_checkI_int __fln__len_checkI_int_intg(int x) {__fln__len_checkI_int y = { .d = x }; return y; }
__fln__len_checkI_int* __fln__len_checkI_int_intg_ptr(int* x) {__fln__len_checkI_int tmp = { .d = *x }; __fln__len_checkI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__len_checkI_int_sec(__fln__len_checkI_int x) { return x.d; }
int* __fln__len_checkI_int_sec_ptr(__fln__len_checkI_int* x) { return &x->d; }
__fln__sha3_initI_sha3_ctx_t __fln__sha3_initI_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_initI_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_initI_sha3_ctx_t* __fln__sha3_initI_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_initI_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_initI_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_initI_sha3_ctx_t_sec(__fln__sha3_initI_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_initI_sha3_ctx_t_sec_ptr(__fln__sha3_initI_sha3_ctx_t* x) { return &x->d; }
__fln__len_checkedI_size_t __fln__len_checkedI_size_t_intg(size_t x) {__fln__len_checkedI_size_t y = { .d = x }; return y; }
__fln__len_checkedI_size_t* __fln__len_checkedI_size_t_intg_ptr(size_t* x) {__fln__len_checkedI_size_t tmp = { .d = *x }; __fln__len_checkedI_size_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
size_t __fln__len_checkedI_size_t_sec(__fln__len_checkedI_size_t x) { return x.d; }
size_t* __fln__len_checkedI_size_t_sec_ptr(__fln__len_checkedI_size_t* x) { return &x->d; }
__fln__sha3_init_checkI_int __fln__sha3_init_checkI_int_intg(int x) {__fln__sha3_init_checkI_int y = { .d = x }; return y; }
__fln__sha3_init_checkI_int* __fln__sha3_init_checkI_int_intg_ptr(int* x) {__fln__sha3_init_checkI_int tmp = { .d = *x }; __fln__sha3_init_checkI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__sha3_init_checkI_int_sec(__fln__sha3_init_checkI_int x) { return x.d; }
int* __fln__sha3_init_checkI_int_sec_ptr(__fln__sha3_init_checkI_int* x) { return &x->d; }
__fln__sha3_initS_sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_initS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_initS_sha3_ctx_t* __fln__sha3_initS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_initS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_initS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_sec(__fln__sha3_initS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_initS_sha3_ctx_t_sec_ptr(__fln__sha3_initS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_updatedS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_updatedS_sha3_ctx_t* __fln__sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_updatedS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_updatedS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_updatedS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_update_checkI_int __fln__sha3_update_checkI_int_intg(int x) {__fln__sha3_update_checkI_int y = { .d = x }; return y; }
__fln__sha3_update_checkI_int* __fln__sha3_update_checkI_int_intg_ptr(int* x) {__fln__sha3_update_checkI_int tmp = { .d = *x }; __fln__sha3_update_checkI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__sha3_update_checkI_int_sec(__fln__sha3_update_checkI_int x) { return x.d; }
int* __fln__sha3_update_checkI_int_sec_ptr(__fln__sha3_update_checkI_int* x) { return &x->d; }
__fln__len_checkedI_int __fln__len_checkedI_int_intg(int x) {__fln__len_checkedI_int y = { .d = x }; return y; }
__fln__len_checkedI_int* __fln__len_checkedI_int_intg_ptr(int* x) {__fln__len_checkedI_int tmp = { .d = *x }; __fln__len_checkedI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__len_checkedI_int_sec(__fln__len_checkedI_int x) { return x.d; }
int* __fln__len_checkedI_int_sec_ptr(__fln__len_checkedI_int* x) { return &x->d; }
__fln__sha3_uninitS_sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_uninitS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_uninitS_sha3_ctx_t* __fln__sha3_uninitS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_uninitS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_sec(__fln__sha3_uninitS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_uninitS_sha3_ctx_t_sec_ptr(__fln__sha3_uninitS_sha3_ctx_t* x) { return &x->d; }
#endif