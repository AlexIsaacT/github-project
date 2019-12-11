#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main()
{
        char c = 'a';
        unsigned t = 40;
        char *a = "Hello_world";
        minprintf("%u\n", t);
        return 0;
}

void minprintf(char *fmt, ...)
{
        va_list ap;
        char *p, *sval;
        char cval;
        unsigned uval;
        int ival;
        double dval;

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
                        ival = va_arg(ap, int);
                        printf ("%d", ival);
                        break;
                case 'f':
                        dval = va_arg(ap, double);
                        printf ("%f", dval);
                        break;
                case 's':
                        for (sval = va_arg(ap, char *); *sval; sval++)
                                putchar(*sval);
                        break;
                case 'c':
                        cval = va_arg(ap, int);
                        printf ("%c", cval);
                        break;
                case 'u':
                        uval = va_arg(ap, unsigned);
                        printf ("%u", uval);
                        break;
                default:
                        putchar(*p);
                        break;
                }
        }
        va_end(ap);
}
