/*
 * DIO_interface.c
 *
 * Created: 8/27/2023 3:59:35 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"

/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_Dir
* Purpose      : Set pin direction
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_pin, u8 Copy_u8_dir
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Pin_Dir(u8 Copy_u8_port, u8 Copy_u8_pin, u8 Copy_u8_dir)
{
	if(Copy_u8_dir==OUTPUT || Copy_u8_dir==INPUT )
	{
		if(Copy_u8_dir==OUTPUT)
		{
			switch(Copy_u8_port)
			{
				/* SET Direction ---> OUTPUT*/
				case PORTA: SET_BIT(DDRA_REG,Copy_u8_pin );break;
				case PORTB: SET_BIT(DDRB_REG,Copy_u8_pin );break;
				case PORTC: SET_BIT(DDRC_REG,Copy_u8_pin );break;
				case PORTD: SET_BIT(DDRD_REG,Copy_u8_pin );break;
			}
		}
		else
		{
			switch(Copy_u8_port)
			{
				/* SET Direction ---> INPUT*/
				case PORTA: CLEAR_BIT(DDRA_REG,Copy_u8_pin );break;
				case PORTB: CLEAR_BIT(DDRB_REG,Copy_u8_pin );break;
				case PORTC: CLEAR_BIT(DDRC_REG,Copy_u8_pin );break;
				case PORTD: CLEAR_BIT(DDRD_REG,Copy_u8_pin );break;

			}
		}
		
	}
}

/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_Val
* Purpose      : Set pin value
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_pin, u8 Copy_u8_val
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Pin_Val(u8 Copy_u8_port, u8 Copy_u8_pin, u8 Copy_u8_val)
{
	if(Copy_u8_val==HIGH || Copy_u8_val==LOW )
	{
		if(Copy_u8_val==HIGH)
		{
			switch(Copy_u8_port)
			{
				/* SET Direction ---> OUTPUT*/
				case PORTA: SET_BIT(PORTA_REG,Copy_u8_pin );break;
				case PORTB: SET_BIT(PORTB_REG,Copy_u8_pin );break;
				case PORTC: SET_BIT(PORTC_REG,Copy_u8_pin );break;
				case PORTD: SET_BIT(PORTD_REG,Copy_u8_pin );break;
			}
		}
		else
		{
			switch(Copy_u8_port)
			{
				/* SET Direction ---> INPUT*/
				case PORTA: CLEAR_BIT(PORTA_REG,Copy_u8_pin );break;
				case PORTB: CLEAR_BIT(PORTB_REG,Copy_u8_pin );break;
				case PORTC: CLEAR_BIT(PORTC_REG,Copy_u8_pin );break;
				case PORTD: CLEAR_BIT(PORTD_REG,Copy_u8_pin );break;

			}
		}
		
	}
}

/*****************************************************************************
* Function Name: DIO_Vid_Get_Pin_Val
* Purpose      : Get pin value
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_pin
* Return value : void
*****************************************************************************/
u8 DIO_u8_Get_Pin_Val(u8 Copy_u8_port, u8 Copy_u8_pin)
{
	u8 LOC_u8_Val=0;
	switch(Copy_u8_port)
	{
		case PORTA:LOC_u8_Val= GET_BIT(PINA_REG,Copy_u8_pin );break;
		case PORTB:LOC_u8_Val= GET_BIT(PINB_REG,Copy_u8_pin );break;
		case PORTC:LOC_u8_Val= GET_BIT(PINC_REG,Copy_u8_pin );break;
		case PORTD:LOC_u8_Val= GET_BIT(PIND_REG,Copy_u8_pin );break;
		
	}
	return LOC_u8_Val;
	
	
}

/*****************************************************************************
* Function Name: DIO_Vid_Toggle_Pin_Val
* Purpose      : Toggle pin value
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_pin
* Return value : void
*****************************************************************************/
void DIO_Vid_Toggle_Pin_Val(u8 Copy_u8_port, u8 Copy_u8_pin)
{
	switch(Copy_u8_port)
	{
		/* SET Direction ---> INPUT*/
		case PORTA: TOGGLE_BIT(PORTA_REG,Copy_u8_pin);break;
		case PORTB: TOGGLE_BIT(PORTB_REG,Copy_u8_pin);break;
		case PORTC: TOGGLE_BIT(PORTC_REG,Copy_u8_pin);break;
		case PORTD: TOGGLE_BIT(PORTD_REG,Copy_u8_pin);break;

	}
}

/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Dir
* Purpose      : Set Port Direction
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_dir
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Port_Dir(u8 Copy_u8_port,  u8 Copy_u8_dir)
{
	if(Copy_u8_dir==PORT_OUTPUT)
	{
		switch(Copy_u8_port)
		{
			/* SET Direction ---> INPUT*/
			case PORTA: DDRA_REG=PORT_OUTPUT;break;
			case PORTB: DDRB_REG=PORT_OUTPUT;break;
			case PORTC: DDRC_REG=PORT_OUTPUT;break;
			case PORTD: DDRD_REG=PORT_OUTPUT;break;

		}
	}
	else
	{
		switch(Copy_u8_port)
		{
			/* SET Direction ---> INPUT*/
			case PORTA: DDRA_REG=PORT_INPUT;break;
			case PORTB: DDRB_REG=PORT_INPUT;break;
			case PORTC: DDRC_REG=PORT_INPUT;break;
			case PORTD: DDRD_REG=PORT_INPUT;break;

		}
		
	}
	
}

/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Val
* Purpose      : Set Port Value
* Parameters   : u8 Copy_u8_port, u8 Copy_u8_val
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Port_Val(u8 Copy_u8_port,  u8 Copy_u8_val)
{
	switch(Copy_u8_port)
	{
		
		case PORTA: PORTA_REG=Copy_u8_val;break;
		case PORTB: PORTB_REG=Copy_u8_val;break;
		case PORTC: PORTC_REG=Copy_u8_val;break;
		case PORTD: PORTD_REG=Copy_u8_val;break;

	}
	
}

