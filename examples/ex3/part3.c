#include "part2.c"

int main() {
    #requires :read @test
    int x;

    test1();

    #requires :read @trusted
    int y;
    test2(y);
}
