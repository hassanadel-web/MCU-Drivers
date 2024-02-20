/*
 * ADC.h
 *
 *  Created on: Feb 20, 2024
 *      Author: hassan
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"

void ADC_init(void);

uint16 ADC_readChannel(uint8 channel_num);



#endif /* ADC_H_ */
