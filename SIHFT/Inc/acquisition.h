/*
 * acquisition.h
 *
 *  Created on: 9 paź 2026
 *      Author: weronika
 */

#ifndef ACQUISITION_H_
#define ACQUISITION_H_

#include <stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "adc.h"
#include "tim.h"

void ACQ_Init(void);

int16_t ACQ_ValueToAngle(uint16_t adc_value);

void ACQ_SafeState(void);
void ACQ_NormalState(void);

#endif /* ACQUISITION_H_ */
