#ifndef OQUEUE__FLN__FLN_H__
#define OQUEUE__FLN__FLN_H__
#include "oqueue.h"
typedef struct {oqueue d; } __fln__oqueue_pop_readyS_oqueue;
typedef struct {oqueue d; } __fln__oqueue_not_has_childI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_check_childS_oqueue;
typedef struct {oqueue d; } __fln__oqueue_has_childI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_push_readyS_oqueue;
typedef struct {oqueue d; } __fln__oqueue_emptyI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_not_emptyS_oqueue;
typedef struct {oqueue d; } __fln__oqueue_pop_readyI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_not_has_childS_oqueue;
typedef struct {bool d; } __fln__oqueue_not_emptyI_bool;
typedef struct {oqueue d; } __fln__oqueue_push_readyI_oqueue;
typedef struct {oqueue d; } __fln__oqueue_emptyS_oqueue;
typedef struct {bool d; } __fln__oqueue_emptyI_bool;
__fln__oqueue_pop_readyS_oqueue __fln__oqueue_pop_readyS_oqueue_intg(oqueue x) {__fln__oqueue_pop_readyS_oqueue y = { .d = x }; return y; }
__fln__oqueue_pop_readyS_oqueue* __fln__oqueue_pop_readyS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_pop_readyS_oqueue tmp = { .d = *x }; __fln__oqueue_pop_readyS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_pop_readyS_oqueue_sec(__fln__oqueue_pop_readyS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_pop_readyS_oqueue_sec_ptr(__fln__oqueue_pop_readyS_oqueue* x) { return &x->d; }
__fln__oqueue_not_has_childI_oqueue __fln__oqueue_not_has_childI_oqueue_intg(oqueue x) {__fln__oqueue_not_has_childI_oqueue y = { .d = x }; return y; }
__fln__oqueue_not_has_childI_oqueue* __fln__oqueue_not_has_childI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_not_has_childI_oqueue tmp = { .d = *x }; __fln__oqueue_not_has_childI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_not_has_childI_oqueue_sec(__fln__oqueue_not_has_childI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_not_has_childI_oqueue_sec_ptr(__fln__oqueue_not_has_childI_oqueue* x) { return &x->d; }
__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue_intg(oqueue x) {__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue y = { .d = x }; return y; }
__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue* __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue tmp = { .d = *x }; __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue_sec(__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue_sec_ptr(__fln__oqueue_check_childS_oqueue_has_childI_oqueue_push_readyI_oqueue* x) { return &x->d; }
__fln__oqueue_check_childS_oqueue __fln__oqueue_check_childS_oqueue_intg(oqueue x) {__fln__oqueue_check_childS_oqueue y = { .d = x }; return y; }
__fln__oqueue_check_childS_oqueue* __fln__oqueue_check_childS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_check_childS_oqueue tmp = { .d = *x }; __fln__oqueue_check_childS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_check_childS_oqueue_sec(__fln__oqueue_check_childS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_check_childS_oqueue_sec_ptr(__fln__oqueue_check_childS_oqueue* x) { return &x->d; }
__fln__oqueue_has_childI_oqueue __fln__oqueue_has_childI_oqueue_intg(oqueue x) {__fln__oqueue_has_childI_oqueue y = { .d = x }; return y; }
__fln__oqueue_has_childI_oqueue* __fln__oqueue_has_childI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_has_childI_oqueue tmp = { .d = *x }; __fln__oqueue_has_childI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_has_childI_oqueue_sec(__fln__oqueue_has_childI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_has_childI_oqueue_sec_ptr(__fln__oqueue_has_childI_oqueue* x) { return &x->d; }
__fln__oqueue_push_readyS_oqueue __fln__oqueue_push_readyS_oqueue_intg(oqueue x) {__fln__oqueue_push_readyS_oqueue y = { .d = x }; return y; }
__fln__oqueue_push_readyS_oqueue* __fln__oqueue_push_readyS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_push_readyS_oqueue tmp = { .d = *x }; __fln__oqueue_push_readyS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_push_readyS_oqueue_sec(__fln__oqueue_push_readyS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_push_readyS_oqueue_sec_ptr(__fln__oqueue_push_readyS_oqueue* x) { return &x->d; }
__fln__oqueue_emptyI_oqueue __fln__oqueue_emptyI_oqueue_intg(oqueue x) {__fln__oqueue_emptyI_oqueue y = { .d = x }; return y; }
__fln__oqueue_emptyI_oqueue* __fln__oqueue_emptyI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_emptyI_oqueue tmp = { .d = *x }; __fln__oqueue_emptyI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_emptyI_oqueue_sec(__fln__oqueue_emptyI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_emptyI_oqueue_sec_ptr(__fln__oqueue_emptyI_oqueue* x) { return &x->d; }
__fln__oqueue_not_emptyS_oqueue __fln__oqueue_not_emptyS_oqueue_intg(oqueue x) {__fln__oqueue_not_emptyS_oqueue y = { .d = x }; return y; }
__fln__oqueue_not_emptyS_oqueue* __fln__oqueue_not_emptyS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_not_emptyS_oqueue tmp = { .d = *x }; __fln__oqueue_not_emptyS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_not_emptyS_oqueue_sec(__fln__oqueue_not_emptyS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_not_emptyS_oqueue_sec_ptr(__fln__oqueue_not_emptyS_oqueue* x) { return &x->d; }
__fln__oqueue_pop_readyI_oqueue __fln__oqueue_pop_readyI_oqueue_intg(oqueue x) {__fln__oqueue_pop_readyI_oqueue y = { .d = x }; return y; }
__fln__oqueue_pop_readyI_oqueue* __fln__oqueue_pop_readyI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_pop_readyI_oqueue tmp = { .d = *x }; __fln__oqueue_pop_readyI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_pop_readyI_oqueue_sec(__fln__oqueue_pop_readyI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_pop_readyI_oqueue_sec_ptr(__fln__oqueue_pop_readyI_oqueue* x) { return &x->d; }
__fln__oqueue_not_has_childS_oqueue __fln__oqueue_not_has_childS_oqueue_intg(oqueue x) {__fln__oqueue_not_has_childS_oqueue y = { .d = x }; return y; }
__fln__oqueue_not_has_childS_oqueue* __fln__oqueue_not_has_childS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_not_has_childS_oqueue tmp = { .d = *x }; __fln__oqueue_not_has_childS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_not_has_childS_oqueue_sec(__fln__oqueue_not_has_childS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_not_has_childS_oqueue_sec_ptr(__fln__oqueue_not_has_childS_oqueue* x) { return &x->d; }
__fln__oqueue_not_emptyI_bool __fln__oqueue_not_emptyI_bool_intg(bool x) {__fln__oqueue_not_emptyI_bool y = { .d = x }; return y; }
__fln__oqueue_not_emptyI_bool* __fln__oqueue_not_emptyI_bool_intg_ptr(bool* x) {__fln__oqueue_not_emptyI_bool tmp = { .d = *x }; __fln__oqueue_not_emptyI_bool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
bool __fln__oqueue_not_emptyI_bool_sec(__fln__oqueue_not_emptyI_bool x) { return x.d; }
bool* __fln__oqueue_not_emptyI_bool_sec_ptr(__fln__oqueue_not_emptyI_bool* x) { return &x->d; }
__fln__oqueue_push_readyI_oqueue __fln__oqueue_push_readyI_oqueue_intg(oqueue x) {__fln__oqueue_push_readyI_oqueue y = { .d = x }; return y; }
__fln__oqueue_push_readyI_oqueue* __fln__oqueue_push_readyI_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_push_readyI_oqueue tmp = { .d = *x }; __fln__oqueue_push_readyI_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_push_readyI_oqueue_sec(__fln__oqueue_push_readyI_oqueue x) { return x.d; }
oqueue* __fln__oqueue_push_readyI_oqueue_sec_ptr(__fln__oqueue_push_readyI_oqueue* x) { return &x->d; }
__fln__oqueue_emptyS_oqueue __fln__oqueue_emptyS_oqueue_intg(oqueue x) {__fln__oqueue_emptyS_oqueue y = { .d = x }; return y; }
__fln__oqueue_emptyS_oqueue* __fln__oqueue_emptyS_oqueue_intg_ptr(oqueue* x) {__fln__oqueue_emptyS_oqueue tmp = { .d = *x }; __fln__oqueue_emptyS_oqueue* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
oqueue __fln__oqueue_emptyS_oqueue_sec(__fln__oqueue_emptyS_oqueue x) { return x.d; }
oqueue* __fln__oqueue_emptyS_oqueue_sec_ptr(__fln__oqueue_emptyS_oqueue* x) { return &x->d; }
__fln__oqueue_emptyI_bool __fln__oqueue_emptyI_bool_intg(bool x) {__fln__oqueue_emptyI_bool y = { .d = x }; return y; }
__fln__oqueue_emptyI_bool* __fln__oqueue_emptyI_bool_intg_ptr(bool* x) {__fln__oqueue_emptyI_bool tmp = { .d = *x }; __fln__oqueue_emptyI_bool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
bool __fln__oqueue_emptyI_bool_sec(__fln__oqueue_emptyI_bool x) { return x.d; }
bool* __fln__oqueue_emptyI_bool_sec_ptr(__fln__oqueue_emptyI_bool* x) { return &x->d; }
#endif