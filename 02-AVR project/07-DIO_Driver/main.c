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

u8 input ;
void main ()
{
	GPIO_voidSetPortDirection(PORTD , OUTPUT);
	GPIO_voidSetPinDirection(PORTA , 1 , INPUT);
	u8 val = 0;
	while(1)
	{

		val = GPIO_u8GetPinValue(PORTA , 1);
		if (val == 1)
			GPIO_voidSetPortValue(PORTD , 255);
		else
			GPIO_voidSetPortValue(PORTD , 0);

	}

}




