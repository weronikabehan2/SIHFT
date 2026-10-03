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

	// i2c init
	PORT_SCL_SCK->MODER &= ~(3 << (2 * PIN_SCL));
	PORT_SCL_SCK->MODER &= ~(3 << (2 * PIN_SCK));
	PORT_RESET->MODER &= ~(1 << (2 * PIN_RESET));

	PORT_SCL_SCK->MODER |= (2 << (2 * PIN_SCL)); // alternate
	PORT_SCL_SCK->MODER |= (2 << (2 * PIN_SCK));
	PORT_RESET->MODER |= (1 << (2 * PIN_RESET)); // output

	PORT_SCL_SCK->OTYPER |= (1 << PIN_SCL); // open drain
	PORT_SCL_SCK->OTYPER |= (1 << PIN_SCK);

	PORT_SCL_SCK->AFR[1] &= ~(0xF << (4 * (PIN_SCL - 8)));
	PORT_SCL_SCK->AFR[1] &= ~(0xF << (4 * (PIN_SCK - 8)));

	PORT_SCL_SCK->AFR[1] |= (4 << (4 * (PIN_SCL - 8))); // AF4
	PORT_SCL_SCK->AFR[1] |= (4 << (4 * (PIN_SCK - 8))); // AF4
}

