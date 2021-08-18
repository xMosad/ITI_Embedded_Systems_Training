/*
 * GPIO.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef GPIO_H_
#define GPIO_H_


/* Port IDs */
#define  PORTA  0
#define  PORTB  1
#define  PORTC  2
#define  PORTD  3

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
void GPIO_setPinValue(u8 port_id , u8 pin , u8 value);
void GPIO_setPinDirection(u8 port_id , u8 pin , u8 dirc );
void GPIO_setPortValue(u8 port_id , u8 value);
void GPIO_setPortDirection(u8 port_id , u8 dirc);
u8 GPIO_getPinValue(u8 port_id , u8 pin);


#endif /* GPIO_H_ */
