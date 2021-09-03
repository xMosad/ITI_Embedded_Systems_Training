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
#include "UART_Interface.h"
#include "ADC_Interface.h"
#include "GIE_Interface.h"

void ADC_Task (void);
void rec(void);

u8 arr[10];
u8 data ;

void main ()
{
	//GPIO_voidSetPinDirection(PORTC , PIN0 , OUTPUT);
	UART_voidInit();
	ADC_voidInit();
	UART_voidSendString("Hi There");
	UART_u8RecAsynch(rec , &data);
	//GIE_voidEnable();

	while(1)
	{
		//UART_voidRecString(arr);
		//UART_voidSendString(arr);
		//ADC_Task();
	}
}


void ADC_Task (void)
{
	u8 data = ADC_u8GetChannelReading(ADC0);
	u8 arr[10];
	sprintf(arr,"R = %i" , data);
	UART_voidSendString(arr);
	UART_voidRecString(arr);
}

void rec(void)
{
	if (data == '0')
	{
		GPIO_voidSetPinValue(PORTC , PIN0 , LOW);
	}
	else if (data == '1')
	{
		GPIO_voidSetPinValue(PORTC , PIN0 , HIGH);
	}
}






