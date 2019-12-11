#include<stdio.h>
#include<string.h>
#define MAX 100
void itoa(int n, char s[]);
void reverse(char s[]);
int main()
{
  int n;
  char s[MAX];
  scanf ("%d", &n);
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}
void itoa(int n, char s[])
{
  int i, sign;
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  if ((sign = n) < 0)
   n = -n;
  i = 0;
  do {
     s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if (sign < 0)
     s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
void reverse(char s[])
{
  int i, j, temp;
  for (i = 0; s[i] != '\0'; i++)
  ;
  i--;
  for (j = 0; j < i; j++, i--)
  {
  temp = s[j];
  s[j] = s[i];
  s[i] = temp;
 }
}
