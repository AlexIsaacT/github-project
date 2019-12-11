#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void filecmp(char *line1, char *line2, int lineno);
int main(int argc, char *argv[])
{
        FILE *fp1, *fp2;
        char line1[MAXLINE], line2[MAXLINE];
        int i = 1;
        if (argc != 3)
        {
                printf ("Input two files\n");
                exit(1);
        }
        else
        {
                if ((fp1 = fopen(argv[1], "r")) == NULL)
                {
                        fprintf (stderr, "can't open %s\n", *argv);
                        exit(2);
                }
                if ((fp2 = fopen(argv[2], "r")) == NULL)
                {
                        fprintf (stderr, "can't open %s\n", *argv);
                        exit(2);
                }
                else
                        while ((fgets(line1, MAXLINE, fp1) != NULL) && (fgets(line2, MAXLINE, fp2) != NULL))
                        {
                                filecmp(line1, line2, i);
                                i++;
                        }
                fclose(fp1);
                fclose(fp2);
        }
        return 0;
}

void filecmp(char *line1, char *line2, int lineno)
{
        if (strcmp(line1, line2) != 0)
                printf( "%d %s", lineno, line1);
}
