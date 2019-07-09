typedef struct { int d; } __fln__int_trusted;
int __fln__read_int_trusted(__fln__int_trusted src) {
    return src.d;
}

// #provides :return @trusted
// int getInput() {
__fln__int_trusted getInput() {
    __fln__int_trusted x;
    return x;
}

// #provides :encrypt @trusted
// int encrypt(int x) {
int encrypt(__fln__int_trusted x) {
    int x2;
    // x2 = x + 1;
    x2 = __fln__read_int_trusted(x) + 1;
    return x2; 
}

// #provides :read @trusted
// #provides :return @trusted
// int passThrough(int x) {
__fln__int_trusted passThrough(__fln__int_trusted x) {
    return x; 
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
    
    y = passThrough(x);

    int x2;

	x2 = encrypt(x);

    network_send(x2);

    return 0;
}
