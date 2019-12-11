#include<stdio.h>
#define MAX 100
int atoi(char *s);
int main()
{
  int c, i;
  char s[MAX];
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  s[i] = c;
  printf ("%d\n", atoi(s));
  return 0;
}
int atoi(char *s)
{
  int n;
  n = 0;
  for (; *s >= '0' && *s <= '9'; s++)
  n = 10 * n + (*s - '0');
  return n;
}
