#include <stdio.h>

#define MAX 20
#define LINE_COUNTER_BUF_LEN 20

int main()
{

  static char line_buf[LINE_COUNTER_BUF_LEN] =
  {
          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
          ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0',
          '\t', '\0'
  };
 printf ("%s\n", line_buf + LINE_COUNTER_BUF_LEN - 3);

        return 0;
}
