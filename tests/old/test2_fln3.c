/*---------------------------------------------------*/
/*              From the Preprocessor                */
/*---------------------------------------------------*/
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
__fln__int_encrypt __fln__write_int_encrypt(int x) {
    __fln__int_encrypt __fln__ret_val_0;
    __fln__ret_val_0.d = x;
    return __fln__ret_val_0;
}
// Holds tags
typedef struct {
    __fln__int_encrypt encrypt;
    __fln__int_trusted trusted;
} __fln__int_table;
__fln__int_table __fln__int_cast_encrypt(__fln__int_encrypt x) {
    __fln__int_table __fln__ret_val_0;
    __fln__ret_val_0.encrypt = x;
    return __fln__ret_val_0;
}
__fln__int_table __fln__int_cast_trusted(__fln__int_trusted x) {
    __fln__int_table __fln__ret_val_0;
    __fln__ret_val_0.trusted = x;
    return __fln__ret_val_0;
}



/*---------------------------------------------------*/
/*                 Transformed Code                  */
/*---------------------------------------------------*/

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
    return __fln__read_int_encrypt(o.encrypt) + 2;
}

// #provides :read @trusted
// #provides :write @encrypt
/*
int testFunc(int f) {
    return f + 3;
}
*/
__fln__int_encrypt testFunc(__fln__int_table f) {
    int __fln__tmp_1 = __fln__read_int_trusted(f.trusted) + 3;
    return __fln__write_int_encrypt(__fln__tmp_1);
}

int main() {
    // #requires :read @trusted @encrypt
    // #requires :write @trusted
    /*
    int x;
    */
    __fln__int_table x;

    // x = getInput();
    x = __fln__int_cast_trusted(getInput());

    int y = getWithSecret(x);

    y = encrypt(x);

    return y;
}
