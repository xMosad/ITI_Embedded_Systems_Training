#include "stdio.h"

typedef unsigned short int u16;
typedef unsigned char  u8;
typedef unsigned long int u32;



struct human {
	u8 hight ;
	u8 weight ;
};

/*  Creatin struct */
typedef struct employee 
{
	u8 name [10];
	u8 age ;
	u16 salary ;
	u16 bonus ;
	struct human info ;
	u32 *ptr;
	struct employee *structPtr;
}employee_t; 

/* Proto types */
void func1 (employee_t emp);
void func2 (employee_t *emp);

/* Making object of the struct */
employee_t ahmed; 
employee_t arr[10];
employee_t *structPtr;



void main(void)
{
	u32 x = 5 ;
	ahmed.age = 5 ;
	ahmed.name[0] = 'h';
	ahmed.name[1] = 'm';
	ahmed.info.hight = 25 ;
	ahmed.ptr = &x ;
	ahmed.structPtr = &ahmed;
	printf("ahmed age : %i \n" , ahmed.age);
	printf("ahmed name : %s \n" , ahmed.name);
	printf("ahmed hight : %i \n" , ahmed.info.hight);
	printf("ahmed ptr : %i \n" , ahmed.ptr);
	printf("ahmed ptr value : %i \n" , *(ahmed.ptr));
	printf("ahmed pointer using &: %i \n" , &ahmed);
	printf("ahmed pointer : %i \n" , ahmed.structPtr);
	printf("ahmed name pointer : %i \n" , ahmed.name);
	
	func1(ahmed);
	
	func2(&ahmed);
	
	/*
	signed char x = 255 ;
	printf("%i\n" ,x);
	printf("%hu\n" ,-128);
	printf("%hu\n" ,128);
	*/
}


void func1 (employee_t emp)
{
	printf("*****************************");
	printf("Employee age : %i \n" , emp.age);
	printf("Employee name : %s \n" , emp.name);
	printf("Employee hight : %i \n" , emp.info.hight);
	printf("Employee ptr : %i \n" , emp.ptr);
	printf("Employee ptr value : %i \n" , *(emp.ptr));
	printf("Employee pointer using & : %i \n" , &emp);
	printf("Employee pointer using self ref : %i \n" , emp.structPtr);
	printf("Employee name pointer : %i \n" , emp.name);
}

void func2 (employee_t *emp)
{
	printf("*****************************");
	printf("Employee age : %i \n" , emp->age);
	printf("Employee name : %s \n" , emp->name);
	printf("Employee hight : %i \n" , emp->info.hight);
	printf("Employee ptr : %i \n" , emp->ptr);
	printf("Employee ptr value : %i \n" , *(emp->ptr));
	printf("Employee pointer using & : %i \n" , emp);
	printf("Employee pointer using self ref : %i \n" , emp->structPtr);
	printf("Employee name pointer : %i \n" , emp->name);
}