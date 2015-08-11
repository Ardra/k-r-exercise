#include<stdio.h>
void squeeze(char str1[],char str[2]);
main()
{
	char str1[100],str2[100];
	printf("\n enter the first string");
	scanf("%s",&str1);
	printf("\n enter the second string");
	scanf("%s",&str2);
	squeeze(str1,str2);
	printf("\n resulting string   : %s\n",str1);
}
void squeeze(char str1[],char str2[])
{	
	int i,j,k;
	for(i=0;str2[i]!='\0';i++)
	{
		for(j=k=0;str1[k]!='\0';k++)
		{
			if(str1[k]!=str2[i])
			{
				str1[j++]=str1[k];
			}
		}
		str1[j]='\0';
	}
	
	return;
}
