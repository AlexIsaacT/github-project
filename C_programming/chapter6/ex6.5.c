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

int main()
{
        struct nlist *table[3] = {
                (install("key1", "defn")),
                (install("key2", "defn")),
                (install("key3", "defn"))
        };
        char *keys[4] = {
                "key1",
                "key2",
                "key3",
        };

        undef("key2");

        struct nlist *np;
        int i;

        for (i = 0; i < 3; i++)
        {
                if ((np = lookup(keys[i])) == NULL)
                        printf ("%s not found\n", keys[i]);
                else
                        printf ("%s : %s\n", np->name, np->defn);
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
