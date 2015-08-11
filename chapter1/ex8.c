#include<stdio.h>
//a program to count blanks, tabs, and newlines.
main()
{
	int blank=0,tab=0,newline=0,c;
	printf("\n enter the input");
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
		{
			++newline;
		}
		else if(c=='\t')
		{
			++tab;
		}
		else if(c==' ')
		{
			++blank;
		}
	}
	printf("\n number of blanks = %d",blank);
	printf("\n number of tabs = %d",tab);
	printf("\n number of newlines = %d\n",newline);
}
