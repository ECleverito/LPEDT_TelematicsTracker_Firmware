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
//  gps_return_t response;
//  uint8_t transferData[] = {CFG_PRT_GET_MESSAGE};
//  uint8_t response_buffer[ACK_RESPONSE_TOTAL_LENGTH+CFG_PRT_RESPONSE_TOTAL_LENGTH];
//
//  I2C_TransferSeq_TypeDef seq;
//
//  seq.addr = SAMM8Q_I2C_7BIT_ADDR;
//  seq.flags = I2C_FLAG_WRITE_WRITE;
//  uint8_t data_stream_addr = SAMM8Q_DATA_STREAM_ADDR;
//  seq.buf[0].data = & data_stream_addr;
//  seq.buf[0].len = 1;
//  seq.buf[1].data = (uint8_t*)transferData;
//  seq.buf[1].len = CFG_PRT_GET_TOTAL_LENGTH;
//
//  I2C_TransferReturn_TypeDef ret;
//
//  ret = I2C_TransferInit(I2C1,&seq);
//
//  while(ret==i2cTransferInProgress)
//    {
//      ret = I2C_Transfer(I2C1);
//    }
//
//  if(ret!=i2cTransferDone) return gps_failed;

  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t frame_buffer[128];
  gps_ubx_frame_t ubx_frame;

  uint16_t payload_len = 0;
  uint8_t payload[] = {
  };

  ubx_frame.preamble_a      = SAMM8Q_PREAMBLE_A;
  ubx_frame.preamble_b      = SAMM8Q_PREAMBLE_B;
  ubx_frame.class           = UBX_CLASS_CFG;
  ubx_frame.id              = UBX_ID_CFG_NAV5;
  ubx_frame.payload_length  = payload_len;
  ubx_frame.payload         = (uint8_t*) payload;

  gps_generate_checksum(&ubx_frame);

  gps_generate_ubx_frame_buffer((uint8_t*) frame_buffer, 128, &ubx_frame);

  seq.addr = SAMM8Q_I2C_7BIT_ADDR;
  seq.flags = I2C_FLAG_WRITE_WRITE;
  uint8_t data_stream_addr = SAMM8Q_DATA_STREAM_ADDR;
  seq.buf[0].data = &data_stream_addr;
  seq.buf[0].len = 1;
  seq.buf[1].data = (uint8_t*)frame_buffer;
  seq.buf[1].len = ubx_frame.payload_length+8;

  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
  {
    ret = I2C_Transfer(I2C1);
  }

  if(ret!=i2cTransferDone) return gps_failed;

  seq.flags = I2C_FLAG_READ;
  seq.buf[0].data = (uint8_t*)frame_buffer;
  seq.buf[0].len = 36+8;

  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

  if(ret!=i2cTransferDone) return gps_failed;

  seq.flags = I2C_FLAG_READ;
  seq.buf[0].data = (uint8_t*)frame_buffer;
  seq.buf[0].len = ACK_RESPONSE_TOTAL_LENGTH;

  ret = I2C_TransferInit(I2C1,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

  if(ret!=i2cTransferDone) return gps_failed;

  return gps_success;
}


