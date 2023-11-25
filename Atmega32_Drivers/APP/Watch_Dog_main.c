#include "LIB/STD_Type.h"
#include "MCAL/Watch_Dog/WatchDog_interface.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "HAL/DC_Motor_Driver/DC_Motor_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "LIB/Vect_table.h"

#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,OUTPUT);
		DIO_Vid_Set_Pin_Dir(PORTD,PIN1,OUTPUT);
	WDT_Enable(_1s_);
	DIO_Vid_Set_Pin_Val(PORTD,PIN0,LOW);
	_delay_ms(3000);
	DIO_Vid_Set_Pin_Val(PORTD,PIN1,HIGH);
	//WDT_Disable();
	//DIO_Vid_Set_Pin_Val(PORTD,PIN0,HIGH);
	
	while(1)
	
	{
		
	}
	
}