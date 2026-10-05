/*
 * i2c.c
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */
#include "i2c.h"

void I2C1_Init(void) {
	RCC->APB1ENR |= (1 << 21);

	I2C1->CR1 &= ~(1 << 0);

	I2C1->CR2 &= ~(63 << 0);
	I2C1->CR2 |= (16 << 0);      // FREQ

	I2C1->CCR &= ~(0xFFF << 0);
	I2C1->CCR |= (80 << 0);      // CCR

	I2C1->TRISE = 17;

	I2C1->CR1 |= (1 << 0);       // PE
}

void I2C_Start(void) {
	I2C1->CR1 |= (1 << 8);
	while(!(I2C1->SR1 & (1 << 0)));
}

void I2C_SendAddress(void) {

}

void I2C_SendByte(void) {

}

void I2C_Stop(void) {

}
