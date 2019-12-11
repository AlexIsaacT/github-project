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
  mid = (low + high) / 2;
  while (low <= high && x != v[mid])
  {
    if (x < v[mid])
    high = mid - 1;
    else
    low = mid + 1;
    mid = (low + high) / 2;
  }
  if (x == v[mid])
     return mid;
  else
     return -1;
}
