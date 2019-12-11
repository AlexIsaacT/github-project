#include<stdio.h>
int strlength(char *);
int main()
{
  int i, c;
  char a[100];
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
    a[i] = c;
    a[i] = '\0';
  printf ("%d\n", strlength(a));
}
int strlength(char *s)
{
  char *p = s;
  while (*p != '\0')
     p++;
  return p - s;
}
