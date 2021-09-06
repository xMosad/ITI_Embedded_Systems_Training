/*
 * GIE.c
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Includes */
#include "GIE_Interface.h"
#include "TMR_Interface.h"

/* Driver includes */
#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Cfg.h"

TaskControlBlock_t TaskBlocksArr[RTOS_TASK_NUM] = {{NULL}};

void RTOS_voidStart (void)
{
	/* Enable Timer and Global interrupt */
	TMR_voidTimer0Init();
	GIE_voidEnable();

	/* Pass scheduler to ISR */
	TMR_voidTimer0SetCallBack(voidScheduler);
}

u8 RTOS_u8CreateTask(u8 Cpy_u8Priority ,u16 Cpy_u16InitialDelay , u16 Cpy_u16Periodicity , void (* func)(void))
{
	u8 local_err = OK;
	if ((Cpy_u8Priority < RTOS_TASK_NUM) && (func != NULL))
	{
		TaskBlocksArr[Cpy_u8Priority].periodicity = Cpy_u16Periodicity;
		TaskBlocksArr[Cpy_u8Priority].InitialDelay = Cpy_u16InitialDelay;
		TaskBlocksArr[Cpy_u8Priority].TaskFunc = func ;
		TaskBlocksArr[Cpy_u8Priority].TaskState = RTOS_TASK_ACTIVE;
	}
	else
	{
		local_err = N_OK ;
	}
	return local_err ;
}

void RTOS_voidStopTask(u8 Cpy_u8Priority)
{
	if ((Cpy_u8Priority < RTOS_TASK_NUM) && (TaskBlocksArr[Cpy_u8Priority].TaskFunc != NULL))
	{
		TaskBlocksArr[Cpy_u8Priority].TaskState = RTOS_TASK_STOPED ;
	}
}

void RTOS_voidResumeTask(u8 Cpy_u8Priority)
{
	if ((Cpy_u8Priority < RTOS_TASK_NUM) && (TaskBlocksArr[Cpy_u8Priority].TaskFunc != NULL))
	{
		TaskBlocksArr[Cpy_u8Priority].TaskState = RTOS_TASK_ACTIVE ;
	}
}

void RTOS_voidDispather(void)
{
	/* Check on all the tasks and execute any task with RunMe flag above zero*/
	for (u8 i = 0; i < RTOS_TASK_NUM ; i++)
	{
		if ( (TaskBlocksArr[i].TaskFunc ) && (TaskBlocksArr[i].RunMe == 1))
		{
			TaskBlocksArr[i].TaskFunc();
			TaskBlocksArr[i].RunMe = 0 ;
			
		}
		else
		{
			/* Should not be here */
		}
	}
	voidSleep();
}

static void voidScheduler (void)
{
	/**  Co operative scheduling  **/
	for (u8 i = 0; i < RTOS_TASK_NUM ; i++)
	{
		if ((TaskBlocksArr[i].TaskFunc) && (TaskBlocksArr[i].TaskState == RTOS_TASK_ACTIVE))
		{	
			/* Time of the task has come */
			if ( TaskBlocksArr[i].InitialDelay == 0)
			{
				/* Dispatcher will check this flag in the while */
				TaskBlocksArr[i].RunMe = 1;
				
				/* Only if the task periodic will updated the TimerCounter */
				TaskBlocksArr[i].InitialDelay = TaskBlocksArr[i].periodicity - 1 ;
			}
			else
			{
				TaskBlocksArr[i].InitialDelay -= 1;
			}
		}
		else
		{
			/* Should not be here */
		}
	}
}


static void voidSleep (void)
{
	SET_BIT(MCUCR , MCUCR_SE);
	__asm__  __volatile__ ("SLEEP" ::);
}


