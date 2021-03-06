// @trusted  int -> __fln__int_trusted
typedef struct { int d; } __fln__int_trusted;
// :read  new -> original
int __fln__read_int_trusted(__fln__int_trusted x) {
    return x.d;
}
// :write  original -> new
__fln__int_trusted __fln__write_int_trusted(int x) {
    __fln__int_trusted __fln__ret_val_0;
    __fln__ret_val_0.d = x;
    return __fln__ret_val_0;
}
// @trusted  int -> __fln__int_encrypt
typedef struct { int d; } __fln__int_encrypt;
int __fln__read_int_encrypt(__fln__int_encrypt x) {
    return x.d;
}
// Holds tags
typedef struct { 
    __fln__int_encrypt encrypt;
    __fln__int_trusted trusted;
} __fln__int_table;

// #provides :write @trusted
/* 
int getInput() {
    return 1;
}
*/
__fln__int_trusted getInput() {
    /* Gets a secret input */
    return __fln__write_int_trusted(1);
}

// #provides :read @trusted
/* 
int getWithSecret(int loc) {
    return loc + 1;
} 
*/
int getWithSecret(__fln__int_table loc) {
    /* Determines a location given a secret x */
    return __fln__read_int_trusted(loc.trusted) + 1;
}

// #provides :read @encrypt
/*
int encrypt(int o) {
    return o + 2;
}
*/
int encrypt(__fln__int_table o) {
    return __fln__read_encrypt(o.encrypt) + 2;
}

int main() {
    // #requires :read @trusted @encrypt
    // #requires :write @trusted
    /*
    int x;
    */
    __fln__int_table x;

    x = getInput();

    int y = getWithSecret(x);

    y = encrypt(x);

    return y;
}
