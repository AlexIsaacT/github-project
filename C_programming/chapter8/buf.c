#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

/*#ifdef NULL
#undef NULL
#endif

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20*/

typedef struct _iobuf {
        int cnt;
        char *ptr;
        char *base;
        int flag;
        int fd;
} FILEx;

extern FILEx _iob[OPEN_MAX];
/*
#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])
*/
enum _flags {
        _READ = 01,
        _WRITE = 02,
        _UNBUF = 03,
        _EOF = 010,
        _ERR = 020,
};

int _fillbufx(FILEx *);
#define getcx(p) (--(p)->cnt >= 0? (unsigned char) *(p)->ptr++:_fillbufx(p))

/*#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
                 ? (unsigned char) *(p)->ptr ++ : _fillbuf(p))

#define putc(x, p) (--(p)->cnt >= 0 \
                    ? *(p)->ptr ++ = (x) : _flushbuf((x), p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)

#define PERMS 0666*/


FILEx *fopenx(char *name, char *mode)
{
        int fd;
        FILE *fp;

        if (*mode != 'r' && *mode != 'w' && *mode != 'a')
                return NULL;
        for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
                if((fp->flag & (_READ | _WRITE)) == 0)
                        break;
        if (fp >= _iob + OPEN_MAX)
                return NULL;

        if (*mode == 'w')
                fd = creat(name, PERMS);
        else if (*mode == 'a')
        {
                if ((fd = open(name, O_WRONLY, 0)) == -1)
                        fd = creat(name, PERMS);
                lseek(fd, 0L, 2);
        }
        else
                fd = open(name, O_RDONLY, 0);
        if (fd == -1)
                return NULL;
        fp->fd = fd;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag = (*mode == 'r') ? _READ : _WRITE;
        return fp;
}

FILEx _iob[OPEN_MAX] = {
        { 0, (char *) 0, (char *) 0, _READ, 0 },
        { 0, (char *) 0, (char *) 0, _WRITE, 1 },
        { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

int _fillbufx(FILE *fp)
{
        int bufsize;

        if ((fp->flag&(_READ | _EOF | _ERR)) != _READ)
                return EOF;
        bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
        if (fp->base == NULL)
                if ((fp->base = (char *) malloc(bufsize)) == NULL)
                        return EOF;
        fp->ptr = fp->base;
        fp->cnt = read(fp->fd, fp->ptr, bufsize);
        if (--fp->cnt < 0)
        {
                if (fp->cnt == -1)
                        fp->flag |= _EOF;
                else
                        fp->flag |= _ERR;
                fp->cnt = 0;
                return EOF;
        }
        return (unsigned char) *fp->ptr++;
}


int main()
{
        FILEx *fp = fopenx("test.c", "r");
        if(fp != NULL) {
                char c;
                while ((c = getcx(fp)) !=EOF)
                        putchar(c);
        }
        else
                puts("Error");
        return 0;
}
