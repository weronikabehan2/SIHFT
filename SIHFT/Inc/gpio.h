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

#define PORT_SCL_SCK GPIOB
#define PIN_SCL 8
#define PIN_SCK 9

#define PORT_RESET GPIOC
#define PIN_RESET 8

void GPIO_Init(void);


#endif /* GPIO_H_ */

