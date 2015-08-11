#include<stdio.h>
void reverse(char str1[100],char str2[100]);
main()
{
	int c,i=0;
	char str1[100],str2[100];
	//printf("\n enter the string");
	
	while((c=getchar())!='\n')
	{
		str1[i]=c;
		++i;
	}
	str1[i]='\0';
	reverse(str1,str2);
	//printf("\n reverse of the string is \n");
	printf("%s",str2);
	printf("\n");

}

void reverse(char str1[100],char str2[100])
{
	
	int i=0,length,j=0,k=0;
	//printf("\n enter the string");
	//scanf("%s",str1);
	//printf("\n string is %s\n",str1);
	

	while(str1[i]!='\0')
	{
		i++;
	}
	length=i;
	--i;//last character str1[i-1]
	for(j=0;j<length;j++)
	{
		str2[k]=str1[i];
		--i;
		++k;
	}
	str2[k]='\0';
	
	
}
