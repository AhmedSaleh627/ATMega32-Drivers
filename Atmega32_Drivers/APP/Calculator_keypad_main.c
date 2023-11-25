#include "LIB/STD_Type.h"
#include "MCAL/DIO/DIO_private.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED_Driver/LED_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "HAL/LCD_Driver/LCD_config.h"
#include "HAL/KeyPad/Keypad_interface.h"
#include "HAL/KeyPad/KeyPad_Config.h"

#define F_CPU 16000000UL
#include<util/delay.h>
int main(void)
{

	u8 key=0xff ;
	u8 key2=0xff ;
	u8 key3=0xff;
	u8 key4=0xff;

	/* PORT DIR */
	DIO_Vid_Set_Port_Dir(LCD_DPORT,PORT_OUTPUT) ;
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT) ;
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT) ;
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT) ;
	u8 counter=0,n1=0,n2=0,flagadd=0,x=0,i=0,j=0,temp1=0,d=0,d2=0,temp3=0;
	uint16 temp2=0,password=0,password2=0,temp4=0;
	u8 flag=0;
	u8 resetFlag = 0;
	
	uint16 num1=0;
	uint16 num2=0;
	u8 k=0;
	uint16 res;
	LCD_Vid_Init() ;
	KEYPAD_Vid_Init() ;
	while (1)
	{
			
		while (1) {
			// ...

			if (resetFlag == 1) {
				// Reset the calculator
				num1 = 0;
				num2 = 0;
				temp1 = 0;
				temp2 = 0;
				temp3 = 0;
				temp4 = 0;
				i = 0;
				j = 0;
				resetFlag = 0;  // Reset the flag
				CLR_Display_two();  // Clear the LCD screen
				continue;  // Continue accepting input
			}
			else
			{
				break;
			}
		}
		
		while(1)
		{
			
			key2=KEYPAD_u8_Get_Key() ;
			d2=asc_to_int(key2);
			
			if(key2 == '0' ||key2 == '1' || key2=='2' || key2=='3' || key2=='4' || key2=='5' || key2=='6'||key2=='7'||key2=='8'||key2=='9'  )
			{
				i++;
				switch (i){
					
					case 1:
					temp1=d2;
					LCD_Vid_GOTOXY(0,0);
					LCD_Send_Number_2(temp1);
					break;
					case 2:
					temp1=temp1*10+(d2);
					LCD_Vid_GOTOXY(0,0);
					LCD_Send_Number_2(temp1);
					break;
					case 3:
					temp2=temp1*10+(d2);
					LCD_Vid_GOTOXY(0,0);
					LCD_Send_Number_2(temp2);
					break;
					case 4:
					temp2=temp2*10+(d2);
					LCD_Vid_GOTOXY(0,0);
					LCD_Send_Number_2(temp2);
					break;
					case 5:
					temp2=temp2*10+(d2);
					LCD_Vid_GOTOXY(0,0);
					LCD_Send_Number_2(temp2);
					break;
					
				}
				
			}
			
			if(key2=='A' || key2=='B' || key2=='C' || key2=='D'   )
			{
				switch(key2)
				{
					case 'A': LCD_Vid_Send_Data('/');break;
					case 'B': LCD_Vid_Send_Data('x');break;
					case 'C': LCD_Vid_Send_Data('-');break;
					case 'D': LCD_Vid_Send_Data('+');break;
				}
				
				if(temp2==0)
				{
					num1=temp1;
					break;
				}
				else
				{
					num1=temp2;
					break;
				}
			}
			
			
		}
		while(1)
		{
			key=KEYPAD_u8_Get_Key() ;
			d2=asc_to_int(key);
			if(key == '0' ||key == '1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6'||key=='7'||key=='8'||key=='9'  )
			{
				
				j++;
				if(key2=='A' || key2=='B' || key2=='C' || key2=='D')
				{
					
				}
				switch (j){
					case 1:
					temp3=d2;
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number_2(temp3);
					break;
					case 2:
					temp3=temp3*10+(d2);
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number_2(temp3);
					break;
					case 3:
					temp4=temp3*10+(d2);
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number_2(temp4);
					break;
					case 4:
					temp4=temp4*10+(d2);
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number_2(temp4);
					break;
					case 5:
					temp4=temp4*10+(d2);
					LCD_Vid_GOTOXY(5,0);
					LCD_Send_Number_2(temp4);
					break;
				}

				
			}
			if(temp4==0)
			{
				num2=temp3;
				
			}
			else
			{
				num2=temp4;
				
			}
			if(key=='#')
			{
				LCD_Vid_GOTOXY(2,1);
				LCD_Vid_Send_Data('=');
				
				if(key2=='A')
				{
					LCD_Vid_GOTOXY(4,1);
					LCD_Send_Number_2(num1/num2);
					break;
				}
				else if(key2=='B')
				{
					LCD_Vid_GOTOXY(4,1);
					LCD_Send_Number_2(num1*num2);
					break;
				}
				else if(key2=='C')
				{
					LCD_Vid_GOTOXY(4,1);
					LCD_Send_Number_2(num1-num2);
					break;
				}
				else
				{
					LCD_Vid_GOTOXY(4,1);
					LCD_Send_Number_2(num1+num2);
					break;
				}
			}
			
			
		}
		
		while(1)
		{
			key3=KEYPAD_u8_Get_Key();
			if(key3=='*')
			{
				resetFlag = 1;  // Set the reset flag
				break;  // Break out of the current loop
			}
			
		}
	}
	

	
}


