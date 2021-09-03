/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mosad
 */

/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"

/* MCAL */
#include "GPIO_Interface.h"
#include "TMR_Interface.h"
#include "ADC_Interface.h"

void Servo_Control (void);

void main ()
{
	GPIO_voidSetPinDirection(PORTD , PIN4 , HIGH);
	GPIO_voidSetPinDirection(PORTD , PIN5 , HIGH);
	TMR_voidTimer1Init();
	TMR_voidSetICR(20000); /* To generate pulse every 20 ms*/
	ADC_voidInit();
	while(1)
	{
		/*for (u16 i = 1000 ; i <= 2000 ; i+=10)
		{
			TMR_voidTimer1SetCompMatchA(i);
			_delay_ms(100);
		}*/
		Servo_Control();
	}

}




s32 map (s32 Cpy_InputMini , s32 Cpy_InputMax , s32 Cpy_OutMini , s32 Cpy_OutMax ,  s32 Cpy_val)
{
	s32 local_holder = Cpy_val - Cpy_InputMax ;
	local_holder *= (Cpy_OutMini - Cpy_OutMax);
	local_holder /= (Cpy_InputMini - Cpy_InputMax);
	local_holder += Cpy_OutMax ;
	return local_holder;
}

void Servo_Control (void)
{
	/* Read Pot first */
	u8 adc_read = ADC_u8GetChannelReading(ADC0);

	/* Map the value to Generate needed PWM*/
	s32 servo_pwm = map(0 , 255 , 1000 , 2000 , adc_read);

	/* Generate the pulse */
	TMR_voidTimer1SetCompMatchA(servo_pwm);
}









