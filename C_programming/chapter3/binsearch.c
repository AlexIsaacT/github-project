#include<stdio.h>
int binsearch(int x, int v[], int n);
int main()
{
  int  n = 10, x;
  int v[] = {2, 4, 6, 10, 15, 23, 27, 32, 35, 45};
  printf ("Enter x : ");
  scanf ("%d", &x);
  printf("%d\n", binsearch (x, v, n));
  return 0;
}
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n-1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x < v[mid])
    high = mid - 1;
    else if (x > v[mid])
    low = mid + 1;
    else
     return mid;
  }
  return -1;
}
