#include<stdio.h>
#define swap(t, x, y)  {t z ; z = x; x = y ; y = z;}
int main()
{
  int x = 10, y = 20;
  printf ("Before swap : x = %d , y = %d\n", x, y);
  swap(int , x, y);
  printf ("After swap : x = %d , y = %d\n", x, y);
  return 0;
}
