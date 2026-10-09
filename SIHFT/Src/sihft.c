/*
 * sihft.c
 *
 *  Created on: 9 paź 2026
 *      Author: weronika
 */
#include "sihft.h"

AlgStruct alg = {0};

void SIHFT_DataCheck(void) {
	alg.adc_error = 0;
	uint16_t sensor1 = ADC_Read(CHANNEL_SENSOR1);
	alg.sensor1_A = sensor1;
	alg.sensor1_B = sensor1;

	uint16_t sensor2 = ADC_Read(CHANNEL_SENSOR2);
	alg.sensor2_A = sensor2;
	alg.sensor2_B = sensor2;

	if(alg.sensor1_A != alg.sensor1_B) alg.adc_error = 1;
	if(alg.sensor2_A != alg.sensor2_B) alg.adc_error = 1;

	int16_t difference = sensor1 - sensor2;
	if(difference < 0) difference *= -1;

	if(difference > TOLERANCE) alg.adc_error = 1;
}

void SIHFT_InstrCheck(void) {
	uint16_t value1 = (alg.sensor1_A + alg.sensor2_A) / 2;
	uint16_t value2 = (alg.sensor1_A + alg.sensor2_A) / 2;

	if(value1 != value2) alg.adc_error = 1;
	alg.average = value1;
}

void SIHFT_Decide(void) {
	if(alg.adc_error != 1) {
		ACQ_NormalState();
		Set_Position(ACQ_ValueToAngle(alg.average));
	}
	else {
		ACQ_SafeState();
	}
}

