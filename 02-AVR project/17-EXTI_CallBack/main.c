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

void INT1_interrupt (void) ;

volatile u8 state  ;
u8 value = 0 ;
u8 swap = 1 ;
void main ()
{
	/* Init pins */
	GPIO_voidSetPortDirection(PORTC , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , PIN3 , INPUT);
	/* Enable pull up for buttons */
	GPIO_voidSetPinValue(PORTD , PIN3 , HIGH);

	EXTI_voidInt1Init();
	EXTI_u8SetInt1CallBack(INT1_interrupt);
	GIE_voidEnable();
	while(1)
	{
		switch (state)
		{
			case 0 :
				GPIO_voidSetPortValue(PORTC , value);
				value = ~value;
				break ;
			case 1 :
				GPIO_voidSetPortValue(PORTC ,swap );
				swap *=2;
				if(swap == 0)
				{
					swap = 1 ;
				}
				break ;
		}
		_delay_ms(500);
	}

}


void INT1_interrupt (void)
{
	state = !state ;
}












