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

#define DEVID_REG  		 				0x00
#define THRESH_TAP_REG 				0x1D
#define OFSX_REG          		0x1E
#define OFSY_REG          		0x1F
#define OFSZ_REG          		0x20
#define TAP_DUR_REG       		0x21
#define TAP_LAT_REG       		0x22
#define TAP_WIN_REG       		0x23
#define THRESH_ACT_REG    		0x24
#define THRESH_NACT_REG   		0x25
#define TIME_NACT_REG     		0x26

#define ACT_CTL_REG      		  0x27
#define X_ACT_ENABLE          0x40
#define Y_ACT_ENABLE          0x20
#define Z_ACT_ENABLE          0x10

#define THRESH_FF_REG     		0x28
#define TIME_FF_REG       		0x29
#define TAP_AXES_REG      		0x2A
#define TAP_SRC_REG       		0x2B
#define BW_RATE_REG      		  0x2C

#define PWR_CTL_REG       		0x2D
#define PWR_CTL_LINK_BIT  		0x20
#define PWR_CTL_AUTO_SLP_BIT 	0x10
#define PWR_CTL_MEAS_BIT      0x08
#define PWR_CTL_SLP_BIT       0x04
#define PWR_CTL_WAKEUP_BIT1   0x02
#define PWR_CTL_WAKEUP_BIT0   0x01

#define INT_ENABLE_REG   		  0x2E
#define ACT_INT_ENABLE        0x10

#define INT_MAP_REG      		  0x2F
#define INT_SRC_REG      		  0x30
#define DATA_FMT_REG     		  0x31
#define DATAX0_REG 		 				0x32
#define DATAX1_REG 		 				0x33
#define DATAY0_REG 		 				0x34
#define DATAY1_REG 		 				0x35
#define DATAZ0_REG 		 				0x36
#define DATAZ1_REG 		 				0x37
#define FIFO_CTL_REG   				0x38
#define FIFO_STAT_REG    		  0x39

#define ONE_GRAV              16

void adxl_init();

void adxl_config();

bool adxl_read(uint8_t regAddr, uint8_t *data, uint8_t len);

bool adxl_write(uint8_t regAddr, uint8_t *data);

extern bool ADXL_read_flag;

#endif /* SRC_ADXL343_H_ */
