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

int16_t ADC_to_Angle(uint16_t adc_value) {
	int32_t value = -90 + (adc_value * 180) / 4095;
	return (int16_t)value;
}
