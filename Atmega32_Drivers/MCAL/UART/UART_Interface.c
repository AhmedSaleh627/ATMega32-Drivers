/*
 * UART_Interface.c
 *
 * Created: 10/13/2023 3:57:15 PM
 *  Author: Ahmed saleh
 */ 

#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "UART_private.h"
#include "UART_Interface.h"

void UART_Vid_Init()
{
	
	/*Enable Reciever and Transmitter */
	UCSRC_REG=(1<<7)|(3<<1);

	UBRRL_REG=103;
	SET_BIT(UCSRB_REG,4);
	SET_BIT(UCSRB_REG,3);
	
}

void UART_Vid_Send(u8 Data)
{
	UDR_REG=Data;
	while((GET_BIT(UCSRA_REG,5))==0 );
	
	
}


uint16 UART_Vid_Recieve()
{
	while((GET_BIT(UCSRA_REG,7))==0 );
	return UDR_REG;
}