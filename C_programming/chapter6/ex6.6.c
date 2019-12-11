#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct nlist {
        struct nlist *next;
        char *name;
        char *defn;
};

#define HASHSIZE 101
#define MAXWORD 1000
static struct nlist *hashtab[HASHSIZE];

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
unsigned hash(char *);
struct nlist *undef(char *name);
int getword(char *, int);
int getch();
void ungetch(int);

int main()
{
        char key[MAXWORD], value[MAXWORD], word[MAXWORD];
        struct nlist *result;
        while ((getword(word, MAXWORD)) != EOF)
        {
                if (strcmp(word, "#define") == 0)
                {
                        getword(key, MAXWORD);
                        getword(value, MAXWORD);
                        install(key, value);
                        result = lookup(key);
                        printf ("%s : %s\n", result->name, result->defn);
                }
        }
        return 0;
}

struct nlist *undef(char *name)
{
        struct nlist *found;
        found = lookup(name);

        if (found == NULL)
                return NULL;
        else
        {
                if (found->next != NULL)
                {
                        found->next = found->next->next;
                        found = found->next;
                }
                else
                        hashtab[hash(name)] = NULL;
        }
        return found;
}

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s)
{
        unsigned hashval;

        for (hashval = 0; *s != '\0'; s++)
                hashval = *s + 31 * hashval;
        return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
        struct nlist *np;

        for (np = hashtab[hash(s)]; np != NULL; np = np->next)
                if (strcmp(s, np->name) == 0)
                        return np;
        return NULL;
}

struct nlist *lookup(char *);
char *strdupp(char *);

struct nlist *install(char *name, char *defn)
{
        struct nlist *np;
        unsigned hashval;

        if ((np = lookup(name)) == NULL)
        {
                np = (struct nlist *) malloc(sizeof(*np));
                if (np == NULL || (np->name = strdupp(name)) == NULL)
                        return NULL;
                hashval = hash(name);
                np->next = hashtab[hashval];
                hashtab[hashval] = np;
        }
        else
                free((void *) np->defn);
        if ((np->defn = strdupp(defn)) == NULL)
                return NULL;
        return np;
}

char *strdupp(char *s)
{
        char *p;
        p = (char *) malloc(strlen(s)+1);
        if (p != NULL)
                strcpy(p, s);
        return p;
}

int getword(char *word, int lim)
{
        int c, getch(void);
        void ungetch(int);
        char *w = word;

        while (isspace(c = getch()))
                ;
        if (!isalnum(c) && c != '#')
        {
                *w++ = '\0';
                return c;
        }
        else
        {
                *w++ = c;
                while (!isspace(c = getch()))
                        *w++ = c;
                ungetch(c);
        }
        *w = '\0';
        return word[0];
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch()
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                printf ("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
