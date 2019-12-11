#include <stdio.h>
#include <string.h>

#define MAX 100
int getlines(char *, int);

int main()
{
        char s[MAX];
        while ((getlines(s, MAX)) > 0);
         printf("%s", s);
        return 0;
}

int getlines(char *line, int max)
{
        if (fgets(line, max, stdin) == NULL)
                return 0;
        else
                return strlen(line);
}
