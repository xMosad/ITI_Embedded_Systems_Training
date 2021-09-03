/*
 * WDT
 *
 *  Created on: Aug 26, 2021
 *      Author: Mosad
 */
/* Library */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Own drive includes */
#include "WDT_Interface.h"
#include "WDT_Private.h"
#include "WDT_Cfg.h"


void  WDT_voidEnable(void)
{
	SET_BIT(WDTCR , WDTCR_WDE);
}

void WDT_voidSleep(u8 Cpy_u8Period)
{
	WDTCR &= ~(7 << WDTCR_WDP0);
	WDTCR |= (Cpy_u8Period << WDTCR_WDP0);
}

void WDT_voidDisable(void)
{
	WDTCR = 0x18 ;
	WDTCR = 0 ;
}
