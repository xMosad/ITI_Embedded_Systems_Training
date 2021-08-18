#include <stdio.h>

/* Proto type */
int Get_Max_Of_4 (int x1, int x2, int x3, int x4);
int Get_Min_Of_4 (int x1, int x2, int x3, int x4);

void main(void)
{
	int a,b,c,d,max,min;
	printf("Please Enter Value 1: ");
	scanf("%d",&a);
	
	printf("Please Enter Value 2: ");
	scanf("%d",&b);

	printf("Please Enter Value 3: ");
	scanf("%d",&c);
	
	printf("Please Enter Value 4: ");
	scanf("%d",&d);
	
	max = Get_Max_Of_4(a,b,c,d);
	min = Get_Min_Of_4(a,b,c,d);
	printf("The Maximum value is %d\n",max);
	printf("The Minimum value is %d",min);
}

/* Functions definition */
int Get_Max_Of_4 (int x1, int x2, int x3, int x4)
{
	int max;
	max = x1;
	
	if (x2 > max)
	{
		max = x2;
	}
	
	if (x3 > max)
	{
		max = x3;
	}
	
	if (x4 > max)
	{
		max = x4;
	}
	
	return max;
	
}

int Get_Min_Of_4 (int x1, int x2, int x3, int x4)
{
	int min;
	min = x1;
	
	if (x2 < min)
	{
		min = x2;
	}
	
	if (x3 < min)
	{
		min = x3;
	}
	
	if (x4 < min)
	{
		min = x4;
	}
	
	return min;
	
}
