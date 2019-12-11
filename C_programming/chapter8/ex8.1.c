#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1000

void error(char *, ...);
int main(int argc, char *argv[])
{
        int fd, n;
        char buf[BUFSIZE];
        if (argc == 1)
                while ((n = read(0, buf, BUFSIZE)) > 0)
                        write(1, buf, n);
        else
                while (--argc > 0)
                        if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
                        {
                                error("cat: can't open %s", *argv);
                                return 1;
                        }
                        else
                        {
                                while ((n = read(fd, buf, BUFSIZE)) > 0)
                                        if (write(1, buf, n) != n)
                                                error("cat: write error on file %s", *argv);
                                close(fd);
                        }
        return 0;
}

#include <stdarg.h>

void error(char *fmt, ...)
{
        va_list args;
        va_start(args, fmt);
        fprintf (stderr, "error: ");
        vfprintf (stderr, fmt, args);
        fprintf (stderr, "\n");
        va_end(args);
        exit(1);
}
