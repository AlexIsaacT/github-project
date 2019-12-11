#include <stdio.h>
#define TABS 8
int main()
{
        int nb = 0,nt = 0, p, c;
        for(p = 1; (c = getchar()) != EOF; p++)
        {
                if( c == ' ')
                {
                        if((p % TABS) != 0)
                                ++nb;
                        else
                        {
                                nb = 0;
                                ++nt;
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
                                p = p + ( TABS - (p -1) % TABS) - 1;
                }
        }
        return 0;
}
