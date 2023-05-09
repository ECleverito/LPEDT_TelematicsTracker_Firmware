/*
 * GPIO.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/GPIO.h"

#include "src/irq.h"

#include <em_cmu.h>

void init_GPIO()
{

  CMU_ClockEnable(cmuClock_GPIO, true);

  GPIO_PinModeSet(ACCEL_DATA_RDY_PORT, ACCEL_DATA_RDY_PIN, gpioModeInput, 0);
  GPIO_ExtIntConfig(ACCEL_DATA_RDY_PORT, ACCEL_DATA_RDY_PIN, 2, true, false, true);

  GPIO_PinModeSet(SOS_BUTTON_PORT, SOS_BUTTON_PIN, gpioModeInput, 0);
  GPIO_ExtIntConfig(SOS_BUTTON_PORT, SOS_BUTTON_PIN, 3, false, true, true);

  GPIO_PinModeSet(GPS_TX_RDY_PORT, GPS_TX_RDY_PIN, gpioModeInputPull, 1);
  GPIO_ExtIntConfig(GPS_TX_RDY_PORT, GPS_TX_RDY_PIN, 0, false, true, true);

  GPIOINT_CallbackRegister(2,accel_event_callback);
  GPIOINT_CallbackRegister(3,sos_event_callback);
  GPIOINT_CallbackRegister(0,GPS_TX_RDY_event_callback);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  GPIO_PinModeSet(GPS_TX_RDY_PORT, GPS_TX_RDY_PIN, gpioModeInput, 0);

}

void init_PPS(void)
{

  GPIO_PinModeSet(GPS_PPS_PORT, GPS_PPS_PIN, gpioModePushPull, false);

}

void PPS_on(void)
{
  GPIO_PinOutClear(GPS_PPS_PORT,GPS_PPS_PIN);
}
