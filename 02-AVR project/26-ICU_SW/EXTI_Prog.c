/*
+ * EXTI.c
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

/* Global */
void(* INT0_ISR)(void) = NULL ;
void(* INT1_ISR)(void) = NULL ;
void(* INT2_ISR)(void) = NULL ;


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

void EXTI_voidInt0SetSenseControl(u8 Cpy_u8SenseVal)
{
	switch (Cpy_u8SenseVal)
	{
		case EXTI_LOW_LEVEL :
			CLR_BIT(MCUCR , MCUCR_ISC00);
			CLR_BIT(MCUCR , MCUCR_ISC01);
			break;

		case EXTI_ON_CHANGE :
			SET_BIT(MCUCR , MCUCR_ISC00);
			CLR_BIT(MCUCR , MCUCR_ISC01);
			break;

		case EXTI_FALLING_EDGE :
			CLR_BIT(MCUCR , MCUCR_ISC00);
			SET_BIT(MCUCR , MCUCR_ISC01);
			break;

		case EXTI_RISING_EDGE :
			SET_BIT(MCUCR , MCUCR_ISC00);
			SET_BIT(MCUCR , MCUCR_ISC01);
			break;

		default : break ;
	}
}

void EXTI_voidInt0DisableInterrupt(void)
{
	CLR_BIT(GICR , GICR_INT0);
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


u8 EXTI_u8SetInt0CallBack (void(* func)(void))
{
	u8 Local_error = OK ;
	if (func != NULL)
	{
		INT0_ISR = func ;
	}
	else 
	{
		Local_error = N_OK;
	}
	return Local_error ;
}

u8 EXTI_u8SetInt1CallBack (void(* func)(void))
{
	u8 Local_error = OK ;
	if (func != NULL)
	{
		INT1_ISR = func ;
	}
	else 
	{
		Local_error = N_OK;
	}
	return Local_error ;
}

u8 EXTI_u8SetInt2CallBack (void(* func)(void))
{
	u8 Local_error = OK ;
	if (func != NULL)
	{
		INT2_ISR = func ;
	}
	else 
	{
		Local_error = N_OK;
	}
	return Local_error ;
}


/* ISR  for External interrupt 0 */
void __vector_1 (void) __attribute__((signal)) ;
void __vector_1 (void)
{
	INT0_ISR();
}

/* ISR  for External interrupt 1 */
void __vector_2 (void) __attribute__((signal)) ;
void __vector_2 (void)
{
	INT1_ISR();
}

/* ISR  for External interrupt 2 */
void __vector_3 (void) __attribute__((signal)) ;
void __vector_3 (void)
{
	INT2_ISR();
}



