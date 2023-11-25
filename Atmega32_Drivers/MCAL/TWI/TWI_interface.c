/*
 * TWI_interface.c
 *
 * Created: 10/27/2023 1:46:17 PM
 *  Author: Ahmed saleh
 */ 
#include "../../LIB/STD_Type.h"
#include "../../LIB/BITMATH.h"
#include "TWI_private.h"
#include "TWI_interface.h"

void TWI_Vid_Master_Init(u8 copy_u8_address) {
	
	/* Set SCL Freq to 400KHZ , With Fs=16MHZ   */
	/* SET TWBR = 12 */
	
	TWBR_REG=12 ;
	/* SET Prescaler :1  */
	CLEAR_BIT(TWSR_REG,0) ;
	CLEAR_BIT(TWSR_REG,1) ;
	
	if(copy_u8_address !=0){
		
		TWAR_REG=copy_u8_address<<1 ;
	}
	else{
		// DO Nothing
	}
	
	/* enable ACK  */
	
	SET_BIT(TWCR_REG,6) ;
	/*  enable TWI */
	SET_BIT(TWCR_REG,2) ;
	
	
}
void TWI_Vid_Slave_Init(u8 copy_u8_address){
	
	TWAR_REG=copy_u8_address<<1 ;
	
	/* enable ACK  */
	
	SET_BIT(TWCR_REG,6) ;
	/*  enable TWI */
	SET_BIT(TWCR_REG,2) ;
	
}

TWI_ErrStatus TWI_Send_StartCondition(void){
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	
	/* set start condition bit */
	SET_BIT(TWCR_REG,5) ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=START_ACK){
		
		Loc_u8_Err=StartConditionErr ;
	}
	else{
		// do nothing
	}
	
	return Loc_u8_Err ;
}
TWI_ErrStatus TWI_Send_RepeatedStart(void){
	
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	
	/* set start condition bit */
	SET_BIT(TWCR_REG,5) ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=REP_START){
		
		Loc_u8_Err=RepeatedStartErr ;
	}
	else{
		// do nothing
	}
	
	return Loc_u8_Err ;
}
TWI_ErrStatus TWI_Send_SlaveAddress_With_Write(u8 copy_u8_address){
	
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	
	/* send 7 bit S/A with write bit on the bus */
	TWDR_REG=copy_u8_address<<1 ;
	CLEAR_BIT(TWDR_REG,0) ;
	/* clr start condition */
	CLEAR_BIT(TWCR_REG,5) ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=SLAVE_ADD_AND_WR_ACK){
		
		Loc_u8_Err=SlaveAddress_With_WriteErr ;
	}
	else{
		// do nothing
	}
	
	return Loc_u8_Err ;
}
TWI_ErrStatus TWI_Send_SlaveAddress_With_Read(u8 copy_u8_address){
	
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	/* send 7 bit S/A with write bit on the bus */
	TWDR_REG=copy_u8_address<<1 ;
	SET_BIT(TWDR_REG,0) ;
	/* clr start condition */
	CLEAR_BIT(TWCR_REG,5) ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=SLAVE_ADD_AND_RR_ACK){
		
		Loc_u8_Err=SlaveAddress_With_ReadErr ;
	}
	else{
		// do nothing
	}
	
	
	return Loc_u8_Err ;
}
TWI_ErrStatus TWI_Master_Send_data(u8 copy_u8_data){
	
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	TWDR_REG = copy_u8_data ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=MASTER_WR_BYTE_ACK){
		
		Loc_u8_Err=Master_Send_dataErr ;
	}
	else{
		// do nothing
	}
	
	return Loc_u8_Err ;
	
}
TWI_ErrStatus TWI_Master_Recive_data(u8 *copy_u8_data){
	
	TWI_ErrStatus Loc_u8_Err=NOErr ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
	/* wait to finished current job  */
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if((TWSR_REG& 0xf8)!=MASTER_RD_BYTE_WITH_ACK){
		
		Loc_u8_Err=Master_Recive_dataErr ;
	}
	else{
		*copy_u8_data=TWDR_REG ;
	}
	
	return Loc_u8_Err ;
	
}
void  TWI_Send_StopCondition(void) {
	
	/* Send stop condition */
	SET_BIT(TWCR_REG,4) ;
	/* CLR Flag to start new operation   */
	SET_BIT(TWCR_REG,7) ;
	
}
TWI_ErrStatus TWI_Slave_ACK(void) {
	
	TWI_ErrStatus Loc_Err=NOErr ;
	
	// start TWI module and acknowledge data after reception
	SET_BIT(TWCR_REG,2) ;
	SET_BIT(TWCR_REG,6) ;
	CLEAR_BIT(TWCR_REG,7) ;
	while(GET_BIT(TWCR_REG,7)==0) ;  // wait for end of transmission acknowledge
	
	if((TWSR_REG& 0xf8) != SLAVE_ADD_RCVD_WD_REQ){
		
		Loc_Err=TWI_Slave_ACKErr;
	}
	else{
		
		// do nothing
	}
	
	return Loc_Err ;
}
u8 TWI_Slave_Recive_Data() {
	
	// start TWI module and acknowledge data after reception
	SET_BIT(TWCR_REG,2) ;
	SET_BIT(TWCR_REG,6) ;
	CLEAR_BIT(TWCR_REG,7) ;
	
	// wait for end of transmission
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	return TWDR_REG ;
	
	
}