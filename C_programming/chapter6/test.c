#include <stdio.h>
#define HASHSIZE 101
unsigned hash(char *);
int main()
{
        int c, i;
        char s[100];

        for (i = 0; (c = getchar()) != '\n'; i++)
                s[i] = c;
        s[i] = '\0';
        printf ("%d\n", hash(s));
        return 0;
}
unsigned hash(char *s)
{
        unsigned hashval;

        for (hashval = 0; *s != '\0'; s++)
                hashval = *s + 31 * hashval;
        printf ("%d\n", hashval);
        return hashval % HASHSIZE;
}
