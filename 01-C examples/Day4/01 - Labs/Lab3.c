#include <stdio.h>

void calculate(int a, int b , int *s , int *sub);

void main (void)
{
	int var1, var2;
	int sum , sub;
	
	printf("Please Enter Value 1:  ");
	scanf("%d",&var1);
	
	printf("Please Enter Value 2:  ");
	scanf("%d",&var2);
	
	calculate(var1,var2 , &sum , &sub);
	
	printf("The sumtion is  :  %d\n", sum);
	printf("The substract is:  %d", sub);
}

void calculate(int a, int b , int *s , int *sub)
{
	*s = a + b;
	*sub = a - b ;
}