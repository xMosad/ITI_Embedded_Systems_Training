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

/* Following This Table we creat array To convert Decimal to 7Segment */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    1    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 | */
/*    2    |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | */
/*    3    |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | */
/*    4    |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 | */
/*    5    |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 | */
/*    6    |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 | */
/*    7    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | */
/*    8    |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    9    |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | */
/***********************************************/

u8 Arr_DecToSeg[10] = {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };
void main ()
{
	/* Initialize portd as output */
	DDRD = 0xff ;
	while(1)
	{
		/*  */
		for(u8 LoopCounter=0; LoopCounter<10;LoopCounter++)
		{
			PORTD = Arr_DecToSeg[LoopCounter];
			_delay_ms(500);
		}

	}

}
