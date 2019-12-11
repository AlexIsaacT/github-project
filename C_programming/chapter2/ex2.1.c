#include <stdio.h>
#include <limits.h>
int main ()
{
 printf("Range of Char %d\n", CHAR_BIT);
 printf("Range of Char Max %d\n", CHAR_MAX);
 printf("Range of Char Min %d\n", CHAR_MIN);
 printf("Range of int min %d\n", INT_MIN);
 printf("Range of int max %d\n", INT_MAX);
 printf("Range of long min %ld\n", LONG_MIN);
 printf("Range of long max %ld\n", LONG_MAX);
 printf("Range of short min %d\n", SHRT_MIN);
 printf("Range of short max %d\n", SHRT_MAX);
 printf("Range of unsigned char %u\n", UCHAR_MAX);
 printf("Range of unsigned long %lu\n", ULONG_MAX);
 printf("Range of unsigned int %u\n", UINT_MAX);
 printf("Range of unsigned short %u\n", USHRT_MAX);
 return 0;
}
