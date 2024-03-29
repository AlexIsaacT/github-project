#include<stdio.h>
void qsort(int v[], int left, int right);
int getlines(char s[], int max);
int main()
{
 int left, right, v[12], i;
 for (i = 0; i < 12; i++)
 scanf ("%d", &v[i]);
 printf ("Enter left position : ");
 scanf ("%d", &left);
 printf ("Enter right position : ");
 scanf ("%d", &right);
 qsort(v, left, right);
 for (i = 0; i < 12; i++)
 printf ("%d ", v[i]);
 printf ("\n");
 return 0;
}
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);
  if (left >= right)
      return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left+1; i <= right; i++)
     if (v[i] < v[left])
        swap (v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}
void swap(int v[], int i, int j)
{
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
