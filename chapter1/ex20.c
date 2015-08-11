#include<stdio.h>
#define SPACE 4
main()
{
	int c,tab_no=1,i;
	while((c=getchar())!=EOF)
	{
		if(c=='\t')
		{
			while((c=getchar())!=EOF&&c=='\t')//1 tab replaced by 4 spaces 
			{
				++tab_no;
			}
			for(i=0;i<tab_no*SPACE;++i)
			{
				putchar('a');
			}
			tab_no=1;
		}
		else if(c==EOF)
		{
			break;
		}
		putchar(c);
		
	}
printf("\n");
}
