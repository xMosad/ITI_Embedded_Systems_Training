#include <stdio.h>

void main(void)
{
    int arr[10];
	int search = 0 ;
	int flag = 0 , temp; 
	int first = 0 ; 
	int last = 9 ;
	int mid = (0 + 9) / 2 ;
	
	/* Enter the array */
	for (int i = 0 ; i < 10 ; i++)
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &arr[i]);
	}
	
	printf("Enter the search value  :");
	scanf("%i" , &search);
	
	/* Sorting the Array first */
	for(int i = 0; i < 9 ; i++ )
	{
		
		for (int j = 0 ; j < 9-i ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j+1] ;
				arr[j+1] = arr[j];
				arr[j] = temp ;
			}
		}
	}
	
	
	while (first <= last)
	{
		if ( arr[mid] == search)
		{
			flag = 1 ;
			break ;
		}
			
		else if (arr[mid] < search)
		{
			first = mid +1 ;
			mid = (last + first) / 2 ;
		}
		else
		{
			last = mid - 1 ;
			mid = (first + last) / 2 ;
		}
	}
	if (flag == 1)
	{
		printf("Value Found");
	}
	else
	{
		printf("Value Not Found");
	}
	
	
	
}
