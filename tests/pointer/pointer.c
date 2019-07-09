int f(int* a) {
    return 0;
}

int g(int a) {
    return 0;
}

int h(void* a) {
    return 0;
}

#param @Alice:secrecy
int i(int* a) {
    return 0;
}

int main() {

    // -------- Assignment of a variable that has a policy ------
    #requires @Alice:secrecy
    int x0;
    
    // Does not work (and should not): -Wincompatible-pointer-types
    int* y0 = &x0;

    // Does work and is OK
    #requires @Alice:secrecy
    int* y1;    
    y1 = &x0;
    
    // Does work and is NOT OK
    int* y2 = (int*) &x0;



    // -------- Function calls with a variable that has a policy ------

    // Does not work (and should not): -Wincompatible-pointer-types
    f(&x0);

    // Does not work (and should not): -Wincompatible-pointer-types
    f(y1);

    // Does work and is NOT OK
    f(y2);



    // -------- Assignment of a pointer that has a policy ------
    #requires @Bob:secrecy
    int* x1;

    // Does not work (and should not): error: incompatible types
    int y3 = *x1;

    // Does work and is OK
    #requires @Bob:secrecy
    int y4;
    y4 = *x1;

    // Does work and is NOT OK
    int y5 = *((int*) x1);



    // -------- Function calls with a pointer that has a policy ------

    // Does not work (and should not): error: incompatible type
    g(*x1);

    // Does not work (and should not): error: incompatible type
    g(y4);

    // Does work and is NOT OK
    g(y5);

    // ------------  Implicit Void Pointer Conversion ---------------

    // Does not work (and should not): error: incompatible type
    h(x0);

    // Does work and is NOT OK
    void* y6;
    i(y6);

    return 0;
}
