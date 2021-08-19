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

#define   STEPPER_DELAY   200

void stepper_rotateClockWise(void);
void stepper_rotateAntiClockWise(void);

void main ()
{
	/* Motor Control pin as output  */
	GPIO_voidSetPinDirection(PORTD , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 2 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 3 , OUTPUT);

	while(1)
	{
		for (u8 i = 0 ; i < 5 ; i++)
		{
			stepper_rotateClockWise();
		}

		for (u8 i = 0 ; i < 5 ; i++)
		{
			stepper_rotateAntiClockWise();
		}

	}

}

void stepper_rotateClockWise(void)
{
	GPIO_voidSetPinValue(PORTD , 0 , HIGH);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);
	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , HIGH);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);
	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , HIGH);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);
	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , HIGH);
	_delay_ms(STEPPER_DELAY);
}

void stepper_rotateAntiClockWise(void)
{

	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , HIGH);
	_delay_ms(STEPPER_DELAY);

	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , HIGH);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);

	GPIO_voidSetPinValue(PORTD , 0 , LOW);
	GPIO_voidSetPinValue(PORTD , 1 , HIGH);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);

	GPIO_voidSetPinValue(PORTD , 0 , HIGH);
	GPIO_voidSetPinValue(PORTD , 1 , LOW);
	GPIO_voidSetPinValue(PORTD , 2 , LOW);
	GPIO_voidSetPinValue(PORTD , 3 , LOW);
	_delay_ms(STEPPER_DELAY);
}




