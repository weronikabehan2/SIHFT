/*
 * algorithms.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#define TOLERANCE 100

#include <stdint.h>
#include "stm32f4xx.h"

typedef struct {
	uint16_t sensor1_A;
	uint16_t sensor1_B;
	uint16_t sensor2_A;
	uint16_t sensor2_B;
	uint8_t adc_error;
} AlgStruct;

extern AlgStruct alg;

uint16_t Read_ADC(uint8_t channel);
void Data_Redundancy_Check(void);
void Instruction_Redundancy_Check(void);


#endif /* ALGORITHMS_H_ */
