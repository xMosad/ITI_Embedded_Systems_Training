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
#include "RTOS/semphr.h"

/* Prototypes */
void Task1 (void *p);
void Task2 (void *p);

/* Global variables */
xSemaphoreHandle  lcd_smph;

void main ()
{
	/* Initialize the Pins */
	GPIO_voidSetPinDirection(PORT_A , PIN0 , OUTPUT);
	GPIO_voidSetPinDirection(PORT_A ,PIN1 , OUTPUT );
	GPIO_voidSetPinDirection(PORT_A ,PIN2 , OUTPUT );
	GPIO_voidSetPortDirection(PORT_D , OUTPUT);

	/* Init Modules */
	LCD_voidInit();

	/* Create semaphore */
	lcd_smph = xSemaphoreCreateCounting(1 ,  /* To make it binary semaphore */
										1);  /* To make it initialy available */

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
	u8 state ;
	while (1)
	{
		state = xSemaphoreTake(lcd_smph,0);
		if (state == pdPASS)
		{
			LCD_voidWriteString("Task1");
			/* Give the semaphore */
			xSemaphoreGive(lcd_smph);
		}
		else
		{
			/* Failed to take semaphor means source is shared */
		}
		vTaskDelay(1000);
	}
}

void Task2 (void *p)
{
	u8 state ;
	while (1)
	{
		state = xSemaphoreTake(lcd_smph,0);
		if (state == pdPASS)
		{
			LCD_voidWriteString("Task2");
			xSemaphoreGive(lcd_smph);
		}
		else
		{
			/* Failed to take semaphor means source is shared */
		}
		vTaskDelay(1000);
	}
}






