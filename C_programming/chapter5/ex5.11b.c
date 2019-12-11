#include <stdio.h>
#include <stdlib.h>
#define DEFAULTTAB 8
int main(int argc, char **argv)
{
        int nb = 0,nt = 0, p, c, d, tabstop;
        if (--argc > 0)
        {
                d = atoi(argv[1]);
                tabstop = d;
        }
        else
                tabstop = DEFAULTTAB;
        for(p = 1; (c = getchar()) != EOF; p++)
        {
                if( c == ' ')
                {
                        if((p % tabstop) != 0)
                                nb++;
                        else
                        {
                                nb = 0;
                                nt++;
                        }
                }
                else
                {
                        while (nt > 0)
                        {
                                putchar('\t');
                                nt--;
                        }
                        if( c == '\t')
                                nb = 0;
                        else
                                while (nb > 0)
                                {
                                        putchar(' ');
                                        nb--;
                                }
                        putchar(c);
                        if(c == '\n')
                                p = 0;
                        else if ( c == '\t')
                                p = p + ( tabstop - (p -1) % tabstop) - 1;
                }
        }
        return 0;
}
