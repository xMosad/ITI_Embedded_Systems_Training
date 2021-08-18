#include <stdio.h>

int main ()
{
	int num = 0; 
	printf("Enter the number to display table :");
	scanf("%i" , &num);
	for (int i = 1 ; i <= 12 ; i++)
	{
		printf("%i  x  %i  = %i \n", num , i , num*i);
	}
	
	
	
	
}