/*
 * I2C.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include <em_i2c.h>

#define I2C0_PORT       gpioPortA
#define I2C0_SCL_PIN    6
#define I2C0_SDA_PIN    7

#define I2C1_PORT       gpioPortC
#define I2C1_SCL_PIN    1
#define I2C1_SDA_PIN    2

void init_I2C0();
void init_I2C1();

#endif /* SRC_I2C_H_ */
