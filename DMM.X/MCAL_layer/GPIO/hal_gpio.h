/* 
 * File:   hal_gpio.h
 * Author: ideapad GAMING
 *
 * Created on July 26, 2023, 1:15 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

#include <../proc/pic18f4620.h>
#include "../MCAL_std_types.h"
#include "../device_config.h"

/* section :function declaration */
Std_ReturnType gio_pin_init(pin_config* my_config);
Std_ReturnType gio_pin_write_direction(pin_config* my_config,uint8 direc);
Std_ReturnType gio_pin_read_direction(pin_config* my_config,uint8* direc );
Std_ReturnType gio_pin_write_logic(pin_config* my_config,uint8 logic );
Std_ReturnType gio_pin_read_logic(pin_config* my_config,uint8* logic );
Std_ReturnType gio_pin_toggle_logic(pin_config* my_config);


Std_ReturnType gio_port_init(port_name_ myport);
Std_ReturnType gio_port_init_direction(port_name_ myport, uint8 direc);
Std_ReturnType gio_port_read_direction(port_name_ myport,uint8* direc );
Std_ReturnType gio_port_write_logic(port_name_ myport,uint8 logic );
Std_ReturnType gio_port_read_logic(port_name_ myport,uint8* logic );
Std_ReturnType gio_port_toggle_logic(port_name_ myport);

#endif	/* HAL_GPIO_H */

