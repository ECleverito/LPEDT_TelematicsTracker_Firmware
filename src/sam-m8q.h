/*
 * sam-m8q.h
 *
 *  Created on: Mar 7, 2023
 *      Author: NikProvost
 */

#ifndef SRC_SAM_M8Q_H_
#define SRC_SAM_M8Q_H_

#include <stdbool.h>
#include <stdint.h>

/***************************
 * SAM-M8Q Device Definitions
 ***************************/

//I2C Address
#define SAMM8Q_I2C_8BIT_ADDR        0x42
#define SAMM8Q_I2C_7BIT_ADDR        (SAMM8Q_I2C_8BIT_ADDR << 1)

//Register Addresses & Lengths
#define SAMM8Q_DATA_STREAM_ADDR     0xff
#define SAMM8Q_DATA_PENDING_HIGH    0xfd
#define SAMM8Q_DATA_PENDING_LOW     0xfe
#define SAMM8Q_DATA_PENDING_LEN     2

/***************************
 * UBX Protocol Definitions
 ***************************/
#define SAMM8Q_PREAMBLE_A   0xB5
#define SAMM8Q_PREAMBLE_B   0x62

typedef enum {
  UBX_CLASS_NAV = 0x01,   // Navigation results messages
  UBX_CLASS_RXM = 0x02,   // Receiver manager messages
  UBX_CLASS_INF = 0x04,   // Information messages
  UBX_CLASS_ACK = 0x05,   // Ack/Nak messages
  UBX_CLASS_CFG = 0x06,   // Configuration input messages
  UBX_CLASS_UPD = 0x09,   // Firmware update messages
  UBX_CLASS_MON = 0x0A,   // Monitoring messages
  UBX_CLASS_AID = 0x0B,   // AssistNow Aiding messages
  UBX_CLASS_TIM = 0x0D,   // Timing messages
  UBX_CLASS_ESF = 0x10,   // External sensor fusion messages
  UBX_CLASS_MGA = 0x13,   // Multiple GNSS assistance messages
  UBX_CLASS_LOG = 0x21,   // Logging messages
  UBX_CLASS_SEC = 0x27,   // Security feature messages
  UBX_CLASS_HNR = 0x28,   // High rate navigation results messages
} ubx_class_t;

