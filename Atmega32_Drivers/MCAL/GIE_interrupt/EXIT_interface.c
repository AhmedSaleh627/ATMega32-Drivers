/*
 * EXIT_interface.c
 *
 * Created: 09/09/2023 16:21:35
 *  Author: AMIT
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "EXIT_interface.h"
#include "EXIT_private.h" 
#include "GIE_interface.h"  
#include "../DIO/DIO_private.h"
#include "../DIO/DIO_interface.h"


/* ptr to fun*/

void(*ptr_int0)(void) ;

void EXT_Vid_Interrupt_Init(u8 SENSE_CONTROL) {
	
	
	if(SENSE_CONTROL ==RISING_EDGE ){
		
		/* INT0*/
		SET_BIT(MCUCR_REG,ISC01) ;
		SET_BIT(MCUCR_REG,ISC00) ;
	}
	if(SENSE_CONTROL ==FALLING_EDGE)
	{
		/* INT0*/
		SET_BIT(MCUCR_REG,ISC01) ;
		CLEAR_BIT(MCUCR_REG,ISC00) ;
	}
	if(SENSE_CONTROL ==ANY_LOGIC_CHANGE)
	{
		/* INT0*/
		CLEAR_BIT(MCUCR_REG,ISC01) ;
		SET_BIT(MCUCR_REG,ISC00) ;
	}
	
	

}

void EXT_Vid_Interrupt0(){
	/* enable global interrupt */
	GIE_Vid_Enable();
	/*enable INT0 */
	SET_BIT(GICR_REG,INT_0_PIN) ;

	
	
}


void EXT_Vid_Interrupt1()
{
	GIE_Vid_Enable();
	SET_BIT(GICR_REG,INT_1_PIN) ;
}

void EXT_Vid_Set_CallBack(void(*ptr_set_callback)(void)){
	
	ptr_int0= ptr_set_callback ;
	
}
/* ISR0 */
/*
void  __vector_1(void)__attribute__((signal));
void __vector_1(void){
	
	
	ptr_int0() ;
	
	
}
*/