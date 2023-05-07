/*
 * irq.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */
#include <em_timer.h>
#include <em_core.h>

#include "src/GPIO.h"
#include "src/adxl343.h"
#include "src/sam-m8q.h"

void TIMER0_IRQHandler()
{
  CORE_DECLARE_IRQ_STATE;

  CORE_ENTER_CRITICAL();

  uint32_t flags=TIMER_IntGet(TIMER0);

  TIMER_IntClear(TIMER0,flags);

  //ADXL_read_flag = true;
  gps_read_flag_set(true);

  CORE_EXIT_CRITICAL();


}
