/*
 * WDT
 *
 *  Created on: Aug 26, 2021
 *      Author: Mosad
 */
#ifndef WDT_INTERFACE_
#define WDT_INTERFACE_

#define   WDT_16_3_ms      0 
#define   WDT_32_5_ms      1
#define   WDT_65_ms        2
#define   WDT_0_13_s       3
#define   WDT_0_26_s       4
#define   WDT_0_52_s       5
#define   WDT_1_s          6
#define   WDT_2_1_s        7

void  WDT_voidEnable(void);
void WDT_voidSleep(u8 Cpy_u8Period);
void WDT_voidDisable(void);

#endif