#include <stdio.h>
#include <ctype.h>

int main()
{
        int c;
        while ((c = getchar()) != EOF)
        {
                if (iscntrl(c) || c == ' ')
                {
                        printf ("0%o", c);
                        if (c == '\n')
                                putchar('\n');
                }
                else
                        putchar(c);
        }
        return 0;
}
