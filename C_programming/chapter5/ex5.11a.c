#include <stdio.h>
#include <stdlib.h>
#define DEFAULTTAB 8
int main(int argc, char **argv)
{
        int c, d, tabstop, n = 0, p = 1;
        if (--argc > 0)
        {
                d = atoi(argv[1]);
                tabstop = d;
        }
        else
                tabstop = DEFAULTTAB;
        while ((c = getchar()) != EOF)
        {
                if (c == '\t')
                {
                        n = tabstop - ((p - 1) % tabstop);
                        while (n > 0)
                        {
                                putchar(' ');
                                p++;
                                n--;
                        }
                }
                else if (c == '\n')
                {
                        putchar(c);
                        p = 1;
                }
                else
                {
                        putchar(c);
                        p++;
                }
        }
        return 0;
}
