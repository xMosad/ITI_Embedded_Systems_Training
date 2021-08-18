#include <stdio.h>

void swap(int **p , int **q , int **r);

void main (void)
{
	int x = 5 , y = 6 , z  = 8;
	int *p = &x , *q = &y , *r =&z;
	
	printf("x = %i\n" , x);
	printf("y = %i\n" , y);
	printf("z = %i\n" , z);
	printf("p = %p\n" , p);
	printf("q = %p\n" , q);
	printf("r = %p\n" , r);
	printf("*p = %i\n" , *p);
	printf("*q = %i\n" , *q);
	printf("*r = %i\n" , *r);
	
	
	printf ("\n\nSwapping pointers \n");
	swap(&p , &q , &r);
	
	printf("x = %i\n" , x);
	printf("y = %i\n" , y);
	printf("z = %i\n" , z);
	printf("p = %p\n" , p);
	printf("q = %p\n" , q);
	printf("r = %p\n" , r);
	printf("*p = %i\n" , *p);
	printf("*q = %i\n" , *q);
	printf("*r = %i\n" , *r);
	
	

}

void swap(int **p , int **q , int **r)
{
	int *temp ;
	temp = *r ;
	*r = *p ;
	*p = *q ;
	*q = temp;
}

