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

bool accel_event;
bool ADXL_read_flag;

void app_init(void)
{

  sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

  init_timer0();
  init_I2C0();

  accel_event = false;
  init_GPIO();

  //Configure accelerometer before taking out of standby
  adxl_config();
  adxl_init();
//  adxl_offset_calibration();

  uint8_t intSrcRegInitial;
  //Clear any initial ADXL interrupt flags
  adxl_read(INT_SRC_REG,&intSrcRegInitial,1);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

  uint8_t intSrc;

  if(accel_event)
    {
      accel_event = false;
      adxl_read(INT_SRC_REG, &intSrc, 1);

      LOG_INFO("Acceleration event detected!\r\n");

      //Wait 1.5 s for FIFO to fill
//      sl_udelay_wait(1500000);

      switch(adxl_getAccelEvent())
      {
        case NONE:
          LOG_INFO("No event detected.\r\n");
          break;
        case HARD_BRAKE:
          LOG_INFO("Hard braking detected!\r\n");
          break;
        case HARD_TURN:
          LOG_INFO("Hard turning detected!\r\n");
          break;
        case CRASH:
          LOG_INFO("Crash detected!\r\n");
          break;
      }

    }

}
