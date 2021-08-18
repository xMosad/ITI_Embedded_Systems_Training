/*
 * KPD_Cfg.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Mosad
 */

#ifndef KPD_CFG_H_
#define KPD_CFG_H_

/**************************** Macros ****************************
 ****************************************************************/
#define   ROWS_NUMBER       4
#define   COLUMNS_NUMBER    4

/**************************** Variables **************************
 ****************************************************************/

/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_SwitchVal[ROWS_NUMBER][COLUMNS_NUMBER] = {
	  {'7' , '8' , '9' , '/' } ,
	  {'4' , '5' , '6' , '*' } ,
	  {'1' , '2' , '3' , '-' } ,
	  {'o' , '0' , '=' , '+' }
};

const u8 KPD_rowPort [ROWS_NUMBER]     = {PORTC , PORTC , PORTC , PORTC};
const u8 KPD_rowPins [ROWS_NUMBER]     = {PIN0 , PIN1 , PIN2 , PIN3};
const u8 KPD_coloumsPort [COLUMNS_NUMBER] = {PORTC , PORTC , PORTC , PORTC};
const u8 KPD_coloumsPins [COLUMNS_NUMBER] = {PIN4 , PIN5 , PIN6 , PIN7};

#endif /* KPD_CFG_H_ */
