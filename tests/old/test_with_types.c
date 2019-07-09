
typedef struct {} privInt;
typedef struct {} pubInt;

// #provides :return @trusted
privInt getInput() {
    privInt x;
    return x;
}

// #provides :read @trusted
pubInt encrypt(privInt x) { 
    pubInt x2;
    return x2; 
}

// #provides :read @trusted
// #provides :return @trusted
privInt passThrough(privInt x) { 
    return x; 
}

int network_send(pubInt x) { 
    return 0;
}

int main() {

    // #requires :read @trusted
	privInt x;

    x = getInput();

    // #requires @trusted
	privInt y;
    
    y = passThrough(x); // Case 1: private -> private

	pubInt x2 = encrypt(x); // Case 2: private -> public

    network_send(x);  // Only valid if case 2 called

    return 0;
}
