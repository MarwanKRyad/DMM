#include "ECU_push_button.h"
Std_ReturnType button_initalize(button_t *my_button)
{
    Std_ReturnType ret=E_NOT_OK;

    if( my_button == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        ret= gio_pin_write_direction(&(my_button->button_info),INPUT);

    }
return ret;


}

Std_ReturnType read_button(button_t *my_button,char* button_type)
{   char temp;

   Std_ReturnType ret=E_NOT_OK;

    if( my_button == NULL || button_type==NULL)
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        ret= gio_pin_read_logic(&(my_button->button_info),&temp );
        if(my_button->my_active==ACTIVE_HIGH)
        {  if(1==temp)
            *button_type=BUTTON_PRESSED;
            else{
                 *button_type= BUTTON_RELEASED;
            }
        }
        else if(my_button->my_active==ACTIVE_LOW)     
        {
         if(1==temp)
            *button_type=BUTTON_RELEASED;
            else{
                 *button_type= BUTTON_PRESSED;
            }
        
        }
    }
return ret;

}
