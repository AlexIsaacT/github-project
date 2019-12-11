#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];
char store[MAXLEN];
int readlines(char *lineptr[], char *store, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
  int nlines;

  if ((nlines = readlines(lineptr, store, MAXLINES)) >= 0)
    {
      qsort (lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf ("error : input too big to sort\n");
      return 1;
    }
}

int getlines(char *, int);

int readlines(char *lineptr[],char *store,int maxlines)
{
    int len,nlines;
    char line[MAXLEN];
    char *p = store;
    char *linestop = store + MAXLEN;
    nlines = 0;
    while((len = getlines(line,MAXLEN)) > 0)
        if(nlines >= maxlines || p + len > linestop)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
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
void writelines(char *lineptr[], int nlines)
{
   while (nlines-- > 0)
      printf ("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
   int i, last;
   void swap(char *v[], int i, int j);
   if (left >= right)
      return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
       if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
   char *temp;
   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}