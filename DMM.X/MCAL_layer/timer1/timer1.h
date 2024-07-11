/* 
 * File:   timer1.h
 * Author: ideapad GAMING
 *
 * Created on September 6, 2023, 5:06 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define TIMER1_COUNTER_MODE_ 1
#define TIMER1_TIMER_MODE_ 0

#define TIMER1_SYC_MODE_ 1
#define TIMER1_ASYNC_MODE_ 0

#define TIMER1_OSC_ENABLE_ 1
#define TIMER1_OSC_DISABLE_ 0

#define TIMER1_CLOCK_SOURCE_ 1
#define TIMER1_ANOTHER_CLOCK_SOURCE_ 0 

#define TIMER1_16BIT_ 1
#define TIMER1_8BIT_ 0

///////////////////////////////////////////////////
#define TIMER1_ON() ( T1CONbits.TMR1ON=1)
#define TIMER1_OFF() ( T1CONbits.TMR1ON=0)
///////////////////////////////////////////////////////
#define TIMER1_TIMER_MODE() ( T1CONbits.TMR1CS=0)
#define TIMER1_COUNTER_MODE() ( T1CONbits.TMR1CS=1)

#define TIMER1_SYC_COUNTER_MODE() (T1CONbits.T1SYNC=0)
#define TIMER1_ASYNC_COUNTER_MODE()(T1CONbits.T1SYNC=1)

#define TIMER1_OSC_ENABLE() (T1CONbits.T1OSCEN=1)
#define TIMER1_OSC_DISABLE() (T1CONbits.T1OSCEN=0)

#define TIMER1_READ_CLOCK_SOURCE() (T1CONbits.T1RUN)

#define TIMER1_16BIT() (T1CONbits.RD16=1)
#define TIMER1_8BIT() (T1CONbits.RD16=0)

#define TIMER1_CHOOSE_CLOCK_DIVISION(CLOCK_DIV) (T1CONbits.T1CKPS=CLOCK_DIV)


typedef struct{
 void (* timer1_inter) (void);
    char priority;
char prescaler_value :2 ;
uint16 timer1_init_value;
char timer1_mode :1;
char counter_mode :1;
char register_size ;
char timer1_osc_enable ;

}timer1_t;
#define CLOCK_OVER__1 0
#define CLOCK_OVER__2 1
#define CLOCK_OVER__4 2

#define CLOCK_OVER__8 3


Std_ReturnType timer1_init(timer1_t * my_timer1);
Std_ReturnType timer1_write(timer1_t * my_timer1 ,uint16 value);
Std_ReturnType timer1_read(timer1_t * my_timer1,uint16 *value);

#endif	/* TIMER1_H */

