/*
 * GPIO.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/* Port IDs */
#define  PORT_A  0
#define  PORT_B  1
#define  PORT_C  2
#define  PORT_D  3

/* Pins */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* Values */
#define  HIGH  1
#define  LOW   0

/* Direction */
#define  OUTPUT 1
#define  INPUT  0

/* Prototypes */
void GPIO_voidSetPinValue(u8 port_id , u8 pin , u8 value);
void GPIO_voidSetPinDirection(u8 port_id , u8 pin , u8 dirc );
void GPIO_voidSetPortValue(u8 port_id , u8 value);
void GPIO_voidSetPortDirection(u8 port_id , u8 dirc);
u8 GPIO_u8GetPinValue(u8 port_id , u8 pin);


#endif /* GPIO_H_ */
