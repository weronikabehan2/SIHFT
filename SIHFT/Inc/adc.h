/*
 * adc.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f4xx.h"

void ADC1_Init(void);

uint16_t Read_ADC(uint8_t channel);

#endif /* ADC_H_ */
