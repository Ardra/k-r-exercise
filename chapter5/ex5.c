char *strncat(char *s,char *t,int n)
{
  char *a;
  a=s;
  while(*a!='\0')
    ++p;
  for(;n>0&&*t!='\0';--n)
    *a++=*t++;
  *a='\0';
  return s;
}



char *strncmp(char *s,char *t,int n)
{
  for(;*s==*t;s++,t++)
    if(*s=='\0'||--n<=0)
      return 0;
  return *s-*t;
}


char *strncpy(char *s,char *t,int n)
{
  char *p;
  p=s;
  for(;n>0&&*t!='\0';--n)
    *p++=*t++;
  for(;n>0;--n)
    *p='\0';
  return s;
}
