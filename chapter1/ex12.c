#include<stdio.h>
main()
{
	int c;
	printf("\n enter the input \n");
	while((c=getchar())!=EOF)
	{
		if(c==' '||c=='\n'||c=='\t')
		{
			printf("\n");
		}
		else
		{
			putchar(c);
		}
	}
	printf("\n");
}
	
