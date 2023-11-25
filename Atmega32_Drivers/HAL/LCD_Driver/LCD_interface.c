/*
 * LCD_interface.c
 *
 * Created: 9/1/2023 5:26:34 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#define F_CPU 16000000UL
#include<util/delay.h>
#define DATA_LENGTH 4

static void SHData(u8 copy_u8_data)
{
	u8 loc_u8_LCD_PIN[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN};
	u8 loc_u8_it=0;
	for(loc_u8_it=0;loc_u8_it<DATA_LENGTH;loc_u8_it++)
	{
		DIO_Vid_Set_Pin_Val(LCD_DPORT,loc_u8_LCD_PIN[loc_u8_it],GET_BIT(copy_u8_data,loc_u8_it));
	}
}
void Send_Enable()
{
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,LOW);
}



/*****************************************************************************
* Function Name: LCD_Vid_Send_Command
* Purpose      : Send Command
* Parameters   : u8 copy_u8_command
* Return value : void
*****************************************************************************/
void LCD_Vid_Send_Command(u8 copy_u8_command)
{
	/* SET RS ---> Low	to send command */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,LOW);
	/* SET RW ---> Low	to send command */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	
	#if LCD_MODE==FOUR_BIT
	/*Send HSB Command*/
	SHData(copy_u8_command>>4);
	Send_Enable();
	/*Send LSB Command*/
	SHData(copy_u8_command);
	Send_Enable();
	
	
	#elif LCD_MODE==EIGHT_BIT
	/*SEND COMMAND */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_command);
	
	/*Send Enable */
	Send_Enable();
	#endif
	
}

/*****************************************************************************
* Function Name: LCD_Vid_Send_Data
* Purpose      : Send Data 
* Parameters   : u8 copy_u8_data
* Return value : void
*****************************************************************************/
void LCD_Vid_Send_Data(u8 copy_u8_data)
{
	/* SET RS ---> Low	to send command */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,HIGH);
	/* SET RW ---> Low	to send command */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	
	#if LCD_MODE==FOUR_BIT
	/*Send HSB Command*/
	SHData(copy_u8_data>>4);
	Send_Enable();
	/*Send LSB Command*/
	SHData(copy_u8_data);
	Send_Enable();
	
	
	#elif LCD_MODE==EIGHT_BIT
	/*SEND COMMAND */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_data);
	
	/*Send Enable */
	Send_Enable();
	#endif
	
}

/*****************************************************************************
* Function Name: LCD_Vid_Init
* Purpose      : Initialize the LCD
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_Vid_Init(void)
{
	  DIO_Vid_Set_Port_Dir(LCD_DPORT,PORT_OUTPUT) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT) ;


	_delay_ms(40);
	#if LCD_MODE==FOUR_BIT
	/*Send Function Set( N=1 ---> Enable the two lines / F=0 ---> Font (5*7) ) */
	SHData(0b0010);
	Send_Enable();
	SHData(0b0010);
	Send_Enable();
	SHData(0b1000);
	Send_Enable();
	#elif LCD_MODE==EIGHT_BIT
	
	/*Send Function Set( N=1 ---> Enable the two lines / F=0 ---> Font (5*7) ) */
	LCD_Vid_Send_Command(0b00111000);
	#endif
	/*Display On/OFF ( D=1 ---> Display on / C=0 ---> cursor off B=0 ---> Blink off ) */
	LCD_Vid_Send_Command(0b00001100);
	/*Send CLR*/
	LCD_Vid_Send_Command(0x01);
}
void LCD_Send_String(u8 *copy_u8_char)
{
	u8 index=0;
	while(copy_u8_char[index]!='\0')
	{
		LCD_Vid_Send_Data(copy_u8_char[index]);
		index++;
	}
}

u8 int_to_asc(u8 copy_u8_int)
{
	int number=0;
	switch(copy_u8_int)
	{
		case 0:number=48;break;
		case 1:number=49;break;
		case 2:number=50;break;
		case 3:number=51;break;
		case 4:number=52;break;
		case 5:number=53;break;
		case 6:number=54;break;
		case 7:number=55;break;
		case 8:number=56;break;
		case 9:number=57;break;
		
		
	}
	return number;
}

u8 asc_to_int(u8 copy_u8_int)
{
	int number=0;
	switch(copy_u8_int)
	{
		case 48:number=0;break;
		case 49:number=1;break;
		case 50:number=2;break;
		case 51:number=3;break;
		case 52:number=4;break;
		case 53:number=5;break;
		case 54:number=6;break;
		case 55:number=7;break;
		case 56:number=8;break;
		case 57:number=9;break;
		
		
	}
	return number;
}


void CLR_Display()
{
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,LOW);
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	LCD_Vid_Send_Command(0b00000001);
	
}
void LCD_Vid_GOTOXY(u8 copy_u8_x , u8 copy_u8_y)
{
	u8 Loc_u8_AddDDRAM=0;
	if(copy_u8_y==0)
	{
		Loc_u8_AddDDRAM=copy_u8_x;
	}
	else if(copy_u8_y==1)
	{
		Loc_u8_AddDDRAM=copy_u8_x+0x40;
	}
	/* Loc_u8_AddDDRAM=copy_u8_x + copy_u8_y *0x40 */
	
	/* Set DDRAM */
	SET_BIT(Loc_u8_AddDDRAM,7);
	LCD_Vid_Send_Command(Loc_u8_AddDDRAM);
}

void LCD_Vid_Draw_data(u8 copy_u8_pattern , u8 *copy_u8_data,u8 copy_u8_x , u8 copy_u8_y)
{
	/* CGRAM Address */
	u8 LOC_u8_AddCGRAM=copy_u8_pattern*8;
	u8 LOC_u8_in=0;
	/* SET CGRAM */
	CLEAR_BIT(LOC_u8_AddCGRAM,7);
	SET_BIT(LOC_u8_AddCGRAM,6);
	LCD_Vid_Send_Command(LOC_u8_AddCGRAM);
	/* draw data in CGRAM */
	for(LOC_u8_in=0;LOC_u8_in<8;LOC_u8_in++)
	{
		LCD_Vid_Send_Data(copy_u8_data[LOC_u8_in]);
	}
	/* Set DDRAM to Display */
	LCD_Vid_GOTOXY(copy_u8_x,copy_u8_y);
	LCD_Vid_Send_Data(copy_u8_pattern);
	
	
}

void LCD_Send_Number(u64 num)
{
	u32 arr[100],i=0,j=0;
	if(num == 0)
	{
		LCD_Vid_Send_Data('0');
	}
	else
	{
		while(num)
		{
			arr[i]=num%10+'0';
			num/=10;
			i++;
		}
		for(j=i;j>0;j--)
		{
			LCD_Vid_Send_Data(arr[j-1]);
		}
	}
}
