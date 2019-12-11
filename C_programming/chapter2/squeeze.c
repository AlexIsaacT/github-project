#include<stdio.h>
void squeeze(char s[]);
int main()
{
  char s[100];
  int i, c;
  for (i = 0; i <= 100; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != EOF ; i++)
  s[i] = c;
  squeeze(s);
  printf ("%s", s);
  return 0;
}
void squeeze(char s[])
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
  if (s[i] != 'c')
    s[j++] = s[i];

  s[j] = '\0';
}
