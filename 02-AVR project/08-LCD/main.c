/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"

/* HAL */
#include "LCD_Interface.h"

/******************************************************************************
* Macros
*******************************************************************************/
#define    BLOCK0   0
#define    BLOCK1   1

u8 Block0[] = {  0x04,0x15,0x0E,0x04,0x0A,0x0A,0x11,0x00}; // Man
u8 Block1[] = {  0x00,0x0A,0x15,0x11,0x0A,0x0A,0x04,0x00}; // Heart
void main ()
{
	LCD_voidInit();
	LCD_voidWriteString("Hi Mosad !");
	LCD_voidAddNewPattern( Block0, 0);
	LCD_voidAddNewPattern( Block1, 1);
	LCD_voidWritePattern(BLOCK0 , 2 , 16);

	while(1)
	{
		for (u8 i = 1 ; i < 16 ; i+=2)
		{
			LCD_voidWritePattern(BLOCK0 , 2 , i);
			LCD_voidWritePattern(BLOCK1 , 2 , i+1);
			_delay_ms(600);
			LCD_voidGoTo(2 , i);
			LCD_voidWriteString("  ");
		}
		while(1)
		{

		}
	}

}




