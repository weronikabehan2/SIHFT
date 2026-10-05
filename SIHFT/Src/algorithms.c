/*
 * algorithms.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */
#include "algorithms.h"
#include "gpio.h"

AlgStruct alg = {0};

uint16_t Read_ADC(uint8_t channel) {
	ADC1->SQR3 &= ~(0x1F << 0);
	ADC1->SQR3 |= (channel << 0);
	ADC1->CR2 |= (1 << 30);
	while(!(ADC1->SR & (1 << 1))) { }
	uint16_t value = ADC1->DR;
	return value;
}

void Data_Redundancy_Check(void) {
	alg.adc_error = 0;
	uint16_t sensor1 = Read_ADC(CHANNEL_SENSOR1);
	alg.sensor1_A = sensor1;
	alg.sensor1_B = sensor1;

	uint16_t sensor2 = Read_ADC(CHANNEL_SENSOR2);
	alg.sensor2_A = sensor2;
	alg.sensor2_B = sensor2;

	if(alg.sensor1_A != alg.sensor1_B) alg.adc_error = 1;
	if(alg.sensor2_A != alg.sensor2_B) alg.adc_error = 1;

	int16_t difference = sensor1 - sensor2;
	if(difference < 0) difference *= -1;

	if(difference > TOLERANCE) alg.adc_error = 1;
}

void Instruction_Redundancy_Check(void) {
	uint16_t value1 = (alg.sensor1_A + alg.sensor2_A) / 2;
	uint16_t value2 = (alg.sensor1_A + alg.sensor2_A) / 2;

	if(value1 != value2) alg.adc_error = 1;
	alg.average = value1;
}

void Safety_Handle(void) {
	if(alg.adc_error != 1) {
		Led_Off();
		Set_Position(ADC_to_Angle(alg.average));
	}
	else {
		Led_On();
		Set_Position(0);
	}
}
