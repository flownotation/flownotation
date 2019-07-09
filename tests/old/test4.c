
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
    #requires :write @trusted
    int x;

    // y can only be written to by a trusted function
    #requires :read @trusted
    #requires :write @trusted
    int y;

    int z;

    // No error
    x = trusted_write(1);
    // Error
    z = trusted_read(x);
    // No Error
    z = trusted_read(y);
    // Error
    y = trusted_write(1);
    // No Error
    x = trusted_write(trusted_read(y));
    // Error
    y = trusted_write(trusted_read(x));

    random_func(trusted_read(x));


}
