/*
 * EXTI.c
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver includes */
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Cfg.h"


void EXTI_voidInt0Init(void)
{
	/* Init Sense Control */
	#if EXTI_INT0_SENSE_CONTROL   == LOW_LEVEL 
		CLR_BIT(MCUCR , MCUCR_ISC00);
		CLR_BIT(MCUCR , MCUCR_ISC01);
		
	#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE 
		SET_BIT(MCUCR , MCUCR_ISC00);
		CLR_BIT(MCUCR , MCUCR_ISC01);
			
	#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
		CLR_BIT(MCUCR , MCUCR_ISC00);
		SET_BIT(MCUCR , MCUCR_ISC01);
		
	#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE 
		SET_BIT(MCUCR , MCUCR_ISC00);
		SET_BIT(MCUCR , MCUCR_ISC01);
		
	#else 
		#warning (" Wrong Configuration !!")

	#endif
	
	/* Init initial interrupt state */
	#if EXTI_INT0_INITIAL_STATE   == ENABLE
		SET_BIT(GICR , GICR_INT0);
		
	#elif EXTI_INT0_INITIAL_STATE == DISABLE
		CLR_BIT(GICR , GICR_INT0);
		
	#else 
		#warning (" Wrong Configuration !!")
	#endif
}

void EXTI_voidInt1Init(void)
{
	/* Init Sense Control */
	#if EXTI_INT1_SENSE_CONTROL   == LOW_LEVEL 
		CLR_BIT(MCUCR , MCUCR_ISC10);
		CLR_BIT(MCUCR , MCUCR_ISC11);
		
	#elif EXTI_INT1_SENSE_CONTROL == ON_CHANGE 
		SET_BIT(MCUCR , MCUCR_ISC10);
		CLR_BIT(MCUCR , MCUCR_ISC11);
			
	#elif EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
		CLR_BIT(MCUCR , MCUCR_ISC10);
		SET_BIT(MCUCR , MCUCR_ISC11);
		
	#elif EXTI_INT1_SENSE_CONTROL == RISING_EDGE 
		SET_BIT(MCUCR , MCUCR_ISC10);
		SET_BIT(MCUCR , MCUCR_ISC11);
		
	#else 
		#warning (" Wrong Configuration !!")
	
	#endif

	/* Init initial interrupt state */
	#if EXTI_INT1_INITIAL_STATE   == ENABLE
		SET_BIT(GICR , GICR_INT1);
		
	#elif EXTI_INT1_INITIAL_STATE == DISABLE
		CLR_BIT(GICR , GICR_INT1);
	#else 
		#warning (" Wrong Configuration !!")
	#endif
}

void EXTI_voidInt2Init(void)
{
	/* Init Sense Control */			
	#if EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
		CLR_BIT(MCUCSR , MCUCSR_ISC2);
		
	#elif EXTI_INT2_SENSE_CONTROL == RISING_EDGE 
		SET_BIT(MCUCSR , MCUCSR_ISC2);
		
	#else 
		#warning (" Wrong Configuration !!")
	#endif
	
	/* Init initial interrupt state */
	#if EXTI_INT2_INITIAL_STATE   == ENABLE
		SET_BIT(GICR , GICR_INT2);
		
	#elif EXTI_INT2_INITIAL_STATE == DISABLE
		CLR_BIT(GICR , GICR_INT2);
		
	#else 
		#warning (" Wrong Configuration !!")
	#endif
}



