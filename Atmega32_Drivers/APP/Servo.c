#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "HAL/DC_Motor_Driver/DC_Motor_interface.h"

#include "LIB/Vect_table.h"
#define F_CPU 16000000UL
#include "util/delay.h"




int main(void)
{
	u32 i=0;
	
	DIO_Vid_Set_Pin_Dir(PORTD,PIN5,OUTPUT);
	TIM1_Vid_ICR_FastPWM_Init();
	
	
	while(1)
	{
		for(i=1000;i<5000;i++)
		{
			TIM1_Vid_SetCompareVal(i);
			_delay_ms(2);
		}	
	
	}
}


