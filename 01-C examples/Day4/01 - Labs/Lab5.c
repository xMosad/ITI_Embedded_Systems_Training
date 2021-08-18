#include <stdio.h>

int Scalar_Mul(int *ptr1, int *ptr2);

void main (void)
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[10] = {5,7,2,0,11,6,17,24,20,100};
	int result = Scalar_Mul(arr1, arr2);

	
	printf("The result is:  %d",result);
}

int Scalar_Mul(int *ptr1, int *ptr2)
{
	int sum = 0;
	int i;
	
	for (i=0;i<10;i++)
	{
		sum += ptr1[i] * ptr2[i];
	}
	
	return sum;
}