#include<stdio.h>
int any(char str1[],char str[2]);
main()
{
	char str1[100],str2[100];
	printf("\n enter the first string");
	scanf("%s",&str1);
	printf("\n enter the second string");
	scanf("%s",&str2);
	printf("\n resulting position  : %d\n",any(str1,str2));
}
int any(char str1[],char str2[])
{	
	int i,j,k,pos=99;
	for(i=0;str2[i]!='\0';i++)
	{
		for(j=k=0;str1[k]!='\0';k++)
		{
			if(str1[k]==str2[i])
			{
				if(k<pos)
				{
					pos=k;
				}
			}
		}
	}
	if(pos==99)
	{
		return -1;
	}
	else
	{
		return pos+1;
	}	
}
