#include <stdio.h>

int Add(int* a, int* b);

void main (void)
{
	int var1, var2;
	int result;
	
	printf("Please Enter Value 1:  ");
	scanf("%d",&var1);
	
	printf("Please Enter Value 2:  ");
	scanf("%d",&var2);
	
	/* pass by address */
	result = Add(&var1,&var2);
	
	printf("The result is:  %d",result);
}

int Add(int* a, int* b)
{	
	int z = *a + *b;
	return z;
}