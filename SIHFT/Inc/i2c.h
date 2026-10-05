/*
 * i2c.h
 *
 *  Created on: 3 paź 2026
 *      Author: weronika
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx.h"
#include "algorithm.s"

void I2C1_Init(void);
void I2C_Start(void);
void I2C_SendAddress(void);
void I2C_SendByte(void);
void I2C_Stop(void);

#endif /* I2C_H_ */
