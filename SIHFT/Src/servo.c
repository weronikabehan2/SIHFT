/*
 * servo.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */
#include "servo.h"

uint16_t Get_Pulse(int8_t angle) {
	uint16_t pulse = 1500 + (pulse * (500/90));
	return pulse;
}

void Set_Position(int8_t angle) {
	if(angle >= -90 && angle <= 90) {
		uint16_t pulse = Set_Angle(angle);
		TIM2->CCR2 = pulse;
	}
}
