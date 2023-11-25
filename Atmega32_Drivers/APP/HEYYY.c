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
	/*DIO_Vid_Set_Port_Dir(LCD_DPORT,PORT_OUTPUT);
	//DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	//DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	//DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);*/
	
	LCD_Vid_Init();
	
	/*LCD_Vid_Send_Data('a');
	//LCD_Send_String("ahmed22");
	
	//DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT);
	//DIO_Vid_Set_Pin_Dir(PORTD,PIN6,INPUT);
//	u8 i=253; */


/*u8 data[8]= { 
	0x0E,
	0x0A,
	0x04,
	0x04,
	0x0A,
	0x15,
	0x04,
	0x0A,
	};
	u8 ball[8]= {
		  0x00,
		  0x00,
		  0x0E,
		  0x1F,
		  0x1F,
		  0x0E,
		  0x00,
		  0x00
	};
	u8 a[8]= {
		  0x04,
		  0x04,
		  0x04,
		  0x04,
		  0x04,
		  0x04,
		  0x04,
		  0x04
	};
	u8 h[8]= {
		 0x00,
		 0x00,
		 0x18,
		 0x04,
		 0x02,
		 0x1F,
		 0x00,
		 0x00
	};
	LCD_Vid_Draw_data(0,data,0,0);
	LCD_Vid_Draw_data(2,data,6,0);*/
	
	/*for( int x=1;x<6;x++)
	{
		LCD_Vid_Draw_data(1,a,x,0);
		_delay_ms(200);
		LCD_Vid_Draw_data(1,h,x,0);
		_delay_ms(200);
		
	}*/
		
	
/*LCD_Vid_GOTOXY(5,1);
LCD_Send_String("ahmed");
* /

//DIO_Vid_Set_Pin_Dir(PORTA,PIN0,INPUT);
/* Active Pull up Resistor*/
/*
DIO_Vid_Set_Pin_Val(PORTA,PIN0,HIGH);
Make Pin1 in PORTA OUTPUT
DIO_Vid_Set_Pin_Dir(PORTA,PIN1,OUTPUT); */


u8 key=0xff ;
u8 key2=0xff ;

/* PORT DIR */
DIO_Vid_Set_Port_Dir(LCD_DPORT,0xf0) ;
DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT) ;
DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT) ;
DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT) ;

LCD_Vid_Init() ;
KEYPAD_Vid_Init() ;

u8 n1,n2,res=0,i=0;


    while (1) 
    {
		//key=KEYPAD_u8_Get_Key() ;

			key=KEYPAD_u8_Get_Key() ;
			if(key == '1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6'||key=='7'||key=='8'||key=='9'){

				//LCD_Vid_Send_Data(key) ;
				n1= asc_to_int(key);
				LCD_Send_Number(n1);
				
			}
		
		
			if(key=='D'){
				
				LCD_Vid_Send_Data('+');
				
			}
		
		
			key2=KEYPAD_u8_Get_Key() ;
			if(key2 == '1' || key2=='2' || key2=='3' || key2=='4' || key2=='5' || key2=='6'||key=='7'||key2=='8'||key2=='9'){

				//LCD_Vid_Send_Data(key) ;
				n2= asc_to_int(key2);
				LCD_Send_Number(n2);
			}
			
		
		if(key=='#'){
			res=n1+n2;
			LCD_Vid_Send_Data('=');
			LCD_Send_Number(res);
			
		}
		i++;
	}
			
		
	if(key=='C'){
			
			LCD_Vid_Send_Command(1) ;
		}
		
		
		
	
		
	}
	

