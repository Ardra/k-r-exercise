#include<stdio.h>
main()
{
	int lower = 0,upper = 300,step = 20;
	float fahr, celsius;
	fahr = lower;
	printf("FAHRENHEIT-CELSIUS TABLE\n");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
	
