int main() {
    #requires @Alice:secrecy
    int h;

    int l;
    
    // Does not work (and should not): error: invalid operands to binary ==
    if (h == 2) {
        l = 1;
    } else {
        l = 0;
    }


    #requires @Alice:secrecy
    int h2;

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

    // Does not work (and should not): error: error: wrong type argument
    if (!h) {
        l = 1;
    } else {
        l = 0;
    }

    return 0;
}
