#include<stdio.h>
#include<string.h>
#define MAX 100
int j = 0;
void reverse(char s[]);
int main()
{
  int c, i;
  char s[MAX];
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != '\n'; i++)
  s[i] = c;
  j = strlen(s);
  reverse(s);
  printf ("%s\n", s);
  return 0;
}
void reverse(char s[])
{
  int c;
  static int i = -1;
  i++, j--;
  if (j > i+1)
  {
   reverse(s);
   i--;j++;
 }
  c = s[i], s[i] = s[j], s[j] = c;
}
