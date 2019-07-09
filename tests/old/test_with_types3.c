typedef struct { int d; } __fln__int_trusted;
int __fln__read_int_trusted(__fln__int_trusted src) {
    return src.d;
}
__fln__int_trusted __fln__write_int_trusted(int src) {
    __fln__int_trusted dest;
    dest.d = src;
    return dest;
}

// #provides :return @trusted
// int getInput() {
__fln__int_trusted getInput() {
    int x = 4;
    return __fln__write_int_trusted(x);
}

// #provides :read @trusted
int encrypt(int x) {
    int x2;
    // x2 = x + 1;
    x2 = x + 1;
    return x2; 
}

// #provides :read @trusted
// #provides :return @trusted
// int passThrough(int x) {
__fln__int_trusted passThrough(int x) {
    return __fln__write_int_trusted(x);
}

int network_send(int x) { 
    return 0;
}

int main() {

    // #requires :read @trusted
	// int x;
    __fln__int_trusted x;

    x = getInput();

    // #requires :read @trusted
    // int y;
    __fln__int_trusted y;
    
    y = passThrough(__fln__read_int_trusted(x)); // Case 1: private -> private

    int x2;

	x2 = encrypt(__fln__read_int_trusted(x)); // Case 2: private -> public

    network_send(x2);  // Only valid if case 2 called

    return 0;
}
