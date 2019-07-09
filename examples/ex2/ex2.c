#include "ex2.h"

#provides :write @trusted
int getInput() {
    return 1;
}

#provides :read @trusted
#provides :write @encrypted
int encrypt(pair x) {
    return x;
}

#provides :read @encrypted
void parseInput(int inpt) {
    inpt + 1;
}

int main() {

    #requires :read @trusted
    int x;

    x = getInput();

    #requires :write @encrypted
    int y;
    
    y = encrypt(x);

    parseInput(y);

    return 0;
}
