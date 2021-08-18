#include <stdio.h>

void main(void)
{
    int arr[10];
	int sum = 0 ; 
	float average = 0 ;
	
	for(int i = 0; i < 10 ; i++ )
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &arr[i]);
		sum += arr[i] ;
	}
	
	average = sum / 10.0 ;
	printf("Sum     = %i \n" , sum );
	printf("Average = %f \n" , average );
}
