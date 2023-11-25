#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "HAL/KeyPad/Keypad_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	
	DIO_Vid_Set_Pin_Dir(PORTB,PIN5,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN7,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN7,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN4,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN6,INPUT);
	
	SPI_Vid_Master_Init();
	
	while (1)
	{
		DIO_Vid_Set_Pin_Val(PORTB,PIN4,LOW);
		SPI_Vid_Master_Send('A');
		_delay_ms(200);
		SPI_Vid_Master_Send('N');
		DIO_Vid_Set_Pin_Val(PORTB,PIN4,HIGH);
		_delay_ms(200);
	}
	
}