typedef enum {
  UBX_ID_ACK_ACK                =   0x01,
  UBX_ID_ACK_NAK                =   0x00,
  UBX_ID_AID_ALM                =   0x30,
  UBX_ID_AID_AOP                =   0x33,
  UBX_ID_AID_EPH                =   0x31,
  UBX_ID_AID_HUI                =   0x02,
  UBX_ID_AID_INI                =   0x01,
  UBX_ID_CFG_ANT                =   0x13,
  UBX_ID_CFG_BATCH              =   0x93,
  UBX_ID_CFG_CFG                =   0x09,
  UBX_ID_CFG_DAT                =   0x06,
  UBX_ID_CFG_DGNSS              =   0x70,
  UBX_ID_CFG_DOSC               =   0x61,
  UBX_ID_CFG_DYNSEED            =   0x85,
  UBX_ID_CFG_ESRC               =   0x60,
  UBX_ID_CFG_FIXSEED            =   0x84,
  UBX_ID_CFG_GEOFENCE           =   0x69,
  UBX_ID_CFG_GNSS               =   0x3E,
  UBX_ID_CFG_HNR                =   0x5C,
  UBX_ID_CFG_INF                =   0x02,
  UBX_ID_CFG_ITFM               =   0x39,
  UBX_ID_CFG_LOGFILTER          =   0x47,
  UBX_ID_CFG_MSG                =   0x01,
  UBX_ID_CFG_NAV5               =   0x24,
  UBX_ID_CFG_NAVX5              =   0x23,
  UBX_ID_CFG_NMEA               =   0x17,
  UBX_ID_CFG_ODO                =   0x1E,
  UBX_ID_CFG_PM2                =   0x3B,
  UBX_ID_CFG_PMS                =   0x86,
  UBX_ID_CFG_PRT                =   0x00,
  UBX_ID_CFG_PWR                =   0x57,
  UBX_ID_CFG_RATE               =   0x08,
  UBX_ID_CFG_RINV               =   0x34,
  UBX_ID_CFG_RST                =   0x04,
  UBX_ID_CFG_RXM                =   0x11,
  UBX_ID_CFG_SBAS               =   0x16,
  UBX_ID_CFG_SMGR               =   0x62,
  UBX_ID_CFG_TMODE2             =   0x3D,
  UBX_ID_CFG_TMODE3             =   0x71,
  UBX_ID_CFG_TP5                =   0x31,
  UBX_ID_CFG_TXSLOT             =   0x53,
  UBX_ID_CFG_USB                =   0x1B,
  UBX_ID_ESF_INS                =   0x15,
  UBX_ID_ESF_MEAS               =   0x02,
  UBX_ID_ESF_RAW                =   0x03,
  UBX_ID_ESF_STATUS             =   0x10,
  UBX_ID_HNR_PVT                =   0x00,
  UBX_ID_INF_DEBUG              =   0x04,
  UBX_ID_INF_ERROR              =   0x00,
  UBX_ID_INF_NOTICE             =   0x02,
  UBX_ID_INF_TEST               =   0x03,
  UBX_ID_INF_WARNING            =   0x01,
  UBX_ID_LOG_BATCH              =   0x11,
  UBX_ID_LOG_CREATE             =   0x07,
  UBX_ID_LOG_ERASE              =   0x03,
  UBX_ID_LOG_FINDTIME           =   0x0E,
  UBX_ID_LOG_INFO               =   0x08,
  UBX_ID_LOG_RETRIEVEBATCH      =   0x10,
  UBX_ID_LOG_RETRIEVEPOSEXTRA   =   0x0f,
  UBX_ID_LOG_RETRIEVEPOS        =   0x0b,
  UBX_ID_LOG_RETRIEVESTRING     =   0x0d,
  UBX_ID_LOG_RETRIEVE           =   0x09,
  UBX_ID_LOG_STRING             =   0x04,
  UBX_ID_MGA_ACK_DATA0          =   0x60,
  UBX_ID_MGA_ANO                =   0x20,
  UBX_ID_MGA_BDS_EPH            =   0x03,
  UBX_ID_MGA_BDS_ALM            =   0x03,
  UBX_ID_MGA_BDS_HEALTH         =   0x03,
  UBX_ID_MGA_BDS_UTC            =   0x03,
  UBX_ID_MGA_BDS_IONO           =   0x03,
  UBX_ID_MGA_DBD                =   0x80,
  UBX_ID_MGA_FLASH_DATA         =   0x21,
  UBX_ID_MGA_FLASH_STOP         =   0x21,
  UBX_ID_MGA_FLASH_ACK          =   0x21,
  UBX_ID_MGA_GAL_EPH            =   0x02,
  UBX_ID_MGA_GAL_ALM            =   0x02,
  UBX_ID_MGA_GAL_TIMEOFFSET     =   0x02,
  UBX_ID_MGA_GAL_UTC            =   0x02,
  UBX_ID_MGA_GLO_EPH            =   0x06,
  UBX_ID_MGA_GLO_ALM            =   0x06,
  UBX_ID_MGA_GLO_TIMEOFFSET     =   0x06,
  UBX_ID_MGA_GPS_EPH            =   0x00,
  UBX_ID_MGA_GPS_ALM            =   0x00,
  UBX_ID_MGA_GPS_HEALTH         =   0x00,
  UBX_ID_MGA_GPS_UTC            =   0x00,
  UBX_ID_MGA_GPS_IONO           =   0x00,
  UBX_ID_MGA_INI_POS_XYZ        =   0x40,
  UBX_ID_MGA_INI_POS_LLH        =   0x40,
  UBX_ID_MGA_INI_TIME_UTC       =   0x40,
  UBX_ID_MGA_INI_TIME_GNSS      =   0x40,
  UBX_ID_MGA_INI_CLKD           =   0x40,
  UBX_ID_MGA_INI_FREQ           =   0x40,
  UBX_ID_MGA_INI_EOP            =   0x40,
  UBX_ID_MGA_QZSS_EPH           =   0x05,
  UBX_ID_MGA_QZSS_ALM           =   0x05,
  UBX_ID_MGA_QZSS_HEALTH        =   0x05,
  UBX_ID_MON_BATCH              =   0x32,
  UBX_ID_MON_GNSS               =   0x28,
  UBX_ID_MON_HW2                =   0x0B,
  UBX_ID_MON_HW                 =   0x09,
  UBX_ID_MON_IO                 =   0x02,
  UBX_ID_MON_MSGPP              =   0x06,
  UBX_ID_MON_PATCH              =   0x27,
  UBX_ID_MON_RXBUF              =   0x07,
  UBX_ID_MON_RXR                =   0x21,
  UBX_ID_MON_SMGR               =   0x2E,
  UBX_ID_MON_TXBUF              =   0x08,
  UBX_ID_MON_VER                =   0x04,
  UBX_ID_NAV_AOPSTATUS          =   0x60,
  UBX_ID_NAV_ATT                =   0x05,
  UBX_ID_NAV_CLOCK              =   0x22,
  UBX_ID_NAV_DGPS               =   0x31,
  UBX_ID_NAV_DOP                =   0x04,
  UBX_ID_NAV_EOE                =   0x61,
  UBX_ID_NAV_GEOFENCE           =   0x39,
  UBX_ID_NAV_HPPOSECEF          =   0x13,
  UBX_ID_NAV_HPPOSLLH           =   0x14,
  UBX_ID_NAV_ODO                =   0x09,
  UBX_ID_NAV_ORB                =   0x34,
  UBX_ID_NAV_POSECEF            =   0x01,
  UBX_ID_NAV_POSLLH             =   0x02,
  UBX_ID_NAV_PVT                =   0x07,
  UBX_ID_NAV_RELPOSNED          =   0x3C,
  UBX_ID_NAV_RESETODO           =   0x10,
  UBX_ID_NAV_SAT                =   0x35,
  UBX_ID_NAV_SBAS               =   0x32,
  UBX_ID_NAV_SOL                =   0x06,
  UBX_ID_NAV_STATUS             =   0x03,
  UBX_ID_NAV_SVINFO             =   0x30,
  UBX_ID_NAV_SVIN               =   0x3B,
  UBX_ID_NAV_TIMEBDS            =   0x24,
  UBX_ID_NAV_TIMEGAL            =   0x25,
  UBX_ID_NAV_TIMEGLO            =   0x23,
  UBX_ID_NAV_TIMEGPS            =   0x20,
  UBX_ID_NAV_TIMELS             =   0x26,
  UBX_ID_NAV_TIMEUTC            =   0x21,
  UBX_ID_NAV_VELECEF            =   0x11,
  UBX_ID_NAV_VELNED             =   0x12,
  UBX_ID_RXM_IMES               =   0x61,
  UBX_ID_RXM_MEASX              =   0x14,
  UBX_ID_RXM_PMREQ              =   0x41,
  UBX_ID_RXM_RAWX               =   0x15,
  UBX_ID_RXM_RLM                =   0x59,
  UBX_ID_RXM_RTCM               =   0x32,
  UBX_ID_RXM_SFRBX              =   0x13,
  UBX_ID_RXM_SVSI               =   0x20,
  UBX_ID_SEC_SIGN               =   0x01,
  UBX_ID_SEC_UNIQID             =   0x03,
  UBX_ID_TIM_DOSC               =   0x11,
  UBX_ID_TIM_FCHG               =   0x16,
  UBX_ID_TIM_HOC                =   0x17,
  UBX_ID_TIM_SMEAS              =   0x13,
  UBX_ID_TIM_SVIN               =   0x04,
  UBX_ID_TIM_TM2                =   0x03,
  UBX_ID_TIM_TOS                =   0x12,
  UBX_ID_TIM_TP                 =   0x01,
  UBX_ID_TIM_VCOCAL             =   0x15,
  UBX_ID_TIM_VRFY               =   0x06,
  UBX_ID_UPD_SOS                =   0x14
} ubx_id_t;

