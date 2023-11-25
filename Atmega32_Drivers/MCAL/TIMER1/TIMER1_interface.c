#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "../../LIB/Vect_table.h"
#include "TIMER1_private.h"
#include "TIMER1_interface.h"
#include "../GIE_interrupt/GIE_interface.h"
#include "../GIE_interrupt/EXIT_interface.h"
#include "../../LIB/Vect_table.h"
#include "../TIMER0/TIMER0_Config.h"

void (*ptr_ICU)(void)=0 ; 


void TIMER1_Vid_ICR_FastPWM_Init(void){
	
	/* fast pwm oc1a :non-inverting mode */
	SET_BIT(TCCR1A_REG,7) ;
	CLEAR_BIT(TCCR1A_REG,6) ;
	/* mode: fastpwm : ICR1 */
	CLEAR_BIT(TCCR1A_REG,0) ;
	SET_BIT(TCCR1A_REG,1) ;
	SET_BIT(TCCR1B_REG,3) ;
	SET_BIT(TCCR1B_REG,4) ;
	
	/* SET ICR1 VAL  */
	ICR1_REG=40000 ;
	OCR1A_REG=2000 ;  // set compare reg
	
	/*set prescaler : 8 */
	CLEAR_BIT(TCCR1B_REG,0) ;
	SET_BIT(TCCR1B_REG,1) ;
	CLEAR_BIT(TCCR1B_REG,2) ;
	
	
}

void TIMER1_Vid_SetCompareVal(u32 copy_u32_val){
	
	OCR1A_REG=copy_u32_val ;
}


void TIMER1_Vid_NormalMode_Init(){
	
	/*set prescaler : 64 */
	SET_BIT(TCCR1B_REG,0) ;
	CLEAR_BIT(TCCR1B_REG,1) ;
	SET_BIT(TCCR1B_REG,2) ;
	
}

void TIMER1_Vid_RestTimer(void){
	
	
	/* rest timer val  */
	TCNT1_REG=0x0000 ;
}

uint16 TIMER1_u16_Read_TimerVal(){
	
	return TCNT1_REG ;
	
	
	
}
void Timer1_U8CaptureEventEnableInterrupt()
{
	SET_BIT(TIMSK_REG, 5);
}


void Timer1_Edge_Select(u8 SENSE_CONTROL)
{
		if(SENSE_CONTROL ==RISING_EDGE ){
			
		
			SET_BIT(TCCR1B_REG, 6);
		}
		if(SENSE_CONTROL ==FALLING_EDGE)
		{
			CLEAR_BIT(TCCR1B_REG, 6);
		}
	
		
}
void Timer1_U8CaptureEventSetCallBack(void(*ptr)(void))
{
	ptr_ICU=ptr;
	
}

ISR(TIMER1_CAPT){
	
	ptr_ICU() ;
	
}