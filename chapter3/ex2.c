#include<stdio.h>
void escape(char s[],char t[]);
main()
{
  int i=0;
  char c;
  char s[100],t[100];
  printf("\n enter the text");
  while((c=getchar())!=EOF)
    {
      t[i++]=c;
    }
  t[i]='\0';
  escape(s,t);
  printf("\n result \n");
  printf("%s \n",s);
}




void escape(char s[],char t[])
{
  int i,j;
  for(i=j=0;t[i]!='\0';i++)
    {
      switch(t[i])
	{
	case '\n':
	  s[j++]='\\';
	  s[j++]='n';
	  break;
	case '\t':
	  s[j++]='\\';
	  s[j++]='t';
	  break;
	default:
	  s[j++]=t[i];
	  break;
	}
    }
  s[j]='\0';
}
