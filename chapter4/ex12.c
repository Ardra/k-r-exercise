#include<stdio.h>
#include<math.h>
void itoa(int n, char s[]);
void main(void) 
{
  char str[100];
  int num;
  printf("\n enter the integer");
  scanf("%d",&num);
  printf("number %d\n", num);
  itoa(num,str);
  printf(" %s\n",str);
 
}
/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[])
{
 static int i;
 if(n / 10)
  itoa(n /10, s);
 else{
  i = 0;
  if(n < 0)
   s[i++] = '-';
 }
 s[i++] = abs(n) %10 + '0';
 s[i] = '\0';
}
