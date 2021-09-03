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
void(* ICU_ISR)(void) = NULL ;

/****************************************************/
/********************* Timer 0 **********************/
/****************************************************/
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

/****************************************************/
/********************* Timer 1 **********************/
/****************************************************/
void TMR_voidTimer1Init(void)
{
	/* Select Mode To normal mode */
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	CLR_BIT(TCCR1A , TCCR1A_WGM11);
	CLR_BIT(TCCR1B , TCCR1B_WGM12);
	CLR_BIT(TCCR1B , TCCR1B_WGM13);

	/* Choose Prescaler to 8
	 * Every tick will take 1 us */
	CLR_BIT(TCCR1B , TCCR1B_CS10);
	SET_BIT(TCCR1B , TCCR1B_CS11);
	CLR_BIT(TCCR1B , TCCR1B_CS12);
}

void TMR_voidSetICR(u16 Cpy_val)
{
	ICR1 =Cpy_val;
}

void TMR_voidTimer1SetCompMatchA(u16 Cpy_value)
{
	OCR1A = Cpy_value;
}

void TMR_voidTimer1SetCompMatchB(u16 Cpy_value)
{
	OCR1B = Cpy_value;
}

void TMR_voidTimer1SetValue( u16 Cpy_u8Val)
{
	TCNT1 = Cpy_u8Val;
}

u16 TMR_u16GetTimer1Value( void)
{
	return TCNT1 ;
}


/****************************************************/
/********************* ISR **************************/
/****************************************************/
void __vector_10 (void) __attribute__((signal)) ;
void __vector_10 (void)
{
	OC0_ISR();
}


