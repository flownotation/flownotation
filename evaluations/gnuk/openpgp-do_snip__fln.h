#ifndef OPENPGP_DO_SNIP__FLN__FLN_H__
#define OPENPGP_DO_SNIP__FLN__FLN_H__
typedef struct {int d; } __fln__no_prvkey_sigI_int;
typedef struct {int d; } __fln__check_lenI_int;
typedef struct {int d; } __fln__no_prvkey_autI_int;
typedef struct {const uint8_t d; } __fln__check_valid_ptrI_const_uint8_t;
typedef struct {int d; } __fln__no_prvkey_decI_int;
typedef struct {int d; } __fln__no_prvkey_decI_no_prvkey_autI_int;
typedef struct {int d; } __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int;
__fln__no_prvkey_sigI_int __fln__no_prvkey_sigI_int_intg(int x) {__fln__no_prvkey_sigI_int y = { .d = x }; return y; }
__fln__no_prvkey_sigI_int* __fln__no_prvkey_sigI_int_intg_ptr(int* x) {__fln__no_prvkey_sigI_int tmp = { .d = *x }; __fln__no_prvkey_sigI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__no_prvkey_sigI_int_sec(__fln__no_prvkey_sigI_int x) { return x.d; }
int* __fln__no_prvkey_sigI_int_sec_ptr(__fln__no_prvkey_sigI_int* x) { return &x->d; }
__fln__check_lenI_int __fln__check_lenI_int_intg(int x) {__fln__check_lenI_int y = { .d = x }; return y; }
__fln__check_lenI_int* __fln__check_lenI_int_intg_ptr(int* x) {__fln__check_lenI_int tmp = { .d = *x }; __fln__check_lenI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__check_lenI_int_sec(__fln__check_lenI_int x) { return x.d; }
int* __fln__check_lenI_int_sec_ptr(__fln__check_lenI_int* x) { return &x->d; }
__fln__no_prvkey_autI_int __fln__no_prvkey_autI_int_intg(int x) {__fln__no_prvkey_autI_int y = { .d = x }; return y; }
__fln__no_prvkey_autI_int* __fln__no_prvkey_autI_int_intg_ptr(int* x) {__fln__no_prvkey_autI_int tmp = { .d = *x }; __fln__no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__no_prvkey_autI_int_sec(__fln__no_prvkey_autI_int x) { return x.d; }
int* __fln__no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_autI_int* x) { return &x->d; }
__fln__check_valid_ptrI_const_uint8_t __fln__check_valid_ptrI_const_uint8_t_intg(const uint8_t x) {__fln__check_valid_ptrI_const_uint8_t y = { .d = x }; return y; }
__fln__check_valid_ptrI_const_uint8_t* __fln__check_valid_ptrI_const_uint8_t_intg_ptr(const uint8_t* x) {__fln__check_valid_ptrI_const_uint8_t tmp = { .d = *x }; __fln__check_valid_ptrI_const_uint8_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const uint8_t __fln__check_valid_ptrI_const_uint8_t_sec(__fln__check_valid_ptrI_const_uint8_t x) { return x.d; }
const uint8_t* __fln__check_valid_ptrI_const_uint8_t_sec_ptr(__fln__check_valid_ptrI_const_uint8_t* x) { return &x->d; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_w(__fln__no_prvkey_decI_no_prvkey_autI_int x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_w_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int* x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_tail_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_w(__fln__no_prvkey_sigI_int x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_w_ptr(__fln__no_prvkey_sigI_int* x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_sigI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_sigI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_sigI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_fst_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_sigI_int tmp = { .d = x->d }; __fln__no_prvkey_sigI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_w(__fln__no_prvkey_decI_int x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_w_ptr(__fln__no_prvkey_decI_int* x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_r(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_decI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_snd_r_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_decI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_int __fln__no_prvkey_decI_int_intg(int x) {__fln__no_prvkey_decI_int y = { .d = x }; return y; }
__fln__no_prvkey_decI_int* __fln__no_prvkey_decI_int_intg_ptr(int* x) {__fln__no_prvkey_decI_int tmp = { .d = *x }; __fln__no_prvkey_decI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__no_prvkey_decI_int_sec(__fln__no_prvkey_decI_int x) { return x.d; }
int* __fln__no_prvkey_decI_int_sec_ptr(__fln__no_prvkey_decI_int* x) { return &x->d; }
__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_intg(int x) {__fln__no_prvkey_decI_no_prvkey_autI_int y = { .d = x }; return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_intg_ptr(int* x) {__fln__no_prvkey_decI_no_prvkey_autI_int tmp = { .d = *x }; __fln__no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__no_prvkey_decI_no_prvkey_autI_int_sec(__fln__no_prvkey_decI_no_prvkey_autI_int x) { return x.d; }
int* __fln__no_prvkey_decI_no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int* x) { return &x->d; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_intg(int x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int y = { .d = x }; return y; }
__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_intg_ptr(int* x) {__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int tmp = { .d = *x }; __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_sec(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int x) { return x.d; }
int* __fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int_sec_ptr(__fln__no_prvkey_sigI_no_prvkey_decI_no_prvkey_autI_int* x) { return &x->d; }
__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_tail_w(__fln__no_prvkey_autI_int x) {__fln__no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_tail_w_ptr(__fln__no_prvkey_autI_int* x) {__fln__no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_tail_r(__fln__no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_tail_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_fst_w(__fln__no_prvkey_decI_int x) {__fln__no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_fst_w_ptr(__fln__no_prvkey_decI_int* x) {__fln__no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_int __fln__no_prvkey_decI_no_prvkey_autI_int_fst_r(__fln__no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_decI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_fst_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_decI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_snd_w(__fln__no_prvkey_autI_int x) {__fln__no_prvkey_decI_no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_decI_no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_snd_w_ptr(__fln__no_prvkey_autI_int* x) {__fln__no_prvkey_decI_no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_decI_no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__no_prvkey_autI_int __fln__no_prvkey_decI_no_prvkey_autI_int_snd_r(__fln__no_prvkey_decI_no_prvkey_autI_int x) { __fln__no_prvkey_autI_int y = { .d = x.d }; return y; }
__fln__no_prvkey_autI_int* __fln__no_prvkey_decI_no_prvkey_autI_int_snd_r_ptr(__fln__no_prvkey_decI_no_prvkey_autI_int* x) { __fln__no_prvkey_autI_int tmp = { .d = x->d }; __fln__no_prvkey_autI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
#endif