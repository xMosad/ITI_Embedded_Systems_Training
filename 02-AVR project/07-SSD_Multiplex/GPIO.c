/*
 * GPIO.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_reg.h"
#include "GPIO.h"

void GPIO_setPinValue(u8 port_id , u8 pin , u8 value)
{
	if (value == HIGH)
	{
		switch (port_id)
		{
			case PORTA :
			SET_BIT (GPIO_PORTA , pin);
			break;

			case PORTB :
			SET_BIT (GPIO_PORTB , pin);
			break;

			case PORTC :
			SET_BIT (GPIO_PORTC , pin);
			break;

			case PORTD :
			SET_BIT (GPIO_PORTD , pin);
			break;

			default:
			break;
		}
	}
	else if (value == LOW)
	{
		switch (port_id)
		{
			case PORTA :
			CLR_BIT (GPIO_PORTA , pin);
			break;

			case PORTB :
			CLR_BIT (GPIO_PORTB , pin);
			break;

			case PORTC :
			CLR_BIT (GPIO_PORTC , pin);
			break;

			case PORTD :
			CLR_BIT (GPIO_PORTD , pin);
			break;

			default:
			break;
		}
	}
	else
	{
		/* Should not be here */
	}


}

void GPIO_setPinDirection(u8 port_id , u8 pin , u8 dirc )
{
	if (dirc == OUTPUT)
	{
		switch (port_id)
		{
			case PORTA :
			SET_BIT (GPIO_DDRA , pin);
			break;

			case PORTB :
			SET_BIT (GPIO_DDRB , pin);
			break;

			case PORTC :
			SET_BIT (GPIO_DDRC , pin);
			break;

			case PORTD :
			SET_BIT (GPIO_DDRD , pin);
			break;

			default:
			break;
		}
	}
	else if (dirc == INPUT)
	{
		switch (port_id)
		{
			case PORTA :
			CLR_BIT (GPIO_DDRA , pin);
			break;

			case PORTB :
			CLR_BIT (GPIO_DDRB , pin);
			break;

			case PORTC :
			CLR_BIT (GPIO_DDRC , pin);
			break;

			case PORTD :
			CLR_BIT (GPIO_DDRD , pin);
			break;

			default:
			break;
		}
	}
	else
	{
		/* Should not be here */
	}
}

void GPIO_setPortValue(u8 port_id , u8 value)
{
	switch (port_id){
		case PORTA :
			GPIO_PORTA = value ;
			break;

		case PORTB :
			GPIO_PORTB = value ;
			break;

		case PORTC :
			GPIO_PORTC = value ;
			break;

		case PORTD :
			GPIO_PORTD = value ;
			break;

		default:
			break;
	}
}

void GPIO_setPortDirection(u8 port_id , u8 dirc)
{
	if (dirc == OUTPUT)
	{
		switch (port_id){
			case PORTA :
				GPIO_DDRA = 255;
				break;
			case PORTB :
				GPIO_DDRB = 255;
				break;
			case PORTC :
				GPIO_DDRC = 255;
				break;
			case PORTD :
				GPIO_DDRD = 255;
				break;
			default:
				break;
		}
	}
	else if (dirc == INPUT)
	{
		switch (port_id){
			case PORTA :
				GPIO_DDRA = 0;
				break;

			case PORTB :
				GPIO_DDRB = 0;
				break;

			case PORTC :
				GPIO_DDRC = 0;
				break;

			case PORTD :
				GPIO_DDRD = 0;
				break;

			default:
				break;
		}
	}
	else {

	}
}

u8 GPIO_getPinValue(u8 port_id , u8 pin)
{
	u8 value ;
	switch (port_id)
	{
		case PORTA :
		value = GET_BIT(GPIO_PINA , pin);
		break;

		case PORTB :
		value = GET_BIT(GPIO_PINB , pin);
		break;

		case PORTC :
		value = GET_BIT(GPIO_PINC , pin);
		break;

		case PORTD :
		value = GET_BIT(GPIO_PIND , pin);
		break;

		default:
		break;
	}
	return value ;
}
