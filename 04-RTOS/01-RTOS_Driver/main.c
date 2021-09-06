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
#include "RTOS_Interface.h"

void Task1 (void);
void Task2 (void);
void Task3 (void);
void Task4 (void);

void main ()
{
	/* Pins Control pin as output  */
	GPIO_voidSetPinDirection(PORTD , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 2 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 3 , OUTPUT);


	/* Create tasks */
	RTOS_u8CreateTask(0 , 1,200 , Task1 );
	RTOS_u8CreateTask(1 , 2,400 , Task2 );
	RTOS_u8CreateTask(2 , 0,800 , Task3 );
	RTOS_u8CreateTask(3 , 3,1600 , Task4 );


	/* Strat RTOS */
	RTOS_voidStart();


	while(1)
	{
		RTOS_voidDispather();
	}

}

void Task1 (void)
{
	static u8 state = 0 ;
	state = !state ;
	GPIO_voidSetPinValue(PORTD , PIN0 , state);
}

void Task2 (void)
{
	static u8 state = 0 ;
	state = !state ;
	GPIO_voidSetPinValue(PORTD , PIN1 , state);
}

void Task3 (void)
{
	static u8 state = 0 ;
	state = !state ;
	GPIO_voidSetPinValue(PORTD , PIN2 , state);
}

void Task4 (void)
{
	static u8 state = 0 ;
	state = !state ;
	GPIO_voidSetPinValue(PORTD , PIN3 , state);
}





