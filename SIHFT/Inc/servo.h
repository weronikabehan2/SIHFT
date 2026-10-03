/*
 * servo.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <stdint.h>
#include "stm32f4xx.h"

uint16_t Get_Pulse(int8_t angle);
void Set_Position(int8_t angle);

#endif /* SERVO_H_ */
