/*---------------------------------------------------*/
/*              From the Preprocessor                */
/*---------------------------------------------------*/
// @trusted  int -> __fln__int_trusted
typedef struct { int d; } __fln__int_trusted;
// :read  new -> original
int __fln__read_int_trusted(__fln__int_trusted x) 
{
    return x.d;
}
// :write  original -> new
__fln__int_trusted __fln__write_int_trusted(int x) 
{
    __fln__int_trusted __fln__ret_val_0;
    __fln__ret_val_0.d = x;
    return __fln__ret_val_0;
}
// @trusted  int -> __fln__int_encrypt
typedef struct { int d; } __fln__int_encrypt;
int __fln__read_int_encrypt(__fln__int_encrypt x) 
{
    return x.d;
}
__fln__int_encrypt __fln__write_int_encrypt(int x)
 {
    __fln__int_encrypt __fln__ret_val_0;
    __fln__ret_val_0.d = x;
    return __fln__ret_val_0;
}
// Holds tags
typedef struct {
    __fln__int_encrypt encrypt;
    __fln__int_trusted trusted;
} __fln__int_table;
__fln__int_table __fln__int_cast_encrypt(__fln__int_encrypt x) 
{
    __fln__int_table __fln__ret_val_0;
    __fln__ret_val_0.encrypt = x;
    return __fln__ret_val_0;
}
__fln__int_table __fln__int_cast_trusted(__fln__int_trusted x) 
{
    __fln__int_table __fln__ret_val_0;
    __fln__ret_val_0.trusted = x;
    return __fln__ret_val_0;
}
__fln__int_trusted __fln__int_cast_table_trusted(__fln__int_table x) 
{
    __fln__int_trusted __fln__ret_val_0;
    __fln__ret_val_0 = x.trusted;
    return __fln__ret_val_0;
}
__fln__int_encrypt __fln__int_cast_table_encrypt(__fln__int_table x) 
{
    __fln__int_encrypt __fln__ret_val_0;
    __fln__ret_val_0 = x.encrypt;
    return __fln__ret_val_0;
}



/*---------------------------------------------------*/
/*                 Transformed Code                  */
/*---------------------------------------------------*/

// #provides :write @trusted
// #provides :return @trusted
/* 
int getInput() {
    return 1;
}
*/
__fln__int_trusted getInput() 
{
    /* Gets a secret input */
    int inpt = 1;
    __fln__int_trusted __fln__int_tmp1;
    __fln__int_tmp1 = __fln__write_int_trusted(inpt);
    return __fln__int_tmp1;
}

// #provides :param(loc) @trusted
// #provides :read @trusted
/* 
int getWithSecret(int loc) {
    return loc + 1;
} 
*/
int getWithSecret(__fln__int_trusted loc) 
{
    /* Determines a location given a secret x */
    int __fln__int_tmp1;
    __fln__int_tmp1 = __fln__read_int_trusted(loc);
    int __fln__int_tmp2;
    __fln__int_tmp2 = __fln__int_tmp1 + 1;
    return  __fln__int_tmp2;
}

// #provides :param(o) @encrypt
// #provides :read @encrypt
/*
int encrypt(int o) {
    return o + 2;
}
*/
int encrypt(__fln__int_encrypt o) 
{
    int __fln__int_tmp1;
    __fln__int_tmp1 = __fln__read_int_encrypt(o);
    int __fln__int_tmp2; 
    __fln__int_tmp2 = __fln__int_tmp1 + 2;
    return __fln__int_tmp2;
}

// #provides :param(f) @trusted
// #provides :read @trusted
// #provides :write @encrypt
// #provides :return @encrypt
/*
int testFunc(int f) {
    return f + 3;
}
*/
__fln__int_encrypt testFunc(__fln__int_trusted f) 
{
    int __fln__int_tmp1;
    __fln__int_tmp1 = __fln__read_int_trusted(f);
    int __fln__int_tmp2;
    __fln__int_tmp2 = __fln__int_tmp1 + 3;
    __fln__int_encrypt __fln__int_tmp3;
    __fln__int_tmp3 = __fln__write_int_encrypt(__fln__int_tmp2);
    return __fln__int_tmp3;
}

// #provides :read @trusted
// #provides :read @encrypt
int main() 
{
    // #requires :param @trusted @encrypt
    // #requires :read @trusted @encrypt
    // #requires :write @trusted
    // #requires :return @encrypt
    /* int x; */
    __fln__int_table x;

    /* x = getInput(); */
    __fln__int_trusted __fln__int_tmp1;
    __fln__int_tmp1 = getInput();
    __fln__int_table __fln__int_tmp2;
    __fln__int_tmp2 = __fln__int_cast_trusted(__fln__int_tmp1);
    x = __fln__int_tmp2;

    /* int y = getWithSecret(x); */
    __fln__int_trusted __fln__int_tmp3;
    __fln__int_tmp3 = __fln__int_cast_table_trusted(x);
    int y = getWithSecret(__fln__int_tmp3);

    /* y = encrypt(x); */
    __fln__int_encrypt __fln__int_tmp4;
    __fln__int_tmp4 = __fln__int_cast_table_encrypt(x);
    y = encrypt(__fln__int_tmp4);

    return y;
}
