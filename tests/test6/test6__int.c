
// Test #has :param(1)
int test_has_param_1(int x) {
return 0;
}

/*
Expect:
int test_has_param_1(__fln__tag_int x)
{
return 0;
}
*/

// Test #has :param(2)
int test_has_param_2(int x, int y) {
return 0;
}

/*
Expect:
int test_has_param_2(int x, __fln__tag_int y)
{
return 0;
}
*/

// Test #has :param
int test_has_param_all(int x, int y) {
return 0;
}

/*
Expect:
int test_has_param_all(__fln__tag_int x, __fln__tag_int y)
{
return 0;
}
*/

// Test #has :return
int test_has_return() {
return 0;
}

/*
Expect:
__fln__tag_int test_has_return()
{
return 0;
}
*/

// Test assign read
int test_assign_read(int x) {
x = 1;
return 0;
}

/*
Expect:
int test_assign_read(__fln__tag_int x)
{
x = __fln__tag_int_write(1);
return 0;
}
*/

// Test assign write
int test_assign_write(int x) {
int y;
y = x;
return 0;
}

/*
Expect:
int test_assign_write(__fln__tag_int x)
{
int y;
y = __fln__tag_int_write(x);
return 0;
}
*/

int test_assign_read_write(int x) {
int y;
y = x;
return 0;
}

/*
Expect:
int test_assign_read_write(__fln__tag_int x)
{
int y;
y = x;
return 0;
}
*/

void func(int x) {
return 0;
}

int test_id_read(int x) {
func(x);
return 0;
}

/*
Expect:
void func(int x)
{
return 0;
}

int test_id_read(__fln__tag_int x)
{
func(__fln__tag_int_read(x));
return 0;
}
*/

void func1(int x) {
return 0;
}

int test_id_write(int x) {
x = func1(x);
return 0;
}

/*
Expect:
void func1(int x)
{
return 0;
}

int test_id_write(__fln__tag_int x)
{
func(x);
return 0;
}
*/

void func2(int x) {
return 0;
}

int test_provides_read(int x) {
func2(x);
return 0;
}

/*
Expect:
void func2(int x)
{
return 0;
}

int test_provides_read(__fln__tag_int x)
{
func2(__fln__tag_int_read(x));
return 0;
}
*/

void func3(int x) {
return 0;
}

int test_provides_write(int x) {
func3(x);
return 0;
}

/*
Expect:
void func3(int x)
{
return 0;
}

int test_provides_write(__fln__tag_int x)
{
func3(x);
return 0;
}
*/

void test_requires_read() {
int x;
x = 17;
}

void test_requires_write_call(int x) {
x;
}

void test_requires_write() {
int x__fln_1;
test_requires_write_call(x);
}

int main() {
return 0;
}

/*
Expect:
int main()
{
__fln__tag_int x;
x = __fln__tag_int_write(17);
}
*/
