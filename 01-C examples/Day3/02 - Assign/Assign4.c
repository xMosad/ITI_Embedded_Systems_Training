#include <stdio.h>

void main(void)
{
	int class1[10],class2[10],class3[10];
	int arr[30] ;
	
	int i,j;
	int passed=0,failed=0;
	int min=0,max=0,sum=0;
	
	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i] = class1[i];
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i+10] = class2[i];
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i+20] = class3[i];
	}
	

	/* Scan the School Grades */
	for ( i =1 ; i <= 3 ; i++)
	{
		for (j=0 ; j<10 ; j++)
		{

			printf("Enter grade for student number %d in class %d: ",j+1,i);
			if (i==1)
				scanf("%d",&class1[j]);
			else if (i==2)
				scanf("%d",&class2[j]);
			else if (i==3)
				scanf("%d",&class3[j]);
		}
	}


	for ( i =1 ; i <= 3 ; i++)
	{
		for (j=0 ; j<10 ; j++)
		{
			if (i==1)
			{
				if (class1[j] > max)
					max = class1[j];
				else if (class1[j] < min)
					min=class1[j];
				
				if (class1[j] >= 50 )
					passed++;
				else
					failed++;
				sum+=class1[j];
			}
			
			if (i==2)
			{
				if (class2[j] > max)
					max=class2[j];
				else if (class2[j] < min)
					min=class2[j];
				
				if (class2[j] >= 50)
					passed++;
				else
					failed++;
				sum+=class2[j];
			}
			if (i==3)
			{
				if (class3[j] > max)
					max=class3[j];
				else if (class3[j] < min)
					min=class3[j];
				
				if (class3[j] >= 50)
					passed++;
				else
					failed++;
				sum+=class3[j];
			}
		}

	}

	printf("\nNumber of passed students = %d \n",passed);
	printf("Number of failed students = %d \n",failed);
	printf("Highest grade = %d \n",max);
	printf("Lowest grade = %d \n",min);
	printf("Average grade = %d \n",sum/30);

}
