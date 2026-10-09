/*
 * gpio.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */
#include "gpio.h"

void GPIO_Init(void) {
	// ports
	RCC->AHB1ENR |= (1 << 1);
	RCC->AHB1ENR |= (1 << 2);

	// led init
	PORT_LED->MODER &= ~(3 << (2 * PIN_LED));

	PORT_LED->MODER |= (1 << (2 * PIN_LED)); // output

	// sensor init
	PORT_SENSOR1->MODER &= ~(3 << (2 * PIN_SENSOR1));
	PORT_SENSOR2->MODER &= ~(3 << (2 * PIN_SENSOR2));

	PORT_SENSOR1->MODER |= (3 << (2 * PIN_SENSOR1)); // analog
	PORT_SENSOR2->MODER |= (3 << (2 * PIN_SENSOR2));

	// servo init
	PORT_SERVO->MODER &= ~(3 << (2 * PIN_SERVO));

	PORT_SERVO->MODER |= (2 << (2 * PIN_SERVO)); // alternate

	PORT_SERVO->AFR[0] &= ~(0xF << (4 * PIN_SERVO));

	PORT_SERVO->AFR[0] |= (1 << (4 * PIN_SERVO)); // AF1
}

