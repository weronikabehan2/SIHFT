/*
 * acquisition.c
 *
 *  Created on: 9 paź 2026
 *      Author: weronika
 */
#include "acquisition.h"

void ACQ_Init(void) {
	GPIO_Init();
	TIM2_Init();
	ADC1_Init();
}

int16_t ACQ_ValueToAngle(uint16_t adc_value) {
	int32_t value = -90 + (adc_value * 180) / 4095;
	return (int16_t)value;
}

void ACQ_SafeState(void) {
	Led_On();
	Set_Position(0);
}

void ACQ_NormalState(void) {
	Led_Off();
}
