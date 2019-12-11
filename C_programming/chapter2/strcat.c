#include<stdio.h>
#define MAX 100
int getlines(char line[], int max);
void strcats(char s[], char t[]);
int main()
{
  char s[MAX], t[MAX];
  getlines(s, MAX);
  getlines(t, MAX);
  strcats(s, t);
  printf ("%s", s);
  return 0;
}
int getlines(char line[], int lim)
{
 int i, c;
 for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
  line[i] = c;
  if (c == '\n')
   {
     line[i] = c;
     i++;
   }
   line[i] = '\0';
}
void strcats(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (s[i] != '\n')
  i++;
  while ((s[i++] = t[j++]) != '\0')
  ;
}
