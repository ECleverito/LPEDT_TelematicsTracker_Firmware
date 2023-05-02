/*
 * GPIO.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/GPIO.h"

void init_LED0(void)
{

  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, false);

}

void toggleLED0(void)
{
  GPIO_PinOutToggle(LED0_PORT,LED0_PIN);
}

void init_PPS(void)
{

  GPIO_PinModeSet(PPS_PORT, PPS_PIN, gpioModePushPull, false);

}

void PPS_on(void)
{
  GPIO_PinOutClear(PPS_PORT,PPS_PIN);
}
