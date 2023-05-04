/*
 * SPI.h
 *
 *  Created on: Mar 7, 2023
 *      Author: erich
 */

#ifndef SRC_SPI_H_
#define SRC_SPI_H_

#include <em_usart.h>

#define XBEE_SPI_PORT     gpioPortC
#define XBEE_SPI_CS_PIN   0
#define XBEE_SPI_MOSI_PIN 1
#define XBEE_SPI_MISO_PIN 2
#define XBEE_SPI_CLK_PIN  3

void init_usart0(void);

#endif /* SRC_SPI_H_ */
