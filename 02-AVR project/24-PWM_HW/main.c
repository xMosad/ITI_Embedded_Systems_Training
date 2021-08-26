/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "TMR_Interface.h"


void main ()
{
	GPIO_voidSetPinDirection(PORTB , PIN3 , HIGH);
	TMR_voidTimer0Init();
	while(1)
	{
		for (u8 i = 0 ; i < 256 ; i++)
		{
			TMR_voidTimer0SetCompareMatch(i);
			_delay_ms(100);
		}

	}

}






