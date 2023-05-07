/*
 * adxl343.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/adxl343.h"

#include <em_i2c.h>

void adxl_init()
{
  uint8_t measureModeVal = PWR_CTL_MEAS_BIT;
  adxl_write(PWR_CTL_REG,&measureModeVal);
}

void adxl_config()
{
  uint8_t registerVal = ONE_GRAV;
  //Configure activity threshold for 1 G
  adxl_write(THRESH_ACT_REG, &registerVal);
  //Configure X & Y axes for activity interrupts
  registerVal = X_ACT_ENABLE | Y_ACT_ENABLE;
  adxl_write(ACT_CTL_REG, &registerVal);
  //Enable "activity" interrupt
  registerVal = ACT_INT_ENABLE;
  adxl_write(INT_ENABLE_REG, &registerVal);
}

bool adxl_read(uint8_t regAddr, uint8_t *data, uint8_t len)
{
  bool result = false;

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  seq.buf[0].data = &regAddr;
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
      seq.buf[0].data = data;
      seq.buf[0].len = len;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          result=true;
        }
      return result;

    }
  else
    {
      return result;
    }

}

bool adxl_write(uint8_t regAddr, uint8_t *data)
{
  I2C_TransferSeq_TypeDef seq;

  uint8_t transferData[] = {regAddr,*data};

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  seq.buf[0].data = transferData;
  seq.buf[0].len = 2;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      return true;
    }
  else
    {
      return false;
    }

}
