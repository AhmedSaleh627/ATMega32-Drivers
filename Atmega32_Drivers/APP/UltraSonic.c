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
#define F_CPU 16000000UL
#include "util/delay.h"

static volatile int pulse=0;
static volatile int i=0;



int main(void)
{
	LCD_Vid_Init();
	
	LCD_Send_String("Distance= ");
	DIO_Vid_Set_Pin_Dir(PORTC,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN3,OUTPUT);
	
	EXT_Vid_Interrupt0();
	EXT_Vid_Interrupt_Init();
	
	uint16 count_a=0;
	
	while(1)
	{
		DIO_Vid_Set_Pin_Val(PORTC,PIN0,HIGH);
		_delay_ms(20);
		DIO_Vid_Set_Pin_Val(PORTC,PIN0,LOW);
		
		 count_a = (pulse/14.5);
		 
		  LCD_Vid_GOTOXY(0,1);
		  LCD_Send_Number(count_a );
		  if(count_a>30)
		  {
			  DIO_Vid_Set_Pin_Val(PORTD,PIN3,HIGH);
		  }
		  else
		  {
			   DIO_Vid_Set_Pin_Val(PORTD,PIN3,LOW); 
		  }
	
		
		
		
		
		
	}
}

ISR(INT_0)
{
	if(i==0)
	{
		TCCR1B_REG=0;
		SET_BIT(TCCR1B_REG,0);
		SET_BIT(TCCR1B_REG,1);
		//SET_BIT(TCCR1B_REG,2);
		
		i=1;
	}
	else
	{
		TCCR1B_REG = 0;
		pulse = TCNT1_REG;
		TCNT1_REG = 0;
		i = 0;
	}
}