/*
 * irq.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */
#include "irq.h"

#include <em_timer.h>
#include <em_core.h>

#include "src/GPIO.h"
#include "src/adxl343.h"

void TIMER0_IRQHandler()
{
  CORE_DECLARE_IRQ_STATE;

  CORE_ENTER_CRITICAL();

  uint32_t flags=TIMER_IntGet(TIMER0);

  TIMER_IntClear(TIMER0,flags);

  toggleLED0();
  sensor_read_flag = true;

  CORE_EXIT_CRITICAL();


}
