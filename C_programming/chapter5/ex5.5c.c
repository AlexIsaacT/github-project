#include<stdio.h>
int getlines(char []);
int strncmpp(char *s, char *t, int n);
int main()
{
  char s[100], t[100];
  int n;
  printf ("Enter the array s : ");
  getlines(s);
  printf ("Enter the array t : ");
  getlines(t);
  printf ("Enter n : ");
  scanf ("%d", &n);
  printf ("%d\n", strncmpp(s, t, n));
  return 0;
}
int strncmpp(char *s, char *t, int n)
{
  while (n > 0 && *s == *t && *s != '\0') {
		s++;
		t++;
		n--;
	}
	if (n == 0 || *s == *t)
		return 0;
	return *s - *t;
 }
int getlines(char s[])
{
  int c, i;
  for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; i++)
   s[i] = c;
  s[i] = '\0';
}
