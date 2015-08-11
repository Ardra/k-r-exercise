#include<stdio.h>
#define YES 1
#define NO  0
void main()
{
	char number[10];
	printf("\n enter the hexadecimal no");
	scanf("%s",&number);
	printf("\n equivalent integer value %d\n",htoi(number));
}
	
int htoi(char s[])
{
 	int hexdigit, i=0, inhex, n;
	if(s[i]=='0')
	{
 		 ++i;
 		 if(s[i]=='x' || s[i]=='x')
		{
			 ++i;
		}

	 }
	 n=0;
	 inhex=YES;
	 for(;inhex==YES;++i)
	{
 		 if(s[i]>='0' && s[i]<='9')
  			 hexdigit=s[i]-'0';
  		else if(s[i]>='a' && s[i]<='f')
   			hexdigit=s[i]-'a'+10;
 		 else if (s[i]>='A' && s[i]<='F')
  			 hexdigit=s[i]-'A'+10;
  		else
  			inhex=NO;
 		if(inhex==YES)
  			 n=16*n+hexdigit;
	 }
 return n;
}

