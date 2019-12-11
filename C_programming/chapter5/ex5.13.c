#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);

int main(int argc, char **argv)
{
        int nlines, n, start, i;
        if (argc == 1)
                n = 10;
        else if (argc == 2 && (*++argv)[0] == '-')
                n = atoi(argv[0] + 1);
        else
                printf ("Wrong usage\n");
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0 && nlines >= n)
        {
                start = nlines - n;
                for (i = start; i < nlines; i++)
                        printf ("%s\n", lineptr[i]);
        }
        else
                for (i = 0; i < nlines; i++)
                        printf ("%s\n", lineptr[i]);
        return 0;
}

#define MAXLEN 1000
int getlines(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
        int len, nlines;
        char *p, line[MAXLEN];
        nlines = 0;
        while ((len = getlines(line, MAXLEN)) > 0)
                if (nlines >= maxlines || (p = alloc(len)) == NULL)
                        return -1;
                else
                {
                        line[len-1] = '\0';
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        return nlines;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
        if (allocbuf + ALLOCSIZE - allocp >= n)
        {
                allocp += n;
                return allocp - n;
        }
        else
                return 0;
}

int getlines(char *s, int lim)
{
        int c;
        char *t = s;
        for (; *s < --lim && (c = getchar()) != EOF && c != '\n'; s++)
                *s = c;
        if (c == '\n')
                *s++ = c;
        *s = '\0';
        return s - t;
}
