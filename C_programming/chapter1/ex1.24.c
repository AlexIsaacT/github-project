#include<stdio.h>
#define MAX 1000
char a[MAX];
int getlines();
int main()
{
  int len = 0, i = 0;
  int brackets = 0, braces = 0, parentheses = 0,s_quote = 1, d_quote = 1;
  while ((len = getlines()) > 0)
  {
    i = 0;
    while (i < len)
    {
      if (a[i] == '{')
       braces++;
      else if (a[i] == '}')
       braces--;
      else if (a[i] == '(')
       parentheses++;
      else if (a[i] == ')')
      parentheses--;
      else if (a[i] == '[')
      brackets++;
      else if (a[i] == ']')
      brackets--;
      else if (a[i] == '\'')
      s_quote *= -1;
      else if (a[i] == '"')
      d_quote *= -1;
      i++;
      }
    }
  if (braces != 0)
  printf ("Improper use of braces\n");
  if (parentheses != 0)
  printf ("Improper use of parentheses\n");
  if (brackets != 0)
  printf ("Improper use of brackets\n");
  if (s_quote != 1)
  printf ("Improper use of single quotes\n");
  if (d_quote != 1)
  printf ("Improper use of double quotes\n");
}
int getlines()
{
  int c, i;
  extern char a[];
  for (i = 0; i < MAX-1 && (c = getchar()) != EOF && c != '\n'; ++i)
  a[i] = c;
  if (c == '\n')
  {
    a[i] = c;
    ++i;
  }
  a[i] = '\0';
  return i;
}
