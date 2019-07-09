/*---------------------------------------------------*/
/*              From the Preprocessor                */
/*---------------------------------------------------*/
// @trusted
typedef struct { int d; } __fln__trusted_int;
// :read
int __fln__trusted_int_read(__fln__trusted_int x) 
{
    return x.d;
}
// :write
__fln__trusted_int __fln__trusted_int_write(int x) 
{
    __fln__trusted_int __fln__tmp_0;
    __fln__tmp_0.d = x;
    return __fln__tmp_0;
}
// @encrypted
typedef struct { int d; } __fln__encrypted_int;
// :read
int __fln__encrypted_int_read(__fln__encrypted_int x) 
{
    return x.d;
}
// :write
__fln__encrypted_int __fln__encrypted_int_write(int x)
 {
    __fln__encrypted_int __fln__tmp_0;
    __fln__tmp_0.d = x;
    return __fln__tmp_0;
}
// (*Autogen*) @TABLE_int
typedef struct {
    int d;
    __fln__encrypted_int encrypted;
    __fln__trusted_int trusted;
} __fln__TABLE_int;
// CAST
__fln__TABLE_int __fln__trusted_int_cast_TABLE(__fln__trusted_int x) 
{
    __fln__TABLE_int __fln__tmp_0;
    __fln__tmp_0.trusted = x;
    return __fln__tmp_0;
}
// CAST
__fln__TABLE_int __fln__encrypted_int_cast_TABLE(__fln__encrypted_int x) 
{
    __fln__TABLE_int __fln__tmp_0;
    __fln__tmp_0.encrypted = x;
    return __fln__tmp_0;
}




// #provides :write @trusted
// #provides :return @trusted
__fln__trusted_int getInput() {
    __fln__trusted_int __fln__tmp_0;
    __fln__tmp_0 = __fln__trusted_int_write(1);
    return __fln__tmp_0;
}

// #provides :param(x) @trusted
// #provides :read @trusted
// #provides :write @encrypted
// #provides :return @encrypted
__fln__encrypted_int encrypt(__fln__trusted_int x) {
    int __fln__tmp_0;
    __fln__tmp_0 = __fln__trusted_int_read(x);
    __fln__encrypted_int __fln__tmp_1;
    __fln__tmp_1 = __fln__encrypted_int_write(__fln__tmp_0 + 1);
    return __fln__tmp_1;
}

// #provides :param(inpt) @ecrypted
void parseInput(__fln__encrypted_int inpt) {
    int __fln__tmp_0;
    __fln__tmp_0 = __fln__encrypted_int_read(inpt);
    __fln__tmp_0 + 1;
}

// #provides :read @trusted @encrypted
// #provides :write @trusted @encrypted
int main() {

    // #requires :param @trusted @encrypted
    // #requires :read @trusted @encrypted
    // #requires :write @trusted @encrypted
    // #requires :return @trusted @encrypted
    __fln__TABLE_int x;

    __fln__trusted_int __fln__tmp_0;
    __fln__tmp_0 = getInput();
    x = __fln__trusted_int_cast_TABLE(__fln__tmp_0);

    __fln__encrypted_int y;
    __fln__trusted_int __fln__tmp_1;
    __fln__tmp_1 = x.trusted;
    y = encrypt(__fln__tmp_1);

    parseInput(y);

    return 0;
}
