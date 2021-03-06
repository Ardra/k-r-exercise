#include<stdio.h>
#define MAX 100
int binsearch(int x,int v[],int n);
main()
{
  int v[MAX],x,n,i,result;
  printf("\n enter the no of elements");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&v[i]);
    }
  printf("\n enter the searching element");
  scanf("%d",&x);
  result=binsearch(x,v,n);
  if(result==-1)
    {
      printf("\n element not present");
    }
  else
    {
      printf("\n element present \n");
    }
}



int binsearch(int x,int v[],int n)
{
  int low,high,mid;
  low=0;
  high=n-1;
  mid=(low+high)/2;
  while(low<=high&&x!=v[mid])
    {
      if(x<v[mid]){
	high=mid-1;
      }
      else
	{
	  low=mid+1;
	}
      mid=(low+high)/2;
      if(x==v[mid]){
	return mid;
      }
      else
	{
	  return -1;
	}
    }
}

