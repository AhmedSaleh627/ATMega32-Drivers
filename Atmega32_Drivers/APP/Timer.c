#include "LIB/STD_Type.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "LIB/Vect_table.h"
#define F_CPU 16000000UL


u8 count=0;

int main(void)
{

	/* INIT Timer reg */
	TCNT0_REG=0x00;
	DIO_Vid_Set_Pin_Dir(PORTA,PIN0,OUTPUT);
	
	Timer0_Vid_Start(_64_PRESCALER);
	Timer0_Vid_Enable_INT();
	while(1)
	{
		
	}
}

ISR(TIMER0_OF)
{
	count++;
	if(count==97)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN0,HIGH);
	}
	if(count==194)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN0,LOW);
		count=0;
	}
	
	
}



