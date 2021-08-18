#include <stdio.h>

int Get_Max (int x, int y);



void main(void)
{
	int a,b,max;
	printf("Please Enter Value 1: ");
	scanf("%d",&a);
	
	printf("Please Enter Value 2: ");
	scanf("%d",&b);
	
	max = Get_Max(a,b);
	printf("The Maximum value is %d",max);
}

int Get_Max (int x, int y)
{
	int var;
	
	if (x>y)
	{
		var = x;
	}
	
	else
	{
		var = y;
	}
	
	return var;
}



