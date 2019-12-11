#include <stdio.h>
#include <string.h>
#define ALLOCSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];
char *alloc(int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsorts(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int getlines(char *, int);
int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;
  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    if (numeric)
      qsorts((void **) lineptr, 0, nlines-1,(int (*)(void *, void *))(numcmp));
    else
      qsorts((void **) lineptr, 0, nlines-1,(int (*)(void *, void *))(strcmp));
     writelines(lineptr, nlines);
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
#include<stdlib.h>
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
void writelines(char *lineptr[], int nlines)
{
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
