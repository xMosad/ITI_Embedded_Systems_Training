/*
 * GIE.c
 *
 *  Created on: Septemper 1, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Includes */
#include "TWI_Interface.h"

/* Driver includes */
#include "EEP_Interface.h"
#include "EEP_Private.h"
#include "EEP_Cfg.h"

void EEP_WriteByte (u8 address , u8 value )
{
	/* Send start */
	TWI_SendStartCondition();
	/* Send SLA + W */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_WRITE);
	/* Send address you want to write to  */
	TWI_MasterSendData(address);
	/* Send data you want to write to  */
	TWI_MasterSendData(value);
	/* Send stop */
	TWI_SendStopCondition();
}

void EEP_WriteBlock (u8 address , u8 *arr , u8 size )
{
	/* Send start */
	TWI_SendStartCondition();
	/* Send SLA + W */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_WRITE);
	/* Send address you want to write to  */
	TWI_MasterSendData(address);
	/* Send data you want to write to  */
	for (u8 i = 0 ; i < size ; i++)
	{
		TWI_MasterSendData(arr[i]);
	}
	/* Send stop */
	TWI_SendStopCondition();
}

void EEP_ReadByte (u8 address , u8 *value )
{
	/* Send start */
	TWI_SendStartCondition();
	/* Send SLA + W */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_WRITE);
	/* Send address you want to read from  */
	TWI_MasterSendData(address);
	/* Send repeated start */
	TWI_SendStartCondition();
	/* Send SLA + R */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_READ);
	/* Read data */
	TWI_MasterReadDataWithNack(value);
	/* Send stop */
	TWI_SendStopCondition();
}

void EEP_ReadBlock (u8 address , u8 *arr , u8 size)
{
	/* Send start */
	TWI_SendStartCondition();
	/* Send SLA + W */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_WRITE);
	/* Send address you want to read from  */
	TWI_MasterSendData(address);
	/* Send repeated start */
	TWI_SendStartCondition();
	/* Send SLA + R */
	TWI_MasterSendAdrres(EEP_DEVICE_ADDRESS , TWI_READ);

	/* Read data */
	for (u8 i = 0 ; i < size-1 ; i++)
	{
		TWI_MasterReadDataWithAck(&arr[i]);
	}

	/* Read last byte */
	TWI_MasterReadDataWithNack(&arr[size-1]);

	/* Send stop */
	TWI_SendStopCondition();
}




