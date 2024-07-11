/* 
 * File:   ECU_push_button.h
 * Author: ideapad GAMING
 *
 * Created on August 3, 2023, 4:27 PM
 */

#ifndef ECU_PUSH_BUTTON_H
#define	ECU_PUSH_BUTTON_H
#include "../../MCAL_layer/GPIO/hal_gpio.h"

typedef enum
{
    BUTTON_RELEASED , 
            BUTTON_PRESSED

}button_statues;
typedef enum
{
    ACTIVE_HIGH,
    ACTIVE_LOW        

}button_active;
typedef struct
{   pin_config button_info;
    button_statues my_state ;
    button_active my_active ;
            

}button_t;
Std_ReturnType button_initalize(button_t *my_button);

Std_ReturnType read_button(button_t *my_button,char* button_type);
#endif	/* ECU_PUSH_BUTTON_H */

