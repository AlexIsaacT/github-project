#include<stdio.h>
#define TOTALBITS 32
unsigned rightrot(unsigned x,int n);
int main()
{
   int x, n, result;
   printf ("Enter x : ");
   scanf ("%u", &x);
   printf ("Enter n : ");
   scanf ("%d", &n);
   result = rightrot(x, n);
   printf("%u\n", result);
   return 0;
}
unsigned rightrot(unsigned x,int n)
{
unsigned v, r;
v = ~(~0 << n) & x;
r = v << (TOTALBITS - n);
x = x >> n;
return x | r;
}
