#include <stdio.h>

void main(void)
{
	int h,i,j;
	
	printf("Please Enter the hieght of the pyramid: ");
	scanf("%d",&h);
	
	/* Every iteration print a line */
	for (i = 0; i < h; i ++)
	{
		/* Print spaces */
		for (j=0; j<h-1-i; j++)
		{
			printf(" ");
		}
		
		/* then Print stars */
		for (j=0; j<2*i+1; j++)
		{
			printf("*");
		}
		
		/* then go to the next line to print the next row */
		printf("\n");
	}
}