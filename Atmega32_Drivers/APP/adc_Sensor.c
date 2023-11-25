#include "LIB/STD_Type.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>
uint16 val ;
uint16 analogval;
void LED()
{
	/* Turn on the LEDs */
		DIO_Vid_Set_Port_Val(PORTB,val);
}

void TEMP_SENSOR()
{
	LCD_Vid_GOTOXY(1,1);
	LCD_Send_Number(val*500/1024);
	_delay_ms(300);
	CLR_Display();
	
}
void LDR_Sensor()
{
	analogval=val*5/1024;
	if(analogval>3)
	{
		DIO_Vid_Set_Pin_Val(PORTB,PIN0,HIGH);
	}
	else
	{
				DIO_Vid_Set_Pin_Val(PORTB,PIN0,LOW);

	}

}

int main(void)
{
	ADC_Vid_Init() ;		//Initialize ADC
	GIE_Vid_Enable();
	ADC_EnableInt();		//Enable ADC Interrupt
	//DIO_Vid_Set_Port_Dir(PORTB,PORT_OUTPUT);	// Set PORTB OUTPUT for the LEDs
//	LCD_Vid_Init();
	DIO_Vid_Set_Pin_Val(PORTA,PIN0,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN0,OUTPUT);
//	ADC_Vid_Set_CallBack(LDR_Sensor);				// CallBack Function for interrupt
	while (1)
	{
		val=ADC_u16_Read(0) ;	
		val=(val*5)/1024;
		if(val>3)
		{
			DIO_Vid_Set_Pin_Val(PORTB,PIN0,HIGH);
		}
		else
		{
			DIO_Vid_Set_Pin_Val(PORTB,PIN0,LOW);

		}
		
	}
}

