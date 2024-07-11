/* 
 * File:   i2c.h
 * Author: ideapad GAMING
 *
 * Created on September 18, 2023, 3:15 PM
 */

#ifndef I2C_H
#define	I2C_H
#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"

#define I2C_SLEW_RATE_DIS 1 

#define I2C_SLEW_RATE_ENABLE 0


#define I2C_SMBUS_DIS 0
#define I2C_SMBUS_ENABLE 1

#define I2C_START_BIT_DET 1
#define I2C_START_BIT_NOT_DET 0

#define I2C_STOP_BIT_DET 1
#define I2C_STOP_BIT_NOT_DET 0


#define I2C_LAST_BYTE_DATA 1
#define I2C_LAST_BYTE_ADDRESS 0

#define I2C_MASTER_MODE 1
#define I2C_SLAVE_MODE 0

#define I2C_SLAVE_MODE_7BIT 0X06 
#define I2C_SLAVE_MODE_10BIT 0X07 
#define I2C_SLAVE_MODE_7BIT_START_STOP_INTER 0X0E
#define I2C_SLAVE_MODE_10BIT_START_STOP_INTER 0X0F
#define I2C_MASTER_MODE_WITH_CLOCK 0X08
#define I2C_MASTER_MODE_SOFTWARE_FIRMWARE 0X0B


#define I2C_REC_MODE_ENABLE 1
#define I2C_REC_MODE_DISABLE 0

#define I2C_GENERAL_CALL_ENABLE 1
#define I2C_GENERAL_CALL_DISABLE 0


///////////////////////////////////
#define I2C_SLEW_RATE_DISABLE_CFG()         (SSPSTATbits.SMP = 1)
#define I2C_SLEW_RATE_ENABLE_CFG()          (SSPSTATbits.SMP = 0)
/* SMBus Enable/Disable */
#define I2C_SMBus_DISABLE_CFG()             (SSPSTATbits.CKE = 0)
#define I2C_SMBus_ENABLE_CFG()              (SSPSTATbits.CKE = 1)
/* General Call Enable */
#define I2C_GENERAL_CALL_DISABLE_CFG()      (SSPCON2bits.GCEN = 0)
#define I2C_GENERAL_CALL_ENABLE_CFG()       (SSPCON2bits.GCEN = 1)
/* Master Mode Receive Enable */
#define I2C_MASTER_RECEIVE_DISABLE_CFG()    (SSPCON2bits.RCEN = 0)
#define I2C_MASTER_RECEIVE_ENABLE_CFG()     (SSPCON2bits.RCEN = 1)
/* Master Synchronous Serial Port Enable */
#define MSSP_MODULE_ENABLE_CFG()            (SSPCON1bits.SSPEN = 1)
#define MSSP_MODULE_DISABLE_CFG()           (SSPCON1bits.SSPEN = 0)
/* Clock Stretch */
#define I2C_CLOCK_STRETCH_ENABLE()          (SSPCON1bits.CKP = 0)
#define I2C_CLOCK_STRETCH_DISABLE()         (SSPCON1bits.CKP = 1)
////////////////////////////////////////////////////////////
#define  Acknowledge_was_received_from_slave 0
#define  Acknowledge_was_not_received_from_slave 1

#define ACK 0

#define NOT_ACK 1

 typedef struct
 {  uint8 i2c_address ;
     uint32 clock_rate;
     uint8 i2c_mode; /* slave or maSTET*/
        uint8 i2c_master_rec_mode :1 ;
        uint8 i2c_slew_rate_enable :1 ;
        uint8 i2c_smbus_enable :1 ;
        uint8 i2c_full_mode ;
        uint8 general_call :1 ;
         void (* i2c_inter_) (void);
     uint8 i2c_priority;

 }i2c_t;
  Std_ReturnType i2c_init(i2c_t * my_i2c);
  Std_ReturnType i2c_send_start(i2c_t * my_i2c);
  Std_ReturnType i2c_send_repeated_start(i2c_t * my_i2c);
  Std_ReturnType i2c_send_stop(i2c_t * my_i2c);
  Std_ReturnType i2c_wrtie_byte(i2c_t * my_i2c , uint8 value,uint8 *ack);
  Std_ReturnType i2c_read_byte(i2c_t * my_i2c , uint8* value,uint8 ack);
  Std_ReturnType i2c_send_frame(i2c_t * my_i2c , uint8 address,uint8 value , uint8* wrtie_ack , uint8 read_ack);


#endif	/* I2C_H */

