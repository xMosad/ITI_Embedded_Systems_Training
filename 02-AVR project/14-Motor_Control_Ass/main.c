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

/* HAL */
#include "LCD_Interface.h"

/****** Macros ******/
#define LEFT_BUTTON    3
#define RIGHT_BUTTON   2

void main ()
{
	/* Motor Control pin as output  */
	GPIO_voidSetPinDirection(PORTC , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTC , 1 , OUTPUT);

	/* Button pin as input and activate pull up */
	/* Rotate right button */
	GPIO_voidSetPinDirection(PORTC , LEFT_BUTTON , INPUT);
	GPIO_voidSetPinValue(PORTC , LEFT_BUTTON , HIGH);

	/* Rotate Left button */
	GPIO_voidSetPinDirection(PORTC , RIGHT_BUTTON , INPUT);
	GPIO_voidSetPinValue(PORTC , RIGHT_BUTTON , HIGH);

	/* Variables */
	u8 right_button_state = 0 ;
	u8 left_button_state = 0 ;

	/* Initialize LCD */
	LCD_voidInit();
	while(1)
	{
		/* Get button states */
		right_button_state = GPIO_u8GetPinValue(PORTC , RIGHT_BUTTON);
		left_button_state = GPIO_u8GetPinValue(PORTC , LEFT_BUTTON);

		if ((right_button_state == 0) && (left_button_state == 0) )
		{
			/* Write to LCD */
			LCD_voidSendCommand(lcd_Clear);
			LCD_voidWriteString("Wrong !!");

			/* Stop Motor */
			GPIO_voidSetPinValue(PORTC , 1 , LOW);
			GPIO_voidSetPinValue(PORTC , 0 , LOW);
		}
		else if (left_button_state == 0)
		{
			/* Write to LCD */
			LCD_voidSendCommand(lcd_Clear);
			LCD_voidWriteString("Left <-");

			/* Move to left */
			GPIO_voidSetPinValue(PORTC , 1 , HIGH);
			GPIO_voidSetPinValue(PORTC , 0 , LOW);
		}
		else if (right_button_state == 0)
		{
			/* Write to LCD */
			LCD_voidSendCommand(lcd_Clear);
			LCD_voidWriteString("Right ->");

			/* Move to right */
			GPIO_voidSetPinValue(PORTC , 0 , HIGH);
			GPIO_voidSetPinValue(PORTC , 1 , LOW);
		}
		else
		{

		}
		_delay_ms(200);
	}

}






