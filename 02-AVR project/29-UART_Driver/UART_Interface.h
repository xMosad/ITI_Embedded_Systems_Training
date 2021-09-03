/*
 * UART
 *
 *  Created on: Aug 27, 2021
 *      Author: Mosad
 */
#ifndef UART_INTERFACE_
#define UART_INTERFACE_

void UART_voidInit(void);
void UART_voidSend(u8 Cpy_data);
u8 UART_u8Receive(void);
void UART_voidSendString (const u8 *Cpy_StrPtr);
void UART_voidRecString (u8 *Cpy_StrPtr);
u8 UART_u8RecAsynch (void (*func)(void), u8 *Cpy_DataPtr);

#endif
