#include "implicit__fln.h"

int main() {
int h__fln_0;

int l;
// Does not work (and should not): error: invalid operands to binary ==
if (h == 2) {
l = 1;
} else {
l = 0;
}


int h2__fln_1;

// Does not work (and should not): error: invalid operands to binary ==
if (h == h2) {
l = 1;
} else {
l = 0;
}

// Does not work (and should not): error: used struct type value
if (h) {
l = 1;
} else {
l = 0;
}


if (!h) {
l = 1;
} else {
l = 0;
}

return 0;
}
