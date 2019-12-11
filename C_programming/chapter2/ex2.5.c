#include<stdio.h>
#define MAX 100
int getlines(char line[], int max);
int location(char s1[], char s2[]);
int main()
{
  char s1[MAX], s2[MAX];
  int loc;
  getlines (s1, MAX);
  getlines (s2, MAX);
  loc = location(s1, s2);
  printf ("%d\n", loc);
  return 0;
}
int getlines(char line[], int lim)
{
  int c, i;
  for (i = 0; i < MAX; i++)
  line[i] = 0;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
  line[i] = c;
  if (c == '\n')
  {
  line[i] = '\0';
}
}
int location(char s1[], char s2[])
{
  int i = 0, j, count = 0;
  while (s1[i] != '\0')
  {
    for (j = 0; s2[j] != '\0'; j++)
     {
       if (s1[i] == s2[j])
       count++;
     }
     if (count != 0)
     {
     return i+1;
     break;
   }
   count = 0;
   i++;
}
if (count == 0)
return -1;
}
