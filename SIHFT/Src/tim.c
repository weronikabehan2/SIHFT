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

