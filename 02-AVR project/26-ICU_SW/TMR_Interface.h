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

/****************************************************/
/********************* Timer1 **********************/
/****************************************************/
void TMR_voidTimer1Init(void);
void TMR_voidSetICR(u16 Cpy_val);
void TMR_voidTimer1SetCompMatchA(u16 Cpy_value);
void TMR_voidTimer1SetCompMatchB(u16 Cpy_value);
void TMR_voidTimer1SetValue( u16 Cpy_u8Val);
u16 TMR_u16GetTimer1Value(void);


#endif
