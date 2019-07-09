#ifndef TEST_AES__FLN__FLN_H__
#define TEST_AES__FLN__FLN_H__
#include "definitions.h"
#include "test_aes.h"
typedef struct {byte d; } __fln__preprocessing_materialI_byte;
typedef struct {MiniMacsRep d; } __fln__check_memoryS_MiniMacsRep;
typedef struct {MiniMacsEnc d; } __fln__check_paramsS_MiniMacsEnc;
typedef struct {int d; } __fln__params_validI_int;
typedef struct {uint d; } __fln__lcodeI_uint;
typedef struct {DAesMiniMacImpl d; } __fln__check_connectionS_DAesMiniMacImpl;
typedef struct {MpcPeer d; } __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer;
__fln__preprocessing_materialI_byte __fln__preprocessing_materialI_byte_intg(byte x) {__fln__preprocessing_materialI_byte y = { .d = x }; return y; }
__fln__preprocessing_materialI_byte* __fln__preprocessing_materialI_byte_intg_ptr(byte* x) {__fln__preprocessing_materialI_byte tmp = { .d = *x }; __fln__preprocessing_materialI_byte* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
byte __fln__preprocessing_materialI_byte_sec(__fln__preprocessing_materialI_byte x) { return x.d; }
byte* __fln__preprocessing_materialI_byte_sec_ptr(__fln__preprocessing_materialI_byte* x) { return &x->d; }
__fln__check_memoryS_MiniMacsRep __fln__check_memoryS_MiniMacsRep_intg(MiniMacsRep x) {__fln__check_memoryS_MiniMacsRep y = { .d = x }; return y; }
__fln__check_memoryS_MiniMacsRep* __fln__check_memoryS_MiniMacsRep_intg_ptr(MiniMacsRep* x) {__fln__check_memoryS_MiniMacsRep tmp = { .d = *x }; __fln__check_memoryS_MiniMacsRep* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
MiniMacsRep __fln__check_memoryS_MiniMacsRep_sec(__fln__check_memoryS_MiniMacsRep x) { return x.d; }
MiniMacsRep* __fln__check_memoryS_MiniMacsRep_sec_ptr(__fln__check_memoryS_MiniMacsRep* x) { return &x->d; }
__fln__check_paramsS_MiniMacsEnc __fln__check_paramsS_MiniMacsEnc_intg(MiniMacsEnc x) {__fln__check_paramsS_MiniMacsEnc y = { .d = x }; return y; }
__fln__check_paramsS_MiniMacsEnc* __fln__check_paramsS_MiniMacsEnc_intg_ptr(MiniMacsEnc* x) {__fln__check_paramsS_MiniMacsEnc tmp = { .d = *x }; __fln__check_paramsS_MiniMacsEnc* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
MiniMacsEnc __fln__check_paramsS_MiniMacsEnc_sec(__fln__check_paramsS_MiniMacsEnc x) { return x.d; }
MiniMacsEnc* __fln__check_paramsS_MiniMacsEnc_sec_ptr(__fln__check_paramsS_MiniMacsEnc* x) { return &x->d; }
__fln__params_validI_int __fln__params_validI_int_intg(int x) {__fln__params_validI_int y = { .d = x }; return y; }
__fln__params_validI_int* __fln__params_validI_int_intg_ptr(int* x) {__fln__params_validI_int tmp = { .d = *x }; __fln__params_validI_int* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
int __fln__params_validI_int_sec(__fln__params_validI_int x) { return x.d; }
int* __fln__params_validI_int_sec_ptr(__fln__params_validI_int* x) { return &x->d; }
__fln__lcodeI_uint __fln__lcodeI_uint_intg(uint x) {__fln__lcodeI_uint y = { .d = x }; return y; }
__fln__lcodeI_uint* __fln__lcodeI_uint_intg_ptr(uint* x) {__fln__lcodeI_uint tmp = { .d = *x }; __fln__lcodeI_uint* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
uint __fln__lcodeI_uint_sec(__fln__lcodeI_uint x) { return x.d; }
uint* __fln__lcodeI_uint_sec_ptr(__fln__lcodeI_uint* x) { return &x->d; }
__fln__check_connectionS_DAesMiniMacImpl __fln__check_connectionS_DAesMiniMacImpl_intg(DAesMiniMacImpl x) {__fln__check_connectionS_DAesMiniMacImpl y = { .d = x }; return y; }
__fln__check_connectionS_DAesMiniMacImpl* __fln__check_connectionS_DAesMiniMacImpl_intg_ptr(DAesMiniMacImpl* x) {__fln__check_connectionS_DAesMiniMacImpl tmp = { .d = *x }; __fln__check_connectionS_DAesMiniMacImpl* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
DAesMiniMacImpl __fln__check_connectionS_DAesMiniMacImpl_sec(__fln__check_connectionS_DAesMiniMacImpl x) { return x.d; }
DAesMiniMacImpl* __fln__check_connectionS_DAesMiniMacImpl_sec_ptr(__fln__check_connectionS_DAesMiniMacImpl* x) { return &x->d; }
__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg(MpcPeer x) {__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer y = { .d = x }; return y; }
__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer* __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_intg_ptr(MpcPeer* x) {__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer tmp = { .d = *x }; __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer* y = malloc(sizeof *y); memcpy(y, &tmp, sizeof *y); return y; }
MpcPeer __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_sec(__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer x) { return x.d; }
MpcPeer* __fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer_sec_ptr(__fln__check_peer_existsS_peer_receive_shareS_peer_receive_macS_MpcPeer* x) { return &x->d; }
#endif