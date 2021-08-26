/*
 * Timer
 *
 *  Created on: Aug 22, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Own driver includes */
#include "TMR_Interface.h"
#include "TMR_Private.h"
#include "TMR_Cfg.h"

void(* OC0_ISR)(void) = NULL ;


void TMR_voidTimer0Init(void)
{
	/* Enable CTC mode*/
	SET_BIT(TCCR0 , TCCR0_WGM01);
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	
	/* Init OCR0  With f = 8 MHZ , PS = 256*/
	OCR0 = 125 ;
	
	/* Select Pre scaler */
	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLR_BIT(TCCR0 , TCCR0_CS02);
}
u8 TMR_voidTimer0SetCallBack(void (* func)(void))
{
	u8 local_error = OK;
	if (func != NULL)
	{
		OC0_ISR = func ;
		/*Enable Time Interrupt */
		SET_BIT(TIMSK , TIMSK_OCIE0);
	}
	else 
	{
		local_error = N_OK;
	}
	return local_error ;
}

void __vector_10 (void) __attribute__((signal)) ;
void __vector_10 (void)
{
	OC0_ISR();
}
