
// void test_call(int x) {
//     x;
// }

// #provides :read(1) @secure
// #provides :read(2) @secure
// int test(int y, int* z) {
//     #requires :read @trusted
//     int x;

//     test_call(x);

//     x = 17; 
// }

// #provides :write @fish
// int test2() {
//     #requires :write @trusted
//     int x;

//     test_call(x);

//     x = 17; 

//     #requires :read @trusted
//     int y;

//     return 0;
// }

typedef struct foo {
    int data; 
    float num; 
} foo;

#provides :integrity @authentic
int f(int x) {
    return 0;
}

float h() {
    return 0.0;
}

void g(int x) {
    return 0;
}

int main() {
    #requires :integrity.{int:data} @authentic
    foo x = {.data=1, .num=2.7};
    x.data = f(1);
    x.num = h();
    g(x.num);
    return 0;
}
