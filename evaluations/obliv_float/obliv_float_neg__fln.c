typedef int OblivBit;
void __obliv_c__copyBit(OblivBit *dest, OblivBit *src)
{
  *dest = *src;
}

void __obliv_c__setBitAnd(OblivBit *out, OblivBit *in0, OblivBit *in1)
{
  *out = (*in0) && (*in1);
}

void __obliv_c__setBitOr(OblivBit *out, OblivBit *in0, OblivBit *in1)
{
  *out = (*in0) || (*in1);
}

void __obliv_c__setBitNot(OblivBit *out, OblivBit *in0)
{
  *out = !(*in0);
}

void __obliv_c__setBitXor(OblivBit *out, OblivBit *in0, __fln__negate_bitS_OblivBit *in1)
{
  OblivBit* in1__fln_p = __fln__negate_bitS_OblivBit_sec_ptr(in1);
  *out = (*in0) != (*in1__fln_p);
}

typedef struct 
{
  OblivBit d;
} __fln__negate_bitS_OblivBit;
__fln__negate_bitS_OblivBit __fln__negate_bitS_OblivBit_intg(OblivBit x)
{
  __fln__negate_bitS_OblivBit y = {.d = x};
  return y;
}

__fln__negate_bitS_OblivBit *__fln__negate_bitS_OblivBit_intg_ptr(OblivBit *x)
{
  __fln__negate_bitS_OblivBit tmp = {.d = *x};
  __fln__negate_bitS_OblivBit *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

OblivBit __fln__negate_bitS_OblivBit_sec(__fln__negate_bitS_OblivBit x)
{
  return x.d;
}

OblivBit *__fln__negate_bitS_OblivBit_sec_ptr(__fln__negate_bitS_OblivBit *x)
{
  return &x->d;
}

void __obliv_c__setBitXor(OblivBit *out, OblivBit *in0, __fln__negate_bitS_OblivBit *in1)
{
  OblivBit* in1__fln_p = __fln__negate_bitS_OblivBit_sec_ptr(in1);
  *out = (*in0) != (*in1__fln_p);
}

void obliv_float_neg_circuit(OblivBit *dest, const OblivBit *op1, const OblivBit *op2)
{
  __fln__negate_bitS_OblivBit *op2_c;
  op2_c = __fln__negate_bitS_OblivBit_intg_ptr(op2);
  OblivBit __obliv_0;
  OblivBit __obliv_1;
  OblivBit __obliv_2;
  OblivBit __obliv_3;
  OblivBit __obliv_4;
  OblivBit __obliv_5;
  OblivBit __obliv_6;
  OblivBit __obliv_7;
  OblivBit __obliv_8;
  OblivBit __obliv_9;
  OblivBit __obliv_10;
  OblivBit __obliv_11;
  OblivBit __obliv_12;
  OblivBit __obliv_13;
  OblivBit __obliv_14;
  OblivBit __obliv_15;
  OblivBit __obliv_16;
  OblivBit __obliv_17;
  OblivBit __obliv_18;
  OblivBit __obliv_19;
  OblivBit __obliv_20;
  OblivBit __obliv_21;
  OblivBit __obliv_22;
  OblivBit __obliv_23;
  OblivBit __obliv_24;
  OblivBit __obliv_25;
  OblivBit __obliv_26;
  OblivBit __obliv_27;
  OblivBit __obliv_28;
  OblivBit __obliv_29;
  OblivBit __obliv_30;
  OblivBit __obliv_31;
  __obliv_c__copyBit(&__obliv_0, op1 + 0);
  __obliv_c__copyBit(&__obliv_1, op1 + 1);
  __obliv_c__copyBit(&__obliv_2, op1 + 2);
  __obliv_c__copyBit(&__obliv_3, op1 + 3);
  __obliv_c__copyBit(&__obliv_4, op1 + 4);
  __obliv_c__copyBit(&__obliv_5, op1 + 5);
  __obliv_c__copyBit(&__obliv_6, op1 + 6);
  __obliv_c__copyBit(&__obliv_7, op1 + 7);
  __obliv_c__copyBit(&__obliv_8, op1 + 8);
  __obliv_c__copyBit(&__obliv_9, op1 + 9);
  __obliv_c__copyBit(&__obliv_10, op1 + 10);
  __obliv_c__copyBit(&__obliv_11, op1 + 11);
  __obliv_c__copyBit(&__obliv_12, op1 + 12);
  __obliv_c__copyBit(&__obliv_13, op1 + 13);
  __obliv_c__copyBit(&__obliv_14, op1 + 14);
  __obliv_c__copyBit(&__obliv_15, op1 + 15);
  __obliv_c__copyBit(&__obliv_16, op1 + 16);
  __obliv_c__copyBit(&__obliv_17, op1 + 17);
  __obliv_c__copyBit(&__obliv_18, op1 + 18);
  __obliv_c__copyBit(&__obliv_19, op1 + 19);
  __obliv_c__copyBit(&__obliv_20, op1 + 20);
  __obliv_c__copyBit(&__obliv_21, op1 + 21);
  __obliv_c__copyBit(&__obliv_22, op1 + 22);
  __obliv_c__copyBit(&__obliv_23, op1 + 23);
  __obliv_c__copyBit(&__obliv_24, op1 + 24);
  __obliv_c__copyBit(&__obliv_25, op1 + 25);
  __obliv_c__copyBit(&__obliv_26, op1 + 26);
  __obliv_c__copyBit(&__obliv_27, op1 + 27);
  __obliv_c__copyBit(&__obliv_28, op1 + 28);
  __obliv_c__copyBit(&__obliv_29, op1 + 29);
  __obliv_c__copyBit(&__obliv_30, op1 + 30);
  __obliv_c__copyBit(&__obliv_31, op1 + 31);
  __obliv_c__setBitXor(&__obliv_31, &__obliv_31, op2);
  __obliv_c__copyBit(dest + 0, &__obliv_0);
  __obliv_c__copyBit(dest + 1, &__obliv_1);
  __obliv_c__copyBit(dest + 2, &__obliv_2);
  __obliv_c__copyBit(dest + 3, &__obliv_3);
  __obliv_c__copyBit(dest + 4, &__obliv_4);
  __obliv_c__copyBit(dest + 5, &__obliv_5);
  __obliv_c__copyBit(dest + 6, &__obliv_6);
  __obliv_c__copyBit(dest + 7, &__obliv_7);
  __obliv_c__copyBit(dest + 8, &__obliv_8);
  __obliv_c__copyBit(dest + 9, &__obliv_9);
  __obliv_c__copyBit(dest + 10, &__obliv_10);
  __obliv_c__copyBit(dest + 11, &__obliv_11);
  __obliv_c__copyBit(dest + 12, &__obliv_12);
  __obliv_c__copyBit(dest + 13, &__obliv_13);
  __obliv_c__copyBit(dest + 14, &__obliv_14);
  __obliv_c__copyBit(dest + 15, &__obliv_15);
  __obliv_c__copyBit(dest + 16, &__obliv_16);
  __obliv_c__copyBit(dest + 17, &__obliv_17);
  __obliv_c__copyBit(dest + 18, &__obliv_18);
  __obliv_c__copyBit(dest + 19, &__obliv_19);
  __obliv_c__copyBit(dest + 20, &__obliv_20);
  __obliv_c__copyBit(dest + 21, &__obliv_21);
  __obliv_c__copyBit(dest + 22, &__obliv_22);
  __obliv_c__copyBit(dest + 23, &__obliv_23);
  __obliv_c__copyBit(dest + 24, &__obliv_24);
  __obliv_c__copyBit(dest + 25, &__obliv_25);
  __obliv_c__copyBit(dest + 26, &__obliv_26);
  __obliv_c__copyBit(dest + 27, &__obliv_27);
  __obliv_c__copyBit(dest + 28, &__obliv_28);
  __obliv_c__copyBit(dest + 29, &__obliv_29);
  __obliv_c__copyBit(dest + 30, &__obliv_30);
  __obliv_c__copyBit(dest + 31, &__obliv_31);
}

