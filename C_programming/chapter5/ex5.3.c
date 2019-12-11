#include<stdio.h>
int getlines(char []);
void strcatt(char *s, char *t);
int main()
{
  char s[100], t[100];
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  strcatt(s, t);
  printf ("%s\n", s);
  return 0;
}
void strcatt(char *s, char *t)
{
  while (*s++ != '\0')
   ;
  s--;
  while ((*s++ = *t++) != '\0')
    ;
  }
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
