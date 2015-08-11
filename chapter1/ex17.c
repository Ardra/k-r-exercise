#include<stdio.h>
#define MAXLINE 1000
int get_line(char line[],int maxline);
void print(char line[]);

main()
{
	char line[MAXLINE],longest[MAXLINE];
	int len,max=80,i=0,c;
	while((len=get_line(line,MAXLINE))>0)
	{
		if(len>max)
		{
			printf("\n entered line greater than 80 characters");
			print(line);
		}
	}

	return 0;
}
void print(char line[])
{	int i=0;
	printf("\n");
	while(line[i]!='\0')
	{
		putchar(line[i]);
		++i;
	}
		
}
int get_line(char line[],int maxline)
{
	int c,i;
	for(i=0;i<maxline-1 && (c=getchar())!=EOF&&c!='\n';++i)
	{
		line[i]=c;
	}
	if(c=='\n')
	{
		line[i]=c;
		++i;
	}
	line[i]='\0';
	return i;
}
		
