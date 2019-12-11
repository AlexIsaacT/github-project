#include <stdio.h>
#define MAXLINE 1000
int getlines(char s[], int max);
int main()
{
int len, i;
char line[MAXLINE];
 while ((len = getlines(line, MAXLINE)) != 0)
        {
        if (len > 1)
           {
            for (i = len-1; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'); i--)
                ;
            line[++i] = '\0';
            printf("%s\n", line);
           }
         }
     return 0;
}
int getlines(char s[], int max)
   {
    int i, c;
    for (i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; i++)
      {
        s[i] = c;
      }
    if (c == '\n')
      {
        s[i] = c;
        i++;
      }
    s[i] = '\0';
    return i;
}
