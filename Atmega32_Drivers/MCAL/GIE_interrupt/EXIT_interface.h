/*
 * EXIT_interface.h
 *
 * Created: 09/09/2023 16:22:14
 *  Author: AMIT
 */ 


#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#define  RISING_EDGE      0
#define  FALLING_EDGE     1
#define  ANY_LOGIC_CHANGE 2
#define  LOW_LEVEL        3

void EXT_Vid_Interrupt_Init(u8 SENSE_CONTROL) ;
void EXT_Vid_Interrupt0() ;
void EXT_Vid_Interrupt1() ; 
void EXT_Vid_Set_CallBack(void(*ptr_set_callback)(void)) ;

#endif /* EXIT_INTERFACE_H_ */