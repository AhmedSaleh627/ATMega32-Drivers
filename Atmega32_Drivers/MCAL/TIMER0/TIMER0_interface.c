/*
 * TIMER0_interface.c
 *
 * Created: 9/23/2023 2:37:44 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "TIMER0_Config.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "../GIE_interrupt/GIE_interface.h"
#include "../../LIB/Vect_table.h"


/*
 FS=16MH 
 Prescaler=64 
 
 timer_overflow= 1.024 ; 

 */

void (*CTC_Callback)(void)=0 ; 
void (*OVI_Callback)(void)=0 ; 
void TIM0_Vid_CTC_Init(void){
    
	 /* select CTC MODE  */
	SET_BIT(TCCR0_REG,3) ; 
CLEAR_BIT(TCCR0_REG,6) ;
     /* SET OCR_REG  */
	    OCR0_REG= OCR_VAL ; 
       /*  enable GIE*/
       GIE_Vid_Enable() ;
	/*  ENABLE PIE( ctc interrupt) */
	  SET_BIT(TIMSK_REG,1) ;
	
}

void TIM0_Vid_start(u8 copy_u16_prescaler){
	
	TCCR0_REG &=0b11111000 ; 
	TCCR0_REG |=copy_u16_prescaler ; 	
	//TCCR0_REG=copy_u16_prescaler ; 
}

void TIM0_Vid_Stope(void){
	
	TCCR0_REG=0x00 ;
}

void TIM0_Vid_OVInterrupt_Enable(void) {
	
	/* ENABLE GLOBAL INTERRUPT (GIE) */
	GIE_Vid_Enable() ; 
	/* enbale timer interrupt (PIE) */
	SET_BIT(TIMSK_REG,0) ; 
	
	
}

void TIM0_Vid_Delayms(u32 copy_u32_delay){
	
	u32 Loc_u32_count=0 ; 
	
	copy_u32_delay=copy_u32_delay/1.024 ; 
	
	TCCR0_REG=0x03 ;  // timer start ( prescaler 64) 
	
	while(Loc_u32_count< copy_u32_delay){
		
		Loc_u32_count++ ; 
		while(GET_BIT(TIFR_REG,0)==0) ;  // POLLING overflow flag 
		SET_BIT(TIFR_REG,0) ;  // clr flag
		
	}
	
	TCCR0_REG=0x00 ; 
	//Loc_u32_count=0; 
	
}
void TIM0_Vid_Fast_PWM(u8 copy_u8_duty){
	
	/* select prescaler  */
	
	TIM0_Vid_start(_64_prescaling) ; 
	
	/* fast pwm  */ 
	SET_BIT(TCCR0_REG,3) ; 
	SET_BIT(TCCR0_REG,6) ; 
	/* non inverting mode  */
	CLEAR_BIT(TCCR0_REG,4) ; 
	SET_BIT(TCCR0_REG,5) ;
	
	OCR0_REG=copy_u8_duty*2.56 ; 
	
	while(GET_BIT(TIFR_REG,1)==0) ; 
	SET_BIT(TIFR_REG,1) ; 
	
	
	
	
	
}
void TIM0_Vid_SetCallBack(u8 copy_u8_mode , void(*ptr)(void))
{
	if(copy_u8_mode==OVI_MODE){
		
		OVI_Callback=ptr ; 
	}
	else if(copy_u8_mode==CTC_MODE){
		
		CTC_Callback=ptr ; 
	}
}
ISR(TIMER0_COMP){
	
	CTC_Callback() ; 
	
}

ISR(TIMER0_OF){
	
	OVI_Callback() ;
	
}