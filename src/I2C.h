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

void init_I2C0();

#endif /* SRC_I2C_H_ */
