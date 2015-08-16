#include<stdio.h>
void ungets(char s[])
{
  int len=strlen(s);
  reverse(s);
  while(len>0)
    ungetch(s[--len]);
}
void reverse(char s[])
{
  int c,i,j;
  for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
      c=s[i];
      s[i]=s[j];
      s[j]=c;
    }
}
