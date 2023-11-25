/*
 * LCD_interface.h
 *
 * Created: 9/1/2023 5:26:18 PM
 *  Author: Ahmed saleh
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_MODE FOUR_BIT

#define EIGHT_BIT 0
#define FOUR_BIT 1

void LCD_Vid_Send_Data(u8 copy_u8_data);
void LCD_Vid_Send_Command(u8 copy_u8_command);
void LCD_Vid_Init(void);
void LCD_Send_String(u8 *copy_u8_char);
void LCD_Vid_GOTOXY(u8 copy_u8_x , u8 copy_u8_y);
void LCD_Vid_Draw_data(u8 copy_u8_pattern , u8 *copy_u8_data,u8 copy_u8_x , u8 copy_u8_y);
void LCD_Send_Number(u64 num);
void CLR_Display();
u8 asc_to_int(u8 copy_u8_int);
u8 int_to_asc(u8 copy_u8_int);
#endif /* LCD_INTERFACE_H_ */