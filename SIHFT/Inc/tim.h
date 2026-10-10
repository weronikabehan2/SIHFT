/*
 * tim.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef TIM_H_
#define TIM_H_

#include <stdint.h>
#include "stm32f4xx.h"

void TIM2_Init(void);

uint16_t Get_Pulse(int16_t angle);
void Set_Position(int16_t angle);

#endif /* TIM_H_ */
