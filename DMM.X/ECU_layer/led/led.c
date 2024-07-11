#include "led.h"


Std_ReturnType led_initalize(led_t *my_led)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_led == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        pin_config my_conf={my_led->my_pin,my_led->my_port,OUTPUT,my_led->led_status};
            
        gio_pin_init(&my_conf);
        ret=E_OK;
    }
return ret;
}
Std_ReturnType led_on(led_t *my_led)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_led == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        pin_config my_conf={my_led->my_pin,my_led->my_port,OUTPUT,my_led->led_status};
            
        gio_pin_write_logic(&my_conf,HIGH);
        ret=E_OK;
    }
return ret;
}
Std_ReturnType led_off(led_t *my_led)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_led == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        pin_config my_conf={my_led->my_pin,my_led->my_port,OUTPUT,my_led->led_status};
            
        gio_pin_write_logic(&my_conf,LOW);
        ret=E_OK;
    }
return ret;
}
Std_ReturnType led_toggle(led_t *my_led)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_led == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        pin_config my_conf={my_led->my_pin,my_led->my_port,OUTPUT,my_led->led_status};
            
        gio_pin_toggle_logic(&my_conf);
        ret=E_OK;
    }
return ret;
}
