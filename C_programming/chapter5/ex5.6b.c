#include<stdio.h>
#include<string.h>
#define MAX 100
void itoa(int n, char *);
void reverse(char *);
int main()
{
  int n;
  char s[MAX];
  scanf ("%d", &n);
  itoa(n, s);
  reverse(s);
  printf("%s\n", s);
  return 0;
}
void itoa(int n, char *s)
{
  int i, sign;
  if ((sign = n) < 0)
   n = -n;
  do {
     *s++ = n % 10 + '0';
  } while((n /= 10) > 0);
  if (sign < 0)
     *s++ = '-';
  *s = '\0';
}
void reverse(char *s)
{
  int temp;
  char *t;
  for (t = s + (strlen(s) - 1); s < t; s++, t--)
  {
  temp = *s;
  *s = *t;
  *t = temp;
 }
}
