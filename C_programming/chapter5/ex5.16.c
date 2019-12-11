#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALLOCSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];
char *alloc(int);
int fold = 0;
int dir = 0;
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int decr);
void qsorts(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);
int getlines(char *, int);
int main(int argc, char *argv[])
{
        int nlines;
        int number = 0, decr = 0, c;
        while (--argc > 0 && (*++argv)[0] == '-')
                while (c = *++argv[0])
                        switch (c)
                        {
                        case 'n':
                                number = 1;
                                break;
                        case 'r':
                                decr = 1;
                                break;
                        case 'f':
                                fold = 1;
                                break;
                        case 'd':
                                dir = 1;
                                break;
                        default:
                                printf ("Not a valid option\n");
                                break;
                        }
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
        {
                if (number)
                        qsorts((void **) lineptr, 0, nlines-1,(int (*)(void *, void *))(numcmp));
                else
                        qsorts((void **) lineptr, 0, nlines-1,(int (*)(void *, void *))(charcmp));
                writelines(lineptr, nlines, decr);
                return 0;
        }
        else
        {
                printf ("input too big to sort\n");
                return 1;
        }
}
void qsorts(void *v[], int left, int right, int (*comp)(void *, void *))
{
        int i, last;
        void swap(void *v[], int, int);
        if (left >= right)
                return;
        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
                if ((*comp)(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left, last);
        qsorts(v, left, last-1, comp);
        qsorts(v, last + 1, right, comp);
}
#include <stdlib.h>
int numcmp(char *s1, char *s2)
{
        double v1, v2;
        v1 = atof(s1);
        v2 = atof(s2);
        if (v1 < v2)
                return -1;
        else if (v1 > v2)
                return 1;
        else
                return 0;
}
void swap(void *v[], int i, int j)
{
        void *temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}
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
void writelines(char *lineptr[], int nlines, int decr)
{
        int i;
        if (decr)
                for (i = nlines - 1; i >= 0; i--)
                        printf ("%s\n", lineptr[i]);
        else
                while (nlines-- > 0)
                        printf ("%s\n", *lineptr++);
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
int charcmp(char *s, char *t)
{
        if (dir)
        {
                for (; tolower(*s) == tolower(*t) || !isalnum(*s) || !isalnum(*t); s++, t++)
                        if (*s == '\0')
                                return 0;
        }
        else
                for (; tolower(*s) == tolower(*t); s++, t++)
                        if (*s == '\0')
                                return 0;
        return tolower(*s) - tolower(*t);
}
