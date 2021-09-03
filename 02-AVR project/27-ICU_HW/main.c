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
#include "stdio.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "TMR_Interface.h"

void ICU_CallBack (void);

u16 global_period ,global_onTime , global_finishState;

u8 period_arr[20];
u8 on_arr[20];
void main ()
{
	/* Initialize the Pins */
	GPIO_voidSetPinDirection(PORTA , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTA ,1 , OUTPUT );
	GPIO_voidSetPinDirection(PORTA ,2 , OUTPUT );
	GPIO_voidSetPinDirection(PORTA ,3 , OUTPUT );
	GPIO_voidSetPortDirection(PORTC , OUTPUT);

	ICU_voidInit();
	ICU_u8SetCallBack(ICU_CallBack);
	GIE_voidEnable();
	LCD_voidInit();
	while(1)
	{
		if (global_finishState != 0)
		{
			LCD_voidGoTo(1 , 1);
			sprintf(period_arr , "Period= %i us" , (global_period));
			LCD_voidWriteString(period_arr);

			LCD_voidGoTo(2 , 1);
			sprintf(on_arr , "OnT= %i us" , (global_onTime));
			LCD_voidWriteString(on_arr);
			global_finishState = 0 ;
		}
	}

}

void ICU_CallBack (void)
{
	static u8 local_state ;
	static u16 read1 , read2 ,read3 ;
	GPIO_voidSetPinValue(PORTA ,3 , HIGH);
	if (local_state == 0)
	{
		read1 = ICU_u16GetRead();
		local_state = 1 ;
	}

	else if (local_state == 1)
	{
		read2 = ICU_u16GetRead();
		global_period = read2 - read1 ;

		/* set sense to falling to calculate on time */
		ICU_voidSetSense(ICU_FALLING_EDGE);

		local_state = 2 ;
	}
	else if (local_state == 2)
	{
		read3 = ICU_u16GetRead();
		global_onTime = read3 - read2 ;
		ICU_voidDisableInterrupt();
		global_finishState = 1;
	}
	GPIO_voidSetPinValue(PORTA ,3 , LOW);

}






