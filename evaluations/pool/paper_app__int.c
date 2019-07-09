#ifndef PAPER_APP_H
#define PAPER_APP_H
typedef int wire;
typedef int bool;

typedef struct {
wire** (*garblerIn)(bool*, int);
wire** (*evaluatorIn)(int);
wire** (*exec)(wire**, wire**);
} Garbler;

typedef struct {
wire** (*garblerIn)(int);
wire** (*evaluatorIn)(bool*, int);
wire** (*exec)(wire**, wire**);
} Evaluator;
#endif
#include "paper_app.h"


#include "paper_app__fln.h"

wire** garblerInA(Garbler alice, bool* inputA, int size) {
wire** out;
return out;
}

wire** evaluatorInA(Garbler alice, int size) {
wire** out;
return out;
}

wire** execA(Garbler alice, wire** func, wire** inpt) {
wire** out;
return out;
}

Garbler new_Garbler() {
Garbler x;
return x;
}

bool* int2bitsA(int x) {
bool* x;
return x;
}

wire** garblerInB(Evaluator bob, int size) {
wire** out;
return out;
}

wire** evaluatorInB(Evaluator bob, bool* inputB, int size) {
wire** out;
return out;
}

wire** execB(Evaluator bob, wire** func, wire** inpt) {
wire** out;
return out;
}

Evaluator new_Evaluator() {
Evaluator x;
return x;
}

bool* int2bitsB(int x) {
bool* x;
return x;
}

// Common application code
wire* mux(wire* x, wire* y, wire* c) {
return xor(and(c, xor(x,y)), y);
}

wire** mux8(wire** ws) {
wire* x = *ws;
wire* y = *ws + 8;
wire* c = *ws + 16;
wire** ret;
for (int i = 0; i < 8; i++) {
ret[i] = mux(x+i, y+i, c);
}
return ret;
}

// Alice's main function
void main1()
{
/*
Justification:
The garbler represents a trusted party.
We do not want the garbler to be accessed or
modified except by trusted functions.
*/
Garbler alice__fln_0;
alice = new_Garbler();

/*
Justification:
Alice's input is a secret, trusted value.
*/
bool* inputA__fln_1;
inputA = int2bitsA(0x01AA);

wire **wsA = garblerInA(alice, inputA, 8);
wire **wsB = evaluatorInA(alice, 8);

wire **ws;
for (int i = 0; i < 8; i++)
{
*ws[i] = *wsA[i];
*ws[i + 8] = *wsB[i];
}
*ws[16] = garblerInA(alice, inputA + 8, 1);
wire **os = execA(alice, mux8, ws);
bool *ret;
for (int i = 0; i < 8; i++)
evaluatorOut(os[i]);
free(os);
}
// Bob's main function
void main2()
{
Evaluator bob;
bob = new_Evaluator();

bool* inputB;
inputB = int2bitsB(0xBB);

wire **wsA = garblerInB(bob, 8);
wire **wsB = evaluatorInB(bob, inputB, 8);
wire **ws;
for (int i = 0; i < 8; i++)
{
*ws[i] = *wsA[i];
*ws[i + 8] = *wsB[i];
}
*ws[16] = garblerInB(bob, 1);
wire **os = execB(bob, mux8, ws);
bool *ret;
for (int i = 0; i < 8; i++)
ret[i] = evaluatorOut(os[i]);
printf("%d", bits2int(ret));
free(os);
}
