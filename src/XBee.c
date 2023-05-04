/*
 * XBee.c
 *
 *  Created on: Mar 7, 2023
 *      Author: erich
 */

#include "src/XBee.h"

#include <em_usart.h>

bool queryXBeeFwVersion(uint8_t *FwVersionDest)
{
  uint8_t frameID = 0x01;

  //Assemble API frame
  uint8_t API_frame[] =
      {
          API_DELIMETER,
          //Length = 3
          0, //Len MSB
          3, //Len LSB
          API_AT_CMD,
          frameID,
          'V',
          'R',
          0
      };

  //Append checksum
  API_frame[7]=calcChecksum(API_frame,4);

  for(int i=0;i<8;i++)
    {
      USART_SpiTransfer(USART0,API_frame[i]);
    }

  uint8_t XBee_response[10];

  for(int i=0;i<10;i++)
    {
      XBee_response[i]=USART_Rx(USART0);
    }

  if(!verifyChecksum(XBee_response,10))
    {
      return false;
    }
  else
    {
      FwVersionDest[0]=XBee_response[7];
      FwVersionDest[1]=XBee_response[8];
      return true;
    }

}

uint8_t calcChecksum(uint8_t *data, int len)
{
  uint8_t runningSum=0;

  for(int i=0;i<len;i++)
    {
      runningSum+=data[3+i];
    }

  return (0xFF-runningSum);
}

bool verifyChecksum(uint8_t *data, int len)
{
  uint8_t runningSum=0;

  for(int i=3;i<len;i++)
    {
      runningSum+=data[i];
    }

  return (runningSum==0xFF);
}
