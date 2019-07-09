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
#include "test9.h"

#include "test9__fln.h"

#include "test9__fln.h"

char f(int a) {
return (char) a;
}

int test() {
int a__fln_21;
{
{
f(a);
a = f(1);
}
}
}

int test_p() {
int* a__fln_24;
{
{
f(a);
a = f(1);
}
}
}

int test1() {
int a__fln_4;
{
{
f(a);
a = f(1);
}
}
}

int test1_p() {
int* a__fln_18;
{
{
f(a);
a = f(1);
}
}
}

int testf_1s(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_2s(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_3s(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_3sp(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_1i(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_2i(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_3i(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_3ip(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_3sip(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_4s(int a, int b) {
f(a);
a = 1;
return a;
}

int testf_4i(int a, int b) {
f(a);
a = 1;
return a;
}

int test2() {
int a__fln_11;
{
f(a);
{
a = b;
}
}
}

int test2_p() {
int* a__fln_13;
{
f(a);
{
a = b;
}
}
}


int test3() {
int a__fln_30;
{
y = f(a);
{
y = b;
}
}
}

int test3_p() {
int* a__fln_5;
{
y = f(a);
{
y = b;
}
}
}


int test4() {
int a__fln_25;
{
{
a = b;
}
}
}

int test4_p() {
int* a__fln_17;
{
{
a = b;
}
}
}

int test5() {
int a__fln_9;
{
{
a = b();
}
}
}

int test5_p() {
int a__fln_0;
{
{
a = b();
}
}
}

int test6() {
int a__fln_31;
f(a);
{
g(a);
{
h(a);
}
}
}

int test6_p() {
int* a__fln_20;
f(a);
{
g(a);
{
h(a);
}
}
}

int test7() {
int a__fln_8;
f(a);
{
g(a);
{
h(a);
}
}
}

int test7_p() {
int* a__fln_7;
f(a);
{
g(a);
{
h(a);
}
}
}

int test8() {
int a__fln_1;
b = f(a);
{
c = g(b);
{
d = h(c);
}
}
}

int test8_p() {
int* a__fln_16;
b = f(a);
{
c = g(b);
{
d = h(c);
}
}
}

int test9() {
int a__fln_23;
a = b;
a = c;
a = d;
}

int test9_p() {
int* a__fln_29;
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
struct foo1 x__fln_12;
}

int test10a() {
const struct foo1 x__fln_19;
}

int test11() {
struct foo1 x__fln_27;
}

int test11a() {
const struct foo1 x__fln_10;
}

int test12() {
struct foo1* x__fln_6;
}

int test12a() {
const struct foo1* x__fln_14;
}

int test13() {
struct foo1* x__fln_22;
}

int test13a() {
const int* x__fln_26;
}

int test14() {
int x__fln_2;
}

int test14a() {
const int x__fln_15;
}

int test15() {
int x__fln_3;
}

int test15a() {
const int* x__fln_28;
}

int test16(struct foo x) {
return 0;
}

int test16a(const struct foo x) {
return 0;
}

int test17(struct foo* x) {
return 0;
}

int test17a(const struct foo* x) {
return 0;
}

int main() {
return 0;
}

int test17a(volatile const int* x) {
return 0;
}
