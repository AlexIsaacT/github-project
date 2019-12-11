#include<stdio.h>
#include<ctype.h>
int getch(void);
void ungetch(int c);
#define SIZE 100
int n;
int main()
{
  float array[SIZE], getfloat(float *);
  for (n = 0; n < SIZE; n++)
    array[n] = 0;
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    printf ("%0.5f\n",array[n]);
return 0;
}
float getfloat(float *pn)
{
  int c, sign;
  float power;
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
      ungetch(c);
      return 0;
    }
    if (c == '.')
      c = getch();
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for ( *pn = 0.0; isdigit(c); c = getch())
     *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
      c = getch();
   for (power = 1.0; isdigit(c); c = getch())
    {
     *pn = 10.0 * *pn + (c - '0');
     power *= 10.0;
   }
  *pn *= sign / power;
  if (c != EOF)
  ungetch(c);
  return c;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
      printf ("ungetch: too many characters\n");
   else
      buf[bufp++] = c;
}
