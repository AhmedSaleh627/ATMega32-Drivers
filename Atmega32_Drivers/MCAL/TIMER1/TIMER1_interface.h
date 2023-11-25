/*
 * TIMER1_interface.h
 *
 * Created: 9/30/2023 4:47:09 PM
 *  Author: Ahmed saleh
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



void TIMER1_Vid_ICR_FastPWM_Init(void) ;
void TIMER1_Vid_SetCompareVal(u32 copy_u32_val) ;
void TIMER1_Vid_NormalMode_Init() ;
void TIMER1_Vid_RestTimer(void) ;
uint16 TIMER1_u16_Read_TimerVal() ;



void Timer1_U8CaptureEventEnableInterrupt();
void Timer1_Edge_Select(u8 SENSE_CONTROL);
void Timer1_U8CaptureEventSetCallBack(void(*ptr)(void));


#endif /* TIMER1_INTERFACE_H_ */