 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Hassan Adel
 *
 *******************************************************************************/




#include "STD_TYPES.h"
#ifndef LCD_H
#define LCD_H
#define LCD_DATA_PORT_ID                  PORTC_ID

#define LCD_RS_PORT_ID                    PORTA_ID
#define LCD_RS_PIN_ID                     PIN0_ID

#define LCD_RW_PORT_ID                    PORTA_ID
#define LCD_RW_PIN_ID                     PIN1_ID

#define LCD_ENABLE_PORT_ID                PORTA_ID
#define LCD_ENABLE_PIN_ID                 PIN2_ID

#define LCD_FUNCTION_SET_8_BIT_2_LINES    0x38
#define LCD_ON_CURSOR_ON_BLINKING         0xf
#define LCD_CLEAR_DISPLAY                 0x1
#define LCD_SET_CURSOR_LOCATION           0x80



void LCD_init(void);
void LCD_writeData(uint8 data);
void LCD_writeCommand(uint8 command);
void LCD_writeString(char*s);
void LCD_intgerToString(int data);

#endif
