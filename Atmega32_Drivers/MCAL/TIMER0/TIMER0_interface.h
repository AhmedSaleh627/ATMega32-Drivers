/*
 * TIMER0_interface.h
 *
 * Created: 9/23/2023 2:37:28 PM
 *  Author: Ahmed saleh
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#define	 TIMER_STOPE      0
#define  No_prescaling    1
#define  _8_prescaling     2
#define  _64_prescaling    3
#define  _256_prescaling   4
#define  _1024_prescaling  5


/*  OCR VAL  */

#define  OCR_VAL     250



#define OVI_MODE     1

#define CTC_MODE     2


void TIM0_Vid_Delayms(u32 copy_u32_delay) ;

void TIM0_Vid_SetCallBack(u8 copy_u8_mode , void(*ptr)(void)) ;
void TIM0_Vid_start(u8 copy_u8_prescaler) ;
void TIM0_Vid_Stope(void) ;
void TIM0_Vid_OVInterrupt_Enable(void) ;
void TIM0_Vid_CTC_Init(void) ;
void TIM0_Vid_Fast_PWM(u8 copy_u8_duty) ;

#endif /* TIMER0_INTERFACE_H_ */