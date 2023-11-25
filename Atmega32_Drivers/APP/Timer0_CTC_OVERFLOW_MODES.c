#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "HAL/DC_Motor_Driver/DC_Motor_interface.h"

#include "LIB/Vect_table.h"
#define F_CPU 16000000UL
#include "util/delay.h"

volatile u32 SW_Counter1 =0;
volatile u32 SW_Counter2 =0;
void B_TOG()
{
	
	SW_Counter1++ ;
	if (SW_Counter1==1954)
	{
		TIMER0_voidSetPreload(224);
		DIO_Vid_Toggle_Pin_Val(PORTD,PIN1);
		SW_Counter1=0;
	}
}

void LED_TOGGLE(void)
{

	SW_Counter2++ ;
	if (SW_Counter2==2000)
	{
		DIO_Vid_Toggle_Pin_Val(PORTD,PIN0);
		SW_Counter2=0;
	}
}


int main(void)
{
	Timer0_Vid_Start(_64_PRESCALER);
	Timer0_Vid_CTC_INIT();
	Timer0_Vid_OVF_Enable_INT();
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN1,OUTPUT);
	TIM0_Vid_Set_CallBack(CTC_MODE,LED_TOGGLE);
	TIM0_Vid_Set_CallBack(OVF_MODE,B_TOG);
	GIE_Vid_Enable();
	
	while(1)
	{}

		
		
	}


