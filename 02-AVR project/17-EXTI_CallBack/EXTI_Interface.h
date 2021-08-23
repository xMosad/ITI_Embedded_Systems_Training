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


#endif /* EXTI_INTERFACE_H_ */
