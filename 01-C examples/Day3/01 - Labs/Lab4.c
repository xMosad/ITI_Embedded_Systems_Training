#include <stdio.h>

int Factorial_Recursion(int n);

void main(void)
{
    int num,fact;
    
	printf("Enter a value: ");
    scanf("%d", &num);
    
	fact = Factorial_Recursion(num);
	printf("Factorial of %d = %d", num ,fact );
  
}
int Factorial_Recursion(int n)
{
    if (n >= 1)
	{
        return n*Factorial_Recursion(n-1);
    }
	
	else
	{
        return 1;
	}
}