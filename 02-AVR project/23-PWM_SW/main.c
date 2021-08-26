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
#include "GIE_Interface.h"
#include "TMR_Interface.h"

void PWM_BY_SW (void);

void main ()
{
	/* Motor Control pin as output  */
	GPIO_voidSetPinDirection(PORTD , PIN0 , OUTPUT);
	//GPIO_voidSetPinValue(PORTD , PIN0 , HIGH);
	GIE_voidEnable();
	TMR_voidTimer0Init();
	TMR_voidTimer0SetCallBack(PWM_BY_SW);
	while(1)
	{


	}

}

void PWM_BY_SW (void)
{
	static u16 counter = 0;
	counter++;
	if (counter == 5)
	{
		GPIO_voidSetPinValue(PORTD , PIN0 , LOW);
	}
	else if (counter == 20)
	{
		GPIO_voidSetPinValue(PORTD , PIN0 , HIGH);
		counter = 0 ;
	}
}





