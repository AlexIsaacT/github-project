#include<stdio.h>
#define MAX 100
int escape(char s[], char t[]);
int main()
{
  int c, i;
  char t[MAX], s[MAX];
  for (i = 0; i <= MAX; i++)
  t[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  t[i] = c;
  escape(s, t);
  printf ("%s\n", s);
  return 0;
}
int escape(char s[], char t[])
{
  int i, j;
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0, j = 0; t[i] != '\0'; i++,j++)
  {
    switch(t[i])
    {
     case '\n':
      s[j] = '\\';
      s[j+1] = 'n';
      j++;
      break;
     case '\t':
      s[j] = '\\';
      s[j+1] = 't';
      j++;
      break;
     default :
      s[j] = t[i];
      break;
    }
  }
}
