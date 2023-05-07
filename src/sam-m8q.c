/*
 * sam-m8q.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Nik Provost
 */


#include "src/sam-m8q.h"

#include <em_i2c.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "sl_udelay.h"
#include "sl_iostream.h"

#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

#define LON_SCALE_FACTOR          1e-7
#define LAT_SCALE_FACTOR          1e-7
#define MMS_TO_MPH_SCALE_FACTOR   0.000621371

//Flag to indicate that GPS data should be read.
static bool GPS_read_flag = false;

//Getter function for local gps_read flag
bool gps_read_flag_get(){
  return GPS_read_flag;
}

//Setter function for local gps_read flag
void gps_read_flag_set(bool flag){
  GPS_read_flag = flag;
}


//Function to generate checksum values for an otherwise pre-populated ubx frame.
//Note: If any changes are made to the ubx frame, checksum values must be regenerated.
void gps_generate_checksum(gps_ubx_frame_t* ubx_frame){
  uint8_t ck_a = 0;
  uint8_t ck_b = 0;
  uint8_t* payload_ptr = ubx_frame->payload;

  ck_a += (uint8_t) ubx_frame->class;
  ck_b += ck_a;

  ck_a += (uint8_t) ubx_frame->id;
  ck_b += ck_a;

  ck_a += (uint8_t) (ubx_frame->payload_length & 0xFF);
  ck_b += ck_a;

  ck_a += (uint8_t) (ubx_frame->payload_length >> 8);
  ck_b += ck_a;

  for(int i = 0; i < ubx_frame->payload_length; i++){
      ck_a += *payload_ptr;
      ck_b += ck_a;
      payload_ptr++;
  }

  ubx_frame->chk_a = ck_a;
  ubx_frame->chk_b = ck_b;
}


//Function to populate a UBX frame buffer from a provided gps_ubx_frame_t struct.
gps_return_t gps_generate_ubx_frame_buffer(uint8_t* frame_buffer, uint16_t frame_buffer_size, gps_ubx_frame_t* ubx_frame){

  if (frame_buffer_size < (ubx_frame->payload_length+8)) return gps_insufficient_buffer_size;

  //Sync Characters
  *frame_buffer = ubx_frame->preamble_a;
  frame_buffer++;
  *frame_buffer = ubx_frame->preamble_b;
  frame_buffer++;

  //Class & ID
  *frame_buffer = (uint8_t) ubx_frame->class;
  frame_buffer++;
  *frame_buffer = (uint8_t) ubx_frame->id;
  frame_buffer++;

  //Payload Length
  *frame_buffer = (uint8_t) (ubx_frame->payload_length & 0xFF);
  frame_buffer++;
  *frame_buffer = (uint8_t) (ubx_frame->payload_length >> 8);
  frame_buffer++;

  //Payload
  memcpy(frame_buffer, ubx_frame->payload, ubx_frame->payload_length);
  frame_buffer += ubx_frame->payload_length;

  //Checksum
  *frame_buffer = ubx_frame->chk_a;
  frame_buffer++;
  *frame_buffer = ubx_frame->chk_b;

  return gps_success;
}


//A function to determine how much data is pending in the GPS's data stream.
gps_return_t gps_read_pending_data_length(uint16_t* pending_data_length){

  *pending_data_length = 0;

  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;

  // Read from the data pending (high and low bytes) registers,
  // which return the number of bytes pending in the data stream,
  // to determine how long of a read is needed from the data stream register.
  seq.addr = SAMM8Q_I2C_7BIT_ADDR;
  seq.flags = I2C_FLAG_WRITE_READ;
  uint8_t register_addr = SAMM8Q_DATA_PENDING_HIGH;

  //Write - Data Pending Register Address
  seq.buf[0].data = &register_addr;
  seq.buf[0].len = 1;

  //Read - Data Pending Register
  seq.buf[1].data = (uint8_t*)pending_data_length;
  seq.buf[1].len = SAMM8Q_DATA_PENDING_LEN;

  //Perform the I2C WRITE-READ transfer and await completion
  ret = I2C_TransferInit(I2C1,&seq);
  while(ret==i2cTransferInProgress)
    {
    ret = I2C_Transfer(I2C1);
    }

  if(ret!=i2cTransferDone) return gps_failed;

  //Need to flip endianess of the returned length
  *pending_data_length = ((*pending_data_length & 0x00FF) << 8) | ((*pending_data_length & 0xFF00) >> 8);

  return gps_success;
}


//A function to read all pending data from the GPS's data stream
gps_return_t gps_read_pending_data(uint8_t* buffer, uint16_t max_len){

  //Get the current number of bytes pending in the data stream register.
  uint16_t data_read_len;
  if (gps_read_pending_data_length(&data_read_len) == gps_failed) return gps_failed;

  //Determine if there is no data to read.
  if (data_read_len == 0) return gps_read_no_data;
  //Determine if there is too much data to read (set by max_len)
  else if (data_read_len > max_len) data_read_len = max_len;

  //Configure I2C Read from data stream
  //No need to write the data stream address because SAMM8Q's internal pointer has automatically
  //incremented to 0xFF after reading the pending data length.

  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;

  seq.addr =        SAMM8Q_I2C_7BIT_ADDR;
  seq.flags =       I2C_FLAG_READ;
  seq.buf[0].data = buffer;
  seq.buf[0].len =  data_read_len;

  //Perform the I2C READ transfer and await completion
  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
  {
      ret = I2C_Transfer(I2C1);
  }

  if(ret!=i2cTransferDone) return gps_failed;

  return gps_success;

}


