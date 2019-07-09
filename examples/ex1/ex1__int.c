#include "ex1.h"

// trusted_read allows for the reading of trusted data
int trusted_read(int x) {
return x;
}

// trusted_write allows for the writing of trusted data
int trusted_write(int x) {
return x;
}

int random_func(int x) {
return x;
}

int main() {
// x can only be read by a trusted function
int x__fln_0;

// y can only be written to by a trusted function
int y__fln_1;

int z;

trusted_read(x);
random_func(y);

}
