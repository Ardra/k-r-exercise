#include<stdio.h>
main()
{
	int c,no_char[10],nc=0,i=0,j=0,k=0;
	printf("\n enter the input(max 10 words) \n");
	while((c=getchar())!=EOF)
	{
		if(c==' '||c=='\n'||c=='\t')
		{
			no_char[i]=nc;
			nc=0;
			i=i+1;
		}
		else
		{
			++nc;
		}
	}
	no_char[i]=nc;//get the no of characters in last word
	printf("\n");
	for(j=0;j<=i;j++)
	{
		printf("%d ",no_char[j]);
	}
	printf("\n histogram of character count of words\n");
	for(j=0;j<=i;j++)
	{
		printf("|%d|",j);
		for(k=0;k<=no_char[j];k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
	
