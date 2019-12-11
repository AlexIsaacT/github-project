#include <stdio.h>

#define IN	1
#define OUT	0

int main()
 {
	int state=OUT,nc=0,nwords[10],i,c,j, big, max_star = 10, stars_to_print, s = 10;

	for(i=0;i<10;i++)
	{
		nwords[i]=0;
	}

	while((c=getchar())!=EOF)
	 {
		if(c==' '||c=='\n'||c=='\t')
		 {
			state=OUT;
			if(nc>0)
			{
		 nwords[nc]=nwords[nc]+1;
			}
			nc=0;
		}
		else if(state==OUT)
		{
			state=IN;
		}

		if(state==IN) {
			++nc;
		}

         }
     big = nwords[0];
      for (i = 1; i < 10; i++)
        {
          if(nwords[i] > big)
            {
              big = nwords[i];
            }
	       }
         printf ("\t\t");
     for (i = 0; i < 10; i++)
       {
         for (j = 1; j < 10 ; j++)
         {
           stars_to_print = (max_star * nwords[j])/big;
           if (stars_to_print/s >= 1)
           {
             if (nwords[j] != 0)
             printf ("*  ");
           }
           else
            {
              if (nwords[j] != 0)
              printf ("   ");
            }
          }
            printf ("\n\t\t");
            s = s - 1;
       }
       printf ("\nLength\t\t");
       for (i = 1; i < 10; i++)
          {
            if (nwords[i] != 0)
            printf ("%d  ", i);
          }
          printf ("\nOccurences\t");
       for (i = 1; i < 10; i++)
       {
         if (nwords[i] != 0)
         printf ("%d  ", nwords[i]);
       }
          printf ("\n");
return 0;
}
