#include <stdio.h>

void Sort(int *arr , int length );

void main (void)
{
	int input_arr[100];
	int length ;
	
	/* First we enter the length */
	printf("Enter length max 100 : ");
	scanf("%i" , &length);
	
	/* The we take the numebers from the user */
	for (int i = 0 ; i < length ; i++)
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &input_arr[i]);
	}
	
	Sort(input_arr , length);
	
}

void Sort(int *arr , int length )
{
	int temp ;
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