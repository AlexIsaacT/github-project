#include<stdio.h>
int bitcount(unsigned x);
int main()
{
  unsigned x;
  printf ("Enter x : ");
  scanf ("%u", &x);
  printf ("%d\n", bitcount(x));
  return 0;
}
int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 1)
     b++;
  return b;
}
