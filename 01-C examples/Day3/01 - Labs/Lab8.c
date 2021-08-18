#include <stdio.h>

void main(void)
{
    int arr[10];
	int search = 0 ;
	int x = 0 ; 
	for (int i = 0 ; i < 10 ; i++)
	{
		printf("Please enter number %i :" , i+1);
		scanf("%i" , &arr[i]);
	}
	
	printf("Enter the search value  :");
	scanf("%i" , &search);
	
	for(int i = 0; i < 9 ; i++ )
	{
		if (arr[i] == search)
		{
			x++;
		}
	}
	
	if (x == 0 )
	{
		printf("Value Not Exist");
	}
	else
	{
		printf("Value Exists %i times : " , x);
	}
	
	
}
