/*
 * adxl343.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/adxl343.h"

#include "src/GPIO.h"
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

#include <em_i2c.h>

void adxl_init()
{
  //Set acceleration offsets using values
  //obtained from calibration
  uint8_t measureModeVal = PWR_CTL_MEAS_BIT;
  adxl_write(PWR_CTL_REG,&measureModeVal);
}

void adxl_config()
{
  uint8_t registerVal = LOW_PWR_MODE | TWLV_PT_5_HZ;
  adxl_write(BW_RATE_REG, &registerVal);

  registerVal = FULL_RES_16_BIT | EIGHT_G_RANGE;
  adxl_write(DATA_FMT_REG, &registerVal);

  registerVal = HALF_G_THRESH;
  //Configure activity threshold for 1 G
  adxl_write(THRESH_ACT_REG, &registerVal);

  //Configure X & Y axes for activity interrupts
  registerVal = X_ACT_ENABLE | Y_ACT_ENABLE;
  adxl_write(ACT_CTL_REG, &registerVal);

  //Enable "activity" interrupt
  registerVal = ACT_INT_ENABLE;
  adxl_write(INT_ENABLE_REG, &registerVal);

  //Put FIFO into trigger mode with 16 presamples
  registerVal = TRIGGER_FIFO_MODE | THIRTYONE_PRESAMPS;
  adxl_write(FIFO_CTL_REG, &registerVal);

  //Offset acceleration vectors with calibration results
  int8_t offsetVal = X_OFFSET;
  adxl_write(OFSX_REG, &offsetVal);
  offsetVal = Y_OFFSET;
  adxl_write(OFSY_REG, &offsetVal);
  offsetVal = Z_OFFSET;
  adxl_write(OFSZ_REG, &offsetVal);
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

void adxl_offset_calibration()
{
  //Configure for application's necessary BW & data format
  uint8_t registerVal = LOW_PWR_MODE | TWLV_PT_5_HZ;
  if(!adxl_write(BW_RATE_REG, &registerVal))
    {
      LOG_ERROR("Error configuring ADXL registers!\r\n");
      return;
    }
  registerVal = FULL_RES_16_BIT | EIGHT_G_RANGE;
  if(!adxl_write(DATA_FMT_REG, &registerVal))
    {
      LOG_ERROR("Error configuring ADXL registers!\r\n");
      return;
    }

  //Configure for bypass mode and data ready interrupts
  //for calibration data collection
  registerVal = BYPASS_FIFO_MODE;
  if(!adxl_write(FIFO_CTL_REG, &registerVal))
    {
      LOG_ERROR("Error configuring ADXL registers!\r\n");
      return;
    }
  registerVal = DATA_READY_ENABLE;
  if(!adxl_write(INT_ENABLE_REG, &registerVal))
    {
      LOG_ERROR("Error configuring ADXL registers!\r\n");
      return;
    }

  //Start ADXL measurements
  adxl_init();

  int16_t x_calibSamps[CALIB_NUM_SAMPS];
  int16_t y_calibSamps[CALIB_NUM_SAMPS];
  int16_t z_calibSamps[CALIB_NUM_SAMPS];

  uint8_t accelRegVals[6];
  //Clear first data ready int flag
  adxl_read(DATAX0_REG, accelRegVals, 6);

  for(int i=0;i<CALIB_NUM_SAMPS;i++)
    {
      while(!accel_event)
        ;
      accel_event = false;

      adxl_read(DATAX0_REG, accelRegVals, 6);

      //Parse acceleration values
      x_calibSamps[i] = accelRegVals[0];
      x_calibSamps[i] |= ((uint16_t)accelRegVals[1])<<8;
      y_calibSamps[i] = accelRegVals[2];
      y_calibSamps[i] |= ((uint16_t)accelRegVals[3])<<8;
      z_calibSamps[i] = accelRegVals[4];
      z_calibSamps[i] |= ((uint16_t)accelRegVals[5])<<8;

    }

  //Calculate averages
  int x_offset=0;
  int y_offset=0;
  int z_offset=0;

  for(int i=0;i<CALIB_NUM_SAMPS;i++)
    {
      x_offset += x_calibSamps[i];
      y_offset += y_calibSamps[i];
      z_offset += z_calibSamps[i];
    }

  x_offset = (x_offset/CALIB_NUM_SAMPS)*4/15.6;
  y_offset = (y_offset/CALIB_NUM_SAMPS)*4/15.6;
  z_offset = (z_offset/CALIB_NUM_SAMPS)*4/15.6;

  LOG_INFO("X offset = %i\r\n",x_offset);
  LOG_INFO("Y offset = %i\r\n",y_offset);
  LOG_INFO("Z offset = %i\r\n",z_offset);

}

void adxl_getAccelVals(accel_vector_t *accel_vector)
{
  //Read acceleration values
  uint8_t accelRegVals[6];

  adxl_read(DATAX0_REG, accelRegVals, 6);

  //Parse x-direction
  accel_vector->x_accel = accelRegVals[0];
  accel_vector->x_accel |= ((uint16_t)accelRegVals[1])<<8;
  //Parse y-direction
  accel_vector->y_accel = accelRegVals[2];
  accel_vector->y_accel |= ((uint16_t)accelRegVals[3])<<8;
  //Parse z-direction
  accel_vector->z_accel = accelRegVals[4];
  accel_vector->z_accel |= ((uint16_t)accelRegVals[5])<<8;
}

enum accel_event_t adxl_getAccelEvent(accel_vector_t *accelEventData)
{
  memset(accelEventData,0,sizeof(accelEventData));
  enum accel_event_t lastEvt = NONE;

  accel_vector_t accel_vecs_FIFO;

  for(int i=0;i<FIFO_SIZE;i++)
    {
      adxl_getAccelVals(&accel_vecs_FIFO);

      if(abs(accel_vecs_FIFO.x_accel) >= ONE_G_EVT || \
         abs(accel_vecs_FIFO.y_accel) >= ONE_G_EVT || \
         abs(accel_vecs_FIFO.z_accel) >= ONE_G_EVT)
        {
          accelEventData->x_accel=accel_vecs_FIFO.x_accel;
          accelEventData->y_accel=accel_vecs_FIFO.y_accel;
          accelEventData->z_accel=accel_vecs_FIFO.z_accel;
          return CRASH;
        }


      if(abs(accel_vecs_FIFO.y_accel) >= HALF_G_EVT)
        {
          accelEventData->y_accel = accel_vecs_FIFO.y_accel;
          if(lastEvt==HARD_BRAKE)
            {
              return CRASH;
            }
          if(abs(accel_vecs_FIFO.x_accel) >= HALF_G_EVT)
            {
              return CRASH;
            }
          lastEvt=HARD_TURN;
        }

      if(abs(accel_vecs_FIFO.x_accel) >= HALF_G_EVT)
        {
          accelEventData->x_accel = accel_vecs_FIFO.x_accel;
          if(lastEvt==HARD_TURN)
            {
              return CRASH;
            }
          if(abs(accel_vecs_FIFO.y_accel) >= HALF_G_EVT)
            {
              return CRASH;
            }
          lastEvt=HARD_BRAKE;
        }

    }

  return lastEvt;
}
