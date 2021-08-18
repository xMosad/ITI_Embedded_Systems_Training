#include <stdio.h>

int main ()
{
	int ID,pass,iterator,flag=0;
	printf("Please Enter your ID: ");
	scanf("%d",&ID);
	
	switch(ID)
	{
		case 1234: 
			printf("Please Enter Password: ");
		    for (iterator = 0; iterator <3; iterator++)
			{
				scanf ("%d",&pass);
				if(pass == 7788)
				{
				   printf("Welcome Ahmed");
				   break;
				}
					   
				else if (iterator<2)
				{
				   printf("Try again: ");
				}
				else if (iterator == 2)
				{
					printf("Incorrect password for 3 times, No more tries");
				}
			}
			
			break;
				   
		case 5678: 
			printf("Please Enter Password: ");
		    for (iterator = 0; iterator <3; iterator++)
			{
			   scanf ("%d",&pass);
			   if(pass == 5566)
			   {
				   printf("Welcome Amr");
				   flag = 1;
				   break;
			   }
			   
			   else if (iterator<2)
			   {
				   printf("Try again: ");
			   }
			}
			break;
				   
		case 9870: 
			printf("Please Enter Password: ");
		    for (iterator = 0; iterator <3; iterator++)
			{
			   scanf ("%d",&pass);
			   if(pass == 1122)
			   {
				   printf("Welcome Wael");
				   flag = 1;
				   break;
			   }
			   
			   else if (iterator<2)
			   {
				   printf("Try again: ");
			   }
			}
			break;
				   
		default  : 
			printf("You are not registered");
		    flag = 2;
	}
	
	
}