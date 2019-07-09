#include "test9.h"

char f(int a) {
    return (char) a;
}

int test() {
    #requires @test1:secrecy
    int a;
    {
        {
            f(a);
            a = f(1);
        }
    }
}

int test_p() {
    #requires @test1:secrecy
    int* a;
    {
        {   
            f(a);
            a = f(1);
        }
    }
}

int test1() {
    #requires @test1:integrity 
    int a;
    {
        {
            f(a);
            a = f(1);
        }
    }
}

int test1_p() {
    #requires @test1:integrity 
    int* a;
    {
        {
            f(a);
            a = f(1);
        }
    }
}

#param @test1:secrecy 
int testf_1s(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(1) @test1:secrecy 
int testf_2s(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(2) @test1:secrecy 
int testf_3s(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(1) @test1:secrecy 
#param(2) @test2:secrecy 
int testf_3sp(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param @test1:integrity 
int testf_1i(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(1) @test1:integrity 
int testf_2i(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(2) @test1:integrity 
int testf_3i(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(1) @test1:integrity 
#param(2) @test2:integrity 
int testf_3ip(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#param(1) @test1:secrecy
#param(2) @test2:integrity 
int testf_3sip(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#return @test1:secrecy 
int testf_4s(int a, int b) {
    f(a);
    a = 1;
    return a;
}

#return @test1:integrity 
int testf_4i(int a, int b) {
    f(a);
    a = 1;
    return a;
}

int test2() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int a;
    {
        f(a);
        {
            a = b;
        }
    }
}

int test2_p() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int* a;
    {
        f(a);
        {
            a = b;
        }
    }
}


int test3() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int a;
    {
        y = f(a);
        {
            y = b;
        }
    }
}

int test3_p() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int* a;
    {
        y = f(a);
        {
            y = b;
        }
    }
}


int test4() {
    #requires @test1:integrity .then @test2:integrity
    int a;
    {
        {
            a = b;
        }
    }
}

int test4_p() {
    #requires @test1:integrity .then @test2:integrity
    int* a;
    {
        {
            a = b;
        }
    }
}

int test5() {
    #requires @test1:integrity .then @test2:integrity
    int a;
    {
        {
            a = b();
        }
    }
}

int test5_p() {
    #requires @test1:integrity .then @test2:integrity
    int a;
    {
        {
            a = b();
        }
    }
}

int test6() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int a;
    f(a);
    {
        g(a);
        {
            h(a);
        }
    }
}

int test6_p() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy
    int* a;
    f(a);
    {
        g(a);
        {
            h(a);
        }
    }
}

int test7() {
    #requires @test1:integrity .then @test2:integrity .then @test3:integrity
    int a;
    f(a);
    {
        g(a);
        {
            h(a);
        }
    }
}

int test7_p() {
    #requires @test1:integrity .then @test2:integrity .then @test3:integrity
    int* a;
    f(a);
    {
        g(a);
        {
            h(a);
        }
    }
}

int test8() {
    #requires @test1:secrecy .then @test2:secrecy .then @test3:secrecy .then @test4:secrecy
    int a;
    b = f(a);
    {
        c = g(b);
        {
            d = h(c);
        }
    }
}

int test8_p() {
    #requires @test1:integrity .then @test2:integrity .then @test3:integrity .then @test4:integrity
    int* a;
    b = f(a);
    {
        c = g(b);
        {
            d = h(c);
        }
    }
}

int test9() {
    #requires @test1:integrity .then @test2:integrity .then @test3:integrity
    int a;
    a = b;
    a = c;
    a = d;
}

int test9_p() {
    #requires @test1:integrity .then @test2:integrity .then @test3:integrity
    int* a;
    a = b;
    a = c;
    a = d;
}

// int test11() {
//     #requires {f1.int @trusted:integrity, f2.float @authentic:secrecy}
//     foo b;
// }

// struct foo { int x; };

// struct foo1 {
//     int x;
// };

// struct foo2 {
//     struct foo1;
// };

// typedef struct foo3 {
//     int x;
// };

// typedef struct {
//     int x;
// } foo4;

int test10() {
    #requires @test1:integrity
    struct foo1 x;
}

int test10a() {
    #requires @test1:secrecy
    const struct foo1 x;
}

int test11() {
    #requires @test1:integrity .then @test2:integrity
    struct foo1 x;
}

int test11a() {
    #requires @test1:secrecy .then @test2:secrecy
    const struct foo1 x;
}

int test12() {
    #requires @test1:integrity
    struct foo1* x;
}

int test12a() {
    #requires @test1:secrecy
    const struct foo1* x;
}

int test13() {
    #requires @test1:integrity .then @test2:integrity
    struct foo1* x;
}

int test13a() {
    #requires @test1:secrecy .then @test2:secrecy
    const int* x;
}

int test14() {
    #requires @test1:integrity
    int x;
}

int test14a() {
    #requires @test1:integrity
    const int x;
}

int test15() {
    #requires @test1:integrity
    int x;
}

int test15a() {
    #requires @test1:integrity
    const int* x;
}

#param @test1:integrity
int test16(struct foo x) {
    return 0;
}

#param @test1:integrity
int test16a(const struct foo x) {
    return 0;
}

#param @test1:integrity
int test17(struct foo* x) {
    return 0;
}

#param @test1:integrity
int test17a(const struct foo* x) {
    return 0;
}

int main() {
    return 0;
}

#param @test1:integrity
int test17a(volatile const int* x) {
    return 0;
}
