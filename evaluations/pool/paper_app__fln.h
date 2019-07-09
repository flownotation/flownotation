#ifndef PAPER_APP__FLN__FLN_H__
#define PAPER_APP__FLN__FLN_H__
#include "paper_app.h"
typedef struct {bool d; } __fln__alice_secretS_bool;
typedef struct {bool d; } __fln__alice_secretI_bool;
typedef struct {Garbler d; } __fln__garbler_protectedS_Garbler;
typedef struct {wire d; } __fln__prepared_functionS_wire;
typedef struct {Garbler d; } __fln__garbler_protectedI_Garbler;
__fln__alice_secretS_bool __fln__alice_secretS_bool_intg(bool x) {__fln__alice_secretS_bool y = { .d = x }; return y; }
__fln__alice_secretS_bool* __fln__alice_secretS_bool_intg_ptr(bool* x) {__fln__alice_secretS_bool tmp = { .d = *x }; __fln__alice_secretS_bool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
bool __fln__alice_secretS_bool_sec(__fln__alice_secretS_bool x) { return x.d; }
bool* __fln__alice_secretS_bool_sec_ptr(__fln__alice_secretS_bool* x) { return &x->d; }
__fln__alice_secretI_bool __fln__alice_secretI_bool_intg(bool x) {__fln__alice_secretI_bool y = { .d = x }; return y; }
__fln__alice_secretI_bool* __fln__alice_secretI_bool_intg_ptr(bool* x) {__fln__alice_secretI_bool tmp = { .d = *x }; __fln__alice_secretI_bool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
bool __fln__alice_secretI_bool_sec(__fln__alice_secretI_bool x) { return x.d; }
bool* __fln__alice_secretI_bool_sec_ptr(__fln__alice_secretI_bool* x) { return &x->d; }
__fln__garbler_protectedS_Garbler __fln__garbler_protectedS_Garbler_intg(Garbler x) {__fln__garbler_protectedS_Garbler y = { .d = x }; return y; }
__fln__garbler_protectedS_Garbler* __fln__garbler_protectedS_Garbler_intg_ptr(Garbler* x) {__fln__garbler_protectedS_Garbler tmp = { .d = *x }; __fln__garbler_protectedS_Garbler* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
Garbler __fln__garbler_protectedS_Garbler_sec(__fln__garbler_protectedS_Garbler x) { return x.d; }
Garbler* __fln__garbler_protectedS_Garbler_sec_ptr(__fln__garbler_protectedS_Garbler* x) { return &x->d; }
__fln__prepared_functionS_wire __fln__prepared_functionS_wire_intg(wire x) {__fln__prepared_functionS_wire y = { .d = x }; return y; }
__fln__prepared_functionS_wire* __fln__prepared_functionS_wire_intg_ptr(wire* x) {__fln__prepared_functionS_wire tmp = { .d = *x }; __fln__prepared_functionS_wire* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
wire __fln__prepared_functionS_wire_sec(__fln__prepared_functionS_wire x) { return x.d; }
wire* __fln__prepared_functionS_wire_sec_ptr(__fln__prepared_functionS_wire* x) { return &x->d; }
__fln__garbler_protectedI_Garbler __fln__garbler_protectedI_Garbler_intg(Garbler x) {__fln__garbler_protectedI_Garbler y = { .d = x }; return y; }
__fln__garbler_protectedI_Garbler* __fln__garbler_protectedI_Garbler_intg_ptr(Garbler* x) {__fln__garbler_protectedI_Garbler tmp = { .d = *x }; __fln__garbler_protectedI_Garbler* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
Garbler __fln__garbler_protectedI_Garbler_sec(__fln__garbler_protectedI_Garbler x) { return x.d; }
Garbler* __fln__garbler_protectedI_Garbler_sec_ptr(__fln__garbler_protectedI_Garbler* x) { return &x->d; }
#endif