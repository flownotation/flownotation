#ifndef SHA3__FLN__FLN_H__
#define SHA3__FLN__FLN_H__
#include "sha3.h"
typedef struct {sha3_ctx_t d; } __fln__sha3_initS_sha3_ctx_t;
typedef struct {sha3_ctx_t d; } __fln__sha3_updatedS_sha3_ctx_t;
typedef struct {sha3_ctx_t d; } __fln__sha3_uninitS_sha3_ctx_t;
typedef struct {sha3_ctx_t d; } __fln__sha3_initS_sha3_updatedS_sha3_ctx_t;
typedef struct {sha3_ctx_t d; } __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t;
__fln__sha3_initS_sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_initS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_initS_sha3_ctx_t* __fln__sha3_initS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_initS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_initS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_initS_sha3_ctx_t_sec(__fln__sha3_initS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_initS_sha3_ctx_t_sec_ptr(__fln__sha3_initS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_updatedS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_updatedS_sha3_ctx_t* __fln__sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_updatedS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_updatedS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_updatedS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_uninitS_sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_uninitS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_uninitS_sha3_ctx_t* __fln__sha3_uninitS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_uninitS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_uninitS_sha3_ctx_t_sec(__fln__sha3_uninitS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_uninitS_sha3_ctx_t_sec_ptr(__fln__sha3_uninitS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w(__fln__sha3_uninitS_sha3_ctx_t x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w_ptr(__fln__sha3_uninitS_sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_uninitS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_uninitS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_uninitS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_uninitS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_uninitS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w(__fln__sha3_initS_sha3_ctx_t x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w_ptr(__fln__sha3_initS_sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_initS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_initS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_intg(sha3_ctx_t x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x }; return y; }
__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_intg_ptr(sha3_ctx_t* x) {__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = *x }; __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
sha3_ctx_t __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_sec(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t x) { return x.d; }
sha3_ctx_t* __fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t_sec_ptr(__fln__sha3_uninitS_sha3_initS_sha3_updatedS_sha3_ctx_t* x) { return &x->d; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w(__fln__sha3_updatedS_sha3_ctx_t x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_w_ptr(__fln__sha3_updatedS_sha3_ctx_t* x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_tail_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w(__fln__sha3_initS_sha3_ctx_t x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_w_ptr(__fln__sha3_initS_sha3_ctx_t* x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_initS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_fst_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_initS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w(__fln__sha3_updatedS_sha3_ctx_t x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_w_ptr(__fln__sha3_updatedS_sha3_ctx_t* x) {__fln__sha3_initS_sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_initS_sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__sha3_updatedS_sha3_ctx_t __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t x) { __fln__sha3_updatedS_sha3_ctx_t y = { .d = x.d }; return y; }
__fln__sha3_updatedS_sha3_ctx_t* __fln__sha3_initS_sha3_updatedS_sha3_ctx_t_snd_r_ptr(__fln__sha3_initS_sha3_updatedS_sha3_ctx_t* x) { __fln__sha3_updatedS_sha3_ctx_t tmp = { .d = x->d }; __fln__sha3_updatedS_sha3_ctx_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
#endif