#include <stdio.h>
#define TABS 8
int main()
{
        int c, n = 0, p = 1;
        while ((c = getchar()) != EOF)
        {
                if (c == '\t')
                {
                        n = TABS - ((p - 1) % TABS);
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
