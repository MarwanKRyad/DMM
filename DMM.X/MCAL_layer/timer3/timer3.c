#include "timer3.h"
static void (* timer3_call) (void)=NULL;
static uint16 timer3_init_;


static void timer3_register_size(timer3_t *my_timer3)
{
    if(my_timer3->register_size==TIMER3_8BIT_)
    {
        TIMER3_8BIT();

           
    
    }
    else {
    
    
  TIMER3_16BIT();
    }
}

static void timer3_mode(timer3_t *my_timer3)
{
    if(my_timer3->timer3_mode==TIMER3_COUNTER_MODE_)
    {
        TIMER3_COUNTER_MODE();   
         if(my_timer3->counter_mode==TIMER3_SYC_MODE_)
         {
             TIMER3_SYC_COUNTER_MODE();
         }
         else 
         {
    
             TIMER3_ASYNC_COUNTER_MODE();
    
         }
    
    }
    else {
    TIMER3_TIMER_MODE();    
    }
}


Std_ReturnType timer3_init(timer3_t *my_timer3)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_timer3 == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        timer3_init_=my_timer3->timer3_init_value;

 /////////////////////////////////////////////
 #if  TIMER3_INTERRUT ==ENABLE
  ret=TIMER3_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_timer3->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             TIMER3_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           TIMER3_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        timer3_call=my_timer3->timer3_inter;
        ret= TIMER3_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////

TIMER3_CHOOSE_CLOCK_DIVISION(my_timer3->prescaler_value);
timer3_mode(my_timer3);
timer3_register_size(my_timer3);
/////////////////

////////////
TMR3H=((my_timer3->timer3_init_value)>>8);
TMR3L=(uint8) (my_timer3->timer3_init_value);
///////////////////////////////////
TIMER3_ON();
        ret=E_OK;
    }
return ret;
}

Std_ReturnType timer3_write(timer3_t * my_timer3 ,uint16 value)
{
   Std_ReturnType ret=E_NOT_OK;

TMR3H=((value)>>8);
TMR3L=(uint8) (value);
        ret=E_OK;
return ret;

}
Std_ReturnType timer3_read(timer3_t * my_timer3 ,uint16 *value)
{   uint8 a,b;
Std_ReturnType ret=E_NOT_OK;

a=TMR3L;
b=TMR3H;
*value=(uint16) a+(uint16) (b<<8);
        ret=E_OK;
return ret;
}

void timer3_isr (void)
{
    TIMER3_INTERRUPT_CLEAR_FLAG();
    TMR3H=((timer3_init_)>>8);
TMR3L=(uint8) (timer3_init_);
    if(timer3_call)
    {timer3_call();}

}