/*
 * GPIO.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#pragma once

#include "em_gpio.h"

#define ACCEL_DATA_RDY_PORT gpioPortD
#define ACCEL_DATA_RDY_PIN  2

#define SOS_BUTTON_PORT     gpioPortD
#define SOS_BUTTON_PIN      3

#define GPS_TX_RDY_PORT     gpioPortC
#define GPS_TX_RDY_PIN      0

#define GPS_PPS_PORT  gpioPortC
#define GPS_PPS_PIN   3

extern bool accel_event;
extern bool sos_event;
extern bool GPS_data_ready;

void init_GPIO();
void init_PPS(void);
void PPS_on(void);
