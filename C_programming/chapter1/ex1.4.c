#include<stdio.h>
int main()
{
  int fahr,celsius;
  int lower,upper,step;
  lower=0;
  upper=300;
  step=20;
  celsius=lower;
  while(celsius<=upper)
  {
    fahr=(9*celsius+160)/5;
    printf("%3d%6d\n",celsius,fahr);
    celsius=celsius+step;
  }
  return 0;
}
