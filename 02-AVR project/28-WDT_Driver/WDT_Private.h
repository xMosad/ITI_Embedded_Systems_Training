/*
 * WDT
 *
 *  Created on: Aug 26, 2021
 *      Author: Mosad
 */
#ifndef WDT_PRIVATE_
#define WDT_PRIVATE_

#define    WDTCR    (*(volatile u8 *) 0x41)
/* WDTCR bits */
#define    WDTCR_WDTOE     4 
#define    WDTCR_WDE       3
#define    WDTCR_WDP2      2
#define    WDTCR_WDP1      1
#define    WDTCR_WDP0      0

#endif