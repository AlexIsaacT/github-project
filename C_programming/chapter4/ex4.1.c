#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int strrindex(char s[], char t[]);
int getlines(char s[], int max);
void reverse(char s[]);
int n;
int main()
{
  int r;
  char s[MAXLINE];
  char pattern[] = "ould";
  reverse(pattern);
  while ((n = getlines(s, MAXLINE)) > 0)
  {
    if((r = strrindex(s, pattern)) > 0)
       printf ("%d\n", r);
    else
        printf ("Pattern not found\n");
  }
 return 0;
}
int getlines(char s[], int lim)
{
  int c, i;
  for (i = 0; i <= MAXLINE; i++)
  s[i] = 0;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  s[i++] = c;
  if (c == '\n')
   s[i++] = c;
  s[i] = '\0';
  return i;
}
int strrindex(char s[], char t[])
{
  int i, j, k;
  for (i = n; i >= 0; i--)
  {
    for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j--, k++)
    ;
    if (k > 0 && t[k] == '\0')
    return j+2;
  }
  return -1;
}
void reverse(char s[])
{
  int i, j, c;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
