#include<stdio.h>
#define MAX 100
void shellsort(char v[], int n);
int main()
{
  int c, i, n;
  char v[MAX];
  for (i = 0; i <= MAX; i++)
  v[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  v[i] = c;
  n = i;
  shellsort(v, n);
  printf ("%s\n", v);
  return 0;
}
void shellsort(char v[], int n)
{
  int gap, i, j, temp;
  for (gap = n / 2; gap > 0; gap /= 2)
      for (i = gap; i < n; i++)
          for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j-=gap)
          {
            temp = v[j];
            v[j] = v[j+gap];
            v[j+gap] = temp;
          }
  }
