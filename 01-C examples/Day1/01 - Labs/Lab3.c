#include <stdio.h>

int main ()
{
	int num1 , num2 ; 
	

	/* Ask the user to enter value 1 */
	printf("Please enter number 1 : ");
	scanf("%i" , &num1);
	
	/* Ask the user to enter value 1 */
	printf("Please enter number 2 : ");
	scanf("%i" , &num2);
	
	int x = num1+ +num1++;
	printf("\n num1+++num2 = %i" , x);
	
	/* Print the results */
	printf("\na + b = %i" , (num1+num2));
	printf("\na x b = %i" , (num1*num2));
	printf("\n num1++ = %i" , num1++);
	printf("\n ++num2 = %i" , ++num2);
	
	
}