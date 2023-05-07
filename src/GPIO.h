/*
 * GPIO.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "em_gpio.h"

#define PPS_PORT gpioPortC
#define PPS_PIN  3

void init_PPS(void);
void PPS_on(void);
