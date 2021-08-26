/*
 * main.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "ADC_Interface.h"

void main ()
{
	/* Init pins */
	GPIO_voidSetPinDirection(PORTC , PIN0, OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN1, OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN2, OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN0 , INPUT);
	ADC_voidInit();
	f32 read ;
	while(1)
	{

		read = ADC_u8GetChannelReading(ADC0);
		read = (read * 5) / 256 ;

		GPIO_voidSetPortValue(PORTC , LOW);
		if ( (read > 0) && (read < 1.5) )
		{
			GPIO_voidSetPinValue(PORTC  , PIN0 , HIGH);
		}
		else if ((read > 1.5) && (read < 3))
		{
			GPIO_voidSetPinValue(PORTC  , PIN1 , HIGH);
		}
		else
		{
			GPIO_voidSetPinValue(PORTC  , PIN2 , HIGH);
		}
		_delay_ms(1000);
	}

}













