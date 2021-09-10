/*
 * LCD.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */
/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"

/* Own driver include */
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Cfg.h"


void LCD_voidInit(void)
{
	_delay_ms(30);

	/* Send command function set */
	LCD_voidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(10);

	/* Send command dispaly on */
	LCD_voidSendCommand(lcd_DisplayOn);
	_delay_ms(10);

	/* Clear the display  */
	LCD_voidSendCommand(lcd_Clear);
	_delay_ms(10);

	/* Entry mode set  */
	LCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(10);

	/* Set cursor home */
	LCD_voidSendCommand(lcd_Home);
	_delay_ms(10);
}

void LCD_voidSendCommand (u8 Cpy_command )
{
	/* Reset RS and RW */
	GPIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , LOW);
	GPIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , LOW);

	/* Write the command to data port */
	GPIO_voidSetPortValue(LCD_DATA_PORT , Cpy_command);

	/* Send Enable signal */
	GPIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , HIGH);
	_delay_us(500);
	GPIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , LOW);
	_delay_us(500);
}

void LCD_voidSendChar (u8 Cpy_data)
{
	/* Reset RW */
	GPIO_voidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , LOW);

	/* Set RS */
	GPIO_voidSetPinValue(LCD_RS_PORT , LCD_RS_PIN , HIGH);

	/* Write the command to data port */
	GPIO_voidSetPortValue(LCD_DATA_PORT , Cpy_data);

	/* Send Enable signal */
	GPIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , HIGH);
	_delay_us(500);
	GPIO_voidSetPinValue(LCD_E_PORT , LCD_E_PIN , LOW);
	_delay_us(500);
}


void LCD_voidWriteString(const u8 *Cpy_str)
{
	while ( (*Cpy_str) != NULL)
	{
		LCD_voidSendChar(*Cpy_str);
		Cpy_str++;
	}
}

void LCD_voidGoTo(u8 Cpy_row , u8 Cpy_column)
{
	if ((Cpy_row>0) && (Cpy_column<=16))
	{
	    switch(Cpy_row)
	    {
		    case 1:
		    	LCD_voidSendCommand(Cpy_column+127);
		    break;

		    case 2:
		    	LCD_voidSendCommand(Cpy_column+191);
		    break;

		    default:
		    break;
	    }
	}
}

void LCD_voidAddNewPattern (u8 *Cpy_patternArray , u8 Cpy_blockNumber)
{
	u8 local_CGAdress = Cpy_blockNumber*LCD_CGRAM_BLOCKS_SIZE + LCD_CGRAM_START ;
	if (Cpy_blockNumber < LCD_CGRAM_BLOCKS_NUMBER)
	{
		LCD_voidSendCommand(local_CGAdress);
		for (u8 i = 0 ; i < LCD_CGRAM_BLOCKS_SIZE ; i++)
		{
			LCD_voidSendChar(Cpy_patternArray[i]);
		}
	}
	else
	{
		/* Error */
	}
}

void LCD_voidWritePattern (u8 Cpy_blockNumber , u8 Cpy_row , u8 Cpy_column)
{
	if (Cpy_blockNumber < LCD_CGRAM_BLOCKS_NUMBER)
	{
		LCD_voidGoTo(Cpy_row , Cpy_column);
		LCD_voidSendChar(Cpy_blockNumber);
	}
	else
	{
		/* Error */
	}
}
