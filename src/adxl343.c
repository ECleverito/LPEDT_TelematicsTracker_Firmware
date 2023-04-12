/*
 * adxl343.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/adxl343.h"

#include <em_i2c.h>

bool adxl_readZ(uint8_t *data)
{
  bool result = false;

  uint8_t transferData[2];

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData[0]= DATAZ0_REG;
  seq.buf[0].data = transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 2;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
          data[0]=transferData[0];
          data[1]=transferData[1];
        }
      return result;

    }
  else
    {
      return result;
    }

}

bool adxl_readAccels(uint8_t *data)
{
  bool result = false;

  uint8_t transferData[6];

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData[0]= DATAX0_REG;
  seq.buf[0].data = transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 6;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
          data[0]=transferData[0];
          data[1]=transferData[1];
          data[2]=transferData[2];
          data[3]=transferData[3];
          data[4]=transferData[4];
          data[5]=transferData[5];
        }
      return result;

    }
  else
    {
      return result;
    }

}

bool adxl_readDevID(uint8_t *data)
{
  bool result = false;

  uint8_t transferData;

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData = DEVID_REG;
  seq.buf[0].data = &transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 1;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
          data[0]=transferData;
        }
      return result;

    }
  else
    {
      return result;
    }

}

bool adxl_readFIFOctl(uint8_t *data)
{
  bool result = false;

  uint8_t transferData;

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData = FIFO_CTL_REG;
  seq.buf[0].data = &transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 1;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
          data[0]=transferData;
        }
      return result;

    }
  else
    {
      return result;
    }

}

bool adxl_readBWRate(uint8_t *data)
{
  bool result = false;

  uint8_t transferData;

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData = BW_RATE_REG;
  seq.buf[0].data = &transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 1;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
          data[0]=transferData;
        }
      return result;

    }
  else
    {
      return result;
    }

}

