#ifndef VECT_TABLE_H_
#define VECT_TABLE_H_

#define ISR(__vector_num) 	void __vector_num(void)__attribute__((signal));\
								void __vector_16(void)	
															
#define INT0 __vector_1
#define INT1 2	__vector_2
#define INT2 3	__vector_3												
#define ADC_INT __vector_16


#endif