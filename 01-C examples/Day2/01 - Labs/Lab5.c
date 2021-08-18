#include <stdio.h>

int main ()
{
	int ID; 
	printf("Please enter your ID ");
	scanf("%i" , &ID);
	
	switch (ID)
	{
		case 1234 : printf(" Welcome Ahmed"); break;
		case 5678 : printf("Welcome Mosad"); break;
		case 1145 : printf("Welcome Shaimaa"); break;
		default  : printf("Wrong ID"); break; 
	}
	
}