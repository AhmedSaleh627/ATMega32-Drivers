/*
 * EXIT_private.h
 *
 * Created: 09/09/2023 16:22:30
 *  Author: AMIT
 */ 


#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_

#define  MCUCR_REG   *((volatile u8*)0x55)
#define  ISC11     3
#define  ISC10     2
#define  ISC01     1
#define  ISC00     0

#define MCUCSR_REG   *((volatile u8*)0x54)
#define  ISC2     6 

#define GICR_REG     *((volatile u8*)0x5B)
#define  INT_0_PIN    6
#define  INT_1_PIN    7 
#define  INT_2    5  

#define GIFR_REG     *((volatile u8*)0x5A)

#endif /* EXIT_PRIVATE_H_ */