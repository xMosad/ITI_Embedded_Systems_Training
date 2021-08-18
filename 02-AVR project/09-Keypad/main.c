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
#include "KPD_Interface.h"

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };

void main ()
{
	/* Initialize portd as output */
	GPIO_voidSetPortDirection(PORTD , OUTPUT)  ;

	/* Initialize keypad */
	KPD_voidInitPins();

	u8 val ;
	while(1)
	{
		val = KPD_u8GetPressedKey();
		if (val){
			val = val - 48 ;
			GPIO_voidSetPortValue(PORTD , Arr_DecToSeg[val]);
		}

	}

}




