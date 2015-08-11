#include<stdio.h>
float conversion(float f);
main()
{
	int lower = 0,upper = 300,step = 20;
	float fahr, celsius;
	fahr = lower;
	printf("FAHRENHEIT-CELSIUS TABLE\n");
	while(fahr <= upper)
	{
		celsius = conversion(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
float conversion(float f)
{
	float c;
	c = (5.0/9.0) * (f-32.0);
	return c;
}
		
