/*
 * GIE.c
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver includes */
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Cfg.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG , SREG_I);
}



