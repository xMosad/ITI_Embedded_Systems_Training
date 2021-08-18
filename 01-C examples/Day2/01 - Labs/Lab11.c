#include <stdio.h>

int main ()
{
	int num = 0 , res = 1;
	printf("Enter the integer : ");
	scanf("%i" , &num);
	
	while (num)
	{
		res = res * num ;
		num-- ;
	}
	
	
	printf("Factorial = %i" , res);
	
	
}