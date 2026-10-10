/*
 * gpio.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f4xx.h"

#define PORT_LED GPIOC
#define PIN_LED 0

#define PORT_SENSOR1 GPIOC
#define PIN_SENSOR1 1
#define CHANNEL_SENSOR1 11

#define PORT_SENSOR2 GPIOC
#define PIN_SENSOR2 2
#define CHANNEL_SENSOR2 12

#define PORT_SERVO GPIOB
#define PIN_SERVO 3


void GPIO_Init(void);

static inline void Led_Off(void) { PORT_LED->BSRR = (1 << (PIN_LED + 16)); }
static inline void Led_On(void) { PORT_LED->BSRR = (1 << PIN_LED); }

#endif /* GPIO_H_ */

