#include "Relay.h"
Std_ReturnType Relay_initalize(Relay_t *my_Relay)
{ Std_ReturnType ret =E_NOT_OK;
    if(my_Relay==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
        pin_config new_config={my_Relay->my_pin,my_Relay->my_port,OUTPUT,my_Relay->my_logic};
        ret=gio_pin_init(&new_config);
    
    
    
    }

}
Std_ReturnType  Relay_turn_on(Relay_t *my_Relay)
  { Std_ReturnType ret =E_NOT_OK;
    if(my_Relay==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
        pin_config new_config={my_Relay->my_pin,my_Relay->my_port,OUTPUT,my_Relay->my_logic};
        ret=gio_pin_write_logic(&new_config,HIGH);
    
    
    
    }

}
Std_ReturnType  Relay_turn_off(Relay_t *my_Relay)
{
    { Std_ReturnType ret =E_NOT_OK;
    if(my_Relay==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
        pin_config new_config={my_Relay->my_pin,my_Relay->my_port,OUTPUT,my_Relay->my_logic};
        ret=gio_pin_write_logic(&new_config,LOW);
    
    
    
    }

}
}