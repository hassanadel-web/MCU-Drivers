/*
 * ADC.c
 *
 *  Created on: Feb 20, 2024
 *      Author: hassan
 */


#include <avr/io.h>
#include "MACROS.h"
#include "ADC.h"

void ADC_init(void)
{
	/*initialize adc without selecting channel number*/

	/*
	 * ADMUX=0
	 * mux0 to mux4 =0 so channel number will be selected later
	 * ADLAR = keep the adc value right adjusted
	 * REFS1:0: =0 means will use external Vref on AREF pin
	 */
	ADMUX=0;
	/*
	 *  set ADEN to Enable adc
	 *  set ADPS0,ADPS1 to choose prescaler 8
	 */
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1);


}


uint16 ADC_readChannel(uint8 channel_number)
{

	channel_number&=0x7; /*clear all bits in channel_number except 0:3 to choose from 8 channels 2^3*/
	ADMUX&=0xE0; /*To claer the mux0:mux4 bits in ADMUX register*/
	ADMUX|=channel_number;
	SET_BIT(ADCSRA,ADSC);
	while(bit_is_clear(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;

}

