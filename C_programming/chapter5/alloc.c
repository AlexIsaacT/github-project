#include<stdio.h>
#define ALLOCSIZE 10000
char *alloc(int n);
void afree(char *);
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
int main()
{
  
}
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
void afree(char *p)
{
   if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
     allocp = p;
}
