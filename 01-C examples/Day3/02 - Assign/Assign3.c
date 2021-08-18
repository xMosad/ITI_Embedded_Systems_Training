#include<stdio.h>

void main (void)
{
	int i;
	int arr[10];
    int max,min;
	
	/* Scan the values loop */
	for (i=0;i<10;i++)
	{
		printf("Please Enter number %d:  ",i);
		scanf ("%d",&arr[i]);
	}
	
	max=arr[0];
	min=arr[0];
	
	for(i=0;i<10;i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	printf("the maximum = %d\n",max);
    printf("the minimum = %d",  min);
}