#include <stdio.h>

#define IN	1
#define OUT	0

int main()
 {
	int state=OUT,nc=0,nwords[10],i,c,j, big, max_star = 10, stars_to_print;

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
  printf("\nLength\tOccurences\n");

	for(i = 1;i<10;i++)
	 {
		 if(nwords[i]!=0)
		 {
		printf("%3d\t", i);
    printf("%3d\t",nwords[i]);
	}

stars_to_print = (max_star * nwords[i])/big;
for (j = 0; j < stars_to_print; j++)
  {
		printf ("*");
	}
if (nwords[i]!=0)
	printf ("\n");
}
return 0;
}
