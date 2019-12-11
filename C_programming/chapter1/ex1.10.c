#include<stdio.h>
int main()
{
  int c;
  while((c=getchar())!=EOF)
  {
  if(c=='\t')
  {
  putchar('\\');
  putchar('t');
}
  else if(c=='\b')
  {
  putchar('\\');
  putchar('b');
}
  else if(c=='\\')
  {
  putchar('\\');
  putchar('\\');
}
else if(c!='\t'&&c!='\b'&&c!='\\')
{
 putchar(c);
}
}
return 0;
}
