#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
        int c;
        while ((c = getchar()) != EOF)
        {
                if (argc != 2)
                        putchar(c);
                else if (strcmp (argv[1], "upper") == 0)
                        putchar(toupper(c));
                else if (strcmp (argv[1], "lower") == 0)
                        putchar(tolower(c));
        }
        return 0;
}
