#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "LIB/Vect_table.h"
#define F_CPU 16000000UL
u8 count2=0;

void LED_TOGGLE(void)
{
	static u32 count=0;
	count++;
	if(count==100)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN0,HIGH);
	}
	else if (count==200)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN0,LOW);
		count=0;
	}
}



void LED_TOGGLE2()
{
	
	count2++;
	if(count2==97)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN1,HIGH);
	}
	if(count2==194)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN1,LOW);
		count2=0;
	}

}






int main(void)
{

	/* INIT Timer reg */
	//Timer0_Vid_Start(_64_PRESCALER);
	//Timer0_Vid_CTC_INIT();
	DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
	//TIM0_Vid_Set_CallBack(CTC_MODE,LED_TOGGLE);
	//Timer0_Vid_OVF_Enable_INT();
	//TIM0_Vid_Set_CallBack(OVF_MODE,LED_TOGGLE2);
	
	u8 i=0;
	for(i=0;i<100;i+=10)
	{
		Timer0_Vid_Fast_PWM(i);
		
	}
	
	while(1)
	{
		
	}
}



