#include "stdio.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;

void main(void)
{
	typedef struct
	{
		u16  x;
		u32  y;
		u16  z;
		u32  k;
	}mystruct;
	
	printf("Size of sturct is %d", sizeof(mystruct));
}