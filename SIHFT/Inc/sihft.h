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
#include <stdbool.h>
#include "stm32f4xx.h"
#include "acquisition.h"

typedef struct {
	volatile uint16_t sensor1_A;
	volatile uint16_t sensor1_B;
	volatile uint16_t sensor2_A;
	volatile uint16_t sensor2_B;
	volatile uint16_t average_A;
	volatile uint16_t average_B;
	volatile int8_t angle_A;
	volatile int8_t angle_B;
	volatile uint8_t adc_error;
} AlgStruct;

typedef enum {
	step1 = 0x1A,
	step2 = 0x2B,
	step3 = 0x3C,
	beg = 0x4D
} state;

typedef enum {
	yes = 0xAAA,
	no = 0xBBB
} ir;

extern volatile uint8_t now_state;
extern volatile uint16_t now_ir;

extern AlgStruct alg;

void SIHFT_DataCheck(void);
void SIHFT_InstrCheck(void);
void SIHFT_Decide(void);
static bool Check(uint8_t val);

#endif /* SIHFT_H_ */
