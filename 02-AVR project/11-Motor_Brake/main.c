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
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);

	/* Button pin as input and activate pull up */
	GPIO_voidSetPinDirection(PORTD , 0 , INPUT);
	GPIO_voidSetPinValue(PORTD , 0 , HIGH);

	u8 state ;
	while(1)
	{
		/* Read button state */
		state = GPIO_u8GetPinValue(PORTD , 0);

		/* Take action */
		if (state == 0)
		{
			GPIO_voidSetPinValue(PORTD , 1 , LOW);
		}
		else
		{
			GPIO_voidSetPinValue(PORTD , 1 , HIGH);
		}

		/* Delay for debounce */
		_delay_ms(200);
	}

}




