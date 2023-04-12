/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include "src/GPIO.h"
#include "src/timers.h"
#include "src/I2C.h"
#include "src/adxl343.h"

#include <stdio.h>
#include <stdbool.h>
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/

bool ADXL_read_flag;

void app_init(void)
{

  init_LED0();
  init_timer0();
  init_I2C0();

  ADXL_read_flag = false;

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

  bool ADXL_readRes = false;
  uint8_t ADXL_accel_data[6];
  int successfulReads = 0;

  if(ADXL_read_flag)
    {
      ADXL_readRes = adxl_readBWRate(ADXL_accel_data);
      printf("Read result: %d",ADXL_readRes);
      if(ADXL_readRes)
        {
          successfulReads++;
        }
      ADXL_read_flag = false;
    }

}
