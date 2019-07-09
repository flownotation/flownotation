#ifndef OT_PROTO_H
#define OT_PROTO_H

#define ALICE 0
#define BOB 1
typedef struct {
int e;
int d;
int N;
} pair;

#endif
#include "ot_proto.h"

#include "ot_proto__fln.h"

void send(int addr, int data) {

}

int recv(int addr) {
int v = 0;
return v;
}

pair gen_RSA_pair() {
int e = 0;
int d = 0;
int N = 0;
pair p = {e, d, N};
return p;
}

int get_public(pair p) {
return p.e;
}

int get_private(pair p) {
return p.d;
}

int get_modulus(pair p) {
return p.N;
}

int rand_int() {
int s = sample();
return s;
}

int enc(int m, int k) {
return m + k;
}

int safe_rand_sub(int a, int b) {
int t = a - b;
return t;
}

void ot_alice(int m0, int m1) {
pair p__fln_3;
p = gen_RSA_pair();
get_public(p);
send(BOB, get_public(p));
send(BOB, get_modulus(p));
int x0__fln_0;
int x1__fln_4;
x0 = rand_int();
x1 = rand_int();
send(BOB, x0);
send(BOB, x1);
int v__fln_2;
v = recv(BOB);
int k0 = pow(safe_rand_sub(v, x0), get_private(p));
int k1 = pow(safe_rand_sub(v, x1), get_private(p));
send(BOB, enc(m0, k0));
send(BOB, enc(m1, k1));
}

int ot_bob(int c) {
int e = recv(ALICE);
int N = recv(ALICE);
int x0 = recv(ALICE);
int x1 = recv(ALICE);
int k__fln_1;
k = rand_int();
int v;
if (c == 0) {
v = x0 + pow(k, e);
} else {
v = x1 + pow(k, e);
}
send(ALICE, v);
int m0p = recv(ALICE);
int m1p = recv(ALICE);
if (c == 0) {
return m0p - k;
} else {
return m1p - k;
}
}
