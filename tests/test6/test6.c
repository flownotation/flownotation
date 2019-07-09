
// Test #has :param(1)
#has :param(1) @tag
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
#has :param(2) @tag
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
#has :param @tag
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
#has :return @tag
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
#has :param(1) @tag
#has :read @tag
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
#has :param(1) @tag
#has :write @tag
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

#has :param(1) @tag
#has :read @tag
#has :write @tag
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

#has :param(1) @tag
#has :read @tag
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

#has :param(1) @tag
#has :write @tag
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

#provides :read @tag
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

#provides :write @tag
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
    #requires :read @tag
    int x;
    x = 17;
}

void test_requires_write_call(int x) {
    x;
}

void test_requires_write() {
    #requires :write @tag
    int x;
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
