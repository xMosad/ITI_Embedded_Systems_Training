/*
 * GPIO_reg.h
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

u8 EXTI_u8SetInt0CallBack (void(* func)(void));
u8 EXTI_u8SetInt1CallBack (void(* func)(void));
u8 EXTI_u8SetInt2CallBack (void(* func)(void));


#define     EXTI_LOW_LEVEL       0
#define     EXTI_ON_CHANGE       1
#define     EXTI_FALLING_EDGE    2
#define     EXTI_RISING_EDGE     3
void EXTI_voidInt0SetSenseControl(u8 Cpy_u8SenseVal);
void EXTI_voidInt0DisableInterrupt(void);

#endif /* EXTI_INTERFACE_H_ */
