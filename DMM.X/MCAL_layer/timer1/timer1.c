#include "timer1.h"
static void (* timer1_call) (void)=NULL;
static uint16 timer1_init_;


static void timer1_register_size(timer1_t *my_timer1)
{
    if(my_timer1->register_size==TIMER1_8BIT_)
    {
        TIMER1_8BIT();

           
    
    }
    else {
    
    
  TIMER1_16BIT();
    }
}

static void timer1_mode(timer1_t *my_timer1)
{
    if(my_timer1->timer1_mode==TIMER1_COUNTER_MODE_)
    {
        TIMER1_COUNTER_MODE();   
         if(my_timer1->counter_mode==TIMER1_SYC_MODE_)
         {
             TIMER1_SYC_COUNTER_MODE();
         }
         else 
         {
    
             TIMER1_ASYNC_COUNTER_MODE();
    
         }
    
    }
    else {
    TIMER1_TIMER_MODE();    
    }
}


Std_ReturnType timer1_init(timer1_t *my_timer1)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_timer1 == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        timer1_init_=my_timer1->timer1_init_value;

 /////////////////////////////////////////////
 #if  TIMER1_INTERRUT ==ENABLE
  ret=TIMER1_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_timer1->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             TIMER1_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           TIMER1_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        timer1_call=my_timer1->timer1_inter;
        ret= TIMER1_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////

TIMER1_CHOOSE_CLOCK_DIVISION(my_timer1->prescaler_value);
timer1_mode(my_timer1);
timer1_register_size(my_timer1);
/////////////////
if(my_timer1->timer1_osc_enable==TIMER1_OSC_ENABLE_)
{
TIMER1_OSC_ENABLE();
}
else
{
TIMER1_OSC_DISABLE();


}
////////////
TMR1H=((my_timer1->timer1_init_value)>>8);
TMR1L=(uint8) (my_timer1->timer1_init_value);
///////////////////////////////////
TIMER1_ON();
        ret=E_OK;
    }
return ret;
}

Std_ReturnType timer1_write(timer1_t * my_timer1 ,uint16 value)
{
   Std_ReturnType ret=E_NOT_OK;

TMR1H=((value)>>8);
TMR1L=(uint8) (value);
        ret=E_OK;
return ret;

}
Std_ReturnType timer1_read(timer1_t * my_timer1 ,uint16 *value)
{   uint8 a,b;
Std_ReturnType ret=E_NOT_OK;

a=TMR1L;
b=TMR1H;
*value=(uint16) a+(uint16) (b<<8);
        ret=E_OK;
return ret;

}

void timer1_isr (void)
{
    TIMER1_INTERRUPT_CLEAR_FLAG();
    TMR1H=((timer1_init_)>>8);
TMR1L=(uint8) (timer1_init_);
    if(timer1_call)
    {timer1_call();}

}