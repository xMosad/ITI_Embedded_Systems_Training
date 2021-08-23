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
	GPIO_voidSetPortDirection(PORTC , OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN0 , INPUT);

	ADC_voidInit();
	u8 read ;
	while(1)
	{

		read = ADC_u8GetChannelReading(ADC0);
		GPIO_voidSetPortValue(PORTC,read);

		_delay_ms(1000);
	}

}













