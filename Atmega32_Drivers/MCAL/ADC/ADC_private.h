/*
 * ADC_private.h
 *
 * Created: 9/16/2023 3:56:30 PM
 *  Author: Ahmed saleh
 */ 

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define SFIOR_REG   *((volatile u8*)0x50) 
#define  ADMUX_REG  *((volatile u8*)0x27) 
#define  ADCSRA_REG *((volatile u8*)0x26)
#define ADCL_REG *((volatile u8*)0x24)
#define ADCH_REG *((volatile u8*)0x25)
#define  ADC_REG    *((volatile uint16*)0x24) // ADCL + ADCH 



#endif /* ADC_PRIVATE_H_ */