#include "dc_motor.h"

Std_ReturnType  dc_motor_initialize(dc_motor_t *my_motor)
{
     Std_ReturnType ret =E_NOT_OK;
    if(my_motor==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {   
     
    
       gio_pin_init(&(my_motor->all_motor[0]));
       gio_pin_init(&(my_motor->all_motor[1]));

    
         ret=E_OK;
    
    }
}
Std_ReturnType  dc_motor_move_righ(dc_motor_t *my_motor)
{
     Std_ReturnType ret =E_NOT_OK;
    if(my_motor==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
   
      gio_pin_write_logic(&(my_motor->all_motor[0]),HIGH);
      gio_pin_write_logic((&(my_motor->all_motor[1])),LOW);

    
         ret=E_OK;
    
    }
}
Std_ReturnType  dc_motor_move_left(dc_motor_t *my_motor)
{
     Std_ReturnType ret =E_NOT_OK;
    if(my_motor==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
       
      gio_pin_write_logic((&(my_motor->all_motor[0])),LOW);
      gio_pin_write_logic((&(my_motor->all_motor[1])),HIGH);
    
         ret=E_OK;
    
    }
}
Std_ReturnType  dc_motor_stop(dc_motor_t *my_motor)
{
     Std_ReturnType ret =E_NOT_OK;
    if(my_motor==NULL)
    {
    
        ret=E_NOT_OK;
    
    }
    else
    {
      
      
      gio_pin_write_logic((&(my_motor->all_motor[0])),LOW);
      gio_pin_write_logic((&(my_motor->all_motor[1])),LOW);
    
         ret=E_OK;
  
    
    }
}