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
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);
	while(1)
	{
		/* Buzzer on */
		GPIO_voidSetPinValue(PORTD , 1 , HIGH);
		_delay_ms(1000);

		/* Buzzer off */
		GPIO_voidSetPinValue(PORTD , 1 , LOW);
		_delay_ms(1000);
	}

}




