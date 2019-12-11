#include<stdio.h>
#define MAX 1000
#define IN 1
#define OUT 0
int main()
{
  int cc, pc = 0,state = OUT, i, s;
  char a[MAX];
  while ((cc = getchar()) != EOF)
  {
    if (pc == '/' && cc == '*')
    {
    state = IN;
    a[0] = pc;
    for (i = 1; state == IN; i++)
    {
    a[i] = cc;
    if (pc == '*' && cc == '/')
    {
    state = OUT;
    for (i = 0; i < MAX ;i++)
     a[i] = 0;
   }
    pc = cc;
    cc = getchar();
  }
}
  else
  {
    putchar(cc);
  }
  pc = cc;
}
printf ("%s", a);
}
