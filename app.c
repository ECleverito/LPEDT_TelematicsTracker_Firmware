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

#include "em_common.h"
#include "sl_power_manager.h"
#include "app.h"

//#define APP_IS_OK_TO_SLEEP      (false)

#define MY_USE_SYSTICKS 1
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

#include <stdio.h>
#include <stdbool.h>
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/

bool ADXL_read_flag;

void app_init(void)
{

  //sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

  init_LED0();
  init_PPS();
  PPS_on();
  init_timer0();
  init_I2C0();

  adxl_init();

  ADXL_read_flag = false;

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  LOG_INFO("HOWDY\n\r");
  bool ADXL_readRes = false;
  uint8_t ADXL_accelVals[6];
  uint8_t pwrCtl;
  uint8_t bwRate;
  int successfulReads = 0;

  if(ADXL_read_flag)
    {
      ADXL_readRes = adxl_read(DATAX0_REG,ADXL_accelVals,6);
      if(ADXL_readRes)
        {
          LOG_INFO("ADXL343 measurements: \r\n");
          LOG_INFO("\tX0 - %d\r\n",ADXL_accelVals[0]);
          LOG_INFO("\tX1 - %d\r\n",ADXL_accelVals[1]);
          LOG_INFO("\tY0 - %d\r\n",ADXL_accelVals[2]);
          LOG_INFO("\tY1 - %d\r\n",ADXL_accelVals[3]);
          LOG_INFO("\tZ0 - %d\r\n",ADXL_accelVals[4]);
          LOG_INFO("\tZ1 - %d\r\n",ADXL_accelVals[5]);
        }

      ADXL_readRes = adxl_read(PWR_CTL_REG,&pwrCtl,1);
      if(ADXL_readRes)
        {
          LOG_INFO("ADXL343 Power Ctl: %d\r\n",pwrCtl);
        }

      ADXL_readRes = adxl_read(BW_RATE_REG,&bwRate,1);
      if(ADXL_readRes)
        {
          LOG_INFO("ADXL343 BW Rate: %d\r\n",bwRate);
        }

      if(ADXL_readRes)
        {
          successfulReads++;
        }
      ADXL_read_flag = false;
    }

}
