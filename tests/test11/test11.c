#include "test11.h"

int test3() { 
    #requires @test0a:secrecy .then @test0b:secrecy .then @test0c:secrecy 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test3() { 
    #requires @test1a:secrecy .then @test1b:secrecy 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test3() { 
    #requires @test2:secrecy 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test6() { 
    #requires @test3a:secrecy .then @test3b:secrecy .then @test3c:secrecy 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test6() { 
    #requires @test4a:secrecy .then @test4b:secrecy 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test6() { 
    #requires @test5:secrecy 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test9() { 
    #requires @test6a:integrity .then @test6b:integrity .then @test6c:integrity 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test9() { 
    #requires @test7a:integrity .then @test7b:integrity 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test9() { 
    #requires @test8:integrity 
    const struct foo* a; 
    { { f(a); a = f(1); } } }
int test12() { 
    #requires @test9a:integrity .then @test9b:integrity .then @test9c:integrity 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test12() { 
    #requires @test10a:integrity .then @test10b:integrity 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test12() { 
    #requires @test11:integrity 
    const struct foo a; 
    { { f(a); a = f(1); } } }
int test15() { 
    #requires @test12a:secrecy .then @test12b:secrecy .then @test12c:secrecy 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test15() { 
    #requires @test13a:secrecy .then @test13b:secrecy 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test15() { 
    #requires @test14:secrecy 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test18() { 
    #requires @test15a:secrecy .then @test15b:secrecy .then @test15c:secrecy 
    const struct foo a; 
    { f(a); { a = b; } } }
int test18() { 
    #requires @test16a:secrecy .then @test16b:secrecy 
    const struct foo a; 
    { f(a); { a = b; } } }
int test18() { 
    #requires @test17:secrecy 
    const struct foo a; 
    { f(a); { a = b; } } }
int test21() { 
    #requires @test18a:integrity .then @test18b:integrity .then @test18c:integrity 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test21() { 
    #requires @test19a:integrity .then @test19b:integrity 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test21() { 
    #requires @test20:integrity 
    const struct foo* a; 
    { f(a); { a = b; } } }
int test24() { 
    #requires @test21a:integrity .then @test21b:integrity .then @test21c:integrity 
    const struct foo a; 
    { f(a); { a = b; } } }
int test24() { 
    #requires @test22a:integrity .then @test22b:integrity 
    const struct foo a; 
    { f(a); { a = b; } } }
int test24() { 
    #requires @test23:integrity 
    const struct foo a; 
    { f(a); { a = b; } } }
int test27() { 
    #requires @test24a:secrecy .then @test24b:secrecy .then @test24c:secrecy 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test27() { 
    #requires @test25a:secrecy .then @test25b:secrecy 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test27() { 
    #requires @test26:secrecy 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test30() { 
    #requires @test27a:secrecy .then @test27b:secrecy .then @test27c:secrecy 
    const struct foo a; 
    a = b; a = c; a = d; }
int test30() { 
    #requires @test28a:secrecy .then @test28b:secrecy 
    const struct foo a; 
    a = b; a = c; a = d; }
int test30() { 
    #requires @test29:secrecy 
    const struct foo a; 
    a = b; a = c; a = d; }
int test33() { 
    #requires @test30a:integrity .then @test30b:integrity .then @test30c:integrity 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test33() { 
    #requires @test31a:integrity .then @test31b:integrity 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test33() { 
    #requires @test32:integrity 
    const struct foo* a; 
    a = b; a = c; a = d; }
int test36() { 
    #requires @test33a:integrity .then @test33b:integrity .then @test33c:integrity 
    const struct foo a; 
    a = b; a = c; a = d; }
int test36() { 
    #requires @test34a:integrity .then @test34b:integrity 
    const struct foo a; 
    a = b; a = c; a = d; }
int test36() { 
    #requires @test35:integrity 
    const struct foo a; 
    a = b; a = c; a = d; }
#param @test36:secrecy 
int test37(const struct foo* a, const struct foo* b) { 
    f(a); a = 1; return a; }
#param @test37:secrecy 
int test38(const struct foo a, const struct foo b) { 
    f(a); a = 1; return a; }
#param @test38:integrity 
int test39(const struct foo* a, const struct foo* b) { 
    f(a); a = 1; return a; }
#param @test39:integrity 
int test40(const struct foo a, const struct foo b) { 
    f(a); a = 1; return a; }
#return @test40:secrecy 
const struct foo* test41(int a, int b) { 
    f(a); a = 1; return a; }
#return @test41:secrecy 
const struct foo test42(int a, int b) { 
    f(a); a = 1; return a; }
#return @test42:integrity 
const struct foo* test43(int a, int b) { 
    f(a); a = 1; return a; }
#return @test43:integrity 
const struct foo test44(int a, int b) { 
    f(a); a = 1; return a; }
