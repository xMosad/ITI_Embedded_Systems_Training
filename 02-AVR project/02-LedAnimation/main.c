/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mosad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"

#define F_CPU 8000000
#include "util/delay.h"

void main ()
{
	/* Initialize the pin as output */
	DDRD = 0xff ;
	while(1)
	{
		/* Shift LEDs Left */
		for(u8 LoopCounter=0; LoopCounter<8;LoopCounter++)
		{
			PORTD = 0x00;
			SET_BIT(PORTD , LoopCounter);
			_delay_ms(500);
		}

		/* Shift LEDs Right */
		for(u8 LoopCounter=6; LoopCounter>0;LoopCounter--)
		{
			PORTD = 0x00;
			SET_BIT(PORTD , LoopCounter);
			_delay_ms(500);
		}
	}

}
