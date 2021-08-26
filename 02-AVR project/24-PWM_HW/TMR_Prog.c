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
	/* Enable fast PWM mode*/
	SET_BIT(TCCR0 , TCCR0_WGM01);
	SET_BIT(TCCR0 , TCCR0_WGM00);
	
	/* Enable Non inverting mode */
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

	/* Select Pre scaler 1024 */
	SET_BIT(TCCR0 , TCCR0_CS00);
	CLR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);
	
}

void TMR_voidTimer0SetCompareMatch(u8 Cpy_value)
{
	OCR0 = Cpy_value;
}


u8 TMR_voidTimer0SetCallBack(void (* func)(void))
{
	u8 local_error = OK;
	if (func != NULL)
	{
		OC0_ISR = func ;
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
