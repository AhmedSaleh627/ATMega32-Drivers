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

volatile u32 SW_Counter1 =0;
volatile u32 SW_Counter2 =0;
volatile u32 SW_Counter3 =0;
volatile u32 SW_Counter4 =0;
void LED2_TOG()
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
	if (SW_Counter2==1*1000)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,HIGH);
		
	}
	else if (SW_Counter2==2*1000)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,LOW);
		SW_Counter2=0;
	}
}
void LED_TOGGLE_2()
{
	SW_Counter3++ ;
	if (SW_Counter3==1)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,HIGH);
		
	}
	else if (SW_Counter3==2)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,LOW);
		SW_Counter3=0;
	}
}
void LED_TOGGLE_3()
{
	SW_Counter4++ ;
	if (SW_Counter4==1)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,HIGH);
		
	}
	else if (SW_Counter4==2)
	{
		DIO_Vid_Set_Pin_Val(PORTD,PIN0,LOW);
		SW_Counter4=0;
	}
}

int main(void)
{
	//Timer0_Vid_Start(_64_PRESCALER);
	//Timer0_Vid_CTC_INIT();
	//Timer0_Vid_OVF_Enable_INT();
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN1,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTD,PIN5,OUTPUT);
	//TIM0_Vid_Set_CallBack(CTC_MODE,LED_TOGGLE);
	//TIM0_Vid_Set_CallBack(OVF_MODE,LED2_TOG);
	//Timer1_Vid_INIT();
	//Timer1_Vid_OVF_Enable_INT();
	//Timer1_Vid_CTC_INIT();
	//Timer1_Vid_Set_CallBack(OVF_MODE_TIM1,LED_TOGGLE_3);
	//Timer1_Vid_Start(_256_PRESCALER);
	
	//	Timer0_Vid_Fast_PWM(10);
		Timer1_Vid_Fast_PWM(80);
	
	while(1)
	{
		

	}
}


