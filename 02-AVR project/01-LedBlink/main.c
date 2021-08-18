/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mosad
 */


#include "avr/io.h"

#define F_CPU 8000000
#include "util/delay.h"


void main ()
{
	_delay_ms(1000);

	/* DDR  - > direction */
	/* PORT  - > 1 OR 0  */
	/* PIN  - > Read 1 or 0 */
	DDRD = 0b00000001 ;
	PORTD =0x01;
	_delay_ms(1000);
	PORTD =0x00;


	while(1)
	{


	}

}


