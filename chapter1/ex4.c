#include<stdio.h>
/* program for celsius - fahrenheit table*/ 
main()
{
	int lower=0,upper=100,step=10;
	float fah,celsius;
	celsius=lower;
	printf("CELSIUS-FAHRENHEIT TABLE\n");
	while(celsius<=upper)
	{
		fah=(celsius*5)/9+32;
		printf("%.0f\t%.1f\n",celsius,fah);
		celsius=celsius+step;
	}
}
