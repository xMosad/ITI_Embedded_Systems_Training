#include <stdio.h>
//#include "STD_TYPE.h"

typedef unsigned char      u8 ;
typedef unsigned short int u16;
typedef unsigned long  int u32;
typedef signed   char      s8 ;
typedef signed   short int s16;
typedef signed   long  int s32;
typedef float              f32;
typedef double             f64;

void main(void)
{
	u8 x ; 
	u32 y ;
	
	printf("The size of u8  is %d bytes\n", sizeof(u8)) ;
	printf("The size of u16 is %d bytes\n", sizeof(u16));
	printf("The size of u32 is %d bytes\n", sizeof(u32));
	printf("The size of s8  is %d bytes\n", sizeof(s8)) ;
	printf("The size of s16 is %d bytes\n", sizeof(s16));
	printf("The size of s32 is %d bytes\n", sizeof(s32));
	printf("The size of f32 is %d bytes\n", sizeof(f32));
	printf("The size of f64 is %d bytes\n", sizeof(f64));
	printf("The size of f64 is %d bytes\n", sizeof(long long int));
}