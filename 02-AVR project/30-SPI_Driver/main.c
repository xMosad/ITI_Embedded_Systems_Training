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
#include "SPI_Interface.h"

#define MASTER 1
#define SLAVE  0

#define MODE   MASTER

#if MODE == MASTER
u8 read ;
void main ()
{
	/* Init pins for SPI */
	GPIO_voidSetPinDirection(PORTB , PIN0 , OUTPUT); // Select slave 1
	GPIO_voidSetPinDirection(PORTB , PIN5 , OUTPUT); // MOSI
	GPIO_voidSetPinDirection(PORTB , PIN6 , INPUT); // MISO
	GPIO_voidSetPinDirection(PORTB , PIN7 , OUTPUT); // SCK

	/* Init pin for Button */
	GPIO_voidSetPinDirection(PORTD , PIN0 , INPUT);
	GPIO_voidSetPinValue(PORTD , PIN0 , HIGH); /* Enable Pull up */

	SPI_voidInitMaster();

	while(1)
	{
		read = GPIO_u8GetPinValue(PORTD , PIN0);
		if (read == 0)
		{
			SPI_u8Transceive('0');
		}
		else if (read == 1)
		{
			SPI_u8Transceive('1');
		}
		_delay_ms(200);
	}
}

#elif MODE == SLAVE
u8 read;
void main ()
{
	/* Init pins for SPI */
	GPIO_voidSetPinDirection(PORTB , PIN4 , INPUT); //SS
	GPIO_voidSetPinDirection(PORTB , PIN5 , INPUT); // MOSI
	GPIO_voidSetPinDirection(PORTB , PIN6 , OUTPUT); // MISO
	GPIO_voidSetPinDirection(PORTB , PIN7 , INPUT); // SCK

	/* Init pin for LED */
	GPIO_voidSetPinDirection(PORTD , PIN0 , OUTPUT);

	SPI_voidInitSlave();

	while(1)
	{
		read = SPI_u8Transceive(0xff);
		if (read == '0')
		{
			GPIO_voidSetPinValue(PORTD , PIN0 , HIGH);
		}
		else if (read == '1')
		{
			GPIO_voidSetPinValue(PORTD , PIN0 , LOW);
		}
	}
}

#endif




