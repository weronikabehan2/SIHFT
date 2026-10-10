/*
 * sihft.c
 *
 *  Created on: 9 paź 2026
 *      Author: weronika
 */
#include "sihft.h"

AlgStruct alg = {0};
volatile uint8_t now_state = beg;
volatile uint16_t now_ir = no;

static bool Check(uint8_t val) {
	if(now_state == val) return 1;
	else return 0;
}

void SIHFT_StoreData(void) {
	alg.adc_error = 0;
	if (!(Check(beg))) {
		alg.adc_error = 1;
		now_state = step1;
	}
	else {
		uint16_t sensor1 = ADC_Read(CHANNEL_SENSOR1);
		alg.sensor1_A = sensor1;
		alg.sensor1_B = (uint16_t)~(sensor1);

		uint16_t sensor2 = ADC_Read(CHANNEL_SENSOR2);
		alg.sensor2_A = sensor2;
		alg.sensor2_B = (uint16_t)~(sensor2);
		now_state = step1;
	}
}

void SIHFT_DataCheck(void) {
	if (!(Check(step1))) {
		alg.adc_error = 1;
		now_state = step2;
	}
	else {
	if((alg.sensor1_A  ^ alg.sensor1_B) != 0xFFFF) alg.adc_error = 1;
	if((alg.sensor2_A ^ alg.sensor2_B) != 0xFFFF) alg.adc_error = 1;

	int16_t difference = alg.sensor1_A - alg.sensor2_A;
	if(difference < 0) difference *= -1;

	if(difference > TOLERANCE) alg.adc_error = 1;
	now_state = step2;
	}
}

void SIHFT_InstrCheck(void) {
	if (!(Check(step2))) {
		alg.adc_error = 1;
		now_state = step3;
	}
	else {
	alg.average_A = (alg.sensor1_A + alg.sensor2_A) / 2;
	uint16_t c_sensor1_B = (uint16_t)~(alg.sensor1_B);
	uint16_t c_sensor2_B = (uint16_t)~(alg.sensor2_B);

	int8_t val = 0;
	if((c_sensor1_B % 2 != 0) && (c_sensor2_B % 2 != 0)) val = 1;
	alg.average_B = (c_sensor1_B / 2) + (c_sensor2_B / 2) + val;
	alg.angle_A = ACQ_ValueToAngle(alg.average_A);
	alg.angle_B = -90 + (alg.average_B * 180) / 4095;

	if((alg.average_A != alg.average_B) || (alg.angle_A != alg.angle_B)) alg.adc_error = 1;

	now_state = step3;
	}
}

void SIHFT_Decide(void) {
	if (!(Check(step3))) alg.adc_error = 1;
	else if(alg.angle_A != alg.angle_B) alg.adc_error = 1;
	if(alg.adc_error != 1) {
		ACQ_NormalState();
		Set_Position(alg.angle_A);
	}
	else ACQ_SafeState();
	now_state = beg;
}

