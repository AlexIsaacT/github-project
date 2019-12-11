#include<stdio.h>
#define MAX 1000
void expand(char s1[], char s2[]);
int main()
{
  int c, i;
  char s1[MAX], s2[MAX];
  for (i = 0; i <= MAX; i++)
  s1[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  s1[i] = c;
  expand(s1, s2);
  printf ("%s\n", s2);
}
void expand(char s1[], char s2[])
{
  int i, j, d = 0;
  for (i = 0; i <= MAX; i++)
  s2[i] = 0;
  for (i = 0, j = 0; s1[i] != '\0'; i++, j++)
  {
   if (s1[i] == '-' && s1[i-1] < s1[i+1])
   {
    d = s1[i-1] + 1;
     for (j; d <= s1[i+1]; j++)
     {
     s2[j] = d;
     d+=1;
     }
     i++;
     j--;
  }
  else
       s2[j] = s1[i];
   }
}
