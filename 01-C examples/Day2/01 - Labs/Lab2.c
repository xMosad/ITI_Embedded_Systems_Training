#include <stdio.h>

int main ()
{
	int hour , salary; 
	printf("Please enter the hour ");
	scanf("%i" , &hour);
	if (hour < 40)
	{
		salary = hour * 50 * 0.9 ;
	}
	if (hour >= 40)
	{
		salary = hour * 50 ;
	}
	printf("your salary %i" ,salary);
}