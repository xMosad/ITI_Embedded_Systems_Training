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


void main ()
{
	LCD_voidInit();

	u8 state = 0;
	while(1)
	{
		for (u8 i = 1 ; i < 11 ; i+=2)
		{
			if (state == 0)
			{
				LCD_voidGoTo(1 , i);
				LCD_voidWriteString("Mosad");
				_delay_ms(500);
				LCD_voidGoTo(1 , i);
				LCD_voidWriteString("     ");
				state = 1 ;
			}
			else if (state == 1)
			{
				LCD_voidGoTo(2 , i);
				LCD_voidWriteString("Mosad");
				_delay_ms(500);
				LCD_voidGoTo(2 , i);
				LCD_voidWriteString("     ");
				state = 0 ;
			}

		}
	}

}




