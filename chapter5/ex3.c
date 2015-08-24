#include<stdio.h>
void str_cat(char *s,char *t);
main()
{
  char s[100],t[100];
  printf("\n enter s");
  scanf("%s",s);
  printf("\n enter t");
  scanf("%s",t);
  str_cat(s,t);
  printf("\n string after concatenation\n");
  printf("%s\n",s);
}
void str_cat(char *s,char *t)
{
  while(*s!='\0')
    s++;
  while((*s++=*t++)!='\0')
    ;
}
