#include<stdio.h>
#include<string.h>
#define MAX 100
void reverse(char s[]);
int main()
{
  int c, i;
  char s[MAX];
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  s[i] = c;
  reverse(s);
  printf ("%s\n", s);
  return 0;
}
void reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
  c = s[i], s[i] = s[j], s[j] = c;
  }
}
