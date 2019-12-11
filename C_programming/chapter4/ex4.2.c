#include<stdio.h>
#include<ctype.h>
#define MAX 100
double atof (char s[]);
int getlines(char s[], int max);
int main()
{
  char s[MAX];
  getlines(s, MAX);
  printf ("%f\n", atof(s));
  return 0;
 }
 int getlines(char s[], int lim)
 {
   int c, i;
   for (i = 0; i <= MAX; i++)
   s[i] = 0;
   i = 0;
   while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
   s[i++] = c;
   if (c == '\n')
    s[i++] = c;
   s[i] = '\0';
   return i;
 }
 double atof(char s[])
 {
   double val, val2, power, power2;
   int i, sign, sign2;
     for (i = 0; isspace(s[i]); i++)
        ;
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
        i++;
   for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
        i++;
   for (power = 1.0; isdigit(s[i]); i++)
      {
       val = 10 * val + (s[i] - '0');
       power *= 10.0;
      }
   if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign2 = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
        i++;
   for (val2 = 0; isdigit(s[i]); i++)
        val2 = 10 * val2 + (s[i] -'0');
   for (power2 = 1.0; val2 > 0; val2--)
        power2 = power2 * 10;
   if (sign2 == -1)
      return sign * val /(power * power2);
   else
      return (sign * val / power) * power2;
  }
