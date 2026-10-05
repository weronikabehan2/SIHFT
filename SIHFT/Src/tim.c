/*
 * tim.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#include "tim.h"

void TIM2_Init(void) { // PWM for servo
	RCC->APB1ENR |= (1 << 0);

	TIM2->PSC = 15;
	TIM2->ARR = 20000 - 1;

	TIM2->CCMR1 &= ~(7 << 12);
	TIM2->CCMR1 |= (6 << 12);   // PWM mode 1, kanał 2

	TIM2->CCER |= (1 << 4);     // CC2E

	TIM2->CR1 |= (1 << 0);      // CEN
}

uint16_t Get_Pulse(int16_t angle) {
	uint16_t pulse = 1500 + (angle * 500) / 90;
	return pulse;
}

void Set_Position(int16_t angle) {
	if(angle >= -90 && angle <= 90) {
		uint16_t pulse = Get_Pulse(angle);
		TIM2->CCR2 = pulse;
	}
}
