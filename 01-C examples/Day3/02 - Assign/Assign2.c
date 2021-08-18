#include <stdio.h>

/* Proto type */
int Add (int a , int b);
int Sub (int a , int b);
int Mul (int a , int b);
int Dev (int a , int b);
int And (int a , int b);
int Or (int a , int b);
int Not (int a );
int Xor (int a , int b);
int Rem (int a , int b);
int Inc (int a );
int Dec (int a );

void main(void)
{
	int operation_id ;
	int op1 , op2 , result;
	printf("Please Enter operaion ID \n");
	printf("1 - Add \n2 - Subtract\n3 - Multiply\n 4 - Devide\n5 - And\n6 - Or\n");
	printf("7 - Not\n8 - Xor\n9 - Reminder\n10 - Increment\n11 - Decrement\n");
	scanf("%d",&operation_id);
	
	if (operation_id > 11 )
	{
		printf ("Wrong ID");
	}
	
	else if ((operation_id == 7 ) || (operation_id == 10 ) || (operation_id == 11 ))
	{
		printf("Please Enter Operand  : ");
		scanf("%i" , &op1);
	}
	
	else
	{
		printf("Please Enter Operand 1  : ");
		scanf("%i" , &op1);
		
		printf("Please Enter Operand 2  : ");
		scanf("%i" , &op2);
	}
	
	switch (operation_id)
	{
		case 1  : result = Add(op1 , op2);  break ;
		case 2  : result = Sub(op1 , op2);  break ;
		case 3  : result = Mul(op1 , op2);  break ;
		case 4  : result = Dev(op1 , op2);  break ;
		case 5  : result = And(op1 , op2);  break ;
		case 6  : result = Or(op1 , op2);  break ;
		case 7  : result = Not(op1);  break ;
		case 8  : result = Xor(op1 , op2);  break ;
		case 9  : result = Rem(op1 , op2); break ;
		case 10 : result = Inc(op1 );  break ;
		case 11 : result = Dec(op1 );  break ;
		default :   break;
	}
	
	printf("\n Result = %i" , result );

}

/* Functions definition */
int Add (int a , int b)
{
	return a + b ;
}

int Sub (int a , int b)
{
	return a - b ;
}

int Mul (int a , int b)
{
	return a * b ;
}

int Dev (int a , int b)
{
	return a / b ;
}

int And (int a , int b)
{
	return a & b ;
}

int Or (int a , int b)
{
	return a | b ;
}

int Not (int a )
{
	return ~ a  ;
}

int Xor (int a , int b)
{
	return a ^ b ;
}

int Rem (int a , int b)
{
	return a % b ;
}

int Inc (int a )
{
	return  ++a  ;
}

int Dec (int a )
{
	return  --a  ;
}
