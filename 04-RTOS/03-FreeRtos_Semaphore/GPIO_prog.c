/*
 * GPIO.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void GPIO_voidSetPinValue(u8 port_id , u8 pin , u8 value)
{
	if (value == HIGH)
	{
		switch (port_id)
		{
			case PORT_A :
			SET_BIT (GPIO_PORTA , pin);
			break;

			case PORT_B :
			SET_BIT (GPIO_PORTB , pin);
			break;

			case PORT_C :
			SET_BIT (GPIO_PORTC , pin);
			break;

			case PORT_D :
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
			case PORT_A :
			CLR_BIT (GPIO_PORTA , pin);
			break;

			case PORT_B :
			CLR_BIT (GPIO_PORTB , pin);
			break;

			case PORT_C :
			CLR_BIT (GPIO_PORTC , pin);
			break;

			case PORT_D :
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

void GPIO_voidSetPinDirection(u8 port_id , u8 pin , u8 dirc )
{
	if (dirc == OUTPUT)
	{
		switch (port_id)
		{
			case PORT_A :
			SET_BIT (GPIO_DDRA , pin);
			break;

			case PORT_B :
			SET_BIT (GPIO_DDRB , pin);
			break;

			case PORT_C :
			SET_BIT (GPIO_DDRC , pin);
			break;

			case PORT_D :
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
			case PORT_A :
			CLR_BIT (GPIO_DDRA , pin);
			break;

			case PORT_B :
			CLR_BIT (GPIO_DDRB , pin);
			break;

			case PORT_C :
			CLR_BIT (GPIO_DDRC , pin);
			break;

			case PORT_D :
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

void GPIO_voidSetPortValue(u8 port_id , u8 value)
{
	switch (port_id){
		case PORT_A :
			GPIO_PORTA = value ;
			break;

		case PORT_B :
			GPIO_PORTB = value ;
			break;

		case PORT_C :
			GPIO_PORTC = value ;
			break;

		case PORT_D :
			GPIO_PORTD = value ;
			break;

		default:
			break;
	}
}

void GPIO_voidSetPortDirection(u8 port_id , u8 dirc)
{
	if (dirc == OUTPUT)
	{
		switch (port_id){
			case PORT_A :
				GPIO_DDRA = 255;
				break;
			case PORT_B :
				GPIO_DDRB = 255;
				break;
			case PORT_C :
				GPIO_DDRC = 255;
				break;
			case PORT_D :
				GPIO_DDRD = 255;
				break;
			default:
				break;
		}
	}
	else if (dirc == INPUT)
	{
		switch (port_id){
			case PORT_A :
				GPIO_DDRA = 0;
				break;

			case PORT_B :
				GPIO_DDRB = 0;
				break;

			case PORT_C :
				GPIO_DDRC = 0;
				break;

			case PORT_D :
				GPIO_DDRD = 0;
				break;

			default:
				break;
		}
	}
	else {

	}
}

u8 GPIO_u8GetPinValue(u8 port_id , u8 pin)
{
	u8 value ;
	switch (port_id)
	{
		case PORT_A :
		value = GET_BIT(GPIO_PINA , pin);
		break;

		case PORT_B :
		value = GET_BIT(GPIO_PINB , pin);
		break;

		case PORT_C :
		value = GET_BIT(GPIO_PINC , pin);
		break;

		case PORT_D :
		value = GET_BIT(GPIO_PIND , pin);
		break;

		default:
		break;
	}
	return value ;
}
