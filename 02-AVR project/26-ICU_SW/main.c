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
#include "EXTI_Interface.h"

void ICU_SW (void);

u16 global_period ,global_onTime , global_finishState;

u8 period_arr[20];
u8 on_arr[20];
void main ()
{
	/* Initialize the Pins For LCD */
	GPIO_voidSetPinDirection(PORTA , 0 , OUTPUT);
	GPIO_voidSetPinDirection(PORTA ,1 , OUTPUT );
	GPIO_voidSetPinDirection(PORTA ,2 , OUTPUT );
	GPIO_voidSetPinDirection(PORTA ,3 , OUTPUT );

	TMR_voidTimer1Init();
	EXTI_voidInt0Init();
	EXTI_u8SetInt0CallBack(ICU_SW);
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

void ICU_SW (void)
{
	static u8 local_state ;
	static u16 read  ;
	//GPIO_voidSetPinValue(PORTA ,3 , HIGH);
	if (local_state == 0)
	{
		TMR_voidTimer1SetValue(0); /*Strat timer */
		local_state = 1 ;
	}

	else if (local_state == 1)
	{
		global_period = TMR_u16GetTimer1Value();

		/* set sense to falling to calculate on time */
		EXTI_voidInt0SetSenseControl(EXTI_FALLING_EDGE);

		local_state = 2 ;
	}
	else if (local_state == 2)
	{
		read = TMR_u16GetTimer1Value();
		global_onTime = read - global_period  ;
		EXTI_voidInt0DisableInterrupt();
		global_finishState = 1;
	}
	//GPIO_voidSetPinValue(PORTA ,3 , LOW);

}






