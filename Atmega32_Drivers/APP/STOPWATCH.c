#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "LIB/Vect_table.h"
#include "HAL/LCD_Driver/LCD_config.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#define F_CPU 16000000UL


u8 count=0;

int main(void)
{

	/* INIT Timer reg */
	TCNT0_REG=0x00;
	DIO_Vid_Set_Pin_Dir(PORTA,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT) ;
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT) ;
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT) ;
	LCD_Vid_Init();
	Timer0_Vid_Start(_64_PRESCALER);

LCD_Vid_GOTOXY(6,0);
LCD_Vid_Send_Data(':');

LCD_Vid_GOTOXY(3,0);
LCD_Vid_Send_Data(':');



LCD_Vid_GOTOXY(1,0);
LCD_Vid_Send_Data('0');
LCD_Vid_GOTOXY(2,0);
LCD_Vid_Send_Data('0');
LCD_Vid_GOTOXY(4,0);
LCD_Vid_Send_Data('0');
LCD_Vid_GOTOXY(5,0);
LCD_Vid_Send_Data('0');
LCD_Vid_GOTOXY(7,0);
LCD_Vid_Send_Data('0');
LCD_Vid_GOTOXY(8,0);
LCD_Vid_Send_Data('0');



while(1)
{


for(u8 k=1;k<=12;k++)
{
	for(u8 j=58;j<=60;j++)
	{
		
		for(u8 i=0;i<60;i++)
		{
			
			if(i<10)
			{
				
				LCD_Vid_GOTOXY(8,0);
				LCD_Send_Number(i);
			}
			else
			{
					
				LCD_Vid_GOTOXY(7,0);
				LCD_Send_Number(i);
			}
			

			Timer0_delay_ms(1000);
			
			if(i==59)
			{
				
				
				
				if(j<10)
				{
					
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number(j);
				}
				else
				{
					
					LCD_Vid_GOTOXY(4,0);
					LCD_Send_Number(j);
				}
				
				
				LCD_Vid_GOTOXY(7,0);
				LCD_Send_Number(0);
				LCD_Vid_GOTOXY(8,0);
				LCD_Send_Number(0);
				
			}
		
			
		}
		if(j==60)
		{
			LCD_Vid_GOTOXY(4,0);
			LCD_Send_Number(0);
			
			if(k<10)
			{
				
				LCD_Vid_GOTOXY(2,0);
				LCD_Send_Number(k);
			}
			else
			{
				
				LCD_Vid_GOTOXY(1,0);
				LCD_Send_Number(k);
			}
			
			
			
		}
		
	}



	
	
}

	}
}




