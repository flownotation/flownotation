typedef int pair;
__fln__trusted_int getInput()
{
  return __fln__trusted_int_write(1);
}

__fln__encrypted_int encrypt(__fln__trusted_pair x)
{
  pair x__fln_p = __fln__trusted_pair_read(x);
  return __fln__encrypted_int_write(x, _, _, f, l, n, _, p);
}

void parseInput(__fln__encrypted_int inpt)
{
  int inpt__fln_p = __fln__encrypted_int_read(inpt);
  inpt__fln_p + 1;
}

int main()
{
  int x__fln_0;
  x = getInput();
  __fln__encrypted_int y;
  y = encrypt(x);
  parseInput(__fln__encrypted_int_read(y));
  return 0;
}

