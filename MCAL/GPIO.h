 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Hassan Adel
 *
 *******************************************************************************/






#ifndef _GPIO_H_
#define _GPIO_H_
#include "STD_TYPES.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	
   PIN_INPUT,PIN_OUTPUT	
	
}GPIO_PinDirectionType;


typedef enum{
	
	
        PORT_INPUT,PORT_OUTPUT=0XFF
	
}GPIO_PortDirction;


void GPIO_SetPinDirection(uint8 port_num,uint8 pin_num,GPIO_PinDirectionType direction);




void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 pin_value);


uint8 GPIO_readPin (uint8 port_num,uint8 pin_num);




void GPIO_setPortDirection(uint8 port_num,GPIO_PortDirction direction);




void GPIO_writePort (uint8 port_num, uint8 port_value);




uint8 GPIO_readPort (uint8 port_num);




#endif
