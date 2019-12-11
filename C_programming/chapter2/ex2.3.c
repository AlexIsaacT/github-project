#include<stdio.h>
#define MAX 20
int htoi(char s[]);
int main()
{
  int i, c;
  char s[MAX];
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  s[i] = c;
  printf ("The integer value is %d\n", htoi(s));
  return 0;
}
int htoi(char s[])
{
  int i = 0, n = 0, hex;
  if (s[i] == 0)
   {
     i++;
     if (s[i] == 'x' || 'X')
     i++;
   }
   for (; s[i] != '\n'; i++)
   {
   if (s[i] >= '0' && s[i] <= '9')
   hex = s[i] - '0';
   else if (s[i] >= 'A' && s[i] <= 'F')
   hex = s[i] - 'A' + 10;
   else if (s[i] >= 'a' && s[i] <= 'f')
   hex = s[i] - 'a' + 10;
   n = 16 * n + hex;
 }
  return n;
}
