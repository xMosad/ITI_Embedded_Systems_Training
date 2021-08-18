#include <stdio.h>

int main ()
{
	int grade; 
	printf("Please enter the grade ");
	scanf("%i" , &grade);
	
	if ( grade < 50)
	{
		printf("your rating is failed");
	}
	
	else if ((grade >= 50) && (grade < 65))
	{
		printf("your rating is Normal");
	}
	
	else if ((grade >= 65) && (grade < 75))
	{
		printf("your rating is Good");
	}
	
	else if ((grade >= 75) && (grade < 85))
	{
		printf("your rating is Very good");
	}
	
	else 
	{
		printf("your rating is  Excellent");
	}
	
}