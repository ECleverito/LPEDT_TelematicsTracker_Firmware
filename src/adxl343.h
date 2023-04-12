/*
 * adxl343.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#ifndef SRC_ADXL343_H_
#define SRC_ADXL343_H_

#include <stdbool.h>
#include <stdint.h>

#define ADXL_ADDR   0xA6

#define DEVID_REG  		 0x00
#define DATAX0_REG 		 0x32
#define DATAX1_REG 		 0x33
#define DATAY0_REG 		 0x34
#define DATAY1_REG 		 0x35
#define DATAZ0_REG 		 0x36
#define DATAZ1_REG 		 0x37
#define FIFO_CTL_REG   0x38
#define BW_RATE_REG    0x2C

bool adxl_readAccels(uint8_t *data);

bool adxl_readAccels(uint8_t *data);

bool adxl_readZ(uint8_t *data);

bool adxl_readDevID(uint8_t *data);

bool adxl_readFIFOctl(uint8_t *data);

bool adxl_readBWRate(uint8_t *data);

extern bool ADXL_read_flag;

#endif /* SRC_ADXL343_H_ */
