#include<stdio.h>
unsigned getbits(unsigned x, int p, int n, unsigned y);
int main()
{
  int x, y, p, n, result;
  printf ("Enter x :");
  scanf ("%u", &x);
  printf ("Enter y :");
  scanf ("%u", &y);
  printf ("Enter p :");
  scanf ("%d", &p);
  printf ("Enter n :");
  scanf ("%d", &n);
  result = getbits(x, p, n, y);
  printf ("result = %u\n", result);
  return 0;
}
unsigned getbits(unsigned x, int p, int n, unsigned y)
{
  return (x >> (p+1-n) & ~(~0 << n)) | (y & (~0 << n));
}
