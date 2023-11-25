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

void  SW_ICU(void) ;


int main(void)
{
	
	  /*  Lcd pin init*/
	  /* PORT DIR */
	  DIO_Vid_Set_Port_Dir(LCD_DPORT,0xf0) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT) ;
	  DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT) ;
	  
	  
	  DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT) ;
	  DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT) ;
	  LCD_Vid_Init() ;
	  
	  
	  TIMER1_Vid_NormalMode_Init() ;
	  
	  /* enable global interrupt */
	  GIE_Vid_Enable();
	  EXT_Vid_Interrupt_Init(RISING_EDGE) ;
	  EXT_Vid_Interrupt0() ;
	  EXT_Vid_Set_CallBack(SW_ICU) ;
	  
	  while (1)
	  {
		  
		  TIM0_Vid_Fast_PWM(50) ;
		  LCD_Vid_GOTOXY(0,0) ;
		  LCD_Send_Number( overflow_ticks) ;
		  _delay_ms(50) ;
		  LCD_Vid_GOTOXY(0,1) ;
		  LCD_Send_Number(on_ticks) ;
		  _delay_ms(50) ;
	  }
	
}


void  SW_ICU(void){

	static u8 count=0 ;
	count ++ ;
	
	if(count==1){
		TIMER1_Vid_RestTimer() ;
		EXT_Vid_Interrupt_Init(FALLING_EDGE) ;
		
	}
	if(count==2){
		on_ticks=TIMER1_u16_Read_TimerVal() ;
		
		EXT_Vid_Interrupt_Init(RISING_EDGE) ;
		
	}
	if(count==3){
		
		overflow_ticks=TIMER1_u16_Read_TimerVal();

	}
	
	
	
}