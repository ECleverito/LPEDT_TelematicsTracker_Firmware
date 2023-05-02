/*
 * I2C.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/I2C.h"

#include <em_i2c.h>
#include <em_cmu.h>

void init_I2C0()
{
  // Using PA5 (SDA) and PA6 (SCL)
  GPIO_PinModeSet(gpioPortA, 6, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(gpioPortA, 7, gpioModeWiredAndPullUpFilter, 1);

  // Route I2C pins to GPIO
  GPIO->I2CROUTE[0].SDAROUTE = (GPIO->I2CROUTE[0].SDAROUTE & ~_GPIO_I2C_SDAROUTE_MASK)
                        | (gpioPortA << _GPIO_I2C_SDAROUTE_PORT_SHIFT
                        | (7 << _GPIO_I2C_SDAROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[0].SCLROUTE = (GPIO->I2CROUTE[0].SCLROUTE & ~_GPIO_I2C_SCLROUTE_MASK)
                        | (gpioPortA << _GPIO_I2C_SCLROUTE_PORT_SHIFT
                        | (6 << _GPIO_I2C_SCLROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[0].ROUTEEN = GPIO_I2C_ROUTEEN_SDAPEN | GPIO_I2C_ROUTEEN_SCLPEN;

  CMU_ClockEnable(cmuClock_I2C0, true);

  I2C_Init_TypeDef i2c0_config = I2C_INIT_DEFAULT;

  i2c0_config.enable = false;

  I2C_Init(I2C0,&i2c0_config);

  I2C_Enable(I2C0,true);
}
