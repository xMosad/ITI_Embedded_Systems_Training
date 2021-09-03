/*
 * UART
 *
 *  Created on: Aug 27, 2021
 *      Author: Mosad
 */
/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Own drive includes */
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Cfg.h"


void (* UART_RecIntCallBack)(void) = NULL ;
u8 *UART_DataPtr ;

void UART_voidInit(void)
{
	/* Enable RX and TX */
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);
	
	/* Set to 8 bit mode 
	 * No parity 
 	 * One stop bit */
	UCSRC = 0b10000110  ;
	
	/* Set buad rate to 9600 */
	UBRRL = 51 ;
}


void UART_voidSend(u8 Cpy_data)
{
	while (GET_BIT(UCSRA , UCSRA_UDRE) == 0);
	UDR = Cpy_data ;
}

u8 UART_u8Receive(void)
{
	while (GET_BIT(UCSRA , UCSRA_RXC) == 0);
	return UDR ;
}

void UART_voidSendString (const u8 *Cpy_StrPtr)
{
	while (*Cpy_StrPtr != NULL)
	{
		UART_voidSend(*Cpy_StrPtr);
		Cpy_StrPtr++;
	}
}

void UART_voidRecString (u8 *Cpy_StrPtr)
{
	do
	{
		*Cpy_StrPtr = UART_u8Receive();
		Cpy_StrPtr++;
	}while (*(Cpy_StrPtr-1) != '\r');
	*(Cpy_StrPtr-1) = NULL;
}


u8 UART_u8RecAsynch (void (*func)(void), u8 *Cpy_DataPtr)
{
	u8 local_error = OK ;
	if ((func != NULL) && (Cpy_DataPtr != NULL))
	{
		UART_RecIntCallBack = func ;
		UART_DataPtr = Cpy_DataPtr;
	}
	else
	{
		local_error = N_OK;
	}

	/* Enable interrupt */
	SET_BIT(UCSRB ,UCSRB_RXCIE);
}

void __vector_13 (void) __attribute__((signal)) ;
void __vector_13 (void)
{
	if (UART_RecIntCallBack != NULL)
	{
		*UART_DataPtr = UDR ;
		UART_RecIntCallBack();
	}
}
