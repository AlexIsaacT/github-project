#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int getlines(char line[], int max);
int main(int argc, char *argv[])
{
        FILE *fp;
        char line[MAXLINE];
        long lineno = 0;
        char *p, *prog;
        int c, except = 0, number = 0, found = 0;
        while (--argc > 0 && (*++argv)[0] == '-')
                while (c = *++argv[0])
                        switch(c)
                        {
                        case 'x':
                                except = 1;
                                break;
                        case 'n':
                                number = 1;
                                break;
                        default:
                                printf ("find : Illegal option %c\n", c);
                                argc = 0;
                                found = -1;
                                break;
                        }
        if (argc == 1)
                while (getlines(line, MAXLINE) > 0)
                {
                        lineno++;
                        if ((strstr(line, *argv) != NULL) != except)
                        {
                                if (number)
                                        printf ("%ld:", lineno);
                                printf ("%s", line);
                                found++;
                        }
                }
        else if (argc < 1)
                printf ("Usage: find -n -x pattern\n");
        else
        {
                p = *argv;
                while (--argc != 0)
                {
                        prog = *++argv;
                        if ((fp = fopen(*argv, "r")) == NULL)
                        {
                                fprintf(stderr, "%s: cant open %s\n", prog, *argv);
                                exit(1);
                        }
                        else
                        {
                                while (fgets(line, MAXLINE, fp) != NULL)
                                {
                                        lineno++;
                                        if ((strstr(line, p) != NULL) != except)
                                        {
                                                if (number)
                                                        printf ("%ld:", lineno);
                                                printf ("%s ", *argv);
                                                printf ("%s", line);
                                                found++;
                                        }
                                }
                                lineno = 0;
                        }
                }
        }
        return found;
}
int getlines(char line[], int max)
{
        int c, i;
        for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
                line[i] = c;
        if (c == '\n')
                line[i++] = c;
        line[i] = '\0';
        return i;
}
