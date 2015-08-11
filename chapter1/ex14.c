#include <stdio.h>
main()
{
	int c, i,j,k;
	int count[96];
	for (i = 0; i <= 95; ++i)
		count[i] = 0;
	while ((c = getchar()) != EOF)
	{
		for(i=32;i<127;i++)
		{
			if(c==i)
			{
				++count[i-32];
			}
		}
	}
	printf("\n HISTOGRAM OF CHARACTER FREQUENCY\n");
	for(j=0;j<95;j++)
	{
		printf("|%c|",j+32);
		for(k=0;k<count[j];k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	
		
		
	
}
