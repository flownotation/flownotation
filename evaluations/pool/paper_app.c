#include "paper_app.h"


#param(1) @garbler_protected:secrecy
#param(2) @alice_secret:secrecy
wire** garblerInA(Garbler alice, bool* inputA, int size) {
    wire** out;
    return out;
}

#param(1) @garbler_protected:secrecy
wire** evaluatorInA(Garbler alice, int size) {
    wire** out;
    return out;
}

#param(1) @garbler_protected:secrecy
#param(2) @prepared_function:secrecy
wire** execA(Garbler alice, wire** func, wire** inpt) {
    wire** out;
    return out;
}

#return @garbler_protected:integrity
Garbler new_Garbler() {
    Garbler x;
    return x;
}

#return @alice_secret:integrity
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
    #requires @garbler_protected:secrecy 
    #requires @garbler_protected:integrity 
    Garbler alice;
    alice = new_Garbler();

    /*
    Justification:
        Alice's input is a secret, trusted value.
    */
    #requires @alice_secret:secrecy
    #requires @alice_secret:integrity 
    bool* inputA;
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
