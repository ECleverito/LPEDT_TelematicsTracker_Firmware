/*
 * GPIO.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/GPIO.h"

void init_GPIO()
{
  GPIO_PinModeSet(ACCEL_DATA_RDY_PORT, ACCEL_DATA_RDY_PIN, gpioModeInput, 0);
  GPIO_PinModeSet(GPS_TX_RDY_PORT, GPS_TX_RDY_PIN, gpioModeInput, 0);
  GPIO_PinModeSet(SOS_BUTTON_PORT, SOS_BUTTON_PIN, gpioModeInput, 0);

  GPIO_PinModeSet(GPS_PPS_LED_CTL_PORT, GPS_PPS_LED_CTL_PIN, gpioModeWiredAnd, 1);
}
