/*
 * I2C.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/I2C.h"

#include <em_cmu.h>

void init_I2C0()
{
  // Using PA5 (SDA) and PA6 (SCL)
  GPIO_PinModeSet(I2C0_PORT, I2C0_SDA_PIN, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(I2C0_PORT, I2C0_SCL_PIN, gpioModeWiredAndPullUpFilter, 1);

  // Route I2C pins to GPIO
  GPIO->I2CROUTE[0].SDAROUTE = (GPIO->I2CROUTE[0].SDAROUTE & ~_GPIO_I2C_SDAROUTE_MASK)
                        | (I2C0_PORT << _GPIO_I2C_SDAROUTE_PORT_SHIFT
                        | (I2C0_SDA_PIN << _GPIO_I2C_SDAROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[0].SCLROUTE = (GPIO->I2CROUTE[0].SCLROUTE & ~_GPIO_I2C_SCLROUTE_MASK)
                        | (I2C0_PORT << _GPIO_I2C_SCLROUTE_PORT_SHIFT
                        | (I2C0_SCL_PIN << _GPIO_I2C_SCLROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[0].ROUTEEN = GPIO_I2C_ROUTEEN_SDAPEN | GPIO_I2C_ROUTEEN_SCLPEN;

  CMU_ClockEnable(cmuClock_I2C0, true);

  I2C_Init_TypeDef i2c0_config = I2C_INIT_DEFAULT;

  i2c0_config.enable = false;

  I2C_Init(I2C0,&i2c0_config);

  I2C_Enable(I2C0,true);
}

void init_I2C1()
{
  //I2C1 SDA: PC02
  //I2C1 SCL: PC01
  GPIO_PinModeSet(I2C1_PORT, I2C1_SDA_PIN, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(I2C1_PORT, I2C1_SCL_PIN, gpioModeWiredAndPullUpFilter, 1);

  // Route I2C1 pins to GPIO
  GPIO->I2CROUTE[1].SDAROUTE = (GPIO->I2CROUTE[1].SDAROUTE & ~_GPIO_I2C_SDAROUTE_MASK)
                        | (I2C1_PORT << _GPIO_I2C_SDAROUTE_PORT_SHIFT
                        | (I2C1_SDA_PIN << _GPIO_I2C_SDAROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[1].SCLROUTE = (GPIO->I2CROUTE[1].SCLROUTE & ~_GPIO_I2C_SCLROUTE_MASK)
                        | (I2C1_PORT << _GPIO_I2C_SCLROUTE_PORT_SHIFT
                        | (I2C1_SCL_PIN << _GPIO_I2C_SCLROUTE_PIN_SHIFT));
  GPIO->I2CROUTE[1].ROUTEEN = GPIO_I2C_ROUTEEN_SDAPEN | GPIO_I2C_ROUTEEN_SCLPEN;

  CMU_ClockEnable(cmuClock_I2C1, true);

  I2C_Init_TypeDef i2c1_config = I2C_INIT_DEFAULT;

  i2c1_config.enable = false;

  I2C_Init(I2C1,&i2c1_config);

  I2C_Enable(I2C1,true);
}
