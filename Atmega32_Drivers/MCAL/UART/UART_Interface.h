/*
 * UART_Interface.h
 *
 * Created: 10/13/2023 3:57:35 PM
 *  Author: Ahmed saleh
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Vid_Init();
void UART_Vid_Send(u8 Data);
uint16 UART_Vid_Recieve();



#endif /* UART_INTERFACE_H_ */