#include<stdio.h>
#include<string.h>
void reverse(char str[],int i,int len);
main()
{
  char str[100];
  printf("\n enter the string");
  scanf("%s",str);
  printf("\n string after reversing");
  reverse(str,0,strlen(str));
  printf("\n %s\n",str);

}
void reverse(char str[],int i,int len)
{
  int j;
  char c;
  j=len-(i+1);
  if(i<j){
    c=str[i];
    str[i]=str[j];
    str[j]=c;
    reverse(str,++i,len);
  }
}
