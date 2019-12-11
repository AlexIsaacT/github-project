#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NUMBER '0'
void push(double);
double pop(void);
int main(int argc, char *argv[])
{
  int type, c;
  double op2;
   while (--argc > 0)
    {
      if (!isdigit(c = **++argv) && strlen(*argv) == 1)
        type = c;
      else
        type = NUMBER;
      switch (type)
      {
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case 'p':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
       default:
            printf("error: unknown command\n");
        break;
        }
    }
    printf("= %g\n", pop());
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
    printf("error: stack full, can't push %g\n", f);
}
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
    }
}
