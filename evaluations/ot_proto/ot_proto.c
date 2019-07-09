#include "ot_proto.h"

void send(int addr, int data) {
	
}

int recv(int addr) {
    int v = 0;
	return v;
}

#return @RSAkey:integrity
pair gen_RSA_pair() {
    int e = 0;
    int d = 0;
    int N = 0;
	pair p = {e, d, N};
	return p;
}

#param @RSAkey:secrecy
int get_public(pair p) {
	return p.e;
}

#param @RSAkey:secrecy
int get_private(pair p) {
	return p.d;
}

#param @RSAkey:secrecy
int get_modulus(pair p) {
	return p.N;
}

#param @random:integrity
int rand_int() {
	int s = sample();
	return s;
}

int enc(int m, int k) {
	return m + k;
}

#param @random:secrecy
int safe_rand_sub(int a, int b) {
	int t = a - b;
	return t;
}

#param @secret:secrecy
void ot_alice(int m0, int m1) {
	#requires @RSAkey:integrity 
	pair p;
	p = gen_RSA_pair();
	get_public(p);
	send(BOB, get_public(p));
	send(BOB, get_modulus(p));
	#requires @random:integrity 
	int x0;
	#requires @random:integrity 
	int x1;
	x0 = rand_int();
	x1 = rand_int();
	send(BOB, x0);
	send(BOB, x1);
	#requires @random:secrecy 
	int v;
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
	#requires @random:integrity 
	int k;
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
