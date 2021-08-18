#include <stdio.h>

	int x = 10;
	int y = 20;

void Swap (void);

void main(void)
{

	printf("X before swap = %d\n",x);
	printf("Y before swap = %d\n\n\n",y);
	
	Swap();
	
	printf("X after swap = %d\n",x);
	printf("Y after swap = %d\n",y);
}


void Swap (void)
{
	int temp = x;
	x = y;
	y = temp;
}
