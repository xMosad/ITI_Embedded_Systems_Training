/*
 * Timer
 *
 *  Created on: Aug 22, 2021
 *      Author: Mosad
 */
 
#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

void TMR_voidTimer0Init(void);
u8 TMR_voidTimer0SetCallBack(void (* func)(void) );
void TMR_voidTimer0SetCompareMatch(u8 Cpy_value);


void TMR_voidTimer1Init(void);
void TMR_voidSetICR(u16 Cpy_val);
void TMR_voidTimer1SetCompMatchA(u16 Cpy_value);
void TMR_voidTimer1SetCompMatchB(u16 Cpy_value);


/****************************************************/
/************************* ICU **********************/
/****************************************************/
#define ICU_FALLING_EDGE    0
#define ICU_RISING_EDGE     1

void ICU_voidInit();
void ICU_voidEnableInterrupt (void);
void ICU_voidDisableInterrupt (void);
u16 ICU_u16GetRead (void);
void ICU_voidSetSense (u8 Cpy_Sense);
u8 ICU_u8SetCallBack(void (* func)(void));

#endif
