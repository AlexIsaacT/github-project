#include<stdio.h>
#include<string.h>
#define MAX 100
void itoa(int n, char s[]);
int main()
{
  int n, i;
  char s[MAX];
  for (i = 0; i < MAX; i++)
  s[i] = 0;
  scanf ("%d", &n);
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}
void itoa(int n, char s[])
{
  static int i = 0;
  if (n < 0)
  {
   s[0] = '-';
    i++;
    n = -n;
  }
  if (n / 10)
   itoa(n / 10, s);
  s[i++] = (n % 10 + '0');
   s[i] = '\0';
}
