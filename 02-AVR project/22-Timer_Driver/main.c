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

void Toggle_Led (void);
volatile u8 led1 , led2 , led3 ,led4 = 0 ;
void main ()
{
	/* Motor Control pin as output  */
	GPIO_voidSetPinDirection(PORTD , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 1 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 2 , OUTPUT);
	GPIO_voidSetPinDirection(PORTD , 3 , OUTPUT);
	GIE_voidEnable();
	TMR_voidTimer0Init();
	TMR_voidTimer0SetCallBack(Toggle_Led);
	while(1)
	{


	}

}

void Toggle_Led (void)
{
	static u16 counter1 = 0;
	static u16 counter2= 0;
	static u16 counter3= 0;
	static u16 counter4= 0;
	counter1++;
	counter2++;
	counter3++;
	counter4++;
	/* Toggle led every 800 ms */
	if (counter1 == 100)
	{
		counter1 = 0 ;
		led1 = !led1 ;
		GPIO_voidSetPinValue(PORTD , 0 , led1);
	}
	/* Toggle led every 640 ms */
	if (counter2 == 80)
	{
		counter2 = 0 ;
		led2 = !led2 ;
		GPIO_voidSetPinValue(PORTD , 1 , led2);
	}

	/* Toggle led every 320 ms */
	if (counter3 == 40)
	{
		counter3 = 0 ;
		led3 = !led3 ;
		GPIO_voidSetPinValue(PORTD , 2 , led3);
	}

	/* Toggle led every 160 ms */
	if (counter4 == 20)
	{
		counter4 = 0 ;
		led4 = !led4 ;
		GPIO_voidSetPinValue(PORTD , 3 , led4);
	}
}





