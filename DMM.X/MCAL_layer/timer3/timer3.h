/* 
 * File:   timer3.h
 * Author: ideapad GAMING
 *
 * Created on September 8, 2023, 5:48 PM
 */

#ifndef TIMER3_H
#define	TIMER3_H

#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"




#define TIMER3_COUNTER_MODE_ 1
#define TIMER3_TIMER_MODE_ 0

#define TIMER3_SYC_MODE_ 1
#define TIMER3_ASYNC_MODE_ 0

#define TIMER3_16BIT_ 1
#define TIMER3_8BIT_ 0

#define TIMER3_ON() ( T3CONbits.TMR3ON=1)
#define TIMER3_OFF() ( T3CONbits.TMR3ON=0)

#define TIMER3_TIMER_MODE() ( T3CONbits.TMR3CS=0)
#define TIMER3_COUNTER_MODE() ( T3CONbits.TMR3CS=1)

#define TIMER3_SYC_COUNTER_MODE() (T3CONbits.T3SYNC=0)
#define TIMER3_ASYNC_COUNTER_MODE()(T3CONbits.T3SYNC=1)

#define TIMER3_16BIT() (T3CONbits.RD16=1)
#define TIMER3_8BIT() (T3CONbits.RD16=0)


#define TIMER3_CHOOSE_CLOCK_DIVISION(CLOCK_DIV) (T3CONbits.T3CKPS=CLOCK_DIV)


#define CLOCK__OVER__1 0
#define CLOCK__OVER__2 1
#define CLOCK__OVER__4 2

#define CLOCK__OVER__8 3

typedef struct{
 void (* timer3_inter) (void);
    char priority;
char prescaler_value :2 ;
uint16 timer3_init_value;
char timer3_mode :1;
char counter_mode :1;
char register_size ;

}timer3_t;

Std_ReturnType timer3_init(timer3_t * my_timer3);
Std_ReturnType timer3_write(timer3_t * my_timer3 ,uint16 value);
Std_ReturnType timer3_read(timer3_t * my_timer3,uint16 *value);
#endif	/* TIMER3_H */

