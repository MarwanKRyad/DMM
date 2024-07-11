#include "timer0.h"
static void (* timer0_call) (void)=NULL;
static uint16 timer0_init_;
static void timer0_prescaler(timer0_t *my_timer0)
{
    if(my_timer0->prescaler_enable==1)
    {
        TIMER0_PSA_ACTIVE();

            TIMER0_CHOOSE_CLOCK_DIVISION(my_timer0->prescaler_value);
    
    }
    else {
    
    
    TIMER0_PSA_DISACTIVE();
    }
}

static void timer0_Resolusion(timer0_t *my_timer0)
{
    if(my_timer0->Resolusion==Resolusion_8bit)
    {
        TIMER0_8BIT();

           
    
    }
    else {
    
    
  TIMER0_16BIT();
    }
}
static void timer0_edge(timer0_t *my_timer0)
{
    if(my_timer0->EDGE_TYPE==RISING_EDGE)
    {
    TIMER0_RISING_EDGE();
    
    }
    else {
    TIMER0_FALLING_EDGE();
    
    
    }
}
static void timer0_mode(timer0_t *my_timer0)
{
    if(my_timer0->timer0_mode==TIMER0_COUNTER_MODE_)
    {
    TIMER0_COUNTER_MODE();    
    }
    else {
    TIMER0_TIMER_MODE();    
    timer0_edge(my_timer0);
    }
}


Std_ReturnType timer0_init(timer0_t *my_timer0)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_timer0 == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        timer0_init_=my_timer0->timer0_init_value;

 /////////////////////////////////////////////
 #if  TIMER0_INTERRUT ==ENABLE
  ret=TIMER0_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_timer0->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             TIMER0_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           TIMER0_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        timer0_call=my_timer0->timer0_inter;
        ret= TIMER0_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////
timer0_prescaler(my_timer0);
timer0_Resolusion(my_timer0);
timer0_mode(my_timer0);
TMR0H=((my_timer0->timer0_init_value)>>8);
TMR0L=(uint8) (my_timer0->timer0_init_value);
        ret=E_OK;
    }
return ret;
}



Std_ReturnType timer0_write(timer0_t * my_timer0 ,uint8 value)
{
   Std_ReturnType ret=E_NOT_OK;

TMR0H=((value)>>8);
TMR0L=(uint8) (value);
        ret=E_OK;
return ret;

}
Std_ReturnType timer0_read(timer0_t * my_timer0,uint8 *value)
{   uint8 a,b;
Std_ReturnType ret=E_NOT_OK;

a=TMR0L;
b=TMR0H;
*value=(uint16) a+(uint16) (b<<8);
        ret=E_OK;
return ret;

}

void timer0_isr (void)
{
    TIMER0_INTERRUPT_CLEAR_FLAG();
    TMR0H=((timer0_init_)>>8);
TMR0L=(uint8) (timer0_init_);
    if(timer0_call)
    {timer0_call();}

}