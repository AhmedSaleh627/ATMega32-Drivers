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

#include "LIB/Vect_table.h"

#define F_CPU 16000000UL
#include "util/delay.h"



volatile static u32 overflow_ticks=0 ;

volatile static u32 on_ticks=0 ;

volatile static u8 dutycycle=10 ;

void  HW_ICU(void) ;


int main(void)
{
	  LCD_Vid_Init() ;
	  DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT) ;
	  TIMER1_Vid_NormalMode_Init() ;
	  GIE_Vid_Enable();
	  Timer1_U8CaptureEventEnableInterrupt();
	  while (1)
	  {

			TIM0_Vid_Fast_PWM(dutycycle) ;
			Timer1_U8CaptureEventSetCallBack(HW_ICU);
			Timer1_Edge_Select(RISING_EDGE);
			LCD_Vid_GOTOXY(0,0) ;

			LCD_Send_Number( overflow_ticks) ;
			_delay_ms(50) ;
			LCD_Vid_GOTOXY(0,1) ;
			LCD_Send_Number(on_ticks) ;
			_delay_ms(50);
			dutycycle++;
			if(dutycycle>=100)
			{
				LCD_Vid_GOTOXY(0,1);
				CLR_Display();
				LCD_Vid_GOTOXY(1,1);
				CLR_Display();
				dutycycle=10;
			}
			

	
		 
	  }
	
}


void  HW_ICU(void){

	static u8 count=0 ;
	count ++ ;
	
	if(count==1){
		TIMER1_Vid_RestTimer() ;
		Timer1_Edge_Select(FALLING_EDGE);
		
	}
	if(count==2){
		on_ticks=TIMER1_u16_Read_TimerVal() ;
		
	Timer1_Edge_Select(RISING_EDGE);
		
	}
	if(count==3){
		
		overflow_ticks=TIMER1_u16_Read_TimerVal();

	}
	
	
	
}