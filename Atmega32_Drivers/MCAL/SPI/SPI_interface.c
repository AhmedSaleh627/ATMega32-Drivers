/*
 * SPI_interface.c
 *
 * Created: 10/20/2023 2:52:08 PM
 *  Author: Ahmed saleh
 */ 

#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"
void SPI_Vid_Master_Init()
{
		
		SET_BIT(SPCR_REG,4);
		SET_BIT(SPCR_REG,1);
		SET_BIT(SPCR_REG,0);
		
		SET_BIT(SPCR_REG,6);  //SPI Enable


}

void SPI_Vid_Master_Send(u8 data)
{
	SPDR_REG=data;
	while( GET_BIT(SPSR_REG,7)==0);
}

void SPI_Vid_Slave_Init()
{
	SET_BIT(SPCR_REG,6);  //SPI Enable	
}
u8 SPI_Vid_Slave_Recieve()
{
	while( GET_BIT(SPSR_REG,7)==0);
	return SPDR_REG;
	
}