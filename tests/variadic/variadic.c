#param(1) @Alice:secrecy
int f(int a, int b, ...) {
    return 0;
}

int main() {
    #requires @Alice:secrecy
    int x;

    int y;
    
    f(x, y);
    return 0;
}
