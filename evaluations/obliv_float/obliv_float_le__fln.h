#ifndef OBLIV_FLOAT_LE__FLN__FLN_H__
#define OBLIV_FLOAT_LE__FLN__FLN_H__
#include "obliv_float_h.h"
typedef struct {OblivBit d; } __fln__le_bitS_OblivBit;
__fln__le_bitS_OblivBit __fln__le_bitS_OblivBit_intg(OblivBit x) {__fln__le_bitS_OblivBit y = { .d = x }; return y; }
__fln__le_bitS_OblivBit* __fln__le_bitS_OblivBit_intg_ptr(OblivBit* x) {__fln__le_bitS_OblivBit tmp = { .d = *x }; __fln__le_bitS_OblivBit* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
OblivBit __fln__le_bitS_OblivBit_sec(__fln__le_bitS_OblivBit x) { return x.d; }
OblivBit* __fln__le_bitS_OblivBit_sec_ptr(__fln__le_bitS_OblivBit* x) { return &x->d; }
#endif