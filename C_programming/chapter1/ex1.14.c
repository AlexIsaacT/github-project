#include<stdio.h>
int main()
{
  int c,i,j,nchar[150], stars_to_print, max_star = 30, big;
  for(i=0;i<150;i++)
  nchar[i]=0;
  while((c=getchar())!=EOF)
  {
  ++nchar[c];
}
big = nchar[0];
for (i = 1; i < 150; i++)
   {
     if(nchar[i] > big)
     {
       big = nchar[i];
     }
   }
printf ("\nCharacter Occurences\n");
  for(i=0;i<150;i++)
  {
    if(nchar[i]!=0)
    {
   printf ("  ");
   putchar(i);
   printf("\t\t%d\t",nchar[i]);
 }
 stars_to_print = (max_star * nchar[i])/big;
 for (j = 0; j < stars_to_print; j++)
   {
 		printf ("*");
 	}
 if(nchar[i]!=0)
 putchar('\n');
}
return 0;
}
