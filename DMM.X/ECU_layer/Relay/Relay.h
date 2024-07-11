/* 
 * File:   Relay.h
 * Author: ideapad GAMING
 *
 * Created on August 5, 2023, 10:48 PM
 */

#ifndef RELAY_H
#define	RELAY_H

#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define  Relay_off 0
#define Relay_on 1
typedef struct 
{
    char my_pin :3 ;       /* @ref pin_number */
char  my_port :3 ;     /* @ref port_name_ */
char my_logic :1 ; 
}Relay_t;

#endif	/* RELAY_H */

Std_ReturnType Relay_initalize(Relay_t *my_Relay);
Std_ReturnType  Relay_turn_on(Relay_t *my_Relay);
Std_ReturnType  Relay_turn_off(Relay_t *my_Relay);
