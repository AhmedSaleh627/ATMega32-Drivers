#include "STD_Type.h"
#include "BITMATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "TWI_interface.h"
#include "LCD_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	SPI_Vid_Slave_Init();
	u8 loc=0;
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN5,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN4,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN6,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN7,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN7,INPUT);
	LCD_Vid_Init();
	while (1)
	{
		loc=SPI_Vid_Slave_Recieve();
		LCD_Vid_Send_Data(loc);
		if(loc=='A')
		{
			DIO_Vid_Set_Pin_Val(PORTD,PIN0,HIGH);
		}
		else
		{
			DIO_Vid_Set_Pin_Val(PORTD,PIN0,LOW);

		}
		
	}
}

