#include<stdio.h>
#include<string.h>
#define MAXLINE 100
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch();
void ungets(char s[]);
void ungetch(int c)
int getlines(char s[], int maxline);
int main()
{
  int c;
  char s[MAXLINE];
  getlines(s, MAXLINE);
  ungets(s);
  while((c = getch()) != EOF)
   putchar(c);
  return 0;
}
int getlines(char s[], int maxline)
{
  int c, i;
  for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  if (c == '\n')
   s[i++] = c;
  s[i] = '\0';
}
void ungets(char s[])
{
  int i;
  i = strlen(s);
  while (i > 0)
  ungetch (s[--i]);
}
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
      printf ("ungetch : too many characters\n");
  else
      buf[bufp++] = c;
}
