#include<stdio.h>
int main()
{
  int c,nl,nt,ns;
  nt=0;
  ns=0;
  nl=0;
  while(
    (c=getchar()) != EOF

  )
  {
  if(c=='\t')
  nt++;
  else if(c=='\n')
  nl++;
  else if(c==' ')
  ns++;
}
  printf("Tabs=%d\t,New line=%d\t,Blanks=%d\n",nt,nl,ns);
  return 0;
}
