#include<stdio.h>
#define MAXLINE 1000
int get_line(char line[],int maxline);
void copy(char to[],char from[]);

main()
{
	char line[MAXLINE],longest[MAXLINE];
	int len,max=0,i=0,c;
	while((len=get_line(line,MAXLINE))>0)
	{
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	}
	if(max>0)
	{
		printf("\n LONGEST LINE:\n");
		printf("%s",longest);
		while(longest[i]!='\0')
		{
			++i;
		}
		if(longest[i]=='\n'||longest[i]==EOF)
		{
			printf("\n length of longest line %d\n",i-2);
		}
		else//longest line greater than 1000 characters
		{
			printf("\n length of longest line %d\n",i-1);
		}
			
		
	}
	return 0;
}
void copy(char to[],char from[])
{
	int i=0;
	while((to[i]=from[i])!='\0')
		++i;
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
		
