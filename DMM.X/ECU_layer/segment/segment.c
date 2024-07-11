#include "segment.h"
Std_ReturnType seg_initalization(seg_t* my_seg)
{ Std_ReturnType ret=E_OK;
     if(my_seg==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
             gio_pin_init(&(my_seg->all_seg[0]));
             gio_pin_init(&(my_seg->all_seg[1]));
             gio_pin_init(&(my_seg->all_seg[2]));
             gio_pin_init(&(my_seg->all_seg[3]));

                        

          ret=E_OK;  
                
          
    }
return ret;

}



Std_ReturnType seg_write_number(seg_t* my_seg,uint8 number)
{ Std_ReturnType ret=E_OK;
     if(my_seg==NULL || number >9)
    {
        ret=E_NOT_OK; //0000 1001
    }
    else 
    {
             gio_pin_write_logic(&(my_seg->all_seg[0]),number&1);
             gio_pin_write_logic(&(my_seg->all_seg[1]),(number>>1)&1);
             //  gio_pin_write_logic(&(my_seg->all_seg[1]),number&2);

             gio_pin_write_logic(&(my_seg->all_seg[2]),(number>>2)&1);
                          //  gio_pin_write_logic(&(my_seg->all_seg[1]),number&4);

             gio_pin_write_logic(&(my_seg->all_seg[3]),(number>>3)&1);
                          //  gio_pin_write_logic(&(my_seg->all_seg[1]),number&8);


                        

          ret=E_OK;  
                
          
    }
return ret;

}
