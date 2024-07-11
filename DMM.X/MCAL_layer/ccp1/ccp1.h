/* 
 * File:   ccp1.h
 * Author: ideapad GAMING
 *
 * Created on September 10, 2023, 3:31 PM
 */

#ifndef CCP1_H
#define	CCP1_H

#include "ccp1_cfg.h"
#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
///////////////////////////////////////////
#define ccp_pwm_mode__ 1
#define ccp_capture_mode__ 2 
#define ccp_compare_mode__ 3




#define ccp_off_mode 0

#define ccp_capture_mode_1_falling 4
#define ccp_capture_mode_1_rising 5
#define ccp_capture_mode_4_rising 5
#define ccp_capture_mode_16_rising 7

#define ccp_compare_toggle_pin 2
#define ccp_compare_high_pin 8
#define ccp_compare_low_pin 9
#define ccp_compare_sw_inter 10
#define ccp_compare_special_event 11

#define ccp_pwm_mode 0x0c

#define ccp1_choose_mode(mode__)  (CCP1CONbits.CCP1M=mode__)
#define ccp2_choose_mode(mode__)  (CCP2CONbits.CCP2M=mode__)

////////////////////////////////////////
typedef union
{
    struct {
    uint8 stcut_low;
    uint8 stcut_high;


    };
     struct {
    uint16 stcut_all;
    };

}reg_8_16;
typedef enum 
{
    CCP1_CCP2_TIMER1=0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER3

}timer_select;

typedef struct
{ uint8 ccp_number;
    uint8 ccp_mode_;
uint8 ccp_detailed_mode;
pin_config my_pin;
uint8 ccp_choose_timer;

 void (* ccp_inter) (void);
    char priority;

#if ccp_mode==pwm_mode_
    
        uint32 pwm_freq_;
        uint8 prescaler_value ;
        uint8 postscaler_value ;

#endif

}ccp_t;
Std_ReturnType ccp_init(ccp_t * my_ccp);


#if ccp_mode==capture_mode_
Std_ReturnType ccp_is_capture_done (ccp_t * my_ccp,uint8* stat_);
  
Std_ReturnType ccp_capture_read_value(ccp_t * my_ccp,uint16* valu);


#endif

#if ccp_mode==compare_mode_
    
Std_ReturnType ccp_is_compare_done (ccp_t * my_ccp,uint8* stat_);
  
Std_ReturnType ccp_compare_write_value(ccp_t * my_ccp,uint16 valu);
#endif

#if ccp_mode==pwm_mode_
    
Std_ReturnType ccp_pwm_choose_duty_cycle (ccp_t * my_ccp,uint8 duty);
  
Std_ReturnType ccp_pwm_start(ccp_t * my_ccp);
Std_ReturnType ccp_pwm_stop(ccp_t * my_ccp);

#endif

#endif	/* CCP1_H */

