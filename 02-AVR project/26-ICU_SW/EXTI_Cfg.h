/*
 * GPIO_reg.h
 *
 *  Created on: Aug 20, 2021
 *      Author: Mosad
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/********** Configurations of Int0 **********/
/* Choose : 
			LOW_LEVEL
			ON_CHANGE
			FALLING_EDGE
			RISING_EDGE
*/
#define    EXTI_INT0_SENSE_CONTROL  RISING_EDGE

/* Choose : 
			ENABLE
			DISABLE
*/
#define    EXTI_INT0_INITIAL_STATE  ENABLE


/********** Configurations of Int1 **********/
/* Choose : 
			LOW_LEVEL
			ON_CHANGE
			FALLING_EDGE
			RISING_EDGE
*/
#define    EXTI_INT1_SENSE_CONTROL  FALLING_EDGE

/* Choose : 
			ENABLE
			DISABLE
*/
#define    EXTI_INT1_INITIAL_STATE  DISABLE

/********** Configurations of Int2 **********/
/* Choose : 
			FALLING_EDGE
			RISING_EDGE
*/
#define    EXTI_INT2_SENSE_CONTROL  FALLING_EDGE

/* Choose : 
			ENABLE
			DISABLE
*/
#define    EXTI_INT2_INITIAL_STATE  DISABLE


#endif /* EXTI_CFG_H_ */
