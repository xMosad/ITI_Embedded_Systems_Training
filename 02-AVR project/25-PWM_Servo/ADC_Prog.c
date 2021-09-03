/*
 * ADC_V0
 *
 *  Created on: Aug 21, 2021
 *      Author: Mosad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"

void (* ADC_ISR)(void) = NULL ;
u8 * Global_AdcReadPtr = NULL ;
u8 Global_AdcState = ADC_FREE ;

void ADC_voidInit(void)
{
	/* Select ADC Ref */
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLR_BIT(ADMUX , ADMUX_REFS1);
	
	/* Left Adjust to read the high 8 bit only */
	SET_BIT(ADMUX,ADMUX_ADLAR);
	
	/* Prescaller selsction to 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	
	/* Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetChannelReading (u8 Cpy_channel)
{
	u16 local_timeOut = 0 ;
	/*** Select channel ***/
	/* Clear the 5 bits first */
	ADMUX &= ~(CLEAR_FIVE_BITS<<ADMUX_MUX0);
	/* Put channel ID in the 5 bits*/	
	ADMUX |= (Cpy_channel<<ADMUX_MUX0); 
	
	/*** Start conversion  ***/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	/*** Wait conversion  ***/
	while ((!GET_BIT(ADCSRA,ADCSRA_ADIF)) && (local_timeOut < 20000))
	{
		local_timeOut++;
	}
		
	/*** Clear complete flag  ***/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	/*** Return value   ***/
	return ADCH ;
}

u8 ADC_u8GetChReadAsynch(u8 Cpy_channel , void(*func)(void) , u8 *Cpy_read)
{
	u8 local_error = OK ;
	if ((func != NULL) &&(Cpy_read != NULL) && (Global_AdcState ==ADC_FREE) )
	{
		/* Set ISR function callback, set global reading variable */
		Global_AdcReadPtr = Cpy_read ;
		ADC_ISR = func;

		/*** Select channel ***/
		ADMUX &= ~(CLEAR_FIVE_BITS<<ADMUX_MUX0); // Clear five bits first
		ADMUX |= (Cpy_channel<<ADMUX_MUX0); // then write them

		/* Update ADC state */
		Global_AdcState = ADC_BUSY ;

		/*** Start conversion  ***/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*** Enable Interrupt  ***/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else
	{
		local_error = N_OK ;
	}
	return local_error;
}

void __vector_16 (void) __attribute__((signal)) ;
void __vector_16 (void)
{
	*Global_AdcReadPtr = ADCH ;
	Global_AdcState = ADC_FREE;
	ADC_ISR();
}
