#include<stdio.h>
int lower(int c);
int main()
{
  int c;
  c = getchar();
  printf ("%c\n", lower(c));
  return 0;
}
int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
   return c + 'a' - 'A';
   else
   return c;
}
