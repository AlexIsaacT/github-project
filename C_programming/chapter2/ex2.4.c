#include<stdio.h>
#define MAX 100
int getlines(char line[], int max);
void squeeze(char s1[], char s2[]);
int main()
{
  char s1[MAX], s2[MAX];
  getlines (s1, MAX);
  getlines (s2, MAX);
  squeeze (s1, s2);
  printf ("%s\n", s1);
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
  line[i] = c;
  i++;
}
  line[i] == '\0';
}
void squeeze(char s1[], char s2[])
{
  int i, j, k,  count = 0;
  while (s1[i] != '\0')
  {
    for (j = 0; s2[j] != '\0'; j++)
     {
       if (s1[i] == s2[j])
       count++;
     }
     if (count != 0)
     {
       k = i;
       while (s1[k] != '\0')
       {
     s1[k] = s1[k+1];
     k++;
   }
   }
   else if(count == 0)
   i++;
   count = 0;
  }
  s1[i] = '\0';
}
