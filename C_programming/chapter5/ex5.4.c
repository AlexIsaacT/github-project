#include<stdio.h>
#include<string.h>
int getlines(char []);
int strend(char *s, char *t);
int main()
{
  char s[100], t[100];
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  printf ("%d\n", strend(s, t));
  return 0;
}
int strend(char *s, char *t)
{
  int i;
  int l = strlen(t);
  while (*s != '\0')
     s++;
  while (*t != '\0')
     t++;
  s--;
  t--;
   while (l > 0)
   {
    if (*s == *t)
     {
       s--;
       t--;
       l--;
     }
    else
       return 0;
     }
   return 1;
  }
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
