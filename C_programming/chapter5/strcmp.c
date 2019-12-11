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
  int i;
  for (i = 0; s[i] == t[i]; i++)
     if (s[i] == '\0')
        return 0;
     return s[i] - t[i];
}
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
