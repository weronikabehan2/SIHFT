/*
 * sihft.h
 *
 *  Created on: 9 paź 2026
 *      Author: weronika
 */

#ifndef SIHFT_H_
#define SIHFT_H_

#define TOLERANCE 100

#include <stdint.h>
#include "stm32f4xx.h"
#include "acquisition.h"

typedef struct {
	uint16_t sensor1_A;
	uint16_t sensor1_B;
	uint16_t sensor2_A;
	uint16_t sensor2_B;
	uint16_t average;
	uint8_t adc_error;
} AlgStruct;

extern AlgStruct alg;

void SIHFT_DataCheck(void);
void SIHFT_InstrCheck(void);
void SIHFT_Decide(void);

#endif /* SIHFT_H_ */
