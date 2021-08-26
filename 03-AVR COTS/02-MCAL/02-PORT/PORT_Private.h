/*
 * GPIO_reg.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Mosad
 */

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_


/*********** Registers ***************/
#define PORT_PORTD (*((volatile u8 *) 0x32))
#define PORT_DDRD  (*((volatile u8 *) 0x31))							           
#define PORT_PORTC (*((volatile u8 *) 0x35))
#define PORT_DDRC  (*((volatile u8 *) 0x34))         
#define PORT_PORTB (*((volatile u8 *) 0x38))
#define PORT_DDRB  (*((volatile u8 *) 0x37))
#define PORT_PORTA (*((volatile u8 *) 0x3B))
#define PORT_DDRA  (*((volatile u8 *) 0x3A))

/************* Macros ****************/
#define CONC(b0,b1,b2,b3,b4,b5,b6,b7)    CONC_H(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_H(b0,b1,b2,b3,b4,b5,b6,b7)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIRECTION     CONC(PORTA_PIN0_DIR,PORTA_PIN1_DIR,PORTA_PIN2_DIR,\
                                 PORTA_PIN3_DIR,PORTA_PIN4_DIR,PORTA_PIN5_DIR,\
                                 PORTA_PIN6_DIR,PORTA_PIN7_DIR)
							 	 
#define PORTB_DIRECTION     CONC(PORTB_PIN0_DIR,PORTB_PIN1_DIR,PORTB_PIN2_DIR,\
                                 PORTB_PIN3_DIR,PORTB_PIN4_DIR,PORTB_PIN5_DIR,\
                                 PORTB_PIN6_DIR,PORTB_PIN7_DIR)	
							 
#define PORTC_DIRECTION     CONC(PORTC_PIN0_DIR,PORTC_PIN1_DIR,PORTC_PIN2_DIR,\
                                 PORTC_PIN3_DIR,PORTC_PIN4_DIR,PORTC_PIN5_DIR,\
                                 PORTC_PIN6_DIR,PORTC_PIN7_DIR)
							 
#define PORTD_DIRECTION     CONC(PORTD_PIN0_DIR,PORTD_PIN1_DIR,PORTD_PIN2_DIR,\
                                 PORTD_PIN3_DIR,PORTD_PIN4_DIR,PORTD_PIN5_DIR,\
                                 PORTD_PIN6_DIR,PORTD_PIN7_DIR)	

#define PORTA_INITIAL_VALUE	CONC(PORTA_PIN0_INTIAL_VALUE,PORTA_PIN1_INTIAL_VALUE\
								,PORTA_PIN2_INTIAL_VALUE,PORTA_PIN3_INTIAL_VALUE\
                                ,PORTA_PIN4_INTIAL_VALUE,PORTA_PIN5_INTIAL_VALUE\
                                ,PORTA_PIN6_INTIAL_VALUE,PORTA_PIN7_INTIAL_VALUE)
                                 
#define PORTB_INITIAL_VALUE	CONC(PORTB_PIN0_INTIAL_VALUE,PORTB_PIN1_INTIAL_VALUE\
								,PORTB_PIN2_INTIAL_VALUE,PORTB_PIN3_INTIAL_VALUE\
                                ,PORTB_PIN4_INTIAL_VALUE,PORTB_PIN5_INTIAL_VALUE\
                                ,PORTB_PIN6_INTIAL_VALUE,PORTB_PIN7_INTIAL_VALUE)

#define PORTC_INITIAL_VALUE	CONC(PORTC_PIN0_INTIAL_VALUE,PORTC_PIN1_INTIAL_VALUE\
								,PORTC_PIN2_INTIAL_VALUE,PORTC_PIN3_INTIAL_VALUE\
                                ,PORTC_PIN4_INTIAL_VALUE,PORTC_PIN5_INTIAL_VALUE\
                                ,PORTC_PIN6_INTIAL_VALUE,PORTC_PIN7_INTIAL_VALUE)
								
#define PORTD_INITIAL_VALUE	CONC(PORTD_PIN0_INTIAL_VALUE,PORTD_PIN1_INTIAL_VALUE\
								,PORTD_PIN2_INTIAL_VALUE,PORTD_PIN3_INTIAL_VALUE\
                                ,PORTD_PIN4_INTIAL_VALUE,PORTD_PIN5_INTIAL_VALUE\
                                ,PORTD_PIN6_INTIAL_VALUE,PORTD_PIN7_INTIAL_VALUE)								
                                



#endif /* PORT_PRIVATE_H_ */
