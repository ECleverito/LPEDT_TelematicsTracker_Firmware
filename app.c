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

bool ADXL_read_flag;

static uint8_t frame_buffer[128];

void app_init(void)
{

  //sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

  init_PPS();
  PPS_on();
  init_timer0();
  //init_I2C0();
  init_I2C1();

  //adxl_init();

  ADXL_read_flag = false;

  //gps_readPortConfig();

  gps_enable_periodic_updates();

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

while(1){
    memset((uint8_t*) frame_buffer, 0, 128);

    //Wait for data to be ready
    while (gps_read_pending_data((uint8_t*) frame_buffer, 128) == gps_read_no_data){

      }

    if(frame_buffer[0] == 0xB5 && frame_buffer[1] == 0x62 && frame_buffer[2] == UBX_CLASS_NAV && frame_buffer[3] == UBX_ID_NAV_PVT)
      print_nav_pvt_info((uint8_t*)frame_buffer);
}



}
