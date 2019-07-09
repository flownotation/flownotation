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