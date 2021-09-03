/*
 * GPIO_reg.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


/*********** Registers ***************/
#define GICR   (*((volatile u8 *)0x5B))						
#define GIFR   (*((volatile u8 *)0x5A))
#define MCUCR  (*((volatile u8 *)0x55))                                
#define MCUCSR (*((volatile u8 *)0x54))

/**** GICR BITS *****/
#define  GICR_INT1    7 
#define  GICR_INT0    6
#define  GICR_INT2    5

/**** GIFR BITS *****/
#define  GICR_INTF1    7 
#define  GICR_INTF0    6
#define  GICR_INTF2    5

/**** MCUCR BITS *****/
#define  MCUCR_ISC00    0 
#define  MCUCR_ISC01    1
#define  MCUCR_ISC10    2
#define  MCUCR_ISC11    3

/**** MCUCSR BITS *****/
#define  MCUCSR_ISC2    6 



/************* Macros for Config ************/
#define     LOW_LEVEL       0
#define     ON_CHANGE       1
#define     FALLING_EDGE    2
#define     RISING_EDGE     3

#define     ENABLE     0
#define     DISABLE    1


#endif /* EXTI_PRIVATE_H_ */
