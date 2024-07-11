/* 
 * File:   dc_motor.h
 * Author: ideapad GAMING
 *
 * Created on August 10, 2023, 6:37 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H
#include "../../MCAL_layer/GPIO/hal_gpio.h"

typedef struct
{
   pin_config all_motor[2];
}dc_motor_t;

Std_ReturnType  dc_motor_initialize(dc_motor_t *my_motor);
Std_ReturnType  dc_motor_move_righ(dc_motor_t *my_motor);
Std_ReturnType  dc_motor_move_left(dc_motor_t *my_motor);
Std_ReturnType  dc_motor_stop(dc_motor_t *my_motor);


#endif	/* DC_MOTOR_H */

