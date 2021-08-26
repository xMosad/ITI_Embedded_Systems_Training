/*
 * main.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "stdio.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "ADC_Interface.h"

/* HAL */
#include "LCD_Interface.h"

f32 read ;
u32 temp  ;
u8 str[20];
u8 str2[20];
void main ()
{
	/* Init LCD Pins*/
	GPIO_voidSetPinDirection(PORTA , PIN0, OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN1, OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN2, OUTPUT);
	GPIO_voidSetPortDirection(PORTD , OUTPUT);

	/*Init ADC pin */
	GPIO_voidSetPinDirection(PORTA , PIN3 , INPUT);
	ADC_voidInit();
	LCD_voidInit();
	while(1)
	{
		/* Get new raeding */
		read = ADC_u8GetChannelReading(ADC3);
		read = (read * 5.0) / 256.0 ;

		/* Clear screen  */
		LCD_voidSendCommand(lcd_Clear);
		/* Get the float as two numbers to print */
		temp = (u32)(read * 100 ) % 100;
		sprintf(str , "v = %i." , (u32)read );
		sprintf(str2 , "%i" , temp );

		/* Print the value */
		LCD_voidWriteString(str);
		LCD_voidWriteString(str2);
		_delay_ms(1000);
	}

}















