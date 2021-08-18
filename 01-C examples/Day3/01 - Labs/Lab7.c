#include <stdio.h>

void main(void)
{
    int arr[100];
	int temp ;
	int length ; 
	
	/* First we enter the length */
	printf("Enter length max 100 : ");
	scanf("%i" , &length);
	
	/* The we take the numebers from the user */
	for (int i = 0 ; i < length ; i++)
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &arr[i]);
	}
	
	/* Bubble sort algrothim */
	for(int i = 0; i < (length - 1) ; i++ )
	{	
		for (int j = 0 ; j < (length-1-i) ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j+1] ;
				arr[j+1] = arr[j];
				arr[j] = temp ;
			}
		}
	}
	
	/* Print the sorted values*/
	printf("Sorted values\n");
	for (int i = 0 ; i < length ; i++)
	{
		printf("%i \n" , arr[i]);
	}
	
	
}
