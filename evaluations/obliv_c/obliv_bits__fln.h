#ifndef OBLIV_BITS__FLN__FLN_H__
#define OBLIV_BITS__FLN__FLN_H__
#include "obliv_bits.h"
typedef struct {OblivBit d; } __fln__oblivS_OblivBit;
typedef struct {const OblivBit d; } __fln__oblivS_const_OblivBit;
__fln__oblivS_OblivBit __fln__oblivS_OblivBit_intg(OblivBit x) {__fln__oblivS_OblivBit y = { .d = x }; return y; }
__fln__oblivS_OblivBit* __fln__oblivS_OblivBit_intg_ptr(OblivBit* x) {__fln__oblivS_OblivBit tmp = { .d = *x }; __fln__oblivS_OblivBit* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
OblivBit __fln__oblivS_OblivBit_sec(__fln__oblivS_OblivBit x) { return x.d; }
OblivBit* __fln__oblivS_OblivBit_sec_ptr(__fln__oblivS_OblivBit* x) { return &x->d; }
__fln__oblivS_const_OblivBit __fln__oblivS_const_OblivBit_intg(const OblivBit x) {__fln__oblivS_const_OblivBit y = { .d = x }; return y; }
__fln__oblivS_const_OblivBit* __fln__oblivS_const_OblivBit_intg_ptr(const OblivBit* x) {__fln__oblivS_const_OblivBit tmp = { .d = *x }; __fln__oblivS_const_OblivBit* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
const OblivBit __fln__oblivS_const_OblivBit_sec(__fln__oblivS_const_OblivBit x) { return x.d; }
const OblivBit* __fln__oblivS_const_OblivBit_sec_ptr(__fln__oblivS_const_OblivBit* x) { return &x->d; }
#endif