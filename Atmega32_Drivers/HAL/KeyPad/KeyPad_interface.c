/*
 * KeyPad.c
 *
 * Created: 9/8/2023 4:58:43 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Keypad_interface.h"
#include "KeyPad_Config.h"


u8 Glo_u8_dataArray[4][4]={
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'},
};

void KEYPAD_Vid_Init(void){
	
	u8 Loc_u8_ROWARRAY[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ;
	u8 Loc_u8_COLARRAY[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ;
	u8 Loc_u8_in=0 ;
	for(Loc_u8_in=0 ; Loc_u8_in<4 ; Loc_u8_in++){
		/* MAKE ROW PINS --> INPUT  */
		
		DIO_Vid_Set_Pin_Dir(KEYPAD_ROW_PORT,Loc_u8_ROWARRAY[Loc_u8_in],INPUT) ;
		/* ACTIVE PULL UP RESISTOR */
		DIO_Vid_Set_Pin_Val(KEYPAD_ROW_PORT,Loc_u8_ROWARRAY[Loc_u8_in],HIGH) ;
	}
	for(Loc_u8_in=0 ; Loc_u8_in<4 ; Loc_u8_in++){
		/* MAKE COL PINS --> OUTPUT   */
		
		DIO_Vid_Set_Pin_Dir(KEYPAD_COL_PORT,Loc_u8_COLARRAY[Loc_u8_in],OUTPUT) ;
		/* ACTIVE PULL UP RESISTOR */
		DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,Loc_u8_COLARRAY[Loc_u8_in],HIGH) ;
	}
	
}

u8 KEYPAD_u8_Get_Key(){
	
	u8 Loc_u8_ROWARRAY[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ;
	u8 Loc_u8_COLARRAY[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ;
	
	u8 Loc_u8_row=0 ;
	u8 Loc_u8_col=0 ;
	u8 Loc_u8_key=0xff ;
	
	for(Loc_u8_col=0; Loc_u8_col<4;Loc_u8_col++){
		
		/* ACTIVE COL PIN --> LOW  */
		DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,Loc_u8_COLARRAY[Loc_u8_col],LOW) ;
		/* CHEK ANY SWITCH PRESSED  */
		
		for(Loc_u8_row=0 ; Loc_u8_row<4;Loc_u8_row++){
			
			if(DIO_u8_Get_Pin_Val(KEYPAD_ROW_PORT,Loc_u8_ROWARRAY[Loc_u8_row])==0){
				
				Loc_u8_key = Glo_u8_dataArray[Loc_u8_row][Loc_u8_col] ;
				while(DIO_u8_Get_Pin_Val(KEYPAD_ROW_PORT,Loc_u8_ROWARRAY[Loc_u8_row])==0);
				return Loc_u8_key ;
				
				
			}
			
			
		}
		DIO_Vid_Set_Pin_Val(KEYPAD_COL_PORT,Loc_u8_COLARRAY[Loc_u8_col],HIGH) ;
		
	}
	
	
	return Loc_u8_key ;
}