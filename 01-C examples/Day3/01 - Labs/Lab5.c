#include <stdio.h>

void main(void)
{
    int arr[10];
	
	for(int i = 0; i < 10 ; i++ )
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &arr[i]);
	}
	
	printf("The values reversed : \n" );
	for(int i = 9; i >= 0 ; i-- )
	{
		printf("%i\n" ,arr[i]);
	}
  
}
