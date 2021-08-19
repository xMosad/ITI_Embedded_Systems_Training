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

void main ()
{
	/* Motor Control pin as output  */
	GPIO_voidSetPinDirection(PORTD , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);

	while(1)
	{
		/* Rotate clockwise  */
		GPIO_voidSetPinValue(PORTD , 0 , HIGH);
		GPIO_voidSetPinValue(PORTD , 1 , LOW);
		_delay_ms(2000);

		/* Rotate in anti clockwise */
		GPIO_voidSetPinValue(PORTD , 0 , LOW);
		GPIO_voidSetPinValue(PORTD , 1 , HIGH);
		_delay_ms(2000);
	}

}




