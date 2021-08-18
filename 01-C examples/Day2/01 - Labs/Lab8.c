#include <stdio.h>

int main ()
{
	int num , sum = 0; 
	float average ;
	printf("Enter the numbers : \n");
	for (int i = 1 ; i <= 10 ; i++)
	{
		printf("Number %i : " , i);
		scanf("%i" , &num);
		sum += num ;
	}
	average = sum / 10.0 ;
	printf("Sum : %i \n" , sum);
	printf("Average : %f " , average);
	
}