//A function to read the SAM-M8Q's Port Configuration.
gps_return_t gps_readPortConfig()
{
  gps_return_t response;
  uint8_t transferData[] = {CFG_PRT_GET_MESSAGE};
  uint8_t response_buffer[ACK_RESPONSE_TOTAL_LENGTH+CFG_PRT_RESPONSE_TOTAL_LENGTH];

  I2C_TransferSeq_TypeDef seq;

  seq.addr = SAMM8Q_I2C_7BIT_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  uint8_t data_stream_addr = SAMM8Q_DATA_STREAM_ADDR;
  seq.buf[0].data = & data_stream_addr;
  seq.buf[0].len = 1;
  seq.buf[1].data = (uint8_t*)transferData;
  seq.buf[1].len = CFG_PRT_GET_TOTAL_LENGTH;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

  if(ret!=i2cTransferDone) return gps_failed;


  //Wait for data to be ready
  while ((response = gps_read_pending_data((uint8_t*) response_buffer, ACK_RESPONSE_TOTAL_LENGTH+CFG_PRT_RESPONSE_TOTAL_LENGTH)) != gps_success){
      if (response == gps_failed) return gps_failed;
  }

//  seq.flags = I2C_FLAG_READ;
//  seq.buf[0].data = (uint8_t*)port_response_buffer;
//  seq.buf[0].len = CFG_PRT_RESPONSE_TOTAL_LENGTH;
//
//
//  ret = I2C_TransferInit(I2C1,&seq);
//
//  while(ret==i2cTransferInProgress)
//    {
//      ret = I2C_Transfer(I2C1);
//    }
//
//  if(ret!=i2cTransferDone) return gps_failed;
//
//  seq.flags = I2C_FLAG_READ;
//    seq.buf[0].data = (uint8_t*)ack_response_buffer;
//    seq.buf[0].len = ACK_RESPONSE_TOTAL_LENGTH;
//
//  ret = I2C_TransferInit(I2C1,&seq);
//
//  while(ret==i2cTransferInProgress)
//    {
//      ret = I2C_Transfer(I2C1);
//    }
//
//  if(ret!=i2cTransferDone) return gps_failed;
  return gps_success;
}


gps_return_t gps_enable_periodic_updates(){
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t payload[] = {
      (uint8_t) UBX_CLASS_NAV,       // Navigation message class (NAV)
      (uint8_t) UBX_ID_NAV_PVT,      // Navigation message ID (NAV-PVT)
      0x01, // Enable message at 1 Hz
  };

  uint8_t frame_buffer[128];

  gps_ubx_frame_t ubx_frame;
  ubx_frame.preamble_a      = SAMM8Q_PREAMBLE_A;
  ubx_frame.preamble_b 			= SAMM8Q_PREAMBLE_B;
  ubx_frame.class      			= UBX_CLASS_CFG;
  ubx_frame.id              = UBX_ID_CFG_MSG;
  ubx_frame.payload_length  = 3;
  ubx_frame.payload         = (uint8_t*) payload;

  gps_generate_checksum(&ubx_frame);

  gps_generate_ubx_frame_buffer((uint8_t*) frame_buffer, 128, &ubx_frame);

  seq.addr = SAMM8Q_I2C_7BIT_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  uint8_t data_stream_addr = SAMM8Q_DATA_STREAM_ADDR;
  seq.buf[0].data = & data_stream_addr;
  seq.buf[0].len = 1;
  seq.buf[1].data = (uint8_t*)frame_buffer;
  seq.buf[1].len = ubx_frame.payload_length+8;

  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

  if(ret!=i2cTransferDone) return gps_failed;

  return gps_success;
}

void print_nav_pvt_info(uint8_t* nav_pvt_data) {
    uint16_t year = (uint16_t)(nav_pvt_data[10] | (nav_pvt_data[11] << 8));
    uint8_t month = nav_pvt_data[12];
    uint8_t day = nav_pvt_data[13];
    uint8_t hour = nav_pvt_data[14];
    uint8_t min = nav_pvt_data[15];
    uint8_t sec = nav_pvt_data[16];
    uint8_t fixType = nav_pvt_data[26];
    int32_t lon_raw = (int32_t)(nav_pvt_data[30] | (nav_pvt_data[31] << 8) |
                                (nav_pvt_data[32] << 16) | (nav_pvt_data[33] << 24));
    int32_t lat_raw = (int32_t)(nav_pvt_data[34] | (nav_pvt_data[35] << 8) |
                                (nav_pvt_data[36] << 16) | (nav_pvt_data[37] << 24));
    float lon = ((float)lon_raw) * LON_SCALE_FACTOR;
    float lat = ((float)lat_raw) * LAT_SCALE_FACTOR;
    uint32_t gSpeed = ((uint32_t)nav_pvt_data[66] | ((uint32_t)nav_pvt_data[67] << 8) |
                                ((uint32_t)nav_pvt_data[68] << 16) | ((uint32_t)nav_pvt_data[69] << 24));
    float gSpeed_mph = ((float)gSpeed) * MMS_TO_MPH_SCALE_FACTOR;
    sl_iostream_printf(app_log_iostream, "Date/Time: %04d-%02d-%02d %02d:%02d:%02d\n\r", year, month, day, hour, min, sec);
    sl_iostream_printf(app_log_iostream,"Fix Type: %d\n\r", fixType);
    sl_iostream_printf(app_log_iostream,"Longitude: %.7f degrees\n\r", lon);
    sl_iostream_printf(app_log_iostream,"Latitude: %.7f degrees\n\r", lat);
    sl_iostream_printf(app_log_iostream,"Ground Speed: %.2f mph\n\n\r", gSpeed_mph);
}












