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
#include "EXTI_Interface.h"
#include "GIE_Interface.h"


volatile u8 led1 , led2 ;
void main ()
{
	/* Init pins */
	GPIO_voidSetPinDirection(PORTC , PIN0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN1 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , PIN2 , INPUT);
	GPIO_voidSetPinDirection(PORTD , PIN3 , INPUT);
	/* Enable pull up for buttons */
	GPIO_voidSetPinValue(PORTD , PIN2 , HIGH);
	GPIO_voidSetPinValue(PORTD , PIN3 , HIGH);

	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	GIE_voidEnable();
	while(1)
	{

	}

}

/* ISR  for External interrupt 0 */
void __vector_1 (void) __attribute__((signal)) ;
void __vector_1 (void)
{
	led1 = !led1 ;
	GPIO_voidSetPinValue(PORTC , PIN0 , led1);
}

/* ISR  for External interrupt 1 */
void __vector_2 (void) __attribute__((signal)) ;
void __vector_2 (void)
{
	led2 = !led2 ;
	GPIO_voidSetPinValue(PORTC , PIN1 , led2);
}








