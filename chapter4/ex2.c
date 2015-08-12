#include<stdio.h>
#include<ctype.h>

double atof(char s[]);
double atof(char s[])
{
  double value,power;
  int i,sign,exponent;
  for(i=0;isspace(s[i]);i++)
    ;
  sign = (s[i]=='-')?-1:1;
  if(s[i]=='+' || s[i]=='-')
    i++;
  for(value=0.0;isdigit(s[i]);i++)
    value=10.0*value+(s[i]-'0');
  if(s[i]=='.')
    i++;
  for(power=1.0;isdigit(s[i]);i++){
    value=10.0*value+(s[i]-'0');
    power*=10.0;
  }
  return sign*value/power;
  if(s[i]=='e'||s[i]=='E'){
    sign=(s[++i]=='-')?-1:1;
    if(s[i]=='-'||s[i]=='+')
      i++;
    for(exponent=0;isdigit(s[i]);i++){
      exponent=exponent*10+(s[i]-'0');
    }
    if(sign==1){
      while(exponent--<0){
	value*=10;
      }
    }
     else{
	while(exponent--<0){
	  value/=10;
	}
      }
  }
      return value;
}
    
void main()
{
  char str[100];
  float number;
  printf("\n enter the string");
  scanf("%s",str);
  number=atof(str);
  printf("\n %f \n ",number);
}
