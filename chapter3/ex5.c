#include<stdio.h>
void reverse(char s[]);
int str_len(char s[]);
main()
{
  int n,b;
  char s[100];
  printf("\n enter the number");
  scanf("%d",&n);
  printf("\n enter the base");
  scanf("%d",&b);
  printf("\n result \n");
  printf("%s",s);
  printf("\n");
}
void itob(int n,char s[],int b)
{
  int sign,i,j,k;
  if((sign=n)<0)
    {
      sign=-1;
    }
  i=0;
  do{
    j=n%b;
    s[j++]=(j<=9)?j+'0':j+'a'-10;
      }while((n/=b)>0);
  if(sign<0)
    {
      s[j]='\0';
    }
  reverse(s);
}
void reverse(char s[])
{
  int c,i,j;
  for(i=0,j=str_len(s)-1;i<j;i++,j--)
    {
      c=s[i];
      s[i]=s[j];
      s[j]=c;
    }
}
int str_len(char s[])
{
  int i=0;
  char c;
  while((c=getchar())!='\0')
    {
      i++;
    }
  return i;
}
