/*
 * ADC_V0
 *
 *  Created on: Aug 21, 2021
 *      Author: Mosad
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* ADC registers */
#define ADMUX   (*((volatile u8 *) 0x27))
#define ADCSRA  (*((volatile u8 *) 0x26))
#define ADCH    (*((volatile u8 *) 0x25))
#define ADCL    (*((volatile u8 *) 0x24))
#define ADC     (*((volatile u16 *) 0x24))
#define SFIOR   (*((volatile u16 *) 0x50))

/**** ADMUX Bits ****/
#define   ADMUX_REFS1     7
#define   ADMUX_REFS0     6
#define   ADMUX_ADLAR     5
#define   ADMUX_MUX0      0

/**** ADCSRA Bits ****/
#define ADCSRA_ADEN     7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2    2
#define ADCSRA_ADPS1    1 
#define ADCSRA_ADPS0    0


/***** Macros *****/
#define CLEAR_FIVE_BITS  31 
#define  ADC_BUSY  0
#define  ADC_FREE  1

#endif
