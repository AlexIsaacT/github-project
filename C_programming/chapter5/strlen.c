#include<stdio.h>
int strlength(char *);
int main()
{
  char a[100];
  int i, c;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   a[i] = c;
   a[i] = '\0';
   printf ("%d\n", strlength(a));
   return 0;
}
int strlength(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
