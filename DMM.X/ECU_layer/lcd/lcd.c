#include "lcd.h"


static Std_ReturnType set_cursor_4(lcd_4 * my_lcd,char row,char column)

 {

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   column --;
    switch(row)
    {
        case 1: 
               ret=lcd_4bit_sned_command(my_lcd,(0x80+column));
               break;
        case 2:
              ret=lcd_4bit_sned_command(my_lcd,(0xc0+column));
              break;
        case 3: 
              ret=lcd_4bit_sned_command(my_lcd,(0x94+column));
              break;
        break;
        case 4:
              ret=lcd_4bit_sned_command(my_lcd,(0xd4+column));
              break;
       
      
        default: 
            break;
    }          
    }
return ret;

}
static Std_ReturnType lcd_4bit_sned(lcd_4 * lcd,_data_command)
{

  Std_ReturnType ret = E_OK;
    ret = gio_pin_write_logic(&(lcd->lcd_pins[0]), (_data_command >> 0) & (uint8)0x01);
    ret = gio_pin_write_logic(&(lcd->lcd_pins[1]), (_data_command >> 1) & (uint8)0x01);
    ret = gio_pin_write_logic(&(lcd->lcd_pins[2]), (_data_command >> 2) & (uint8)0x01);
    ret = gio_pin_write_logic(&(lcd->lcd_pins[3]), (_data_command >> 3) & (uint8)0x01);
    return ret;

}
static Std_ReturnType lcd_4bit_sned_enable(lcd_4 * my_lcd)
{ Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
            
        ret=gio_pin_write_logic(&(my_lcd->lcd_e),1);
        __delay_ms(0.5);
         ret=gio_pin_write_logic(&(my_lcd->lcd_e),0);
               
         
          ret=E_OK;  
                
          
    }
return ret;

}
Std_ReturnType lcd_4bit_initilization(lcd_4 * my_lcd)
 {

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {  /* ret=gio_pin_init(&(my_lcd->lcd_rs));
        ret=gio_pin_init(&(my_lcd->lcd_e));
         for(int i=0;i<4;i++)
         { ret=gio_pin_init(&(my_lcd->lcd_pins[i]));
         
         }
      
         __delay_ms(20);
        ret=lcd_4bit_sned_command(my_lcd,LCD_8BIT_2LINE);
         __delay_ms(5);
        ret=lcd_4bit_sned_command(my_lcd,LCD_8BIT_2LINE);

           __delay_us(120);
            ret=lcd_4bit_sned_command(my_lcd,LCD_8BIT_2LINE);



        ret=lcd_4bit_sned_command(my_lcd,LCD_CLEAR);
__delay_ms(200);
                                               ret=lcd_4bit_sned_command(my_lcd,LCD_4BIT_2LINE);

        ret=lcd_4bit_sned_command(my_lcd,LCD_RETURN_HOME);

        ret=lcd_4bit_sned_command(my_lcd,LCD_INCREMENT_ADDRESS);
        
        ret=lcd_4bit_sned_command(my_lcd,LCD_DISLPAY_ON_UNDERLINE_CURSER_OFF_SIDE_OFF);

        ret=lcd_4bit_sned_command(my_lcd,DDRAM_START);
*/

  ret=gio_pin_init(&(my_lcd->lcd_rs));
        ret=gio_pin_init(&(my_lcd->lcd_e));
         for(int i=0;i<4;i++)
         { ret=gio_pin_init(&(my_lcd->lcd_pins[i]));
         
         }
      
        __delay_ms(20);
        ret = lcd_4bit_sned_command(my_lcd, LCD_8BIT_2LINE);
        __delay_ms(5);
        ret = lcd_4bit_sned_command(my_lcd, LCD_8BIT_2LINE);
        __delay_us(150);
        ret = lcd_4bit_sned_command(my_lcd, LCD_8BIT_2LINE);
        
        ret = lcd_4bit_sned_command(my_lcd, LCD_CLEAR);
        ret = lcd_4bit_sned_command(my_lcd, LCD_RETURN_HOME);
        ret = lcd_4bit_sned_command(my_lcd, LCD_INCREMENT_ADDRESS);
       ret = lcd_4bit_sned_command(my_lcd, LCD_DISLPAY_ON_UNDERLINE_CURSER_OFF_SIDE_OFF);
        
        
        
        ret = lcd_4bit_sned_command(my_lcd, LCD_4BIT_2LINE);
        ret = lcd_4bit_sned_command(my_lcd, 0x80);
           
                
          
    }
return ret;

}
Std_ReturnType lcd_4bit_sned_character(lcd_4 * my_lcd,char character)

