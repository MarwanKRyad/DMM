/* 
 * File:   led.h
 * Author: ideapad GAMING
 *
 * Created on July 26, 2023, 2:41 AM
 */

#ifndef LED_H
#define	LED_H
/* section :includes section */

#include "../../MCAL_layer/GPIO/hal_gpio.h"
/* section :DATA types declarations  */
typedef enum 
{
    LED_OFF,
    LED_ON

}led_light;



typedef struct 
{   
    char my_pin :3;
    char my_port :3;
    char led_status :1;
}led_t;

/* section :function declaration */
Std_ReturnType led_initalize(led_t *my_led);
Std_ReturnType led_on(led_t *my_led);
Std_ReturnType led_off(led_t *my_led);
Std_ReturnType led_toggle(led_t *my_led);

#endif	/* LED_H */

