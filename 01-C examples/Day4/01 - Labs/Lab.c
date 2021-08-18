#include <stdio.h>

//objdump -s -j .rdata out.o
char name[10] = "Ahmed";
char *namePtr = "Ali";
int main (void)
{
	/*
	printf("%s\n" , name);
	printf("%s\n" , namePtr);
	
	printf("Enter first name : ");
	scanf("%s" , name);
	
	//namePtr[1] = 'm';
	//printf("Enter Second name : ");
	//scanf("%s" , &namePtr);
	
	printf("\n%s %s\n" , name , namePtr);
	*/
	
	/*****************************/
	
	
	int var = 0x9000 ;
	unsigned char *ptr = (unsigned char *)&var;
	printf("\n%i" , *ptr);
	ptr++;
	printf("\n%x" , *ptr);

	
}