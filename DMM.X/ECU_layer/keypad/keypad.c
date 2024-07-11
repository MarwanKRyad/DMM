#include "keypad.h"
char a[4][4]=
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+' }

};
Std_ReturnType keypad_initalization(keypad_t* my_keypad)
{ Std_ReturnType ret=E_OK;
     if(my_keypad==NULL)
    {
        ret=E_NOT_OK; //0000 1001
    }
    else 
    {      
         for(int i=0;i<row_number;i++)
            ret= gio_pin_init(&(my_keypad->row_pins[i]));
         for(int j=0;j<column_number;j++)
            ret= gio_pin_write_direction(&(my_keypad->column_pins[j]),INPUT);
          
                
          
    }
return ret;

}
Std_ReturnType keypad_write_value(keypad_t* my_keypad,char* value)
{ Std_ReturnType ret=E_OK;

char temp;
     if(my_keypad==NULL)
    {
        ret=E_NOT_OK; //0000 1001
    }
    else 
    {  for(int i=0;i<4;i++)
        { for(int w=0;w<4;w++)
               
          {ret= gio_pin_write_logic(&(my_keypad->row_pins[w]),0);}
           
           
                ret= gio_pin_write_logic(&(my_keypad->row_pins[i]),1);
                
           for(int j=0;j<4;j++)
           { gio_pin_read_logic(&(my_keypad->column_pins[j]),&temp);
               if(temp ==1)
               {
                   *value=a[i][j];
                      
               }
           }
           
        }
          
    }
return ret;
}