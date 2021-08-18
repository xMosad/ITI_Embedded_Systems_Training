#include <stdio.h>

int main ()
{
	int num = 0; 
	printf("Enter the answer of 3x4 :");
	scanf("%i" , &num);
	
	/* Loop */
	/* Waiting */
	while (num != 12)
	{	
		printf("Not correct. try again : ");
		scanf("%i" , &num);	
	}
	
	
	printf("Thank you");
	
	
	
}