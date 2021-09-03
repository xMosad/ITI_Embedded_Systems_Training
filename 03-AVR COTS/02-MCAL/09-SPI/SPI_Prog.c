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
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Cfg.h"


void SPI_voidInitMaster(void)
{
	/* Disable interrupt */
	CLR_BIT(SPCR , SPCR_SPIE);

	/* MSB First */
	CLR_BIT(SPCR , SPCR_DORD);

	/* Master select */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Clk idle low |  Leading edge is rising */
	CLR_BIT(SPCR, SPCR_CPOL);

	/* Sample at leading edge */
	CLR_BIT(SPCR, SPCR_CPHA);

	/* Freq / 16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);

}

void SPI_voidInitSlave(void)
{
	/* Disable interrupt */
	CLR_BIT(SPCR , SPCR_SPIE);

	/* MSB First */
	CLR_BIT(SPCR , SPCR_DORD);

	/* Slave select */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* Clk idle low |  Leading edge is rising */
	CLR_BIT(SPCR, SPCR_CPOL);

	/* Sample at leading edge */
	CLR_BIT(SPCR, SPCR_CPHA);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);
}


u8 SPI_u8Transceive(u8 Cpy_data)
{
	/* Send Data */
	SPDR = Cpy_data ;

	/* Wait till data is sent */
	while (GET_BIT(SPSR , SPSR_SPIF) == 0);

	/* Return received data */
	return SPDR ;
}



