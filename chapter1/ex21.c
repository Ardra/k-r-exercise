#include<stdio.h>
#define TAB 4
main()
{
	int c,space_no=1,i,no_tab=0,add_space=0;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			while((c=getchar())!=EOF&&c==' ')//1 tab replaced by 4 spaces 
			{
				++space_no;
			}
			no_tab=space_no/TAB;
			add_space=space_no%TAB;
			for(i=0;i<no_tab+add_space;++i)
			{
				putchar('a');
			}
			no_tab=1;
			add_space=0;
		}
		else if(c==EOF)
		{
			break;
		}
		putchar(c);
		
	}
printf("\n");
}
