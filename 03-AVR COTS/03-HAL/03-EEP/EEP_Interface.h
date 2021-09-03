/*
 * GIE
 *
 *  Created on: Septemper 1, 2021
 *      Author: Mosad
 */ 
#ifndef EEP_INTERFACE_H_
#define EEP_INTERFACE_H_

 
void EEP_WriteByte (u8 address , u8 value );
void EEP_ReadByte (u8 address , u8 *value );
void EEP_WriteBlock (u8 address , u8 *arr , u8 size );
void EEP_ReadBlock (u8 address , u8 *arr , u8 size);




#endif
