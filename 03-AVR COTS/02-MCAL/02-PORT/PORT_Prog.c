/*
 * GPIO.c
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver includes */
#include "PORT_Interface.h"
#include "PORT_Private.h"
#include "PORT_Cfg.h"


void PORT_voidInit(void)
{
	/* Init pins direction */
	PORT_DDRA = PORTA_DIRECTION ;
    PORT_DDRB = PORTB_DIRECTION ;
    PORT_DDRC = PORTC_DIRECTION ;
    PORT_DDRD = PORTD_DIRECTION;
	
	/* Init pin values */
	PORT_PORTA = PORTA_INITIAL_VALUE;
    PORT_PORTB = PORTB_INITIAL_VALUE;
    PORT_PORTC = PORTC_INITIAL_VALUE;
    PORT_PORTD = PORTD_INITIAL_VALUE;


} 