{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {  ret=gio_pin_write_logic(&(my_lcd->lcd_rs),1);
         for(int i=0;i<4;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(character>>(4+i)) & (char ) 0x01);
         
         }
         ret=lcd_4bit_sned_enable(my_lcd);
               
          for(int i=0;i<4;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(character>>i) & (char ) 0x01);
         
         }
         ret=lcd_4bit_sned_enable(my_lcd);
          ret=E_OK;  
         /* ret=gio_pin_write_logic(&(my_lcd->lcd_rs),1);
         ret=lcd_4bit_sned(my_lcd,character>>4);
                  ret=lcd_4bit_sned_enable(my_lcd);

         ret=lcd_4bit_sned(my_lcd,character);
                  ret=lcd_4bit_sned_enable(my_lcd);*/
                
          
    }
return ret;

}

Std_ReturnType lcd_4bit_sned_command(lcd_4 * my_lcd,char command)
{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    { ret=gio_pin_write_logic(&(my_lcd->lcd_rs),0);
         for(int i=0;i<4;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(command>>(4+i)) & (char ) 0x01);
         
         }
         ret=lcd_4bit_sned_enable(my_lcd);
               
          for(int i=0;i<4;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(command>>i) & (char ) 0x01);
         
         }
         ret=lcd_4bit_sned_enable(my_lcd);
          ret=E_OK;  
        /*ret=gio_pin_write_logic(&(my_lcd->lcd_rs),0);
         ret=lcd_4bit_sned(my_lcd,command>>4);
                  ret=lcd_4bit_sned_enable(my_lcd);

         ret=lcd_4bit_sned(my_lcd,command);
                  ret=lcd_4bit_sned_enable(my_lcd);*/


          
    }
return ret;

}
Std_ReturnType lcd_4bit_sned_string(lcd_4 * my_lcd,char array[])
{   int i=0;

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {       
         while(array[i]!=NULL)
         { 
          ret=lcd_4bit_sned_character(my_lcd,array[i]);
         
         i++;} 
    }
return ret;

}
Std_ReturnType lcd_4bit_sned_string_at_pos(lcd_4 * my_lcd,char row,char column,char array[])
{   int i=0;

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {       ret=set_cursor_4( my_lcd,row, column);
         while(array[i]!=NULL)
         { 
             
          ret=lcd_4bit_sned_character(my_lcd,array[i]);
         
         i++;} 
    }
return ret;

}
static Std_ReturnType set_cursor_8(lcd_8 * my_lcd,char row,char column)

 {

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   column --;
    switch(row)
    {
        case 1: 
               ret=lcd_8bit_sned_command(my_lcd,(0x80+column));
               break;
        case 2:
              ret=lcd_8bit_sned_command(my_lcd,(0xc0+column));
              break;
        case 3: 
              ret=lcd_8bit_sned_command(my_lcd,(0x94+column));
              break;
        break;
        case 4:
              ret=lcd_8bit_sned_command(my_lcd,(0xd4+column));
              break;
       
      
        default: 
            break;
    }          
    }
return ret;

}
static Std_ReturnType lcd_8bit_sned_enable(lcd_8 * my_lcd)
{ Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
            
        ret=gio_pin_write_logic(&(my_lcd->lcd_e),1);
        __delay_ms(0.5);
         ret=gio_pin_write_logic(&(my_lcd->lcd_e),0);
               
         
          ret=E_OK;  
                
          
    }
return ret;

}

Std_ReturnType lcd_8bit_sned_command(lcd_8 * my_lcd,char command)
{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {    ret=gio_pin_write_logic(&(my_lcd->lcd_rs),0);
         for(int i=0;i<8;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(command>>i) & (char ) 0x01);
         
         }
         ret=lcd_8bit_sned_enable(my_lcd);
               
         
          ret=E_OK;  
                
          
    }
return ret;

}



