/*
 * GIE
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */

#ifndef RTOS_PRIAVTE_H_
#define RTOS_PRIAVTE_H_


#define MCUCR  (*((volatile u8 *)0x55))
#define MCUCR_SE   7

typedef struct 
{
	u16 periodicity ;
	u16 InitialDelay ;
	void (*TaskFunc)(void);
	u8 RunMe ;
	u8 TaskState;
}TaskControlBlock_t;

static void voidScheduler (void);
static void voidSleep (void);


#endif
