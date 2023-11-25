#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/KeyPad/Keypad_interface.h"
#include "MCAL/I2C/I2C_interface.h"
#include "MCAL/TWI/TWI_interface.h"
#include "HAL/EEPROM/EEPROM_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	u8 Loc_val=0;
	DIO_Vid_Set_Pin_Dir(PORTC,PIN7,OUTPUT);
	TWI_Vid_Master_Init(0);
	EEPROM_Vid_Send_Data(0,'A');
	Loc_val=EEPROM_Vid_Recieve_Data(0);
	
	if(Loc_val=='A')
	{
		DIO_Vid_Set_Pin_Val(PORTC,PIN7,HIGH);
	}
	else
	{
		DIO_Vid_Set_Pin_Val(PORTC,PIN7,LOW);
	}
	
	while (1)
	{
		
		
	}
	
}

