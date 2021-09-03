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
#include "TWI_Interface.h"

/* HAL */
#include "EEP_Interface.h"

u8 val[5] = {};
void main ()
{
	u8 x ;
	/* Init pins for I2C */
	TWI_voidInitMaster(0);
	EEP_ReadBlock(0x01 , val , 3);
	EEP_WriteBlock(0xfa , val , 3);
	_delay_ms(20);
	EEP_WriteByte(0x01 , 8 );
	_delay_ms(20);
	EEP_ReadByte(0x01 , &x );
	_delay_ms(20);
	EEP_WriteByte(0x02 , 8 );
	while(1)
	{

	}
}










