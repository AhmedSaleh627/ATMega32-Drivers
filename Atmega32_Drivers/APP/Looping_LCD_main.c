#include "LIB/STD_Type.h"
#include "MCAL/Watch_Dog/WatchDog_interface.h"
#include "LIB/BITMATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE_interrupt/GIE_interface.h"
#include "MCAL/GIE_interrupt/EXIT_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "HAL/DC_Motor_Driver/DC_Motor_interface.h"
#include "HAL/LCD_Driver/LCD_config.h"
#include "HAL/LCD_Driver/LCD_interface.h"
#include <string.h>
#include "LIB/Vect_table.h"

#define F_CPU 16000000UL
#include "util/delay.h"

char *LargeText="________--________-- ";
u8 iCursor=0;
u8 iLineNumber=1;
 
void UpdateDisplay();
int main(void)
{
	  
	LCD_Vid_Init();
	
	  while (1)
	  {
		
		UpdateDisplay();
		_delay_ms(100);
				
	  }

	
}
void UpdateDisplay()
{
	u8 iLenofLargeText=strlen(LargeText);
	if(iCursor==(iLenofLargeText-1))
	{
		iCursor=0;
	}
	LCD_Vid_GOTOXY(0,iLineNumber);
	
	if(iCursor<iLenofLargeText-16)
	{
		 for(u8 iChar=iCursor; iChar<iCursor+16; iChar++)
		 {
			 LCD_Vid_Send_Data(LargeText[iChar]);
		 }
	}
	else
	{
		for(u8 iChar=iCursor;iChar< (iLenofLargeText-1);iChar++)
		{
			  LCD_Vid_Send_Data(LargeText[iChar]);
		}
		for(u8 iChar=0;iChar<=16-(iLenofLargeText-iCursor);iChar++)
		{
			 LCD_Vid_Send_Data(LargeText[iChar]);
		}
	}
	iCursor++;
	
}