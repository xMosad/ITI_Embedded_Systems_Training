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
	/*** Select channel ***/
	/* Clear the 5 bits first */
	ADMUX &= ~(CLEAR_FIVE_BITS<<ADMUX_MUX0);
	/* Put channel ID in the 5 bits*/	
	ADMUX |= (Cpy_channel<<ADMUX_MUX0); 
	
	/*** Start conversion  ***/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	/*** Wait conversion  ***/
	while (! GET_BIT(ADCSRA,ADCSRA_ADIF));
		
	/*** Clear complete flag  ***/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	/*** Return value   ***/
	return ADCH ;
}