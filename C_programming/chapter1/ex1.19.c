#include<stdio.h>
#define MAXLINE 1000
int getlines(char line[],int lim);
void reverse(char rline[]);
int main()
{
  int len;
  char line[MAXLINE];
   while((len=getlines(line,MAXLINE))>0)
     {
       reverse(line);
       printf("%s",line);
     }
  return 0;
}
  int getlines(char s[],int lim)
  {
  int i,c;
   for(i=0;i<lim-1 &&(c=getchar())!=EOF && c != '\n';i++)
    {
     s[i] = c;
    }
   if( c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}
void reverse(char rline[])
{
  int i,j;
  char r;
  for(i=0;rline[i]!='\0';i++)
    ;
   --i;
  if(rline[i]=='\n')
   --i;
  j = 0;
  while(j < i)
  {
    r = rline[j];
    rline[j] = rline[i];
    rline[i] = r;
    --i;
    ++j;
  }
}
