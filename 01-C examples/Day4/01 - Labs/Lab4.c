#include <stdio.h>



void main (void)
{
	int arr[10] = {5 , 8 , 7 , 9 , 10 , 81 , 45 , 45 ,12};
	int *ptr = arr ;
	
	ptr = &arr[0];
	int sum ;
	for (int i = 0 ; i < 10; i++)
	{
		//sum += *(ptr+i); 
		sum += ptr[i];
	}
	
	arr[1]  == *(ptr + 1) == ptr[1]
	printf("sum = %i " , sum);
	
	
}

