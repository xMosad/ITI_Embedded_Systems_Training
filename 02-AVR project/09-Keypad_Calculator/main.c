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
#include <stdio.h>

/* HAL */
#include "LCD_Interface.h"
#include "KPD_Interface.h"

/******************************************************************************
* Global variables
*******************************************************************************/
u8 global_u8Num1 , global_u8Num2 , global_u8Operation;
s8 global_u8Sum;
u8 global_u8WrongFlag ;
u8 global_u8StrArr[10];

void main ()
{

	/* Init HAL modules */
	LCD_voidInit();
	KPD_voidInitPins();

	while(1)
	{
		/* Clear screen at the start of every operation */
		LCD_voidSendCommand(lcd_Clear);

		/************** To Enter first operand ******************/

		/* Wait till button is pressed */
		while (global_u8Num1 == 0)
		{
			global_u8Num1 = KPD_u8GetPressedKey();
		}

		/* Print the number on screen first */
		LCD_voidSendChar(global_u8Num1);

		/* Then convert from Ascii to integer */
		global_u8Num1 -= 48 ;


		/********************* To Enter Operation ****************/
		while (global_u8Operation == 0)
		{
			global_u8Operation = KPD_u8GetPressedKey();
		}
		LCD_voidSendChar(global_u8Operation);


		/********************** To Enter second operand *************/

		/* Wait till button is pressed */
		while (global_u8Num2 == 0)
		{
			global_u8Num2 = KPD_u8GetPressedKey();
		}

		/* Print the number on screen first */
		LCD_voidSendChar(global_u8Num2);

		/* Then convert from Ascii to integer */
		global_u8Num2 -= 48 ;



		/****************** Wait to enter equal *********************/
		while ('=' != KPD_u8GetPressedKey());


		/****************** Calculate Answer ************************/
		switch (global_u8Operation)
		{
			case '+' : global_u8Sum = global_u8Num1 + global_u8Num2; break ;
			case '-' : global_u8Sum = global_u8Num1 - global_u8Num2; break ;
			case '*' : global_u8Sum = global_u8Num1 * global_u8Num2; break ;
			case '/' :
				if (global_u8Num2 == 0)
				{
					global_u8WrongFlag = 1 ;
				}
				else
				{
					global_u8Sum = global_u8Num1 / global_u8Num2;
				}
				break ;
		}


		/******************* Print the result ********************/
		LCD_voidGoTo(2 , 6);   /* Move to second line */

		/* Check for any operation errors */
		if (global_u8WrongFlag == 0)
		{
			/* View answer */
			LCD_voidWriteString("Result = ");
			/* Convert to string */
			sprintf(global_u8StrArr , "%d", global_u8Sum);
			LCD_voidWriteString(global_u8StrArr);
		}
		else
		{
			LCD_voidWriteString("Error !!!");
		}

		/****************** Re init variables ***************/
		global_u8Num1 = 0 ;
		global_u8Num2 = 0 ;
		global_u8Operation = 0 ;

		/********* Wait User to enter any key to start new operation  ******/
		while ( ! (KPD_u8GetPressedKey()) );

	}

}






