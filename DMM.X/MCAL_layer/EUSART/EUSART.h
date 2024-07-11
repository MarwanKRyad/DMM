/* 
 * File:   newfile.h
 * Author: ideapad GAMING
 *
 * Created on September 13, 2023, 7:56 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H
#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"

#define EUSART_ENABLE 1
#define EUSART_DISABLE 0

#define EUSART_SYNCHRONOUS_MODE 1
#define EUSART_ASYNCHRONOUS_MODE 0

#define EUSART_16BIT 1
#define EUSART_8BIT 0

#define EUSART_LOW_SPEED 0
#define EUSART_HIGH_SPEED 1

/////////////////////////////////
#define EUSART_ASYNCHRONOUS_TX_ENABLE 1
#define EUSART_ASYNCHRONOUS_TX_DISABLE 0

#define EUSART_ASYNCHRONOUS_TX_9bit 1
#define EUSART_ASYNCHRONOUS_TX_8bit 0


#define EUSART_ASYNCHRONOUS_TX_ENABLE_INERRUPUT 1
#define EUSART_ASYNCHRONOUS_TX_DISABLE_INERRUPUT 0

#define EUSART_ASYNCHRONOUS_TX_SHIFT_REG_EMPTY 1
#define EUSART_ASYNCHRONOUS_TX_SHIFT_REG_FULL 0

//////////////////////////////////

#define EUSART_ASYNCHRONOUS_RX_ENABLE 1
#define EUSART_ASYNCHRONOUS_RX_DISABLE 0

#define EUSART_ASYNCHRONOUS_RX_9bit 1
#define EUSART_ASYNCHRONOUS_RX_8bit 0

#define EUSART_ASYNCHRONOUS_RX_ENABLE_INERRUPUT 1
#define EUSART_ASYNCHRONOUS_RX_DISABLE_INERRUPUT 0



#define EUSART_ASYNCHRONOUS_RX_FRAMING_ERROR_EXISTS 1
#define EUSART_ASYNCHRONOUS_RX_FRAMING_ERROR_DOSENOT_EXISTS 0

 #define EUSART_ASYNCHRONOUS_RX_OVERRUN_ERROR_EXISTS 1
#define EUSART_ASYNCHRONOUS_RX_OVERRUN_ERROR_DOSENOT_EXISTS 0



 
  typedef enum {
 _8BIT_Asynchronous_low,
 _8BIT_Asynchronous_high,
   
 _16BIT_Asynchronous_low,
 _16BIT_Asynchronous_high,
     
 _8BIT_synchronous,
 _16BIT_synchronous
 
 
 
 }select_freq;
 
 typedef struct
 {void (* tx_inter_) (void);
     uint8 tx_priority;
   
     uint8 tx_enable;
     uint8 tx_inter;
     uint8 tx_9_8_bit;
 
 
 }tx_t;
 
 
 typedef struct
 {
 
 void (* rx_inter_) (void);
     uint8 rx_priority;
     uint8 rx_enable;
     uint8 rx_inter;
     uint8 rx_9_8_bit;
     uint8 frame_error;
     uint8 overrun_error;
 
 }rx_t;
 
 
 typedef struct
 {
     uint32 baudrate;
     uint8 choose_baudrate_equ;
 tx_t tx_config;
 rx_t rx_config;
 
 
 }eusart_t;
 
Std_ReturnType eusart_init(eusart_t * eusart);
Std_ReturnType eusart_rx_read_byte_blocking(uint8 *val);

 Std_ReturnType eusart_tx_write_string_blocking(eusart_t * eusart,uint8 val[],uint16 size_);
 Std_ReturnType eusart_tx_write_byte_blocking_without_enable(uint8 val);
  Std_ReturnType eusart_tx_write_byte_blocking_with_enable(uint8 val);

#endif	/* NEWFILE_H */

