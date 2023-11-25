/*
 * TIMER0_private.h
 *
 * Created: 9/23/2023 2:38:00 PM
 *  Author: Ahmed saleh
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG *((volatile u8*)0x53)
#define TCNT0_REG *((volatile u8*)0x52)
#define OCR0_REG   *((volatile u8*)0x5C)

#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG  *((volatile u8*)0x58)


#define TCCR2_REG *((volatile u8*)0x45)
#define TCNT2_REG *((volatile u8*)0x44)
#define OCR2_REG   *((volatile u8*)0x43)



#endif /* TIMER0_PRIVATE_H_ */