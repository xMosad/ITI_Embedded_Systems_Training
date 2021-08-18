/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mosad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"

#define F_CPU 8000000
#include "util/delay.h"

#define LED_BLINK        0
#define LED_SHIFT_LEFT   1
#define LED_SHIFT_RIGHT  2
#define LED_CONVERGING   3
#define LED_DIVERFING    4
#define LED_PING_PONG    5
#define LED_SNAKE        6
#define LED_CONV_DIV     7

u8 switch_state ;
s8 right =4 ,left =3;
s8 first =0 ,last =7;
s8 snake_c ;
void main ()
{
	/* Set PORTD as output */
	DDRD   = 0xff;

	/* Set A0,A1,A2 as input */
	CLR_BIT(DDRA , 0);
	CLR_BIT(DDRA , 1);
	CLR_BIT(DDRA , 2);
	while(1)
	{
		switch_state = GET_BIT(PINA , 0 ) |
				       (GET_BIT(PINA , 1 ) << 1 )|
					   (GET_BIT(PINA , 2 ) << 2);

		switch (switch_state)
		{
			case LED_BLINK       :
				PORTD = ~PORTD;
				_delay_ms(300);
				break;

			case  LED_SHIFT_RIGHT:
				for(u8 i = 0 ; i < 8 ; i++)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , i);
					_delay_ms(250);
				}
				break;

			case LED_SHIFT_LEFT :
				for(s8 i = 7 ; i >= 0 ; i--)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , i);
					_delay_ms(250);
				}
				break;

			case LED_CONVERGING  :
				PORTD = 0 ;
				_delay_ms(300);
				for(u8 i = 0 ; i < 4 ; i++)
				{
					SET_BIT(PORTD , first);
					SET_BIT(PORTD , last);
					last --;
					first++;
					_delay_ms(300);
				}
				first = 0 ;
				last = 7 ;
				break;


			case LED_DIVERFING   :
				PORTD = 0 ;
				_delay_ms(300);
				for(u8 i = 0 ; i < 4 ; i++)
				{
					SET_BIT(PORTD , right);
					SET_BIT(PORTD , left);
					left --;
					right++;
					_delay_ms(300);
				}
				right = 4 ;
				left = 3 ;
				break;

			case LED_PING_PONG   :
				for(u8 i = 0 ; i < 8 ; i++)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , i);
					_delay_ms(250);
				}
				for(s8 i = 7 ; i >= 0 ; i--)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , i);
					_delay_ms(250);
				}

				break;

			case LED_SNAKE       :
				PORTD = 0 ;
				for(u8 i = 0 ; i < 8 ; i++)
				{
					SET_BIT(PORTD , i);
					_delay_ms(300);
				}
				break;


			case LED_CONV_DIV    :
				for(u8 i = 0 ; i < 4 ; i++)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , first);
					SET_BIT(PORTD , last);
					last --;
					first++;
					_delay_ms(300);
				}
				for(u8 i = 0 ; i < 4 ; i++)
				{
					PORTD = 0 ;
					SET_BIT(PORTD , right);
					SET_BIT(PORTD , left);
					left --;
					right++;
					_delay_ms(300);
				}
				right = 4 ;
				left = 3 ;
				first = 0 ;
				last = 7 ;

				break;
		}

	}

}




