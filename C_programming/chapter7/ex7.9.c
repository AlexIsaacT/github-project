#include <stdio.h>

int isupperr(int c);

int main()
{
        int c;
        c = getchar();
        if (isupperr(c))
                printf ("True\n");
        else
                printf ("False\n");
        return 0;
}

int isupperr(int c)
{
        if (c >= 'A' && c <= 'Z')
                return 1;
        else
                return 0;
}
