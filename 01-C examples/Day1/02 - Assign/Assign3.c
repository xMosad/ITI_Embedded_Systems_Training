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
	
	/* Print the results */
	printf("a + b = %i\n" , (num1+num2));
	printf("a - b = %i\n" , (num1-num2));
	printf("a & b = %i\n" , (num1&num2));
	printf("a | b = %i\n" , (num1|num2));
	printf("a ^ b = %i\n" , (num1^num2));
}