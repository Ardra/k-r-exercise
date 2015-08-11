#include<stdio.h>
#define MAXLINE 1000
int getline(char s[],int lim);
int strindex(char s[],char t[]);
char pattern[]="ould";
main()
{
	int found=0;
	char line[MAXLINE];
	while(getline(line,MAXLINE)>0)
	{
		if(strindex(line,pattern)>=0)
		{
			printf("%s",patten);
			++found;
		}
	}
	return found;
}
int getline(char s[],int lim)
{
	int c,i;
	i=0;
	while(--lim>0&&(c=getchar())!='\0'&&c!='\n')
	{
		s[i++]=c;
	}
	if(c=='\n')
	{	
		s[i++]=c;
	}
	s[i]=\0';
}
int strindex(char s[],char t[])
{
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++);
		if(k>0&&t[k]=='\0')
		{
			return i;
		}
	}
	return -1;
}

		