/* Port Configuration (CFG-PRT) Get Message */
#define CFG_PRT_CLASS       0x06
#define CFG_PRT_ID          0x00
#define CFG_PRT_GET_PAYLOAD_LENGTH  0x00, 0x00
#define CFG_PRT_CHK_A       0x06
#define CFG_PRT_CHK_B       0x18
#define CFG_PRT_GET_TOTAL_LENGTH  8
#define CFG_PRT_GET_MESSAGE SAMM8Q_PREAMBLE_A, SAMM8Q_PREAMBLE_B, CFG_PRT_CLASS, CFG_PRT_ID, CFG_PRT_GET_PAYLOAD_LENGTH, CFG_PRT_CHK_A, CFG_PRT_CHK_B

/* Port Configuration (CFG-PRT) Get Response */
#define CFG_PRT_RESPONSE_TOTAL_LENGTH   28

/* ACK ACK/NACK Response */
#define ACK_CLASS           0x05
#define ACK_ACK_ID          0x01
#define ACK_NACK_ID         0x00
#define ACK_PAYLOAD_LENGTH  0x00, 0x02
#define ACK_RESPONSE_TOTAL_LENGTH 10

typedef struct
{
  uint8_t       preamble_a;
  uint8_t       preamble_b;
  ubx_class_t   class;
  ubx_id_t      id;
  uint16_t      payload_length;
  uint8_t*      payload;
  uint8_t       chk_a;
  uint8_t       chk_b;
} gps_ubx_frame_t;

typedef enum{
  gps_success,
  gps_failed,
  gps_read_no_data,
  gps_insufficient_buffer_size,
} gps_return_t;


gps_return_t gps_readPortConfig();
gps_return_t gps_enable_periodic_updates();

bool gps_read_flag_get();
void gps_read_flag_set(bool flag);
gps_return_t gps_read_pending_data(uint8_t* buffer, uint16_t max_len);
void print_nav_pvt_info(uint8_t* nav_pvt_data);


#endif /* SRC_SAM_M8Q_H_ */
