#include<stdio.h>
main()
{
	int c;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			putchar(c);
			while((c=getchar())!=EOF&&c==' ');
		}
		else if(c==EOF)
		{
			break;
		}
			putchar(c);
		
	}
printf("\n");
}
