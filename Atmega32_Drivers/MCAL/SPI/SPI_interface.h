/*
 * SPI_interface.h
 *
 * Created: 10/20/2023 2:51:50 PM
 *  Author: Ahmed saleh
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Vid_Master_Init();
void SPI_Vid_Slave_Init();
void SPI_Vid_Master_Send(u8 data);
u8 SPI_Vid_Slave_Recieve();


#endif /* SPI_INTERFACE_H_ */