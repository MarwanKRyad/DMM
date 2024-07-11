/* 
 * File:   interrupt_config.h
 * Author: ideapad GAMING
 *
 * Created on August 27, 2023, 11:55 PM
 */
#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H
//////////

////////////
#include <../proc/pic18f4620.h>
#include "../MCAL_std_types.h"
#include "interrupt_gen_conf.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define INTERRUPT_ENABLE 1
#define INTERRUPT_DISABLE 0
#define INTERRUPT_OCUURED 1
#define INTERRUPT_NOT_OCUURED 0
typedef enum{
Low_Priority,
    High_Priority
    
}Priority_t;
/////////////////////////////////////////////////////
#if INTERRUPT_PRIORITY==ENABLE
#define INTERRUPT_ENABLE_PRIORITY() (RCONbits.IPEN=1)

#define INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT() (INTCONbits.GIEH=1)
#define INTERRUPT_DISABLE_GLOBAL_HIGH_INTERRUPT() (INTCONbits.GIEH=0)
#define INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT() (INTCONbits.GIEL=1)
#define INTERRUPT_DISABLE_GLOBAL_LOW_INTERRUPT() (INTCONbits.GIEL=0)
#endif
/////////////////////////////////////////////////////////////////////
#if INTERRUPT_PRIORITY==DISABLE

#define INTERRUPT_DISABLE_PRIORITY() (RCONbits.IPEN=0)

#define INTERRUPT_ENABLE_GLOBAL_INTERRUPT() (INTCONbits.GIE=1)
#define INTERRUPT_DISENABLE_GLOBAL_INTERRUPT() (INTCONbits.GIE=0)
#define INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT() (INTCONbits.PEIE=1)
#define INTERRUPT_DISABLE_PERIPHERAL_INTERRUPT() (INTCONbits.PEIE=0)
#endif

#endif	/* INTERRUPT_CONFIG_H */

