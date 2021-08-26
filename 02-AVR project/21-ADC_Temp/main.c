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
#include "GIE_Interface.h"

/* HAL */
#include "LCD_Interface.h"


void LCD_Control (void);
void LED_Control (void);

u8 ADC_read ;
f32 Temp_Val , Mv_value;
u8 str[10];

void main ()
{
	/* Init LCD Pins*/
	GPIO_voidSetPinDirection(PORTA , PIN0, OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN1, OUTPUT);
	GPIO_voidSetPinDirection(PORTA , PIN2, OUTPUT);
	GPIO_voidSetPortDirection(PORTD , OUTPUT);

	/* Init leds pins */
	GPIO_voidSetPinDirection(PORTC , PIN0, OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN1, OUTPUT);
	GPIO_voidSetPinDirection(PORTC , PIN2, OUTPUT);

	/*Init ADC pin */
	GPIO_voidSetPinDirection(PORTA , PIN3 , INPUT);

	ADC_voidInit();
	LCD_voidInit();
	GIE_voidEnable();
	while(1)
	{
		/* Get new raeding */
		ADC_u8GetChReadAsynch(ADC3 , LED_Control , &ADC_read);
		_delay_ms(1000);
	}

}
void Temp_cal (void)
{
	Mv_value = ((u32)ADC_read * 5000) / 256 ;
	Temp_Val = Mv_value / 10 ;
}

void LCD_Control (void)
{
	Temp_cal();
	LCD_voidSendCommand(lcd_Clear);
	sprintf(str , "T = %i" , (u32)Temp_Val );
	LCD_voidWriteString(str);
}


void LED_Control (void)
{
	Temp_cal();
	GPIO_voidSetPortValue(PORTC , LOW);
	if ( (Temp_Val < 20) )
	{
		GPIO_voidSetPinValue(PORTC  , PIN0 , HIGH);
	}
	else if ((Temp_Val < 40) && (Temp_Val > 20))
	{
		GPIO_voidSetPinValue(PORTC  , PIN1 , HIGH);
	}
	else if ((Temp_Val > 40))
	{
		GPIO_voidSetPinValue(PORTC  , PIN2 , HIGH);
	}
}














