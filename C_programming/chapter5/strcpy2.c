#include<stdio.h>
int getlines(char []);
void strcpyy(char *s, char *t);
int main()
{
  char s[100], t[100];
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  strcpyy(s, t);
  printf ("%s\n", s);
  return 0;
}
void strcpyy(char *s, char *t)
{
  while (*s++ = *t++)
   ;
}
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