#param @test44:secrecy 
int test45(const struct foo* a) { 
    return 0; }
#param @test45:secrecy 
int test46(const struct foo a) { 
    return 0; }
#param @test46:integrity 
int test47(const struct foo* a) { 
    return 0; }
#param @test47:integrity 
int test48(const struct foo a) { 
    return 0; }
int test51() { 
    #requires @test48a:secrecy .then @test48b:secrecy .then @test48c:secrecy 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test51() { 
    #requires @test49a:secrecy .then @test49b:secrecy 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test51() { 
    #requires @test50:secrecy 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test54() { 
    #requires @test51a:secrecy .then @test51b:secrecy .then @test51c:secrecy 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test54() { 
    #requires @test52a:secrecy .then @test52b:secrecy 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test54() { 
    #requires @test53:secrecy 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test57() { 
    #requires @test54a:integrity .then @test54b:integrity .then @test54c:integrity 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test57() { 
    #requires @test55a:integrity .then @test55b:integrity 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test57() { 
    #requires @test56:integrity 
    const signed long int* a; 
    { { f(a); a = f(1); } } }
int test60() { 
    #requires @test57a:integrity .then @test57b:integrity .then @test57c:integrity 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test60() { 
    #requires @test58a:integrity .then @test58b:integrity 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test60() { 
    #requires @test59:integrity 
    const signed long int a; 
    { { f(a); a = f(1); } } }
int test63() { 
    #requires @test60a:secrecy .then @test60b:secrecy .then @test60c:secrecy 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test63() { 
    #requires @test61a:secrecy .then @test61b:secrecy 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test63() { 
    #requires @test62:secrecy 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test66() { 
    #requires @test63a:secrecy .then @test63b:secrecy .then @test63c:secrecy 
    const signed long int a; 
    { f(a); { a = b; } } }
int test66() { 
    // #requires @test64a:secrecy .then @test64b:secrecy 
    const signed long int a; 
    { f(a); { a = b; } } }
int test66() { 
    // #requires @test65:secrecy 
    const signed long int a; 
    { f(a); { a = b; } } }
int test69() { 
    // #requires @test66a:integrity .then @test66b:integrity .then @test66c:integrity 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test69() { 
    // #requires @test67a:integrity .then @test67b:integrity 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test69() { 
    // #requires @test68:integrity 
    const signed long int* a; 
    { f(a); { a = b; } } }
int test72() { 
    // #requires @test69a:integrity .then @test69b:integrity .then @test69c:integrity 
    const signed long int a; 
    { f(a); { a = b; } } }
int test72() { 
    // #requires @test70a:integrity .then @test70b:integrity 
    const signed long int a; 
    { f(a); { a = b; } } }
int test72() { 
    // #requires @test71:integrity 
    const signed long int a; 
    { f(a); { a = b; } } }
int test75() { 
    // #requires @test72a:secrecy .then @test72b:secrecy .then @test72c:secrecy 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test75() { 
    // #requires @test73a:secrecy .then @test73b:secrecy 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test75() { 
    // #requires @test74:secrecy 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test78() { 
    // #requires @test75a:secrecy .then @test75b:secrecy .then @test75c:secrecy 
    const signed long int a; 
    a = b; a = c; a = d; }
int test78() { 
    // #requires @test76a:secrecy .then @test76b:secrecy 
    const signed long int a; 
    a = b; a = c; a = d; }
int test78() { 
    // #requires @test77:secrecy 
    const signed long int a; 
    a = b; a = c; a = d; }
int test81() { 
    // #requires @test78a:integrity .then @test78b:integrity .then @test78c:integrity 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test81() { 
    // #requires @test79a:integrity .then @test79b:integrity 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test81() { 
    // #requires @test80:integrity 
    const signed long int* a; 
    a = b; a = c; a = d; }
int test84() { 
    // #requires @test81a:integrity .then @test81b:integrity .then @test81c:integrity 
    const signed long int a; 
    a = b; a = c; a = d; }
int test84() { 
    // #requires @test82a:integrity .then @test82b:integrity 
    const signed long int a; 
    a = b; a = c; a = d; }
int test84() { 
    // #requires @test83:integrity 
    const signed long int a; 
    a = b; a = c; a = d; }
// #param @test84:secrecy 
int test85(const signed long int* a, const signed long int* b) { 
    f(a); a = 1; return a; }
// #param @test85:secrecy 
int test86(const signed long int a, const signed long int b) { 
    f(a); a = 1; return a; }
// #param @test86:integrity 
int test87(const signed long int* a, const signed long int* b) { 
    f(a); a = 1; return a; }
// #param @test87:integrity 
int test88(const signed long int a, const signed long int b) { 
    f(a); a = 1; return a; }
