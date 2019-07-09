
#provides :return @trusted
int getInput() {
    return 1;
}

#provides :param(x) @trusted
#provides :return @encrypted
int encrypt(int x) {
    return x + 1;
}

#provides :param(inpt) @encrypted
void parseInput(int inpt) {
    inpt + 1;
}

#provides :read @trusted OR @encrypt
#provides :write @trusted OR @encrypt
int main() {

    #requires :param @trusted AND @encrypt
    #requires :return @trusted
    int x;

    x = getInput();

    int y;
    
    y = encrypt(x);

    parseInput(y);

    return 0;
}








