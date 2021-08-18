#include <stdio.h>
#include "macro.h"
#include "macro.h"
#include "macro.h"

typedef   unsigned int   u32 ;


void main(void)
{
	u32 n1 = 0 ;
	u32 n2 = 7 ;
	u32 n3 = 0b11110111 ;
	u32 m = 0xff;
	
	
	SET_BIT(n1 , 0);
	CLR_BIT(n2 , 2);
	TOG_BIT(n3 , 1);
	
	printf(" n1 = %i \n" , n1);
	printf(" n2 = %i \n" , n2);
	printf(" n3 = %i \n" , n3);

}