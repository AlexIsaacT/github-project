#include<stdio.h>
int getlines(char []);
void strncatt(char *s, char *t, int n);
int main()
{
  char s[100], t[100];
  int n;
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  printf ("Enter n : ");
  scanf ("%d", &n);
  strncatt(s, t, n);
  printf ("%s\n", s);
  return 0;
}
void strncatt(char *s, char *t, int n)
{
  int i = 0;
  while (*s++ != '\0')
   ;
  s--;
  while (i < n)
    {
      *s++ = *t++;
       i++;
    }
   *s = '\0';
}
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
