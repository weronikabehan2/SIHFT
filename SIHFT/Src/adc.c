/*
 * adc.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */
#include "adc.h"

void ADC1_Init(void) { // ADC for sensors
	RCC->APB2ENR |= (1 << 8);

	ADC1->CR1 &= ~(3 << 24);    // RES = 00 = 12-bit

	ADC1->CR2 &= ~(1 << 1);     // CONT = 0 = single conversion

	ADC1->SMPR1 &= ~(7 << 3);
	ADC1->SMPR1 |= (7 << 3);    // SMP11 = 480 cykli

	ADC1->SMPR1 &= ~(7 << 6);
	ADC1->SMPR1 |= (7 << 6);    // SMP12 = 480 cykli

	ADC1->CR2 |= (1 << 0);      // ADON
}



uint16_t ADC_Read(uint8_t channel) {
	ADC1->SQR3 &= ~(0x1F << 0);
	ADC1->SQR3 |= (channel << 0);
	ADC1->CR2 |= (1 << 30);
	while(!(ADC1->SR & (1 << 1))) { }
	uint16_t value = ADC1->DR;
	return value;
}
