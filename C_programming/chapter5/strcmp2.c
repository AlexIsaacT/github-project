#include<stdio.h>
int getlines(char []);
int strcmpp(char *s, char *t);
int main()
{
  char s[100], t[100];
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  printf ("%d\n", strcmpp(s, t));
  return 0;
}
int strcmpp(char *s, char *t)
{
  for (; *s == *t; s++, t++)
     if (*s == '\0')
        return 0;
     return *s - *t;
}
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
