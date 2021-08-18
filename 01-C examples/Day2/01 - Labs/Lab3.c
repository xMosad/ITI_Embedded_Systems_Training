#include <stdio.h>

int main ()
{
	int num ; 
	
	/* Ask the user to enter value 1 */
	printf("Please enter number : ");
	scanf("%i" , &num);
	
	if (num % 2)
		printf("Number is odd ");
		//printf("\n Will this print ??");
	else 
		printf("Number is even ");
		//printf("\n Will this print ??");
}