#include<stdio.h>
void expand(char s1[],char s2[]);
main()
{
  int i=0;
  char s1[100],s2[100],c;
  printf("\n enter the text");
  while((c=getchar())!=EOF)
    {
      s1[i++]=c;
    }
  s1[i]='\0';
  printf("\n result \n");
  expand(s1,s2);
  printf("%s\n",s2);

}
void expand(char s1[],char s2[])
{
  char c;
  int i=0,j=0;
  while((c=s1[i++])!='\0')
    {
      if(s1[i]=='-'&&s1[i+1]>=c)
	{
	  i++;
	  while(c<s1[i])
	    {
	      s2[j++]=c++;
	    }
	}
      else
	{
	  s2[j++]=c;
	}
    }
    s2[j]='\0';
}
