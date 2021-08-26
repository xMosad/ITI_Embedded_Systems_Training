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

void SSD_Count (void);


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
	/* Motor Control pin as output  */
	GPIO_voidSetPortDirection(PORTD , OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN1 , OUTPUT);
	TMR_voidTimer0Init();
	TMR_voidTimer0SetCallBack(SSD_Count);
	GIE_voidEnable();
	while(1)
	{


	}

}

/* 10 ms */
void SSD_Count (void)
{
	static u16 counter = 0;
	static u16 counter2 = 0;
	static u8 number = 0;
	u8 index ;
	counter++;
	counter2++;
	/*  */
	if (counter == 1)
	{
		GPIO_voidSetPinValue(PORTC , PIN0 , HIGH);
		GPIO_voidSetPinValue(PORTC , PIN1 , LOW);
		index = number % 10 ;
		GPIO_voidSetPortValue(PORTD , Arr_DecToSeg[index]);
	}
	else if (counter == 2)
	{
		counter = 0;
		GPIO_voidSetPinValue(PORTC , PIN0 , LOW);
		GPIO_voidSetPinValue(PORTC , PIN1 , HIGH);
		index = number / 10 ;
		GPIO_voidSetPortValue(PORTD , Arr_DecToSeg[index]);
	}

	/* Every 1 sec */
	if (counter2 == 100)
	{
		number++;
		counter2 = 0;
		if (number == 100){number = 0 ;}
	}
}





