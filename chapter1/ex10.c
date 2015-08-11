#include<stdio.h>
//a program to count blanks, tabs, and newlines.
main()
{
	int c;
	printf("enter the input \n");
	while((c=getchar())!=EOF)
	{
		if(c=='\t')
		{
			putchar("\\");
			putchar('t');
		}
		else if(c=='\b')
		{
			putchar("\\");
			printf('b');
		}
		else if(c=='\\')
		{
			putchar("\\");
			putchar('\\');
		}
		else
		{
			putchar(c);
		}
		
	}
}
