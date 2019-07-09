#ifndef OBLIV_FLOAT_H
#define OBLIV_FLOAT_H
typedef int OblivBit;

void __obliv_c__copyBit(OblivBit* dest, OblivBit* src) {
*dest = *src;
}

void __obliv_c__setBitAnd(OblivBit* out, OblivBit* in0, OblivBit* in1) {
*out = *in0 && *in1;
}

void __obliv_c__setBitOr(OblivBit* out, OblivBit* in0, OblivBit* in1) {
*out = *in0 || *in1;
}

void __obliv_c__setBitNot(OblivBit* out, OblivBit* in0) {
*out = !*in0;
}

void __obliv_c__setBitXor(OblivBit* out, OblivBit* in0, OblivBit* in1) {
*out = (*in0 != *in1);
}
#endif