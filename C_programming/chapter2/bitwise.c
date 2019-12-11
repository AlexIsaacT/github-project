#include<stdio.h>
unsigned getbits(unsigned x, int p, int n);
int main()
{
  int x, p, n, result = 0, dec, i = 1, ans, r;
  printf ("Enter x :");
  scanf ("%u", &x);
  printf ("Enter p :");
  scanf ("%d", &p);
  printf ("Enter n :");
  scanf ("%d", &n);
  ans = getbits(x, p, n);
/*  while (ans != 0)
  {
    r = ans % 2;
    result = result + r * i;
    ans = ans / 2;
    i = i * 10;
  }*/
  printf ("result = %u\n", ans);
  return 0;
}
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
