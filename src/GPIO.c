/*
 * GPIO.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/GPIO.h"

#include <em_cmu.h>

void init_GPIO()
{

  CMU_ClockEnable(cmuClock_GPIO, true);

  GPIO_PinModeSet(ACCEL_DATA_RDY_PORT, ACCEL_DATA_RDY_PIN, gpioModeInput, 0);
//  GPIO_IntDisable(GPIO_IntGetEnabled());
  GPIO_ExtIntConfig(ACCEL_DATA_RDY_PORT, ACCEL_DATA_RDY_PIN, 2, true, false, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  GPIO_PinModeSet(GPS_TX_RDY_PORT, GPS_TX_RDY_PIN, gpioModeInput, 0);
  GPIO_PinModeSet(SOS_BUTTON_PORT, SOS_BUTTON_PIN, gpioModeInput, 0);

  GPIO_PinModeSet(GPS_PPS_LED_CTL_PORT, GPS_PPS_LED_CTL_PIN, gpioModeWiredAnd, 1);
}
