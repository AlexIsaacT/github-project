#include<stdio.h>
int main()
{
  float fahr, celsius;
  int lower,upper,step;
  lower = 0;
  upper = 300;
  step = 20;
  printf("Table for Fahrenheit to celsius conversion\n");
  printf("Fahr\tcelsius\n");
  fahr=lower;
  while(fahr<=upper)
  {
    celsius=(5.0/9.0)*(fahr-32.0);
    printf("%4.0f\t%7.3f\n",fahr,celsius);
    fahr=fahr+step;
  }
  return 0;
}
