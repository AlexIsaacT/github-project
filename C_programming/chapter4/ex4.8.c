#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char []);
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
int getch(void);
void ungetch(int);
int getop(char s[])
{
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
   ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
   return c;
   i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
       ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
     ungetch(c);
     return NUMBER;
}
char buf = 0;
int getch(void)
{
  int c;
  if(buf!=0)
      c = buf;
  else
      c = getchar();
      buf = 0;
  return c;
}
void ungetch(int c)
{
  if(buf != 0)
     printf("ungetch: too many characters\n");
  else
     buf = c;
}
