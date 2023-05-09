/*
 * irq.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#ifndef SRC_IRQ_H_
#define SRC_IRQ_H_

void accel_event_callback();
void sos_event_callback();
void GPS_TX_RDY_event_callback();

#endif /* SRC_IRQ_H_ */
