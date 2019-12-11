#include<stdio.h>
#define MAXLINE 1000
int getlines(char line[], int max);
int strindex(char *, char *);
char pattern[] = "ould";
int main()
{
  char line[MAXLINE];
  int found = 0;
  while (getlines(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0)
    {
      printf ("%s", line);
      found++;
    }
 return found;
}
int getlines(char s[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
     s[i++] = c;
     if (c == '\n')
     s[i++] = c;
     s[i] = '\0';
     return i;
}
int strindex(char *s, char *t)
{
  char *b = s;
  char *p, *r;
  for (; *s != '\0'; s++)
  {
    for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
    ;
    if (r > t && *r == '\0')
    return s - b;
  }
return -1;
}
