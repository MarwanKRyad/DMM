/* 
 * File:   keypad.h
 * Author: ideapad GAMING
 *
 * Created on August 13, 2023, 6:18 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define row_number 4 
#define column_number 4 
typedef struct
{
    pin_config row_pins [row_number];
        pin_config column_pins [column_number];


}keypad_t;
Std_ReturnType keypad_initalization(keypad_t* my_keypad);
Std_ReturnType keypad_write_value(keypad_t* my_keypad,char* value);

#endif	/* KEYPAD_H */

