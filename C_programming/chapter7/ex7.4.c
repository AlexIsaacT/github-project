#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
        int c;
        unsigned a;
        minscanf ("%u", &a);
        printf ("%u\n", a);
        return 0;
}

void minscanf(char *fmt, ...)
{
        va_list ap;
        char *p;
        unsigned *uval;
        int *ival;
        float *dval;

        va_start(ap, fmt);
        for (p = fmt; *p; p++)
        {
                if (*p != '%')
                {
                        putchar(*p);
                        continue;
                }
                switch (*++p)
                {
                case 'd':
                        ival = va_arg(ap, int *);
                        scanf ("%d", ival);
                        break;
                case 'f':
                        dval = va_arg(ap, float *);
                        scanf ("%f", dval);
                        break;
                case 'u':
                        uval = va_arg(ap, unsigned *);
                        scanf ("%u", uval);
                        break;
                default:
                        putchar(*p);
                        break;
                }
        }
        va_end(ap);
}
