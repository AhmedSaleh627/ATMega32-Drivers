/*
 * UART_private.h
 *
 * Created: 10/13/2023 3:57:49 PM
 *  Author: Ahmed saleh
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define  UDR_REG     *((volatile u8*)0x2C)
#define  UCSRA_REG   *((volatile u8*)0x2B)
#define  UCSRB_REG   *((volatile u8*)0x2A)

#define	 UBRRL_REG   *((volatile u8*)0x29)

#define	 UCSRC_REG   *((volatile u8*)0x40)
#define	 UBRRH_REG   *((volatile u8*)0x40)

#endif /* UART_PRIVATE_H_ */