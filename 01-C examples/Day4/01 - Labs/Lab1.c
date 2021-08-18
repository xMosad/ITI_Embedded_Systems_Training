#include <stdio.h>

int main (void)
{
	int x = 10;
	int *ptr = &x;
	
	printf("X before change is: %d\n",x);
	
	/* Change x through its address */
	*ptr = 20;
	
	printf("X after change is: %d",x);
}