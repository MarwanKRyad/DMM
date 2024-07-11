#include "timer2.h"
static void (* timer2_call) (void)=NULL;
static uint8 timer2_init_;
Std_ReturnType timer2_init(timer2_t *my_timer2)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_timer2 == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        timer2_init_=my_timer2->timer2_init_value;

 /////////////////////////////////////////////
 #if  TIMER2_INTERRUT ==ENABLE
  ret=TIMER2_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_timer2->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             TIMER2_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           TIMER2_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        timer2_call=my_timer2->timer2_inter;
        ret= TIMER2_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////

 TIMER2_CHOOSE_PRE_CLOCK_DIVISION(my_timer2->prescaler_value);
TIMER2_CHOOSE_POST_CLOCK_DIVISION(my_timer2->postscaler_value);
/////////////////

////////////
TMR2=(my_timer2->timer2_init_value);
///////////////////////////////////
TIMER2_ON();
        ret=E_OK;
    }
return ret;
}

Std_ReturnType timer2_write(timer2_t * my_timer2 ,uint8 value)
{
TMR2=value;

}
Std_ReturnType timer2_read(timer2_t * my_timer2,uint8 *value)
{
*value=TMR2;

}


void timer2_isr (void)
{
    TIMER2_INTERRUPT_CLEAR_FLAG();
    TMR2=(timer2_init_);
    if(timer2_call)
    {timer2_call();}

}