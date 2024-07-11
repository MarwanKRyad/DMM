#include "hal_gpio.h"
volatile uint8 *TRIS_REG[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *LAT_REG[]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *PORT_REG[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};


Std_ReturnType gio_pin_write_direction(pin_config* my_config,uint8 direc)
{   Std_ReturnType ret=E_OK;

    if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else {
        switch (direc)
        {
          case OUTPUT:
                CLEAR_BITE(*TRIS_REG[my_config->my_port],my_config->my_pin);
                my_config->my_direction=1;
                break;
        
         case INPUT:
                SET_BITE(*TRIS_REG[my_config->my_port],my_config->my_pin);
                my_config->my_direction=0;

                break;
                
            default:
                ret=E_NOT_OK;
                break;
        }
    }
        return ret;
}
Std_ReturnType gio_pin_read_direction(pin_config* my_config,uint8* direc )
{
    Std_ReturnType ret=E_OK;
     if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else {
      *direc= READ_BITE(*TRIS_REG[my_config->my_port],my_config->my_pin);
        
    }
return ret;

}
Std_ReturnType gio_pin_write_logic(pin_config* my_config,uint8 logic )
{    Std_ReturnType ret=E_OK;
     if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else {
        switch (logic)
        {
          case HIGH:
                SET_BITE(*LAT_REG[my_config->my_port],my_config->my_pin);
                my_config->my_logic=1;
                break;
        
         case LOW:
                CLEAR_BITE(*LAT_REG[my_config->my_port],my_config->my_pin);
                 my_config->my_logic=0;
                break;
                
            default:
                ret=E_NOT_OK;
                break;
         }
    }
return ret;
}


Std_ReturnType gio_pin_read_logic(pin_config* my_config,uint8* logic )
{
Std_ReturnType ret=E_OK;
     if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else {
      *logic= READ_BITE(*PORT_REG[my_config->my_port],my_config->my_pin);
        
    }
return ret;
}
Std_ReturnType gio_pin_toggle_logic(pin_config* my_config)
{ Std_ReturnType ret=E_OK;
     if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
          TOGGLE_BITE(*LAT_REG[my_config->my_port],my_config->my_pin);
          my_config->my_logic=!(my_config->my_logic);
                
                
          
    }
return ret;

}










Std_ReturnType gio_pin_init(pin_config* my_config)
{
Std_ReturnType ret=E_OK;

    if(my_config==NULL|| (my_config->my_pin > PIN_MAX_NUBER-1) || (my_config->my_port > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
        
        ret= gio_pin_write_direction(my_config,my_config->my_direction);
        ret= gio_pin_write_logic(my_config,my_config->my_logic);

    }
        return ret;


}



/////////////////////////////////////////////////////////////////

Std_ReturnType gio_port_init_direction(port_name_ myport , uint8 direc )
{     Std_ReturnType ret=E_NOT_OK;

    if( (myport > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
          *TRIS_REG[myport]=direc;
                
           ret=E_OK;

          
    }
return ret;
}
Std_ReturnType gio_port_read_direction(port_name_ myport,uint8* direc )
{
    Std_ReturnType ret=E_NOT_OK;

    if( (myport > PORT_MAX_NUBER-1) || (direc==NULL) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
          *direc=*TRIS_REG[myport];
                
           ret=E_OK;

          
    }
return ret;
}
Std_ReturnType gio_port_write_logic(port_name_ myport,uint8 logic )
{     Std_ReturnType ret=E_NOT_OK;

    if( (myport > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
          *LAT_REG[myport]=logic;
                
           ret=E_OK;

          
    }
return ret;
}
Std_ReturnType gio_port_read_logic(port_name_ myport,uint8* logic )
{
Std_ReturnType ret=E_NOT_OK;

    if( (myport > PORT_MAX_NUBER-1) || (logic==NULL) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
          *logic=*PORT_REG[myport];
                
           ret=E_OK;

          
    }
return ret;
}
Std_ReturnType gio_port_toggle_logic(port_name_ myport)
 {
Std_ReturnType ret=E_NOT_OK;

    if( (myport > PORT_MAX_NUBER-1) )
    {
        ret=E_NOT_OK;
    }
    else 
    {
            *LAT_REG[myport]=~ (*LAT_REG[myport]);
            //*LAT_REG[myport]=~ (*LAT_REG[myport]) ^ 0xff;

           ret=E_OK;

          
    }
return ret;
}