#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSPACE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int maxlines,char *ls);
int get_line(char s[],int);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);

main()
{
  int nlines;
  char linestore[MAXSPACE];
  if((nlines=readlines(lineptr,MAXLINES,linestore)) >= 0){
    qsort(lineptr,0,nlines-1);
    writelines(lineptr,nlines);
    return 0;
  }else{
    printf("\n error input too big to sort\n");
    return 1;
  }
}

int readlines(char *lineptr[], int maxlines,char *ls)
{
  int len, nlines;
  char *p,line[MAXLEN];
  nlines = 0;
  p=ls+strlen(ls);
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines||(strlen(ls)+len)>MAXSPACE)                         
      return -1;           
    else{
      line[len-1]='\0';
      strcpy(p,line);
      lineptr[nlines++]=p;
      p+=len;
    }
  return nlines;
}

void writelines(char *lineptr[],int nlines)
{
  int i;

  for(i=0;i<nlines;i++)
    printf("%s\n",lineptr[i]);
}

void qsort(char *v[],int left,int right)
{
  int i,last;
  void swap(char *v[],int i,int j);

  if(left>=right)
    return;
  swap(v,left,(left+right)/2);
  last=left;
  for(i=left+1;i<=right;i++)
    if(strcmp(v[i],v[left])<0)
      swap(v,++last,i);
  swap(v,left,last);
  qsort(v,left,last-1);
  qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
  char *temp;

  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int get_line(char s[],int lim)
{
  int c,i;
  i=0;
  while(--lim>0 && (c=getchar())!=EOF && c!='\n')
    s[i++]=c;
  if(c=='\n')
    s[i++]=c;
  s[i]='\0';
  return i;
}