gps_return_t gps_enable_periodic_updates(){
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t frame_buffer[128];
  gps_ubx_frame_t ubx_frame;


  // CONFIGURE PORT

  uint16_t cfg_prt_payload_len = 20;
  uint8_t cfg_prt_payload[] = {
      0x00,                         // Port ID
      0x00,                         // Reserved x1
      0x9B, 0x00,                   // TX Ready Config Flags
      0x84, 0x00, 0x00, 0x00,       // Mode Config Flags
      0x00, 0x00, 0x00, 0x00,       // Reserved x4
      0x07, 0x00,                   // InProtoMask
      0x03, 0x00,                   // OutProtoMask
      0x00, 0x00,                   // Flags
      0x00, 0x00                    // Reserved x2
  };

  ubx_frame.preamble_a      = SAMM8Q_PREAMBLE_A;
  ubx_frame.preamble_b      = SAMM8Q_PREAMBLE_B;
  ubx_frame.class           = UBX_CLASS_CFG;
  ubx_frame.id              = UBX_ID_CFG_PRT;
  ubx_frame.payload_length  = cfg_prt_payload_len;
  ubx_frame.payload         = (uint8_t*) cfg_prt_payload;

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


    //CONFIGURE NAVIGATION ENGINE

    uint16_t cfg_nav5_payload_len = 36;
    uint8_t cfg_nav5_payload[] = {
        0x41, 0x00,                    //mask (apply static hold & dyn model settings)
        0x04,        									 //dynModel (0x04 = Automotive Mode)
        0x03,        									 //fixMode
        0x00, 0x00, 0x00, 0x00,        //FixedAlt
        0x10, 0x27, 0x00, 0x00,        //fixedAltVar
        0x05,        									 //minElev
        0x00,        									 //drLimit
        0xfa, 0x00,         					 //pDop
        0xfa, 0x00,         					 //tDop
        0x64, 0x00,         					 //pAcc
        0x5e, 0x01,                    //tAcc
        0x2D,        									 //staticHoldThresh (0x2D = 45 cm/s)
        0x3c,        									 //dgnssTimeout
        0x00,        									 //cnoThreshNumSVs
        0x00,        									 //cnoThresh
        0x00, 0x00,        						 //reserved
        0x0A, 0x00,        						 //staticHoldMaxDist (0x0A = 10 m)
        0x00,                          //utcStandard
        0x00, 0x00, 0x00, 0x00, 0x00   //reserved
    };

    ubx_frame.class           = UBX_CLASS_CFG;
    ubx_frame.id              = UBX_ID_CFG_NAV5;
    ubx_frame.payload_length  = cfg_nav5_payload_len;
    ubx_frame.payload         = (uint8_t*) cfg_nav5_payload;

    gps_generate_checksum(&ubx_frame);

    gps_generate_ubx_frame_buffer((uint8_t*) frame_buffer, 128, &ubx_frame);

    seq.addr = SAMM8Q_I2C_7BIT_ADDR;
    seq.flags = I2C_FLAG_WRITE;
    seq.buf[0].data = (uint8_t*)frame_buffer;
    seq.buf[0].len = ubx_frame.payload_length+8;

    ret = I2C_TransferInit(I2C1,&seq);

    while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

    if(ret!=i2cTransferDone) return gps_failed;


    //CONFIGURE POWER MANAGEMENT SYSTEM

    uint16_t cfg_pms_payload_len = 8;
    uint8_t cfg_pms_payload[] = {
       0x00,        //Version
       0x03,        //Power Setup Value (0x03 = Agressive Power Saver 1 Hz)
       0x00, 0x00,  //Period
       0x00, 0x00,  //onTime
       0x00, 0x00   //Reserved 2x
    };

    ubx_frame.class           = UBX_CLASS_CFG;
    ubx_frame.id              = UBX_ID_CFG_PMS;
    ubx_frame.payload_length  = cfg_pms_payload_len;
    ubx_frame.payload         = (uint8_t*) cfg_pms_payload;

    gps_generate_checksum(&ubx_frame);

    gps_generate_ubx_frame_buffer((uint8_t*) frame_buffer, 128, &ubx_frame);

    seq.addr = SAMM8Q_I2C_7BIT_ADDR;
    seq.flags = I2C_FLAG_WRITE;
    seq.buf[0].data = (uint8_t*)frame_buffer;
    seq.buf[0].len = ubx_frame.payload_length+8;

    ret = I2C_TransferInit(I2C1,&seq);

    while(ret==i2cTransferInProgress)
     {
       ret = I2C_Transfer(I2C1);
     }

    if(ret!=i2cTransferDone) return gps_failed;


   //CONFIGURE OUTPUT DATA & RATE

    uint16_t cfg_msg_payload_len = 3;
    uint8_t cfg_msg_payload[] = {
      (uint8_t) UBX_CLASS_NAV,       // Navigation message class (NAV)
      (uint8_t) UBX_ID_NAV_PVT,      // Navigation message ID (NAV-PVT)
      0x05, // Enable message at .2 Hz
    };

    ubx_frame.class      			= UBX_CLASS_CFG;
    ubx_frame.id              = UBX_ID_CFG_MSG;
    ubx_frame.payload_length  = cfg_msg_payload_len;
    ubx_frame.payload         = (uint8_t*) cfg_msg_payload;

    gps_generate_checksum(&ubx_frame);

    gps_generate_ubx_frame_buffer((uint8_t*) frame_buffer, 128, &ubx_frame);

    seq.addr = SAMM8Q_I2C_7BIT_ADDR;
    seq.flags = I2C_FLAG_WRITE;
    seq.buf[0].data = (uint8_t*)frame_buffer;
    seq.buf[0].len = ubx_frame.payload_length+8;

    ret = I2C_TransferInit(I2C1,&seq);

    while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C1);
    }

    if(ret!=i2cTransferDone) return gps_failed;

    return gps_success;
}

void print_nav_pvt_info(uint8_t* nav_pvt_data) {
    //uint16_t year = (uint16_t)(nav_pvt_data[10] | (nav_pvt_data[11] << 8));
    //uint8_t month = nav_pvt_data[12];
    //uint8_t day = nav_pvt_data[13];
    //uint8_t hour = nav_pvt_data[14];
    //uint8_t min = nav_pvt_data[15];
    //uint8_t sec = nav_pvt_data[16];
    //uint8_t fixType = nav_pvt_data[26];
    int32_t lon_raw = (int32_t)(nav_pvt_data[30] | (nav_pvt_data[31] << 8) |
                                (nav_pvt_data[32] << 16) | (nav_pvt_data[33] << 24));
    int32_t lat_raw = (int32_t)(nav_pvt_data[34] | (nav_pvt_data[35] << 8) |
                                (nav_pvt_data[36] << 16) | (nav_pvt_data[37] << 24));
    float lon = ((float)lon_raw) * LON_SCALE_FACTOR;
    float lat = ((float)lat_raw) * LAT_SCALE_FACTOR;
    uint32_t gSpeed = ((uint32_t)nav_pvt_data[66] | ((uint32_t)nav_pvt_data[67] << 8) |
                                ((uint32_t)nav_pvt_data[68] << 16) | ((uint32_t)nav_pvt_data[69] << 24));
    float gSpeed_mph = ((float)gSpeed) * MMS_TO_MPH_SCALE_FACTOR;
    //sl_iostream_printf(app_log_iostream, "Date/Time: %04d-%02d-%02d %02d:%02d:%02d. ", year, month, day, hour, min, sec);
    //sl_iostream_printf(app_log_iostream,"Fix Type: %d. ", fixType);
    //sl_iostream_printf(app_log_iostream,"Longitude: %.7f degrees. ", lon);
    //sl_iostream_printf(app_log_iostream,"Latitude: %.7f degrees. ", lat);
    //sl_iostream_printf(app_log_iostream,"Ground Speed: %.2f mph.\n\r", gSpeed_mph);

    //HTTP POST from XBee
    sl_iostream_printf(app_log_iostream, "POST /gps?latitude=%.7f&longitude=%.7f&speed=%.1f HTTP/1.1\r\nHost: teletracker.herokuapp.com\r\n\r\n", lat, lon, gSpeed_mph);
    //sl_iostream_printf(app_log_iostream, "GET /home HTTP/1.1\r\nHost: teletracker.herokuapp.com\r\n\r\n");
}












