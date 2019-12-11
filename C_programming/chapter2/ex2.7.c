 #include<stdio.h>
 unsigned invert(unsigned x, int p, int n);
 int main()
 {
   int x, p, n, result = 0, i = 1, ans, r;
   printf ("Enter x :");
   scanf ("%u", &x);
   printf ("Enter p :");
   scanf ("%d", &p);
   printf ("Enter n :");
   scanf ("%d", &n);
   ans = invert(x, p, n);
  /*while (ans != 0)
   {
     r = ans % 2;
     result = result + r * i;
     ans = ans / 2;
     i = i * 10;
   }*/
   printf ("result = %u\n", ans);
   return 0;
 }
 unsigned invert(unsigned x, int p, int n)
 {
    return  x ^ (~(~0 << n) << (p + 1 - n));
 }