// #return @test88:secrecy 
const signed long int* test89(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test89:secrecy 
const signed long int test90(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test90:integrity 
const signed long int* test91(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test91:integrity 
const signed long int test92(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test92:secrecy 
int test93(const signed long int* a) { 
    return 0; }
// #param @test93:secrecy 
int test94(const signed long int a) { 
    return 0; }
// #param @test94:integrity 
int test95(const signed long int* a) { 
    return 0; }
// #param @test95:integrity 
int test96(const signed long int a) { 
    return 0; }
int test99() { 
    // #requires @test96a:secrecy .then @test96b:secrecy .then @test96c:secrecy 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test99() { 
    // #requires @test97a:secrecy .then @test97b:secrecy 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test99() { 
    // #requires @test98:secrecy 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test102() { 
    // #requires @test99a:secrecy .then @test99b:secrecy .then @test99c:secrecy 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test102() { 
    // #requires @test100a:secrecy .then @test100b:secrecy 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test102() { 
    // #requires @test101:secrecy 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test105() { 
    // #requires @test102a:integrity .then @test102b:integrity .then @test102c:integrity 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test105() { 
    // #requires @test103a:integrity .then @test103b:integrity 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test105() { 
    // #requires @test104:integrity 
    const unsigned long int* a; 
    { { f(a); a = f(1); } } }
int test108() { 
    // #requires @test105a:integrity .then @test105b:integrity .then @test105c:integrity 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test108() { 
    // #requires @test106a:integrity .then @test106b:integrity 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test108() { 
    // #requires @test107:integrity 
    const unsigned long int a; 
    { { f(a); a = f(1); } } }
int test111() { 
    // #requires @test108a:secrecy .then @test108b:secrecy .then @test108c:secrecy 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test111() { 
    // #requires @test109a:secrecy .then @test109b:secrecy 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test111() { 
    // #requires @test110:secrecy 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test114() { 
    // #requires @test111a:secrecy .then @test111b:secrecy .then @test111c:secrecy 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test114() { 
    // #requires @test112a:secrecy .then @test112b:secrecy 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test114() { 
    // #requires @test113:secrecy 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test117() { 
    // #requires @test114a:integrity .then @test114b:integrity .then @test114c:integrity 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test117() { 
    // #requires @test115a:integrity .then @test115b:integrity 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test117() { 
    // #requires @test116:integrity 
    const unsigned long int* a; 
    { f(a); { a = b; } } }
int test120() { 
    // #requires @test117a:integrity .then @test117b:integrity .then @test117c:integrity 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test120() { 
    // #requires @test118a:integrity .then @test118b:integrity 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test120() { 
    // #requires @test119:integrity 
    const unsigned long int a; 
    { f(a); { a = b; } } }
int test123() { 
    // #requires @test120a:secrecy .then @test120b:secrecy .then @test120c:secrecy 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test123() { 
    // #requires @test121a:secrecy .then @test121b:secrecy 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test123() { 
    // #requires @test122:secrecy 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test126() { 
    // #requires @test123a:secrecy .then @test123b:secrecy .then @test123c:secrecy 
    const unsigned long int a; 
    a = b; a = c; a = d; }
int test126() { 
    // #requires @test124a:secrecy .then @test124b:secrecy 
    const unsigned long int a; 
    a = b; a = c; a = d; }
int test126() { 
    // #requires @test125:secrecy 
    const unsigned long int a; 
    a = b; a = c; a = d; }
int test129() { 
    // #requires @test126a:integrity .then @test126b:integrity .then @test126c:integrity 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test129() { 
    // #requires @test127a:integrity .then @test127b:integrity 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test129() { 
    // #requires @test128:integrity 
    const unsigned long int* a; 
    a = b; a = c; a = d; }
int test132() { 
    // #requires @test129a:integrity .then @test129b:integrity .then @test129c:integrity 
    const unsigned long int a; 
    a = b; a = c; a = d; }
int test132() { 
    // #requires @test130a:integrity .then @test130b:integrity 
    const unsigned long int a; 
    a = b; a = c; a = d; }
int test132() { 
    // #requires @test131:integrity 
    const unsigned long int a; 
    a = b; a = c; a = d; }
// #param @test132:secrecy 
int test133(const unsigned long int* a, const unsigned long int* b) { 
    f(a); a = 1; return a; }
// #param @test133:secrecy 
int test134(const unsigned long int a, const unsigned long int b) { 
    f(a); a = 1; return a; }
// #param @test134:integrity 
int test135(const unsigned long int* a, const unsigned long int* b) { 
    f(a); a = 1; return a; }
// #param @test135:integrity 
int test136(const unsigned long int a, const unsigned long int b) { 
    f(a); a = 1; return a; }
// #return @test136:secrecy 
const unsigned long int* test137(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test137:secrecy 
const unsigned long int test138(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test138:integrity 
const unsigned long int* test139(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test139:integrity 
const unsigned long int test140(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test140:secrecy 
int test141(const unsigned long int* a) { 
    return 0; }
// #param @test141:secrecy 
int test142(const unsigned long int a) { 
    return 0; }
// #param @test142:integrity 
int test143(const unsigned long int* a) { 
    return 0; }
// #param @test143:integrity 
int test144(const unsigned long int a) { 
    return 0; }
int test147() { 
    // #requires @test144a:secrecy .then @test144b:secrecy .then @test144c:secrecy 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test147() { 
    // #requires @test145a:secrecy .then @test145b:secrecy 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test147() { 
    // #requires @test146:secrecy 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test150() { 
    // #requires @test147a:secrecy .then @test147b:secrecy .then @test147c:secrecy 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test150() { 
    // #requires @test148a:secrecy .then @test148b:secrecy 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test150() { 
    // #requires @test149:secrecy 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test153() { 
    // #requires @test150a:integrity .then @test150b:integrity .then @test150c:integrity 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test153() { 
    // #requires @test151a:integrity .then @test151b:integrity 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test153() { 
    // #requires @test152:integrity 
    const unsigned short int* a; 
    { { f(a); a = f(1); } } }
int test156() { 
    // #requires @test153a:integrity .then @test153b:integrity .then @test153c:integrity 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test156() { 
    // #requires @test154a:integrity .then @test154b:integrity 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test156() { 
    // #requires @test155:integrity 
    const unsigned short int a; 
    { { f(a); a = f(1); } } }
int test159() { 
    // #requires @test156a:secrecy .then @test156b:secrecy .then @test156c:secrecy 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test159() { 
    // #requires @test157a:secrecy .then @test157b:secrecy 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test159() { 
    // #requires @test158:secrecy 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test162() { 
    // #requires @test159a:secrecy .then @test159b:secrecy .then @test159c:secrecy 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test162() { 
    // #requires @test160a:secrecy .then @test160b:secrecy 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test162() { 
    // #requires @test161:secrecy 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test165() { 
    // #requires @test162a:integrity .then @test162b:integrity .then @test162c:integrity 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test165() { 
    // #requires @test163a:integrity .then @test163b:integrity 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test165() { 
    // #requires @test164:integrity 
    const unsigned short int* a; 
    { f(a); { a = b; } } }
int test168() { 
    // #requires @test165a:integrity .then @test165b:integrity .then @test165c:integrity 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test168() { 
    // #requires @test166a:integrity .then @test166b:integrity 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test168() { 
    // #requires @test167:integrity 
    const unsigned short int a; 
    { f(a); { a = b; } } }
int test171() { 
    // #requires @test168a:secrecy .then @test168b:secrecy .then @test168c:secrecy 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test171() { 
    // #requires @test169a:secrecy .then @test169b:secrecy 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test171() { 
    // #requires @test170:secrecy 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test174() { 
    // #requires @test171a:secrecy .then @test171b:secrecy .then @test171c:secrecy 
    const unsigned short int a; 
    a = b; a = c; a = d; }
int test174() { 
    // #requires @test172a:secrecy .then @test172b:secrecy 
    const unsigned short int a; 
    a = b; a = c; a = d; }
int test174() { 
    // #requires @test173:secrecy 
    const unsigned short int a; 
    a = b; a = c; a = d; }
int test177() { 
    // #requires @test174a:integrity .then @test174b:integrity .then @test174c:integrity 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test177() { 
    // #requires @test175a:integrity .then @test175b:integrity 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test177() { 
    // #requires @test176:integrity 
    const unsigned short int* a; 
    a = b; a = c; a = d; }
int test180() { 
    // #requires @test177a:integrity .then @test177b:integrity .then @test177c:integrity 
    const unsigned short int a; 
    a = b; a = c; a = d; }
int test180() { 
    // #requires @test178a:integrity .then @test178b:integrity 
    const unsigned short int a; 
    a = b; a = c; a = d; }
int test180() { 
    // #requires @test179:integrity 
    const unsigned short int a; 
    a = b; a = c; a = d; }
// #param @test180:secrecy 
int test181(const unsigned short int* a, const unsigned short int* b) { 
    f(a); a = 1; return a; }
// #param @test181:secrecy 
int test182(const unsigned short int a, const unsigned short int b) { 
    f(a); a = 1; return a; }
// #param @test182:integrity 
int test183(const unsigned short int* a, const unsigned short int* b) { 
    f(a); a = 1; return a; }
// #param @test183:integrity 
int test184(const unsigned short int a, const unsigned short int b) { 
    f(a); a = 1; return a; }
// #return @test184:secrecy 
const unsigned short int* test185(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test185:secrecy 
const unsigned short int test186(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test186:integrity 
const unsigned short int* test187(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test187:integrity 
const unsigned short int test188(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test188:secrecy 
int test189(const unsigned short int* a) { 
    return 0; }
// #param @test189:secrecy 
int test190(const unsigned short int a) { 
    return 0; }
// #param @test190:integrity 
int test191(const unsigned short int* a) { 
    return 0; }
// #param @test191:integrity 
int test192(const unsigned short int a) { 
    return 0; }
int test195() { 
    // #requires @test192a:secrecy .then @test192b:secrecy .then @test192c:secrecy 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test195() { 
    // #requires @test193a:secrecy .then @test193b:secrecy 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test195() { 
    // #requires @test194:secrecy 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test198() { 
    // #requires @test195a:secrecy .then @test195b:secrecy .then @test195c:secrecy 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test198() { 
    // #requires @test196a:secrecy .then @test196b:secrecy 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test198() { 
    // #requires @test197:secrecy 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test201() { 
    // #requires @test198a:integrity .then @test198b:integrity .then @test198c:integrity 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test201() { 
    // #requires @test199a:integrity .then @test199b:integrity 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test201() { 
    // #requires @test200:integrity 
    const signed short int* a; 
    { { f(a); a = f(1); } } }
int test204() { 
    // #requires @test201a:integrity .then @test201b:integrity .then @test201c:integrity 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test204() { 
    // #requires @test202a:integrity .then @test202b:integrity 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test204() { 
    // #requires @test203:integrity 
    const signed short int a; 
    { { f(a); a = f(1); } } }
int test207() { 
    // #requires @test204a:secrecy .then @test204b:secrecy .then @test204c:secrecy 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test207() { 
    // #requires @test205a:secrecy .then @test205b:secrecy 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test207() { 
    // #requires @test206:secrecy 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test210() { 
    // #requires @test207a:secrecy .then @test207b:secrecy .then @test207c:secrecy 
    const signed short int a; 
    { f(a); { a = b; } } }
int test210() { 
    // #requires @test208a:secrecy .then @test208b:secrecy 
    const signed short int a; 
    { f(a); { a = b; } } }
int test210() { 
    // #requires @test209:secrecy 
    const signed short int a; 
    { f(a); { a = b; } } }
int test213() { 
    // #requires @test210a:integrity .then @test210b:integrity .then @test210c:integrity 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test213() { 
    // #requires @test211a:integrity .then @test211b:integrity 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test213() { 
    // #requires @test212:integrity 
    const signed short int* a; 
    { f(a); { a = b; } } }
int test216() { 
    // #requires @test213a:integrity .then @test213b:integrity .then @test213c:integrity 
    const signed short int a; 
    { f(a); { a = b; } } }
int test216() { 
    // #requires @test214a:integrity .then @test214b:integrity 
    const signed short int a; 
    { f(a); { a = b; } } }
int test216() { 
    // #requires @test215:integrity 
    const signed short int a; 
    { f(a); { a = b; } } }
int test219() { 
    // #requires @test216a:secrecy .then @test216b:secrecy .then @test216c:secrecy 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test219() { 
    // #requires @test217a:secrecy .then @test217b:secrecy 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test219() { 
    // #requires @test218:secrecy 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test222() { 
    // #requires @test219a:secrecy .then @test219b:secrecy .then @test219c:secrecy 
    const signed short int a; 
    a = b; a = c; a = d; }
int test222() { 
    // #requires @test220a:secrecy .then @test220b:secrecy 
    const signed short int a; 
    a = b; a = c; a = d; }
int test222() { 
    // #requires @test221:secrecy 
    const signed short int a; 
    a = b; a = c; a = d; }
int test225() { 
    // #requires @test222a:integrity .then @test222b:integrity .then @test222c:integrity 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test225() { 
    // #requires @test223a:integrity .then @test223b:integrity 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test225() { 
    // #requires @test224:integrity 
    const signed short int* a; 
    a = b; a = c; a = d; }
int test228() { 
    // #requires @test225a:integrity .then @test225b:integrity .then @test225c:integrity 
    const signed short int a; 
    a = b; a = c; a = d; }
int test228() { 
    // #requires @test226a:integrity .then @test226b:integrity 
    const signed short int a; 
    a = b; a = c; a = d; }
int test228() { 
    // #requires @test227:integrity 
    const signed short int a; 
    a = b; a = c; a = d; }
// #param @test228:secrecy 
int test229(const signed short int* a, const signed short int* b) { 
    f(a); a = 1; return a; }
// #param @test229:secrecy 
int test230(const signed short int a, const signed short int b) { 
    f(a); a = 1; return a; }
// #param @test230:integrity 
int test231(const signed short int* a, const signed short int* b) { 
    f(a); a = 1; return a; }
// #param @test231:integrity 
int test232(const signed short int a, const signed short int b) { 
    f(a); a = 1; return a; }
// #return @test232:secrecy 
const signed short int* test233(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test233:secrecy 
const signed short int test234(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test234:integrity 
const signed short int* test235(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test235:integrity 
const signed short int test236(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test236:secrecy 
int test237(const signed short int* a) { 
    return 0; }
// #param @test237:secrecy 
int test238(const signed short int a) { 
    return 0; }
// #param @test238:integrity 
int test239(const signed short int* a) { 
    return 0; }
// #param @test239:integrity 
int test240(const signed short int a) { 
    return 0; }
int test243() { 
    // #requires @test240a:secrecy .then @test240b:secrecy .then @test240c:secrecy 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test243() { 
    // #requires @test241a:secrecy .then @test241b:secrecy 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test243() { 
    // #requires @test242:secrecy 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test246() { 
    // #requires @test243a:secrecy .then @test243b:secrecy .then @test243c:secrecy 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test246() { 
    // #requires @test244a:secrecy .then @test244b:secrecy 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test246() { 
    // #requires @test245:secrecy 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test249() { 
    // #requires @test246a:integrity .then @test246b:integrity .then @test246c:integrity 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test249() { 
    // #requires @test247a:integrity .then @test247b:integrity 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test249() { 
    // #requires @test248:integrity 
    const unsigned int* a; 
    { { f(a); a = f(1); } } }
int test252() { 
    // #requires @test249a:integrity .then @test249b:integrity .then @test249c:integrity 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test252() { 
    // #requires @test250a:integrity .then @test250b:integrity 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test252() { 
    // #requires @test251:integrity 
    const unsigned int a; 
    { { f(a); a = f(1); } } }
int test255() { 
    // #requires @test252a:secrecy .then @test252b:secrecy .then @test252c:secrecy 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test255() { 
    // #requires @test253a:secrecy .then @test253b:secrecy 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test255() { 
    // #requires @test254:secrecy 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test258() { 
    // #requires @test255a:secrecy .then @test255b:secrecy .then @test255c:secrecy 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test258() { 
    // #requires @test256a:secrecy .then @test256b:secrecy 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test258() { 
    // #requires @test257:secrecy 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test261() { 
    // #requires @test258a:integrity .then @test258b:integrity .then @test258c:integrity 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test261() { 
    // #requires @test259a:integrity .then @test259b:integrity 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test261() { 
    // #requires @test260:integrity 
    const unsigned int* a; 
    { f(a); { a = b; } } }
int test264() { 
    // #requires @test261a:integrity .then @test261b:integrity .then @test261c:integrity 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test264() { 
    // #requires @test262a:integrity .then @test262b:integrity 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test264() { 
    // #requires @test263:integrity 
    const unsigned int a; 
    { f(a); { a = b; } } }
int test267() { 
    // #requires @test264a:secrecy .then @test264b:secrecy .then @test264c:secrecy 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test267() { 
    // #requires @test265a:secrecy .then @test265b:secrecy 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test267() { 
    // #requires @test266:secrecy 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test270() { 
    // #requires @test267a:secrecy .then @test267b:secrecy .then @test267c:secrecy 
    const unsigned int a; 
    a = b; a = c; a = d; }
int test270() { 
    // #requires @test268a:secrecy .then @test268b:secrecy 
    const unsigned int a; 
    a = b; a = c; a = d; }
int test270() { 
    // #requires @test269:secrecy 
    const unsigned int a; 
    a = b; a = c; a = d; }
int test273() { 
    // #requires @test270a:integrity .then @test270b:integrity .then @test270c:integrity 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test273() { 
    // #requires @test271a:integrity .then @test271b:integrity 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test273() { 
    // #requires @test272:integrity 
    const unsigned int* a; 
    a = b; a = c; a = d; }
int test276() { 
    // #requires @test273a:integrity .then @test273b:integrity .then @test273c:integrity 
    const unsigned int a; 
    a = b; a = c; a = d; }
int test276() { 
    // #requires @test274a:integrity .then @test274b:integrity 
    const unsigned int a; 
    a = b; a = c; a = d; }
int test276() { 
    // #requires @test275:integrity 
    const unsigned int a; 
    a = b; a = c; a = d; }
// #param @test276:secrecy 
int test277(const unsigned int* a, const unsigned int* b) { 
    f(a); a = 1; return a; }
// #param @test277:secrecy 
int test278(const unsigned int a, const unsigned int b) { 
    f(a); a = 1; return a; }
// #param @test278:integrity 
int test279(const unsigned int* a, const unsigned int* b) { 
    f(a); a = 1; return a; }
// #param @test279:integrity 
int test280(const unsigned int a, const unsigned int b) { 
    f(a); a = 1; return a; }
// #return @test280:secrecy 
const unsigned int* test281(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test281:secrecy 
const unsigned int test282(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test282:integrity 
const unsigned int* test283(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test283:integrity 
const unsigned int test284(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test284:secrecy 
int test285(const unsigned int* a) { 
    return 0; }
// #param @test285:secrecy 
int test286(const unsigned int a) { 
    return 0; }
// #param @test286:integrity 
int test287(const unsigned int* a) { 
    return 0; }
// #param @test287:integrity 
int test288(const unsigned int a) { 
    return 0; }
int test291() { 
    // #requires @test288a:secrecy .then @test288b:secrecy .then @test288c:secrecy 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test291() { 
    // #requires @test289a:secrecy .then @test289b:secrecy 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test291() { 
    // #requires @test290:secrecy 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test294() { 
    // #requires @test291a:secrecy .then @test291b:secrecy .then @test291c:secrecy 
    const long double a; 
    { { f(a); a = f(1); } } }
int test294() { 
    // #requires @test292a:secrecy .then @test292b:secrecy 
    const long double a; 
    { { f(a); a = f(1); } } }
int test294() { 
    // #requires @test293:secrecy 
    const long double a; 
    { { f(a); a = f(1); } } }
int test297() { 
    // #requires @test294a:integrity .then @test294b:integrity .then @test294c:integrity 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test297() { 
    // #requires @test295a:integrity .then @test295b:integrity 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test297() { 
    // #requires @test296:integrity 
    const long double* a; 
    { { f(a); a = f(1); } } }
int test300() { 
    // #requires @test297a:integrity .then @test297b:integrity .then @test297c:integrity 
    const long double a; 
    { { f(a); a = f(1); } } }
int test300() { 
    // #requires @test298a:integrity .then @test298b:integrity 
    const long double a; 
    { { f(a); a = f(1); } } }
int test300() { 
    // #requires @test299:integrity 
    const long double a; 
    { { f(a); a = f(1); } } }
int test303() { 
    // #requires @test300a:secrecy .then @test300b:secrecy .then @test300c:secrecy 
    const long double* a; 
    { f(a); { a = b; } } }
int test303() { 
    // #requires @test301a:secrecy .then @test301b:secrecy 
    const long double* a; 
    { f(a); { a = b; } } }
int test303() { 
    // #requires @test302:secrecy 
    const long double* a; 
    { f(a); { a = b; } } }
int test306() { 
    // #requires @test303a:secrecy .then @test303b:secrecy .then @test303c:secrecy 
    const long double a; 
    { f(a); { a = b; } } }
int test306() { 
    // #requires @test304a:secrecy .then @test304b:secrecy 
    const long double a; 
    { f(a); { a = b; } } }
int test306() { 
    // #requires @test305:secrecy 
    const long double a; 
    { f(a); { a = b; } } }
int test309() { 
    // #requires @test306a:integrity .then @test306b:integrity .then @test306c:integrity 
    const long double* a; 
    { f(a); { a = b; } } }
int test309() { 
    // #requires @test307a:integrity .then @test307b:integrity 
    const long double* a; 
    { f(a); { a = b; } } }
int test309() { 
    // #requires @test308:integrity 
    const long double* a; 
    { f(a); { a = b; } } }
int test312() { 
    // #requires @test309a:integrity .then @test309b:integrity .then @test309c:integrity 
    const long double a; 
    { f(a); { a = b; } } }
int test312() { 
    // #requires @test310a:integrity .then @test310b:integrity 
    const long double a; 
    { f(a); { a = b; } } }
int test312() { 
    // #requires @test311:integrity 
    const long double a; 
    { f(a); { a = b; } } }
int test315() { 
    // #requires @test312a:secrecy .then @test312b:secrecy .then @test312c:secrecy 
    const long double* a; 
    a = b; a = c; a = d; }
int test315() { 
    // #requires @test313a:secrecy .then @test313b:secrecy 
    const long double* a; 
    a = b; a = c; a = d; }
int test315() { 
    // #requires @test314:secrecy 
    const long double* a; 
    a = b; a = c; a = d; }
int test318() { 
    // #requires @test315a:secrecy .then @test315b:secrecy .then @test315c:secrecy 
    const long double a; 
    a = b; a = c; a = d; }
int test318() { 
    // #requires @test316a:secrecy .then @test316b:secrecy 
    const long double a; 
    a = b; a = c; a = d; }
int test318() { 
    // #requires @test317:secrecy 
    const long double a; 
    a = b; a = c; a = d; }
int test321() { 
    // #requires @test318a:integrity .then @test318b:integrity .then @test318c:integrity 
    const long double* a; 
    a = b; a = c; a = d; }
int test321() { 
    // #requires @test319a:integrity .then @test319b:integrity 
    const long double* a; 
    a = b; a = c; a = d; }
int test321() { 
    // #requires @test320:integrity 
    const long double* a; 
    a = b; a = c; a = d; }
int test324() { 
    // #requires @test321a:integrity .then @test321b:integrity .then @test321c:integrity 
    const long double a; 
    a = b; a = c; a = d; }
int test324() { 
    // #requires @test322a:integrity .then @test322b:integrity 
    const long double a; 
    a = b; a = c; a = d; }
int test324() { 
    // #requires @test323:integrity 
    const long double a; 
    a = b; a = c; a = d; }
// #param @test324:secrecy 
int test325(const long double* a, const long double* b) { 
    f(a); a = 1; return a; }
// #param @test325:secrecy 
int test326(const long double a, const long double b) { 
    f(a); a = 1; return a; }
// #param @test326:integrity 
int test327(const long double* a, const long double* b) { 
    f(a); a = 1; return a; }
// #param @test327:integrity 
int test328(const long double a, const long double b) { 
    f(a); a = 1; return a; }
// #return @test328:secrecy 
const long double* test329(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test329:secrecy 
const long double test330(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test330:integrity 
const long double* test331(int a, int b) { 
    f(a); a = 1; return a; }
// #return @test331:integrity 
const long double test332(int a, int b) { 
    f(a); a = 1; return a; }
// #param @test332:secrecy 
int test333(const long double* a) { 
    return 0; }
// #param @test333:secrecy 
int test334(const long double a) { 
    return 0; }
// #param @test334:integrity 
int test335(const long double* a) { 
    return 0; }
// #param @test335:integrity 
int test336(const long double a) { 
    return 0; }
int test339() { 
    // #requires @test336a:secrecy .then @test336b:secrecy .then @test336c:secrecy 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test339() { 
    // #requires @test337a:secrecy .then @test337b:secrecy 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test339() { 
    // #requires @test338:secrecy 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test342() { 
    // #requires @test339a:secrecy .then @test339b:secrecy .then @test339c:secrecy 
    const short int a; 
    { { f(a); a = f(1); } } }
int test342() { 
    // #requires @test340a:secrecy .then @test340b:secrecy 
    const short int a; 
    { { f(a); a = f(1); } } }
int test342() { 
    // #requires @test341:secrecy 
    const short int a; 
    { { f(a); a = f(1); } } }
int test345() { 
    // #requires @test342a:integrity .then @test342b:integrity .then @test342c:integrity 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test345() { 
    // #requires @test343a:integrity .then @test343b:integrity 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test345() { 
    // #requires @test344:integrity 
    const short int* a; 
    { { f(a); a = f(1); } } }
int test348() { 
    // #requires @test345a:integrity .then @test345b:integrity .then @test345c:integrity 
    const short int a; 
    { { f(a); a = f(1); } } }
int test348() { 
    // #requires @test346a:integrity .then @test346b:integrity 
    const short int a; 
    { { f(a); a = f(1); } } }
int test348() { 
    // #requires @test347:integrity 
    const short int a; 
    { { f(a); a = f(1); } } }
int test351() { 
    // #requires @test348a:secrecy .then @test348b:secrecy .then @test348c:secrecy 
    const short int* a; 
    { f(a); { a = b; } } }
int test351() { 
    // #requires @test349a:secrecy .then @test349b:secrecy 
    const short int* a; 
    { f(a); { a = b; } } }
int test351() { 
    // #requires @test350:secrecy 
    const short int* a; 
    { f(a); { a = b; } } }
int test354() { 
    // #requires @test351a:secrecy .then @test351b:secrecy .then @test351c:secrecy 
    const short int a; 
    { f(a); { a = b; } } }
int test354() { 
    // #requires @test352a:secrecy .then @test352b:secrecy 
    const short int a; 
    { f(a); { a = b; } } }
int test354() { 
    // #requires @test353:secrecy 
    const short int a; 
    { f(a); { a = b; } } }
int test357() { 
    // #requires @test354a:integrity .then @test354b:integrity .then @test354c:integrity 
    const short int* a; 
    { f(a); { a = b; } } }
int test357() { 
    // #requires @test355a:integrity .then @test355b:integrity 
    const short int* a; 
    { f(a); { a = b; } } }
int test357() { 
    // #requires @test356:integrity 
    const short int* a; 
    { f(a); { a = b; } } }
int test360() { 
    // #requires @test357a:integrity .then @test357b:integrity .then @test357c:integrity 
    const short int a; 
    { f(a); { a = b; } } }
int test360() { 
    // #requires @test358a:integrity .then @test358b:integrity 
    const short int a; 
    { f(a); { a = b; } } }
int test360() { 
    // #requires @test359:integrity 
    const short int a; 
    { f(a); { a = b; } } }
int test363() { 
    // #requires @test360a:secrecy .then @test360b:secrecy .then @test360c:secrecy 
    const short int* a; 
    a = b; a = c; a = d; }
int test363() { 
    // #requires @test361a:secrecy .then @test361b:secrecy 
    const short int* a; 
    a = b; a = c; a = d; }