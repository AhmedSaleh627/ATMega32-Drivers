/*
 * ADC_Config.h
 *
 * Created: 9/17/2023 6:50:48 PM
 *  Author: Ahmed saleh
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* -----------ADCSRA_REG Bits--------------- */
/* PreScaler Selection Bits */
#define  ADPS0 0
#define  ADPS1 1
#define  ADPS2 2

#define	 ADEN  7	//ADC Enable
#define	 ADSC  6	//ADC Start Conversion
#define  ADATE 5	//ADC Auto Trigger Enable
#define  ADIF  4	//ADC Interrupt Flag
#define  ADIE  3	//ADC Interrupt Enable

/* -----------ADMUX_REG Bits--------------- */
/* voltage reference mode */
#define	 REFS1 7	
#define	 REFS0 6

#define  ADLAR 5			//ADC Left Adjust Result

/* -----------SFIOR_REG Bits--------------- */
/* Auto Trigger  */
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

/*TYPES*/
#define ADC_MODE_AUTO_TRIGGER 1
#define ADC_MODE_SINGLE_CONVERSION 0
#define ADC_MODE_SELECTOR	ADC_MODE_SINGLE_CONVERSION



#endif /* ADC_CONFIG_H_ */