#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

void main(void)
{
	u8 *ptr ;
	u32 BlockSize;
	u32 Counter_1, Counter_2 ;
	u8 TemporaryVariable;
	
	printf("Please Enter the number of numbers: ");
	scanf ("%d",&BlockSize);
	
	ptr = (u8*) malloc(BlockSize);
	
	for (Counter_1=0; Counter_1<BlockSize; Counter_1++)
	{
		printf("Please Enter number %d: ",Counter_1+1);
		scanf ("%d",&ptr[Counter_1]);
	}
	
	/* Sort the values using Bubble sorting */
	for (Counter_1=0; Counter_1<BlockSize-1;Counter_1++)
	{
		 for (Counter_2 = 0; Counter_2 < BlockSize-Counter_1-1; Counter_2++) 
		{
			if(ptr[Counter_2] > ptr[Counter_2+1])
			{
				/* Swap */
				TemporaryVariable = ptr[Counter_2+1];
				ptr[Counter_2+1] = ptr[Counter_2];
				ptr[Counter_2] = TemporaryVariable;
			}
		}
	}
	
	/* Print the values after sorting */
	printf("Values after sorting are:\n");
	for (Counter_1=0;Counter_1<BlockSize;Counter_1++)
	{
		printf("%d\n",ptr[Counter_1]);
	}
}