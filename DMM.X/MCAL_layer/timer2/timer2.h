/* 
 * File:   timer2.h
 * Author: ideapad GAMING
 *
 * Created on September 7, 2023, 11:30 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define TIMER2_ON() ( T2CONbits.TMR2ON=1)
#define TIMER2_OFF() ( T2CONbits.TMR2ON=0)

#define TIMER2_CHOOSE_PRE_CLOCK_DIVISION(CLOCK_DIV) (T2CONbits.T2CKPS=CLOCK_DIV)
#define TIMER2_CHOOSE_POST_CLOCK_DIVISION(CLOCK_DIV) (T2CONbits.TOUTPS=CLOCK_DIV)

#define PRE_CLOCK_OVER__1 0
#define PRE_CLOCK_OVER__4 1
#define PRE_CLOCK_OVER__16 3

typedef enum {
              POST_CLOCK_1 ,
            POST_CLOCK_2 ,
             POST_CLOCK_3 ,
          POST_CLOCK_4 ,
              POST_CLOCK_5 ,
            POST_CLOCK_6 , 
             POST_CLOCK_7 ,
             POST_CLOCK_8 ,
             POST_CLOCK_9 ,
             POST_CLOCK_10 ,
             POST_CLOCK_11,
             POST_CLOCK_12 ,
             POST_CLOCK_13 ,
             POST_CLOCK_14 ,
             POST_CLOCK_15 ,
             POST_CLOCK_16 ,         
}post_clock;


typedef struct{
 void (* timer2_inter) (void);
    char priority;
char prescaler_value :2 ;
char postscaler_value  ;

uint8 timer2_init_value;

}timer2_t;

Std_ReturnType timer2_init(timer2_t * my_timer2);
Std_ReturnType timer2_write(timer2_t * my_timer2 ,uint8 value);
Std_ReturnType timer2_read(timer2_t * my_timer2,uint8 *value);
#endif	/* TIMER2_H */

