#include<stdio.h>
/*fahrenheit-celsius table*/
main()
{
	int fah;
	printf("fahrenheit-celsius table\n");
	for(fah=300;fah>=0;fah=fah-20)
	{
		printf("%3d\t%6.1f\n",fah,(5.0/9.0)*(fah-32));
	}
}
