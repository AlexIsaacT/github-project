#include<stdio.h>
#include<ctype.h>
#define MAX 100
int atoi(char s[]);
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
int atoi(char s[])
{
 int i, n, sign;
 for (i = 0; isspace(s[i]); i++)
 ;
 sign = (s[i] == '-') ? -1 : 1;
 if (s[i] == '+' || s[i] == '-')
  i++;
  for (n = 0; isdigit(s[i]); i++)
   n = 10 * n + (s[i] - '0');
 return sign * n;
}
