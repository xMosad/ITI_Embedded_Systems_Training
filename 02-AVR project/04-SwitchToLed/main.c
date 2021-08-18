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
	/* Set PORTD as output */
	DDRD   = 0xff;
	/* Set PORTA as input */
	CLR_BIT(DDRA,0);
	/* Connect A0 to Pull up resistor */
	//SET_BIT(PORTA,0);

	while(1)
	{
		/* Check if A0 is High, Flash LED String */
		if(GET_BIT(PINA,0) == 1)
		{
			PORTD = ~PORTD;
		}
		else
		{
			PORTD = 0;
		}
		_delay_ms(500);
	}

}
