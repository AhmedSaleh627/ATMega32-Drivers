/*
 * LED_interface.c
 *
 * Created: 9/1/2023 2:54:58 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

void LED_Vid_ON(u8 copy_u8_port , u8 copy_u8_pin)
{
	DIO_Vid_Set_Pin_Dir(copy_u8_port,copy_u8_pin,OUTPUT);
	DIO_Vid_Set_Pin_Val(copy_u8_port,copy_u8_pin,HIGH);
}
void LED_Vid_OFF(u8 copy_u8_port , u8 copy_u8_pin)
{
	DIO_Vid_Set_Pin_Dir(copy_u8_port,copy_u8_pin,OUTPUT);
	DIO_Vid_Set_Pin_Val(copy_u8_port,copy_u8_pin,LOW);
	
}
void LED_Vid_TOGGLE(u8 copy_u8_port , u8 copy_u8_pin)
{
	DIO_Vid_Set_Pin_Dir(copy_u8_port,copy_u8_pin,OUTPUT);
	DIO_Vid_Toggle_Pin_Val(copy_u8_port,copy_u8_pin);
}