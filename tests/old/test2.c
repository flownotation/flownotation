// #provides :write @trusted
// #provides :return @trusted
int getInput() {
    return 1;
}

// #provides :param(loc) @trusted
// #provides :read @trusted
int getWithSecret(int loc) {
    return loc + 1;
}

// #provides :param(o) @encrypt
// #provides :read @encrypt
int encrypt(int o) {
    return o + 2;
}

// #provides :param(f) @trusted
// #provides :read @trusted
// #provides :write @encrypt
// #provides :return @encrypt
int testFunc(int f) {
    return f + 3;
}

// #provides :read @trusted
// #provides :write @encrypt
int main() {
    // #requires :read @trusted @encrypt
    // #requires :write @trusted
    int x;

    x = getInput();

    int y = getWithSecret(x);

    y = encrypt(x);

    return y;
} 
