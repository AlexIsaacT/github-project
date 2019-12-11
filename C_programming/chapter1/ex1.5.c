#include<stdio.h>
int main()
{
int celsius;
for(celsius=300;celsius>=0;celsius=celsius-20)
printf("%5d\t%5d\n",celsius,(9*celsius+160)/5);
return 0;
}
