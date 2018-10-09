#include<stdio.h>

int logicalShift(int x, int n) {
  int sign = x & (0x1<<0x1f);
  x = (x^sign)>>n;
  sign = sign >> 0x1f & 0x1;
  return x ^ (sign<<0x1e>>n<<1);
}

int divpwr2(int x, int n) {
  int sign = x & (0x1 << 0x1f), t;
  t = (sign >> 0x1f) & 0x1;
  t = (t << 0x1) + t;
  x = x + ((t << n) >> 0x2);
  return x >> n;
}
unsigned float_neg(unsigned uf) {
  /* unsigned x = 0xff << 0x; */
  unsigned flag = 0x0, i = 0x17, last = uf & 0x1, cp = uf;
  // flag: 0表示为 NaN 1表示不是NaN
  while (i)
    {
      if (uf & 0x1 != last)
        flag = 0x1;
      i = i - 1;
      uf = uf >> 0x1;
    }
  if (((uf & 0xff) == 0xff) && flag)
    flag = 0x0;
  else
    flag = 0x1;
  return cp ^ (flag << 0x1f);
}

int isLessOrEqual(int x, int y) {
  int sign1 = ((x ^ y) >> 0x1f) & 0x1, sign2 = (y >> 0x1f) & 0x1, sign3, ans;
  // sign1: x y 同号为0 异号为1   sign2: y 的符号   sign3: ans = y - x 的符号
  x = ~x + 1;
  ans = x + y;
  sign3 = (ans >> 0x1f) & 0x1;
  return (sign1 & !sign2) | (!sign1 & !sign3);
}

unsigned float_twice(unsigned uf) {
    unsigned flag = 0x0, i = 0x17, last = uf & 0x1, cp = uf;
  // flag: 0表示为 NaN 1表示不是NaN
  if (!((uf >> 0x16) & 0x1))
  {
    unsigned x = (0xff | (0x1 << 8)) << 0x17;
    cp = x & uf;
    uf = (uf & ~x) << 0x1;
    return cp | uf;
  }
  while (i)
    {
      if (uf & 0x1 != last)
        flag = 0x1;
      i = i - 1;
      uf = uf >> 0x1;
    }
  if ((((uf & 0xff) == 0xff) && flag) || !((uf & 0xff) != 0x0 || flag || last))
    flag = 0x0;
  else
    flag = 0x1;
  return cp + (flag << 0x17);
}

int main(void)
{
    int n, x, y;
    //scanf("%d", &n);
    n = 0x80000000;
    x = 0x800002;
    y = 0x7fffffff;
    printf("\n%x\n",float_twice(n));
    return 0;
}
