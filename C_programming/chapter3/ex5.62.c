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
  printf("%s\n", s);
  return 0;
}
void itoa(int n, char *s)
{
  int  sign;
  if ((sign = n) < 0)
   n = -n;
  do {
     *s++ = n % 10 + '0';
  } while((n /= 10) > 0);
  if (sign < 0)
     *s++ = '-';
  *s = '\0';
  reverse(s);
}
void reverse(char *s)
{
  int i, j, temp;
  while (*s++ != '\0')
    ;
   s--;
  for (j = 0; j < *s; j++, s--)
  {
  temp = *s;
  s[j] = *s;
  *s = temp;
 }
}
