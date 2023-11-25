/*
 * ADC_interface.h
 *
 * Created: 9/16/2023 4:00:14 PM
 *  Author: Ahmed saleh
 */ 

#include "../../LIB/STD_Type.h"
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum {
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7,
}ADC_Channels;

#define PRESCALER

void ADC_Vid_Init(void) ;
uint16 ADC_u16_Read( ADC_Channels copy_u8_ch) ;
void ADC_Vid_Set_CallBack(void(*ptr_set_callback)(void));
void ADC_Vid_Set_CallBack2(void(*ptr2_set_callback)(void));
void ADC_EnableInt() ; 
void ADC_DisableInt() ; 


#endif /* ADC_INTERFACE_H_ */