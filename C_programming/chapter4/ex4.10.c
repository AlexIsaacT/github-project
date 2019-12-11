#include<stdio.h>
#include<stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char s[]);
void push(double);
double pop(void);
int main()
{
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
      case NUMBER:
            push (atof(s));
            break;
      case '+':
            push (pop() + pop());
            break;
      case '*':
            push(pop() * pop());
            break;
      case '-':
            op2 = pop();
            push (pop() - op2);
            break;
      case '/':
            op2 = pop();
            if (op2 != 0.0)
            push (pop() / op2);
            else
            printf ("error : zero divisor\n");
            break;
      case '\n':
           printf ("\t%.8g\n", pop());
           break;
      default :
           printf ("error : unknown command %s\n", s);
           break;
        }
    }
    return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
  if (sp < MAXVAL)
     val[sp++] = f;
  else
    printf ("error : stack full, can't push %g\n", f);
}
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf ("error : stack empty");
    return 0.0;
  }
}
#include<ctype.h>
#define MAXLINE 100
int j = 0;
int getlines(char g[], int max);
char g[MAXLINE];
int getop(char s[])
{
  int i, c;
 if (g[j] == '\0')
    if (getlines(g, MAXLINE) == 0)
     return EOF;
    else
      j = 0;
  while ((s[0] = c = g[j++]) == ' ' || c == '\t')
   ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
   return c;
   i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = g[j++]))
       ;
  if (c == '.')
    while (isdigit(s[++i] = c = g[j++]))
      ;
  s[i] = '\0';
  j--;
  return NUMBER;
}
int getlines(char g[], int max)
 {
   int c, i;
   for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
    g[i] = c;
   if (c == '\n')
    g[i++] = c;
   g[i] = '\0';
   return i;
 }
