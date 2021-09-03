/*
 * SPI
 *
 *  Created on: Aug 27, 2021
 *      Author: Mosad
 */
/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Own drive includes */
#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Cfg.h"


void TWI_voidInitMaster(u8 Cpy_u8Address)
{
	/* Set clock frequency to 400 kbps 
	 * With 8 Mhz Fos  
	 * TWPS = 0 */
	TWBR = 2 ;
	CLR_BIT(TWSR , TWSR_TWPS1);
	CLR_BIT(TWSR , TWSR_TWPS0);
	
	/* Set the address */
	if (Cpy_u8Address)
	{
		TWAR |= (Cpy_u8Address << TWAR_TWA0);
	}
	
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Cpy_u8Address)
{
	/* Set the address */
	if (Cpy_u8Address)
	{
		TWAR |= (Cpy_u8Address << TWAR_TWA0);
	}

	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

TWI_ErrState_t TWI_SendStartCondition (void)
{
	TWI_ErrState_t local_err = NoError ;
	
	/* Set start condition bit */
	SET_BIT(TWCR , TWCR_TWSTA);
	
	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);
	
	/* Wait till start condition is sent */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);
	
	/* Check status register */
	if ((TWSR & TWSR_MASK ) != START_ACK )
	{
		local_err = StartConditionErr ;
	}
	else 
	{

	}
	return local_err ;
}

TWI_ErrState_t TWI_SendRepeatedStart (void)
{
	TWI_ErrState_t local_err = NoError ;
	
	/* Set start condition bit */
	SET_BIT(TWCR , TWCR_TWSTA);
	
	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);
	
	/* Wait till start condition is sent */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);
	
	/* Check status register */
	if ((TWSR & TWSR_MASK ) != START_ACK )
	{
		local_err = RepStartErr ;
	}
	else 
	{

	}
	return local_err ;
}

TWI_ErrState_t TWI_MasterSendAdrres (u8 Cpy_u8Adress ,u8 Cpy_u8Operation)
{
	TWI_ErrState_t local_err = NoError ;
	u8 local_address ;

	if (Cpy_u8Operation == TWI_WRITE)
	{
		local_address = ((Cpy_u8Adress << 1) | 0 );
	}
	else if (Cpy_u8Operation == TWI_READ)
	{
		local_address = ((Cpy_u8Adress << 1) | 1 );
	}
	else 
	{
		
	}
	
	/* Write address to data register */
	TWDR = local_address ;
	
	/* Clear start condition */
	CLR_BIT(TWCR , TWCR_TWSTA);

	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);

	/* Wait till Job is finished */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);
	
	/* Check operation */
	if (((TWSR & TWSR_MASK ) != SLAVE_W_ACK ) 
		&& (Cpy_u8Operation == TWI_WRITE))
	{
		local_err = AddressWriteNackErr ;
	}
	else if ( ((TWSR & TWSR_MASK ) != SLAVE_R_ACK) 
		       && (Cpy_u8Operation == TWI_READ))
	{
		local_err = AddressReadNackErr ;
	}
	else 
	{
		
	}
	
	return local_err ;
}

TWI_ErrState_t TWI_MasterSendData (u8 Cpy_u8Data)
{
	TWI_ErrState_t local_err = NoError ;
	
	/* Write address to data register */
	TWDR = Cpy_u8Data ;

	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);
	
	/* Wait till Job is finished */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);
	
	/* Check status register */
	if ((TWSR & TWSR_MASK ) != SLAVE_DATA_ACK )
	{
		local_err = DataSlaveNackErr ;
	}
	else 
	{
		
	}
	return local_err ;
}

TWI_ErrState_t TWI_MasterReadDataWithAck (u8 *Cpy_u8Data)
{
	TWI_ErrState_t local_err = NoError ;

	/* Enable ACK */
	SET_BIT(TWCR , TWCR_TWEA);

	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);
	
	/* Wait till Job is finished */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);
	
	/* Check status register */
	if ((TWSR & TWSR_MASK ) != MASTER_R_DATA_ACK )
	{
		local_err = DataRecNackErr ;

	}
	else 
	{
		/* Read the data */
		*Cpy_u8Data = TWDR ;
	}
	
	return local_err ;	
}

TWI_ErrState_t TWI_MasterReadDataWithNack (u8 *Cpy_u8Data)
{
	TWI_ErrState_t local_err = NoError ;

	/* Disable ACK */
	CLR_BIT(TWCR , TWCR_TWEA);

	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);

	/* Wait till Job is finished */
	while (GET_BIT(TWCR , TWCR_TWINT)==0);

	/* Check status register */
	if ((TWSR & TWSR_MASK ) != MASTER_R_DATA_NACK )
	{
		local_err = DataRecNackErr;
	}
	else
	{
		/* Read the data */
		*Cpy_u8Data = TWDR ;
	}

	return local_err ;
}

void TWI_SendStopCondition (void)
{
	/* Generate stop condition */
	SET_BIT(TWCR , TWCR_TWSTO);
	
	/* Clear flag so TWI start its job */
	SET_BIT(TWCR , TWCR_TWINT);
}






