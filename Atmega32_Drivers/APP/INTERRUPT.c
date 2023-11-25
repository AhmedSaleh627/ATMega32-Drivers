#include "LIB/STD_Type.h"
#include "MCAL/DIO/DIO_private.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/EXIT_interface.h"


#define F_CPU 16000000UL
#include<util/delay.h>
int main(void)
{
	/* MAKE PIN2 IN PORTD --> INPUT FOR INTERRUPT  */
	DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT) ;
	DIO_Vid_Set_Pin_Dir(PORTD,PIN3,INPUT) ;
	DIO_Vid_Set_Pin_Dir(PORTC,PIN2,OUTPUT) ;
	
	/* INIT INTERRUPT  */
	EXT_Vid_Interrupt_Init() ;
	
	
	while (1)
	{
		/* ENABLE INTERRRUPT  */
		EXT_Vid_Interrupt0() ;
		EXT_Vid_Interrupt1() ;
	}
}
