/*
 * main.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"

/* FreeRTOS */
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"

void Task1 (void *p);
void Task2 (void *p);
void Task3 (void *p);
void Task4 (void *p);

void main ()
{
	GPIO_voidSetPortDirection(PORT_D , OUTPUT);

	xTaskCreate(Task1  /* Function address */
				, NULL /* Function Name Null because we dont want it  */
				, 100 /* Stack depth */
				, NULL /* Pointer to void, will be passed to the task */
				, 1  /* Priority */
				, NULL); /* Handle task used with other funcions like delete task */

	xTaskCreate(Task2  /* Function address */
					, NULL /* Function Name Null because we dont want it  */
					, 100 /* Stack depth */
					, NULL /* Pointer to void, will be passed to the task */
					, 0  /* Priority */
					, NULL); /* Handle task used with other funcions like delete task */

	xTaskCreate(Task3  /* Function address */
					, NULL /* Function Name Null because we dont want it  */
					, 100 /* Stack depth */
					, NULL /* Pointer to void, will be passed to the task */
					, 0  /* Priority */
					, NULL); /* Handle task used with other funcions like delete task */

	xTaskCreate(Task4  /* Function address */
					, NULL /* Function Name Null because we dont want it  */
					, 100 /* Stack depth */
					, NULL /* Pointer to void, will be passed to the task */
					, 0  /* Priority */
					, NULL); /* Handle task used with other funcions like delete task */


	vTaskStartScheduler();




	/*****/
	while(1)
	{


	}

}

void Task1 (void *p)
{
	u8 state = 0 ;
	while (1)
	{
		GPIO_voidSetPinValue(PORT_D , PIN0 , state);
		vTaskDelay( pdMS_TO_TICKS(200) ); /* Delay for how many tick */
		state = !state ;
	}

}

void Task2 (void *p)
{
	u8 state = 0 ;
	while (1)
	{
		GPIO_voidSetPinValue(PORT_D , PIN1 , state);
		vTaskDelay(400);
		state = !state ;
	}
}

void Task3 (void *p)
{
	u8 state = 0 ;
	while (1)
	{
		GPIO_voidSetPinValue(PORT_D , PIN2 , state);
		vTaskDelay(800);
		state = !state ;
	}
}

void Task4 (void *p)
{
	u8 state = 0 ;
	while (1)
	{
		GPIO_voidSetPinValue(PORT_D , PIN3 , state);
		vTaskDelay(1600);
		state = !state ;
	}
}




