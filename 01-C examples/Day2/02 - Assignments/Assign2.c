#include <stdio.h>

int main ()
{
int ID, Pass;
	
	printf("Please Enter Your ID: ");
	scanf("%d",&ID);
	
	if ((ID == 1111) || (ID == 2222) || (ID == 3333) )
	{
		printf("Please Enter Your Password: ");
		scanf("%d",&Pass);
		
		if((ID == 1111) && (Pass == 1234))
		{
			printf("Welcome Ahmed");
		}
		
		else if((ID == 2222) && (Pass == 5678))
		{
			printf("Welcome Ali");
		}
		
		else if((ID == 3333) && (Pass == 1011))
		{
			printf("Welcome Amr");
		}
		
		else
		{
			printf("Incorrect Password");
		}
	}
	
	else
	{
		printf("Incorrect ID");
	}

}