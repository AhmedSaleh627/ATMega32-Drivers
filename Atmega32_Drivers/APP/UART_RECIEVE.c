#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/GIE_interrupt/EXIT_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "HAL/DC_Motor_Driver/DC_Motor_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "LIB/Vect_table.h"
#include "MCAL/UART/UART_Interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"

static volatile int pulse=0;
static volatile int i=0;

u8 countx=0;
u8 county=0;
u8 num1;
int main(void)
{
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,INPUT);
	LCD_Vid_Init();
	UART_Vid_Init();
    CLR_Display();

	while(1)
	{
		
			num1=UART_Vid_Recieve();
			if(num1=='c')
			{
				LCD_Send_String("CLearing");
				_delay_ms(200);
				CLR_Display();
				countx=0;
				county=0;
			}
			else 
			{
				if(num1%2==0)
				{
					LCD_Vid_GOTOXY(countx,0);
					LCD_Send_Number(num1);
					countx++;
				}
				else
				{
					LCD_Vid_GOTOXY(county,1);
					LCD_Send_Number(num1);
					county++;
				}
			}
			
			
	
	
	
	}
}

