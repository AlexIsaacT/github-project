#include<stdio.h>
int getlines(char *);
int main()
{
  char s[100];
  getlines(s);
  printf ("%s\n", s);
  return 0;
}
int getlines(char *s)
{
  int c;
  for (; (c = getchar()) != EOF && c != '\n'; s++)
    *s = c ;
  *s = '\0';
}
