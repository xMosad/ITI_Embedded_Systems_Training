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

/* HAL */
#include "LCD_Interface.h"

/* FreeRTOS */
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"
#include "RTOS/queue.h"

/* Prototypes */
void Task1 (void *p);
void Task2 (void *p);

/* Global variables */
xQueueHandle  lcd_Queue;

void main ()
{
	/* Initialize the Pins */
	GPIO_voidSetPinDirection(PORT_A , PIN0 , OUTPUT);
	GPIO_voidSetPinDirection(PORT_A ,PIN1 , OUTPUT );
	GPIO_voidSetPinDirection(PORT_A ,PIN2 , OUTPUT );
	GPIO_voidSetPortDirection(PORT_D , OUTPUT);

	/* Init Modules */
	LCD_voidInit();

	/* Create Queue */
	lcd_Queue = xQueueCreate(5 , sizeof(u8));

	/* Create tasks */
	xTaskCreate(Task1 ,NULL , 200 , NULL , 2 , NULL );
	xTaskCreate(Task2 ,NULL , 200 , NULL , 2 , NULL );

	/* Start scheduler */
	vTaskStartScheduler();
	while(1)
	{


	}

}

void Task1 (void *p)
{
	u8 state = 'a' ;
	while (1)
	{
		xQueueSendToBack(lcd_Queue , &state , 0);
		state++;
		xQueueSendToBack(lcd_Queue , &state , 0);
		vTaskDelay(1000);

	}
}

void Task2 (void *p)
{
	u8 state , val;
	while (1)
	{
		state = xQueueReceive(lcd_Queue , &val ,0);
		if (state == pdPASS)
		{
			LCD_voidSendChar(val);
		}
		else
		{
			/* Failed to take semaphor means source is shared */
		}
	}
}






