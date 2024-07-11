/* 
 * File:   timer0.h
 * Author: ideapad GAMING
 *
 * Created on September 5, 2023, 3:19 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H
#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define RISING_EDGE 1 
#define FALLING_EDGE 0 

#define Resolusion_8bit 1 
#define Resolusion_16bit 0 

#define TIMER0_COUNTER_MODE_ 0
#define TIMER0_TIMER_MODE_ 1

#define TIMER0_ON() ( T0CONbits.TMR0ON=1)
#define TIMER0_OFF() ( T0CONbits.TMR0ON=0)

#define TIMER0_8BIT() ( T0CONbits.T08BIT=1)
#define TIMER0_16BIT() ( T0CONbits.T08BIT=0)

#define TIMER0_TIMER_MODE() ( T0CONbits.T0CS=0)
#define TIMER0_COUNTER_MODE() ( T0CONbits.T0CS=1)

#define TIMER0_FALLING_EDGE() ( T0CONbits.T0SE=1)
#define TIMER0_RISING_EDGE() ( T0CONbits.T0SE=0)

#define TIMER0_PSA_ACTIVE() ( T0CONbits.PSA=0)
#define TIMER0_PSA_DISACTIVE() ( T0CONbits.PSA=1)

#define TIMER0_CHOOSE_CLOCK_DIVISION(CLOCK_DIV) (T0CONbits.T0PS=CLOCK_DIV)

typedef enum {
    CLOCK_OVER_2,
    CLOCK_OVER_4,
    CLOCK_OVER_8,
    CLOCK_OVER_16,
    CLOCK_OVER_32,
    CLOCK_OVER_64,
    CLOCK_OVER_128,
    CLOCK_OVER_256


}TIMER0_CLOCK;
typedef struct 
{
    void (* timer0_inter) (void);
    char priority;
char prescaler_enable :1 ;
char prescaler_value  ;
char EDGE_TYPE :1  ;
char Resolusion :1 ;
uint16 timer0_init_value;
char timer0_mode :1;
}timer0_t;


Std_ReturnType timer0_init(timer0_t * my_timer0);
Std_ReturnType timer0_write(timer0_t * my_timer0 ,uint8 value);
Std_ReturnType timer0_read(timer0_t * my_timer0,uint8 *value);

#endif	/* TIMER0_H */