Std_ReturnType lcd_8bit_initilization(lcd_8 * my_lcd)
 {

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
         for(int i=0;i<8;i++)
         { ret=gio_pin_init(&(my_lcd->lcd_pins[i]));
         
         }
        ret=gio_pin_init(&(my_lcd->lcd_rs));
        ret=gio_pin_init(&(my_lcd->lcd_e));
         __delay_ms(200);
        ret=lcd_8bit_sned_command(my_lcd,LCD_8BIT_2LINE);
         __delay_ms(5);
        ret=lcd_8bit_sned_command(my_lcd,LCD_8BIT_2LINE);

           __delay_us(120);
        ret=lcd_8bit_sned_command(my_lcd,LCD_CLEAR);
        ret=lcd_8bit_sned_command(my_lcd,LCD_RETURN_HOME);
        ret=lcd_8bit_sned_command(my_lcd,LCD_INCREMENT_ADDRESS);
        ret=lcd_8bit_sned_command(my_lcd,LCD_DISLPAY_ON_UNDERLINE_CURSER_OFF_SIDE_OFF);

        ret=lcd_8bit_sned_command(my_lcd,DDRAM_START);

           
                
          
    }
return ret;

}

Std_ReturnType lcd_8bit_sned_character(lcd_8 * my_lcd,char character)

{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {    ret=gio_pin_write_logic(&(my_lcd->lcd_rs),1);
         for(int i=0;i<8;i++)
         { ret=gio_pin_write_logic(&(my_lcd->lcd_pins[i]),(character>>i) & (char ) 0x01);
         
         }
         ret=lcd_8bit_sned_enable(my_lcd);
               
         
          ret=E_OK;  
                
          
    }
return ret;

}
Std_ReturnType lcd_4bit_sned_character_at_pos(lcd_4 * my_lcd,char row,char column,char character)
{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   

           ret=set_cursor_4( my_lcd,row, column);
          ret=lcd_4bit_sned_character(my_lcd,character);
    }
return ret;

}
Std_ReturnType lcd_8bit_sned_character_at_pos(lcd_8 * my_lcd,char row,char column,char character)
{

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   

           ret=set_cursor_8( my_lcd,row, column);
          ret=lcd_8bit_sned_character(my_lcd,character);
    }

return ret;

}

Std_ReturnType lcd_8bit_sned_string(lcd_8 * my_lcd,char array[])
{   int i=0;

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {       
         while(array[i]!=NULL)
         { 
          ret=lcd_8bit_sned_character(my_lcd,array[i]);
         
         i++;} 
    }
return ret;

}
Std_ReturnType lcd_8bit_sned_string_at_pos(lcd_8 * my_lcd,char row,char column,char array[])
{   int i=0;

 Std_ReturnType ret=E_OK;
     if(my_lcd==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {       ret=ret=set_cursor_8( my_lcd,row, column);
         while(array[i]!=NULL)
         { 
             
          ret=lcd_8bit_sned_character(my_lcd,array[i]);
         
         i++;} 
    }
return ret;

}
void convert_char_to_string (unsigned char number,unsigned char array[])
{    memset(array,'\0',4);
          
    sprintf(array,"%i",number);

}
void convert_short_to_string ( short int number, char array[])
{   char temp[6]={0};
uint8 counter=0;
    memset(array,' ',5);
array[5]='\0';                        //{ , , , , ,\0} 
                                      //(1,2,3,\0 , ,\0}
                                      //{ , , , , ,\0}
                                      //temp=(1,2,\0, , ,\0) 
                                      //arr=(1,2, , , ,\0)  
    sprintf(temp,"%i",number);
    while (temp[counter]!='\0')
    {
       array[counter]= temp[counter];

        counter ++;
    }

}
void convert_int_to_string (  int number, char array[])
{    memset(array,'\0',11);
          
    sprintf(array,"%i",number);

}
Std_ReturnType lcd_8bit_sned_custom_char(lcd_8 * my_lcd,char row,char column,char array[],char pos)
{   Std_ReturnType ret;
            ret=lcd_8bit_sned_command(my_lcd,0x40+8*pos);

    for(int i=0 ;i<8;i++)
    {
        ret=lcd_8bit_sned_character(my_lcd,array[i]);
    
    }
          ret=lcd_8bit_sned_character_at_pos(my_lcd,row,column,pos);
                       return ret;
}
Std_ReturnType lcd_4bit_sned_custom_char(lcd_4 * my_lcd,char row,char column,char array[],char pos)
{   Std_ReturnType ret;
            ret=lcd_4bit_sned_command(my_lcd,0x40+8*pos);

    for(int i=0 ;i<8;i++)
    {
        ret=lcd_4bit_sned_character(my_lcd,array[i]);
    
    }
          ret=lcd_4bit_sned_character_at_pos(my_lcd,row,column,pos);
                       return ret;
}