/*
 * SPI
 *
 *  Created on: Aug 27, 2021
 *      Author: Mosad
 */
#ifndef TWI_INTERFACE_
#define TWI_INTERFACE_

typedef enum {
	NoError ,
	StartConditionErr,
	RepStartErr,
	AddressWriteNackErr,
	AddressReadNackErr,
	DataSlaveNackErr,
	DataRecNackErr
}TWI_ErrState_t;

#define    TWI_WRITE      0
#define    TWI_READ       1

void TWI_voidInitMaster(u8 Cpy_u8Address);
void TWI_voidInitSlave(u8 Cpy_u8Address);

TWI_ErrState_t TWI_SendStartCondition (void);
TWI_ErrState_t TWI_SendRepeatedStart (void);
TWI_ErrState_t TWI_MasterSendAdrres (u8 Cpy_u8Adress ,u8 Cpy_u8Operation);
TWI_ErrState_t TWI_MasterSendData (u8 Cpy_u8Data);
TWI_ErrState_t TWI_MasterReadDataWithAck (u8 *Cpy_u8Data);
TWI_ErrState_t TWI_MasterReadDataWithNack (u8 *Cpy_u8Data);
void TWI_SendStopCondition (void);


#endif
