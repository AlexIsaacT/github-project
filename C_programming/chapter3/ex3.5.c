#include<stdio.h>
#define MAX 100
void itob (int n, char s[], int b);
void reverse(char s[]);
int main()
{
  int n, b;
  char s[MAX];
  printf ("Enter the integer : ");
  scanf ("%d", &n);
  printf ("Enter the base : ");
  scanf ("%d", &b);
  itob(n, s, b);
  printf ("result = %s\n", s);
  return 0;
}
void itob(int n, char s[], int b)
{
  int i, sign, c;
  char t[20];
  c = 'A';
  for (i = 10; i < 16; i++)
  t[i] = c++;
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  i = 0;
  if ((sign = n) < 0)
    n = -n;
  do {
    if ((n % b) < 10)
     s[i++] = (n % b) + '0';
    else
      s[i++] = t[n % b];
  } while((n /= b) > 0);
if (sign < 0)
      s[i++] = '-';
s[i] = '\0';
reverse(s);
}
void reverse(char s[])
{
  int i, j, temp;
for (i = 0; s[i] != '\0'; i++)
;
i--;
for (j = 0; j < i; j++, i--)
{
temp = s[j];
s[j] = s[i];
s[i] = temp;
}
}
