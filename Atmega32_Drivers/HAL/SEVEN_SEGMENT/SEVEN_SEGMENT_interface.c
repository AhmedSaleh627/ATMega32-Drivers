/*
 * SEVEN_SEGMENT_interface.c
 *
 * Created: 8/27/2023 4:09:14 PM
 *  Author: Ahmed saleh
 */

#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
/*****************************************************************************
* Function Name: SSD_Vid_Init
* Purpose      : Initialize Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SSD_Vid_Init()
{
	DIO_Vid_Set_Pin_Dir(PORTA,PIN4,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTA,PIN5,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTA,PIN6,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTA,PIN7,OUTPUT);
	
	DIO_Vid_Set_Pin_Dir(PORTB,PIN2,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTB,PIN1,OUTPUT);
}

/*****************************************************************************
* Function Name: SSD_EN1
* Purpose      : Enable First Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SSD_EN1()
{
	DIO_Vid_Set_Pin_Val(PORTB,PIN2,HIGH);
	
}

/*****************************************************************************
* Function Name: SSD_EN2
* Purpose      : Enable Second Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SSD_EN2()
{
	DIO_Vid_Set_Pin_Val(PORTB,PIN1,HIGH);
}

/*****************************************************************************
* Function Name: SSD_DIS1
* Purpose      : Disable First Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SSD_DIS1()
{
	DIO_Vid_Set_Pin_Val(PORTB,PIN2,LOW);
	
}

/*****************************************************************************
* Function Name: SSD_DIS2
* Purpose      : Disable Second Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SSD_DIS2()
{
	DIO_Vid_Set_Pin_Val(PORTB,PIN1,LOW);
}

/*****************************************************************************
* Function Name: SEVEN_SEGMENT_Write_Val
* Purpose      : Write Value On Seven Segment
* Parameters   : void
* Return value : void
*****************************************************************************/
void SEVEN_SEGMENT_Write_Val(u8 number)
{
	if(number<10)
	{
		DIO_Vid_Set_Pin_Val(PORTA,PIN4,GET_BIT(number,0));
		DIO_Vid_Set_Pin_Val(PORTA,PIN5,GET_BIT(number,1));
		DIO_Vid_Set_Pin_Val(PORTA,PIN6,GET_BIT(number,2));
		DIO_Vid_Set_Pin_Val(PORTA,PIN7,GET_BIT(number,3));
		
	}
}