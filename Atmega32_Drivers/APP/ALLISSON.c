#include "LIB/STD_Type.h"
#include "MCAL/DIO/DIO_private.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include "HAL/LCD_Driver/LCD_config.h"
#define F_CPU 16000000UL
#include<util/delay.h>

int main(void)
{
	DIO_Vid_Set_Port_Dir(LCD_DPORT,PORT_OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	
	LCD_Vid_Init();
	u8 Allison[8]= {
	0x1F,
	0x15,
	0x1B,
	0x04,
	0x15,
	0x04,
	0x0A,
	0x0A
	};
	u8 Maguire[8]= {
		0x1F,
		0x15,
		0x1B,
		0x04,
		0x15,
		0x04,
		0x0A,
		0x0A
	};
	u8 Silva[8]= {
	0x1F,
	0x15,
	0x1B,
	0x04,
	0x15,
	0x04,
	0x0A,
	0x0A
	};
	u8 Fence[8]= {
		 0x1C,
		 0x10,
		 0x10,
		 0x10,
		 0x10,
		 0x10,
		 0x1C,
		 0x00
	};
	u8 ball[8]= {
		  0x00,
		  0x00,
		  0x04,
		  0x0E,
		  0x1B,
		  0x0E,
		  0x04,
		  0x00
	};
	u8 empty[8]= {
		 0x00,
		 0x00,
		 0x00,
		 0x00,
		 0x00,
		 0x00,
		 0x00,
		 0x00
	};
	u8 action[8]= {
		0x1F,
		0x15,
		0x1B,
		0x05,
		0x15,
		0x04,
		0x1A,
		0x02
	};
		u8 action2[8]= {
			  0x1F,
			  0x15,
			  0x1B,
			  0x14,
			  0x15,
			  0x04,
			  0x0B,
			  0x08
		};
		u8 action3[8]= {
			 0x1F,
			 0x15,
			 0x1B,
			 0x15,
			 0x15,
			 0x04,
			 0x0A,
			 0x0A
		};
	
	
	while(1)
	{
		
		LCD_Vid_Draw_data(0,Allison,1,1);
		LCD_Vid_Draw_data(1,Silva,5,0);
		LCD_Vid_Draw_data(2,Maguire,5,1);
		LCD_Vid_Draw_data(3,Fence,0,0);
		
		LCD_Vid_Draw_data(4,ball,4,1);
		_delay_ms(1000);
		LCD_Vid_Draw_data(6,action,5,1);
		
		LCD_Vid_Draw_data(5,empty,4,1);
		_delay_ms(100);
		LCD_Vid_Draw_data(2,Maguire,5,1);
		LCD_Vid_Draw_data(4,ball,3,1);
	
		LCD_Vid_Draw_data(5,empty,3,1);
		_delay_ms(100);
		LCD_Vid_Draw_data(4,ball,2,1);
		_delay_ms(1000);
		LCD_Vid_Draw_data(7,action2,1,1);
	
		LCD_Vid_Draw_data(5,empty,2,1);
		_delay_ms(100);
		LCD_Vid_Draw_data(0,Allison,1,1);
		LCD_Vid_Draw_data(4,ball,4,0);
		_delay_ms(1000);
		LCD_Vid_Draw_data(6,action,5,0);

		LCD_Vid_Draw_data(5,empty,4,0);
		LCD_Vid_Draw_data(8,action3,1,1);
		LCD_Vid_Draw_data(4,ball,3,0);
		LCD_Vid_Draw_data(5,empty,3,0);
		_delay_ms(100);
		LCD_Vid_Draw_data(4,ball,2,0);
		LCD_Vid_Draw_data(5,empty,2,0);
		
		_delay_ms(100);
		LCD_Vid_Draw_data(4,ball,1,0);
		LCD_Vid_Draw_data(5,empty,1,0);
		_delay_ms(100);
		CLR_Display_two();
		LCD_Send_String("GOAALLLLL!!!");
		_delay_ms(1500);
		CLR_Display_two();
		
		
		
	}
}