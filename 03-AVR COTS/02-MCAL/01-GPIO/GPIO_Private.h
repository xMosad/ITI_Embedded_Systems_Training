/*
 * GPIO_reg.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/* PortD registers */
#define GPIO_PORTD (*((volatile u8 *) 0x32))
#define GPIO_DDRD  (*((volatile u8 *) 0x31))
#define GPIO_PIND  (*((volatile u8 *) 0x30))
								
/* PortC registers */           
#define GPIO_PORTC (*((volatile u8 *) 0x35))
#define GPIO_DDRC  (*((volatile u8 *) 0x34))
#define GPIO_PINC  (*((volatile u8 *) 0x33))
								
/* PortB registers */           
#define GPIO_PORTB (*((volatile u8 *) 0x38))
#define GPIO_DDRB  (*((volatile u8 *) 0x37))
#define GPIO_PINB  (*((volatile u8 *) 0x36))
								
/* PortA registers */           
#define GPIO_PORTA (*((volatile u8 *) 0x3B))
#define GPIO_DDRA  (*((volatile u8 *) 0x3A))
#define GPIO_PINA  (*((volatile u8 *) 0x39))


#endif /* GPIO_REG_H_ */
