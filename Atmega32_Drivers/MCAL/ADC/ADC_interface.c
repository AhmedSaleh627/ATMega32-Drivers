/*
 * ADC_interface.c
 *
 * Created: 9/16/2023 4:10:19 PM
 *  Author: Ahmed saleh
 */ 

#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_Type.h"
#include "../GIE_interrupt/GIE_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_Config.h"
#include "../../LIB/Vect_table.h"

static void(*ptr_ADC_int)(void)=NULL;


void ADC_Vid_Init(void){
	
	/*  select Voltage Reference   */
	CLEAR_BIT(ADMUX_REG,REFS1) ;
	SET_BIT(ADMUX_REG,REFS0)  ;
	
	/* SELECT ADC MODE */
	#if    ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		SET_BIT(ADCSRA_REG,ADATE);		//Auto Trigger Enable
		/* SELECTING FREE RUNNING MODE */
		CLEAR_BIT(SFIOR_REG,ADTS2);
		CLEAR_BIT(SFIOR_REG,ADTS1);
		CLEAR_BIT(SFIOR_REG,ADTS0);
	#elif  ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		CLEAR_BIT(ADCSRA_REG,ADATE);
	#endif

	SET_BIT(ADCSRA_REG,ADIF);   // CLEAR INTERRUPT FLAG
	
	/*  ENABLE ADC */
	SET_BIT(ADCSRA_REG,ADEN) ;
	
	/* Select prescaler ---> 128  */
	
	SET_BIT(ADCSRA_REG,ADPS0) ;
	SET_BIT(ADCSRA_REG,ADPS1) ;
	SET_BIT(ADCSRA_REG,ADPS2) ;

}

uint16 ADC_u16_Read( ADC_Channels channel_num){
	/* SELECT CHANNEL */	
	ADMUX_REG&=0xF0;
	ADMUX_REG |=channel_num;
	/*  START conversion */
	SET_BIT(ADCSRA_REG,ADSC);
	
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
		return ADC_REG;
	#elif  ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
		while( (GET_BIT(ADCSRA_REG,ADSC))==0);
		return ADC_REG;
	#endif 
}

void ADC_EnableInt() 
{
	SET_BIT(ADCSRA_REG,ADIE);
}
void ADC_DisableInt() 
{	
	CLEAR_BIT(ADCSRA_REG,ADIE);
}

void ADC_Vid_Set_CallBack(void(*ptr_set_callback)(void))
{
	ptr_ADC_int=ptr_set_callback;
}




ISR(ADC_INT)
{
	if(ptr_ADC_int!=NULL)
	{
		ptr_ADC_int();
	}
}