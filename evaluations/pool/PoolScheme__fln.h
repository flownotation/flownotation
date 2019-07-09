#ifndef POOLSCHEME__FLN__FLN_H__
#define POOLSCHEME__FLN__FLN_H__
#include "PoolScheme.h"
typedef struct {ServiceConfig d; } __fln__initalized_serviceI_ServiceConfig;
typedef struct {Pool d; } __fln__initalized_poolI_Pool;
typedef struct {Pool d; } __fln__initialized_poolS_Pool;
typedef struct {uint64_t d; } __fln__valid_gateI_uint64_t;
__fln__initalized_serviceI_ServiceConfig __fln__initalized_serviceI_ServiceConfig_intg(ServiceConfig x) {__fln__initalized_serviceI_ServiceConfig y = { .d = x }; return y; }
__fln__initalized_serviceI_ServiceConfig* __fln__initalized_serviceI_ServiceConfig_intg_ptr(ServiceConfig* x) {__fln__initalized_serviceI_ServiceConfig tmp = { .d = *x }; __fln__initalized_serviceI_ServiceConfig* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
ServiceConfig __fln__initalized_serviceI_ServiceConfig_sec(__fln__initalized_serviceI_ServiceConfig x) { return x.d; }
ServiceConfig* __fln__initalized_serviceI_ServiceConfig_sec_ptr(__fln__initalized_serviceI_ServiceConfig* x) { return &x->d; }
__fln__initalized_poolI_Pool __fln__initalized_poolI_Pool_intg(Pool x) {__fln__initalized_poolI_Pool y = { .d = x }; return y; }
__fln__initalized_poolI_Pool* __fln__initalized_poolI_Pool_intg_ptr(Pool* x) {__fln__initalized_poolI_Pool tmp = { .d = *x }; __fln__initalized_poolI_Pool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
Pool __fln__initalized_poolI_Pool_sec(__fln__initalized_poolI_Pool x) { return x.d; }
Pool* __fln__initalized_poolI_Pool_sec_ptr(__fln__initalized_poolI_Pool* x) { return &x->d; }
__fln__initialized_poolS_Pool __fln__initialized_poolS_Pool_intg(Pool x) {__fln__initialized_poolS_Pool y = { .d = x }; return y; }
__fln__initialized_poolS_Pool* __fln__initialized_poolS_Pool_intg_ptr(Pool* x) {__fln__initialized_poolS_Pool tmp = { .d = *x }; __fln__initialized_poolS_Pool* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
Pool __fln__initialized_poolS_Pool_sec(__fln__initialized_poolS_Pool x) { return x.d; }
Pool* __fln__initialized_poolS_Pool_sec_ptr(__fln__initialized_poolS_Pool* x) { return &x->d; }
__fln__valid_gateI_uint64_t __fln__valid_gateI_uint64_t_intg(uint64_t x) {__fln__valid_gateI_uint64_t y = { .d = x }; return y; }
__fln__valid_gateI_uint64_t* __fln__valid_gateI_uint64_t_intg_ptr(uint64_t* x) {__fln__valid_gateI_uint64_t tmp = { .d = *x }; __fln__valid_gateI_uint64_t* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
uint64_t __fln__valid_gateI_uint64_t_sec(__fln__valid_gateI_uint64_t x) { return x.d; }
uint64_t* __fln__valid_gateI_uint64_t_sec_ptr(__fln__valid_gateI_uint64_t* x) { return &x->d; }
#endif