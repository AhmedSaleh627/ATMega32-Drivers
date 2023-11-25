/*
 * TWI_interface.h
 *
 * Created: 10/27/2023 1:46:31 PM
 *  Author: Ahmed saleh
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



typedef enum
{
	NOErr ,
	StartConditionErr ,
	RepeatedStartErr ,
	SlaveAddress_With_WriteErr,
	SlaveAddress_With_ReadErr,
	Master_Send_dataErr ,
	Master_Recive_dataErr,
	TWI_Slave_ACKErr,
	
}TWI_ErrStatus;

/**************************** master function*********************/

//  address =0
void TWI_Vid_Master_Init(u8 copy_u8_address) ;
void TWI_Vid_Slave_Init(u8 copy_u8_address) ;

TWI_ErrStatus TWI_Send_StartCondition(void) ;
TWI_ErrStatus TWI_Send_RepeatedStart(void) ;
TWI_ErrStatus TWI_Send_SlaveAddress_With_Write(u8 copy_u8_address) ;
TWI_ErrStatus TWI_Send_SlaveAddress_With_Read(u8 copy_u8_address) ;
TWI_ErrStatus TWI_Master_Send_data(u8 copy_u8_data) ;
TWI_ErrStatus TWI_Master_Recive_data(u8 *copy_u8_data) ;
void  TWI_Send_StopCondition(void) ;
TWI_ErrStatus TWI_Slave_ACK(void) ;
u8 TWI_Slave_Recive_Data() ;




#endif /* TWI_INTERFACE_H_ */