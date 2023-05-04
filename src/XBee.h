/*
 * XBee.h
 *
 *  Created on: Mar 7, 2023
 *      Author: erich
 */

#ifndef SRC_XBEE_H_
#define SRC_XBEE_H_

#include <stdbool.h>
#include <stdint.h>

//AT commands
#define FW_VERSION_AT "VR"

//API-mode formatting
#define API_DELIMETER 0x7E
#define API_AT_CMD    0x08

bool queryXBeeFwVersion(uint8_t *FwVersionDest);

uint8_t calcChecksum(uint8_t *data, int len);
bool verifyChecksum(uint8_t *data, int len);

#endif /* SRC_XBEE_H_ */
