/*
 * TIMER1_private.h
 *
 * Created: 9/30/2023 4:45:43 PM
 *  Author: Ahmed saleh
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A_REG   *((volatile u8*)0x4F)
#define TCCR1B_REG   *((volatile u8*)0x4E)


#define TCNT1_REG   *((volatile uint16*)0x4C)


#define OCR1A_REG   *((volatile uint16*)0x4A)


#define OCR1B_REG   *((volatile uint16*)0x48)


#define ICR1_REG	 *((volatile uint16*)0x46)


#define WDTCR_REG   *((volatile u8*)0x41)

#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG  *((volatile u8*)0x58)


#endif /* TIMER1_PRIVATE_H_ */