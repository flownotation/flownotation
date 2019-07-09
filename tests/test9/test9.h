#ifndef TEST9_H
#define TEST9_H
struct foo { int x; };

struct foo1 {
    int x;
};

struct foo2 {
    struct foo1;
};
#endif