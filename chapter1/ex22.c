#include<stdio.h>
int str_length(char str[]);
main()
{
	int count=0,i,length;
	char str[100],c;
	while((c=getchar())!=EOF&&(++count)>0)
	{
							
		if(c!=' '&&c!='\t'&&c!='\n')
		{
			i=0;
			str[i]=c;
			++i;
			while((c=getchar())!=EOF&&c!=' '&&c!='\n'&&c!='\t')
			{
				str[i]=c;
				++i;
				++count;
			}
			str[i]='\0';	
			length=str_length(str);
			if(count+length<80)
			{
				printf("%s",str);
			}
			else if(count+length>80)
			{
				printf("\n%s",str);
				count=0;
			}
		
		}
		else if(c==' '||c=='\t')
		{
			putchar(c);
			++count;
		}
		putchar(c);
		++count;
	}
}

int str_length(char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
		++i;
	}
	return i;
}			

