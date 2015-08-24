#include<stdio.h>
int strlen(char *s);
int strcmp(char *s,char *t);
int strend(char *s,char *t);
main()
{
  char s[100],t[100];
  int result;
  printf("\n enter s");
  scanf("%s",s);
  printf("\n enter t");
  scanf("%s",t);
  result=strend(s,t);
  if(result==1)
    {
      printf("\n string t occurs at end of s\n");
    }
  else
    {
      printf("\n string t not occurs at end of s\n");
    }
}
int strlen(char *s)
{
  int i=0;
  while(*s!='\0'){
    i++;
    s++;
  }
  return i;
}
int strcmp(char *s,char *t)
{
  for(;*s==*t;s++,t++)
    if(*s=='\0')
      return 0;
  return *s-*t;
}
int strend(char *s,char *t)
{
  int result=0,slen=0,tlen=0;
  slen=strlen(s);
  tlen=strlen(t);
  if(tlen<=slen){
    s+=slen-tlen;
    if(0==strcmp(s,t))
      result=1;
  }
  return result;
}
