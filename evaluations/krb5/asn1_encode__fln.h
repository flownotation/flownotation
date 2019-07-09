#ifndef ASN1_ENCODE__FLN__FLN_H__
#define ASN1_ENCODE__FLN__FLN_H__
#include "asn1_encode.h"
typedef struct {const struct atype_info d; } __fln__freeptrS_const_struct_atype_info;
typedef struct {const struct atype_info d; } __fln__freebaseS_const_struct_atype_info;
typedef struct {const struct atype_info d; } __fln__freebaseS_freeptrS_const_struct_atype_info;
typedef struct {const struct cntype_info d; } __fln__freecnS_const_struct_cntype_info;
typedef struct {const struct seq_info d; } __fln__freeseqS_const_struct_seq_info;
__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_tail_w(__fln__freeptrS_const_struct_atype_info x) {__fln__freebaseS_freeptrS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_tail_w_ptr(__fln__freeptrS_const_struct_atype_info* x) {__fln__freebaseS_freeptrS_const_struct_atype_info tmp = { .d = x->d }; __fln__freebaseS_freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_tail_r(__fln__freebaseS_freeptrS_const_struct_atype_info x) { __fln__freeptrS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_tail_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info* x) { __fln__freeptrS_const_struct_atype_info tmp = { .d = x->d }; __fln__freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_fst_w(__fln__freebaseS_const_struct_atype_info x) {__fln__freebaseS_freeptrS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_fst_w_ptr(__fln__freebaseS_const_struct_atype_info* x) {__fln__freebaseS_freeptrS_const_struct_atype_info tmp = { .d = x->d }; __fln__freebaseS_freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freebaseS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_fst_r(__fln__freebaseS_freeptrS_const_struct_atype_info x) { __fln__freebaseS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freebaseS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_fst_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info* x) { __fln__freebaseS_const_struct_atype_info tmp = { .d = x->d }; __fln__freebaseS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_snd_w(__fln__freeptrS_const_struct_atype_info x) {__fln__freebaseS_freeptrS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_snd_w_ptr(__fln__freeptrS_const_struct_atype_info* x) {__fln__freebaseS_freeptrS_const_struct_atype_info tmp = { .d = x->d }; __fln__freebaseS_freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_snd_r(__fln__freebaseS_freeptrS_const_struct_atype_info x) { __fln__freeptrS_const_struct_atype_info y = { .d = x.d }; return y; }
__fln__freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_snd_r_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info* x) { __fln__freeptrS_const_struct_atype_info tmp = { .d = x->d }; __fln__freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
__fln__freeptrS_const_struct_atype_info __fln__freeptrS_const_struct_atype_info_intg(const struct atype_info x) {__fln__freeptrS_const_struct_atype_info y = { .d = x }; return y; }
__fln__freeptrS_const_struct_atype_info* __fln__freeptrS_const_struct_atype_info_intg_ptr(const struct atype_info* x) {__fln__freeptrS_const_struct_atype_info tmp = { .d = *x }; __fln__freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct atype_info __fln__freeptrS_const_struct_atype_info_sec(__fln__freeptrS_const_struct_atype_info x) { return x.d; }
const struct atype_info* __fln__freeptrS_const_struct_atype_info_sec_ptr(__fln__freeptrS_const_struct_atype_info* x) { return &x->d; }
__fln__freebaseS_const_struct_atype_info __fln__freebaseS_const_struct_atype_info_intg(const struct atype_info x) {__fln__freebaseS_const_struct_atype_info y = { .d = x }; return y; }
__fln__freebaseS_const_struct_atype_info* __fln__freebaseS_const_struct_atype_info_intg_ptr(const struct atype_info* x) {__fln__freebaseS_const_struct_atype_info tmp = { .d = *x }; __fln__freebaseS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct atype_info __fln__freebaseS_const_struct_atype_info_sec(__fln__freebaseS_const_struct_atype_info x) { return x.d; }
const struct atype_info* __fln__freebaseS_const_struct_atype_info_sec_ptr(__fln__freebaseS_const_struct_atype_info* x) { return &x->d; }
__fln__freebaseS_freeptrS_const_struct_atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_intg(const struct atype_info x) {__fln__freebaseS_freeptrS_const_struct_atype_info y = { .d = x }; return y; }
__fln__freebaseS_freeptrS_const_struct_atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_intg_ptr(const struct atype_info* x) {__fln__freebaseS_freeptrS_const_struct_atype_info tmp = { .d = *x }; __fln__freebaseS_freeptrS_const_struct_atype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct atype_info __fln__freebaseS_freeptrS_const_struct_atype_info_sec(__fln__freebaseS_freeptrS_const_struct_atype_info x) { return x.d; }
const struct atype_info* __fln__freebaseS_freeptrS_const_struct_atype_info_sec_ptr(__fln__freebaseS_freeptrS_const_struct_atype_info* x) { return &x->d; }
__fln__freecnS_const_struct_cntype_info __fln__freecnS_const_struct_cntype_info_intg(const struct cntype_info x) {__fln__freecnS_const_struct_cntype_info y = { .d = x }; return y; }
__fln__freecnS_const_struct_cntype_info* __fln__freecnS_const_struct_cntype_info_intg_ptr(const struct cntype_info* x) {__fln__freecnS_const_struct_cntype_info tmp = { .d = *x }; __fln__freecnS_const_struct_cntype_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct cntype_info __fln__freecnS_const_struct_cntype_info_sec(__fln__freecnS_const_struct_cntype_info x) { return x.d; }
const struct cntype_info* __fln__freecnS_const_struct_cntype_info_sec_ptr(__fln__freecnS_const_struct_cntype_info* x) { return &x->d; }
__fln__freeseqS_const_struct_seq_info __fln__freeseqS_const_struct_seq_info_intg(const struct seq_info x) {__fln__freeseqS_const_struct_seq_info y = { .d = x }; return y; }
__fln__freeseqS_const_struct_seq_info* __fln__freeseqS_const_struct_seq_info_intg_ptr(const struct seq_info* x) {__fln__freeseqS_const_struct_seq_info tmp = { .d = *x }; __fln__freeseqS_const_struct_seq_info* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const struct seq_info __fln__freeseqS_const_struct_seq_info_sec(__fln__freeseqS_const_struct_seq_info x) { return x.d; }
const struct seq_info* __fln__freeseqS_const_struct_seq_info_sec_ptr(__fln__freeseqS_const_struct_seq_info* x) { return &x->d; }
#endif