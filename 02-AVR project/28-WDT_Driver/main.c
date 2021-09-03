/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "WDT_Interface.h"


void main ()
{
	WDT_voidEnable();


	WDT_voidSleep(WDT_2_1_s);
	GPIO_voidSetPinDirection(PORTD , PIN0 , OUTPUT);
	GPIO_voidSetPinValue(PORTD , PIN0 , HIGH);
	_delay_ms(1000);


	WDT_voidSleep(WDT_2_1_s);
	GPIO_voidSetPinValue(PORTD , PIN0 , LOW);
	_delay_ms(1000);

	WDT_voidSleep(WDT_0_13_s); /**/

	while(1)
	{


	}

}






