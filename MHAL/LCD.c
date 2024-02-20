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

#include "GPIO.h"
#include <util/delay.h>
#include "LCD.h"





void LCD_writeData(uint8 data)
{
	/* RS to write data*/
	   
	    GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);
			/*RW=0 to write*/
	  
	    GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW);
			/*to send comand on data port*/
		
		GPIO_writePort(LCD_DATA_PORT_ID,data);
			/*enable lcd*/
		
		GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH);
		_delay_ms(1);
		GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW);
		_delay_ms(2);	

}
void LCD_writeCommand(uint8 command)
{
	/*RS=0 to write command*/

		GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
		/*RW=0 to write*/

		GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW);
		/*to send comand on data port*/

		GPIO_writePort(LCD_DATA_PORT_ID,command);
		/*enable lcd*/

		GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH);
		_delay_ms(1);
		GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW);
		_delay_ms(2);
		
		
		
		
		
}


void LCD_init(void)
{
	GPIO_setPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

    GPIO_SetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);

    GPIO_SetPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_HIGH);
    GPIO_SetPinDirection(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH);
	_delay_ms(40);
	LCD_writeCommand(LCD_FUNCTION_SET_8_BIT_2_LINES);
	_delay_ms(1);
	/*display on off control*/
	LCD_writeCommand(LCD_ON_CURSOR_ON_BLINKING);
	_delay_ms(1);
	/*clear LCD*/
	LCD_writeCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(2);
	
	
	
	
}


void LCD_writeString(const char*s)
{
	uint8 i=0;
	while(s[i]!='\0')
	{
		LCD_writeData(s[i]);
		i++;
	}
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_writeString(buff); /* Display the string */
}



void LCD_moveCursor(uint8 row,uint8 col)
{
     uint8 lcd_memory_address;
     switch(row)
     {
        case 0: lcd_memory_address=col;
        break;
        case 1: lcd_memory_address=0x40+col;
        break;
        case 2: lcd_memory_address=0x10+col;
        break;
        case 4: lcd_memory_address=0x50+col;
        break;
     }
     LCD_writeCommand(lcd_memory_address|LCD_SET_CURSOR_LOCATION);
}


void LCD_writeInRowCol(uint8 row,uint8 col,const char*str)
{
	LCD_moveCursor(row,col);
	LCD_writeString(*str);
}

void LCD_clearScreen(void)
{
	LCD_writeCommand(LCD_CLEAR_DISPLAY);
}
