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
#include "GPIO.h"

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };

void main ()
{
	GPIO_setPortDirection(PORTD , OUTPUT);
	GPIO_setPinDirection(PORTC , PIN0 , OUTPUT);
	GPIO_setPinDirection(PORTC , PIN1 , OUTPUT);
	GPIO_setPinDirection(PORTC , PIN2 , OUTPUT);
	u8 val = 0 ;
	u8 counter = 0 ;
	u8 hunderds , tens , ones ;
	while(1)
	{
		/* Devid the number */
		hunderds = val / 100 ;
		tens = (val % 100) / 10 ;
		ones = (val % 100) % 10 ;

		/* Activate SSD 1 only */
		GPIO_setPinValue(PORTC , PIN0 , LOW);
		GPIO_setPinValue(PORTC , PIN1 , HIGH);
		GPIO_setPinValue(PORTC , PIN2 , HIGH);
		GPIO_setPortValue(PORTD , Arr_DecToSeg[hunderds]);
		_delay_ms(10);

		/* Activate SSD 2 only */
		GPIO_setPinValue(PORTC , PIN0 , HIGH);
		GPIO_setPinValue(PORTC , PIN1 , LOW);
		GPIO_setPinValue(PORTC , PIN2 , HIGH);
		GPIO_setPortValue(PORTD , Arr_DecToSeg[tens]);
		_delay_ms(10);

		/* Activate SSD 2 only */
		GPIO_setPinValue(PORTC , PIN0 , HIGH);
		GPIO_setPinValue(PORTC , PIN1 , HIGH);
		GPIO_setPinValue(PORTC , PIN2 , LOW);
		GPIO_setPortValue(PORTD , Arr_DecToSeg[ones]);
		_delay_ms(10);

		counter++;
		if (counter == 20)
		{
			val++;
			counter = 0;
		}
	}

}




