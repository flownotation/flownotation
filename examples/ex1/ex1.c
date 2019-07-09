#include "ex1.h"

// trusted_read allows for the reading of trusted data
#provides :read @trusted
int trusted_read(int x) {
    return x;
}

// trusted_write allows for the writing of trusted data
#provides :write @trusted
int trusted_write(int x) {
    return x;
}

int random_func(int x) {
    return x;
}

int main() {
    // x can only be read by a trusted function
    #requires :read @trusted
    int x;

    // y can only be written to by a trusted function
    #requires :write @trusted
    int y;

    int z;

    trusted_read(x);
    random_func(y);

}
