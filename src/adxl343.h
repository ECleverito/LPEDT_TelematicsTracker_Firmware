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

#define FIFO_SIZE   32

#define DEVID_REG  		 				0x00
#define THRESH_TAP_REG 				0x1D
#define OFSX_REG          		0x1E
#define OFSY_REG          		0x1F
#define OFSZ_REG          		0x20
#define TAP_DUR_REG       		0x21
#define TAP_LAT_REG       		0x22
#define TAP_WIN_REG       		0x23

#define THRESH_ACT_REG    		0x24
#define ONE_G_THRESH          16
#define HALF_G_THRESH         8

#define THRESH_NACT_REG   		0x25
#define EIGHTH_G_THRESH       2

#define TIME_NACT_REG     		0x26
#define TIME_NACT_MAX_4_MIN   0xFF

#define ACT_CTL_REG      		  0x27
#define X_ACT_ENABLE          0x40
#define Y_ACT_ENABLE          0x20
#define Z_ACT_ENABLE          0x10
#define X_NACT_ENABLE         0x04
#define Y_NACT_ENABLE         0x02
#define Z_NACT_ENABLE         0x01

#define THRESH_FF_REG     		0x28
#define TIME_FF_REG       		0x29
#define TAP_AXES_REG      		0x2A
#define TAP_SRC_REG       		0x2B

#define BW_RATE_REG      		  0x2C
#define LOW_PWR_MODE          0x10
#define TWLV_PT_5_HZ          0x07

#define PWR_CTL_REG       		0x2D
#define PWR_CTL_LINK_BIT  		0x20
#define PWR_CTL_AUTO_SLP_BIT 	0x10
#define PWR_CTL_MEAS_BIT      0x08
#define PWR_CTL_SLP_BIT       0x04
#define PWR_CTL_WAKEUP_BIT1   0x02
#define PWR_CTL_WAKEUP_BIT0   0x01

#define INT_ENABLE_REG   		  0x2E
#define ACT_INT_ENABLE        0x10
#define DATA_READY_ENABLE     0x80

#define INT_MAP_REG      		  0x2F
#define INT_SRC_REG      		  0x30

#define DATA_FMT_REG     		  0x31
#define FULL_RES_16_BIT       0x08
#define EIGHT_G_RANGE         0x02
#define ONE_G_EVT             250
#define HALF_G_EVT            125

//Data in these registers is 4 mg/LSB
//and two's complement (signed)
#define DATAX0_REG 		 				0x32
#define DATAX1_REG 		 				0x33
#define DATAY0_REG 		 				0x34
#define DATAY1_REG 		 				0x35
#define DATAZ0_REG 		 				0x36
#define DATAZ1_REG 		 				0x37

#define FIFO_CTL_REG   				0x38
#define TRIGGER_FIFO_MODE     0xC0
#define INT1_TRIGGER          0
#define INT2_TRIGGER          0x20
#define SIXTEEN_PRESAMPS      0x10
#define THIRTYONE_PRESAMPS    0x1F
#define BYPASS_FIFO_MODE      0

#define FIFO_STAT_REG    		  0x39

#define CALIB_NUM_SAMPS       10

//Offset values obtained from calibration
//These are already scaled for loading directly
//into the offset registers.
#define X_OFFSET              (-1)
#define Y_OFFSET              2
#define Z_OFFSET              (-63)

void adxl_init();

void adxl_config();

bool adxl_read(uint8_t regAddr, uint8_t *data, uint8_t len);

bool adxl_write(uint8_t regAddr, uint8_t *data);

void adxl_offset_calibration();

typedef struct accel_vector_s
{
  int16_t x_accel;
  int16_t y_accel;
  int16_t z_accel;
}accel_vector_t;

void adxl_getAccelVals(accel_vector_t *accel_vector);

enum accel_event_t
{
  NONE,
  HARD_BRAKE,
  HARD_TURN,
  CRASH
};

enum accel_event_t adxl_getAccelEvent();

extern bool ADXL_read_flag;

#endif /* SRC_ADXL343_H_ */
