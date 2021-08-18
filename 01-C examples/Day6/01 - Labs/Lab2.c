#include <stdio.h>

typedef unsigned short int u16;

typedef struct
{
	u16 Salary    ;
	u16 Bonus     ;
	u16 Deduction ;
}Employee;

void main(void)
{
	Employee Ahmed,Amr,Waleed;
	u16 Total=0; 
	printf("Please Enter Ahmed Salary: ");
	scanf ("%d",&Ahmed.Salary);
	printf("Please Enter Ahmed Bonus: ");
	scanf ("%d",&Ahmed.Bonus);
	printf("Please Enter Ahmed Deduction: ");
	scanf ("%d",&Ahmed.Deduction);
	
	printf("Please Enter Amr Salary: ");
	scanf ("%d",&Amr.Salary);
	printf("Please Enter Amr Bonus: ");
	scanf ("%d",&Amr.Bonus);
	printf("Please Enter Amr Deduction: ");
	scanf ("%d",&Amr.Deduction);
	
	printf("Please Enter Waleed Salary: ");
	scanf ("%d",&Waleed.Salary);
	printf("Please Enter Waleed Bonus: ");
	scanf ("%d",&Waleed.Bonus);
	printf("Please Enter Waleed Deduction: ");
	scanf ("%d",&Waleed.Deduction);
	
	Total = (Ahmed.Salary + Amr.Salary + Waleed.Salary + Ahmed.Bonus
	         + Amr.Bonus + Waleed.Bonus - Ahmed.Deduction - Amr.Deduction
			 - Waleed.Deduction);
	
	printf("Total Value Needed is %d",Total);
}