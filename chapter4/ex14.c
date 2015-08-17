#include<stdio.h>
#define swap(t,x,y){t temp;temp=x;x=y;y=temp;}
main()
{
  int a,b;
  printf("\n enter a");
  scanf("%d",&a);
  printf("\n enter b");
  scanf("%d",&b);
  printf("\n before swapping a=%d b=%d",a,b);
  swap(int,a,b)
  printf("\n after swapping a=%d b=%d\n",a,b);
}
