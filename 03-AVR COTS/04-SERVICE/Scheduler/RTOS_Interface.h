/*
 * GIE
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */ 
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


#define    RTOS_TASK_STOPED   0
#define    RTOS_TASK_ACTIVE   1

void RTOS_voidStart (void);
u8 RTOS_u8CreateTask(u8 Cpy_u8Priority ,u16 Cpy_u16InitialDelay , u16 Cpy_u16Periodicity , void (* func)(void));
void RTOS_voidStopTask(u8 Cpy_u8Priority);
void RTOS_voidResumeTask(u8 Cpy_u8Priority);

void RTOS_voidDispather(void);


#endif
