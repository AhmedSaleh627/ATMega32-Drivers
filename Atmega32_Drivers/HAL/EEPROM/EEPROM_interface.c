/*
 * EEPROM_interface.c
 *
 * Created: 10/27/2023 3:51:38 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

void EEPROM_Vid_Send_Data(uint16 copy_u16_address,u8 copy_u8_data)
{
	
	u8 Loc_device_address=0b1010000|copy_u16_address>>8;
	/* Send Start Condition */
	TWI_Send_StartCondition();
	/* Send Address packet */
	TWI_Send_SlaveAddress_With_Write(Loc_device_address);
	/* Send LSB */
	TWI_Master_Send_data((u8)copy_u16_address);
	/* Send Data */
	TWI_Master_Send_data(copy_u8_data);
	TWI_Send_StopCondition();
	_delay_ms(5);
}
u8 EEPROM_Vid_Recieve_Data(uint16 copy_u16_address)
{
	u8 Loc_u8_val=0;
	
	u8 Loc_device_address=0b1010000|copy_u16_address>>8;
	/* Send Start Condition */
	TWI_Send_StartCondition();
	/* Send Address packet */
	TWI_Send_SlaveAddress_With_Write(Loc_device_address);
	/* Send LSB */
	TWI_Master_Send_data((u8)copy_u16_address);
	/* Return Data */
	TWI_Send_RepeatedStart();
	/* Send the address packet again with read */
	TWI_Send_SlaveAddress_With_Read(Loc_device_address);
	
	TWI_Master_Recive_data(&Loc_u8_val);
	
	TWI_Send_StopCondition();
	return Loc_u8_val ;
}