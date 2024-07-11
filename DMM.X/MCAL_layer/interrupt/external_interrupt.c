#include "external_interrupt.h"
static void (* int0_call) (void)=NULL;
static void (* int1_call) (void)=NULL;
static void (* int2_call) (void)=NULL;

static void (* rb4_call_high) (void)=NULL;
static void (* rb4_call_low) (void)=NULL;

static void (* rb5_call_high) (void)=NULL;
static void (* rb5_call_low) (void)=NULL;

static void (* rb6_call_high) (void)=NULL;
static void (* rb6_call_low) (void)=NULL;

static void (* rb7_call_high) (void)=NULL;
static void (* rb7_call_low) (void)=NULL;



static Std_ReturnType INTERRUPT_INTX_call_back(INTX_T * my_int)
{
        Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         switch(my_int->source)
         {
             case Int0 :int0_call=my_int->EXT;
                 break;
             case Int1 :int1_call=my_int->EXT;
                 break;
                 
             case Int2 :int2_call=my_int->EXT;
                 break;
         }
               
         
          ret=E_OK;  
                
          
    }
return ret;

}


static Std_ReturnType INTERRUPT_INTX_ENABLE(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {  
        #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_int->priority==High_Priority)
         {INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();}
         else {
        INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();}
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif

         switch(my_int->source)
         {
             case Int0 :INT0_ENABLE();
                 break;
             case Int1 :INT1_ENABLE();
                 break;
                 
             case Int2 :INT2_ENABLE();
                 break;
         }
               
         
          ret=E_OK;  
                
          
    }
return ret;

}
static Std_ReturnType INTERRUPT_INTX_DISABLE(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         switch(my_int->source)
         {
             case Int0 :INT0_DISABLE();
                 break;
             case Int1 :INT1_DISABLE();
                 break;
                 
             case Int2 :INT2_DISABLE();
                 break;
         }
               
         
          ret=E_OK;  
                
          
    }
return ret;

}
static Std_ReturnType INTERRUPT_INTX_PIN_INIT(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         
        ret=gio_pin_write_direction(&(my_int->mypin),INPUT); 
         
          ret=E_OK;  
                
          
    }
return ret;

}
static Std_ReturnType INTERRUPT_INTX_EDGE_INIT(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {       
     if(my_int->source==INT0)
        {
            switch(my_int->source)
                {
                 case Rising_edge :INT0_RISING_EDGE();
                     break;
                 case Falling_edge :INT0_FALLING_EDGE();
                     break;
                }
    
        }
         
         
         
         
         
    else if(my_int->source==INT1)
        {
             switch(my_int->source)
                {
                 case Rising_edge :INT1_RISING_EDGE();
                     break;
                 case Falling_edge :INT1_FALLING_EDGE();
                     break;
                }
    
        }
        
    else if(my_int->source==INT2)
            {
                switch(my_int->source)
                {
                 case Rising_edge :INT2_RISING_EDGE();
                     break;
                 case Falling_edge :INT2_FALLING_EDGE();
                     break;
                }
    
            }
             
         
          ret=E_OK;  
                
          
    }
return ret;

}
#if INTERRUPT_PRIORITY==ENABLE

static Std_ReturnType INTERRUPT_INTX_PRIORITY_INIT(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   if(my_int->source==Int1)
            {
                switch(my_int->priority)
                {
                 case Low_Priority :INT1_LOW_PRIORITY();
                     break;
                 case High_Priority :INT1_HIGH_PRIORITY();
                     break;
                }
    
            }
        
    else if(my_int->source==Int2)
            {
                switch(my_int->priority)
                {
                 case Low_Priority :INT2_LOW_PRIORITY();
                     break;
                 case High_Priority :INT2_HIGH_PRIORITY();
                     break;
                }
    
            }
             
         
          ret=E_OK;  
                
          
    }
return ret;

}
#endif
static Std_ReturnType INTERRUPT_CLEAR_FLAG(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         switch(my_int->source)
         {
             case Int0 :INT0_CLEAR_FLAG();
                 break;
             case Int1 :INT1_CLEAR_FLAG();
                 break;
                 
             case Int2 :INT2_CLEAR_FLAG();
                 break;
         }
               
         
          ret=E_OK;  
                
          
    }
return ret;

}

Std_ReturnType INTERRUPT_INTX_INIT(INTX_T * my_int)
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         ret=INTERRUPT_CLEAR_FLAG(my_int);
         ret=INTERRUPT_INTX_PIN_INIT(my_int);
         ret=INTERRUPT_INTX_EDGE_INIT(my_int);
         #if INTERRUPT_PRIORITY==ENABLE
         ret=INTERRUPT_INTX_PRIORITY_INIT(my_int);
         #endif
         ret=INTERRUPT_INTX_call_back(my_int);
         ret=INTERRUPT_INTX_ENABLE(my_int);
         
    }
               
         
          ret=E_OK;  
                
          
    
return ret;

}
Std_ReturnType INTERRUPT_INTX_DEINIT(INTX_T * my_int)
{


}
Std_ReturnType INTERRUPT_RBX_INIT(RBX_T * my_int)
{
{
Std_ReturnType ret=E_OK;
     if(my_int==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {
         ret=RB_CLEAR_FLAG();
         ret=gio_pin_write_direction(&(my_int->mypin),INPUT); 
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_int->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             RB_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
             RB_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
         RB_ENABLE();
/////////////////////////////////////////////////
         switch (my_int->mypin.my_pin)
         {   case 4:rb4_call_high=my_int->EXT_HIGH; 
                    rb4_call_low=my_int->EXT_LOW;
                         break;
                    
             case 5:rb5_call_high=my_int->EXT_HIGH; 
                    rb5_call_low=my_int->EXT_LOW;
                         break;
             case 6:rb6_call_high=my_int->EXT_HIGH; 
                    rb6_call_low=my_int->EXT_LOW;
                         break;
             case 7:rb7_call_high=my_int->EXT_HIGH; 
                    rb7_call_low=my_int->EXT_LOW;
                         break;
         
         
         }
         
    }
               
         
          ret=E_OK;  
                
          
    
return ret;

}

}
Std_ReturnType INTERRUPT_RBX_DEINIT(RBX_T * my_int)
{


}
void INT0_ISR(void)
{   Std_ReturnType ret;
    ret=INT0_CLEAR_FLAG();
    if(int0_call)
    {
    
    int0_call();
    
    }
}
void INT1_ISR(void)
{   Std_ReturnType ret;
    ret=INT1_CLEAR_FLAG();
    if(int1_call)
    {
    
    int1_call();
    
    }
}
void INT2_ISR(void)
{   Std_ReturnType ret;
    ret=INT2_CLEAR_FLAG();
    if(int2_call)
    {
    
    int2_call();
    
    }
}
void RB4_ISR(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb4_call_high)
    {
    
    rb4_call_high();
    
    }
}
void RB4_ISR2(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb4_call_low)
    {
    
    rb4_call_low();
    
    }
}


void RB5_ISR(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb5_call_high)
    {
    
    rb5_call_high();
    
    }
}
void RB5_ISR2(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb5_call_low)
    {
    
    rb5_call_low();
    
    }
}


void RB6_ISR(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb6_call_high)
    {
    
    rb6_call_high();
    
    }
}
void RB6_ISR2(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb6_call_low)
    {
    
    rb6_call_low();
    
    }
}


void RB7_ISR(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb7_call_high)
    {
    
    rb7_call_high();
    
    }
}
void RB7_ISR2(void)
{  
    RB_CLEAR_FLAG();
 

    if(rb7_call_low)
    {
    
    rb7_call_low();
    
    }
}