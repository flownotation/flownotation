typedef struct {int d; } __fln__trusted_int_isRead;
typedef struct {int d; } __fln__trusted_int_isWrite;
int __fln__trusted_int_isRead_read(__fln__trusted_int_isRead x) { return x.d; }
int __fln__trusted_int_isWrite_read(__fln__trusted_int_isWrite x) { return x.d; }
__fln__trusted_int_isRead __fln__trusted_int_isRead_write(int x) {__fln__trusted_int_isRead y; y.d = x; return y; }
__fln__trusted_int_isWrite __fln__trusted_int_isWrite_write(int x) {__fln__trusted_int_isWrite y; y.d = x; return y; }

int trusted_read(__fln__trusted_int_isRead x)
{
  return __fln__trusted_int_isRead_read(x);
}

__fln__trusted_int_isWrite trusted_write(int x)
{
  return __fln__trusted_int_isWrite_write(x);
}

int main()
{
  __fln__trusted_int_isRead x;
  __fln__trusted_int_isWrite y;
  int z;
  z = 0;
  if (z)
  {
    z = trusted_read(x) + 1;
    x = __fln__trusted_int_isRead_write(z);
  }
  else
  {
    y = trusted_write(trusted_read(x));
    z = __fln__trusted_int_isWrite_read(y);
  }

}

