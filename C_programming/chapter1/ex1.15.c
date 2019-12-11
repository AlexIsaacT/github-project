#include<stdio.h>
int celsius(int fahr);
int main()
{
int fahr;
for(fahr=0;fahr<=300;fahr=fahr+20)
printf("%d\t%d\n",fahr,celsius(fahr));
return 0;
}
int celsius(int fahr)
{
  int i,p;
  for(i=0;i<=300;i=i+20)
  p=5*(fahr-32)/9;
  return p;
}
