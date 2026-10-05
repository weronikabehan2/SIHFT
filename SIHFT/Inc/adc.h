/*
 * adc.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"

void ADC1_Init(void);

int16_t ADC_to_Angle(uint16_t adc_value);

#endif /* ADC_H_ */
