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
#include "src/sam-m8q.h"
#include "sl_iostream.h"

#include "em_common.h"
#include "sl_power_manager.h"
#include "app.h"

//#define APP_IS_OK_TO_SLEEP      (false)

#define MY_USE_SYSTICKS 1
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/

bool accel_event;
bool sos_event;

static uint8_t frame_buffer[128];

void app_init(void)
{

  //sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

  accel_event=false;
  sos_event=false;
  init_GPIO();
  init_PPS();
  PPS_on();

  init_timer0();
  init_I2C0();
  init_I2C1();

  adxl_config();
  adxl_init();

  uint8_t intSrc;
  //Clear interrupt flag on ADXL
  adxl_read(INT_SRC_REG,&intSrc,1);

  //gps_readPortConfig();

  gps_enable_periodic_updates();

  sl_iostream_printf(app_log_iostream,"MG Booting\r\n");

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

  if(accel_event)
    {
      accel_event=false;

      uint8_t intSrc;
      //Clear interrupt flag on ADXL
      adxl_read(INT_SRC_REG,&intSrc,1);

      adxl_getAccelEvent();
    }

  if(sos_event)
    {
      sos_event=false;
    }

}
