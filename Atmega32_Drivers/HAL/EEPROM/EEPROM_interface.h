/*
 * EEPROM_interface.h
 *
 * Created: 10/27/2023 3:51:28 PM
 *  Author: Ahmed saleh
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_





void EEPROM_Vid_Send_Data(uint16 copy_u16_address,u8 copy_u8_data);
u8 EEPROM_Vid_Recieve_Data(uint16 copy_u16_address);




#endif /* EEPROM_INTERFACE_H_ */